#include "types.h"
#include "pso/render/ChunkVertexJob.h"
#include "pso/render/ChunkPolygonList.h"
#ifndef __MWERKS__
#include <math.h>
#endif
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/unk/text_803E2008.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/system/memory.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/player/TObjPlayer.h"

#pragma scheduling off

struct FloatColor { f32 a, r, g, b; };

struct ByteColor { u8 r, g, b, a; };

struct Mtx_803DC994 { f32 m[3][4]; };
struct ChunkNode_803E2F78 {
    u32 flags;
    s32 obj;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    ChunkNode_803E2F78 *child;
    ChunkNode_803E2F78 *sibling;
    f32 f34;
};

typedef union {
    u8 u8;
    u16 u16;
    s16 s16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

#ifdef __MWERKS__
volatile PPCWGPipe GXWGFifo : 0xCC008000;
#else
#define GXWGFifo (*(volatile PPCWGPipe *)0xCC008000)
#endif


typedef struct Vtx_803E36C4 { f32 x, y, z, nx, ny, nz; u32 pad[2]; } Vtx_803E36C4;

struct Sub_803E3B6C { u8 pad[0xC]; u8 *q; };

struct Rec_803E3B6C { u8 pad[8]; Sub_803E3B6C *p; };

struct Holder_803E3B6C { Rec_803E3B6C *recs; };

typedef f32 Mtx_803E4354[3][4];
extern "C" {
void GXSetNumTexGens(u8);
s32 GXSetTevOp(int, int);
s32 GXSetTevOrder(int, int, int, int);
s32 GXSetNumTevStages(int);
extern s32 model_render_flags;
extern u8 lbl_805D77D8;
extern u8 lbl_805D77D9;
s32 GXSetZMode(int, int, int);
s32 GXSetZCompLoc(int);
extern s32 ginja_draw_flags;
extern s32 (*player_chunk_draw_end_callback)();
extern s32 chunk_texture_record_index;
void GXSetChanMatColor(s32, ByteColor);
void convert_color_f32_to_u8(const FloatColor*,ByteColor*);
void convert_color_u8_to_f32(const ByteColor*,FloatColor*);
extern FloatColor model_material_color;
extern s32 model_render_flags,ginja_draw_flags;
extern u32 chunk_blend_header_bits;
extern u32 chunk_strip_dirty_flags;
void GXSetAlphaCompare(int comp0, int ref0, int op, int comp1, int ref1);
extern s32 chunk_vertex_cache_buffer;
extern s32 lbl_805D77FC;
extern s32 chunk_render_flags;
void transform_chunk_object_tree(void *, void (*)(void *));
extern s32 current_matrix;
s32 __cvt_fp2unsigned(f32);
void apply_quat_rotation__10TObjPlayerFf(f32 *arg0, f32 farg0);
void rotate_matrix_by_node_angles(void *, int);
void push_matrix(void);
void scale_current_matrix(void *);
void post_translate_matrix(void *);
extern u8 chunk_object_current_matrix[];
void transform_point_by_current_matrix(u8 *, u8 *);
void rotate_vector_by_current_matrix(u8 *, u8 *);
void GXBegin(int, int, u16);
void Dolphin_GXSetVtxDesc(int, int);
void GXClearVtxDesc(void);
void draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info);
void GXSetChanCtrl(s32 chan, u8 enable, s32 ambSrc, s32 matSrc, u32 lightMask, s32 diffFn, s32 attnFn);
extern u32 gx_chan_ctrl_light_mask;
extern u32 chunk_has_vertex_colors;
void draw_strip_pos_normal__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info);
void draw_triangle_strips__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info);
s32 GXSetBlendMode(int, int, int, int);
extern s32 material_alpha_compare_reference;
extern u8 *current_render_context;
void GXSetVtxAttrFmt(int, int, int, int, u8);
void draw_chunk_textured_strips(s16 *list, Vtx_803E36C4 *verts, u32 info, s32 large);
struct ChunkModel_803E44D4 { u32 *vertices; s16 *polygons; };
struct ChunkBuffer_803E44D4 { void *vertices; s32 bytes; };
struct ChunkRecording_803E44D4 { ChunkBuffer_803E44D4 buffers[32]; s32 index; };
void OSReport(const char*, ...);
void* memmove(void*, const void*, unsigned long);
}
char lbl_804FC810[19] = "CHNK MEMORY ASSERT";
extern u32 lbl_805D77E4;
extern ChunkRecording_803E44D4* chunk_vertex_cache_state;
extern "C" {
void PSMTXConcat(const Mtx_803E4354, const Mtx_803E4354, Mtx_803E4354);
void PSMTXTrans(Mtx_803E4354, f32, f32, f32);
void PSMTXScale(Mtx_803E4354, f32, f32, f32);
s32 GXSetNumChans(int);
s32 GXLoadPosMtxImm(void *, int);
s32 GXLoadNrmMtxImm(void *, int);
s32 GXLoadTexMtxImm(void *, int, int);
extern Mtx_803E4354 identity_matrix;
extern s32 chunk_previous_strip_flags;

#pragma push
#pragma peephole off
#pragma scheduling off
void TObjPlayer::copy_matrix3x3_for_chunk_tree() {
    struct Mtx_803DC994 *src = (struct Mtx_803DC994 *)this;
    struct Mtx_803DC994 *dst = (struct Mtx_803DC994 *)current_matrix;
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[0][1];
    dst->m[0][2] = src->m[0][2];
    dst->m[1][0] = src->m[1][0];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[1][2];
    dst->m[2][0] = src->m[2][0];
    dst->m[2][1] = src->m[2][1];
    dst->m[2][2] = src->m[2][2];
}
#pragma pop

#define node ((ChunkNode_803E2F78 *)arg0)
void transform_chunk_object_tree(void *arg0, void (*cb)(void *)) {
    u32 flags;
    s32 r;

    do {
        flags = node->flags;
        r = 0;
        if (flags & 0x800) {
            get_current_matrix(chunk_object_current_matrix);
        }
        if ((flags & 7) == 7) {
            if (!(flags & 8)) {
                r = ((s32 (*)(s32))cb)(node->obj);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, cb);
            }
        } else {
            push_matrix();
            if (!(flags & 1)) {
                post_translate_matrix(node->pos);
            }
            if (!(flags & 2)) {
                if (flags & 0x1000) {
                    ((TObjPlayer *)chunk_object_current_matrix)->copy_matrix3x3_for_chunk_tree();
                } else if (flags & 0x400) {
                    ((void (*)(f32, f32 *))apply_quat_rotation__10TObjPlayerFf)(node->f34, (f32 *)node->ang);
                } else {
                    rotate_matrix_by_node_angles(node->ang, flags & 0x20);
                }
            }
            if (!(flags & 4)) {
                scale_current_matrix(node->scl);
            }
            if (!(flags & 8)) {
                r = ((s32 (*)(s32))cb)(node->obj);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, cb);
            }
            pop_matrix();
        }
        arg0 = node->sibling;
    } while (arg0 != NULL);
}
#undef node

extern "C" {
// The store loop at 0x803E1E84 writes the current 3x4 as these pairs.
// reorder_current_matrix_ps (0x803E1E74) falls into it; push_reordered_matrix_ps
// (0x803E1ED0) advances the matrix slot by 0x30 and branches to it.
// Position uses the translation column; the normal uses only the 3x3.
struct ReorderedMatrix_803E3390 {
    f32 m00, m10;
    f32 m20, m01;
    f32 m11, m21;
    f32 m02, m12;
    f32 m22, m03;
    f32 m13, m23;
};
struct VtxIn_803E3390 {
    f32 x, y, z;
    f32 nx, ny, nz;
};
struct VtxOut_803E3390 {
    f32 x, y, z;
    f32 nx, ny, nz;
    f32 pad[2];
};
typedef char ReorderedMatrix_803E3390_size[sizeof(ReorderedMatrix_803E3390) == 0x30 ? 1 : -1];
typedef char VtxIn_803E3390_size[sizeof(VtxIn_803E3390) == 0x18 ? 1 : -1];
typedef char VtxOut_803E3390_size[sizeof(VtxOut_803E3390) == 0x20 ? 1 : -1];

// This chunk command transforms indexed positions and normals with signed 8.8 weights.
#ifdef __MWERKS__
asm void GXSetVtxAttrFmtv(ChunkVertexJob *job, ReorderedMatrix_803E3390 *matrix, u32 accumulate) {
#include "orig_asm/pso/unk/text_803E2F28/GXSetVtxAttrFmtv.inc"
}
#else
static void transform_chunk_vertex(const VtxIn_803E3390 *src, const ReorderedMatrix_803E3390 *matrix, VtxOut_803E3390 *dst) {
    f32 x = src->x, y = src->y, z = src->z;
    f32 nx = src->nx, ny = src->ny, nz = src->nz;
    dst->x = fmaf(matrix->m02, z, fmaf(matrix->m01, y, fmaf(matrix->m00, x, matrix->m03)));
    dst->y = fmaf(matrix->m12, z, fmaf(matrix->m11, y, fmaf(matrix->m10, x, matrix->m13)));
    dst->z = fmaf(matrix->m22, z, fmaf(matrix->m21, y, fmaf(matrix->m20, x, matrix->m23)));
    dst->nx = fmaf(matrix->m02, nz, fmaf(matrix->m01, ny, matrix->m00 * nx));
    dst->ny = fmaf(matrix->m12, nz, fmaf(matrix->m11, ny, matrix->m10 * nx));
    dst->nz = fmaf(matrix->m22, nz, fmaf(matrix->m21, ny, matrix->m20 * nx));
}

struct WeightedChunkVertex {
    VtxIn_803E3390 vertex;
    s16 weight;
    u16 index;
};

typedef char WeightedChunkVertex_size[sizeof(WeightedChunkVertex) == 0x1C ? 1 : -1];

void GXSetVtxAttrFmtv(ChunkVertexJob *job, ReorderedMatrix_803E3390 *matrix, u32 accumulate) {
    const WeightedChunkVertex *src = (const WeightedChunkVertex *)job->src;
    for (s32 i = 0; i < job->count; ++i, ++src) {
        VtxOut_803E3390 *dst = (VtxOut_803E3390 *)(job->dst + src->index * sizeof(VtxOut_803E3390));
        VtxOut_803E3390 transformed;
        transform_chunk_vertex(&src->vertex, matrix, &transformed);
        f32 weight = src->weight * (1.0f / 256.0f);
        if (accumulate) {
            dst->x = fmaf(transformed.x, weight, dst->x);
            dst->y = fmaf(transformed.y, weight, dst->y);
            dst->z = fmaf(transformed.z, weight, dst->z);
            dst->nx = fmaf(transformed.nx, weight, dst->nx);
            dst->ny = fmaf(transformed.ny, weight, dst->ny);
            dst->nz = fmaf(transformed.nz, weight, dst->nz);
        } else {
            dst->x = transformed.x * weight;
            dst->y = transformed.y * weight;
            dst->z = transformed.z * weight;
            dst->nx = transformed.nx * weight;
            dst->ny = transformed.ny * weight;
            dst->nz = transformed.nz * weight;
        }
    }
}
#endif

// Matrix pairs: (m00,m10)(m20,m01)(m11,m21)(m02,m12)(m22,m03)(m13,m23).
// Loads with W=1 force ps1 = 1.0; ps_madds0/1 accumulate position columns,
// ps_muls1 starts the normal. The first vertex is peeled; stores use psq_stu
// (+12, +8 W=1, +4, +8 W=1) leaving dst->pad untouched.
#ifdef __MWERKS__
asm void transform_chunk_vertices_pos_normal(register ChunkVertexJob *job, register ReorderedMatrix_803E3390 *matrix) {
    nofralloc
    lwz r5, 0x0(r3)
    lwz r6, 0x4(r3)
    lwz r7, 0x8(r3)
    stwu r1, -0x40(r1)
    stfd f14, 0x8(r1)
    stfd f15, 0x10(r1)
    addi r7, r7, -0x1
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    mtctr r7
    psq_l f0, 0x0(r4), 0, 0
    addi r6, r6, -0x8
    psq_l f1, 0x8(r4), 1, 0
    addi r5, r5, -0xc
    psq_l f6, 0x24(r4), 0, 0
    psq_lu f8, 0x8(r6), 0, 0
    psq_l f7, 0x2c(r4), 1, 0
    psq_lu f9, 0x8(r6), 0, 0
    ps_madds0 f11, f0, f8, f6
    psq_l f2, 0xc(r4), 0, 0
    ps_madds0 f12, f1, f8, f7
    psq_l f3, 0x14(r4), 1, 0
    ps_muls1 f13, f0, f9
    psq_lu f10, 0x8(r6), 0, 0
    ps_muls1 f14, f1, f9
    psq_l f5, 0x20(r4), 1, 0
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f4, 0x18(r4), 0, 0
    ps_madds0 f13, f2, f10, f13
    psq_lu f8, 0x8(r6), 0, 0
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x8(r6), 0, 0
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x8(r6), 0, 0
    cmpwi r7, 0x0
    beq tail
loop:
    ps_madds0 f11, f0, f8, f6
    psq_stu f15, 0xc(r5), 0, 0
    ps_madds0 f12, f1, f8, f7
    psq_stu f16, 0x8(r5), 1, 0
    ps_muls1 f13, f0, f9
    psq_stu f17, 0x4(r5), 0, 0
    ps_muls1 f14, f1, f9
    psq_stu f18, 0x8(r5), 1, 0
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_lu f8, 0x8(r6), 0, 0
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x8(r6), 0, 0
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x8(r6), 0, 0
    bdnz loop
tail:
    psq_stu f15, 0xc(r5), 0, 0
    psq_stu f16, 0x8(r5), 1, 0
    psq_stu f17, 0x4(r5), 0, 0
    psq_stu f18, 0x8(r5), 1, 0
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    addi r1, r1, 0x40
    blr
}
#else
void transform_chunk_vertices_pos_normal(ChunkVertexJob *job, ReorderedMatrix_803E3390 *matrix) {
    VtxOut_803E3390 *dst = (VtxOut_803E3390 *)job->dst;
    VtxIn_803E3390 *src = (VtxIn_803E3390 *)job->src;
    s32 n = job->count;
    while (n-- > 0) {
        transform_chunk_vertex(src, matrix, dst);
        src++;
        dst++;
    }
}
#endif
}

void TObjPlayer::transform_vertex_list() {
    ChunkVertexJob *arg0 = (ChunkVertexJob *)this;
    s32 n = arg0->count;
    u8 *src = arg0->src;
    u8 *dst = arg0->dst;
    while (n-- > 0) {
        transform_point_by_current_matrix(src, dst);
        rotate_vector_by_current_matrix(src + 0xC, dst + 0xC);
        f32 t = *(f32 *)(src + 0x18);
        src += 0x1C;
        *(s32 *)(dst + 0x18) = __cvt_fp2unsigned(t);
        dst += 0x20;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}
static inline void GXNormal3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}
static inline void GXTexCoord2s16(s16 s, s16 t) {
    GXWGFifo.s16 = s;
    GXWGFifo.s16 = t;
}

void draw_chunk_textured_strips(s16 *list, Vtx_803E36C4 *verts, u32 info, s32 large) {
    s16 s;
    s16 t;
    Vtx_803E36C4 *v;
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if ((u32)chunk_render_flags != 0) {
        if ((u32)chunk_render_flags & 1) {
            if ((u32)chunk_render_flags & 0x200) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        } else if ((u32)chunk_render_flags & 2) {
            if ((u32)chunk_render_flags & 0x400) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        }
    }
    TObjPlayer::clear_move_state_bits();
    GXSetVtxAttrFmt(0, 0xD, 1, 3, large ? 0xC : 8);
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    Dolphin_GXSetVtxDesc(0xD, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(0x98, 0, n);
        }
        do {
            v = &verts[*list++];
            s = *list++;
            t = *list++;
            if (draw) {
                GXPosition3f32(v->x, v->y, v->z);
                GXNormal3f32(v->nx, v->ny, v->nz);
                GXTexCoord2s16(s, t);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}

void draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    Vtx_803E36C4 *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(0x98, 0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32(v->x, v->y, v->z);
            GXNormal3f32(v->nx, v->ny, v->nz);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
}
s32 dispatch_chunk_vertex_list(u32*, s32);
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void submit_chunk_material_color(s32 type, s16* data) {
    FloatColor add;
    ByteColor color;
    ByteColor fallback = {0, 0, 0, 0x7F};
    ByteColor converted;
    ByteColor convertedAdd;
    if ((u32)(((u8)type-0x10)&1)!=0U) {
        s16 gb=data[0],ar=data[1];
        color.a=(ar>>8)&255;
        color.r=(u8)ar;
        color.g=(gb>>8)&255;
        color.b=(u8)gb;
        if ((u32)(model_render_flags&0x10)!=0U) {
            convert_color_f32_to_u8(&model_material_color,&converted);
            GXSetChanMatColor(4,converted);
        } else if ((u32)(model_render_flags&0x20)!=0U) {
            convert_color_u8_to_f32(&color,&add);
            add.a+=model_material_color.a;
            add.r+=model_material_color.r;
            add.g+=model_material_color.g;
            add.b+=model_material_color.b;
            convert_color_f32_to_u8(&add,&convertedAdd);
            GXSetChanMatColor(4,convertedAdd);
        } else GXSetChanMatColor(4,color);
    }
    if ((u32)(ginja_draw_flags&2)!=0U) GXSetChanMatColor(4,fallback);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_chunk_blend(u32 x) {
    chunk_blend_header_bits = x & 0x3F00;
    chunk_strip_dirty_flags |= 8;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
void apply_chunk_texture_command(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 idx;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    var_r5 = 1;
    var_r6 = 1;
    if ((u32) (arg0 & 0x2000) != 0) {
        var_r6 = 0;
    } else if ((u32) (arg0 & 0x8000) != 0) {
        var_r6 = 2;
    }
    if ((u32) (arg0 & 0x1000) != 0) {
        var_r5 = 0;
    } else if ((u32) (arg0 & 0x4000) != 0) {
        var_r5 = 2;
    }
    var_r31 = arg1 & 0x1FFF;
    idx = var_r31;
    var_r4 = var_r6;
    var_r6 = 0;
    load_list_texture((idx), (var_r4), (var_r5), 0);
    chunk_texture_record_index = var_r31;
}
#pragma pop

void TObjPlayer::setup_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetNumTexGens(0U);
    GXSetTevOp(0, 4);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
}

#pragma push
#pragma peephole off
void setup_chunk_tev_stages(void) {
    if ((u32) (model_render_flags & 0x80000) != 0) {
        GXSetNumTevStages((int)((void *) ((u8)(lbl_805D77D8 + 1))));
        GXSetNumTexGens((u8)((void *) ((u8)(lbl_805D77D9 + 1))));
    } else {
        GXSetNumTevStages((int)((void *) (1U)));
        GXSetNumTexGens((u8)((void *) (1U)));
    }
    GXSetTevOp(0, 0);
    GXSetTevOrder(0, 0, 0, 4);
}
#pragma pop

void set_strip_lighting_chan_ctrl(u32 flags) {
    u8 enable;
    if (chunk_has_vertex_colors != 0) {
        enable = 0;
    } else if (flags & 1) {
        enable = 0;
    } else {
        enable = 1;
    }
    if (chunk_has_vertex_colors != 0) {
        GXSetChanCtrl(0, enable, 0, 1, gx_chan_ctrl_light_mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 1, gx_chan_ctrl_light_mask, 2, 2);
    } else {
        GXSetChanCtrl(0, enable, 0, 0, gx_chan_ctrl_light_mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 0, gx_chan_ctrl_light_mask, 2, 2);
    }
}

#pragma push
#pragma scheduling off
s32 set_chunk_alpha_compare_ref(int ref) {
    GXSetAlphaCompare(4, ref, 0, 7, 0);
}
#pragma pop

void set_chunk_blend_depth_mode(s32 arg0, s32 arg1) {
    // Inferred names: the two reasons the blended pass may keep depth writes,
    // loaded from .sdata2 like the original's static constants.
    static const u32 texture_alpha_reason = 1;
    static const u32 model_alpha_reason = 2;
    s32 var_r31;
    s32 temp_r30;
    s32 temp_r29;
    u32 var_r28;
    u8 *temp_r4;
    u32 id;
    u8 *temp_r3;
    u32 var_r6;
    if ((u32) (arg0 & 8) != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    temp_r30 = (u32) (chunk_blend_header_bits & 0x3800) >> 0xBU;
    temp_r29 = (u32) (chunk_blend_header_bits & 0x700) >> 8U;
    if ((u32) chunk_render_flags != 0) {
        TObjPlayer::clear_move_state_bits();
    }
    if (arg1 == 0) {
        GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
        GXSetZCompLoc(0);
        GXSetZMode(1, 3, 0);
    } else if (var_r31 != 0) {
        var_r6 = 0;
        var_r28 = 1U;
        temp_r4 = (u8 *)((*(Holder_803E3B6C **)(current_render_context + 0x20))->recs[chunk_texture_record_index].p->q);
        id = model_render_flags;
        if (((u32) (id & 0x10) != 0) && (1.0f != model_material_color.a)) {
            var_r28 = 0U;
        }
        if (((u32) (id & 0x20) != 0) && (0.0f != model_material_color.a)) {
            var_r28 = 0U;
        }
        if ((u32) *(u32 *)((s8 *)temp_r4 + 4) == 0xEU) {
            if ((u32) (id & 0x400000) != 0) {
                if ((u32) (*(s32 *)((s8 *)temp_r4 + 0x1C) & 0x40000000) != 0) {
                    var_r6 |= texture_alpha_reason;
                }
            } else {
                var_r6 |= texture_alpha_reason;
            }
        }
        if ((u32) (id & 1) != 0) {
            var_r6 |= model_alpha_reason;
        }
        if ((var_r28 != 0U) && (var_r6 != 0) && (temp_r30 == 4) && (temp_r29 == 5)) {
            if ((u32) chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
            if ((u32) (model_render_flags & 0x200000) != 0) {
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref(0);
            } else {
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref((u8) material_alpha_compare_reference);
            }
        } else {
            if ((u32) chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            if (((u32) (id & 0x01000000) != 0) && ((u32) (ginja_draw_flags & 2) == 0)) {
                GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref((u8) material_alpha_compare_reference);
            } else {
                GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
                GXSetZCompLoc(0);
                if (var_r28 != 0U) {
                    GXSetZMode(1, 3, 0);
                } else {
                    GXSetZMode(1, 3, 1);
                }
                set_chunk_alpha_compare_ref(0);
            }
        }
    } else {
        if ((u32) chunk_render_flags != 0) {
            chunk_render_flags |= 0x400;
        }
        temp_r3 = (u8 *)((*(Holder_803E3B6C **)(current_render_context + 0x20))->recs[chunk_texture_record_index].p->q);
        if (((u32) *(u32 *)((s8 *)temp_r3 + 4) == 0xEU) && ((u32) (*(s32 *)((s8 *)temp_r3 + 0x1C) & 0x40000000) != 0)) {
            set_chunk_alpha_compare_ref(0x1F);
            GXSetBlendMode(0, temp_r30, temp_r29, 0);
            GXSetZCompLoc(0);
            GXSetZMode(1, 3, 1);
        } else {
            GXSetBlendMode(0, temp_r30, temp_r29, 0);
            GXSetZCompLoc(1);
            GXSetZMode(1, 3, 1);
        }
    }
    if ((u32) (model_render_flags & 0x400) != 0) {
        GXSetZMode(1, 3, 0);
    }
}

extern "C" {
void GXSetTexCoordGen2(s32 dst, u32 func, u32 src, s32 mtx, s32 normalize, s32 pt);
extern s32 chunk_polygon_cache_pending;  // lists cached by NJD_CB_CP and not yet drawn by NJD_CB_DP
extern u32 chunk_polygon_flags_and_mask;
extern u32 chunk_polygon_flags_or_mask;
}

#pragma push
#pragma bool off
#pragma opt_propagation off
void dispatch_chunk_polygon_list(s16 *list, s32 vertex_buffer) {
    struct CommandState {
        s16 wire;
        int header;
    } state;
    s32 type;
    u32 strip_size;  // shorts after the size word, strip_info included
    s32 strip_info;  // [UserOffset(2)|nbStrip(14)]
    u32 changed;

    while ((state.header = (state.wire = *list++)) != NJD_CE) {
        s16 decoded = (s16)(state.header & 0xFF);
        type = decoded;
        if (type < NJD_TINYOFF) {
            switch (type) {
            case NJD_CB_BA:
                set_chunk_blend(state.header);
                break;
            case NJD_CB_CP:
                chunk_polygon_list_cache[(s16)((state.header >> 8) & 0xFF)] = list;
                chunk_polygon_cache_pending++;
                return;
            case NJD_CB_DP:
                dispatch_chunk_polygon_list(chunk_polygon_list_cache[(s16)((state.header >> 8) & 0xFF)], vertex_buffer);
                chunk_polygon_cache_pending--;
                break;
            }
        } else if (type < NJD_MATOFF) {
            apply_chunk_texture_command(state.header, *list);
            list++;
        } else if (type < NJD_STRIPOFF) {
            s32 size = (s16)*list++;
            set_chunk_blend(state.header);
            submit_chunk_material_color(state.header, list);
            list += size;
        } else {
            strip_size = *(u16 *)list++;
            strip_info = (s16)*list++;
            if ((u32)(model_render_flags & 0x800) != 0) {
                struct MaskWord {
                    s16 value;
                } masked;
                masked.value = state.wire;
                masked.value &= chunk_polygon_flags_and_mask;
                masked.value |= chunk_polygon_flags_or_mask;
                state.header = masked.value;
            }
            state.header = (s16)(state.header >> NJD_FST_SHIFT);
            changed = state.header ^ chunk_previous_strip_flags;
            changed |= chunk_strip_dirty_flags;
            chunk_previous_strip_flags = state.header;
            chunk_strip_dirty_flags = 0;
            if (changed & (NJD_FST_IL >> NJD_FST_SHIFT)) {
                set_strip_lighting_chan_ctrl(state.header);
            }
            switch (type) {
            case NJD_CS:
                if (state.header & (NJD_FST_ENV >> NJD_FST_SHIFT)) {
                    set_chunk_blend_depth_mode(state.header, 1);
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(0, 0, 1, 0x2A, 0, 0x7D);
                    draw_strip_pos_normal__10TObjPlayerFPvPvUi(list, (Vtx_803E36C4 *) vertex_buffer, strip_info);
                } else {
                    set_chunk_blend_depth_mode(state.header, 0);
                    TObjPlayer::setup_tev_passclr();
                    draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(list, (Vtx_803E36C4 *) vertex_buffer, strip_info);
                }
                break;
            case NJD_CS_UVN:
            case NJD_CS_UVH:
                set_chunk_blend_depth_mode(state.header, 1);
                if (state.header & (NJD_FST_ENV >> NJD_FST_SHIFT)) {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(0, 0, 1, 0x2A, 0, 0x7D);
                    draw_triangle_strips__10TObjPlayerFPvPvUi(list, (Vtx_803E36C4 *) vertex_buffer, strip_info);
                } else if (chunk_has_vertex_colors != 0) {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
                    draw_chunk_color_tex_strips(list, (ChunkColorVertex *) vertex_buffer, strip_info, type == NJD_CS_UVH);
                } else {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
                    draw_chunk_textured_strips(list, (Vtx_803E36C4 *) vertex_buffer, strip_info, type == NJD_CS_UVH);
                }
                break;
            }
            list += strip_size - 1;
        }
    }
}
#pragma pop

extern "C" {
void push_reordered_matrix_ps(void);
void transform_vertex_list__10TObjPlayerFv(ChunkVertexJob *job, s32 matrix);
}

s32 dispatch_chunk_vertex_list(u32 *list, s32 buffer) {
    u32 info;
    u32 length;
    s32 total;
    u16 type;
    ChunkVertexJob job;
    total = 0;
    push_reordered_matrix_ps();
    while ((*list & 0xFF) != 0xFF) {
        type = *list;
        length = (*list & 0xFFFF0000) >> 16;
        info = list[1];
        list += 2;
        job.count = (info & 0xFFFF0000) >> 16;
        job.src = (u8 *)list;
        job.dst = (u8 *)(buffer + (info & 0xFFFF) * 32);
        total += job.count;
        if ((type & 0xFF) == 0x29) {
            transform_chunk_vertices_pos_normal(&job, (ReorderedMatrix_803E3390 *)current_matrix);
        } else if ((type & 0xFF) == 0x2C) {
            GXSetVtxAttrFmtv(&job, (ReorderedMatrix_803E3390 *)current_matrix, ((type & ~0x8000) >> 8) & 0xFF);
        } else if ((type & 0xFF) == 0x2A) {
            transform_vertex_list__10TObjPlayerFv(&job, current_matrix);
        } else if ((type & 0xFF) == 0x23) {
            pop_matrix();
            chunk_has_vertex_colors = 1;
            cache_chunk_vertex_colors(&job, current_matrix);
            push_matrix();
        }
        list += length - 1;
    }
    pop_matrix();
    return total;
}

void TObjPlayer::setup_model_draw_state(void *) {
    Mtx_803E4354 scale;
    Mtx_803E4354 trans;
    Mtx_803E4354 m;
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::reset_particle_counter();
        apply_scene_fog();
    }
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xA, 0, 4, 0);
    GXSetNumChans(1);
    chunk_previous_strip_flags = 0;
    chunk_strip_dirty_flags = -1;
    GXLoadPosMtxImm(identity_matrix, 0);
    GXLoadNrmMtxImm(identity_matrix, 0);
    if ((u32) (model_render_flags & 0x100000) != 0) {
        PSMTXScale(scale, -0.5f, -0.5f, 0.0f);
        PSMTXTrans(trans, 0.5f, 0.5f, 1.0f);
        PSMTXConcat(scale, identity_matrix, m);
        PSMTXConcat(trans, m, m);
        GXLoadTexMtxImm(m, 0x2A, 0);
    }
    push_matrix();
    GXSetZCompLoc(0);
}

#pragma push
#pragma peephole off
void TObjPlayer::end_chunk_draw() {
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::set_effect_active();
        apply_scene_fog();
    }
    pop_matrix();
    GXSetZCompLoc(1);
    GXSetZMode(1, 1, 1);
    set_chunk_alpha_compare_ref(0);
    if (((s32 (*)()) player_chunk_draw_end_callback) != NULL) {
        player_chunk_draw_end_callback();
    }
}
#pragma pop

s32 draw_chunk_vertices_cached__10TObjPlayerFPv(void* arg) {
    ChunkModel_803E44D4* model = (ChunkModel_803E44D4*)arg;
    s32 cache;
    s32 count = 0;
    if ((u32)chunk_render_flags & 4) return 0;
    chunk_has_vertex_colors = 0;
    cache = chunk_vertex_cache_buffer;
    if (lbl_805D77E4 & 4) {
        if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes != 0) {
            memmove((void*)chunk_vertex_cache_buffer, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes);
        }
        chunk_vertex_cache_state->index++;
    } else if (model->vertices != 0) {
        count = dispatch_chunk_vertex_list(model->vertices, chunk_vertex_cache_buffer);
    }
    if (lbl_805D77E4 & 1) {
        if (chunk_vertex_cache_state) {
            if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices == 0) {
                if (count) {
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices = xmalloc(count << 5);
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes = count << 5;
                }
            } else {
                OSReport(lbl_804FC810);
            }
            chunk_vertex_cache_state->index++;
        }
    } else {
        if (lbl_805D77E4 & 2) {
            if (count) memmove(chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, (void*)chunk_vertex_cache_buffer, count << 5);
            chunk_vertex_cache_state->index++;
        }
        if (model->polygons) dispatch_chunk_polygon_list(model->polygons, cache);
        return 0;
    }
}

void draw_chunk_model(void *arg0) {
    TObjPlayer::setup_model_draw_state(arg0);
    draw_chunk_vertices_cached__10TObjPlayerFPv(arg0);
    TObjPlayer::end_chunk_draw();
}

#pragma push
#pragma scheduling off

void draw_chunk_object(void *child) {
    TObjPlayer::setup_model_draw_state(child);
    transform_chunk_object_tree(child, (void (*)(void *))draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void draw_strip_pos_normal__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    Vtx_803E36C4 *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(0x98, 0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32(v->x, v->y, v->z);
            GXNormal3f32(v->nx, v->ny, v->nz);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimization_level 4
void draw_triangle_strips__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info) {
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    Vtx_803E36C4 *v;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if ((u32)chunk_render_flags != 0) {
        if ((u32)chunk_render_flags & 1) {
            if ((u32)chunk_render_flags & 0x200) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        } else if ((u32)chunk_render_flags & 2) {
            if ((u32)chunk_render_flags & 0x400) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        }
    }
    TObjPlayer::clear_move_state_bits();
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(0x98, 0, n);
        }
        do {
            v = &verts[*list++];
            if (draw) {
                GXPosition3f32(v[2].x, v[2].y, v[2].z);
                GXNormal3f32(v[2].nx, v[2].ny, v[2].nz);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer__sub_803E492C(s32 a, s32 b) {
    chunk_vertex_cache_buffer = a;
    lbl_805D77FC = b;
    chunk_render_flags = 0;
}
#pragma pop


void set_chunk_render_flags(u32 flags) {
    chunk_render_flags = flags;
}

void clear_chunk_render_flags() {
    chunk_render_flags = 0;
}


u8 chunk_object_current_matrix[0x30];
