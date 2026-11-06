#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern s8 *TWindowCtrl__active_window;

s32 TWindowCtrl::get_window(s32 arg0) {
    if (TWindowCtrl__active_window == 0) {
        return 0;
    }
    if (arg0 < 0) {
        return 0;
    }
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(TWindowCtrl__active_window + 0x48))[arg0];
}
