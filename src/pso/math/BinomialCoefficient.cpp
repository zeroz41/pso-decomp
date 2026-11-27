#include "types.h"
#include "pso/math/BinomialCoefficient.h"

// Where fractional_part leaves the whole part it drops.
f32 fractional_part_whole;

#pragma push
#pragma optimize_for_size off
#pragma scheduling off
#pragma peephole off
s32 calc_binomial_coefficient(s32 n, s32 k) {
    s32 d = 1;
    s32 r = 1;
    s32 i;
    for (i = k; i != 0; i--) {
        d *= i;
        r *= n - i + 1;
    }
    return r / d;
}
#pragma pop

// MSL math.h's inline float classification and split.
inline int __fpclassifyf(float __value) {
    switch (*(int *)&__value & 0x7f800000) {
    case 0x7f800000:
        if ((*(int *)&__value & 0x7fffff) != 0) {
            return 1;
        }
        return 2;
    case 0:
        if ((*(int *)&__value & 0x7fffff) != 0) {
            return 5;
        }
        return 3;
    }
    return 4;
}
inline float modff(float x, float *iptr) {
    float frac;
    long i;
    switch (__fpclassifyf(x)) {
    case 1:
    case 3:
        *iptr = x;
        return x;
    case 2:
        *iptr = x;
        return 0.0f;
    case 5:
        *iptr = 0.0f;
        return x;
    }
    i = (long) x;
    frac = x - (float) i;
    if (*(int *)&frac == 0 || (*(int *)&x & 0x7f800000) >= 0x4b800000) {
        *iptr = x;
        return 0.0f;
    }
    *iptr = (float) i;
    return frac;
}
#pragma push
#pragma peephole off
#pragma scheduling off
f32 fractional_part(f32 x) {
    return modff(x, &fractional_part_whole);
}
#pragma pop
