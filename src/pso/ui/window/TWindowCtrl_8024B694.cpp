#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::set_window_flags_off(s32 arg1) {
    TWindowCtrl::set_window_flags(this, arg1, 0);
}
