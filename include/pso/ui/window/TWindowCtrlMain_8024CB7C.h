#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H

#include "types.h"

extern "C" {
void TWindowCtrlMain__sub_8024CB7C(void);
void TWindowCtrlMain__sub_8024CB8C(void);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
s32 TWindowCtrlMain__sub_8024CDB0(void *p);
s32 TWindowCtrlMain__sub_8024CDD0(s32 arg0);
s32 TWindowCtrlMain__sub_8024CE24(void);
s32 TWindowCtrlMain__sub_8024CE34(void);
bool TWindowCtrlMain__sub_8024CE58(void);
}
void draw_menu_backdrop_gradients(s32 viewport_index);
WindowControlState *get_window_control_state(s32 viewport_index);
extern "C" {
s32 is_window_display_enabled(void);
}

#endif
