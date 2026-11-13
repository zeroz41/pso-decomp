#include "types.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod lbl_804CEA4C;

void fn_8024AC64(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, lbl_804CEA4C);
}
}
