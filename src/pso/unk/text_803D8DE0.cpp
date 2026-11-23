#include "types.h"
#include "pso/unk/text_803D8DE0.h"
#include "pso/render/RenderSbssGlobals.h"

extern "C" {
#pragma push
#pragma scheduling off
void fn_803D8DE0(MtxP matrix, Vec *src, Vec *dst, u32 count) {
    if (matrix == NULL) {
        matrix = *current_matrix;
    }
    PSMTXMultVecArraySR(matrix, src, dst, count);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void blend_quaternions_nlerp(const Quaternion *a, const Quaternion *b, Quaternion *out, f32 t) {
    f32 x, y, z, w;
    f32 inv;
    f32 ax, ay, az, aw, bx, by, bz, bw;
    f32 s;
    f32 mag;

    ax = a->x;
    ay = a->y;
    az = a->z;
    aw = a->w;
    bx = b->x;
    by = b->y;
    bz = b->z;
    bw = b->w;
    s = (1.0f) - t;

    if (aw * bw + (az * bz + (ax * bx + ay * by)) > (0.0f)) {
        x = ax * s + bx * t;
        y = ay * s + by * t;
        z = az * s + bz * t;
        w = aw * s + bw * t;
    } else {
        x = ax * s - bx * t;
        y = ay * s - by * t;
        z = az * s - bz * t;
        w = aw * s - bw * t;
    }
    mag = w * w + (z * z + (x * x + y * y));
    if (mag > 0.0f) {
        volatile f32 r;
        f64 g = __frsqrte(mag);
        g = (0.5) * g * ((3.0) - mag * (g * g));
        g = (0.5) * g * ((3.0) - mag * (g * g));
        g = (0.5) * g * ((3.0) - mag * (g * g));
        r = (f32)(mag * g);
        mag = r;
    }
    inv = (1.0f) / mag;
    out->x = x * inv;
    out->y = y * inv;
    out->z = z * inv;
    out->w = w * inv;
}
#pragma pop

}
