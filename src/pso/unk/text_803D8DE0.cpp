#include "types.h"
#include "pso/unk/text_803D8DE0.h"

extern "C" {
typedef struct { f32 x, y, z, w; } Quat_803D8E0C;

extern s32 current_matrix;
#pragma push
#pragma scheduling off
void fn_803D8DE0(u32 matrix, Vec *src, Vec *dst, u32 count) {
    if (matrix == 0U) {
        matrix = current_matrix;
    }
    PSMTXMultVecArraySR((MtxP)matrix, src, dst, count);
}
#pragma pop
#pragma push
#pragma scheduling off
#pragma pop
#pragma push
#pragma scheduling off
#pragma pop

static inline f32 sqrtf_803D8E0C(f32 x) {
    if (x > 0.0f) {
        volatile f32 r;
        f64 g = __frsqrte(x);
        g = (0.5) * g * ((3.0) - x * (g * g));
        g = (0.5) * g * ((3.0) - x * (g * g));
        g = (0.5) * g * ((3.0) - x * (g * g));
        r = (f32)(x * g);
        return r;
    }
    return x;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void blend_quaternions_nlerp(Quat_803D8E0C *a, Quat_803D8E0C *b, Quat_803D8E0C *out, f32 t) {
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
