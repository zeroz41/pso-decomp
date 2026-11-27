#ifndef PSO_MATH_QUATERNIONBLEND_H
#define PSO_MATH_QUATERNIONBLEND_H

#include "types.h"
#include <dolphin/mtx.h>

// Transforms count vectors by the rotation part of matrix (the current one
// for 0), src and dst may be the same array.
void mult_vec_array_sr(MtxP matrix, Vec *src, Vec *dst, u32 count);
extern "C" {
// Normalized linear blend of the quaternions a to b by t into out, taking the
// shorter arc.
void blend_quaternions_nlerp(const f32 *a, const f32 *b, f32 t, f32 *out);
}

#endif
