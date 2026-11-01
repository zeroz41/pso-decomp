#include "pso/TMainTask.h"
#include "pso/misc/TWindowMessage.h"
#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLoadCtrl.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TTecLuker.h"
#include "pso/object/TObjBgmColCtrl.h"
#include "pso/object/TObjDoor.h"
#include "pso/ui/TAdDialingGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_801A4820_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_801A4820_main_task_size[sizeof(RecoveredGlobal_801A4820_main_task) == 0x34 ? 1 : -1];

struct RecoveredGlobal_801A46D8_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_801A46D8_main_task_size[sizeof(RecoveredGlobal_801A46D8_main_task) == 0x34 ? 1 : -1];

struct RecoveredGlobal_801A4610_lbl_804C20E8 {
    s32 value;
    u8 remaining[0x154];
};

struct RecoveredGlobal_801A4610_lbl_804C2240 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_801A4610_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_801A4610_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_801A400C_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct Pair_801A3CFC { s32 f0; s32 f4; };

struct Entry_801A3CFC {
    u8 pad0[2];
    s16 f2;
    s32 f4;
    s32 f8;
    s32 fC;
    char name[0x10];
};

struct Msg_801A3CFC {
    u8 pad0[0x84];
    Entry_801A3CFC entries[4];
    s8 f104;
    s8 f105;
    s8 f106;
    u8 pad107[0x114 - 0x107];
};

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

struct Obj_801A40D8 { u8 pad[0x20]; };

struct PlB_801A40D8 { u8 pad[0x18]; };

struct Pl_801A40D8 : PlB_801A40D8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
};

extern "C" {
s32 reset_quest_result_callbacks__22THunterGuildSeqOfflineFPv();
void clear_enabled_main_warps(void);
void queue_destruction__7TObjectFv(void *arg0);
extern u32 quest_mission_manager;
int is_quest_active(void);
void TLobby__sub_801A4C6C(void* p);
    extern int challenge_task_created;
int TKeyBoardControl__sub_8000F95C(void);
s32 is_keyboard_active();
s32 clear_keyboard_key_state();
int TKeyBoardControl__sub_8000F9CC(int);
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 TLobby__sub_8006EF90();
s32 TObjBoss2Tunnel__sub_8007D1D0();
int send_logout__6TLobbyFv(void);
s8 func_801A5E54__Fv();
s32 controller_stuff__Fv();
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 render_tick__Fv();
s32 run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 func_803DCDFC__Fv();
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
s32 cleanup__6TLobbyFv();
void run_area_scene_cleanup(u8 *arg0);
s32 PPCSync();
extern const char lbl_80446930[];
extern s32 lbl_805D5718;
void __construct_array(void *, void *, int, int, int);
s32 TLobby__sub_8013A23C(s32 arg0);
void bswap_32__FPUl(void *);
s32 handle_game_join__6TLobbyFPv(void *);
char *strcpy(char *, const char *);
void *memset(void *, int, u32);
extern char lbl_80446918[];
extern char lbl_80446924[];
extern Pair_801A3CFC lobby_udp_test_game_entries[];
extern s32 TLobby__designated_client_id;
extern s32 game_protocol_instance;
s32 __dt__7TObjectFv(void *, s32);
s32 get_current_floor();
s32 find_leader_section_id(void *, s32);
s32 process_deferred_player_setup__6TLobbyFv();
s32 reset_state_flags__6TLobbyFv();
s32 unlock_main_warp_destination();
int reset_controller_input_state(void);
s32 TObjPlayer__sub_801B1BA4();
s32 TObjPlayer__sub_801B1C8C();
void *get_player_by_client_id(s32);
s32 get_team_state__6TLobbyFPv();
s32 TLobby__sub_8020DC78();
s32 load_area_scene_and_init(void *);
s32 promote_area_floor(void *);
void *__nw__7TObjectFUl(s32);
s32 __ct__7TObjectFP7TObject(void *, s32);
s32 is_area_transfer_pending();
s32 apply_phase_keyboard_mode();
s32 run_load_callback_table(void *, s32);
void TLobby__sub_801A3E94(void);
s32 TAdDialingGC__sub_801A4C90();
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32);
s32 TLobby__sub_80207E24(void *, s32);
s32 TKeyBoardControl__sub_8000F90C(int);
int TKeyBoardControl__sub_8000F91C(int);
s32 run_join_lobby_connect__6TLobbyFi(void *);
void *TLobby__ct(void *, void *);
s32 TLobby__sub_80146908();
void TLobby__sub_801A3CF8(void);
int TLobby__sub_801A3E8C(void);
u32 TAdDialingGC__sub_801A4C9C();
s32 set_copy_clear_color_argb(int, int, int);
s32 TGameProtocol__ct(void *, void *);
s32 TLobby__sub_801F3774();
int init__23TAdSinglePlyChrSelectGCFv(void);
s32 TLobby__sub_80207F10();
s32 TLobby__sub_8020A6B0(int);
s32 TAdDialingGC__sub_80328730();
s32 create__12TAdDialingGCFv(void *);
void send_room_change__6TLobbyFi(s32 arg0);
void TLobby__sub_80141038(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_801F494C(u16 arg0);
s32 reset_story_select__6TLobbyFPv();
s32 init_key_slots__15TOKeyJungleMainFPv();
s32 depart_floor_population();
}
void deactivate_keyboard(void);
void clear_switch_table(void);
void send_keepalive(u8 *arg0);
extern s32 actor_frame_tick;
extern u32 TLobby__protocol_instance;
extern s32 TLobby__lobby_state_flags;
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern s32 TLobby__idle_timeout_active;
extern s32 lbl_805D55C0;
extern s16 TLobby__data_805D5CE8;
extern s32 TLobby__online_lobby_frame_counter;
void clear_resource_load_tasks(void);
extern RecoveredGlobal_801A4610_lbl_804C20E8 online_lobby_scene_callback_table;
extern RecoveredGlobal_801A4610_lbl_804C2240 lobby_area_reload_callbacks;
extern unsigned char lbl_80515BA0[];
extern s32 local_client_id;
extern s32 online_lobby_scene_handle;
void cleanup_online_lobby_scene(void);
void process_pending_resources(void);
void clear_quest_floor_designations(void);
extern u8 TLobby__data_805011D8[];
s32 start_quest_mission(void);
extern u8 game_variations[];
extern int TLobby__new_game_setup_flags;
extern u32 quest_area_manager;
s32 change_floor_reload_area(void);
void run_online_lobby_scene(void);
void load_battle_param_entry(void);
extern s32 TLobby__lobby_number;
void reload_lobby_floor_scene(void);
void init_area_lights(void);
void load_floor_scene(void);
void arrive_floor_population(void);
void TLobby::set_flag_and_update() { TLobby__new_game_setup_flags = (TLobby__new_game_setup_flags | 0x1); TLobby__sub_801A4C6C(lbl_80515BA0); }

void TLobby::init_chr_select() { TKeyBoardControl::reset(); send_logout__6TLobbyFv(); init__23TAdSinglePlyChrSelectGCFv(); TKeyBoardControl__sub_8000F91C(9); TKeyBoardControl__sub_8000F9CC(18); }
void TLobby::reset_to_chr_select() { reset_controller_input_state(); send_logout__6TLobbyFv(); TLobby::free_objects(); TKeyBoardControl__sub_8000F95C(); TLobby::clear_counter(); init__23TAdSinglePlyChrSelectGCFv(); TKeyBoardControl__sub_8000F91C(9); TKeyBoardControl__sub_8000F9CC(18); }
void TLobby__sub_801A3CF8(void) {  }

void TLobby::start_udp_test_game() {
    Msg_801A3CFC msg;
    ((TLobby *)((u8 *)&lobby_udp_test_game_entries[0]))->bswap_udp_test_header();
    ((TLobby *)((u8 *)&lobby_udp_test_game_entries[1]))->bswap_udp_test_header();
    ((TLobby *)((s32)&msg))->construct_entry_array();
    memset(&msg, 0, 0x114);
    msg.f104 = local_client_id;
    msg.f105 = TLobby__designated_client_id;
    msg.f106 = 0;
    msg.entries[0].f2 = 1;
    msg.entries[0].f4 = 0x013158B7;
    msg.entries[0].f8 = lobby_udp_test_game_entries[0].f4;
    msg.entries[0].fC = 0;
    strcpy(msg.entries[0].name, lbl_80446918);
    msg.entries[1].f2 = 1;
    msg.entries[1].f4 = 0x013158B8;
    msg.entries[1].f8 = lobby_udp_test_game_entries[1].f4;
    msg.entries[1].fC = 1;
    strcpy(msg.entries[1].name, lbl_80446924);
    handle_game_join__6TLobbyFPv(&msg);
    ((TObject *)game_protocol_instance)->delete_children();
    ((TLobby *)(1 - local_client_id))->open_udp_socket_for_player();
}

s32 TLobby::construct_entry_array() {
    s32 arg0 = (s32)this;
    __construct_array((void *)(arg0 + 0x84), (void *)TLobby__sub_8013A23C, 0, 0x20, 4);
    return arg0;
}

void TLobby::bswap_udp_test_header() {
    u8 *arg0 = (u8 *)this;
    *(u32 *)(arg0 + 4) = arg0[0] + (arg0[1] << 8) + (arg0[2] << 16) + (arg0[3] << 24);
    bswap_32__FPUl((u8 *)&this->m_flags);
}

int TLobby__sub_801A3E8C(void) { return 0; }
void TLobby__sub_801A3E94(void) {  }

void reload_lobby_floor_scene(void) {
    s32 sp8[9];
    __ct__7TObjectFP7TObject(sp8, 0);
    TLobby::clear_counters();
    reset_state_flags__6TLobbyFv();
    TObjPlayer__sub_801B1C8C();
    TLobby::stop_audio_streams();
    process_pending_resources();
    reset_controller_input_state();
    TLobby::send_game_character();
    render_tick__Fv();
    render_tick__Fv();
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    TLobby::free_objects();
    main_task.delete_layer_children();
    main_task.resume_layers();
    promote_area_floor(lbl_80515BA0);
    TLobby::reset_counter();
    reset_story_select__6TLobbyFPv();
    get_team_state__6TLobbyFPv();
    TLobby__sub_8020DC78();
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    TLobby__sub_8020A6B0(0xF);
    TLobby__sub_80141038(lbl_80515BA0, 0xF, TLobby__lobby_number);
    ((TLobby *)lbl_80515BA0)->set_value(0);
    set_current_floor_area(0xF);
    TScene::set_scene(TLobby__lobby_number);
    load_area_scene_and_init(lbl_80515BA0);
    load_battle_param_entry();
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    TLobby__sub_801F494C(0);
    TLobby__sub_801A3E94();
    process_deferred_player_setup__6TLobbyFv();
    TLobby::install_game_join_handlers();
    TObjPlayer__sub_801B1BA4();
    send_room_change__6TLobbyFi(TLobby__lobby_number);
    init_key_slots__15TOKeyJungleMainFPv();
    TLobby__data_805D5CE8 = 0;
    __dt__7TObjectFv(sp8, -1);
}

void TLobby::send_and_handle() { TLobby::blocking_vsync(this); }

typedef char RecoveredGlobal_801A400C_main_task_size[sizeof(RecoveredGlobal_801A400C_main_task) == 0x34 ? 1 : -1];
void TLobby::blocking_vsync(void* _w0) {
    TLoadCtrl::set_field1C(0);
    func_803DCDFC__Fv();
    if ((s32) lbl_805D5718 != 0) {
        main_task.begin_frame();
        main_task.run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        ::debug_print(lbl_80446930);
        render_tick__Fv();
    } else {
        controller_stuff__Fv();
        TKeyBoardControl::update_input_frame();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render();
        main_task.render_screen_overlay();
        process_async_file_reads();
        update_sound_request_slots();
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
        TAdSinglePlyChrSelectGC::noop();
    }
    TLoadCtrl::set_field1C(1);
    render_tick__Fv();
}

void TLobby::reload_floor_scene() {
    Obj_801A40D8 sp8;
    s32 i;
    Pl_801A40D8 *p;
    s32 j;
    reset_state_flags__6TLobbyFv();
    TObjPlayer__sub_801B1C8C();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    __ct__7TObjectFP7TObject(&sp8, 0);
    process_pending_resources();
    reset_controller_input_state();
    render_tick__Fv();
    render_tick__Fv();
    for (i = 0; i < 12; i++) {
        p = (Pl_801A40D8 *)get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)(&sp8));
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
    TLobby__sub_8020DC78();
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
    process_deferred_player_setup__6TLobbyFv();
    TObjPlayer__sub_801B1BA4();
    TObjBgmColCtrl::create_controller();
    __dt__7TObjectFv(&sp8, -1);
}

void TLobby::free_objects() {
    TRaderMapCore::free_map_data();
    clear_switch_table();
    TTecLuker::apply_all_players();
    TLobby::reset_floor_items();
    TNpcPlayer::enable_all_battle_ctrl();
    if ((u32) quest_mission_manager != 0U) {
        queue_destruction__7TObjectFv((void *)quest_mission_manager);
    }
    clear_enabled_main_warps();
    reset_quest_result_callbacks__22THunterGuildSeqOfflineFPv();
    TLobby::clear_counter();
    TLobby::reset_door_state();
    TObjDoor::reset_instance();
    TLobby::set_cleanup_flag();
    TLobby::reset_quest_counter();
    TLobby::clear_quest_state();
}

typedef char RecoveredGlobal_801A4610_lbl_804C20E8_size[sizeof(RecoveredGlobal_801A4610_lbl_804C20E8) == 0x158 ? 1 : -1];
typedef char RecoveredGlobal_801A4610_lbl_804C2240_size[sizeof(RecoveredGlobal_801A4610_lbl_804C2240) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_801A4610_lbl_80515BA0_size[sizeof(RecoveredGlobal_801A4610_lbl_80515BA0) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_801A4610_main_task_size[sizeof(RecoveredGlobal_801A4610_main_task) == 0x34 ? 1 : -1];

s32 start_quest_mission(void) {
    u8 tmp[0x1C];
    s32 i;
    s32 j;
    VObj_18_801A4268 *q;
    VObj_18_801A4268 *p;
    __ct__7TObjectFP7TObject(tmp, 0);
    reset_state_flags__6TLobbyFv();
    TObjPlayer__sub_801B1C8C();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    process_pending_resources();
    reset_controller_input_state();
    render_tick__Fv();
    render_tick__Fv();
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    for (i = 0; i < 12; i++) {
        p = (VObj_18_801A4268 *) get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tmp);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(lbl_80515BA0);
    TLobby::sync_story_select();
    TAdStorySelectGC::set_state(0);
    TKeyBoardControl::update();
    TLobby::free_objects();
    get_team_state__6TLobbyFPv();
    TLobby__sub_8020DC78();
    TQuestThread::clear_all_floor_handlers();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(1);
    TQuestThread::create_by_mode();
    clear_quest_floor_designations();
    if (quest_mission_manager != 0) {
        q = (VObj_18_801A4268 *)new TQuestThread((TObject *)quest_mission_manager, 0);
        q->m1();
    }
    TLobby::setup_quest_list();
    TLobby::set_enemy_mode_flag();
    TQuestListOnline::ensure_online_quests_loaded();
    load_area_scene_and_init(lbl_80515BA0);
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
    process_deferred_player_setup__6TLobbyFv();
    TObjPlayer__sub_801B1BA4();
    TQuestThread::create_for_floor();
    __dt__7TObjectFv(tmp, -1);
}

s32 change_floor_reload_area(void) {
    u8 tmp[0x1C];
    s32 i;
    s32 j;
    s32 r;
    void *q;
    VObj_18_801A441C *p;
    __ct__7TObjectFP7TObject(tmp, 0);
    reset_state_flags__6TLobbyFv();
    TObjPlayer__sub_801B1C8C();
    TLobby::stop_audio_streams();
    process_pending_resources();
    reset_controller_input_state();
    render_tick__Fv();
    render_tick__Fv();
    find_leader_section_id(TLobby__data_805011D8, TLobby__designated_client_id);
    for (i = 0; i < 12; i++) {
        p = (VObj_18_801A441C *) get_player_by_client_id(i);
        if (p != NULL) {
            ((TObject *)p)->set_parent((TObject *)tmp);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(lbl_80515BA0);
    ((TLobby *)lbl_80515BA0)->clear_ready_flag_unless_locked();
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    if (TLobby__new_game_setup_flags & 1) {
        TLobby__new_game_setup_flags &= ~1;
        TLobby::init_limits();
        TAdDialingGC__sub_801A4C90();
        TLobby__sub_80207E24(game_variations, 0x80);
        apply_phase_keyboard_mode();
        run_load_callback_table(&lobby_area_reload_callbacks.value, 0x48);
        TLobby::reset_item_id_counters();
        TLobby::reset_floor_items();
    }
    r = ((s32)load_area_scene_and_init(lbl_80515BA0));
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
    TObjPlayer__sub_801B1BA4();
    process_deferred_player_setup__6TLobbyFv();
    TQuestThread::create_for_floor();
    if (r != 0) {
        load_character_from_card__23TAdSinglePlyChrSelectGCFi(0);
    }
    if (quest_area_manager != 0) {
        new TQuestThread((TObject *)quest_area_manager, 0);
    }
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::clear_callback_and_reset_keyboard();
    }
    TLobby::clear_callback_and_reset_keyboard();
    __dt__7TObjectFv(tmp, -1);
}

void cleanup_online_lobby_scene(void) {
    s32 *var_r3;
    s32 var_r31;
    s32 var_r4;
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    send_logout__6TLobbyFv();
    TLobby::free_objects();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_main_task *)&(*(RecoveredGlobal_801A4820_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_main_task *)&(*(RecoveredGlobal_801A4820_main_task *)&main_task)).value);
    main_task.delete_layer_children();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_main_task *)&(*(RecoveredGlobal_801A4820_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_main_task *)&(*(RecoveredGlobal_801A4820_main_task *)&main_task)).value);
    main_task.resume_layers();
    var_r3 = (s32 *)tl_su;
    ((TObject *)var_r3)->delete_children();
    PPCSync();
    var_r31 = 0;
    do {
        render_tick__Fv();
        var_r31 += 1;
    } while (var_r31 < 0x1E);
    cleanup__6TLobbyFv();
    if ((s32) online_lobby_scene_handle == 0) {
        var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_lbl_80515BA0 *)&lbl_80515BA0).value);
        var_r3 = (s32 *)(&(*(RecoveredGlobal_801A4610_lbl_80515BA0 *)&lbl_80515BA0).value);
        run_area_scene_cleanup((u8 *)(&(*(RecoveredGlobal_801A4610_lbl_80515BA0 *)&lbl_80515BA0).value));
    }
    TLobby::free_single_player_chr_select();
    TLobby::update_photon_chairs();
    var_r3 = &lobby_area_reload_callbacks.value;
    var_r4 = 0x48;
    var_r3 = &lobby_area_reload_callbacks.value;
    call_funcs_reverse__6TLobbyFPvUi(&lobby_area_reload_callbacks.value, 0x48);
    var_r3 = &online_lobby_scene_callback_table.value;
    var_r4 = 0x158;
    var_r3 = &online_lobby_scene_callback_table.value;
    call_funcs_reverse__6TLobbyFPvUi(&online_lobby_scene_callback_table.value, 0x158);
    local_client_id = 0;
    TLobby__lobby_state_flags = 0;
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick__Fv();
}

void TLobby::run_lobby_frame() {
    s32 temp_r0;
    func_803DCDFC__Fv();
    controller_stuff__Fv();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    TObjBoss2Tunnel__sub_8007D1D0();
    if (((s32) lbl_805D55C0 == 0) && (TAdPlayerLoadGC__sub_801E1B50((int) (get_chr_select_state__23TAdSinglePlyChrSelectGCFv())) != -1)) {
        if (TAdPlayerLoadGC::probe_card_slot(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 0) {
            TLobby__online_lobby_frame_counter = 0;
        } else {
            temp_r0 = TLobby__online_lobby_frame_counter + 1;
            TLobby__online_lobby_frame_counter = temp_r0;
            if (temp_r0 > 0xC) {
                TLobby::disconnect_protocol();
            }
        }
    }
    TLobby::update_periodic_tick();
    if ((func_801A5E54__Fv() != 0) || ((s32) TLobby__idle_timeout_active == 1)) {
        TLobby::reset_to_chr_select();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        send_logout__6TLobbyFv();
        TKeyBoardControl__sub_8000F9CC(0);
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
    render_tick__Fv();
}

void TLobby::run_main_frame() {
    s32 temp_r0;
    func_803DCDFC__Fv();
    controller_stuff__Fv();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    TObjBoss2Tunnel__sub_8007D1D0();
    TLobby__sub_8006EF90();
    if (((s32) lbl_805D55C0 == 0) && (TAdPlayerLoadGC__sub_801E1B50((int) (get_chr_select_state__23TAdSinglePlyChrSelectGCFv())) != -1)) {
        if (TAdPlayerLoadGC::probe_card_slot(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 0) {
            TLobby__online_lobby_frame_counter = 0;
        } else {
            temp_r0 = TLobby__online_lobby_frame_counter + 1;
            TLobby__online_lobby_frame_counter = temp_r0;
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
    if ((func_801A5E54__Fv() != 0) || ((s32) TLobby__idle_timeout_active == 1)) {
        TLobby::init_chr_select();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        send_logout__6TLobbyFv();
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick__Fv();
}

void TLobby::update_camera_state() {
    if (is_quest_active() != 0) {
        TLobby::run_lobby_frame();
        return;
    }
    TLobby::run_main_frame();
}

void run_online_lobby_scene(void) {
    void *lobby;
    void *p;
    TLobby__new_game_setup_flags = 0;
    TLobby__lobby_state_flags = 0;
    set_copy_clear_color_argb(0, 0, 0);
    TKeyBoardControl::update();
    TLobby__sub_801F3774();
    reset_controller_input_state();
    clear_keyboard_key_state();
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(0xF);
    clear_resource_load_tasks();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::poll_default();
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(&online_lobby_scene_callback_table.value, 0x158);
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
    create__12TAdDialingGCFv(tl_window);
    online_lobby_scene_handle = TLobby__sub_80146908();
    TAdDialingGC__sub_80328730();
    TLoadCtrl::set_field1C(0);
    while (TAdDialingGC__sub_801A4C9C() != 0) {
        func_803DCDFC__Fv();
        controller_stuff__Fv();
        TKeyBoardControl::update_input_frame();
        main_task.begin_frame();
        main_task.run_task();
        main_task.render();
        main_task.render_screen_overlay();
        process_async_file_reads();
        update_sound_request_slots();
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
        if (func_801A5E54__Fv() != 0) {
            break;
        }
        render_tick__Fv();
    }
    TLoadCtrl::set_field1C(1);
    TAdDialingGC::close();
    if (online_lobby_scene_handle != 0) {
        init__23TAdSinglePlyChrSelectGCFv();
        TKeyBoardControl__sub_8000F91C(2);
        TKeyBoardControl__sub_8000F9CC(0x12);
        TLoadCtrl::cleanup_scene();
    } else {
        lobby = __nw__7TObjectFUl(0x1C);
        if (lobby != NULL) {
            lobby = TLobby__ct(lobby, tl_su);
        }
        p = __nw__7TObjectFUl(0x20);
        if (p != NULL) {
            TGameProtocol__ct(p, tl_su);
        }
        TLobby__sub_801A3CF8();
        reset_state_flags__6TLobbyFv();
        if (TLobby__sub_801A3E8C() != 0) {
            TLobby::load_set_gsl_files();
            ((TLobby *)lbl_80515BA0)->init_range(0);
        } else {
            ((TLobby *)lbl_80515BA0)->init_range(0xF);
            ((TLobby *)lbl_80515BA0)->set_value(0);
            set_current_floor_area(0xF);
            TScene::set_scene(0);
        }
        load_area_scene_and_init(lbl_80515BA0);
        TLoadCtrl::cleanup_scene();
        process_deferred_player_setup__6TLobbyFv();
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
    TLobby__online_lobby_frame_counter = 0;
    render_tick__Fv();
}

void TLobby::update_periodic_tick() {
    if ((TLobby__lobby_state_flags & 1) && ((actor_frame_tick % 900) == 0) && ((u32) TLobby__protocol_instance != 0U)) {
        send_keepalive((u8 *)TLobby__protocol_instance);
    }
}
void TLobby__sub_801A4C6C(void* p) { *(u32*)((char*)p + 0x20) |= 0x1; }
void TLobby::set_value(s32 v) { *(s32 *)&this->m_next = v; }
void TLobby::reset_counter() { challenge_task_created = 0; }
