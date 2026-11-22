#include "types.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include <dolphin/mtx/GeoTypes.h>
#include <math.h>

extern "C" {
s32 quads_touch(Vec *a, Vec *b);
s32 quad_projection_overlap_mask(Vec *a, Vec *b);
extern const BoxFaces box_face_corner_index_table;
const BoxFaces box_face_corner_index_table = {
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}}};
s32 test_aabb_overlap(Vec *minA, Vec *maxA, Vec *minB, Vec *maxB) {
    if (maxA->x < minB->x) {
        return 0;
    }
    if (minA->x > maxB->x) {
        return 0;
    }
    if (maxA->y < minB->y) {
        return 0;
    }
    if (minA->y > maxB->y) {
        return 0;
    }
    if (maxA->z < minB->z) {
        return 0;
    }
    return (u32) __cntlzw(minA->z > maxB->z) >> 5;
}

#pragma push
#pragma fp_contract off
#pragma use_lmw_stmw off
// A quad corner projected onto the XY, XZ or YZ plane.
struct ProjectedPoint { f32 u, v; };
s32 quad_corner_inside(ProjectedPoint *a, ProjectedPoint *b);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// The area of the triangle a, b, c: half of |a - b| times the distance of c from the line through a and b.
f32 triangle_area(ProjectedPoint *a, ProjectedPoint *b, ProjectedPoint *c) {
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

// 1 if a corner of the smaller quad lies inside the larger one: the four triangles it makes with the larger
// quad's edges add up to less than 1.025 times that quad's area.
s32 quad_corner_inside(ProjectedPoint *a, ProjectedPoint *b) {
    ProjectedPoint *p;
    ProjectedPoint *inner;
    ProjectedPoint *outer;
    f32 areaA;
    f32 areaB;
    f32 limit;
    s32 i;
    areaA = triangle_area(a, a + 1, a + 2) + triangle_area(a, a + 2, a + 3);
    areaB = triangle_area(b, b + 1, b + 2) + triangle_area(b, b + 2, b + 3);
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
        if (triangle_area(p, outer, outer + 1) + triangle_area(p, outer + 1, outer + 2) +
                triangle_area(p, outer + 2, outer + 3) + triangle_area(p, outer + 3, outer) <
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
#pragma push
#pragma opt_loop_invariants off
s32 quads_touch(Vec *a, Vec *b) {
    ProjectedPoint pa[4];
    ProjectedPoint pb[4];
    s32 hitXY;
    s32 hitXZ;
    s32 hitYZ;
    s32 inXY;
    s32 inXZ;
    s32 inYZ;
    s32 i;
    s32 j;
    s32 result;
    f32 lengthSqAYZ;
    f32 prevAvXZ;
    f32 prevAuYZ;
    f32 prevBuXY;
    f32 prevBvXY;
    f32 prevBvXZ;
    f32 curAvXZ;
    f32 prevAuXZ;
    f32 curBuXY;
    f32 curBvXY;
    f32 curBvXZ;
    f32 lengthSqAXY;
    f32 lengthSqAXZ;
    f32 hitUXY;
    f32 interAXY;
    f32 prevAvYZ;
    f32 prevBuXZ;
    f32 slopeAXZ;
    f32 slopeAXY;
    f32 curAuYZ;
    f32 curBuXZ;
    f32 curAuXZ;

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
                slopeAXY = (curAv - prevAv) / (curAu - prevAu);
                interAXY = prevAv - slopeAXY * prevAu;
                vertA = 0;
            } else {
                lineAu = prevAu;
                vertA = 1;
            }
            prevBuXY = b[3].x;
            prevBvXY = b[3].y;
            for (j = 0; j < 4; j++) {
                parallel = 0;
                lengthSqAXY = (prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv);
                curBuXY = b[j].x;
                curBvXY = b[j].y;
                if (prevBuXY < curBuXY - 0.025f || prevBuXY > 0.025f + curBuXY) {
                    slopeB = (curBvXY - prevBvXY) / (curBuXY - prevBuXY);
                    interB = prevBvXY - slopeB * prevBuXY;
                    vertB = 0;
                } else {
                    lineBu = prevBuXY;
                    vertB = 1;
                }
                if (vertA == 0 && vertB == 0) {
                    if (slopeAXY < slopeB - 0.025f || slopeAXY > 0.025f + slopeB) {
                        hitUXY = (interB - interAXY) / (slopeAXY - slopeB);
                        hitV = interAXY + slopeAXY * hitUXY;
                    } else {
                        parallel = 1;
                    }
                } else if (vertB == 0) {
                    hitUXY = lineAu;
                    hitV = interB + slopeB * hitUXY;
                } else if (vertA == 0) {
                    hitUXY = lineBu;
                    hitV = interAXY + slopeAXY * hitUXY;
                } else {
                    parallel = 1;
                }
                if (parallel == 0) {
                    onA = 0;
                    onB = 0;
                    toPrev = sqrtf_803DFB1C((prevAu - hitUXY) * (prevAu - hitUXY) + (prevAv - hitV) * (prevAv - hitV));
                    toCur = sqrtf_803DFB1C((curAu - hitUXY) * (curAu - hitUXY) + (curAv - hitV) * (curAv - hitV));
                    length = sqrtf_803DFB1C(lengthSqAXY);
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onA = 1;
                    }
                    toPrev = sqrtf_803DFB1C((prevBuXY - hitUXY) * (prevBuXY - hitUXY) + (prevBvXY - hitV) * (prevBvXY - hitV));
                    toCur = sqrtf_803DFB1C((curBuXY - hitUXY) * (curBuXY - hitUXY) + (curBvXY - hitV) * (curBvXY - hitV));
                    length = sqrtf_803DFB1C((prevBuXY - curBuXY) * (prevBuXY - curBuXY) + (prevBvXY - curBvXY) * (prevBvXY - curBvXY));
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onB = 1;
                    }
                    if (onA != 0 && onB != 0) {
                        hitXY = 1;
                        break;
                    }
                }
                prevBuXY = curBuXY;
                prevBvXY = curBvXY;
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
        f32 lineAu;
        f32 toPrev;
        f32 toCur;
        f32 length;
        f32 interA;
        f32 hitU;
        f32 hitV;
        f32 slopeB;
        f32 interB;
        f32 lineBu;

        prevAuXZ = a[3].x;
        prevAvXZ = a[3].z;
        for (i = 0; i < 4; i++) {
            curAuXZ = a[i].x;
            curAvXZ = a[i].z;
            if (prevAuXZ < curAuXZ - 0.025f || prevAuXZ > 0.025f + curAuXZ) {
                slopeAXZ = (curAvXZ - prevAvXZ) / (curAuXZ - prevAuXZ);
                interA = prevAvXZ - slopeAXZ * prevAuXZ;
                vertA = 0;
            } else {
                lineAu = prevAuXZ;
                vertA = 1;
            }
            prevBuXZ = b[3].x;
            prevBvXZ = b[3].z;
            for (j = 0; j < 4; j++) {
                parallel = 0;
                lengthSqAXZ = (prevAuXZ - curAuXZ) * (prevAuXZ - curAuXZ) + (prevAvXZ - curAvXZ) * (prevAvXZ - curAvXZ);
                curBuXZ = b[j].x;
                curBvXZ = b[j].z;
                if (prevBuXZ < curBuXZ - 0.025f || prevBuXZ > 0.025f + curBuXZ) {
                    slopeB = (curBvXZ - prevBvXZ) / (curBuXZ - prevBuXZ);
                    interB = prevBvXZ - slopeB * prevBuXZ;
                    vertB = 0;
                } else {
                    lineBu = prevBuXZ;
                    vertB = 1;
                }
                if (vertA == 0 && vertB == 0) {
                    if (slopeAXZ < slopeB - 0.025f || slopeAXZ > 0.025f + slopeB) {
                        hitU = (interB - interA) / (slopeAXZ - slopeB);
                        hitV = interA + slopeAXZ * hitU;
                    } else {
                        parallel = 1;
                    }
                } else if (vertB == 0) {
                    hitU = lineAu;
                    hitV = interB + slopeB * hitU;
                } else if (vertA == 0) {
                    hitU = lineBu;
                    hitV = interA + slopeAXZ * hitU;
                } else {
                    parallel = 1;
                }
                if (parallel == 0) {
                    onA = 0;
                    onB = 0;
                    toPrev = sqrtf_803DFB1C((prevAuXZ - hitU) * (prevAuXZ - hitU) + (prevAvXZ - hitV) * (prevAvXZ - hitV));
                    toCur = sqrtf_803DFB1C((curAuXZ - hitU) * (curAuXZ - hitU) + (curAvXZ - hitV) * (curAvXZ - hitV));
                    length = sqrtf_803DFB1C(lengthSqAXZ);
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onA = 1;
                    }
                    toPrev = sqrtf_803DFB1C((prevBuXZ - hitU) * (prevBuXZ - hitU) + (prevBvXZ - hitV) * (prevBvXZ - hitV));
                    toCur = sqrtf_803DFB1C((curBuXZ - hitU) * (curBuXZ - hitU) + (curBvXZ - hitV) * (curBvXZ - hitV));
                    length = sqrtf_803DFB1C((prevBuXZ - curBuXZ) * (prevBuXZ - curBuXZ) + (prevBvXZ - curBvXZ) * (prevBvXZ - curBvXZ));
                    if (0.025f + length >= toPrev + toCur - 0.025f) {
                        onB = 1;
                    }
                    if (onA != 0 && onB != 0) {
                        hitXZ = 1;
                        break;
                    }
                }
                prevBuXZ = curBuXZ;
                prevBvXZ = curBvXZ;
            }
            if (hitXZ != 0) {
                break;
            }
            prevAuXZ = curAuXZ;
            prevAvXZ = curAvXZ;
        }
    }
    {
        s32 vertA;
        s32 vertB;
        s32 parallel;
        s32 onA;
        s32 onB;
        f32 lineAu;
        f32 toPrev;
        f32 toCur;
        f32 length;
        f32 curAv;
        f32 prevBu;
        f32 slopeA;
        f32 prevBv;
        f32 interA;
        f32 hitU;
        f32 hitV;
        f32 curBu;
        f32 curBv;
        f32 slopeB;
        f32 interB;
        f32 lineBu;

        prevAuYZ = a[3].y;
        prevAvYZ = a[3].z;
        for (i = 0; i < 4; i++) {
            curAuYZ = a[i].y;
            curAv = a[i].z;
            if (prevAuYZ < curAuYZ - 0.025f || prevAuYZ > 0.025f + curAuYZ) {
                slopeA = (curAv - prevAvYZ) / (curAuYZ - prevAuYZ);
                interA = prevAvYZ - slopeA * prevAuYZ;
                vertA = 0;
            } else {
                lineAu = prevAuYZ;
                vertA = 1;
            }
            prevBu = b[3].y;
            prevBv = b[3].z;
            for (j = 0; j < 4; j++) {
                parallel = 0;
                lengthSqAYZ = (prevAuYZ - curAuYZ) * (prevAuYZ - curAuYZ) + (prevAvYZ - curAv) * (prevAvYZ - curAv);
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
                    toPrev = sqrtf_803DFB1C((prevAuYZ - hitU) * (prevAuYZ - hitU) + (prevAvYZ - hitV) * (prevAvYZ - hitV));
                    toCur = sqrtf_803DFB1C((curAuYZ - hitU) * (curAuYZ - hitU) + (curAv - hitV) * (curAv - hitV));
                    length = sqrtf_803DFB1C(lengthSqAYZ);
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
            prevAuYZ = curAuYZ;
            prevAvYZ = curAv;
        }
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].y;
        pb[i].u = b[i].x;
        pb[i].v = b[i].y;
    }
    inXY = quad_corner_inside(pa, pb);
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].z;
        pb[i].u = b[i].x;
        pb[i].v = b[i].z;
    }
    inXZ = quad_corner_inside(pa, pb);
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].y;
        pa[i].v = a[i].z;
        pb[i].u = b[i].y;
        pb[i].v = b[i].z;
    }
    inYZ = quad_corner_inside(pa, pb);
    result = 0;
    if ((hitXY != 0 || inXY != 0) && (hitXZ != 0 || inXZ != 0) && (hitYZ != 0 || inYZ != 0)) {
        result = 1;
    }
    return result;
}
#pragma pop
#pragma pop

// The planes in which a corner of one quad lies inside the other: 4 = XY, 2 = XZ, 1 = YZ.
s32 quad_projection_overlap_mask(Vec *a, Vec *b) {
    ProjectedPoint pa[4];
    ProjectedPoint pb[4];
    s32 mask = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].y;
        pb[i].u = b[i].x;
        pb[i].v = b[i].y;
    }
    if (quad_corner_inside(pa, pb) != 0) {
        mask |= 4;
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].x;
        pa[i].v = a[i].z;
        pb[i].u = b[i].x;
        pb[i].v = b[i].z;
    }
    if (quad_corner_inside(pa, pb) != 0) {
        mask |= 2;
    }
    for (i = 0; i < 4; i++) {
        pa[i].u = a[i].y;
        pa[i].v = a[i].z;
        pb[i].u = b[i].y;
        pb[i].v = b[i].z;
    }
    if (quad_corner_inside(pa, pb) != 0) {
        mask |= 1;
    }
    return mask;
}

s32 test_box_overlap(Vec *cornersA, Vec *cornersB) {
    Vec faceA[4];
    Vec faceB[4];
    Vec minA;
    Vec maxA;
    Vec minB;
    Vec maxB;
    s32 i;
    s32 j;
    s32 mask;
    s32 *indexA;
    s32 *indexB;
    int k;
    mask = 0;
    calc_box_bounds(cornersA, &minA, &maxA);
    calc_box_bounds(cornersB, &minB, &maxB);
    if (test_aabb_overlap(&minA, &maxA, &minB, &maxB) != 0) {
    BoxFaces faces = box_face_corner_index_table;
    for (i = 0; i < 6; i++) {
        indexA = faces.v[i];
        faceA[0].x = cornersA[indexA[0]].x; faceA[0].y = cornersA[indexA[0]].y; faceA[0].z = cornersA[indexA[0]].z;
        faceA[1].x = cornersA[indexA[1]].x; faceA[1].y = cornersA[indexA[1]].y; faceA[1].z = cornersA[indexA[1]].z;
        faceA[2].x = cornersA[indexA[2]].x; faceA[2].y = cornersA[indexA[2]].y; faceA[2].z = cornersA[indexA[2]].z;
        faceA[3].x = cornersA[indexA[3]].x; faceA[3].y = cornersA[indexA[3]].y; faceA[3].z = cornersA[indexA[3]].z;
        for (j = 0; j < 6; j++) {
            indexB = faces.v[j];
            faceB[0].x = cornersB[indexB[0]].x; faceB[0].y = cornersB[indexB[0]].y; faceB[0].z = cornersB[indexB[0]].z;
            faceB[1].x = cornersB[indexB[1]].x; faceB[1].y = cornersB[indexB[1]].y; faceB[1].z = cornersB[indexB[1]].z;
            faceB[2].x = cornersB[indexB[2]].x; faceB[2].y = cornersB[indexB[2]].y; faceB[2].z = cornersB[indexB[2]].z;
            faceB[3].x = cornersB[indexB[3]].x; faceB[3].y = cornersB[indexB[3]].y; faceB[3].z = cornersB[indexB[3]].z;
            if (quads_touch(faceA, faceB) != 0) {
                return 1;
            }
            mask |= quad_projection_overlap_mask(faceA, faceB);
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
