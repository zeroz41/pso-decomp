#include "pso/unk/TUnk_804C8678.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/unk/text_801A3014.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/system/main_loop.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/unk/TLobby_802A7290.h"
#include "pso/unk/text_803000C8.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/object/base/TObjBase.h"
#include "pso/render/TFogCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/city/TShopGetItemWindow_8021F0A4.h"
#include "pso/ui/city/TShopGetItemWindow_8021F074.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/warp/TObjCityMainWarp_801867F4.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowOptionCtrl_8034C384.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/ui/chat/TWindowChat_800774C0.h"
#include "pso/unk/TLobby_80077B60.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/ui/window/TWindowSubStatusDisp_8036D774.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"


struct VBase_801A33DC { char pad[0x18]; };

struct VObj_801A33DC : VBase_801A33DC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Obj_801A33DC { u8 data[0x20]; };

struct VBase_801A3014 { char pad[0x18]; };

struct VObj_801A3014 : VBase_801A3014 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Obj_801A3014 { u8 data[0x20]; };

struct VBase_801A31D8 { char pad[0x18]; };

struct VObj_801A31D8 : VBase_801A31D8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Obj_801A31D8 { u8 data[0x20]; };

struct VBase_801A37D0 { char pad[0x18]; };

struct VObj_801A37D0 : VBase_801A37D0 {
    virtual void m0();
    virtual void m1();
};

struct Cam_801A37D0 {
    u8 pad0[0x94];
    s32 yaws[4];
    Vec poss[4];
    u8 padd4[0x178 - 0xD4];
    Vec pos;
    u8 pad184[0x194 - 0x184];
    s32 yaw;
};

struct PVB_801A39BC { char pad[0x18]; };

struct PV_801A39BC : PVB_801A39BC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6();
};

extern "C" {
s32 TLobby__sub_801A3B98();
void TLobby__sub_802075F4(void);
void TWindowCtrlMain__sub_8024D838(void);
void TObjPlayer__sub_80156934(void);
void TRaderMapCore__sub_801F95CC(void);
void TWindowDD__sub_80344114(void);
void THunterGuildSeqOffline__sub_80213410(void);
void TQuestThread__sub_801F5D88(void);
void TLobby__sub_8029B2A4(void);
}
void prepare_adventure_maps(void);
void init_scene_fog_system(void);
void init_item_drop_tables(void);
void clear_received_symbol_chat(void);

// Load and release hooks of the offline game scene, in pairs: init_offline_game_scene runs
// each load front to back (run_load_callback_table), TLobby::teardown_scene each release
// back to front (TLobby::call_funcs_reverse).
FloorResourceCallbacks offline_game_scene_callbacks[48] = {
    {TAdSelectGameModeGC__sub_802C478C, (FloorResourceCallback)TAdSelectGameModeGC::call_enable_camera},
    {TLobby::enable_and_refresh, disable_and_free_boss4rock_buffer},
    {TObjPlayer::init_shared, TObjPlayer::finalize_shared},
    {fn_803000C8, TLobby__sub_803000A0},
    {prepare_adventure_maps, TLobby__sub_802075F4},
    {TLobby::clear_story_flags_and_reset_camera, TLobby::clear_story_flag_list},
    {TLobby::init_on_main_phase, NULL},
    {(FloorResourceCallback)TLobby__sub_80293124, TLobby::destroy_tombstone},
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {TWindowCtrlMain__sub_8024D838, TWindowCtrlMain::free_all_windows},
    {TWindowCtrl::close, TWindowCtrl::shutdown},
    {TLobby__sub_8001ED74, TLobby__sub_8001ED70},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {TKeyBoardControl__sub_80131F60, TKeyBoardControl__sub_80131F5C},
    {alloc_battle_param_tables, TLobby::free_boss4_rock},
    {TLobby__sub_801A2554, TLobby__sub_801A2550},
    {TObjPlayer::reset, TObjPlayer__sub_80156934},
    {init_scene_fog_system, TFogCtrl::reset},
    {load_light_entry_file, TObjLight::free_shared_data},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {TLobby::load_item_data, TLobby__sub_802083C0},
    {init_item_drop_tables, TLobby::free_resources},
    {init_item_system, free_item_system},
    {TLobby::create_heap_8000, TLobby::free_heap},
    {TRaderMapCore__sub_801F95CC, TRaderMapCore::free_heap},
    {TLobby::load_set_gsl_files, clear_map_set_data},
    {TLobby::load_set_event_gsl, (FloorResourceCallback)TLobby::get_team_state},
    {alloc_work_buffer, TLobby__sub_801A5478},
    {TLobby::load_freeze_ice_resource, TLobby::destroy_global_singleton},
    {TWindowDD__sub_80344114, TWindowDD::free_buffers},
    {init_switch_table, clear_switch_table},
    {reset_shop_stock_and_params, clear_all_shop_stock},
    {(FloorResourceCallback)THunterGuildSeqOffline::reset_quest_result_callbacks, THunterGuildSeqOffline__sub_80213410},
    {TQuestThread::clear_all_floor_handlers, TQuestThread__sub_801F5D88},
    {TObjCityMainWarp::reset, TObjCityMainWarp__sub_80186AB8},
    {(FloorResourceCallback)TLobby__sub_80225C64, (FloorResourceCallback)TLobby__sub_80225C44},
    {(FloorResourceCallback)TLobby__sub_8001DC04, (FloorResourceCallback)TLobby::forward_8001DBD8},
    {(FloorResourceCallback)TLobby__sub_8034C3A4, (FloorResourceCallback)TLobby__sub_8034C384},
    {(FloorResourceCallback)TWindowGetComCard__sub_8007B67C, (FloorResourceCallback)TWindowGetComCard__sub_8007B65C},
    {(FloorResourceCallback)TLobby__sub_8024285C, (FloorResourceCallback)(void (*)(void *))TLobby::reset_state},
    {clear_received_symbol_chat, TLobby__sub_80077608},
    {TLobby__sub_80077BAC, TLobby::free_static_windows},
    {TLobby::init_char_slots, TLobby__sub_801C3A40},
    {(FloorResourceCallback)TOKeyJungleMain::init_key_slots, TLobby__sub_8029B2A4},
    {(FloorResourceCallback)TLobby__sub_802D39FC, (FloorResourceCallback)TLobby__sub_802D39DC},
    {TObjBoss2Tunnel::reset_state, TObjBoss2Tunnel__sub_8007DD24},
    {TBGMulti__ct, TLobby::free_singleton_805D7018},
    {clear_boss6_player_snapshots, NULL},
};
extern "C" {
void __dt__7TObjectFv(void *, int);
void find_leader_section_id(void *, s32);
void unlock_main_warp_destination(s32);
void reset_controller_input_state();
void load_area_scene_and_init(void *);
void __ct__7TObjectFP7TObject(void *, void *);
s32 is_area_transfer_pending();
s32 apply_phase_keyboard_mode();
s32 TLobby__sub_801A2E00();
s32 rebuild_player_inventory(void *);
s32 get_game_play_mode();
s32 TKeyBoardControl__sub_8000F95C();
s32 clear_keyboard_key_state();
s32 request_main_phase(s32);
s32 TObjBoss2Tunnel__sub_8007D1D0();
void TLobby__sub_8007EB20(const char *, ...);
s8 func_801A5E54__Fv();
s32 func_803DCDFC__Fv();
s32 TLobby__sub_8006EF90();
u16 TCameraCtrl__sub_8006A5DC();
s8 TLobby__sub_801A3C40();
s32 TWindowCtrlMain__sub_8024CB7C();
s32 TWindowCtrlMain__sub_8024CB8C();
s32 TKeyBoardControl__sub_8000F90C(s32);
s32 set_queued_main_phase(s32);
s32 run_load_callback_table(void *, s32);
s32 TLobby__sub_801A2DF4();
s32 TLobby__sub_801A2DF8();
s32 TLobby__sub_801A2DFC();
s32 TObjPlayer__sub_801B1BA4();
s32 TObjPlayer__sub_801B1C8C();
s32 set_copy_clear_color_argb(s32, s32, s32);
s32 TLobby__sub_801F3774();
}
void clear_floor_population(void);
void clear_resource_load_tasks(void);
void run_single_view_frame(void);
void process_pending_resources();
extern u8 TLobby__data_805011D8[];
extern s32 TLobby__designated_client_id;
void run_offline_area_transfer(void);
void load_battle_param_entry(void);
extern u8 fn_801B309C[];
void clear_quest_floor_designations(void);
void setup_split_screen(void);
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;
void run_offline_game_frame(void);
void run_offline_transfer_frame(void);
extern Cam_801A37D0 *camera_ctrl_instance;
void run_split_screen_frame(void);
extern s32 local_client_id;
extern s32 actor_frame_tick;
s32 lbl_805D5CE0;
extern s32 TLobby__lobby_state_flags;


void TLobby::reload_offline_area() {
    Obj_801A3014 holder;
    void *p;
    s32 i;
    s32 j;
    __ct__7TObjectFP7TObject(&holder, NULL);
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    TLobby__sub_801A2E00();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        void *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            ((TObject *)q)->set_parent((TObject *)(&holder));
        }
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 0:
            break;
        case 1:
            TLobby::destroy_global();
            break;
        case 2:
            break;
        }
    }
    TLobby::reset_quest_state();
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TLobby::backup_story_select();
    TKeyBoardControl::update();
    TLobby::get_team_state();
    clear_floor_population();
    TLobby__sub_80207E48();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    apply_phase_keyboard_mode();
    TLoadCtrl::start_loading(1);
    TLobby::init_limits();
    TLobby::load_set_gsl_files();
    TLobby::load_set_event_gsl();
    load_battle_param_entry();
    initialize_floor_transition(&floor_transition_state, 0, 0);
    load_area_scene_and_init(&floor_transition_state);
    TLoadCtrl::cleanup_scene();
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::clear_callback_and_reset_keyboard();
    }
    TLobby::clear_callback_and_reset_keyboard();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A3014 *)p)->m6();
            rebuild_player_inventory(p);
            ((TObjPlayer *)fn_801B309C)->for_each_player_slot();
        }
    }
    load_battle_param_entry();
    update_main_warp_visible_mask(0);
    __dt__7TObjectFv(&holder, -1);
}

void TLobby::rebuild_area_keep_players() {
    Obj_801A31D8 holder;
    s32 i;
    s32 j;
    void *p;
    __ct__7TObjectFP7TObject(&holder, NULL);
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    TObjPlayer::refresh_player_lobby_headers();
    TObjPlayer::create_active_players();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        void *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            ((TObject *)q)->set_parent((TObject *)(&holder));
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TLobby::sync_story_select();
    TAdStorySelectGC::set_state(0);
    TKeyBoardControl::update();
    TLobby::reset_quest_state();
    TLobby::get_team_state();
    clear_floor_population();
    TQuestThread::clear_all_floor_handlers();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 0:
            break;
        case 1:
            setup_split_screen();
            break;
        case 2:
            break;
        }
    }
    TLoadCtrl::start_loading(1);
    TQuestThread::create_by_mode();
    clear_quest_floor_designations();
    {
        void *t = new TQuestThread(quest_mission_manager, 0);
        ((VObj_801A31D8 *)t)->m1();
    }
    TLobby::set_enemy_mode_flag();
    TLobby::init_limits();
    TLobby::setup_quest_list();
    TQuestListVM::load_vm();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        load_area_scene_and_init(&floor_transition_state);
    } else {
        initialize_floor_transition(&floor_transition_state, 0, 0);
        load_area_scene_and_init(&floor_transition_state);
    }
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A31D8 *)p)->m6();
            rebuild_player_inventory(p);
            ((TObjPlayer *)fn_801B309C)->for_each_player_slot();
        }
    }
    TQuestThread::create_for_floor();
    __dt__7TObjectFv(&holder, -1);
}

void run_offline_area_transfer(void) {
    Obj_801A33DC holder;
    s32 i;
    void *p;
    s32 j;
    __ct__7TObjectFP7TObject(&holder, NULL);
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        void *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            ((TObject *)q)->set_parent((TObject *)(&holder));
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    load_area_scene_and_init(&floor_transition_state);
    unlock_main_warp_destination(get_current_floor());
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A33DC *)p)->m6();
        }
    }
    TQuestThread::create_for_floor();
    if (quest_area_manager != NULL) {
        new TQuestThread(quest_area_manager, 0);
    }
    __dt__7TObjectFv(&holder, -1);
}

void TLobby::teardown_scene() {
    if (is_split_screen() != 0) {
        TCameraCtrl::set_fullscreen_viewport();
    }
    TLobby__sub_801A3B98();
    TAdSelectGameModeGC::enable_camera();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    TLobby::reset_quest_state();
    main_task.delete_layer_children();
    main_task.resume_layers();
    ((TObject *)tl_su)->delete_children();
    run_area_scene_cleanup(&floor_transition_state);
    TLobby::call_funcs_reverse(offline_game_scene_callbacks, sizeof(offline_game_scene_callbacks));
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick();
}

void run_offline_game_frame(void) {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    TLobby__sub_8007EB20("Condition E%d", TLobby__data_805D614C * 0xC);
    TLobby__sub_8007EB20("Condition O%d", TLobby__data_805D6148 * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TObjBoss2Tunnel__sub_8007D1D0();
    if (func_801A5E54__Fv() != 0) {
        TLobby::shutdown_keyboard_control();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        run_offline_area_transfer();
        clear_keyboard_key_state();
    }
    if (TKeyBoardControl::get_input() != 0) {
        TLobby::reload_offline_area();
        TKeyBoardControl__sub_8000F95C();
    }
    render_tick();
}

void run_offline_transfer_frame(void) {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    TLobby__sub_8007EB20("Condition E%d", TLobby__data_805D614C * 0xC);
    TLobby__sub_8007EB20("Condition O%d", TLobby__data_805D6148 * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    TObjBoss2Tunnel__sub_8007D1D0();
    TLobby__sub_8006EF90();
    if (func_801A5E54__Fv() != 0) {
        TLobby::reset_keyboard_input();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    if (TKeyBoardControl::get_input() != 0) {
        TLobby::rebuild_area_keep_players();
        TKeyBoardControl__sub_8000F95C();
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        run_offline_area_transfer();
        clear_keyboard_key_state();
    }
    render_tick();
}

void run_single_view_frame(void) {
    main_task.begin_frame();
    TCameraCtrl::set_mode(0);
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
}

void run_split_screen_frame(void) {
    s32 i;
    s8 id;
    main_task.begin_frame();
    id = TLobby__sub_801A3C40();
    if (id >= 0) {
        TCameraCtrl::set_mode(id);
        main_task.run_task();
        forward_clear_split_screen_fog();
        TCameraCtrl::set_split_viewport(1, 0);
        main_task.render();
        if (camera_ctrl_instance != NULL) {
            camera_ctrl_instance->yaws[id] = camera_ctrl_instance->yaw;
            VecCopy((Vec *)&camera_ctrl_instance->poss[id], (const Vec *)&camera_ctrl_instance->pos);
        }
    } else {
        for (i = 0; i < TCameraCtrl::get_camera_id(); i++) {
            TCameraCtrl::set_mode(i);
            if (TCameraCtrl__sub_8006A5DC() != 5 && TCameraCtrl__sub_8006A5DC() != 9) {
                if (i == 0) {
                    main_task.run_task();
                    TWindowSubStatusDisp::draw_split_screen_hud();
                } else if (camera_ctrl_instance != NULL) {
                    ((VObj_801A37D0 *)camera_ctrl_instance)->m1();
                }
                TCameraCtrl::set_split_viewport(TCameraCtrl::get_camera_id(), i);
                forward_clear_split_screen_fog();
                main_task.render();
                TCameraCtrl::sync_split_view_slots(i, 0);
                TWindowCtrlMain__sub_8024CB8C();
            } else {
                TWindowCtrlMain__sub_8024CB7C();
                if (i == 0) {
                    main_task.run_task();
                }
                TCameraCtrl::set_split_viewport(1, 0);
                forward_clear_split_screen_fog();
                main_task.render();
                TCameraCtrl::sync_split_view_slots(i, 1);
                TWindowCtrlMain__sub_8024CB7C();
                break;
            }
        }
    }
    TCameraCtrl::set_mode(0x64);
    TCameraCtrl::set_fullscreen_viewport();
    main_task.render_screen_overlay();
}

void dispatch_offline_main_frame(void) {
    if (is_quest_active() != 0) {
        run_offline_game_frame();
        return;
    }
    run_offline_transfer_frame();
}
void init_offline_game_scene(void) {
    s32 game_mode;
    s32 i;
    void *player_data;
    lbl_805D5CE0 = 0;
    TLobby__lobby_state_flags = 0;
    set_copy_clear_color_argb(0, 0, 0);
    TKeyBoardControl::update();
    reset_controller_input_state();
    clear_keyboard_key_state();
    clear_resource_load_tasks();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::poll_default();
    TObjPlayer__sub_801B1C8C();
    set_current_floor_area(0);
    TScene::set_scene(0);
    floor_transition_state.init_range(0);
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(offline_game_scene_callbacks, sizeof(offline_game_scene_callbacks));
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLoadCtrl::cleanup_scene();
        TObjPlayer__sub_801B1BA4();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TLobby__sub_801F3774();
    TLobby__sub_801A2DFC();
    TLobby::apply_char_to_players();
    TLobby__sub_801A2DF8();
    actor_frame_tick = 0;
    local_client_id = 0;
    TLobby__designated_client_id = 0;
    TLobby__sub_801A2DF4();
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    load_area_scene_and_init(&floor_transition_state);
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    game_mode = TLobby::get_game_mode();
    for (i = 0; i < game_mode; i++) {
        player_data = TObjPlayer::get_player_data(i);
        if (player_data != NULL) {
            ((PV_801A39BC *)player_data)->m6();
        }
    }
    TObjPlayer__sub_801B1BA4();
    if (quest_area_manager != NULL) {
        new TQuestThread(quest_area_manager, 0);
    }
    if (TAdSinglePlyChrSelectGC::save_character_to_card() == 0) {
        if (is_quest_active() != 0) {
            TLobby::shutdown_keyboard_control();
        } else {
            TLobby::reset_keyboard_input();
        }
    }
    TKeyBoardControl__sub_8000F90C(2);
    set_queued_main_phase(0xE);
    render_tick();
}
