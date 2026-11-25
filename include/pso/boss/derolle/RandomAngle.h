#ifndef PSO_BOSS_DEROLLE_RANDOMANGLE_H
#define PSO_BOSS_DEROLLE_RANDOMANGLE_H

#include "types.h"

// rand() * random_unit_scale * random_angle_range: a random angle in [0, 0x10000).
s32 random_angle();
extern const f32 random_unit_scale;
extern const f32 random_angle_range;

#endif
