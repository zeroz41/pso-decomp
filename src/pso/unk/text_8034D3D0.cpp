#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/TDuelEffectString.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/math/CurvePathPoint.h"

extern "C" {
s32 fn_8034D3D0(CurvePathPoint *e, f32 scale, s32 n, s32 step, s32 closed, Vec *out, s32) {
    f32 sum;
    f32 total;
    f32 ratio;
    s32 i;

    if (e == NULL || n <= 1) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += e[i].length;
    }
    if (0.0f == sum) {
        return 0;
    }
    if (closed == 0) {
        total = (s32) (sum - e[n - 1].length);
    } else {
        total = (s32) sum;
    }
    ratio = scale * step; ratio /= total;
    if (ratio >= 1.0f) {
        return 1;
    }
    return TBoss8Dragon::eval_bezier_curve(e, n, closed, out, ratio);
}
}

#pragma push
#pragma fp_contract on
s32 TBoss8Dragon::eval_bezier_curve(CurvePathPoint *pts, int count, int closed, Vec *out, f32 t) {
    s32 n;
    s32 i;
    f32 u;
    f32 w;
    f32 a;
    f32 b;
    s32 k;
    if (count <= 2) {
        return 0;
    }
    n = count - 1;
    u = (1.0f) - t;
    out->z = out->y = out->x = (0.0f);
    if (closed == 0) {
        for (i = 0; i <= n; i++) {
            k = calc_binomial_coefficient(n, i);
            a = pow(t, (f32)i);
            b = pow(u, (f32)(n - i));
            w = ((f32)k * a) * b;
            out->x += w * pts[i].pos.x;
            out->y += w * pts[i].pos.y;
            out->z += w * pts[i].pos.z;
        }
    } else {
        count = n + 1;
        for (i = 0; i <= n; i++) {
            k = calc_binomial_coefficient(count, i);
            a = pow(t, (f32)i);
            b = pow(u, (f32)(count - i));
            w = ((f32)k * a) * b;
            if (i == n) {
                out->x += w * pts[0].pos.x;
                out->y += w * pts[0].pos.y;
                out->z += w * pts[0].pos.z;
            } else {
                out->x += w * pts[i].pos.x;
                out->y += w * pts[i].pos.y;
                out->z += w * pts[i].pos.z;
            }
        }
    }
    if ((1.0f) == t) {
        return 1;
    }
    return 0;
}
#pragma pop

extern "C" {

#pragma push
#pragma fp_contract on
s32 fn_8034D790(CurvePathPoint *e, f32 scale, s32 n, s32 count, s32 closed, Vec *out) {
    Vec a;
    Vec b;
    Vec d;
    f32 sum;
    f32 pos;
    f32 acc;
    f32 prev;
    s32 total;
    s32 seg;
    s32 i;
    s32 idx;

    if (e == NULL || n <= 1) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += e[i].length;
    }
    if (0.0f == sum) {
        return 0;
    }
    pos = scale * count;
    if (closed == 0) {
        total = (s32)(sum - e[n - 1].length);
    } else {
        total = (s32)sum;
    }
    seg = (s32)pos / total;
    pos -= seg * sum;
    if (closed == 0 && seg != 0) {
        VecCopy((Vec *)out, &e[n - 1].pos);
        return 1;
    }
    acc = 0.0f;
    prev = acc;
    for (i = 0; i < n; i++) {
        acc += e[i].length;
        if (pos <= acc) {
            pos -= prev;
            idx = i;
            break;
        }
        prev = acc;
    }
    if (idx == n - 1) {
        VecCopy((Vec *)&a, &e[idx].pos);
        VecCopy((Vec *)&b, &e[0].pos);
    } else {
        VecCopy((Vec *)&a, &e[idx].pos);
        VecCopy((Vec *)&b, &e[idx + 1].pos);
    }
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    normalize_vector(&d);
    out->x = d.x * pos + a.x;
    out->y = d.y * pos + a.y;
    out->z = d.z * pos + a.z;
    return 0;
}
}
#pragma pop
