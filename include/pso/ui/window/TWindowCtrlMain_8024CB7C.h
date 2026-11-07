#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024CB7C_H

#include "types.h"
#include "pso/unk/WindowControlState.h"

class TObject;

extern "C" {
void TWindowCtrlMain__sub_8024CB7C(void);
void TWindowCtrlMain__sub_8024CB8C(void);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
TObject *TWindowCtrlMain__sub_8024CDB0(void *p);
TObject *TWindowCtrlMain__sub_8024CDD0(s32 arg0);
TObject *TWindowCtrlMain__sub_8024CE24(void);
TObject *TWindowCtrlMain__sub_8024CE34(void);
bool TWindowCtrlMain__sub_8024CE58(void);
}
void draw_menu_backdrop_gradients(s32 viewport_index);
extern "C" {
s32 is_window_display_enabled(void);
}

#endif
