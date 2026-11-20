#ifndef PSO_SYSTEM_VECTOR_H
#define PSO_SYSTEM_VECTOR_H

#include "types.h"
#include <dolphin/mtx.h>

Vec * VecCopy(Vec *dst, const Vec *src);
// Copies three words: a Vec, or an x/y/z angle triple.
void copy_xyz(void *dst, void *src);
// Copies two words: an NJS_POINT2.
void copy_vec2(void *dst, void *src);

f32 normalize_vector_safe(Vec *vector);
f32 normalize_vector_xz(Vec *vector);
// Rotate v about the y axis by angle, then add origin.
void rotate_y_and_translate(Vec *v, Vec *origin, s32 angle);

#endif
