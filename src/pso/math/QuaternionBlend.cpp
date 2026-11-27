#include "types.h"
#include "pso/math/QuaternionBlend.h"
#include "pso/render/RenderSbssGlobals.h"

#pragma push
#pragma scheduling off
void mult_vec_array_sr(MtxP matrix, Vec *src, Vec *dst, u32 count) {
    if (matrix == NULL) {
        matrix = *current_matrix;
    }
    PSMTXMultVecArraySR(matrix, src, dst, count);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
void blend_quaternions_nlerp(const f32 *a, const f32 *b, f32 t, f32 *out) {
    f32 x, y, z, w;
    f32 inv;
    f32 ax, ay, az, aw, bx, by, bz, bw;
    f32 s;
    f32 mag;

    ax = a[0];
    ay = a[1];
    az = a[2];
    aw = a[3];
    bx = b[0];
    by = b[1];
    bz = b[2];
    bw = b[3];
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
    out[0] = x * inv;
    out[1] = y * inv;
    out[2] = z * inv;
    out[3] = w * inv;
}
}
#pragma pop
