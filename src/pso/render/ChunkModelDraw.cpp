#include "types.h"
#include <string.h>
#include "pso/render/ChunkVertexJob.h"
#include "pso/render/ChunkPolygonList.h"
#include <math.h>
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/SceneFog.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/memory.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/model_render_state.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/system/MatrixOps.h"
#include <dolphin/mtx.h>
#include "pso/animation/MotionContext.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/gx/GXStruct.h>
#include <dolphin/os.h>
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXGeometry.h>
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXLighting.h>
#include <dolphin/gx/GXPixel.h>
#include <dolphin/gx/GXVert.h>
#include <dolphin/gx/GXTev.h>
#undef PSO_SDK_COMPACT_MATH






// One vertex of the chunk vertex cache: transformed position and normal, then
// the vertex colour and a pad word to 32 bytes.
struct ChunkCachedVertex {
    Vec pos;
    Vec normal;
    u32 color;
    u32 pad;
};

extern "C" {
void transform_chunk_object_tree(void *object, s32 (*draw)(void *model));
void draw_strip_list_pos_nrm(s16 *list, ChunkCachedVertex *verts, u32 info);
void draw_strip_pos_normal(s16 *list, ChunkCachedVertex *verts, u32 info);
void draw_triangle_strips(s16 *list, ChunkCachedVertex *verts, u32 info);
void draw_chunk_textured_strips(s16 *list, ChunkCachedVertex *verts, u32 info, s32 large);
}

// One recorded chunk vertex cache: the transformed vertices of one model draw.
struct ChunkCacheBuffer { void *vertices; s32 bytes; };
struct ChunkCacheRecording { ChunkCacheBuffer buffers[32]; s32 index; };

char chunk_memory_assert_message[19] = "CHNK MEMORY ASSERT";
GC_Mtx chunk_object_current_matrix;

s32 chunk_previous_strip_flags;
u32 chunk_strip_dirty_flags;
u8 chunk_tev_stage_extra;
u8 chunk_texgen_extra;
void (*player_chunk_draw_end_callback)();
u32 chunk_has_vertex_colors;
u32 chunk_vertex_cache_flags;
ChunkCacheRecording* chunk_vertex_cache_state;
s32 chunk_texture_record_index;
u32 chunk_blend_header_bits;
u32 lbl_805D77F4;
u32 chunk_render_flags;
s32 chunk_vertex_cache_size;
saddr chunk_vertex_cache_buffer;

extern "C" {

#pragma push
#pragma peephole off
#pragma scheduling off
void copy_matrix3x3_for_chunk_tree(const GC_Mtx *src) {
    GC_Mtx *dst = current_matrix;
    (*dst)[0][0] = (*src)[0][0];
    (*dst)[0][1] = (*src)[0][1];
    (*dst)[0][2] = (*src)[0][2];
    (*dst)[1][0] = (*src)[1][0];
    (*dst)[1][1] = (*src)[1][1];
    (*dst)[1][2] = (*src)[1][2];
    (*dst)[2][0] = (*src)[2][0];
    (*dst)[2][1] = (*src)[2][1];
    (*dst)[2][2] = (*src)[2][2];
}
#pragma pop

#define node ((NJS_OBJECT *)object)
void transform_chunk_object_tree(void *object, s32 (*draw)(void *model)) {
    u32 flags;
    s32 r;

    do {
        flags = node->evalflags;
        r = 0;
        if (flags & 0x800) {
            get_current_matrix(&chunk_object_current_matrix);
        }
        if ((flags & 7) == 7) {
            if (!(flags & 8)) {
                r = draw(node->model);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, draw);
            }
        } else {
            push_matrix();
            if (!(flags & 1)) {
                post_translate_matrix(node->pos);
            }
            if (!(flags & 2)) {
                if (flags & 0x1000) {
                    copy_matrix3x3_for_chunk_tree(&chunk_object_current_matrix);
                } else if (flags & 0x400) {
                    apply_quat_rotation(node->quat_w, (f32 *)node->ang);
                } else {
                    rotate_matrix_by_node_angles(node->ang, flags & 0x20);
                }
            }
            if (!(flags & 4)) {
                scale_current_matrix(node->scl);
            }
            if (!(flags & 8)) {
                r = draw(node->model);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, draw);
            }
            pop_matrix();
        }
        object = node->sibling;
    } while (object != NULL);
}
#undef node
}

struct ChunkPairedMatrix {
    f32 m00, m10;
    f32 m20, m01;
    f32 m11, m21;
    f32 m02, m12;
    f32 m22, m03;
    f32 m13, m23;
};
// A chunk vertex stream entry: position then normal, untransformed.
struct ChunkVertexPosNormal {
    Vec pos;
    Vec normal;
};
LAYOUT_ASSERT(ChunkPairedMatrix_size, sizeof(ChunkPairedMatrix) == 0x30);
LAYOUT_ASSERT(ChunkVertexPosNormal_size, sizeof(ChunkVertexPosNormal) == 0x18);
LAYOUT_ASSERT(ChunkCachedVertex_size, sizeof(ChunkCachedVertex) == 0x20);

struct WeightedChunkVertex {
    ChunkVertexPosNormal vertex;
    s16 weight;
    u16 index;
};
LAYOUT_ASSERT(WeightedChunkVertex_size, sizeof(WeightedChunkVertex) == 0x1C);

extern "C" {
// The store loop at 0x803E1E84 writes the current 3x4 as these pairs.
// reorder_current_matrix_ps (0x803E1E74) falls into it; push_reordered_matrix_ps
// (0x803E1ED0) advances the matrix slot by 0x30 and branches to it.
// Position uses the translation column; the normal uses only the 3x3.

// This chunk command transforms indexed positions and normals with signed 8.8 weights.
#ifdef __MWERKS__
asm void transform_chunk_vertices_weighted(ChunkVertexJob *job, ChunkPairedMatrix *matrix, u32 accumulate) {
#include "orig_asm/pso/render/ChunkModelDraw/transform_chunk_vertices_weighted.inc"
}
#else
static void transform_chunk_vertex(const ChunkVertexPosNormal *src, const ChunkPairedMatrix *matrix, ChunkCachedVertex *dst) {
    f32 x = src->pos.x, y = src->pos.y, z = src->pos.z;
    f32 nx = src->normal.x, ny = src->normal.y, nz = src->normal.z;
    dst->pos.x = fmaf(matrix->m02, z, fmaf(matrix->m01, y, fmaf(matrix->m00, x, matrix->m03)));
    dst->pos.y = fmaf(matrix->m12, z, fmaf(matrix->m11, y, fmaf(matrix->m10, x, matrix->m13)));
    dst->pos.z = fmaf(matrix->m22, z, fmaf(matrix->m21, y, fmaf(matrix->m20, x, matrix->m23)));
    dst->normal.x = fmaf(matrix->m02, nz, fmaf(matrix->m01, ny, matrix->m00 * nx));
    dst->normal.y = fmaf(matrix->m12, nz, fmaf(matrix->m11, ny, matrix->m10 * nx));
    dst->normal.z = fmaf(matrix->m22, nz, fmaf(matrix->m21, ny, matrix->m20 * nx));
}

void transform_chunk_vertices_weighted(ChunkVertexJob *job, ChunkPairedMatrix *matrix, u32 accumulate) {
    const WeightedChunkVertex *src = (const WeightedChunkVertex *)job->src;
    for (s32 i = 0; i < job->count; ++i, ++src) {
        ChunkCachedVertex *dst = (ChunkCachedVertex *)(job->dst + src->index * sizeof(ChunkCachedVertex));
        ChunkCachedVertex transformed;
        transform_chunk_vertex(&src->vertex, matrix, &transformed);
        f32 weight = src->weight * (1.0f / 256.0f);
        if (accumulate) {
            dst->pos.x = fmaf(transformed.pos.x, weight, dst->pos.x);
            dst->pos.y = fmaf(transformed.pos.y, weight, dst->pos.y);
            dst->pos.z = fmaf(transformed.pos.z, weight, dst->pos.z);
            dst->normal.x = fmaf(transformed.normal.x, weight, dst->normal.x);
            dst->normal.y = fmaf(transformed.normal.y, weight, dst->normal.y);
            dst->normal.z = fmaf(transformed.normal.z, weight, dst->normal.z);
        } else {
            dst->pos.x = transformed.pos.x * weight;
            dst->pos.y = transformed.pos.y * weight;
            dst->pos.z = transformed.pos.z * weight;
            dst->normal.x = transformed.normal.x * weight;
            dst->normal.y = transformed.normal.y * weight;
            dst->normal.z = transformed.normal.z * weight;
        }
    }
}
#endif

// Matrix pairs: (m00,m10)(m20,m01)(m11,m21)(m02,m12)(m22,m03)(m13,m23).
// Loads with W=1 force ps1 = 1.0; ps_madds0/1 accumulate position columns,
// ps_muls1 starts the normal. The first vertex is peeled; stores use psq_stu
// (+12, +8 W=1, +4, +8 W=1) leaving dst->pad untouched.
#ifdef __MWERKS__
asm void transform_chunk_vertices_pos_normal(register ChunkVertexJob *job, register ChunkPairedMatrix *matrix) {
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
void transform_chunk_vertices_pos_normal(ChunkVertexJob *job, ChunkPairedMatrix *matrix) {
    ChunkCachedVertex *dst = (ChunkCachedVertex *)job->dst;
    ChunkVertexPosNormal *src = (ChunkVertexPosNormal *)job->src;
    s32 n = job->count;
    while (n-- > 0) {
        transform_chunk_vertex(src, matrix, dst);
        src++;
        dst++;
    }
}
#endif

// NJD_CV_VN_D8 records: position, normal and a diffuse colour.
struct ChunkVertexNormalColor {
    Vec pos;
    Vec normal;
    f32 color;
};

void transform_chunk_vertices_pos_normal_color(ChunkVertexJob *job, GC_Mtx *matrix) {
    s32 n = job->count;
    ChunkVertexNormalColor *src = (ChunkVertexNormalColor *)job->src;
    ChunkCachedVertex *dst = (ChunkCachedVertex *)job->dst;
    while (n-- > 0) {
        transform_point_by_current_matrix(&src->pos.x, &dst->pos);
        rotate_vector_by_current_matrix(&src->normal, &dst->normal);
        f32 color = src->color;
        src++;
        dst->color = color;
        dst++;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void draw_chunk_textured_strips(s16 *list, ChunkCachedVertex *verts, u32 info, s32 large) {
    s16 s;
    s16 t;
    ChunkCachedVertex *v;
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if (chunk_render_flags != 0) {
        if (chunk_render_flags & 1) {
            if (chunk_render_flags & 0x200) {
                clear_chunk_strip_blend_flags();
                draw = 0;
            }
        } else if (chunk_render_flags & 2) {
            if (chunk_render_flags & 0x400) {
                clear_chunk_strip_blend_flags();
                draw = 0;
            }
        }
    }
    clear_chunk_strip_blend_flags();
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, large ? 0xC : 8);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
        }
        do {
            v = &verts[*list++];
            s = *list++;
            t = *list++;
            if (draw) {
                GXPosition3f32(v->pos.x, v->pos.y, v->pos.z);
                GXNormal3f32(v->normal.x, v->normal.y, v->normal.z);
                GXTexCoord2s16(s, t);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}

void draw_strip_list_pos_nrm(s16 *list, ChunkCachedVertex *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    ChunkCachedVertex *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32(v->pos.x, v->pos.y, v->pos.z);
            GXNormal3f32(v->normal.x, v->normal.y, v->normal.z);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
}
s32 dispatch_chunk_vertex_list(u32*, saddr);
#pragma pop

void submit_chunk_material_color(s32 type, s16* data) {
    NJS_ARGB add;
    GXColor color;
    GXColor fallback = {0, 0, 0, 0x7F};
    GXColor converted;
    GXColor convertedAdd;
    if ((u32)(((u8)type-0x10)&1)!=0U) {
        s16 gb=data[0],ar=data[1];
        color.a=(ar>>8)&255;
        color.r=(u8)ar;
        color.g=(gb>>8)&255;
        color.b=(u8)gb;
        if ((u32)(model_render_flags&0x10)!=0U) {
            convert_color_f32_to_u8(&model_material_color,&converted);
            GXSetChanMatColor(GX_COLOR0A0, converted);
        } else if ((u32)(model_render_flags&0x20)!=0U) {
            convert_color_u8_to_f32(&color,&add);
            add.a+=model_material_color.a;
            add.r+=model_material_color.r;
            add.g+=model_material_color.g;
            add.b+=model_material_color.b;
            convert_color_f32_to_u8(&add,&convertedAdd);
            GXSetChanMatColor(GX_COLOR0A0, convertedAdd);
        } else GXSetChanMatColor(GX_COLOR0A0, color);
    }
    if ((u32)(ginja_draw_flags&2)!=0U) GXSetChanMatColor(GX_COLOR0A0, fallback);
}

void set_chunk_blend(u32 x) {
    chunk_blend_header_bits = x & 0x3F00;
    chunk_strip_dirty_flags |= 8;
}

void apply_chunk_texture_command(s32 header, s32 texture_word) {
    s32 texture_id;
    s32 wrap_t = GX_REPEAT;
    s32 wrap_s = GX_REPEAT;
    if (header & NJD_FCL_U) {
        wrap_s = GX_CLAMP;
    } else if (header & NJD_FFL_U) {
        wrap_s = GX_MIRROR;
    }
    if (header & NJD_FCL_V) {
        wrap_t = GX_CLAMP;
    } else if (header & NJD_FFL_V) {
        wrap_t = GX_MIRROR;
    }
    texture_id = texture_word & NJD_TID_MASK;
    load_list_texture(texture_id, wrap_s, wrap_t, 0);
    chunk_texture_record_index = texture_id;
}

void setup_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetNumTexGens(0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
}

void setup_chunk_tev_stages(void) {
    if ((u32) (model_render_flags & 0x80000) != 0) {
        GXSetNumTevStages(chunk_tev_stage_extra + 1);
        GXSetNumTexGens(chunk_texgen_extra + 1);
    } else {
        GXSetNumTevStages(1);
        GXSetNumTexGens(1);
    }
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
}

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
        GXSetChanCtrl(GX_COLOR0, enable, GX_SRC_REG, GX_SRC_VTX, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
        GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
    } else {
        GXSetChanCtrl(GX_COLOR0, enable, GX_SRC_REG, GX_SRC_REG, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
        GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
    }
}

void set_chunk_alpha_compare_ref(u8 ref) {
    GXSetAlphaCompare(GX_GREATER, ref, GX_AOP_AND, GX_ALWAYS, 0);
}

void set_chunk_blend_depth_mode(s32 header, s32 textured) {
    // The two reasons the blended pass may keep depth writes.
    static const u32 texture_alpha_reason = 1;
    static const u32 model_alpha_reason = 2;
    GXBlendMode blend_mode;
    GXBlendFactor src_factor;
    GXBlendFactor dst_factor;
    u32 material_opaque;
    GinjaSurfaceState *alpha_surface;
    s32 id;
    GinjaSurfaceState *zcomp_surface;
    u32 alpha_reasons;
    if ((u32) (header & (NJD_FST_UA >> NJD_FST_SHIFT)) != 0) {
        blend_mode = GX_BM_BLEND;
    } else {
        blend_mode = GX_BM_NONE;
    }
    src_factor = (GXBlendFactor)((chunk_blend_header_bits & 0x3800) >> 11);
    dst_factor = (GXBlendFactor)((chunk_blend_header_bits & 0x700) >> 8);
    if (chunk_render_flags != 0) {
        clear_chunk_strip_blend_flags();
    }
    if (textured == 0) {
        GXSetBlendMode(blend_mode, src_factor, dst_factor, GX_LO_CLEAR);
        GXSetZCompLoc(GX_FALSE);
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    } else if (blend_mode != GX_BM_NONE) {
        alpha_reasons = 0;
        material_opaque = 1U;
        alpha_surface = current_render_context->textures->textures[chunk_texture_record_index].texture->surface;
        id = model_render_flags;
        if (((u32) (id & 0x10) != 0) && (1.0f != model_material_color.a)) {
            material_opaque = 0U;
        }
        if (((u32) (id & 0x20) != 0) && (0.0f != model_material_color.a)) {
            material_opaque = 0U;
        }
        if (alpha_surface->header.format == 0xEU) {
            if ((u32) (id & 0x400000) != 0) {
                if ((u32) (alpha_surface->header.flags & 0x40000000) != 0) {
                    alpha_reasons |= texture_alpha_reason;
                }
            } else {
                alpha_reasons |= texture_alpha_reason;
            }
        }
        if ((u32) (id & 1) != 0) {
            alpha_reasons |= model_alpha_reason;
        }
        if ((material_opaque != 0U) && (alpha_reasons != 0) && (src_factor == GX_BL_SRCALPHA) && (dst_factor == GX_BL_INVSRCALPHA)) {
            if (chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            GXSetBlendMode(blend_mode, src_factor, dst_factor, GX_LO_CLEAR);
            if ((u32) (model_render_flags & 0x200000) != 0) {
                GXSetZCompLoc(GX_FALSE);
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                set_chunk_alpha_compare_ref(0);
            } else {
                GXSetZCompLoc(GX_FALSE);
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                set_chunk_alpha_compare_ref(material_alpha_compare_reference);
            }
        } else {
            if (chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            if (((u32) (id & 0x01000000) != 0) && ((u32) (ginja_draw_flags & 2) == 0)) {
                GXSetBlendMode(blend_mode, src_factor, dst_factor, GX_LO_CLEAR);
                GXSetZCompLoc(GX_FALSE);
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                set_chunk_alpha_compare_ref(material_alpha_compare_reference);
            } else {
                GXSetBlendMode(blend_mode, src_factor, dst_factor, GX_LO_CLEAR);
                GXSetZCompLoc(GX_FALSE);
                if (material_opaque != 0U) {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
                } else {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                }
                set_chunk_alpha_compare_ref(0);
            }
        }
    } else {
        if (chunk_render_flags != 0) {
            chunk_render_flags |= 0x400;
        }
        zcomp_surface = current_render_context->textures->textures[chunk_texture_record_index].texture->surface;
        if ((zcomp_surface->header.format == 0xEU) && ((u32) (zcomp_surface->header.flags & 0x40000000) != 0)) {
            set_chunk_alpha_compare_ref(0x1F);
            GXSetBlendMode(GX_BM_NONE, src_factor, dst_factor, GX_LO_CLEAR);
            GXSetZCompLoc(GX_FALSE);
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
        } else {
            GXSetBlendMode(GX_BM_NONE, src_factor, dst_factor, GX_LO_CLEAR);
            GXSetZCompLoc(GX_TRUE);
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
        }
    }
    if ((u32) (model_render_flags & 0x400) != 0) {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    }
}

extern "C" {
extern s32 chunk_polygon_cache_pending;  // lists cached by NJD_CB_CP and not yet drawn by NJD_CB_DP
}

#pragma push
#pragma bool off
#pragma opt_propagation off
void dispatch_chunk_polygon_list(s16 *list, saddr vertex_buffer) {
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
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_NRM, GX_TEXMTX4, GX_FALSE, GX_PTIDENTITY);
                    draw_strip_pos_normal(list, (ChunkCachedVertex *) vertex_buffer, strip_info);
                } else {
                    set_chunk_blend_depth_mode(state.header, 0);
                    setup_tev_passclr();
                    draw_strip_list_pos_nrm(list, (ChunkCachedVertex *) vertex_buffer, strip_info);
                }
                break;
            case NJD_CS_UVN:
            case NJD_CS_UVH:
                set_chunk_blend_depth_mode(state.header, 1);
                if (state.header & (NJD_FST_ENV >> NJD_FST_SHIFT)) {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_NRM, GX_TEXMTX4, GX_FALSE, GX_PTIDENTITY);
                    draw_triangle_strips(list, (ChunkCachedVertex *) vertex_buffer, strip_info);
                } else if (chunk_has_vertex_colors != 0) {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
                    draw_chunk_color_tex_strips(list, (ChunkColorVertex *) vertex_buffer, strip_info, type == NJD_CS_UVH);
                } else {
                    setup_chunk_tev_stages();
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
                    draw_chunk_textured_strips(list, (ChunkCachedVertex *) vertex_buffer, strip_info, type == NJD_CS_UVH);
                }
                break;
            }
            list += strip_size - 1;
        }
    }
}
#pragma pop

s32 dispatch_chunk_vertex_list(u32 *list, saddr buffer) {
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
            transform_chunk_vertices_pos_normal(&job, (ChunkPairedMatrix *)current_matrix);
        } else if ((type & 0xFF) == 0x2C) {
            transform_chunk_vertices_weighted(&job, (ChunkPairedMatrix *)current_matrix, ((type & ~0x8000) >> 8) & 0xFF);
        } else if ((type & 0xFF) == 0x2A) {
            transform_chunk_vertices_pos_normal_color(&job, current_matrix);
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

void setup_model_draw_state(void *) {
    Mtx34 scale;
    Mtx34 trans;
    Mtx34 m;
    if ((u32) (ginja_draw_flags & 2) != 0) {
        disable_scene_fog();
        apply_scene_fog();
    }
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
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
        GXLoadTexMtxImm(m, GX_TEXMTX4, GX_MTX3x4);
    }
    push_matrix();
    GXSetZCompLoc(GX_FALSE);
}

void end_chunk_draw() {
    if ((u32) (ginja_draw_flags & 2) != 0) {
        enable_scene_fog();
        apply_scene_fog();
    }
    pop_matrix();
    GXSetZCompLoc(GX_TRUE);
    GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
    set_chunk_alpha_compare_ref(0);
    if (player_chunk_draw_end_callback != NULL) {
        player_chunk_draw_end_callback();
    }
}

s32 draw_chunk_vertices_cached(void* arg) {
    NJS_CNK_MODEL* model = (NJS_CNK_MODEL*)arg;
    saddr cache;
    s32 count = 0;
    if (chunk_render_flags & 4) return 0;
    chunk_has_vertex_colors = 0;
    cache = chunk_vertex_cache_buffer;
    if (chunk_vertex_cache_flags & 4) {
        if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes != 0) {
            memmove((void*)chunk_vertex_cache_buffer, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes);
        }
        chunk_vertex_cache_state->index++;
    } else if (model->vertex_list != NULL) {
        count = dispatch_chunk_vertex_list((u32 *)model->vertex_list, chunk_vertex_cache_buffer);
    }
    if (chunk_vertex_cache_flags & 1) {
        if (chunk_vertex_cache_state) {
            if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices == 0) {
                if (count) {
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices = xmalloc(count << 5);
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes = count << 5;
                }
            } else {
                OSReport(chunk_memory_assert_message);
            }
            chunk_vertex_cache_state->index++;
        }
    } else {
        if (chunk_vertex_cache_flags & 2) {
            if (count) memmove(chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, (void*)chunk_vertex_cache_buffer, count << 5);
            chunk_vertex_cache_state->index++;
        }
        if (model->polygon_list) dispatch_chunk_polygon_list(model->polygon_list, cache);
        return 0;
    }
}

void draw_chunk_model(void *model) {
    setup_model_draw_state(model);
    draw_chunk_vertices_cached(model);
    end_chunk_draw();
}


void draw_chunk_object(void *child) {
    setup_model_draw_state(child);
    transform_chunk_object_tree(child, draw_chunk_vertices_cached);
    end_chunk_draw();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void draw_strip_pos_normal(s16 *list, ChunkCachedVertex *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    ChunkCachedVertex *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32(v->pos.x, v->pos.y, v->pos.z);
            GXNormal3f32(v->normal.x, v->normal.y, v->normal.z);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimization_level 4
void draw_triangle_strips(s16 *list, ChunkCachedVertex *verts, u32 info) {
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    ChunkCachedVertex *v;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if (chunk_render_flags != 0) {
        if (chunk_render_flags & 1) {
            if (chunk_render_flags & 0x200) {
                clear_chunk_strip_blend_flags();
                draw = 0;
            }
        } else if (chunk_render_flags & 2) {
            if (chunk_render_flags & 0x400) {
                clear_chunk_strip_blend_flags();
                draw = 0;
            }
        }
    }
    clear_chunk_strip_blend_flags();
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
        }
        do {
            v = &verts[*list++];
            if (draw) {
                GXPosition3f32(v[2].pos.x, v[2].pos.y, v[2].pos.z);
                GXNormal3f32(v[2].normal.x, v[2].normal.y, v[2].normal.z);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

void init_chunk_draw(saddr vertex_buffer, s32 vertex_buffer_size) {
    chunk_vertex_cache_buffer = vertex_buffer;
    chunk_vertex_cache_size = vertex_buffer_size;
    chunk_render_flags = 0;
}


void set_chunk_render_flags(u32 flags) {
    chunk_render_flags = flags;
}

void clear_chunk_render_flags() {
    chunk_render_flags = 0;
}


