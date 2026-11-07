


#include "types.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"






struct Vec_803E1B1C { f32 x, y, z; };


typedef struct TexObj_803E1D90 { u32 dummy[8]; } TexObj_803E1D90;

typedef struct TexHdr_803E1D90 {
    u32 f0;
    s32 format;
    u32 f8;
    u32 fC;
    u32 width;
    u32 height;
    u32 f18;
    u32 flags;
    void *image;
} TexHdr_803E1D90;

typedef struct TexInfo_803E1D90 { u32 f0; u32 f4; u32 tlut; TexHdr_803E1D90 *hdr; } TexInfo_803E1D90;

typedef struct TexEnt_803E1D90 { u32 f0; u32 f4; TexInfo_803E1D90 *info; } TexEnt_803E1D90;

typedef struct TexList_803E1D90 { TexEnt_803E1D90 *ents; } TexList_803E1D90;

typedef struct Ctx_803E1D90 { u8 pad[0x20]; TexList_803E1D90 *list; } Ctx_803E1D90;


struct V_803E18C0 { f32 x, y, z; };

struct Line_803E18C0 { V_803E18C0 o; V_803E18C0 d; };


struct Faces_803E0ED4 { s32 v[6][4]; };

extern "C" {
s32 GXLoadPosMtxImm(void *, int);
/* GX_PNMTX0..GX_PNMTX9 */
s32 gx_pos_mtx_index_table[10] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27};
extern s32 current_matrix;
extern const f32 lbl_805E1038;
extern const f32 lbl_805E103C;
/* GX_TEXMTX0..GX_TEXMTX9 */
s32 tex_matrix_id_table[10] = {30, 33, 36, 39, 42, 45, 48, 51, 54, 57};
void GXLoadTexMtxImm(void *mtx, u32 id, s32 type);
void OSPanic(const char *, int, const char *, ...);
extern char lbl_805D46F0[6]; /* "sorry"; .sdata not split into this unit yet */
void calc_bounds_min_max__10TObjPlayerFPvPvPv(struct Vec_803E1B1C *pts, struct Vec_803E1B1C *mn, struct Vec_803E1B1C *mx);
void Dolphin_GXInitTexObj(TexObj_803E1D90 *, void *, u16, u16, s32, s32, s32, u8);
void GXInitTexObjCI(TexObj_803E1D90 *, void *, u16, u16, s32, s32, s32, u8, u32);
void GXLoadTexObj(TexObj_803E1D90 *, s32);
/* GX_TEXMAP0..GX_TEXMAP7, GX_TEXMAP_NULL */
s32 list_texture_map_table[10] = {0, 1, 2, 3, 4, 5, 6, 7, 0xFF};
extern TexObj_803E1D90 list_texture_tex_obj;
extern Ctx_803E1D90 *current_render_context;
extern const f32 lbl_805E1020;
extern const f32 lbl_805E1024;
extern const f64 lbl_805E1028;
extern const f64 lbl_805E1030;
f32 project_point_onto_line(V_803E18C0 *p, Line_803E18C0 *l, V_803E18C0 *out);
s32 TObjPlayer__sub_803DFB1C(Vec_803E1B1C *a, Vec_803E1B1C *b);
s32 __SITransfer(Vec_803E1B1C *a, Vec_803E1B1C *b);
extern const Faces_803E0ED4 box_face_corner_index_table;
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



struct CollisionSphere { Vec_803E1B1C center; f32 radius; };
struct EdgeOrder_803E112C { s32 v[5]; };
extern const Faces_803E0ED4 box_face_vertex_index_table, box_edge_adjacent_face_table;
extern const EdgeOrder_803E112C lbl_8047E558;
extern const f32 lbl_805E1000, lbl_805E1018, lbl_805E101C;
extern const f64 lbl_805E1008, lbl_805E1010;

#pragma use_lmw_stmw off
struct Point2_803E0CC8 { f32 u, v; };
s32 TObjPlayer__sub_803DF9D0(Point2_803E0CC8 *a, Point2_803E0CC8 *b);
extern const f32 lbl_805E0FD8, lbl_805E0FDC, lbl_805E0FE0, lbl_805E0FF8, lbl_805E0FFC;
extern const f64 lbl_805E0FE8, lbl_805E0FF0;

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
    if ((f32)fabs(a->u - b->u) < lbl_805E0FD8) {
        nx = lbl_805E0FDC;
        ny = lbl_805E0FE0;
        off = -a->u;
    } else {
        nx = b->v - a->v;
        ny = -(b->u - a->u);
        off = -a->u * nx - a->v * ny;
    }
    cross = fabs(off + (nx * c->u + ny * c->v));
    len = nx * nx + ny * ny;
    if (len > lbl_805E0FE0) {
        volatile f32 y;
        f64 g = __frsqrte(len);
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - len * (g * g));
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - len * (g * g));
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - len * (g * g));
        y = (f32)(len * g);
        len = y;
    }
    height = cross / len;
    base = (a->u - b->u) * (a->u - b->u) + (a->v - b->v) * (a->v - b->v);
    if (base > lbl_805E0FE0) {
        volatile f32 y;
        f64 g = __frsqrte(base);
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - base * (g * g));
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - base * (g * g));
        g = lbl_805E0FE8 * g * (lbl_805E0FF0 - base * (g * g));
        y = (f32)(base * g);
        r = y;
    } else {
        r = base;
    }
    return lbl_805E0FF8 * (height * r);
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
    for (i = 0, p = inner, limit = lbl_805E0FFC * limit; i < 4; p++, i++) {
        if (TObjPlayer__sub_803DF840(p, outer, outer + 1) + TObjPlayer__sub_803DF840(p, outer + 1, outer + 2) +
                TObjPlayer__sub_803DF840(p, outer + 2, outer + 3) + TObjPlayer__sub_803DF840(p, outer + 3, outer) <
            limit) {
            return 1;
        }
    }
    return 0;
}

// 0.025f (lbl_805E0FD8) is the coordinate and slope tolerance; written as a literal below.
extern const f32 lbl_805E0FE0;
extern const f64 lbl_805E0FE8;
extern const f64 lbl_805E0FF0;

static inline f32 sqrtf_803DFB1C(f32 x) {
    volatile f32 y;
    if (x > lbl_805E0FE0) {
        f64 guess = __frsqrte(x);
        guess = lbl_805E0FE8 * guess * (lbl_805E0FF0 - guess * guess * x);
        guess = lbl_805E0FE8 * guess * (lbl_805E0FF0 - guess * guess * x);
        guess = lbl_805E0FE8 * guess * (lbl_805E0FF0 - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

/* Two quads touch: in each of the XY, XZ and YZ projections an edge of one
   crosses an edge of the other, or one projection lies inside the other. */
s32 TObjPlayer__sub_803DFB1C(Vec_803E1B1C *a, Vec_803E1B1C *b) {
    Point2_803E0CC8 pb[4];
    Point2_803E0CC8 pa[4];
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
        f32 slopeA;
        f32 interA;
        f32 lineAu;
        f32 prevBu;
        f32 prevBv;
        f32 curBu;
        f32 curBv;
        f32 slopeB;
        f32 interB;
        f32 lineBu;
        f32 hitU;
        f32 hitV;
        f32 toPrev;
        f32 toCur;
        f32 length;

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
                    length = sqrtf_803DFB1C((prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv));
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
        f32 prevAu;
        f32 prevAv;
        f32 curAu;
        f32 curAv;
        f32 slopeA;
        f32 interA;
        f32 lineAu;
        f32 prevBu;
        f32 prevBv;
        f32 curBu;
        f32 curBv;
        f32 slopeB;
        f32 interB;
        f32 lineBu;
        f32 hitU;
        f32 hitV;
        f32 toPrev;
        f32 toCur;
        f32 length;

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
                    length = sqrtf_803DFB1C((prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv));
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
        f32 prevAu;
        f32 prevAv;
        f32 curAu;
        f32 curAv;
        f32 slopeA;
        f32 interA;
        f32 lineAu;
        f32 prevBu;
        f32 prevBv;
        f32 curBu;
        f32 curBv;
        f32 slopeB;
        f32 interB;
        f32 lineBu;
        f32 hitU;
        f32 hitV;
        f32 toPrev;
        f32 toCur;
        f32 length;

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
                    length = sqrtf_803DFB1C((prevAu - curAu) * (prevAu - curAu) + (prevAv - curAv) * (prevAv - curAv));
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

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
static inline f32 collisionRoot(f32 x) {
    volatile f32 y;
    if (x > lbl_805E1000) {
        f64 guess = __frsqrte(x);
        guess = lbl_805E1008 * guess * (lbl_805E1010 - guess * guess * x);
        guess = lbl_805E1008 * guess * (lbl_805E1010 - guess * guess * x);
        guess = lbl_805E1008 * guess * (lbl_805E1010 - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

s32 test_box_sphere_contact(Vec_803E1B1C *box, CollisionSphere *sphere) {
    Vec_803E1B1C boxMin;
    Vec_803E1B1C boxMax;
    Vec_803E1B1C sphereMin;
    Vec_803E1B1C sphereMax;
    calc_bounds_min_max__10TObjPlayerFPvPvPv(box, &boxMin, &boxMax);
    ((TObjPlayer *)sphere)->calc_bounds((u8 *)&sphereMin, (u8 *)&sphereMax);
    if (((TObjPlayer *)&boxMin)->test_aabb_overlap((u8 *)&boxMax, (u8 *)&sphereMin, (u8 *)&sphereMax) != 0) {
        Faces_803E0ED4 faces = box_face_vertex_index_table;
        Vec_803E1B1C normals[6];
        Faces_803E0ED4 adjacent = box_edge_adjacent_face_table;
        s32 i;
        s32 j;
        s32 inside = 1;
        for (i = 0; i < 6; i++) {
            Vec_803E1B1C *n = &normals[i];
            f32 scale;
            n->x = -((box[faces.v[i][1]].y - box[faces.v[i][0]].y) * (box[faces.v[i][2]].z - box[faces.v[i][0]].z) - (box[faces.v[i][1]].z - box[faces.v[i][0]].z) * (box[faces.v[i][2]].y - box[faces.v[i][0]].y));
            n->y = -((box[faces.v[i][1]].z - box[faces.v[i][0]].z) * (box[faces.v[i][2]].x - box[faces.v[i][0]].x) - (box[faces.v[i][1]].x - box[faces.v[i][0]].x) * (box[faces.v[i][2]].z - box[faces.v[i][0]].z));
            n->z = -((box[faces.v[i][1]].x - box[faces.v[i][0]].x) * (box[faces.v[i][2]].y - box[faces.v[i][0]].y) - (box[faces.v[i][1]].y - box[faces.v[i][0]].y) * (box[faces.v[i][2]].x - box[faces.v[i][0]].x));
            scale = lbl_805E1018 / collisionRoot(n->z * n->z + (n->x * n->x + n->y * n->y));
            n->x *= scale;
            n->y *= scale;
            n->z *= scale;
        }
        for (i = 0; i < 6; i++) {
            EdgeOrder_803E112C order = lbl_8047E558;
            s32 faceHit = 1;
            Vec_803E1B1C *n = &normals[i];
            s32 *face = faces.v[i];
            Vec_803E1B1C *center = &sphere->center;
            f32 d = -(n->z * box[face[0]].z + (n->x * box[face[0]].x + n->y * box[face[0]].y));
            f32 t = -(d + (center->z * n->z + (center->x * n->x + center->y * n->y))) /
                    (n->z * n->z + (n->x * n->x + n->y * n->y));
            f32 px = center->x + t * n->x;
            f32 py = center->y + t * n->y;
            f32 pz = center->z + t * n->z;
            f32 dist = collisionRoot((pz - center->z) * (pz - center->z) +
                                     ((px - center->x) * (px - center->x) + (py - center->y) * (py - center->y)));
            for (j = 0; j < 4; j++) {
                s32 k = order.v[j];
                Vec_803E1B1C *a = &box[face[k]];
                Vec_803E1B1C *b = &box[face[order.v[j + 1]]];
                f32 ex = a->x - b->x;
                f32 ey = a->y - b->y;
                f32 ez = a->z - b->z;
                f32 s = (ez * (pz - a->z) + (ex * (px - a->x) + ey * (py - a->y))) / (ez * ez + (ex * ex + ey * ey));
                f32 fx = ex * s + a->x;
                f32 fy = ey * s + a->y;
                f32 fz = ez * s + a->z;
                f32 dx = fx - px;
                f32 dy = fy - py;
                f32 dz = fz - pz;
                f32 scale = lbl_805E1018 / collisionRoot(dz * dz + (dx * dx + dy * dy));
                dx *= scale;
                dy *= scale;
                dz *= scale;
                if ((f32)__fabs(normals[adjacent.v[i][k]].x - dx) <= lbl_805E101C &&
                    (f32)__fabs(normals[adjacent.v[i][k]].y - dy) <= lbl_805E101C &&
                    (f32)__fabs(normals[adjacent.v[i][k]].z - dz) <= lbl_805E101C &&
                    sphere->radius >= dist) {
                    faceHit &= 1;
                } else if (dist <= sphere->radius) {
                    if ((pz - fz) * (pz - fz) + ((px - fx) * (px - fx) + (py - fy) * (py - fy)) <=
                    sphere->radius * sphere->radius - dist * dist) {
                        faceHit &= 1;
                    } else {
                        faceHit = 0;
                    }
                } else {
                    faceHit = 0;
                }
            }
            if (faceHit != 0) {
                return 1;
            }
            f32 dx = px - sphere->center.x;
            f32 dy = py - sphere->center.y;
            f32 dz = pz - sphere->center.z;
            f32 scale = lbl_805E1018 / collisionRoot(dz * dz + (dx * dx + dy * dy));
            dx *= scale;
            dy *= scale;
            dz *= scale;
            if ((f32)__fabs(n->x - dx) <= lbl_805E101C && (f32)__fabs(n->y - dy) <= lbl_805E101C &&
                      (f32)__fabs(n->z - dz) <= lbl_805E101C) inside &= 1; else inside = 0;
        }
        if (inside != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma pop


__declspec(section ".sdata2") extern const f64 lbl_805E1040;
__declspec(section ".sdata2") extern const f64 lbl_805E1048;
}

s32 spheres_overlap(u8 *arg0, u8 *arg1) {
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    temp_f3 = *(f32 *)((s8 *)arg1 + 0) - *(f32 *)((s8 *)arg0 + 0);
    temp_f4 = *(f32 *)((s8 *)arg1 + 4) - *(f32 *)((s8 *)arg0 + 4);
    temp_f2 = *(f32 *)((s8 *)arg1 + 8) - *(f32 *)((s8 *)arg0 + 8);
    temp_f5 = *(f32 *)((s8 *)arg0 + 0xC) + *(f32 *)((s8 *)arg1 + 0xC);
    return ((temp_f2 * temp_f2) + ((temp_f3 * temp_f3) + (temp_f4 * temp_f4))) <= (temp_f5 * temp_f5);
}


#pragma push
#pragma scheduling off

f32 project_point_onto_line(V_803E18C0 *p, Line_803E18C0 *l, V_803E18C0 *out) {
    f32 t;
    f32 x;
    f32 r;
    t = (l->d.z * (p->z - l->o.z) + (l->d.x * (p->x - l->o.x) + l->d.y * (p->y - l->o.y))) /
        (l->d.z * l->d.z + (l->d.x * l->d.x + l->d.y * l->d.y));
    if (out != NULL) {
        out->x = l->o.x + l->d.x * t;
        out->y = l->o.y + l->d.y * t;
        out->z = l->o.z + l->d.z * t;
        x = (p->z - out->z) * (p->z - out->z) + ((p->x - out->x) * (p->x - out->x) + (p->y - out->y) * (p->y - out->y));
    } else {
        x = (p->z - (l->o.z + l->d.z * t)) * (p->z - (l->o.z + l->d.z * t)) +
            ((p->x - (l->o.x + l->d.x * t)) * (p->x - (l->o.x + l->d.x * t)) +
             (p->y - (l->o.y + l->d.y * t)) * (p->y - (l->o.y + l->d.y * t)));
    }
    if (x < lbl_805E1020) {
        return lbl_805E1024;
    }
    if (x > lbl_805E1024) {
        volatile f32 y;
        f64 g = __frsqrte(x);
        g = lbl_805E1028 * g * (lbl_805E1030 - g * g * x);
        g = lbl_805E1028 * g * (lbl_805E1030 - g * g * x);
        g = lbl_805E1028 * g * (lbl_805E1030 - g * g * x);
        y = (f32)(x * g);
        r = y;
    } else {
        r = x;
    }
    return r;
}
#pragma pop

#pragma push
#pragma scheduling off
f32 xyz_distance(Vec *a, Vec *b) {
    f32 x = (a->z - b->z) * (a->z - b->z) + ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
    f32 r;
    if (x < lbl_805E1038) {
        return lbl_805E103C;
    }
    if (x > lbl_805E103C) {
        volatile f32 y;
        f64 g = __frsqrte(x);
        g = lbl_805E1040 * g * (lbl_805E1048 - g * g * x);
        g = lbl_805E1040 * g * (lbl_805E1048 - g * g * x);
        g = lbl_805E1040 * g * (lbl_805E1048 - g * g * x);
        y = (f32)(x * g);
        r = y;
    } else {
        r = x;
    }
    return r;
}
#pragma pop


void calc_bounds_min_max__10TObjPlayerFPvPvPv(struct Vec_803E1B1C *pts, struct Vec_803E1B1C *mn, struct Vec_803E1B1C *mx) {
    s32 i;
    mn->x = pts->x;
    mn->y = pts->y;
    mn->z = pts->z;
    mx->x = pts->x;
    mx->y = pts->y;
    mx->z = pts->z;
    pts++;
    for (i = 1; i < 8; i++, pts++) {
        if (pts->x < mn->x) mn->x = pts->x;
        if (pts->y < mn->y) mn->y = pts->y;
        if (pts->z < mn->z) mn->z = pts->z;
        if (pts->x > mx->x) mx->x = pts->x;
        if (pts->y > mx->y) mx->y = pts->y;
        if (pts->z > mx->z) mx->z = pts->z;
    }
}

void TObjPlayer::calc_bounds(u8 *arg1, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 0) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg1 + 4) = (f32) (*(f32 *)((s8 *)arg0 + 4) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 0) + *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 4) = (f32) (*(f32 *)((s8 *)arg0 + 4) + *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + *(f32 *)((s8 *)arg0 + 0xC));
}


// 1.0f constants in .sdata, read by the assembly below (not yet split into this unit).
extern "C" f32 lbl_805D46EC;
extern "C" f32 lbl_805D46FC;

asm void translate_current_matrix_ps(f32 x, f32 y, f32 z) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/translate_current_matrix_ps.inc"
}

asm f32 TObjPlayer__sub_803E1CA4(s32 angle) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/TObjPlayer__sub_803E1CA4.inc"
}

asm void rotate_current_matrix_x_ps(s32 angle) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/rotate_current_matrix_x_ps.inc"
}

extern s8 scene_fog_enable_flag;


#pragma push
#pragma scheduling off
void load_current_pos_matrix(s32 arg0) {
    GXLoadPosMtxImm((void *)current_matrix, gx_pos_mtx_index_table[arg0]);
}
#pragma pop


#pragma push
#pragma scheduling off
void load_current_tex_matrix(s32 i) {
    GXLoadTexMtxImm((void *)current_matrix, tex_matrix_id_table[i], 0);
}
#pragma pop


void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map) {
    TexInfo_803E1D90 *info = current_render_context->list->ents[idx].info;
    TexHdr_803E1D90 *hdr = info->hdr;
    u32 flags = hdr->flags;
    u8 mip;
    if (flags & 0x80000000) {
        mip = 1;
    } else {
        mip = 0;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&list_texture_tex_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip, info->tlut);
    } else {
        Dolphin_GXInitTexObj(&list_texture_tex_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip);
    }
    GXLoadTexObj(&list_texture_tex_obj, list_texture_map_table[map]);
}


asm void reorder_current_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/reorder_current_matrix_ps.inc"
}

asm void push_reordered_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/push_reordered_matrix_ps.inc"
}

void TObjPlayer::reload_texture(s32 arg1, u32 arg2, void *arg3) {
    s32 size;
    if ((arg2 & 0x40000000) != 0) {
        size = arg1;
    } else {
        OSPanic("nuReLoadTexture.c", 48, lbl_805D46F0); /* __FILE__ in the original */
    }
    TObjPlayer__sub_803DAE1C((s32)this, size, (u32)arg3);
}

asm void TObjPlayer__sub_803E1F60(void) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/TObjPlayer__sub_803E1F60.inc"
}

asm void push_identity_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803DF7A8/push_identity_matrix_ps.inc"
}

void TObjPlayer::set_effect_active() {
    scene_fog_enable_flag = 1;
}


void TObjPlayer::reset_particle_counter() {
    scene_fog_enable_flag = 0;
}

TexObj_803E1D90 list_texture_tex_obj;
