#include "types.h"
#include "pso/unk/text_803D619C.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

f32 lbl_805D76A8;

#pragma push
#pragma optimize_for_size off
#pragma scheduling off
#pragma peephole off
s32 TBoss8Dragon::calc_binomial_coefficient(s32 n, s32 k) {
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

inline int __fpclassifyf_803D6308(float __value) {
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
inline float modff_803D6308(float x, float *iptr) {
    float frac;
    long i;
    switch (__fpclassifyf_803D6308(x)) {
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
f32 fn_803D6308(f32 x) {
    return modff_803D6308(x, &lbl_805D76A8);
}
#pragma pop
