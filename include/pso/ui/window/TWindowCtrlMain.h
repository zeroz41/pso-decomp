#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/WindowControlState.h"

struct TWindowCtrlScreen;
class TWindowCtrlSub;

struct TWindowCtrlMain : public TObject {
    static const char *class_name;
    // The scene hook tables pair this load hook with free_all_windows.
    static void reset_windows();
    static void disable_display();
    static void enable_display();
    static TObject * window_task_root;
    static s32 display_flags;
    static TObject *instance;
    static TWindowCtrlScreen *screen_controller;
    static TWindowCtrlSub *sub_controller;
    static WindowControlState viewport_states[6];
    TWindowCtrlMain();
    virtual ~TWindowCtrlMain();
    void render();
    void run_task();
    static void free_all_windows();
    static void reset_all(void* _w0);
    static saddr get_instance();
    static void free_window();
    static void release_ptr(TObject **ptr);
    static f32 get_scale(s32 viewport);
    static f32 get_bottom(s32 viewport_index);
    static f32 get_right(s32 viewport_index);
    static f32 get_top(s32 viewport_index);
    static f32 get_left(s32 viewport_index);
    static void set_bottom(f32 value, s32 viewport_index);
    static void set_left(f32 value, s32 viewport_index);
    static void update_fade_alphas();
    static void set_fill_color(s32 viewport_index, s32 color);
    static void free_shared_draw_context();

};

LAYOUT_ASSERT(TWindowCtrlMain_size, sizeof(TWindowCtrlMain) == 0x1C);

s32 get_viewport_fill_color(s32 viewport_index);
TObject *get_main_window_root(void);
TObject *get_clip_out_window_root(void);
TObject *get_client_window_root(s32 client);
TObject *get_viewport_window_root(s32 viewport_index);
s32 has_window_task_root(void);
void draw_menu_backdrop_gradients(s32 viewport_index);
s32 is_window_display_enabled(void);

s16 get_function_key_menu(void *menu);

char *build_status_text(s32 client_id);

#endif
