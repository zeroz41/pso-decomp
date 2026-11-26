#include "pso/player/GuildCardEntry.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby_8007B858.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/TScreenFadeController.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/system/TLanguage.h"
#include "pso/object/lobby/LobbyGoGoBall.h"
#include "pso/object/lobby/TGoGoBallGame.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/map/TSetManager.h"
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/TLobbyEventTheme.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TCameraCapturePass.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/npc/NpcEnemyAnimReset.h"
#include "pso/render/reflection.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjControl.h"
#include "pso/network/LegacyEnemyKill.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/npc/TNpcTalkTrigger.h"
#include "pso/render/CameraCapture.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/network/TradeProposalCmd.h"
#include "pso/unk/TDeferredRenderQueue.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/effect/TIndirectEffectDrawTask.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/object/switch/TOChatSensor.h"
#include "pso/ui/chat/TSymbolChatCapture.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCineCtrl.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/map/area/AreaScene.h"
#include "pso/system/TGStream.h"
#include "pso/system/GslArchive.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/memory.h"
#include "pso/network/protocol/SendGuildCardPacket.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/technique/TTecLuker.h"

// The tail of the guild card code: it follows TWindowSubComCard_8007A810.cpp's static
// initialiser, which CW emits last in its file, so it opens this file.

s32 GuildCardEntry::get_card_id() const { return tag.m_guildcard_number; }
int GuildCardEntry::is_active() const { return flags & 1; }
s8 GuildCardEntry::get_char_class() { return char_class; }

s32 GuildCardEntry::is_own_card() const {
    if (flags & 2) {
        return 0;
    }
    return 1;
}

void G_SendGuildCard_6x06::bswap() {
    header.bswap();
    card.bswap();
}

void GuildCardEntry::bswap() { tag.bswap(); }

void G_SendGuildCard_6x06::send_to(u32 client) {
    bswap();
    // The packet starts with its header: send it as a whole game command.
    ((game_command *)&header)->send_to_client(client);
}

GuildCardEntry *TWindowSubComCard::get_own_guild_card() { return own_guild_card; }

G_SendGuildCard_6x06::G_SendGuildCard_6x06() {
    header.subcommand = 6;
    header.size = sizeof(G_SendGuildCard_6x06) / 4;
}

int TAdSinglePlyChrSelectGC::get_state() {  return (int)guild_card_save_payload; }

void TPlyGuildCardTag::bswap() {
    bswap_32(&m_guildcard_number);
    bswap_16(&m_tag2);
}

void set_guild_card_receive_active() {
    short_mail_flags |= 2;
}

s32 ShortMailEntry::get_sender_card_id() { return sender_card_id; }

char *ShortMailEntry::get_sender_name() { return sender_name; }

s32 TObjPlayer::get_section_id() {
    return appearance.section;
}

const char *TObjPlayer::get_name() { return appearance.name; }





// Session resources, loaded front to back by TLobby::run_lobby_load_tables and released
// back to front by TLobby::clear_session_buffers (load, release pairs).
FloorResourceCallbacks session_resource_callbacks[29] = {
    {TCameraCtrl::reset_view_state, TCameraCtrl::reset},
    {TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view},
    {(FloorResourceCallback)reset_npc_enemy_anims_on_floor_load, forward_npc_enemy},
    {create_reflection_target, destroy_reflection_target},
    {init_camera_render_target, free_camera_render_target},
    {TScene::load_current_floor, TScene::free_scene_resources},
    {TSceneSora::load_sky_resources, TSceneSora::release_sky_scene},
    {TRaderMapCore::load_map_resources, TRaderMapCore::unload_floor_map},
    {setup_floor_decorations, clear_floor_flags_and_depart},
    {TLobby::clear_flag_on_phase_e, object_control_on_floor_free_stub},
    {clear_legacy_enemy_kill_flags, release_legacy_enemy_kill_flags},
    {load_particle_entry_resources, TParticleCtrl::free_all},
    {TFogCtrl::update_fog_entries, TFogCtrl::release_fog_entries},
    {init_partner_dialogue, release_partner_dialogue},
    {reset_npc_proximity_target_on_floor_load, reset_npc_proximity_target_on_floor_free},
    {reset_quest_collision_ids_on_floor_load, reset_quest_collision_ids_on_floor_free},
    {reset_and_init_capture_texture, reset_and_release_capture_texture},
    {init_shadow_map_texture, release_shadow_map_texture},
    {load_indirect_dat, TEffIndirectCtrl::free_all},
    {close_trade_request_on_floor_load, close_trade_request_on_floor_unload},
    {clear_deferred_render_queue_on_floor_load, clear_deferred_render_queue_on_floor_free},
    {KeyboardKeyState::reset_global_keys_b, KeyboardKeyState::reset_global_keys_a},
    {clear_game_end_window_on_floor_load, clear_game_end_window_on_floor_free},
    {TIndirectEffectDrawTask::clear_instance_on_floor_load, TIndirectEffectDrawTask::clear_instance_on_floor_free},
    {clear_signboard_texture_buffer_pointer, TLobby::free_global_buffer},
    {chat_sensor_on_floor_load, chat_sensor_on_floor_free},
    {symbol_chat_capture_on_floor_load, symbol_chat_capture_on_floor_free},
    {reset_return_city_scan_on_floor_load, return_city_on_floor_free},
    {TTecLuker::reset_visit_counts_on_floor_load, TTecLuker::reset_visit_counts_on_floor_free},
};

// Field-only resources: loaded and released only outside Pioneer 2 and the lobby.
FloorResourceCallbacks field_resource_callbacks[4] = {
    {load_technique_resources, free_technique_resources},
    {load_photon_blast_resources, release_photon_blast_resources},
    {load_camera_banks, free_camera_banks},
    {update_battle_params, NULL},
};

void TLobby::create_tasks() {
    create_area_fog_ctrl();
    if (is_split_screen() == 0) {
        new TCameraCapturePass(tl_particlemodel, 1);
        new TCameraCapturePass(tl_particlemodel, 0);
        new TDeferredRenderQueue(tl_particlemodel);
        new TIndirectEffectDrawTask(tl_particlemodel);
    }
    TMainTask::cleanup_game_objects();
    TScene::create();
    TSceneSora::create_instance();
    TSetManager::create();
    activate_triggered_floor_events();
    new TWindowCtrlMain();
    new TWindowCtrl(tl_00);
    new TScreenFadeController(tl_fade);
    TLobby::set_fade_params(0);
    new TCineCtrl(tl_00);
    TRaderMapCore::create();
    restore_floor_telepipes();
    new TNpcPartnerSpawner(tl_06);
    new TSwitch(tl_00);
    TQuestColCtrl::init();
    if (get_current_floor_area() == AREA_LOBBY) {
        TLobbyEventTheme::create();
    }
    if ((get_current_floor_area() == AREA_LOBBY) && (TLobby::is_scene_ready() != 0)) {
        TGoGoBallGame::create();
    }
    if ((get_main_phase() == 0xF) && ((get_current_floor_area() == AREA_PIONEER2_EP1) || (get_current_floor_area() == AREA_PIONEER2_EP2))) {
        new THunterGuildSeqOnlineTask(tl_01);
    }
    new TTecCtrl(tl_01);
}

void TLobby::clear_session_buffers() {
    if (get_current_floor_area() == AREA_LOBBY) {
        free_player_tex_texture();
        free_lobby_textures();
        free_obj_lobby_main();
    }
    if ((get_current_floor_area() != AREA_PIONEER2_EP1) && (get_current_floor_area() != AREA_LOBBY) && (get_current_floor_area() != AREA_PIONEER2_EP2)) {
        TLobby::call_funcs_reverse(field_resource_callbacks, 0x20);
    }
    TLobby::call_funcs_reverse(session_resource_callbacks, 0xE8);
}

s32 TLobby::run_lobby_load_tables() {
    s32 second_result;
    s32 first_result;
    first_result = run_load_callback_table(session_resource_callbacks, 0xE8);
    if (first_result == 0) {
        return first_result;
    }
    if ((get_current_floor_area() != AREA_PIONEER2_EP1) && (get_current_floor_area() != AREA_LOBBY) && (get_current_floor_area() != AREA_PIONEER2_EP2)) {
        second_result = run_load_callback_table(field_resource_callbacks, 0x20);
        if (second_result == 0) {
            return second_result;
        }
    }
    if (get_current_floor_area() == AREA_LOBBY) {
        load_obj_lobby_main();
        load_lobby_textures();
        load_player_tex_texture();
    }
    return 1;
}


s32 TLobby::check_disconnect_conditions() {
    apply_phase_keyboard_mode();
    if (TLobby::run_lobby_load_tables() == 0) {
        TLobby::reset_and_invoke();
        return 1;
    }
    load_area_gsl();
    if (TLobby::update_key_machine() == 0) {
        close_gsl_archive();
        TLobby::reset_and_invoke();
        return 1;
    }
    if (load_current_floor_resources() == 0) {
        close_gsl_archive();
        TLobby::reset_and_invoke();
        return 1;
    }
    close_gsl_archive();
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_and_invoke();
        return 1;
    }
    TLobby::clear_callback_and_reset_keyboard();
    return 0;
}
void TLobby::reset_and_invoke() { TLobby::reset_keyboard_state(); TLobby::invoke_callback(); TLobby::clear_callback_and_reset_keyboard(); }



    extern short quest_collision_next_id;
void reset_quest_collision_ids_on_floor_load(void) { quest_collision_next_id = 0; }

void reset_quest_collision_ids_on_floor_free(void) { quest_collision_next_id = 0; }


saddr TWindowSubComCard::get_card_slot(s32 index) {
    s32 state;
    s32 slot;
    saddr addr;
    slot = index;
    if (slot < 0) {
        addr = 0;
        return 0;
    }
    if (slot >= 0x1C) {
        addr = 0;
        return 0;
    }
    state = TAdSinglePlyChrSelectGC::get_state();
    addr = state + 0x10000;
    addr = state + 0xD2C4;
    addr += slot * 0x90;
    return addr;
}

void TLobby::collect_active_card_ids() {
    CollectActiveCardIdsL *self = (CollectActiveCardIdsL *)this;
    GuildCardEntry *card;
    s32 *p;
    s32 i;
    s32 n;
    card = (GuildCardEntry *)TWindowSubComCard::get_card_slot(0);
    p = self->ids;
    n = 0;
    i = 0;
    do {
        if (card->is_active() == 0) {
            break;
        }
        *p++ = card->get_card_id();
        i++;
        n++;
        card++;
    } while (i < 0x1c);
    self->count = n;
    for (i = n; i < 0x1e; i++) {
        *p++ = 0;
    }
}

void TLobby::send_status_packet() {
    char lobby[0x84];

    ((TLobby *)lobby)->collect_active_card_ids();
    protocol_instance->send_c6_packet((TBlockedSenders *)lobby);
}
