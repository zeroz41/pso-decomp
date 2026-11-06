#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_flag_bit5() {
    if ((void *) TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return ((u16) *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) >> 5U) & 1;
}
