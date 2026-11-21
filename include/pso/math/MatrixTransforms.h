#ifndef PSO_MATH_MATRIXTRANSFORMS_H
#define PSO_MATH_MATRIXTRANSFORMS_H

#include "types.h"
struct Vec;

void euler_yxz_to_quaternion(u8 *arg0, u8 *arg1);
void euler_zyx_to_quaternion(u8 *arg0, u8 *arg1);
extern "C" {
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
// *v -= *sub
void subtract_vector(Vec *v, const Vec *sub);
}

#endif
