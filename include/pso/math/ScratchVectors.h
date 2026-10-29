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
extern ScratchRotation scratch_rotation;

#endif
