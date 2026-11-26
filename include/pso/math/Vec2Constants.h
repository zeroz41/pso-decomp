#ifndef PSO_MATH_VEC2CONSTANTS_H
#define PSO_MATH_VEC2CONSTANTS_H

#include "types.h"

struct NJS_POINT2;

const NJS_POINT2 *get_large_vec2(void);
const NJS_POINT2 *get_one_vec2(void);
extern "C" {
const NJS_POINT2 *get_zero_vec2(void);
}

#endif
