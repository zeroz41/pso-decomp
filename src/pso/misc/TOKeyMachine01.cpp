#include "types.h"
#include "pso/map/CurrentArea.h"

extern s32 current_floor_area_type;

s32 get_current_area() {
    return current_floor_area_type;
}
