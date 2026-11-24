#ifndef PSO_MATH_CLAMPED_STEP_H
#define PSO_MATH_CLAMPED_STEP_H

#include "types.h"

// Apply a signed step and clamp in the direction of travel.
extern "C" {
void approach_value(f32 *value, f32 step, f32 limit);
void add_angle_clamped(s32 *value, s32 step, s32 limit);
}

#endif
