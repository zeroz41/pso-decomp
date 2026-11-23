#ifndef PSO_UNK_TEXT_803D8DE0_H
#define PSO_UNK_TEXT_803D8DE0_H

#include "types.h"
#include <dolphin/mtx.h>

// --- C functions defined in text_803D8DE0.cpp ---
extern "C" {
// Transforms count vectors by the rotation part of matrix (the current one
// for 0), src and dst may be the same array.
void fn_803D8DE0(MtxP matrix, Vec *src, Vec *dst, u32 count);
// Normalized linear blend from a to b by t, taking the shorter arc.
void blend_quaternions_nlerp(const Quaternion *a, const Quaternion *b, Quaternion *out, f32 t);
}
// --- end of C functions

#endif
