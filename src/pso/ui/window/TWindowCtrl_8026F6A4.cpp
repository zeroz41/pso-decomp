#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


void TWindowCtrl::set_flag_active() {
    if (instance != NULL) {
        instance->flags |= 8;
    }
}

void TWindowCtrl::clear_flag_8() {
    if (instance != NULL) {
        instance->flags &= ~8;
    }
}
