#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_flag_bit5() {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return ((u16) TWindowCtrl__active_window->flags >> 5U) & 1;
}
