#ifndef PSO_MATH_SCRATCHVECTORS_H
#define PSO_MATH_SCRATCHVECTORS_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// Global scratch storage the game's movement code computes in.
struct ScratchRotation {
    s32 x;
    s32 y;
    s32 z;
};

extern Vec scratch_vec;
extern Vec scratch_vec2;
extern Vec scratch_vec3;
extern Vec scratch_vec4;
extern ScratchRotation scratch_rotation;

#endif
