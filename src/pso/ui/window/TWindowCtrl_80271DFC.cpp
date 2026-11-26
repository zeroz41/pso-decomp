#include "types.h"
#include "pso/ui/window/TWindowCtrl_80271DFC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"


void TWindowCtrl::set_flag_bit0() {
    if (instance != NULL) {
        instance->flags |= 1;
    }
}

void TWindowCtrl::clear_active_flag() {
    if (instance != NULL) {
        instance->flags &= ~1;
    }
}

void TRaderMapCore::clear() { TRaderMapCore::view_mode = 0; }

int get_window_count_ratio_value(void) { return TWindowSubStatusDisp::count_ratio_value; }
