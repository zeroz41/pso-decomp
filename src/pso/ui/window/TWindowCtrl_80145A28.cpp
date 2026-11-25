#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_pulse_color() {
    if (instance == NULL) {
        return -0x1600;
    }
    return instance->pulse_color;
}
