#include "types.h"
#include "pso/unk/text_8023F160.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"

struct RecoveredGlobal_8023F1B8_lbl_804CCDA8 {
    s32 value;
    u8 remaining[0xB4];
};

struct RecoveredGlobal_8023F1B8_lbl_804CCE60 {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_8023F1B8_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct Vec_8023F22C { f32 x, y, z; };

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern RecoveredGlobal_8023F1B8_lbl_804CCDA8 lbl_804CCDA8;
extern RecoveredGlobal_8023F1B8_lbl_804CCE60 lobby_scene_release_callback_table;
extern u32 game_mode_scene_instance;
void set_active_camera_pose(Vec_8023F22C *, Vec_8023F22C *);
void TCameraCtrl__ct(void *, void *);
s32 is_area_transfer_pending(void);
void apply_phase_keyboard_mode(void);
void run_load_callback_table(void *, s32);
void init_menu_scene_lights(void *, s32);
void set_copy_clear_color_argb(s32, s32, s32);
void load_floor_sound_bank(s32);
void *__nw__7TObjectFUl(u32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
}

extern "C" {
void fn_8023F160(void) {
    call_funcs_reverse__6TLobbyFPvUi(&lobby_scene_release_callback_table.value, 0x38);
}
void fn_8023F18C(void) {
    run_load_callback_table(&lobby_scene_release_callback_table.value, 0x38);
}
}
void clear_resource_load_tasks(void);
void set_screen_size(f32, f32);
extern Vec_8023F22C lbl_8044DCE8;
extern Vec_8023F22C lbl_8044DCF4;
extern u8 default_scene_light_config[];
extern Vec_8023F22C TObjLight__scene_light_state;
typedef char RecoveredGlobal_8023F1B8_lbl_804CCDA8_size[sizeof(RecoveredGlobal_8023F1B8_lbl_804CCDA8) == 0xB8 ? 1 : -1];
typedef char RecoveredGlobal_8023F1B8_lbl_804CCE60_size[sizeof(RecoveredGlobal_8023F1B8_lbl_804CCE60) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_8023F1B8_main_task_size[sizeof(RecoveredGlobal_8023F1B8_main_task) == 0x34 ? 1 : -1];

void TLobby::release_scene_resources() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    if ((u32) game_mode_scene_instance != 0U) {
        queue_destruction__7TObjectFv((void *)game_mode_scene_instance);
        game_mode_scene_instance = 0U;
    }
    main_task.delete_layer_children();
    call_funcs_reverse__6TLobbyFPvUi(&lobby_scene_release_callback_table.value, 0x38);
    call_funcs_reverse__6TLobbyFPvUi(&lbl_804CCDA8.value, 0xB8);
    TParticleCtrl::free_heap();
    clear_resource_load_tasks();
    render_tick();
}
void init_game_mode_select_scene(void) {
    s32 i;
    f32 c;
    void *p;
    set_screen_size(1.0f, 1.0f);
    set_copy_clear_color_argb(0, 0, 0);
    for (i = 0; i < 0x80; i++) {
    }
    reset_controller_input_state();
    clear_resource_load_tasks();
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(&lbl_804CCDA8.value, 0xb8);
    if (is_area_transfer_pending() != 0) {
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    run_load_callback_table(&lobby_scene_release_callback_table.value, 0x38);
    if (is_area_transfer_pending() != 0) {
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TParticleCtrl::init_heap((void *)0x100000);
    init_menu_scene_lights(default_scene_light_config, 4);
    TObjLight__scene_light_state.y = -1.0f * sin_table_lookup(0x1555);
    c = cos_table_lookup(0x1555);
    TObjLight__scene_light_state.x = c * sin_table_lookup(0x9000);
    TObjLight__scene_light_state.z = c * cos_table_lookup(0x9000);
    p = __nw__7TObjectFUl(0x1d4);
    if (p != NULL) {
        TCameraCtrl__ct(p, tl_camera);
    }
    {
        Vec_8023F22C eye = lbl_8044DCE8;
        Vec_8023F22C at = lbl_8044DCF4;
        TCameraCtrl::select_active_controller(9);
        set_active_camera_pose(&eye, &at);
    }
    TParticleCtrl::create_quad_sprites();
    p = (void *)new TWindowCtrlMain();
    game_mode_scene_instance = 0;
    load_floor_sound_bank(0);
}
