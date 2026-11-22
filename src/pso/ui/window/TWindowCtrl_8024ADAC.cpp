#include "pso/ui/window/WindowCtrlCallback.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024ADAC.h"
#include "pso/ui/window/TWindowCtrl.h"


void TWindowCtrl::set_flag_bit2() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags |= 4;
    }
}

void TWindowCtrl::clear_flag_bit2() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->flags &= ~4;
    }
}

extern "C" {
extern PlayerWindowCommand lbl_804CEA1C;
extern PlayerWindowCommand lbl_804CEA10;
void TWindowCtrl__sub_8024ADAC(saddr client_id) {
    PlayerWindowCommand callback = lbl_804CEA1C;
    call_window_method__11TWindowCtrlFPvi(client_id, callback);
}
void TWindowCtrl__sub_8024ADF0(saddr client_id) {
    PlayerWindowCommand callback = lbl_804CEA10;
    call_window_method__11TWindowCtrlFPvi(client_id, callback);
}

}
