#include "pso/render/GinjaMaterial.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTextureMatrices.h"

typedef void (*RecoveredCallback_2be3cacebb2e)(void);

struct Mtx_803DC994 { f32 m[3][4]; };

struct C_803DCBF0 { u32 a; u32 b; u32 c; u32 d; u32 e; u32 f; u32 g; u32 h; u32 i; };

typedef void (*RecoveredCallback_1268626c296b)(void *);

struct Tbl_803DCC34 { u32 v[12]; };

extern GinjaSceneState render_contexts[6];
ModelNodeCallback model_node_callback;
void flush_model_draw_queue(void);
extern "C" {

extern RecoveredCallback_2be3cacebb2e ginja_draw_end_callback;
void copy_rotation_to_current_matrix(struct Mtx_803DC994 *src);
void GXSetBlendMode(int, int, int, int);
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[];
void init_render_context(C_803DCBF0 *arg0);
extern RecoveredCallback_1268626c296b motion_node_draw_callback;
__declspec(section ".rodata") extern const Tbl_803DCC34 gx_blend_mode_table;
s32 rotate_matrix_by_node_angles(void *, void *);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern GC_Mtx node_saved_matrix;
void set_model_node_callback(ModelNodeCallback callback) {
    model_node_callback = callback;
}

void draw_ginja_model_with_motion(void *model, void *motion, f32 frame) {
    bind_motion_context((NJS_MOTION *)motion, frame);
    model_draw_context->draw = draw_ginja_model_lists;
    prepare_ginja_model();
    init_model_draw_queue(draw_ginja_model_lists);
    draw_ginja_motion_node_tree((NJS_OBJECT *)model);
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

void copy_rotation_to_current_matrix(struct Mtx_803DC994 *src) {
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

struct Mtx_803DC994;
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
                    copy_rotation_to_current_matrix(reinterpret_cast<struct Mtx_803DC994 *>(&node_saved_matrix));
                } else if (f & 0x400) {
                    apply_quat_rotation(node->quat_w, (f32 *)node->ang);
                } else {
                    rotate_matrix_by_node_angles(node->ang, (void *) (f & 0x20));
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

void select_render_context(s32 arg0) {
    current_render_context = &render_contexts[arg0];
}

void init_render_context(C_803DCBF0 *arg0) {
    arg0->a = 0x808C0000;
    arg0->c = 0;
    arg0->d = 0x949004C0;
    arg0->e = 0x80012;
    arg0->f = -1;
    arg0->g = -1;
    arg0->h = 0x20000000;
    arg0->i = 0;
}

void set_color_blending_mode(s32 target, s32 mode) {
    Tbl_803DCC34 tbl = gx_blend_mode_table;
    if (mode == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x03FFFFFF) | 0xB0000000;
    } else if (mode == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x03FFFFFF) | 0x94000000;
    } else if (target == 0) {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0x1FFFFFFF) | (tbl.v[mode] << 29);
    } else {
        current_render_context->blend_mode = (current_render_context->blend_mode & 0xE3FFFFFF) | (tbl.v[mode] << 26);
    }
}

void apply_cached_blend_mode(s32 arg0) {
    u32 v = current_render_context->blend_mode;
    int src = cached_blend_factor_table[(v & 0xE0000000) >> 29];
    int dst = cached_blend_factor_table[(v & 0x1C000000) >> 26];
    if (arg0 != 0) {
        GXSetBlendMode(1, src, dst, 0);
    } else {
        GXSetBlendMode(0, src, dst, 0);
    }
}

__declspec(section ".rodata") extern const Tbl_803DCC34 gx_blend_mode_table = {{255, 255, 6, 2, 7, 3, 5, 3, 4, 2, 1, 0}};
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[8] = {0, 1, 2, 3, 4, 5, 6, 7};


GC_Mtx node_saved_matrix;

