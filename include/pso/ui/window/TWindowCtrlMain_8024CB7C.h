#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H

#include "types.h"
#include "pso/unk/WindowControlState.h"

class TObject;

s32 get_viewport_fill_color(s32 viewport_index);
TObject *get_main_window_root(void);
TObject *get_clip_out_window_root(void);
extern "C" {
TObject *TWindowCtrlMain__sub_8024CDB0(void *p);
TObject *get_viewport_window_root(s32 viewport_index);
s32 has_window_task_root(void);
}
void draw_menu_backdrop_gradients(s32 viewport_index);
extern "C" {
s32 is_window_display_enabled(void);
}

#endif
