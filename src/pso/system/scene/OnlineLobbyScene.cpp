#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/ControllerInput.h"
#include "pso/network/NetworkConnect.h"
#include <string.h>
#include "pso/system/save/CardFileInfo.h"
#include "pso/network/TGameProtocol.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/unk/TQuestManager.h"
#include "pso/ui/frontend/DrawLineResource.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/system/scene/OnlineLobbyScene.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/system/debug_print.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobbyAutoReply.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/map/TSetManager.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerCreate.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/object/base/TObjBase.h"
#include "pso/render/TFogCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowOptionCtrl_8034C384.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/system/byteswap.h"
#include "pso/system/main_loop.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/map/area/AreaScene.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/unk/TObjFreezeShell.h"
#include "dolphin/base/PPCArch.h"
#include "pso/ui/frontend/TAdDialingGC_801A4C90.h"
#include "pso/unk/text_801F3774.h"
#include "pso/unk/TLobby_80209524.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_800FA260.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/object/warp/TObjLaboMapWarp_80185248.h"


struct Pair_801A3CFC { s32 f0; s32 f4; };

extern "C" {
int clear_keyboard_input_flag(void);
// The run_*_frame callers test this as an int, while SystemBootInit defines it bool.
s32 is_keyboard_active();
s32 clear_keyboard_key_state();
int request_main_phase(int);
extern s32 lbl_805D5718;
s32 load_area_scene_and_init(void *);
}
void set_fallback_main_phase(s32 phase);
void set_queued_main_phase(s32 phase);
void deactivate_keyboard(void);
extern "C" {
void TLobby__sub_801A3E94(void);
}
extern "C" {
void TLobby__sub_801A3CF8(void);
int TLobby__sub_801A3E8C(void);
}
extern "C" {
s32 reset_story_select__6TLobbyFPv();
}

// Load and release hooks of the online lobby scene, in pairs: run_online_lobby_scene runs
// each load front to back (run_load_callback_table), cleanup_online_lobby_scene each release
// back to front (TLobby::call_funcs_reverse).
FloorResourceCallbacks online_lobby_scene_callback_table[43] = {
    {TAdSelectGameModeGC::setup_views, (FloorResourceCallback)TAdSelectGameModeGC::call_enable_camera},
    {init_game_player_actions, release_game_player_actions},
    {init_player_shared, finalize_player_shared},
    {clear_story_flag_list_and_reload, clear_story_flag_list},
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {load_keyboard_resources, free_keyboard_resources},
    {TWindowCtrlMain::reset_windows, TWindowCtrlMain::free_all_windows},
    {TWindowCtrl::close, TWindowCtrl::shutdown},
    {reset_clock_bar_pulse, TLobby__sub_8001ED70},
    {alloc_battle_param_tables, free_battle_param_tables},
    {reset_id_counters, free_id_counters},
    {init_entity_tables, clear_entity_tables},
    {init_scene_fog_system, TFogCtrl::reset},
    {load_light_entry_file, TObjLight::free_shared_data},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {init_item_system, free_item_system},
    {TLobby::load_item_data, free_forest_rel_work_buffer},
    {init_item_drop_tables, free_item_drop_tables},
    {TLobby::create_heap_8000, TLobby::free_heap},
    {TRaderMapCore::create_heap, TRaderMapCore::free_heap},
    {alloc_work_buffer, free_deferred_packet_buffer},
    {init_switch_table, clear_switch_table},
    {TObjFreezeShell::load_freeze_ice_resource, TObjFreezeShell::free_freeze_ice_resource},
    {reset_shop_stock_and_params, clear_all_shop_stock},
    {THunterGuildSeqOffline::reset_quest_result_callbacks, THunterGuildSeqOffline__sub_80213410},
    {TQuestThread::clear_all_floor_handlers, clear_quest_floor_handlers},
    {TObjCityMainWarp::reset, TObjCityMainWarp::free_resources},
    {(FloorResourceCallback)TLobby__sub_80225C64, (FloorResourceCallback)TLobby__sub_80225C44},
    {(FloorResourceCallback)reset_auto_reply_flags_callback, (FloorResourceCallback)clear_auto_reply_flags},
    {(FloorResourceCallback)TLobby__sub_8034C3A4, (FloorResourceCallback)TLobby__sub_8034C384},
    {(FloorResourceCallback)TWindowGetComCard__sub_8007B67C, (FloorResourceCallback)TWindowGetComCard__sub_8007B65C},
    {reset_com_card_list_callback, TLobby::reset_state},
    {clear_received_symbol_chat, TLobby__sub_80077608},
    {reset_choice_search_data, free_choice_search_data},
    {load_word_select_data, TWindowDD::free_buffers},
    {reset_globals, NULL},
    {init_char_slots, free_char_slots},
    {init_jungle_key_slots, unload_jungle_key_slots},
    {(FloorResourceCallback)TLobby__sub_802D39FC, (FloorResourceCallback)TLobby__sub_802D39DC},
    {load_draw_line_task_resource, free_draw_line_task_resource},
    {TObjBoss2Tunnel::reset_state, TObjBoss2Tunnel::free_resources},
    {clear_boss6_player_snapshots, NULL},
};

// Area resources reloaded on a floor change and released with the lobby scene.
FloorResourceCallbacks lobby_area_reload_callbacks[9] = {
    { start_challenge_mode, NULL },
    { TLobby::update_drop_item, NULL },
    { clear_floor_population, NULL },
    { TLobby::load_set_gsl_files, clear_map_set_data },
    { TLobby::load_set_event_gsl, (FloorResourceCallback)TLobby::get_team_state },
    { init_switch_table, clear_switch_table },
    { reset_shop_stock_and_params, clear_all_shop_stock },
    { update_battle_params, NULL },
    { clear_boss6_player_snapshots, NULL },
};
Pair_801A3CFC lobby_udp_test_game_entries[2] = {
    {0x9D6D3202, 0},
    {0x9D6D3201, 0},
};

extern s32 lbl_805D55C0;
s16 lobby_floor_reload_pending;
int new_game_setup_flags;
s32 online_lobby_scene_handle;
s32 online_lobby_frame_counter;
void TLobby::set_flag_and_update() { new_game_setup_flags = (new_game_setup_flags | 0x1); set_floor_transition_ready(&floor_transition_state); }

void init_chr_select() { TKeyBoardControl::reset(); TLobby::send_logout(); TAdSinglePlyChrSelectGC::init(); set_queued_main_phase(9); request_main_phase(18); }
void reset_to_chr_select() { reset_controller_input_state(); TLobby::send_logout(); TLobby::free_objects(); clear_keyboard_input_flag(); TLobby::clear_counter(); TAdSinglePlyChrSelectGC::init(); set_queued_main_phase(9); request_main_phase(18); }
void TLobby__sub_801A3CF8(void) {  }

void start_udp_test_game() {
    ((TLobby *)((u8 *)&lobby_udp_test_game_entries[0]))->bswap_udp_test_header();
    ((TLobby *)((u8 *)&lobby_udp_test_game_entries[1]))->bswap_udp_test_header();
    TPlyJoinGame msg;
    memset(&msg, 0, sizeof(msg));
    msg.client_id = local_client_id;
    msg.leader_id = designated_client_id;
    msg.disable_udp = 0;
    msg.lobby_data[0].tag.m_tag2 = 1;
    msg.lobby_data[0].tag.m_guildcard_number = 0x013158B7;
    msg.lobby_data[0].ip_addr = lobby_udp_test_game_entries[0].f4;
    msg.lobby_data[0].client_id = 0;
    strcpy(msg.lobby_data[0].name, "UDPTEST-1");
    msg.lobby_data[1].tag.m_tag2 = 1;
    msg.lobby_data[1].tag.m_guildcard_number = 0x013158B8;
    msg.lobby_data[1].ip_addr = lobby_udp_test_game_entries[1].f4;
    msg.lobby_data[1].client_id = 1;
    strcpy(msg.lobby_data[1].name, "UDPTEST-2");
    TLobby::handle_game_join(&msg);
    game_protocol_instance->delete_children();
    TLobby::open_udp_socket_for_player(1 - local_client_id);
}

TPlyJoinGame::TPlyJoinGame() {}

void TLobby::bswap_udp_test_header() {
    u8 *bytes = (u8 *)this;
    *(u32 *)(bytes + 4) = bytes[0] + (bytes[1] << 8) + (bytes[2] << 16) + (bytes[3] << 24);
    bswap_32((u32 *)(&this->m_flags));
}

int TLobby__sub_801A3E8C(void) { return 0; }
void TLobby__sub_801A3E94(void) {  }

void reload_lobby_floor_scene(void) {
    TObject holder(NULL);
    TLobby::clear_counters();
    TLobby::reset_state_flags();
    TObjPlayer::send_local_player_invisible();
    TLobby::stop_audio_streams();
    process_pending_resources();
    reset_controller_input_state();
    TLobby::send_game_character();
    render_tick();
    render_tick();
    leader_selection.find_leader_section_id(designated_client_id);
    TLobby::free_objects();
    main_task.delete_layer_children();
    main_task.resume_layers();
    promote_area_floor(&floor_transition_state);
    TLobby::reset_counter();
    reset_story_select__6TLobbyFPv();
    TLobby::get_team_state();
    clear_floor_population();
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    load_floor_object_set(0xF);
    initialize_floor_transition(&floor_transition_state, 0xF, TLobby::lobby_number);
    floor_transition_state.set_next_floor_index(0);
    set_current_floor_area(0xF);
    TScene::set_scene(TLobby::lobby_number);
    load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state));
    load_battle_param_entry();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    load_quest_story_flags(0);
    TLobby__sub_801A3E94();
    TLobby::process_deferred_player_setup();
    TLobby::install_game_join_handlers();
    TObjPlayer::send_local_player_visible();
    TLobby::send_room_change(TLobby::lobby_number);
    init_jungle_key_slots();
    lobby_floor_reload_pending = 0;
}

void send_and_handle() { blocking_vsync(); }

void blocking_vsync() {
    TLoadCtrl::set_field1C(0);
    begin_gx_frame();
    if ((s32) lbl_805D5718 != 0) {
        main_task.begin_frame();
        main_task.run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        ::debug_print("BlockingVsync");
        render_tick();
    } else {
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render();
        main_task.render_screen_overlay();
        process_async_file_reads();
        update_sound_request_slots();
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
        TAdSinglePlyChrSelectGC::noop();
    }
    TLoadCtrl::set_field1C(1);
    render_tick();
}

void reload_floor_scene() {
    s32 i;
    TObjPlayer *p;
    s32 j;
    TLobby::reset_state_flags();
    TObjPlayer::send_local_player_invisible();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    TObject holder(NULL);
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            p->set_parent(&holder);
        }
    }
    main_task.delete_layer_children();
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::poll_default();
    load_floor_scene();
    init_area_lights();
    depart_floor_population();
    clear_floor_population();
    load_floor_object_set(0xF);
    arrive_floor_population();
    TLobby::create_tasks();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = get_player_by_client_id(j);
        if (p != NULL) {
            p->set_parent((TObject *)tl_03);
            p->reset_motion_fields();
        }
    }
    TLobby::process_deferred_player_setup();
    TObjPlayer::send_local_player_visible();
    TObjBgmColCtrl::create_controller();
}

void TLobby::free_objects() {
    TRaderMapCore::free_map_data();
    clear_switch_table();
    TTecLuker::apply_all_players();
    TLobby::reset_floor_items();
    delete_npc_players();
    if (quest_mission_manager != NULL) {
        quest_mission_manager->queue_destruction();
    }
    clear_enabled_main_warps();
    THunterGuildSeqOffline::reset_quest_result_callbacks();
    TLobby::clear_counter();
    TLobby::reset_door_state();
    TObjDoor::reset_instance();
    TLobby::set_cleanup_flag();
    TLobby::reset_quest_counter();
    TLobby::clear_quest_state();
}

void start_quest_mission(void) {
    s32 i;
    s32 j;
    TQuestThread *q;
    TObjPlayer *p;
    TObject holder(NULL);
    TLobby::reset_state_flags();
    TObjPlayer::send_local_player_invisible();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    leader_selection.find_leader_section_id(designated_client_id);
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            p->set_parent(&holder);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TLobby::sync_story_select();
    TAdStorySelectGC::set_state(0);
    TKeyBoardControl::update();
    TLobby::free_objects();
    TLobby::get_team_state();
    clear_floor_population();
    TQuestThread::clear_all_floor_handlers();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(1);
    TQuestThread::create_by_mode();
    clear_quest_floor_designations();
    if (quest_mission_manager != NULL) {
        q = new TQuestThread(quest_mission_manager, 0);
        q->run_task();
    }
    TLobby::setup_quest_list();
    TLobby::set_enemy_mode_flag();
    TQuestListOnline::ensure_online_quests_loaded();
    load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state));
    unlock_main_warp_destination(get_current_floor());
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = get_player_by_client_id(j);
        if (p != NULL) {
            p->set_parent((TObject *)tl_03);
            p->reset_motion_fields();
        }
    }
    TLobby::process_deferred_player_setup();
    TObjPlayer::send_local_player_visible();
    TQuestThread::create_for_floor();
}

void change_floor_reload_area(void) {
    s32 i;
    s32 j;
    s32 r;
    void *q;
    TObjPlayer *p;
    TObject holder(NULL);
    TLobby::reset_state_flags();
    TObjPlayer::send_local_player_invisible();
    TLobby::stop_audio_streams();
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    leader_selection.find_leader_section_id(designated_client_id);
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            p->set_parent(&holder);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    floor_transition_state.clear_ready_flag_unless_locked();
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    if (new_game_setup_flags & 1) {
        new_game_setup_flags &= ~1;
        reset_enemy_and_object_ids();
        select_game_player_actions();
        TLobby__sub_80207E24(game_variations, 0x80);
        apply_phase_keyboard_mode();
        run_load_callback_table(lobby_area_reload_callbacks, sizeof(lobby_area_reload_callbacks));
        TLobby::reset_item_id_counters();
        TLobby::reset_floor_items();
    }
    r = ((s32)load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state)));
    unlock_main_warp_destination(get_current_floor());
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = get_player_by_client_id(j);
        if (p != NULL) {
            p->set_parent((TObject *)tl_03);
            p->reset_motion_fields();
        }
    }
    if (r != 0) {
        TLobby__sub_801A3E94();
    }
    TObjPlayer::send_local_player_visible();
    TLobby::process_deferred_player_setup();
    TQuestThread::create_for_floor();
    if (r != 0) {
        TAdSinglePlyChrSelectGC::load_character_from_card(0);
    }
    if (quest_area_manager != NULL) {
        new TQuestThread(quest_area_manager, 0);
    }
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::clear_callback_and_reset_keyboard();
    }
    TLobby::clear_callback_and_reset_keyboard();
}

void cleanup_online_lobby_scene(void) {
    s32 i;
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    TLobby::send_logout();
    TLobby::free_objects();
    main_task.delete_layer_children();
    main_task.resume_layers();
    ((TObject *)tl_su)->delete_children();
    PPCSync();
    i = 0;
    do {
        render_tick();
        i += 1;
    } while (i < 0x1E);
    cleanup();
    if (online_lobby_scene_handle == 0) {
        run_area_scene_cleanup(&floor_transition_state);
    }
    TLobby::free_single_player_chr_select();
    release_lobby_player_actions();
    TLobby::call_funcs_reverse(lobby_area_reload_callbacks, sizeof(lobby_area_reload_callbacks));
    TLobby::call_funcs_reverse(online_lobby_scene_callback_table, sizeof(online_lobby_scene_callback_table));
    local_client_id = 0;
    lobby_state_flags = 0;
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick();
}

void run_lobby_frame() {
    s32 frame_count;
    begin_gx_frame();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    take_snapshot();
    if (((s32) lbl_805D55C0 == 0) && (poll_memcard_result((int) ((s8)TAdSinglePlyChrSelectGC::get_chr_select_state())) != -1)) {
        if (TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0) {
            online_lobby_frame_counter = 0;
        } else {
            frame_count = online_lobby_frame_counter + 1;
            online_lobby_frame_counter = frame_count;
            if (frame_count > 0xC) {
                TLobby::disconnect_protocol();
            }
        }
    }
    update_periodic_tick();
    if ((static_cast<s8>(poll_reset_request()) != 0) || ((s32) TLobby::idle_timeout_active == 1)) {
        reset_to_chr_select();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TLobby::send_logout();
        request_main_phase(0);
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        change_floor_reload_area();
        clear_keyboard_key_state();
    }
    if (is_keyboard_active() != 0) {
        reload_floor_scene();
        deactivate_keyboard();
    }
    if (TKeyBoardControl::get_input() != 0) {
        reload_lobby_floor_scene();
        clear_keyboard_input_flag();
    }
    render_tick();
}

void run_main_frame() {
    s32 frame_count;
    begin_gx_frame();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    take_snapshot();
    run_challenge_frame();
    if (((s32) lbl_805D55C0 == 0) && (poll_memcard_result((int) ((s8)TAdSinglePlyChrSelectGC::get_chr_select_state())) != -1)) {
        if (TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0) {
            online_lobby_frame_counter = 0;
        } else {
            frame_count = online_lobby_frame_counter + 1;
            online_lobby_frame_counter = frame_count;
            if (frame_count > 0xC) {
                TLobby::disconnect_protocol();
            }
        }
    }
    update_periodic_tick();
    if (TKeyBoardControl::get_input() != 0) {
        start_quest_mission();
        clear_keyboard_input_flag();
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        change_floor_reload_area();
        clear_keyboard_key_state();
    }
    if (is_keyboard_active() != 0) {
        reload_floor_scene();
        deactivate_keyboard();
    }
    if (lobby_floor_reload_pending == 1) {
        reload_lobby_floor_scene();
    }
    if ((static_cast<s8>(poll_reset_request()) != 0) || ((s32) TLobby::idle_timeout_active == 1)) {
        init_chr_select();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TLobby::send_logout();
        request_main_phase(0);
    }
    render_tick();
}

void update_camera_state() {
    if (is_quest_active() != 0) {
        run_lobby_frame();
        return;
    }
    run_main_frame();
}

void run_online_lobby_scene(void) {
    TLobby *lobby;
    new_game_setup_flags = 0;
    lobby_state_flags = 0;
    set_copy_clear_color_argb(0, 0, 0);
    TKeyBoardControl::update();
    TLobby__sub_801F3774();
    reset_controller_input_state();
    clear_keyboard_key_state();
    set_fallback_main_phase(2);
    set_queued_main_phase(0xF);
    clear_resource_load_tasks();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::poll_default();
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(online_lobby_scene_callback_table, sizeof(online_lobby_scene_callback_table));
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLoadCtrl::cleanup_scene();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TLobby__sub_80207F10();
    load_floor_object_set(0xF);
    TAdDialingGC::open();
    ((TAdDialingGC *)tl_window)->create();
    online_lobby_scene_handle = init_network_and_connect();
    TAdDialingGC::set_dial_result(online_lobby_scene_handle);
    TLoadCtrl::set_field1C(0);
    while (TAdDialingGC::get_instance() != 0) {
        begin_gx_frame();
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render();
        main_task.render_screen_overlay();
        process_async_file_reads();
        update_sound_request_slots();
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
        if (static_cast<s8>(poll_reset_request()) != 0) {
            break;
        }
        render_tick();
    }
    TLoadCtrl::set_field1C(1);
    TAdDialingGC::close();
    if (online_lobby_scene_handle != 0) {
        TAdSinglePlyChrSelectGC::init();
        set_queued_main_phase(2);
        request_main_phase(0x12);
        TLoadCtrl::cleanup_scene();
    } else {
        lobby = new TLobby(tl_su);
        new TGameProtocol(tl_su);
        TLobby__sub_801A3CF8();
        TLobby::reset_state_flags();
        if (TLobby__sub_801A3E8C() != 0) {
            TLobby::load_set_gsl_files();
            floor_transition_state.init_range(0);
        } else {
            floor_transition_state.init_range(0xF);
            floor_transition_state.set_next_floor_index(0);
            set_current_floor_area(0xF);
            TScene::set_scene(0);
        }
        load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state));
        TLoadCtrl::cleanup_scene();
        TLobby::process_deferred_player_setup();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render_screen_overlay();
        if (TLobby__sub_801A3E8C() != 0) {
            start_udp_test_game();
        } else {
            TLobby::run_join_lobby_connect(lobby);
        }
    }
    actor_frame_tick = 0;
    lobby_floor_reload_pending = 0;
    online_lobby_frame_counter = 0;
    render_tick();
}

void update_periodic_tick() {
    if ((lobby_state_flags & 1) && ((actor_frame_tick % 900) == 0) && (TLobby::protocol_instance != NULL)) {
        TLobby::protocol_instance->send_keepalive();
    }
}
void set_floor_transition_ready(FloorTransition *transition) { transition->state_flags |= 1; }
void FloorTransition::set_next_floor_index(s32 floor) { next_floor = floor; }
void TLobby::reset_counter() { challenge_task_created = 0; }
