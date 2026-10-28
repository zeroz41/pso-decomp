#include "types.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

s32 TOKeyMachine01::is_state_active() {
    if ((get_current_area() == 0x1C) || (get_current_area() == 0x1D) || (get_current_area() == 0x20) || (get_current_area() == 0x1F)) {
        return 1;
    }
    return 0;
}
