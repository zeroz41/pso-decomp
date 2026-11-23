#include "pso/player/GuildCardEntry.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby_8007B858.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/TUnk_80499970.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/system/TLanguage.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/unk/TUnk_804F07C8.h"
#include "pso/map/TSetManager.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobbyEventTheme.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TUnk_8048E5F4.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/unk/TLobby_802D79EC.h"
#include "pso/render/reflection.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_800F7744.h"
#include "pso/unk/text_800C7FEC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/npc/TNpcPlayer_8034DAA0.h"
#include "pso/unk/TLobby_80191218.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/unk/TUnk_804EDAC0.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/unk/TLobby_8033ECB0.h"
#include "pso/unk/TUnk_804EFA88.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/unk/TLobby_8015ABD0.h"
#include "pso/unk/TLobby_8036B204.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCineCtrl.h"
#include "pso/unk/TLobby_800F8AA8.h"

void load_particle_entry_resources(void);
void init_partner_dialogue(void);
void load_technique_resources(void);


extern "C" {
void TLobby__sub_802A5154(void);
s32 run_load_callback_table(void *, int);
void TSceneSora__sub_80207430(void);
void TTecLuker__sub_80234F08(void);
void TTecLuker__sub_80234F48(void);
void fn_80198E84(void);
s32 create_area_fog_ctrl();
s32 activate_triggered_floor_events();
s32 cleanup_game_objects__9TMainTaskFv();
s32 restore_floor_telepipes();
s32 __ct__15TWindowCtrlMainFv();
s32 TWindowTimer__sub_80198D98();

extern saddr tl_00;
extern saddr tl_01;
extern saddr tl_06;
extern saddr tl_particlemodel;
extern saddr tl_fade;

// Session resources, loaded front to back by TLobby::run_lobby_load_tables and released
// back to front by TLobby::clear_session_buffers (load, release pairs).
FloorResourceCallbacks lbl_8048D4C0[29] = {
    {TCameraCtrl::reset_view_state, TCameraCtrl::reset},
    {TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view},
    {(FloorResourceCallback)TLobby__sub_802D7A0C, TLobby::forward_npc_enemy},
    {create_reflection_target, destroy_reflection_target},
    {TObjPlayer::init_render_target_singleton, TObjPlayer::free_singleton},
    {TScene::load_current_floor, TScene::free_scene_resources},
    {TSceneSora::load_sky_resources, TSceneSora__sub_80207430},
    {TRaderMapCore::load_map_resources, TRaderMapCore::unload_floor_map},
    {TLobby::setup_floor_decorations, TLobby::clear_floor_flags_and_depart},
    {TLobby::clear_flag_on_phase_e, TLobby__sub_800F7744},
    {clear_legacy_enemy_kill_flags, release_legacy_enemy_kill_flags},
    {load_particle_entry_resources, TParticleCtrl::free_all},
    {TFogCtrl::update_fog_entries, TFogCtrl::fn_800FBA58},
    {init_partner_dialogue, TNpcPlayer__sub_8034EDB8},
    {TLobby__sub_80191270, TLobby__sub_80191264},
    {TLobby__sub_8007BBEC, TLobby__sub_8007BBF8},
    {reset_and_init_capture_texture, reset_and_release_capture_texture},
    {TObjPlayer__sub_80083F38, (FloorResourceCallback)TObjPlayer__sub_80083F04},
    {load_indirect_dat, TEffIndirectCtrl::free_all},
    {(FloorResourceCallback)TLobby__sub_802D39BC, (FloorResourceCallback)close_trade_request__6TLobbyFPv},
    {TLobby__sub_8032BE3C, TLobby__sub_8032BE30},
    {KeyboardKeyState::reset_global_keys_b, KeyboardKeyState::reset_global_keys_a},
    {TLobby__sub_80279708, TLobby__sub_802796FC},
    {TLobby__sub_8033EE04, TLobby__sub_8033EDF8},
    {clear_signboard_texture_buffer_pointer, TLobby::free_global_buffer},
    {TLobby__sub_8015ABD4, TLobby__sub_8015ABD0},
    {TLobby__sub_8036B510, TLobby__sub_8036B50C},
    {TWindowReturnCity__sub_8026D4C0, TWindowReturnCity__sub_8026D4BC},
    {TTecLuker__sub_80234F48, TTecLuker__sub_80234F08},
};

// Field-only resources: loaded and released only outside Pioneer 2 and the lobby.
FloorResourceCallbacks lbl_8048D5A8[4] = {
    {load_technique_resources, TLobby__sub_8022F068},
    {load_photon_blast_resources, release_photon_blast_resources},
    {load_camera_banks, free_camera_banks},
    {TLobby::update_difficulty, NULL},
};

void TLobby::create_tasks() {
    uaddr tmp;
    create_area_fog_ctrl();
    if (is_split_screen() == 0) {
        new TUnk_8048E5F4((TObject *)tl_particlemodel, 1);
        new TUnk_8048E5F4((TObject *)tl_particlemodel, 0);
        new TUnk_804EDAC0((TObject *)tl_particlemodel);
        new TUnk_804EFA88((TObject *)tl_particlemodel);
    }
    cleanup_game_objects__9TMainTaskFv();
    TScene::create();
    TSceneSora::create_instance();
    TSetManager::create();
    activate_triggered_floor_events();
    tmp = (uaddr)TObject::operator new(0x1C);
    if (tmp != 0U) {
        __ct__15TWindowCtrlMainFv();
    }
    new TWindowCtrl((TObject *)tl_00);
    new TUnk_80499970((TObject *)tl_fade);
    TLobby::set_fade_params(0);
    new TCineCtrl((TObject *)tl_00);
    TRaderMapCore::create();
    restore_floor_telepipes();
    new TUnk_804F07C8((TObject *)tl_06);
    new TSwitch((TObject *)tl_00);
    TQuestColCtrl::init();
    if (get_current_floor_area() == AREA_LOBBY) {
        TLobbyEventTheme::create();
    }
    if ((get_current_floor_area() == AREA_LOBBY) && (TLobby::is_scene_ready() != 0)) {
        TWindowTimer__sub_80198D98();
    }
    if ((get_main_phase() == 0xF) && ((get_current_floor_area() == AREA_PIONEER2_EP1) || (get_current_floor_area() == AREA_PIONEER2_EP2))) {
        new THunterGuildSeqOnlineTask((TObject *)tl_01);
    }
    new TTecCtrl((TObject *)tl_01);
}

void TLobby::clear_session_buffers() {
    if (get_current_floor_area() == AREA_LOBBY) {
        TLobby::free_dialing_gc();
        fn_80198E84();
        free_obj_lobby_main();
    }
    if ((get_current_floor_area() != AREA_PIONEER2_EP1) && (get_current_floor_area() != AREA_LOBBY) && (get_current_floor_area() != AREA_PIONEER2_EP2)) {
        TLobby::call_funcs_reverse(lbl_8048D5A8, 0x20);
    }
    TLobby::call_funcs_reverse(lbl_8048D4C0, 0xE8);
}

s32 TLobby::run_lobby_load_tables() {
    s32 temp_r3;
    s32 temp_r3_2;
    temp_r3_2 = run_load_callback_table(lbl_8048D4C0, 0xE8);
    if (temp_r3_2 == 0) {
        return temp_r3_2;
    }
    if ((get_current_floor_area() != AREA_PIONEER2_EP1) && (get_current_floor_area() != AREA_LOBBY) && (get_current_floor_area() != AREA_PIONEER2_EP2)) {
        temp_r3 = run_load_callback_table(lbl_8048D5A8, 0x20);
        if (temp_r3 == 0) {
            return temp_r3;
        }
    }
    if (get_current_floor_area() == AREA_LOBBY) {
        load_obj_lobby_main();
        TLanguage::load_lobby_textures();
        TLobby__sub_802A5154();
    }
    return 1;
}

s32 load_area_gsl();
s32 close_gsl_archive();


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
}

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct L_8007BC5C { u8 pad0; u8 count; u8 pad2[2]; s32 ids[30]; };

    extern short quest_collision_next_id;
void TLobby__sub_8007BBEC(void) { quest_collision_next_id = 0; }

void TLobby__sub_8007BBF8(void) { quest_collision_next_id = 0; }

extern saddr TLobby__protocol_instance;

saddr TWindowSubComCard::get_card_slot(s32 arg0) {
    s32 state;
    s32 var_r31;
    saddr var_r3;
    var_r31 = arg0;
    if (var_r31 < 0) {
        var_r3 = 0;
        return 0;
    }
    if (var_r31 >= 0x1C) {
        var_r3 = 0;
        return 0;
    }
    state = TAdSinglePlyChrSelectGC::get_state();
    var_r3 = state + 0x10000;
    var_r3 = state + 0xD2C4;
    var_r3 += var_r31 * 0x90;
    return var_r3;
}

void TLobby::collect_active_card_ids() {
    L_8007BC5C *arg0 = (L_8007BC5C *)this;
    u8 *card;
    s32 *p;
    s32 i;
    s32 n;
    card = (u8 *)TWindowSubComCard::get_card_slot(0);
    p = arg0->ids;
    n = 0;
    i = 0;
    do {
        if (reinterpret_cast<GuildCardEntry *>(card)->is_active() == 0) {
            break;
        }
        *p++ = reinterpret_cast<GuildCardEntry *>(card)->get_card_id();
        i++;
        n++;
        card += 0x90;
    } while (i < 0x1c);
    arg0->count = n;
    for (i = n; i < 0x1e; i++) {
        *p++ = 0;
    }
}

void TLobby::send_status_packet() {
    char lobby[0x84];

    ((TLobby *)lobby)->collect_active_card_ids();
    ((TLobby *)TLobby__protocol_instance)->send_c6_packet((s32 *) lobby);
}
