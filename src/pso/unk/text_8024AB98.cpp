#include "types.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/WindowCtrlCallback.h"


extern PlayerWindowCommand TWindowSubComCard__window_ctrl_callback_pmf;
extern PlayerWindowCommand lbl_804CEA64;
extern PlayerWindowCommand lbl_804CEA58;

void TWindowSubComCard__sub_8024AB98(saddr client_id) {
    call_window_method__11TWindowCtrlFPvi(client_id, TWindowSubComCard__window_ctrl_callback_pmf);
}

void TObjPlayer__sub_8024ABDC(saddr arg0) {
    call_window_method__11TWindowCtrlFPvi(arg0, lbl_804CEA64);
}

void TLobby__sub_8024AC20(saddr arg0) {
    call_window_method__11TWindowCtrlFPvi(arg0, lbl_804CEA58);
}
