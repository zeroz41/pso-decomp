#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 is_split_screen();
extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_display_flag() {
    if (is_split_screen() != 0) {
        return 0;
    }
    if ((void *) TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return ((u16) *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) >> 1U) & 1;
}

}
