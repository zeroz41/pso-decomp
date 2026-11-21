#include "pso/ui/window/WindowCtrlCallback.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024ADAC.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

void TWindowCtrl::set_flag_bit2() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 4);
    }
}

void TWindowCtrl::clear_flag_bit2() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFFFFFB);
    }
}

extern "C" {
extern PlayerWindowCommand lbl_804CEA1C;
extern PlayerWindowCommand lbl_804CEA10;
void TWindowCtrl__sub_8024ADAC(saddr arg0) {
    PlayerWindowCommand callback = lbl_804CEA1C;
    call_window_method__11TWindowCtrlFPvi(arg0, callback);
}
void TWindowCtrl__sub_8024ADF0(saddr arg0) {
    PlayerWindowCommand callback = lbl_804CEA10;
    call_window_method__11TWindowCtrlFPvi(arg0, callback);
}

}
