#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


void TWindowCtrl::set_flag_active() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags |= 8;
    }
}

void TWindowCtrl::clear_flag_8() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags &= ~8;
    }
}
