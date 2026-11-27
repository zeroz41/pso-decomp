#include "pso/render/GinjaMaterial.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/render/DebugFont.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/system/MatrixStack.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXStruct.h>
#include <dolphin/gx/GXPixel.h>
#undef PSO_SDK_COMPACT_MATH


// Defined at the end of the unit.
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[];
__declspec(section ".rodata") extern const BlendModeFactorTable gx_blend_mode_table;
extern GC_Mtx node_saved_matrix;

ModelNodeCallback model_node_callback;
extern "C" {

void set_model_node_callback(ModelNodeCallback callback) {
    model_node_callback = callback;
}

void draw_ginja_model_with_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    bind_motion_context(motion, frame);
    model_draw_context->draw = draw_ginja_model_lists;
    prepare_ginja_model();
    init_model_draw_queue(draw_ginja_model_lists);
    draw_ginja_motion_node_tree(model);
    flush_model_draw_queue();
    if (ginja_draw_end_callback != NULL) {
        ginja_draw_end_callback();
    }
}
}
#pragma push
#pragma peephole off
#pragma scheduling off
void draw_ginja_motion_node_tree(NJS_OBJECT *node) {
    void *model;
    NJS_OBJECT *child;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (model_node_callback != NULL) {
            model_node_callback(node);
        }
        model = node->model;
        if (model != NULL && (node->evalflags & 8) == 0) {
            queue_model_draw_matrix(model, *current_matrix);
        }
        child = node->child;
        if (child != NULL) {
            draw_ginja_motion_node_tree(child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}
#pragma pop

void copy_rotation_to_current_matrix(const GC_Mtx *src) {
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

void traverse_model_node_tree(NJS_OBJECT *node, s32 (*draw)(void *model)) {
    do {
        uaddr f = node->evalflags;
        if (f & 0x800) {
            get_current_matrix(&node_saved_matrix);
        }
        if ((f & 7) == 7) {
            if (!(f & 8)) {
                draw(node->model);
            }
            if (!(f & 0x10)) {
                traverse_model_node_tree(node->child, draw);
            }
        } else {
            push_matrix();
            if (!(f & 1)) {
                post_translate_matrix(node->pos);
            }
            if (!(f & 2)) {
                if (f & 0x1000) {
                    copy_rotation_to_current_matrix(&node_saved_matrix);
                } else if (f & 0x400) {
                    apply_quat_rotation(node->quat_w, (f32 *)node->ang);
                } else {
                    rotate_matrix_by_node_angles(node->ang, f & 0x20);
                }
            }
            if (!(f & 4)) {
                scale_current_matrix(node->scl);
            }
            if (!(f & 8)) {
                draw(node->model);
            }
            if (!(f & 0x10)) {
                traverse_model_node_tree(node->child, draw);
            }
            pop_matrix();
        }
        node = node->sibling;
    } while (node != NULL);
}

void draw_motion_node_tree_with_context(NJS_OBJECT *node) {
    void *t;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (motion_node_draw_callback != NULL) {
            motion_node_draw_callback(node);
        }
        t = node->model;
        if (t != 0 && (node->evalflags & 8) == 0) {
            model_draw_context->draw(t);
        }
        if (node->child != NULL) {
            draw_motion_node_tree_with_context(node->child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}

void select_render_context(s32 index) {
    current_render_context = &render_contexts[index];
}

void init_render_context(GinjaSceneState *context) {
    context->reserved00 = 0x808C0000;
    context->texture_header = NULL;
    context->blend_mode = 0x949004C0;
    context->reserved10 = 0x80012;
    context->reserved14 = -1;
    context->tlut_name = -1;
    context->reserved1C = 0x20000000;
    context->textures = NULL;
}

void set_color_blending_mode(s32 target, s32 mode) {
    BlendModeFactorTable tbl = gx_blend_mode_table;
    if (mode == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x03FFFFFF) | 0xB0000000;
    } else if (mode == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x03FFFFFF) | 0x94000000;
    } else if (target == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x1FFFFFFF) | (tbl.factor[mode] << 29);
    } else {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0xE3FFFFFF) | (tbl.factor[mode] << 26);
    }
}

void apply_cached_blend_mode(s32 enable_blend) {
    u32 v = current_render_context->blend_mode;
    int src = cached_blend_factor_table[(v & 0xE0000000) >> 29];
    int dst = cached_blend_factor_table[(v & 0x1C000000) >> 26];
    if (enable_blend != 0) {
        GXSetBlendMode(GX_BM_BLEND, (GXBlendFactor)src, (GXBlendFactor)dst, GX_LO_CLEAR);
    } else {
        GXSetBlendMode(GX_BM_NONE, (GXBlendFactor)src, (GXBlendFactor)dst, GX_LO_CLEAR);
    }
}

__declspec(section ".rodata") extern const BlendModeFactorTable gx_blend_mode_table = {{255, 255, 6, 2, 7, 3, 5, 3, 4, 2, 1, 0}};
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[8] = {0, 1, 2, 3, 4, 5, 6, 7};


GC_Mtx node_saved_matrix;

