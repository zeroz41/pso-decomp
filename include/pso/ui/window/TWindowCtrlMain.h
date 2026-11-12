#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlMain : public TObject {
    TWindowCtrlMain();
    virtual ~TWindowCtrlMain();
    void render();
    void run_task();
    static void free_all_windows();
    static void reset_all(void* _w0);
    void update_child_2c();
    void spawn_palette_slot_light(s32 kind);
    void update_field28();
    void free_member();
    s32 get_main_menu_message();
    static int get_instance();
    static void advance_card_status(s32 arg0);
    static void free_window();
    static void release_ptr(void **arg0);
    void init_fields();
    static f32 get_scale();
    f32 get_field_18();
    f32 get_ctrl_field14();
    f32 get_field10();
    f32 get_position_z();
    static void set_field18(f32 value, s32 viewport_index);
    static void set_depth(f32 value, s32 viewport_index);
    static void update_fade_alphas();
    static void set_value(s32 arg0, s32 arg1);
    static void free_keyboard_soft();
    void draw_strip_swap_color(s32 n, s32 flags, f32 _w3);
};

typedef char TWindowCtrlMain_size[sizeof(TWindowCtrlMain) == 0x1C ? 1 : -1];
#endif
