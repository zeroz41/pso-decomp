#include "types.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod lbl_804CEA40;

void TWindowReturnCity__sub_8024ACA8(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, lbl_804CEA40);
}
}
