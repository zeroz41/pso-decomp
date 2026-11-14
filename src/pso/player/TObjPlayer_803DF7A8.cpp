#include "types.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 TObjPlayer__sub_803DFB1C(Vec_803E1B1C *a, Vec_803E1B1C *b);
s32 __SITransfer(Vec_803E1B1C *a, Vec_803E1B1C *b);
extern const Faces_803E0ED4 box_face_corner_index_table;
const Faces_803E0ED4 box_face_corner_index_table = {
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}}};
s32 test_box_overlap__10TObjPlayerFPvPv(Vec_803E1B1C *boxA, Vec_803E1B1C *boxB);
s32 TObjPlayer::test_aabb_overlap(u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *arg0 = (u8 *)this;
    if (*(f32 *)((s8 *)arg1 + 0) < *(f32 *)((s8 *)arg2 + 0)) {
        return 0;
    }
    if (*(f32 *)((s8 *)arg0 + 0) > *(f32 *)((s8 *)arg3 + 0)) {
        return 0;
    }
    if (*(f32 *)((s8 *)arg1 + 4) < *(f32 *)((s8 *)arg2 + 4)) {
        return 0;
    }
    if (*(f32 *)((s8 *)arg0 + 4) > *(f32 *)((s8 *)arg3 + 4)) {
        return 0;
    }
    if (*(f32 *)((s8 *)arg1 + 8) < *(f32 *)((s8 *)arg2 + 8)) {
        return 0;
    }
    return (u32) __cntlzw(*(f32 *)((s8 *)arg0 + 8) > *(f32 *)((s8 *)arg3 + 8)) >> 5;
}

#pragma push
#pragma fp_contract off
#pragma use_lmw_stmw off
struct Point2_803E0CC8 { f32 u, v; };
s32 TObjPlayer__sub_803DF9D0(Point2_803E0CC8 *a, Point2_803E0CC8 *b);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// MSL's inline fabs (the double-returning wrapper around __fabs).
static inline f64 fabs(f64 x) { return __fabs(x); }

// The area of the triangle a, b, c: half of |a - b| times the distance of c from the line through a and b.
f32 TObjPlayer__sub_803DF840(Point2_803E0CC8 *a, Point2_803E0CC8 *b, Point2_803E0CC8 *c) {
    f32 nx;
    f32 ny;
    f32 off;
    f32 cross;
    f32 height;
    f32 len;
    f32 base;
    f32 r;
    if ((f32)fabs(a->u - b->u) < 0.025f) {
        nx = 1.0f;
        ny = 0.0f;
        off = -a->u;
    } else {
        nx = b->v - a->v;
        ny = -(b->u - a->u);
        off = -a->u * nx - a->v * ny;
    }
    cross = fabs(off + (nx * c->u + ny * c->v));
    len = nx * nx + ny * ny;
    if (len > 0.0f) {
        volatile f32 y;
        f64 g = __frsqrte(len);
        g = 0.5 * g * (3.0 - len * (g * g));
        g = 0.5 * g * (3.0 - len * (g * g));
        g = 0.5 * g * (3.0 - len * (g * g));
        y = (f32)(len * g);
        len = y;
    }
    height = cross / len;
    base = (a->u - b->u) * (a->u - b->u) + (a->v - b->v) * (a->v - b->v);
    if (base > 0.0f) {
        volatile f32 y;
        f64 g = __frsqrte(base);
        g = 0.5 * g * (3.0 - base * (g * g));
        g = 0.5 * g * (3.0 - base * (g * g));
        g = 0.5 * g * (3.0 - base * (g * g));
        y = (f32)(base * g);
        r = y;
    } else {
        r = base;
    }
    return 0.5f * (height * r);
}

s32 TObjPlayer__sub_803DF9D0(Point2_803E0CC8 *a, Point2_803E0CC8 *b) {
    Point2_803E0CC8 *p;
    Point2_803E0CC8 *inner;
    Point2_803E0CC8 *outer;
    f32 areaA;
    f32 areaB;
    f32 limit;
    s32 i;
    areaA = TObjPlayer__sub_803DF840(a, a + 1, a + 2) + TObjPlayer__sub_803DF840(a, a + 2, a + 3);
    areaB = TObjPlayer__sub_803DF840(b, b + 1, b + 2) + TObjPlayer__sub_803DF840(b, b + 2, b + 3);
    if (areaA < areaB) {
        inner = a;
        outer = b;
        limit = areaB;
    } else {
        inner = b;
        outer = a;
        limit = areaA;
    }
    for (i = 0, p = inner, limit = 1.025f * limit; i < 4; p++, i++) {
        if (TObjPlayer__sub_803DF840(p, outer, outer + 1) + TObjPlayer__sub_803DF840(p, outer + 1, outer + 2) +
                TObjPlayer__sub_803DF840(p, outer + 2, outer + 3) + TObjPlayer__sub_803DF840(p, outer + 3, outer) <
            limit) {
            return 1;
        }
    }
    return 0;
}

// 0.025f is the coordinate and slope tolerance.

static inline f32 sqrtf_803DFB1C(f32 x) {
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte(x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

/* Two quads touch: in each of the XY, XZ and YZ projections an edge of one
   crosses an edge of the other, or one projection lies inside the other. */
s32 TObjPlayer__sub_803DFB1C(Vec_803E1B1C *a, Vec_803E1B1C *b) {
    Point2_803E0CC8 pa[4];
    Point2_803E0CC8 pb[4];
    s32 hitXY;
    s32 hitXZ;
    s32 hitYZ;
    s32 inXY;
    s32 inXZ;
    s32 inYZ;
    s32 i;
    s32 j;
    s32 result;

    hitXY = 0;
    hitXZ = 0;
    hitYZ = 0;
    {
        s32 vertA;
        s32 vertB;
        s32 parallel;
        s32 onA;
        s32 onB;
        f32 prevAu;
        f32 prevAv;
        f32 curAu;
        f32 curAv;
        f32 lineAu;
        f32 toPrev;
        f32 toCur;
        f32 length;
        f32 prevBu;
        f32 prevBv;
        f32 curBu;
        f32 curBv;
        f32 lengthSqA;
        f32 hitU;
        f32 interA;
        f32 slopeA;
        f32 hitV;
        f32 slopeB;
        f32 interB;
        f32 lineBu;

        prevAu = a[3].x;
        prevAv = a[3].y;
        for (i = 0; i < 4; i++) {
            curAu = a[i].x;
            curAv = a[i].y;
            if (prevAu < curAu - 0.025f || prevAu > 0.025f + curAu) {
                slopeA = (curAv - prevAv) / (curAu - prevAu);
                interA = prevAv - slopeA * prevAu;
                vertA = 0;
            } else {
                lineAu = prevAu;
                vertA = 1;
            }
            prevBu = b[3].x;
            prevBv = b[3].y;
            lengthSqA = (prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv);
            for (j = 0; j < 4; j++) {
                parallel = 0;
                curBu = b[j].x;
                curBv = b[j].y;
                if (prevBu < curBu - 0.025f || prevBu > 0.025f + curBu) {
                    slopeB = (curBv - prevBv) / (curBu - prevBu);
                    interB = prevBv - slopeB * prevBu;
                    vertB = 0;
                } else {
                    lineBu = prevBu;
                    vertB = 1;
                }
                if (vertA == 0 && vertB == 0) {
                    if (slopeA < slopeB - 0.025f || slopeA > 0.025f + slopeB) {
                        hitU = (interB - interA) / (slopeA - slopeB);
                        hitV = interA + slopeA * hitU;
                    } else {
                        parallel = 1;
                    }
                } else if (vertB == 0) {
                    hitU = lineAu;
                    hitV = interB + slopeB * hitU;
                } else if (vertA == 0) {
                    hitU = lineBu;
                    hitV = interA + slopeA * hitU;
                } else {
                    parallel = 1;
                }
                if (parallel == 0) {
                    onA = 0;
                    onB = 0;
                    toPrev = sqrtf_803DFB1C((prevAu - hitU) * (prevAu - hitU) + (prevAv - hitV) * (prevAv - hitV));
                    toCur = sqrtf_803DFB1C((curAu - hitU) * (curAu - hitU) + (curAv - hitV) * (curAv - hitV));
                    length = sqrtf_803DFB1C(lengthSqA);
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onA = 1;
                    }
                    toPrev = sqrtf_803DFB1C((prevBu - hitU) * (prevBu - hitU) + (prevBv - hitV) * (prevBv - hitV));
                    toCur = sqrtf_803DFB1C((curBu - hitU) * (curBu - hitU) + (curBv - hitV) * (curBv - hitV));
                    length = sqrtf_803DFB1C((prevBu - curBu) * (prevBu - curBu) + (prevBv - curBv) * (prevBv - curBv));
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onB = 1;
                    }
                    if (onA != 0 && onB != 0) {
                        hitXY = 1;
                        break;
                    }
                }
                prevBu = curBu;
                prevBv = curBv;
            }
            if (hitXY != 0) {
                break;
            }
            prevAu = curAu;
            prevAv = curAv;
        }
    }
    {
        s32 vertA;
        s32 vertB;
        s32 parallel;
        s32 onA;
        s32 onB;
        f32 prevBv;
        f32 prevAu;
        f32 prevAv;
        f32 curAu;
        f32 curAv;
        f32 lineAu;
        f32 toPrev;
        f32 toCur;
        f32 length;
        f32 prevBu;
        f32 curBu;
        f32 lengthSqA;
        f32 curBv;
        f32 slopeA;
        f32 interA;
        f32 hitU;
        f32 hitV;
        f32 slopeB;
        f32 interB;
        f32 lineBu;

        prevAu = a[3].x;
        prevAv = a[3].z;
        for (i = 0; i < 4; i++) {
            curAu = a[i].x;
            curAv = a[i].z;
            if (prevAu < curAu - 0.025f || prevAu > 0.025f + curAu) {
                slopeA = (curAv - prevAv) / (curAu - prevAu);
                interA = prevAv - slopeA * prevAu;
                vertA = 0;
            } else {
                lineAu = prevAu;
                vertA = 1;
            }
            prevBu = b[3].x;
            prevBv = b[3].z;
            lengthSqA = (prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv);
            for (j = 0; j < 4; j++) {
                parallel = 0;
                curBu = b[j].x;
                curBv = b[j].z;
                if (prevBu < curBu - 0.025f || prevBu > 0.025f + curBu) {
                    slopeB = (curBv - prevBv) / (curBu - prevBu);
                    interB = prevBv - slopeB * prevBu;
                    vertB = 0;
                } else {
                    lineBu = prevBu;
                    vertB = 1;
                }
                if (vertA == 0 && vertB == 0) {
                    if (slopeA < slopeB - 0.025f || slopeA > 0.025f + slopeB) {
                        hitU = (interB - interA) / (slopeA - slopeB);
                        hitV = interA + slopeA * hitU;
                    } else {
                        parallel = 1;
                    }
                } else if (vertB == 0) {
                    hitU = lineAu;
                    hitV = interB + slopeB * hitU;
                } else if (vertA == 0) {
                    hitU = lineBu;
                    hitV = interA + slopeA * hitU;
                } else {
                    parallel = 1;
                }
                if (parallel == 0) {
                    onA = 0;
                    onB = 0;
                    toPrev = sqrtf_803DFB1C((prevAu - hitU) * (prevAu - hitU) + (prevAv - hitV) * (prevAv - hitV));
                    toCur = sqrtf_803DFB1C((curAu - hitU) * (curAu - hitU) + (curAv - hitV) * (curAv - hitV));
                    length = sqrtf_803DFB1C(lengthSqA);
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onA = 1;
                    }
                    toPrev = sqrtf_803DFB1C((prevBu - hitU) * (prevBu - hitU) + (prevBv - hitV) * (prevBv - hitV));
                    toCur = sqrtf_803DFB1C((curBu - hitU) * (curBu - hitU) + (curBv - hitV) * (curBv - hitV));
                    length = sqrtf_803DFB1C((prevBu - curBu) * (prevBu - curBu) + (prevBv - curBv) * (prevBv - curBv));
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onB = 1;
                    }
                    if (onA != 0 && onB != 0) {
                        hitXZ = 1;
                        break;
                    }
                }
                prevBu = curBu;
                prevBv = curBv;
            }
            if (hitXZ != 0) {
                break;
            }
            prevAu = curAu;
            prevAv = curAv;
        }
    }
    {
        s32 vertA;
        s32 vertB;
        s32 parallel;
        s32 onA;
        s32 onB;
        f32 lengthSqA;
        f32 prevAu;
        f32 prevAv;
        f32 curAu;
        f32 curAv;
        f32 lineAu;
        f32 toPrev;
        f32 toCur;
        f32 length;
        f32 prevBu;
        f32 prevBv;
        f32 curBu;
        f32 curBv;
        f32 slopeA;
        f32 interA;
        f32 hitU;
        f32 hitV;
        f32 slopeB;
        f32 interB;
        f32 lineBu;

        prevAu = a[3].y;
        prevAv = a[3].z;
        for (i = 0; i < 4; i++) {
            curAu = a[i].y;
            curAv = a[i].z;
            if (prevAu < curAu - 0.025f || prevAu > 0.025f + curAu) {
                slopeA = (curAv - prevAv) / (curAu - prevAu);
                interA = prevAv - slopeA * prevAu;
                vertA = 0;
            } else {
                lineAu = prevAu;
                vertA = 1;
            }
            prevBu = b[3].y;
            prevBv = b[3].z;
            lengthSqA = (prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv);
            for (j = 0; j < 4; j++) {
                parallel = 0;
                curBu = b[j].y;
                curBv = b[j].z;
                if (prevBu < curBu - 0.025f || prevBu > 0.025f + curBu) {
                    slopeB = (curBv - prevBv) / (curBu - prevBu);
                    interB = prevBv - slopeB * prevBu;
                    vertB = 0;
                } else {
                    lineBu = prevBu;
                    vertB = 1;
                }
                if (vertA == 0 && vertB == 0) {
                    if (slopeA < slopeB - 0.025f || slopeA > 0.025f + slopeB) {
                        hitU = (interB - interA) / (slopeA - slopeB);
                        hitV = interA + slopeA * hitU;
                    } else {
                        parallel = 1;
                    }
                } else if (vertB == 0) {
                    hitU = lineAu;
                    hitV = interB + slopeB * hitU;
                } else if (vertA == 0) {
                    hitU = lineBu;
                    hitV = interA + slopeA * hitU;
                } else {
                    parallel = 1;
                }
                if (parallel == 0) {
                    onA = 0;
                    onB = 0;
                    toPrev = sqrtf_803DFB1C((prevAu - hitU) * (prevAu - hitU) + (prevAv - hitV) * (prevAv - hitV));
                    toCur = sqrtf_803DFB1C((curAu - hitU) * (curAu - hitU) + (curAv - hitV) * (curAv - hitV));
                    length = sqrtf_803DFB1C(lengthSqA);
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onA = 1;
                    }
                    toPrev = sqrtf_803DFB1C((prevBu - hitU) * (prevBu - hitU) + (prevBv - hitV) * (prevBv - hitV));
                    toCur = sqrtf_803DFB1C((curBu - hitU) * (curBu - hitU) + (curBv - hitV) * (curBv - hitV));
                    length = sqrtf_803DFB1C((prevBu - curBu) * (prevBu - curBu) + (prevBv - curBv) * (prevBv - curBv));
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onB = 1;
                    }
                    if (onA != 0 && onB != 0) {
                        hitYZ = 1;
                        break;
                    }
                }
                prevBu = curBu;
                prevBv = curBv;
            }
            if (hitYZ != 0) {
                break;
            }
            prevAu = curAu;
            prevAv = curAv;
        }
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].y;
        pb[i].u = b[i].x;
        pb[i].v = b[i].y;
    }
    inXY = TObjPlayer__sub_803DF9D0(pa, pb);
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].z;
        pb[i].u = b[i].x;
        pb[i].v = b[i].z;
    }
    inXZ = TObjPlayer__sub_803DF9D0(pa, pb);
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].y;
        pa[i].v = a[i].z;
        pb[i].u = b[i].y;
        pb[i].v = b[i].z;
    }
    inYZ = TObjPlayer__sub_803DF9D0(pa, pb);
    result = 0;
    if ((hitXY != 0 || inXY != 0) && (hitXZ != 0 || inXZ != 0) && (hitYZ != 0 || inYZ != 0)) {
        result = 1;
    }
    return result;
}
#pragma pop

s32 __SITransfer(Vec_803E1B1C *a, Vec_803E1B1C *b) {
    Point2_803E0CC8 pa[4];
    Point2_803E0CC8 pb[4];
    s32 mask = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].y;
        pb[i].u = b[i].x;
        pb[i].v = b[i].y;
    }
    if (TObjPlayer__sub_803DF9D0(pa, pb) != 0) {
        mask |= 4;
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].z;
        pb[i].u = b[i].x;
        pb[i].v = b[i].z;
    }
    if (TObjPlayer__sub_803DF9D0(pa, pb) != 0) {
        mask |= 2;
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].y;
        pa[i].v = a[i].z;
        pb[i].u = b[i].y;
        pb[i].v = b[i].z;
    }
    if (TObjPlayer__sub_803DF9D0(pa, pb) != 0) {
        mask |= 1;
    }
    return mask;
}

s32 test_box_overlap__10TObjPlayerFPvPv(Vec_803E1B1C *boxA, Vec_803E1B1C *boxB) {
    Vec_803E1B1C qa[4];
    Vec_803E1B1C qb[4];
    Vec_803E1B1C mnA;
    Vec_803E1B1C mxA;
    Vec_803E1B1C mnB;
    Vec_803E1B1C mxB;
    s32 i;
    s32 j;
    s32 mask;
    s32 *fa;
    s32 *fb;
    int k;
    mask = 0;
    calc_bounds_min_max__10TObjPlayerFPvPvPv((struct Vec_803E1B1C *)(boxA), (struct Vec_803E1B1C *)(&mnA), (struct Vec_803E1B1C *)(&mxA));
    calc_bounds_min_max__10TObjPlayerFPvPvPv((struct Vec_803E1B1C *)(boxB), (struct Vec_803E1B1C *)(&mnB), (struct Vec_803E1B1C *)(&mxB));
    if (((TObjPlayer *)((u8 *)&mnA))->test_aabb_overlap((u8 *)&mxA, (u8 *)&mnB, (u8 *)&mxB) != 0) {
    Faces_803E0ED4 faces = box_face_corner_index_table;
    for (i = 0; i < 6; i++) {
        fa = faces.v[i];
        qa[0].x = boxA[fa[0]].x; qa[0].y = boxA[fa[0]].y; qa[0].z = boxA[fa[0]].z;
        qa[1].x = boxA[fa[1]].x; qa[1].y = boxA[fa[1]].y; qa[1].z = boxA[fa[1]].z;
        qa[2].x = boxA[fa[2]].x; qa[2].y = boxA[fa[2]].y; qa[2].z = boxA[fa[2]].z;
        qa[3].x = boxA[fa[3]].x; qa[3].y = boxA[fa[3]].y; qa[3].z = boxA[fa[3]].z;
        for (j = 0; j < 6; j++) {
            fb = faces.v[j];
            qb[0].x = boxB[fb[0]].x; qb[0].y = boxB[fb[0]].y; qb[0].z = boxB[fb[0]].z;
            qb[1].x = boxB[fb[1]].x; qb[1].y = boxB[fb[1]].y; qb[1].z = boxB[fb[1]].z;
            qb[2].x = boxB[fb[2]].x; qb[2].y = boxB[fb[2]].y; qb[2].z = boxB[fb[2]].z;
            qb[3].x = boxB[fb[3]].x; qb[3].y = boxB[fb[3]].y; qb[3].z = boxB[fb[3]].z;
            if (TObjPlayer__sub_803DFB1C(qa, qb) != 0) {
                return 1;
            }
            mask |= __SITransfer(qa, qb);
            if (mask == 7) {
                return 1;
            }
        }
    }
    return 0;
    }
    return 0;
}

#pragma pop
}
