#include "musyx/runtime/musyx_internal.h"

extern "C" {

void salApplyMatrix(const SND_FMATRIX *mat, const SND_FVECTOR *in, SND_FVECTOR *out) {
    out->x = mat->m[0][0] * in->x + mat->m[0][1] * in->y + mat->m[0][2] * in->z + mat->t[0];
    out->y = mat->m[1][0] * in->x + mat->m[1][1] * in->y + mat->m[1][2] * in->z + mat->t[1];
    out->z = mat->m[2][0] * in->x + mat->m[2][1] * in->y + mat->m[2][2] * in->z + mat->t[2];
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
static inline f32 salSqrtf(f32 x) {
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
f32 salNormalizeVector(SND_FVECTOR *vec) {
    f32 l = salSqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
    vec->x /= l;
    vec->y /= l;
    vec->z /= l;
    return l;
}
#pragma pop

}
