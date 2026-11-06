#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_field24() {
    if ((void *) TWindowCtrl__active_window == NULL) {
        return -0x1600;
    }
    return *(s32 *)((s8 *)TWindowCtrl__active_window + 0x24);
}
