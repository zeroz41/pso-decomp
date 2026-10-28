#include "pso/TMainTask.h"
#include "types.h"
#include "pso/system/main_loop.h"
#include "pso/system/vector.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TAdSelectGameModeGC.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLoadCtrl.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_801A3540_lbl_804C1F68 {
    s32 value;
    u8 remaining[0x17C];
};

struct RecoveredGlobal_801A3540_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_801A3540_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_801A3770_main_task {
    s32 value;
    u8 remaining[0x30];
};

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

struct RecoveredGlobal_801A3540_lbl_80515BA0;
struct RecoveredGlobal_801A3540_main_task;
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

struct Vec_801A37D0 { f32 x, y, z; };

struct Cam_801A37D0 {
    u8 pad0[0x94];
    s32 yaws[4];
    Vec_801A37D0 poss[4];
    u8 padd4[0x178 - 0xD4];
    Vec_801A37D0 pos;
    u8 pad184[0x194 - 0x184];
    s32 yaw;
};

struct RecoveredGlobal_801A3540_lbl_804C1F68;
struct PVB_801A39BC { char pad[0x18]; };

struct PV_801A39BC : PVB_801A39BC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6();
};

extern "C" {
s32 is_split_screen(void);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
s32 TLobby__sub_801A3B98();
s32 run_area_scene_cleanup(void *);
extern RecoveredGlobal_801A3540_lbl_804C1F68 offline_game_scene_callbacks;
extern RecoveredGlobal_801A3540_lbl_80515BA0 lbl_80515BA0;
void __dt__7TObjectFv(void *, int);
void *get_player_data__10TObjPlayerFi(s32);
s32 get_current_floor();
void find_leader_section_id(void *, s32);
void unlock_main_warp_destination(s32);
void reset_controller_input_state();
void load_area_scene_and_init(void *);
void promote_area_floor(void *);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
s32 is_area_transfer_pending();
s32 apply_phase_keyboard_mode();
s32 TLobby__sub_80141038(void *, int, int);
s32 update_main_warp_visible_mask(int);
s32 TLobby__sub_801A2E00();
s32 for_each_player_slot__10TObjPlayerFv(void *);
s32 rebuild_player_inventory(void *);
s32 TLobby__sub_80207E48();
s32 get_team_state__6TLobbyFPv();
s32 TLobby__sub_8020DC78();
s32 get_game_play_mode();
s32 TKeyBoardControl__sub_8000F95C();
s32 clear_keyboard_key_state();
s32 TKeyBoardControl__sub_8000F9CC(s32);
s32 TObjBoss2Tunnel__sub_8007D1D0();
void TLobby__sub_8007EB20(const char *, ...);
s8 func_801A5E54__Fv();
s32 run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 func_803DCDFC__Fv();
s32 TLobby__sub_8006EF90();
s32 get_fog_ctrl__16TKeyBoardControlFv();
u16 TCameraCtrl__sub_8006A5DC();
s8 TLobby__sub_801A3C40();
s32 TWindowCtrlMain__sub_8024CB7C();
s32 TWindowCtrlMain__sub_8024CB8C();
s32 TKeyBoardControl__sub_8000F90C(s32);
s32 TKeyBoardControl__sub_8000F91C(s32);
s32 is_quest_active();
s32 run_load_callback_table(void *, s32);
s32 TLobby__sub_801A2DF4();
s32 TLobby__sub_801A2DF8();
s32 TLobby__sub_801A2DFC();
s32 TObjPlayer__sub_801B1BA4();
s32 TObjPlayer__sub_801B1C8C();
s32 set_copy_clear_color_argb(s32, s32, s32);
s32 TLobby__sub_801F3774();
s32 save_character_to_card__23TAdSinglePlyChrSelectGCFv();
}
void clear_resource_load_tasks(void);
void run_single_view_frame(void);
void process_pending_resources();
extern u8 TLobby__data_805011D8[];
extern s32 TLobby__designated_client_id;
extern u32 quest_area_manager;
void run_offline_area_transfer(void);
void load_battle_param_entry(void);
extern u8 fn_801B309C[];
void clear_quest_floor_designations(void);
void setup_split_screen(void);
extern u32 quest_mission_manager;
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern char lbl_804468F8[];
extern char lbl_80446908[];
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;
void run_offline_game_frame(void);
void run_offline_transfer_frame(void);
extern Cam_801A37D0 *camera_ctrl_instance;
void run_split_screen_frame(void);
extern s32 local_client_id;
extern s32 actor_frame_tick;
extern s32 lbl_805D5CE0;
extern s32 TLobby__lobby_state_flags;
void init_offline_game_scene(void);
void dispatch_offline_main_frame(void);

typedef char RecoveredGlobal_801A3540_lbl_804C1F68_size[sizeof(RecoveredGlobal_801A3540_lbl_804C1F68) == 0x180 ? 1 : -1];
typedef char RecoveredGlobal_801A3540_lbl_80515BA0_size[sizeof(RecoveredGlobal_801A3540_lbl_80515BA0) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_801A3540_main_task_size[sizeof(RecoveredGlobal_801A3540_main_task) == 0x34 ? 1 : -1];

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
        void *q = get_player_data__10TObjPlayerFi(i);
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
    promote_area_floor(&lbl_80515BA0);
    TLobby::backup_story_select();
    TKeyBoardControl::update();
    get_team_state__6TLobbyFPv();
    TLobby__sub_8020DC78();
    TLobby__sub_80207E48();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    apply_phase_keyboard_mode();
    TLoadCtrl::start_loading(1);
    TLobby::init_limits();
    TLobby::load_set_gsl_files();
    TLobby::load_set_event_gsl();
    load_battle_param_entry();
    TLobby__sub_80141038(&lbl_80515BA0, 0, 0);
    load_area_scene_and_init(&lbl_80515BA0);
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
        p = get_player_data__10TObjPlayerFi(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A3014 *)p)->m6();
            rebuild_player_inventory(p);
            for_each_player_slot__10TObjPlayerFv(fn_801B309C);
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
        void *q = get_player_data__10TObjPlayerFi(i);
        if (q != NULL) {
            ((TObject *)q)->set_parent((TObject *)(&holder));
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&lbl_80515BA0);
    TLobby::sync_story_select();
    TAdStorySelectGC::set_state(0);
    TKeyBoardControl::update();
    TLobby::reset_quest_state();
    get_team_state__6TLobbyFPv();
    TLobby__sub_8020DC78();
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
        void *t = new TQuestThread((TObject *)quest_mission_manager, 0);
        ((VObj_801A31D8 *)t)->m1();
    }
    TLobby::set_enemy_mode_flag();
    TLobby::init_limits();
    TLobby::setup_quest_list();
    TQuestListVM::load_vm();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        load_area_scene_and_init(&lbl_80515BA0);
    } else {
        TLobby__sub_80141038(&lbl_80515BA0, 0, 0);
        load_area_scene_and_init(&lbl_80515BA0);
    }
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = get_player_data__10TObjPlayerFi(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A31D8 *)p)->m6();
            rebuild_player_inventory(p);
            for_each_player_slot__10TObjPlayerFv(fn_801B309C);
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
        void *q = get_player_data__10TObjPlayerFi(i);
        if (q != NULL) {
            ((TObject *)q)->set_parent((TObject *)(&holder));
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&lbl_80515BA0.value);
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    load_area_scene_and_init(&lbl_80515BA0.value);
    unlock_main_warp_destination(get_current_floor());
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = get_player_data__10TObjPlayerFi(j);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tl_03);
            ((VObj_801A33DC *)p)->m6();
        }
    }
    TQuestThread::create_for_floor();
    if (quest_area_manager != 0) {
        new TQuestThread((TObject *)quest_area_manager, 0);
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
    run_area_scene_cleanup(&lbl_80515BA0.value);
    call_funcs_reverse__6TLobbyFPvUi(&offline_game_scene_callbacks.value, 0x180);
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick();
}

typedef char RecoveredGlobal_801A3770_main_task_size[sizeof(RecoveredGlobal_801A3770_main_task) == 0x34 ? 1 : -1];

void run_offline_game_frame(void) {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    TLobby__sub_8007EB20(lbl_804468F8, TLobby__data_805D614C * 0xC);
    TLobby__sub_8007EB20(lbl_80446908, TLobby__data_805D6148 * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TObjBoss2Tunnel__sub_8007D1D0();
    if (func_801A5E54__Fv() != 0) {
        TLobby::shutdown_keyboard_control();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TKeyBoardControl__sub_8000F9CC(0);
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
    TLobby__sub_8007EB20(lbl_804468F8, TLobby__data_805D614C * 0xC);
    TLobby__sub_8007EB20(lbl_80446908, TLobby__data_805D6148 * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    TObjBoss2Tunnel__sub_8007D1D0();
    TLobby__sub_8006EF90();
    if (func_801A5E54__Fv() != 0) {
        TLobby::reset_keyboard_input();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TKeyBoardControl__sub_8000F9CC(0);
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
        get_fog_ctrl__16TKeyBoardControlFv();
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
                get_fog_ctrl__16TKeyBoardControlFv();
                main_task.render();
                TCameraCtrl::sync_split_view_slots(i, 0);
                TWindowCtrlMain__sub_8024CB8C();
            } else {
                TWindowCtrlMain__sub_8024CB7C();
                if (i == 0) {
                    main_task.run_task();
                }
                TCameraCtrl::set_split_viewport(1, 0);
                get_fog_ctrl__16TKeyBoardControlFv();
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
    void *temp_r3;
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
    ((TLobby *)(&lbl_80515BA0))->init_range(0);
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(&offline_game_scene_callbacks, 0x180);
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
    load_area_scene_and_init(&lbl_80515BA0);
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    game_mode = TLobby::get_game_mode();
    for (i = 0; i < game_mode; i++) {
        temp_r3 = get_player_data__10TObjPlayerFi(i);
        if (temp_r3 != NULL) {
            ((PV_801A39BC *)temp_r3)->m6();
        }
    }
    TObjPlayer__sub_801B1BA4();
    if (quest_area_manager != 0) {
        new TQuestThread((TObject *)quest_area_manager, 0);
    }
    if (save_character_to_card__23TAdSinglePlyChrSelectGCFv() == 0) {
        if (is_quest_active() != 0) {
            TLobby::shutdown_keyboard_control();
        } else {
            TLobby::reset_keyboard_input();
        }
    }
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(0xE);
    render_tick();
}
