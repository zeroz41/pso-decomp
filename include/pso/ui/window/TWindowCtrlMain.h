#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/WindowControlState.h"

struct TWindowCtrlScreen;
class TWindowCtrlSub;

struct TWindowCtrlMain : public TObject {
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
    static void advance_card_status(s32 local_client_id);
    static void free_window();
    static void release_ptr(void **arg0);
    static f32 get_scale();
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

extern "C" {
// TWindowCtrlMain::reset_all(0): the load hook the scene hook tables pair with free_all_windows.
void TWindowCtrlMain__sub_8024D838(void);
}
#endif
