#include "types.h"
#include "pso/boss/derolle/RandomAngle.h"
#include <stdlib.h>

s32 random_angle() {
    return (s32) (random_angle_range * (random_unit_scale * (f32) rand()));
}
