#include "types.h"
#include "pso/player/TObjPlayer.h"

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
void draw_chunk_vertices_cached__10TObjPlayerFPv();
struct A_803E4BDC { u8 pad[0xC]; s32 fc; };
struct B_803E4BDC { u8 pad[0x28]; s32 f28; };
void draw_motion_tree__10TObjPlayerFPvPvi(void *arg0, void *arg1, s32 arg2);
void bind_motion_context(void *);
extern s32 motion_angle_sampler_table[];
extern A_803E4BDC *model_draw_context;
extern B_803E4BDC *current_motion_context;
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
void draw_blend_motion_tree__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
s32 bind_motion_blend_channels(void *);
void draw_motion_bound__10TObjPlayerFiiPvfi(void *, void *, void *, f32, void (*)(void));
void draw_chunk_model_with_shape_motion(void *arg0, void *arg1, void *arg2, f32 farg0);
s32 push_matrix();
s32 pop_matrix();
void compose_motion_node_matrix(void *arg0);
}
void select_motion_context(s32 arg0);
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern RecoveredCallback_1268626c296b chunk_model_node_callback;
s32 draw_object_tree_recursive(void *arg);
void traverse_animated_node_tree(void *arg);
extern s32 chunk_render_flags;

void TObjPlayer::clear_move_state_bits() {
    chunk_render_flags &= 0xFFFFF9FF;
}

extern s32 player_chunk_draw_end_callback;

void TObjPlayer::set_global_state(s32 arg0) {
    player_chunk_draw_end_callback = arg0;
}

extern s32 motion_packed_rotation_mode;

void draw_blend_motion_tree__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2) {
    bind_motion_blend_channels((void *)arg1);
    if ((s32) motion_packed_rotation_mode != 0) {
        select_motion_context(1);
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)motion_angle_sampler_table + 0xC);
        select_motion_context(0);
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)motion_angle_sampler_table + 0xC);
    }
    *(s32 *)((s8 *)model_draw_context + 0xC) = arg2;
    draw_object_tree_recursive((void *)arg0);
}

s32 draw_object_tree_recursive(void *arg) {
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
            ((void (*)(u32, A_803E4BDC *))model_draw_context->fc)(t, model_draw_context);
        }
        if (arg0->child != NULL) {
            draw_object_tree_recursive((void *)arg0->child);
        }
        pop_matrix();
        arg0 = arg0->next;
    } while (arg0 != NULL);
}

void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0) {
    setup_model_draw_state__10TObjPlayerFPv();
    ((s32 (*)(void *, void *, f32, void (*)()))draw_blend_motion_tree__10TObjPlayerFiii)(arg0, arg1, farg0, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void draw_model_motion(void *arg0, void *arg1, f32 farg0) {
    setup_model_draw_state__10TObjPlayerFPv();
    ((s32 (*)(void *, void *, f32, void (*)()))draw_motion_tree__10TObjPlayerFPvPvi)(arg0, arg1, farg0, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void draw_chunk_model_with_shape_motion(void *child, void *arg1, void *arg2, f32 farg0) {
    setup_model_draw_state__10TObjPlayerFPv();
    draw_motion_bound__10TObjPlayerFiiPvfi(child, arg1, arg2, farg0, draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}

void TObjPlayer::set_global_flag() {
    motion_packed_rotation_mode = 1;
}

void TObjPlayer::clear_global_state() {
    motion_packed_rotation_mode = 0;
}
void draw_motion_tree__10TObjPlayerFPvPvi(void *arg0, void *arg1, s32 arg2) {
    bind_motion_context(arg1);
    model_draw_context->fc = arg2;
    if (motion_packed_rotation_mode != 0) {
        current_motion_context->f28 = motion_angle_sampler_table[3];
    }
    traverse_animated_node_tree(arg0);
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
            ((void (*)(u32, A_803E4BDC *))model_draw_context->fc)(t, model_draw_context);
        }
        if (arg0->child != NULL) {
            traverse_animated_node_tree((void *)arg0->child);
        }
        pop_matrix();
        arg0 = arg0->next;
    } while (arg0 != NULL);
}
