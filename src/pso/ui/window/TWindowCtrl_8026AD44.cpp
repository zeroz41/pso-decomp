#include "types.h"
#include "pso/ui/window/TWindowCtrl_8026AD44.h"
#include "pso/ui/window/TWindowCtrl.h"


TWindowMessageLog *TWindowCtrl::get_field44() {
    if (instance == NULL) {
        return 0;
    }
    return instance->message_log;
}

void TWindowCtrl__sub_8026AD60(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = NULL;
    }
}

void TWindowCtrl__sub_8026AD78(TWindowMessageLog *window_message_log) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = window_message_log;
    }
}
