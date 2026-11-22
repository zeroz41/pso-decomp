#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_flag_bit0() {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return TWindowCtrl__active_window->flags & 1;
}
