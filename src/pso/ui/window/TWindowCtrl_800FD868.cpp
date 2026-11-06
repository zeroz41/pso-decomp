#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

void TWindowCtrl::clear_flag_2() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFFFFFD);
    }
}

void TWindowCtrl::set_close_flag() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 2);
    }
}
