#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

void salApplyMatrix(u8 *mat, u8 *arg1, u8 *arg2) {
    *(f32 *)((s8 *)arg2 + 0) = (f32) (*(f32 *)((s8 *)mat + 0x24) + ((*(f32 *)((s8 *)mat + 8) * *(f32 *)((s8 *)arg1 + 8)) + ((*(f32 *)((s8 *)mat + 0) * *(f32 *)((s8 *)arg1 + 0)) + (*(f32 *)((s8 *)mat + 4) * *(f32 *)((s8 *)arg1 + 4)))));
    *(f32 *)((s8 *)arg2 + 4) = (f32) (*(f32 *)((s8 *)mat + 0x28) + ((*(f32 *)((s8 *)mat + 0x14) * *(f32 *)((s8 *)arg1 + 8)) + ((*(f32 *)((s8 *)mat + 0xC) * *(f32 *)((s8 *)arg1 + 0)) + (*(f32 *)((s8 *)mat + 0x10) * *(f32 *)((s8 *)arg1 + 4)))));
    *(f32 *)((s8 *)arg2 + 8) = (f32) (*(f32 *)((s8 *)mat + 0x2C) + ((*(f32 *)((s8 *)mat + 0x20) * *(f32 *)((s8 *)arg1 + 8)) + ((*(f32 *)((s8 *)mat + 0x18) * *(f32 *)((s8 *)arg1 + 0)) + (*(f32 *)((s8 *)mat + 0x1C) * *(f32 *)((s8 *)arg1 + 4)))));
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
static inline f32 sqrtf_803BAD1C(f32 x) {
    static const f64 _half = .5;
    static const f64 _three = 3.0;
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte((f64)x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}
f32 salNormalizeVector(Vec_803BAD1C *vec) {
    f32 l = sqrtf_803BAD1C(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
    vec->x /= l;
    vec->y /= l;
    vec->z /= l;
    return l;
}
#pragma pop

}
