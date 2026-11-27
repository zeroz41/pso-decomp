#include "types.h"
#include "pso/ui/window/TWindowCtrlMessageLog.h"
#include "pso/ui/window/TWindowCtrl.h"


TWindowMessageLog *TWindowCtrl::get_field44() {
    if (instance == NULL) {
        return 0;
    }
    return instance->message_log;
}

void clear_message_log_window(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = NULL;
    }
}

void set_message_log_window(TWindowMessageLog *window_message_log) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = window_message_log;
    }
}
