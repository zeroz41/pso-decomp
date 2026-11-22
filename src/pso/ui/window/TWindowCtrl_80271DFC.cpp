#include "types.h"
#include "pso/ui/window/TWindowCtrl_80271DFC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"


void TWindowCtrl::set_flag_bit0() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags |= 1;
    }
}

void TWindowCtrl::clear_active_flag() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags &= ~1;
    }
}

    extern int TRaderMapCore__view_mode;
void TRaderMapCore::clear() { TRaderMapCore__view_mode = 0; }

    extern int TWindowSubStatusDisp__count_ratio_value;
int get_window_count_ratio_value(void) {  return TWindowSubStatusDisp__count_ratio_value; }
