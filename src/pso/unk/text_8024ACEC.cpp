#include "types.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod player_keyboard_hold_cb;

void begin_player_keyboard_hold(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, player_keyboard_hold_cb);
}
}
