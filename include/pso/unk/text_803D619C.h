#ifndef PSO_UNK_TEXT_803D619C_H
#define PSO_UNK_TEXT_803D619C_H

#include "types.h"

extern "C" {
int __fpclassifyf_803D6308(float __value);
}
f32 fractional_part(f32 x);
// n choose k.
s32 calc_binomial_coefficient(s32 n, s32 k);
extern "C" {
float modff_803D6308(float x, float *iptr);
}

#endif
