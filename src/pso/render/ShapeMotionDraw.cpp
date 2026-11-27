#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include <stddef.h>
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "pso/render/ChunkPolygonList.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"

ShapeMotionContext *current_shape_motion_context;

#pragma push
#pragma scheduling off
#pragma opt_common_subs off
#pragma peephole off

void draw_shape_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, NJS_MOTION *shape, f32 frame, ModelDrawCallback draw_model) {
    ModelDrawContext *p = model_draw_context;
    bind_motion_context(motion, frame);
    p->draw = draw_model;
    if (shape == NULL) {
        draw_motion_node_tree_with_context(model);
        return;
    }
    select_shape_motion_context(0);
    bind_shape_motion(shape, frame);
    draw_shape_motion_node_tree(model);
}

// Draws node, its siblings and their children, each chunk model with its
// vertex list replaced by the one the shape motion gives for the node.
void draw_shape_motion_node_tree(NJS_OBJECT *node) {
    void *vertices;
    ModelDrawContext *ctx;
    NJS_CNK_MODEL *model;
    void *saved;
    ctx = model_draw_context;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (!(node->evalflags & 0x80)) {
            model = (NJS_CNK_MODEL *)node->model;
            if (model != NULL && !(node->evalflags & 8)) {
                sample_shape_node_vertices(&model->vertex_list, &vertices);
                saved = model->vertex_list;
                model->vertex_list = vertices;
                ctx->draw(model);
                model->vertex_list = saved;
            } else {
                advance_shape_motion_row();
            }
        } else if (node->model != NULL && !(node->evalflags & 8)) {
            ctx->draw(node->model);
        }
        if (node->child != NULL) {
            draw_shape_motion_node_tree(node->child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}

#pragma push
#pragma optimize_for_size off
#pragma opt_common_subs on
// Stores in *dst the vertex list src blended by the current row's vertex and
// normal keys, or src itself when the row has neither.
void sample_shape_vertices(void **src, void **dst) {
    u32 normal_key_count;
    u32 vertex_key_count;
    void *vertex_keys;
    void *normal_keys;

    if (*src == NULL) {
        *dst = NULL;
        return;
    }
    if (current_shape_motion_context->type & NJD_MTYPE_VERT_4) {
        vertex_keys = current_shape_motion_context->keys[current_shape_motion_context->channel];
        if (vertex_keys != NULL) {
            vertex_key_count = current_shape_motion_context->key_counts[current_shape_motion_context->channel];
        }
        current_shape_motion_context->channel++;
    } else {
        vertex_keys = NULL;
    }
    if (current_shape_motion_context->type & NJD_MTYPE_NORM_5) {
        normal_keys = current_shape_motion_context->keys[current_shape_motion_context->channel];
        if (normal_keys != NULL) {
            normal_key_count = current_shape_motion_context->key_counts[current_shape_motion_context->channel];
        }
        current_shape_motion_context->channel++;
    } else {
        normal_keys = NULL;
    }
    if (vertex_keys != NULL || normal_keys != NULL) {
        interpolate_shape_vertices(vertex_keys, vertex_key_count, normal_keys, normal_key_count,
                                   current_shape_motion_context->frame, (u32 *)*src, dst);
        return;
    }
    *dst = *src;
}

#pragma pop

#pragma push
#pragma use_lmw_stmw off
// Copies the chunk vertex list src into shape_vertex_buffer with its
// positions and normals interpolated between the keys around frame, and
// stores the copy in *out.
void interpolate_shape_vertices(void *vertex_keys, u32 vertex_key_count, void *normal_keys, u32 normal_key_count,
                                f32 frame, u32 *src, void **out) {
    f32 *vertex0;
    f32 *normal0;
    f32 *vertex1;
    f32 *normal1;
    f32 vertex_weight;
    f32 normal_weight;
    f32 vertex_rate;
    NJS_MKEY_P *vertex_key0;
    NJS_MKEY_P *vertex_key1;
    f32 normal_rate;
    NJS_MKEY_P *normal_key0;
    NJS_MKEY_P *normal_key1;
    u32 *s;
    u32 head;
    u32 *p;
    u32 *d;
    u32 size;
    s32 count;
    s32 has_position;
    s32 has_normal;
    s32 has_color;
    s32 has_flags;
    s32 i;
    if (vertex_keys != NULL) {
        find_motion_key_interval(vertex_keys, sizeof(NJS_MKEY_P), vertex_key_count, frame, &vertex_key0, &vertex_key1, &vertex_rate);
        vertex_weight = 1.0f - vertex_rate;
        vertex0 = vertex_key0->key;
        vertex1 = vertex_key1->key;
    }
    if (normal_keys != NULL) {
        find_motion_key_interval(normal_keys, sizeof(NJS_MKEY_P), normal_key_count, frame, &normal_key0, &normal_key1, &normal_rate);
        normal_weight = 1.0f - normal_rate;
        normal0 = normal_key0->key;
        normal1 = normal_key1->key;
    }
    p = src;
    *out = d = shape_vertex_buffer;
    for (;;) {
        head = p[0];
        if ((u8)head == NJD_CE) {
            *d = head;
            return;
        }
        size = head >> 16;
        count = p[1] >> 16;
        switch ((u8)head) {
        case NJD_CV:
            has_position = 1; has_normal = 0; has_color = 0; has_flags = 0;
            break;
        case NJD_CV_D8:
            has_position = 1; has_normal = 0; has_color = 1; has_flags = 0;
            break;
        case NJD_CV_UF:
            has_position = 1; has_normal = 0; has_color = 0; has_flags = 1;
            break;
        case NJD_CV_VN:
            has_position = 1; has_normal = 1; has_color = 0; has_flags = 0;
            break;
        case NJD_CV_VN_D8:
            has_position = 1; has_normal = 1; has_color = 1; has_flags = 0;
            break;
        case NJD_CV_VN_UF:
            has_position = 1; has_normal = 1; has_color = 0; has_flags = 1;
            break;
        case NJD_CV_VN_NF:
            has_position = 1; has_normal = 1; has_color = 0; has_flags = 1;
            break;
        default:
            has_position = 0; has_normal = 0; has_color = 0; has_flags = 0;
            break;
        }
        d[0] = head;
        d[1] = p[1];
        s = p + 2;
        d += 2;
        for (i = 0; i < count; i++) {
            if (has_position != 0) {
                f32 *dst = (f32 *)d;
                if (vertex_keys != NULL) {
                    dst[0] = vertex0[0] * vertex_weight + vertex1[0] * vertex_rate;
                    dst[1] = vertex0[1] * vertex_weight + vertex1[1] * vertex_rate;
                    dst[2] = vertex0[2] * vertex_weight + vertex1[2] * vertex_rate;
                    vertex0 += 3;
                    vertex1 += 3;
                } else {
                    f32 *from = (f32 *)s;
                    dst[0] = from[0];
                    dst[1] = from[1];
                    dst[2] = from[2];
                }
                d += 3;
                s += 3;
            }
            if (has_normal != 0) {
                f32 *dst = (f32 *)d;
                if (normal_keys != NULL) {
                    dst[0] = normal0[0] * normal_weight + normal1[0] * normal_rate;
                    dst[1] = normal0[1] * normal_weight + normal1[1] * normal_rate;
                    dst[2] = normal0[2] * normal_weight + normal1[2] * normal_rate;
                    normal0 += 3;
                    normal1 += 3;
                } else {
                    f32 *from = (f32 *)s;
                    dst[0] = from[0];
                    dst[1] = from[1];
                    dst[2] = from[2];
                }
                d += 3;
                s += 3;
            }
            if (has_color != 0) {
                *d++ = *s++;
            }
            if (has_flags != 0) {
                *d++ = *s++;
            }
        }
        p += size + 1;
    }
}
#pragma pop

// Starts the first row of the current shape motion; each row holds
// `channels` key pointers and then `channels` key counts.
void set_shape_motion_row_stride(s32 channels) {
    s32 size = channels * 4;
    u8 *row;
    current_shape_motion_context->key_list_size = size;
    current_shape_motion_context->row_size = size + size;
    row = current_shape_motion_context->row;
    current_shape_motion_context->keys = (void **)row;
    current_shape_motion_context->key_counts = (u32 *)(row + current_shape_motion_context->key_list_size);
    current_shape_motion_context->channel = 0;
}
#pragma pop

#pragma push
#pragma scheduling off
// Moves to the next node's row.
void advance_shape_motion_row() {
    u8 *row = current_shape_motion_context->row;
    row += current_shape_motion_context->row_size;
    current_shape_motion_context->row = row;
    current_shape_motion_context->keys = (void **)row;
    current_shape_motion_context->key_counts = (u32 *)(row + current_shape_motion_context->key_list_size);
    current_shape_motion_context->channel = 0;
}
#pragma pop

#pragma push
#pragma scheduling off
// Points the current shape context at shape's first row at frame.
void bind_shape_motion(NJS_MOTION *shape, f32 frame) {
    current_shape_motion_context->row = (u8 *)shape->mdata;
    current_shape_motion_context->frame_count = shape->nbFrame;
    current_shape_motion_context->frame = frame;
    current_shape_motion_context->channel = 0;
    current_shape_motion_context->type = shape->type;
    set_shape_motion_row_stride(shape->inp_fn & ~0xC0);
}
#pragma pop

void select_shape_motion_context(s32 index) {
    current_shape_motion_context = &shape_motion_contexts[index];
}

ShapeMotionContext shape_motion_contexts[2];

void set_shape_vertex_buffer(u32 *buffer) {
    shape_vertex_buffer = buffer;
}

void sample_shape_node_vertices(void **src, void **dst) {
    sample_shape_vertices(src, dst);
    advance_shape_motion_row();
}

#pragma push
#pragma use_lmw_stmw off
void draw_chunk_color_tex_strips(s16 *list, ChunkCachedVertex *verts, u32 flags, s32 big) {
    s32 draw;
    u32 count;
    s32 extra;
    s32 n;

    draw = 1;
    extra = (flags >> 14) & 3;
    count = flags & 0x3FFF;
    if (chunk_render_flags != 0) {
        if (chunk_render_flags & 1) {
            if (chunk_render_flags & 0x200) {
                clear_chunk_strip_blend_flags();
                draw = 0;
            }
        } else if ((chunk_render_flags & 2) && (chunk_render_flags & 0x400)) {
            clear_chunk_strip_blend_flags();
            draw = 0;
        }
    }
    clear_chunk_strip_blend_flags();
    GXClearVtxDesc();
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, big ? 0xC : 8);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
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
            ChunkCachedVertex *v = &verts[list[0]];
            u32 c;
            s16 s = list[1];
            s16 t = list[2];
            list += 3;
            if (draw) {
                f32 x;
                f32 y;
                f32 z;
                z = v->pos.z;
                y = v->pos.y;
                x = v->pos.x;
                GXWGFifo.f32 = x;
                GXWGFifo.f32 = y;
                GXWGFifo.f32 = z;
                c = v->color;
                GXWGFifo.u32 = ((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24);
                GXWGFifo.s16 = s;
                GXWGFifo.s16 = t;
            }
            list += extra;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop
