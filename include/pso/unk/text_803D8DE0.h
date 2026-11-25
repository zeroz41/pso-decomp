#ifndef PSO_UNK_TEXT_803D8DE0_H
#define PSO_UNK_TEXT_803D8DE0_H

#include "types.h"
#include <dolphin/mtx.h>

// Transforms count vectors by the rotation part of matrix (the current one
// for 0), src and dst may be the same array.
void mult_vec_array_sr(MtxP matrix, Vec *src, Vec *dst, u32 count);
extern "C" {
// Normalized linear blend from a to b by t, taking the shorter arc.
void blend_quaternions_nlerp(const Quaternion *a, const Quaternion *b, Quaternion *out, f32 t);
}

#endif
