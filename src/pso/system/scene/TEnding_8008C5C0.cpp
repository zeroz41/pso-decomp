#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/unk/text_8008C4F4.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TEnding.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/system/scene/TEnding_8008C5C0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct RecoveredGlobal_8008C534_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_8008C4F4_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
void func_803DCDFC__Fv(void);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern s32 ending_scene_callbacks[];
typedef char RecoveredGlobal_8008C534_main_task_size[sizeof(RecoveredGlobal_8008C534_main_task) == 0x34 ? 1 : -1];

typedef char RecoveredGlobal_8008C4F4_main_task_size[sizeof(RecoveredGlobal_8008C4F4_main_task) == 0x34 ? 1 : -1];
void fn_8008C4F4(void) {
    s32 *var_r3;
    s32 var_r4;
    TLobby::stop_audio_streams();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C4F4_main_task *)&(*(RecoveredGlobal_8008C534_main_task *)&main_task)).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C4F4_main_task *)&(*(RecoveredGlobal_8008C534_main_task *)&main_task)).value);
    main_task.delete_layer_children();
    var_r3 = ending_scene_callbacks;
    var_r4 = 0x68;
    var_r3 = ending_scene_callbacks;
    call_funcs_reverse__6TLobbyFPvUi(ending_scene_callbacks, 0x68);
    render_tick();
}
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
void run_game_frame(void) {
    s32 *var_r3;
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.begin_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.run_task();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.render();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8008C534_main_task *)&main_task).value);
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::noop();
    if (func_801A5E54__Fv() != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        var_r3 = NULL;
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick();
}

struct Vec_8008C5E8 { s32 x, y, z; };

extern "C" {
void set_active_camera_pose(u8 *arg0, u8 *arg1);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void __ct__7TEndingFv(void *);
void run_load_callback_table(void *, int);
void set_copy_clear_color_argb(int, int, int);
void *__nw__7TObjectFUl(int);
extern Vec_8008C5E8 lbl_80439570;
extern Vec_8008C5E8 lbl_8043957C;
extern u8 lbl_80439588[];
extern u8 default_scene_light_config[];
extern s32 ending_scene_active;

void TEnding::set_flag_and_advance() {
    ending_scene_active = 1;
    TEnding::start_ending_scene();
}

void TEnding::start_ending_scene() {
    void *p;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    init_map_lights(default_scene_light_config);
    p = __nw__7TObjectFUl(0x1D4);
    if (p != 0) {
        TCameraCtrl__ct((u8 *)p, tl_camera);
    }
    Vec_8008C5E8 a = lbl_80439570;
    Vec_8008C5E8 b = lbl_8043957C;
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose((u8 *)&a, (u8 *)&b);
    clear_resource_load_tasks();
    run_load_callback_table(ending_scene_callbacks, 0x68);
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(2);
    play_area_music((char *)lbl_80439588);
    TParticleCtrl::create_quad_sprites();
    p = __nw__7TObjectFUl(0x710);
    if (p != 0) {
        __ct__7TEndingFv(p);
    }
    render_tick();
}

void TEnding__sub_8008C6E8() {}
void TEnding__sub_8008C6EC() {}
}

void TEnding::render() {}
