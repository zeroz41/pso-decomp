#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 get_main_menu_message__15TWindowCtrlMainFv();
s32 get_window_layout_position(s32);

s32 TWindowCtrl::get_message_by_type(s8 arg0, s32 arg1) {
    s32 window;
    s32 var_r3;

    window = TWindowCtrl::get_window(arg1);
    if (window == 0) {
        return 0;
    }
    if (get_main_menu_message__15TWindowCtrlMainFv() != 0) {
        var_r3 = 0x4D;
    } else if (((TWindowCtrl *)window)->get_active_menu() != 0) {
        var_r3 = 0x48;
    } else {
        var_r3 = 0x43;
    }
    return get_window_layout_position(var_r3 + arg0);
}

extern void *TWindowCtrl__active_window;

void TWindowCtrl::release_slot(s8 *arg0) {
    s8 temp_r4;

    if ((void *) TWindowCtrl__active_window != NULL) {
        temp_r4 = *arg0;
        if ((temp_r4 >= 0) && (temp_r4 < 4)) {
            *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & ~(0x40 << temp_r4));
            *arg0 = -1;
        }
    }
}

}
