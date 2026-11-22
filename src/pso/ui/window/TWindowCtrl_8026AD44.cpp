#include "types.h"
#include "pso/ui/window/TWindowCtrl_8026AD44.h"
#include "pso/ui/window/TWindowCtrl.h"


TWindowMessageLog *TWindowCtrl::get_field44() {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return TWindowCtrl__active_window->message_log;
}

void TWindowCtrl__sub_8026AD60(void) {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->message_log = NULL;
    }
}

void TWindowCtrl__sub_8026AD78(TWindowMessageLog *window_message_log) {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->message_log = window_message_log;
    }
}
