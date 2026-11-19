#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"

typedef void (*RecoveredCallback_1268626c296b)(void *);
struct Node_803E49FC {
    u32 flags;
    u32 f4;
    u8 pad8[0x2C - 0x8];
    struct Node_803E49FC *child;
    struct Node_803E49FC *next;
};

extern "C" {
s32 setup_model_draw_state__10TObjPlayerFPv();
}
struct B_803E4BDC { u8 pad[0x28]; s32 f28; };
void draw_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame, ModelDrawCallback draw_model);
extern void *motion_angle_sampler_table[];
extern B_803E4BDC *current_motion_context;
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
}
void draw_chunk_model_with_shape_motion(void *arg0, void *arg1, NJS_MOTION *arg2, f32 farg0);
void compose_motion_node_matrix(void *arg0);
void select_motion_context(s32 arg0);
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern RecoveredCallback_1268626c296b chunk_model_node_callback;
void draw_object_tree_recursive(void *arg);
void traverse_animated_node_tree(void *arg);
extern s32 chunk_render_flags;

void TObjPlayer::clear_move_state_bits() {
    chunk_render_flags &= 0xFFFFF9FF;
}

extern s32 (*player_chunk_draw_end_callback)();

void TObjPlayer::set_global_state(s32 arg0) {
    player_chunk_draw_end_callback = (s32 (*)())arg0;
}

s32 motion_packed_rotation_mode;

void draw_blend_motion_tree(NJS_OBJECT *model, NJS_MOTION_LINK *motion, f32 blend_factor, ModelDrawCallback draw_model) {
    bind_motion_blend_channels(motion, blend_factor);
    if ((s32) motion_packed_rotation_mode != 0) {
        select_motion_context(1);
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)motion_angle_sampler_table + 0xC);
        select_motion_context(0);
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)motion_angle_sampler_table + 0xC);
    }
    model_draw_context->draw = draw_model;
    draw_object_tree_recursive(model);
}

void draw_object_tree_recursive(void *arg) {
    struct Node_803E49FC *arg0 = (struct Node_803E49FC *)arg;
    u32 t;
    do {
        push_matrix();
        ((TObjPlayer *)arg0)->apply_motion_node_transform();
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(arg0);
        }
        t = arg0->f4;
        if (t != 0 && (arg0->flags & 8) == 0) {
            model_draw_context->draw((void *)t);
        }
        if (arg0->child != NULL) {
            draw_object_tree_recursive((void *)arg0->child);
        }
        pop_matrix();
        arg0 = arg0->next;
    } while (arg0 != NULL);
}

void draw_model_blend_motion(void *model, void *motion, f32 blend_factor) {
    setup_model_draw_state__10TObjPlayerFPv();
    draw_blend_motion_tree((NJS_OBJECT *)model, (NJS_MOTION_LINK *)motion, blend_factor, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void draw_model_motion(void *model, void *motion, f32 frame) {
    setup_model_draw_state__10TObjPlayerFPv();
    draw_motion_tree((NJS_OBJECT *)model, (NJS_MOTION *)motion, frame, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void draw_chunk_model_with_shape_motion(void *child, void *motion, NJS_MOTION *shape, f32 frame) {
    setup_model_draw_state__10TObjPlayerFPv();
    draw_shape_motion_tree((NJS_OBJECT *)child, (NJS_MOTION *)motion, shape, frame, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void set_motion_packed_rotation() {
    motion_packed_rotation_mode = 1;
}

void clear_motion_packed_rotation() {
    motion_packed_rotation_mode = 0;
}
void draw_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame, ModelDrawCallback draw_model) {
    bind_motion_context(motion, frame);
    model_draw_context->draw = draw_model;
    if (motion_packed_rotation_mode != 0) {
        current_motion_context->f28 = (s32)motion_angle_sampler_table[3];
    }
    traverse_animated_node_tree(model);
}
void traverse_animated_node_tree(void *arg) {
    struct Node_803E49FC *arg0 = (struct Node_803E49FC *)arg;
    u32 t;
    do {
        push_matrix();
        compose_motion_node_matrix(arg0);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(arg0);
        }
        t = arg0->f4;
        if (t != 0 && (arg0->flags & 8) == 0) {
            model_draw_context->draw((void *)t);
        }
        if (arg0->child != NULL) {
            traverse_animated_node_tree((void *)arg0->child);
        }
        pop_matrix();
        arg0 = arg0->next;
    } while (arg0 != NULL);
}
