#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/ControllerInput.h"
#include <string.h>
#include "pso/system/save/CardFileInfo.h"
#include "pso/network/TGameProtocol.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/unk/TUnk_804C8678.h"
#include "pso/ui/frontend/DrawLineResource.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "types.h"
#include "pso/unk/TLobby_801A3C48.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/system/debug_print.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby.h"
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
#include "pso/ui/city/TShopGetItemWindow_8021F0A4.h"
#include "pso/ui/city/TShopGetItemWindow_8021F074.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/unk/TLobby_802A7290.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
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
#include "pso/object/warp/TObjCityMainWarp_801867F4.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowOptionCtrl_8034C384.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/ui/chat/TWindowChat_800774C0.h"
#include "pso/system/byteswap.h"
#include "pso/system/main_loop.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/npc/NpcPartnerControl.h"


struct Pair_801A3CFC { s32 f0; s32 f4; };

struct VBase_18_801A4268 { char pad[0x18]; };

struct VObj_18_801A4268 : VBase_18_801A4268 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct VBase_18_801A441C { char pad[0x18]; };

struct VObj_18_801A441C : VBase_18_801A441C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};


struct PlB_801A40D8 { u8 pad[0x18]; };

struct Pl_801A40D8 : PlB_801A40D8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
};

extern "C" {
void clear_enabled_main_warps(void);
    extern int challenge_task_created;
int TKeyBoardControl__sub_8000F95C(void);
s32 is_keyboard_active();
s32 clear_keyboard_key_state();
int request_main_phase(int);
s32 TLobby__sub_8006EF90();

s32 func_803DCDFC__Fv();
s32 cleanup__6TLobbyFv();
s32 PPCSync();
extern s32 lbl_805D5718;
s32 unlock_main_warp_destination();
s32 load_area_scene_and_init(void *);
s32 run_load_callback_table(void *, s32);
void TLobby__sub_801A3E94(void);
s32 TAdDialingGC__sub_801A4C90();
s32 TKeyBoardControl__sub_8000F90C(int);
int set_queued_main_phase(int);
s32 run_join_lobby_connect__6TLobbyFi(void *);
s32 TLobby__sub_80146908();
void TLobby__sub_801A3CF8(void);
int TLobby__sub_801A3E8C(void);
u32 TAdDialingGC__sub_801A4C9C();
s32 TLobby__sub_801F3774();
s32 TLobby__sub_8020A6B0(int);
s32 TAdDialingGC__sub_80328730();
void TLobby__sub_801F494C(u16 client);
s32 reset_story_select__6TLobbyFPv();
s32 init_key_slots__15TOKeyJungleMainFPv();
void TWindowCtrlMain__sub_8024D838(void);
void TObjPlayer__sub_80156934(void);
void TRaderMapCore__sub_801F95CC(void);
void TWindowDD__sub_80344114(void);
void TQuestThread__sub_801F5D88(void);
void TLobby__sub_8029B2A4(void);
void reset_globals(void);
}
void init_scene_fog_system(void);
void clear_received_symbol_chat(void);

// Load and release hooks of the online lobby scene, in pairs: run_online_lobby_scene runs
// each load front to back (run_load_callback_table), cleanup_online_lobby_scene each release
// back to front (TLobby::call_funcs_reverse).
FloorResourceCallbacks online_lobby_scene_callback_table[43] = {
    {TAdSelectGameModeGC__sub_802C478C, (FloorResourceCallback)TAdSelectGameModeGC::call_enable_camera},
    {TLobby::enable_and_refresh, disable_and_free_boss4rock_buffer},
    {TObjPlayer::init_shared, TObjPlayer::finalize_shared},
    {TLobby::clear_story_flags_and_reset_camera, TLobby::clear_story_flag_list},
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {TKeyBoardControl__sub_80131F60, TKeyBoardControl__sub_80131F5C},
    {TWindowCtrlMain__sub_8024D838, TWindowCtrlMain::free_all_windows},
    {TWindowCtrl::close, TWindowCtrl::shutdown},
    {TLobby__sub_8001ED74, TLobby__sub_8001ED70},
    {alloc_battle_param_tables, TLobby::free_boss4_rock},
    {reset_id_counters, free_id_counters},
    {TObjPlayer::reset, TObjPlayer__sub_80156934},
    {init_scene_fog_system, TFogCtrl::reset},
    {load_light_entry_file, TObjLight::free_shared_data},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {init_item_system, free_item_system},
    {TLobby::load_item_data, TLobby__sub_802083C0},
    {init_item_drop_tables, free_item_drop_tables},
    {TLobby::create_heap_8000, TLobby::free_heap},
    {TRaderMapCore__sub_801F95CC, TRaderMapCore::free_heap},
    {alloc_work_buffer, TLobby__sub_801A5478},
    {init_switch_table, clear_switch_table},
    {TLobby::load_freeze_ice_resource, TLobby::destroy_global_singleton},
    {reset_shop_stock_and_params, clear_all_shop_stock},
    {THunterGuildSeqOffline::reset_quest_result_callbacks, THunterGuildSeqOffline__sub_80213410},
    {TQuestThread::clear_all_floor_handlers, TQuestThread__sub_801F5D88},
    {TObjCityMainWarp::reset, TObjCityMainWarp__sub_80186AB8},
    {(FloorResourceCallback)TLobby__sub_80225C64, (FloorResourceCallback)TLobby__sub_80225C44},
    {(FloorResourceCallback)TLobby__sub_8001DC04, (FloorResourceCallback)TLobby::forward_8001DBD8},
    {(FloorResourceCallback)TLobby__sub_8034C3A4, (FloorResourceCallback)TLobby__sub_8034C384},
    {(FloorResourceCallback)TWindowGetComCard__sub_8007B67C, (FloorResourceCallback)TWindowGetComCard__sub_8007B65C},
    {TLobby__sub_8024285C, TLobby::reset_state},
    {clear_received_symbol_chat, TLobby__sub_80077608},
    {reset_choice_search_data, free_choice_search_data},
    {TWindowDD__sub_80344114, TWindowDD::free_buffers},
    {reset_globals, NULL},
    {TLobby::init_char_slots, TLobby__sub_801C3A40},
    {(FloorResourceCallback)TOKeyJungleMain::init_key_slots, TLobby__sub_8029B2A4},
    {(FloorResourceCallback)TLobby__sub_802D39FC, (FloorResourceCallback)TLobby__sub_802D39DC},
    {load_draw_line_task_resource, free_draw_line_task_resource},
    {TObjBoss2Tunnel::reset_state, TObjBoss2Tunnel__sub_8007DD24},
    {clear_boss6_player_snapshots, NULL},
};

// Area resources reloaded on a floor change and released with the lobby scene.
FloorResourceCallbacks lobby_area_reload_callbacks[9] = {
    { TLobby::init_on_main_phase, NULL },
    { TLobby::update_drop_item, NULL },
    { clear_floor_population, NULL },
    { TLobby::load_set_gsl_files, clear_map_set_data },
    { TLobby::load_set_event_gsl, (FloorResourceCallback)TLobby::get_team_state },
    { init_switch_table, clear_switch_table },
    { reset_shop_stock_and_params, clear_all_shop_stock },
    { TLobby::update_difficulty, NULL },
    { clear_boss6_player_snapshots, NULL },
};
Pair_801A3CFC lobby_udp_test_game_entries[2] = {
    {0x9D6D3202, 0},
    {0x9D6D3201, 0},
};

void deactivate_keyboard(void);
extern s32 actor_frame_tick;
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern s32 lbl_805D55C0;
s16 TLobby__data_805D5CE8;
int new_game_setup_flags;
s32 online_lobby_scene_handle;
s32 online_lobby_frame_counter;
void clear_resource_load_tasks(void);
extern s32 local_client_id;
void process_pending_resources(void);
void clear_quest_floor_designations(void);
void start_quest_mission(void);
void change_floor_reload_area(void);
void load_battle_param_entry(void);
void reload_lobby_floor_scene(void);
void init_area_lights(void);
void load_floor_scene(void);
void TLobby::set_flag_and_update() { new_game_setup_flags = (new_game_setup_flags | 0x1); set_floor_transition_ready(&floor_transition_state); }

void TLobby::init_chr_select() { TKeyBoardControl::reset(); TLobby::send_logout(); TAdSinglePlyChrSelectGC::init(); set_queued_main_phase(9); request_main_phase(18); }
void TLobby::reset_to_chr_select() { reset_controller_input_state(); TLobby::send_logout(); TLobby::free_objects(); TKeyBoardControl__sub_8000F95C(); TLobby::clear_counter(); TAdSinglePlyChrSelectGC::init(); set_queued_main_phase(9); request_main_phase(18); }
void TLobby__sub_801A3CF8(void) {  }

void TLobby::start_udp_test_game() {
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
    u8 *arg0 = (u8 *)this;
    *(u32 *)(arg0 + 4) = arg0[0] + (arg0[1] << 8) + (arg0[2] << 16) + (arg0[3] << 24);
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
    TLobby__sub_8020A6B0(0xF);
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
    TLobby__sub_801F494C(0);
    TLobby__sub_801A3E94();
    TLobby::process_deferred_player_setup();
    TLobby::install_game_join_handlers();
    TObjPlayer::send_local_player_visible();
    TLobby::send_room_change(TLobby::lobby_number);
    init_key_slots__15TOKeyJungleMainFPv();
    TLobby__data_805D5CE8 = 0;
}

void TLobby::send_and_handle() { TLobby::blocking_vsync(); }

void TLobby::blocking_vsync() {
    TLoadCtrl::set_field1C(0);
    func_803DCDFC__Fv();
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

void TLobby::reload_floor_scene() {
    s32 i;
    Pl_801A40D8 *p;
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
        p = (Pl_801A40D8 *)get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent(&holder);
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
    TLobby__sub_8020A6B0(0xF);
    arrive_floor_population();
    TLobby::create_tasks();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = (Pl_801A40D8 *)get_player_by_client_id(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            p->v6();
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
    VObj_18_801A4268 *q;
    VObj_18_801A4268 *p;
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
        p = (VObj_18_801A4268 *) get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent(&holder);
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
        q = (VObj_18_801A4268 *)new TQuestThread(quest_mission_manager, 0);
        q->m1();
    }
    TLobby::setup_quest_list();
    TLobby::set_enemy_mode_flag();
    TQuestListOnline::ensure_online_quests_loaded();
    load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state));
    get_current_floor();
    unlock_main_warp_destination();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = (VObj_18_801A4268 *) get_player_by_client_id(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            p->m6();
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
    VObj_18_801A441C *p;
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
        p = (VObj_18_801A441C *) get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent(&holder);
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
        TAdDialingGC__sub_801A4C90();
        TLobby__sub_80207E24(game_variations, 0x80);
        apply_phase_keyboard_mode();
        run_load_callback_table(lobby_area_reload_callbacks, sizeof(lobby_area_reload_callbacks));
        TLobby::reset_item_id_counters();
        TLobby::reset_floor_items();
    }
    r = ((s32)load_area_scene_and_init(reinterpret_cast<u8 *>(&floor_transition_state)));
    get_current_floor();
    unlock_main_warp_destination();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < 12; j++) {
        p = (VObj_18_801A441C *) get_player_by_client_id(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            p->m6();
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
    s32 *var_r3;
    s32 i;
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    TLobby::send_logout();
    TLobby::free_objects();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.delete_layer_children();
    var_r3 = (s32 *)&main_task;
    var_r3 = (s32 *)&main_task;
    main_task.resume_layers();
    var_r3 = (s32 *)tl_su;
    ((TObject *)var_r3)->delete_children();
    PPCSync();
    i = 0;
    do {
        render_tick();
        i += 1;
    } while (i < 0x1E);
    cleanup__6TLobbyFv();
    if ((s32) online_lobby_scene_handle == 0) {
        var_r3 = (s32 *)&floor_transition_state;
        var_r3 = (s32 *)&floor_transition_state;
        run_area_scene_cleanup(&floor_transition_state);
    }
    TLobby::free_single_player_chr_select();
    TLobby::update_photon_chairs();
    TLobby::call_funcs_reverse(lobby_area_reload_callbacks, sizeof(lobby_area_reload_callbacks));
    TLobby::call_funcs_reverse(online_lobby_scene_callback_table, sizeof(online_lobby_scene_callback_table));
    local_client_id = 0;
    lobby_state_flags = 0;
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick();
}

void TLobby::run_lobby_frame() {
    s32 temp_r0;
    func_803DCDFC__Fv();
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
            temp_r0 = online_lobby_frame_counter + 1;
            online_lobby_frame_counter = temp_r0;
            if (temp_r0 > 0xC) {
                TLobby::disconnect_protocol();
            }
        }
    }
    TLobby::update_periodic_tick();
    if ((static_cast<s8>(func_801A5E54()) != 0) || ((s32) idle_timeout_active == 1)) {
        TLobby::reset_to_chr_select();
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
        TLobby::reload_floor_scene();
        deactivate_keyboard();
    }
    if (TKeyBoardControl::get_input() != 0) {
        reload_lobby_floor_scene();
        TKeyBoardControl__sub_8000F95C();
    }
    render_tick();
}

void TLobby::run_main_frame() {
    s32 temp_r0;
    func_803DCDFC__Fv();
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
    TLobby__sub_8006EF90();
    if (((s32) lbl_805D55C0 == 0) && (poll_memcard_result((int) ((s8)TAdSinglePlyChrSelectGC::get_chr_select_state())) != -1)) {
        if (TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0) {
            online_lobby_frame_counter = 0;
        } else {
            temp_r0 = online_lobby_frame_counter + 1;
            online_lobby_frame_counter = temp_r0;
            if (temp_r0 > 0xC) {
                TLobby::disconnect_protocol();
            }
        }
    }
    TLobby::update_periodic_tick();
    if (TKeyBoardControl::get_input() != 0) {
        start_quest_mission();
        TKeyBoardControl__sub_8000F95C();
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        change_floor_reload_area();
        clear_keyboard_key_state();
    }
    if (is_keyboard_active() != 0) {
        TLobby::reload_floor_scene();
        deactivate_keyboard();
    }
    if ((s16) TLobby__data_805D5CE8 == 1) {
        reload_lobby_floor_scene();
    }
    if ((static_cast<s8>(func_801A5E54()) != 0) || ((s32) idle_timeout_active == 1)) {
        TLobby::init_chr_select();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TLobby::send_logout();
        request_main_phase(0);
    }
    render_tick();
}

void TLobby::update_camera_state() {
    if (is_quest_active() != 0) {
        TLobby::run_lobby_frame();
        return;
    }
    TLobby::run_main_frame();
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
    TKeyBoardControl__sub_8000F90C(2);
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
    TLobby__sub_8020A6B0(0xF);
    TAdDialingGC::open();
    ((TAdDialingGC *)tl_window)->create();
    online_lobby_scene_handle = TLobby__sub_80146908();
    TAdDialingGC__sub_80328730();
    TLoadCtrl::set_field1C(0);
    while (TAdDialingGC__sub_801A4C9C() != 0) {
        func_803DCDFC__Fv();
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render();
        main_task.render_screen_overlay();
        process_async_file_reads();
        update_sound_request_slots();
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
        if (static_cast<s8>(func_801A5E54()) != 0) {
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
            TLobby::start_udp_test_game();
        } else {
            run_join_lobby_connect__6TLobbyFi(lobby);
        }
    }
    actor_frame_tick = 0;
    TLobby__data_805D5CE8 = 0;
    online_lobby_frame_counter = 0;
    render_tick();
}

void TLobby::update_periodic_tick() {
    if ((lobby_state_flags & 1) && ((actor_frame_tick % 900) == 0) && (protocol_instance != NULL)) {
        protocol_instance->send_keepalive();
    }
}
void set_floor_transition_ready(Obj_80515BA0 *transition) { transition->state_flags |= 1; }
void Obj_80515BA0::set_next_floor_index(s32 floor) { next_floor = floor; }
void TLobby::reset_counter() { challenge_task_created = 0; }
