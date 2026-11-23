#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_flag_bit5() {
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 5U) & 1;
}
