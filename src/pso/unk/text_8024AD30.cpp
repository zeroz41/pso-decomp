#include "types.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod window_ctrl_end_keyboard_hold_callback_entry;

void end_player_keyboard_hold(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, window_ctrl_end_keyboard_hold_callback_entry);
}
}
