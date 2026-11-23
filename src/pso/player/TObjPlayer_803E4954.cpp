#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"

struct Node_803E49FC {
    u32 flags;
    u32 f4;
    u8 pad8[0x2C - 0x8];
    struct Node_803E49FC *child;
    struct Node_803E49FC *next;
};

void draw_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame, ModelDrawCallback draw_model);
void draw_chunk_model_with_shape_motion(void *child, void *motion, NJS_MOTION *shape, f32 frame);
void compose_motion_node_matrix(void *arg0);
void draw_model_blend_motion(void *model, void *motion, f32 blend_factor);
void draw_object_tree_recursive(void *arg);
void traverse_animated_node_tree(void *arg);
extern s32 chunk_render_flags;

void TObjPlayer::clear_move_state_bits() {
    chunk_render_flags &= 0xFFFFF9FF;
}

extern s32 (*player_chunk_draw_end_callback)();

void TObjPlayer::set_global_state(saddr arg0) {
    player_chunk_draw_end_callback = (s32 (*)())arg0;
}

s32 motion_packed_rotation_mode;

void draw_blend_motion_tree(NJS_OBJECT *model, NJS_MOTION_LINK *motion, f32 blend_factor, ModelDrawCallback draw_model) {
    bind_motion_blend_channels(motion, blend_factor);
    if ((s32) motion_packed_rotation_mode != 0) {
        select_motion_context(1);
        current_motion_context->sample_angle_keys = motion_angle_sampler_table[3];
        select_motion_context(0);
        current_motion_context->sample_angle_keys = motion_angle_sampler_table[3];
    }
    model_draw_context->draw = draw_model;
    draw_object_tree_recursive(model);
}

void draw_object_tree_recursive(void *arg) {
    struct Node_803E49FC *arg0 = (struct Node_803E49FC *)arg;
    uaddr t;
    do {
        push_matrix();
        apply_motion_node_transform((NJS_OBJECT *)arg0);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(reinterpret_cast<NJS_OBJECT *>(arg0));
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
    TObjPlayer::setup_model_draw_state(model);
    draw_blend_motion_tree((NJS_OBJECT *)model, (NJS_MOTION_LINK *)motion, blend_factor, TObjPlayer::draw_chunk_vertices_cached);
    TObjPlayer::end_chunk_draw();
}

void draw_model_motion(void *model, void *motion, f32 frame) {
    TObjPlayer::setup_model_draw_state(model);
    draw_motion_tree((NJS_OBJECT *)model, (NJS_MOTION *)motion, frame, TObjPlayer::draw_chunk_vertices_cached);
    TObjPlayer::end_chunk_draw();
}

void draw_chunk_model_with_shape_motion(void *child, void *motion, NJS_MOTION *shape, f32 frame) {
    TObjPlayer::setup_model_draw_state(child);
    draw_shape_motion_tree((NJS_OBJECT *)child, (NJS_MOTION *)motion, shape, frame, TObjPlayer::draw_chunk_vertices_cached);
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
        current_motion_context->sample_angle_keys = motion_angle_sampler_table[3];
    }
    traverse_animated_node_tree(model);
}
void traverse_animated_node_tree(void *arg) {
    struct Node_803E49FC *arg0 = (struct Node_803E49FC *)arg;
    uaddr t;
    do {
        push_matrix();
        compose_motion_node_matrix(arg0);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(reinterpret_cast<NJS_OBJECT *>(arg0));
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
