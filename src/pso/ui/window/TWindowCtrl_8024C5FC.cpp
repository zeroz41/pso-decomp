#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern s8 *TWindowCtrl__active_window;

saddr TWindowCtrl::get_window(s32 client_id) {
    if (TWindowCtrl__active_window == 0) {
        return 0;
    }
    if (client_id < 0) {
        return 0;
    }
    if (client_id >= 0xC) {
        return 0;
    }
    return ((s32 *)(TWindowCtrl__active_window + 0x48))[client_id];
}
