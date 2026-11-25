#ifndef PSO_MATH_MATRIXTRANSFORMS_H
#define PSO_MATH_MATRIXTRANSFORMS_H

#include "types.h"
#include <dolphin/mtx.h>
struct Vec;

// Converts Ninja x/y/z angles (0x10000 = full turn) to a quaternion.
void euler_yxz_to_quaternion(const s32 *ang, f32 *quat);
void euler_zyx_to_quaternion(const s32 *ang, f32 *quat);
extern "C" {
// Translates matrix (the current matrix when NULL) by (x, y, z).
void translate_matrix(MtxP matrix, f32 x, f32 y, f32 z);
// *v -= *sub
void subtract_vector(Vec *v, const Vec *sub);
}

#endif
