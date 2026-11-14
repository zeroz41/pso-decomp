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
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/system/scene/TEndingC_8008D00C.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"

struct RecoveredGlobal_8008C534_main_task {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
void func_803DCDFC__Fv(void);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
void reset__11TCameraCtrlFv(void);
void disable_and_free_boss4rock_buffer(void);
}
void create_player_ending_motion(void);

// Load and release hooks of the ending scene, in pairs: run_load_callback_table
// calls the first of each pair, call_funcs_reverse the second, last pair first.
void (*ending_scene_callbacks[26])(void) = {
    TCameraCtrl::reset_view_state, reset__11TCameraCtrlFv,
    TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view,
    TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources,
    TLobby::set_ending_callback, TLobby::free_ending_callback,
    ending_scene_nop_load, ending_scene_nop_release,
    register_texture_ed_512kabe_c, release_lobby__8TEndingCFv,
    TScene::bind_ending_wall_textures, TEndingAB::destroy_instance,
    alloc_quest_download_buffer, TLobby::free_chr_select_singleton,
    init_item_system, free_item_system,
    create_player_ending_motion, TObjPlayer::free_shared_lobby_data,
    TLobby::enable_and_refresh, disable_and_free_boss4rock_buffer,
    TAdEndText::load_ending_font, TAdEndText::free_resources,
    TAdRicoRingCtrl::load_static_resource, TAdRicoRingCtrl::release_global_805D4A00,
};

extern "C" {
typedef char RecoveredGlobal_8008C534_main_task_size[sizeof(RecoveredGlobal_8008C534_main_task) == 0x34 ? 1 : -1];

void fn_8008C4F4(void) {
    TLobby::stop_audio_streams();
    main_task.delete_layer_children();
    call_funcs_reverse__6TLobbyFPvUi(ending_scene_callbacks, sizeof(ending_scene_callbacks));
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

extern "C" {
void set_active_camera_pose(u8 *arg0, u8 *arg1);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void run_load_callback_table(void *, int);
void set_copy_clear_color_argb(int, int, int);
void *__nw__7TObjectFUl(int);
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
    Vec a = {0.0f, 0.0f, 0.0f};
    Vec b = {0.0f, 0.0f, -100.0f};
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose((u8 *)&a, (u8 *)&b);
    clear_resource_load_tasks();
    run_load_callback_table(ending_scene_callbacks, sizeof(ending_scene_callbacks));
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(2);
    play_area_music("ending.adx");
    TParticleCtrl::create_quad_sprites();
    new TEnding;
    render_tick();
}

// inferred: the empty load/unload pair in ending_scene_callbacks
void ending_scene_nop_release() {}
void ending_scene_nop_load() {}
}

void TEnding::render() {}
