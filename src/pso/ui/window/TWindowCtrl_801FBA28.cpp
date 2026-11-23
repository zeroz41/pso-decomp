#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_flag_bit0() {
    if (instance == NULL) {
        return 0;
    }
    return instance->flags & 1;
}
