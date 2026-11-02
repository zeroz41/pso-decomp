#ifndef PSO_MATH_ANGLE_LOOKUP_H
#define PSO_MATH_ANGLE_LOOKUP_H

#include "types.h"

// One {sin, cos} pair per 1/65536 turn, built by init_sin_cos_table; the
// lookups below are the Ninja library's hand-written assembly.
struct SinCosPair {
    f32 sin;
    f32 cos;
};

extern "C" {
extern SinCosPair *sin_cos_table;
f32 sin_table_lookup(s32 angle);
f32 cos_table_lookup(s32 angle);
}

#endif
