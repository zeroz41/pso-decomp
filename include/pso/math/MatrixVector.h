#ifndef PSO_MATH_MATRIXVECTOR_H
#define PSO_MATH_MATRIXVECTOR_H

#include "types.h"
#include <dolphin/mtx.h>

extern "C" {
void rotate_matrix_about_axis(u8 *arg0, saddr arg1, s32 angle);
void rotate_vector_by_matrix(uaddr matrix, const Vec *src, Vec *dst);
void scale_matrix_vec3(u8 *matrix, u8 *arg1);
void set_matrix_identity(u8 *matrix);
void translate_matrix_vec3(u8 *matrix, u8 *arg1);
f32 vec_squared_length(const Vec *v);
// |v| (hand-written assembly, estimate precision).
f32 vector_length(const Vec *v);
// Sets m to the identity (hand-written assembly).
void matrix_identity(MtxP m);
}

#endif
