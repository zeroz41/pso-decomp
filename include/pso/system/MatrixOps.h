#ifndef PSO_SYSTEM_MATRIXOPS_H
#define PSO_SYSTEM_MATRIXOPS_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/render/gjSystem.h"

// The matrix stack's transforms (DebugFont.cpp .. text_803D96A8) that the
// other module headers do not declare yet. A NULL matrix is the current one.
extern "C" {
void rotate_matrix_x(MtxP matrix, s32 angle);
void rotate_matrix_z(MtxP matrix, s32 angle);
void scale_matrix(MtxP matrix, f32 sx, f32 sy, f32 sz);
// dst += src.
void vec3_add_to(Vec *dst, const Vec *src);
}

#endif
