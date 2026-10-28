#include "types.h"
#include "pso/map/FloorArea.h"

s32 is_central_control_area() {
    if ((get_current_floor_area() == AREA_SEABED_UPPER) || (get_current_floor_area() == AREA_SEABED_LOWER) || (get_current_floor_area() == AREA_BARBA_RAY) || (get_current_floor_area() == AREA_OLGA_FLOW)) {
        return 1;
    }
    return 0;
}
