#include "types.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/WindowCtrlCallback.h"

extern "C" {
extern WindowCtrlMethod TWindowSubComCard__window_ctrl_callback_pmf;
extern WindowCtrlMethod lbl_804CEA64;
extern WindowCtrlMethod lbl_804CEA58;

void TWindowSubComCard__sub_8024AB98(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, TWindowSubComCard__window_ctrl_callback_pmf);
}

void TObjPlayer__sub_8024ABDC(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, lbl_804CEA64);
}

void TLobby__sub_8024AC20(s32 arg0) {
    call_window_method__11TWindowCtrlFPvi((void *)arg0, lbl_804CEA58);
}
}
