#ifndef PSO_MATH_ANGLE_LOOKUP_H
#define PSO_MATH_ANGLE_LOOKUP_H

#include "types.h"

// One {sin, cos} pair per 1/65536 turn, built by init_sin_cos_table; the
// lookups below are the Ninja library's hand-written assembly.
typedef struct SinCosPair SinCosPair;
struct SinCosPair {
    f32 sin;
    f32 cos;
};

#ifdef __cplusplus
extern "C" {
#endif
extern SinCosPair *sin_cos_table;
f32 sin_table_lookup(s32 angle);
f32 cos_table_lookup(s32 angle);
#ifdef __cplusplus
}
#endif

#endif
