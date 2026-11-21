#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::set_window_flags_off(s32 client, s32 flags) {
    TWindowCtrl::set_window_flags((void *)client, flags, 0);
}
