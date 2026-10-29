#ifndef PSO_UNK_TEXT_803D853C_H
#define PSO_UNK_TEXT_803D853C_H

#include "types.h"

void get_current_matrix(void *m);
extern "C" {
// dst = m * src; m is the current matrix when NULL.
void matrix_mult_vec(f32 (*m)[4], const struct Vec *src, struct Vec *dst);
}
void rotate_matrix_yxz(s32 matrix, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
}

#endif
