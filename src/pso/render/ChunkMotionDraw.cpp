#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"

struct Node_803E49FC {
    u32 flags;
    u32 f4;
    u8 pad8[0x2C - 0x8];
    struct Node_803E49FC *child;
    struct Node_803E49FC *next;
};


void clear_chunk_strip_blend_flags() {
    chunk_render_flags &= 0xFFFFF9FF;
}

extern void (*player_chunk_draw_end_callback)();

void set_chunk_draw_end_callback(void (*callback)()) {
    player_chunk_draw_end_callback = callback;
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

void draw_object_tree_recursive(void *object) {
    struct Node_803E49FC *node = (struct Node_803E49FC *)object;
    uaddr t;
    do {
        push_matrix();
        apply_motion_node_transform((NJS_OBJECT *)node);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(reinterpret_cast<NJS_OBJECT *>(node));
        }
        t = node->f4;
        if (t != 0 && (node->flags & 8) == 0) {
            model_draw_context->draw((void *)t);
        }
        if (node->child != NULL) {
            draw_object_tree_recursive((void *)node->child);
        }
        pop_matrix();
        node = node->next;
    } while (node != NULL);
}

void draw_model_blend_motion(void *model, void *motion, f32 blend_factor) {
    setup_model_draw_state(model);
    draw_blend_motion_tree((NJS_OBJECT *)model, (NJS_MOTION_LINK *)motion, blend_factor, draw_chunk_vertices_cached);
    end_chunk_draw();
}

void draw_model_motion(void *model, void *motion, f32 frame) {
    setup_model_draw_state(model);
    draw_motion_tree((NJS_OBJECT *)model, (NJS_MOTION *)motion, frame, draw_chunk_vertices_cached);
    end_chunk_draw();
}

void draw_chunk_model_with_shape_motion(void *child, void *motion, NJS_MOTION *shape, f32 frame) {
    setup_model_draw_state(child);
    draw_shape_motion_tree((NJS_OBJECT *)child, (NJS_MOTION *)motion, shape, frame, draw_chunk_vertices_cached);
    end_chunk_draw();
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
void traverse_animated_node_tree(void *object) {
    struct Node_803E49FC *node = (struct Node_803E49FC *)object;
    uaddr t;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(reinterpret_cast<NJS_OBJECT *>(node));
        }
        t = node->f4;
        if (t != 0 && (node->flags & 8) == 0) {
            model_draw_context->draw((void *)t);
        }
        if (node->child != NULL) {
            traverse_animated_node_tree((void *)node->child);
        }
        pop_matrix();
        node = node->next;
    } while (node != NULL);
}
