#include "types.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod window_ctrl_init_params;

void fn_8024AB54(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, window_ctrl_init_params);
}
}
