#include "types.h"
#include "pso/ui/window/TWindowCtrl_80271DFC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

void TWindowCtrl::set_flag_bit0() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 1);
    }
}

void TWindowCtrl::clear_active_flag() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFE);
    }
}

    extern int TRaderMapCore__view_mode;
void TRaderMapCore::clear() { TRaderMapCore__view_mode = 0; }

    extern int TWindowSubStatusDisp__count_ratio_value;
int get_window_count_ratio_value(void) {  return TWindowSubStatusDisp__count_ratio_value; }
