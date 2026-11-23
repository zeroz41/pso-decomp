#ifndef PSO_PLAYER_TOBJPLAYER_803E4954_H
#define PSO_PLAYER_TOBJPLAYER_803E4954_H

#include "types.h"
#include "pso/system/ModelDrawCallback.h"

struct NJS_OBJECT;
struct NJS_MOTION;
struct NJS_MOTION_LINK;


// Draws model posed by motion and deformed by shape (a Ninja shape motion) at frame.
void draw_chunk_model_with_shape_motion(void *model, void *motion, NJS_MOTION *shape, f32 frame);
void draw_blend_motion_tree(NJS_OBJECT *model, NJS_MOTION_LINK *motion, f32 blend_factor, ModelDrawCallback draw_model);
void draw_shape_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, NJS_MOTION *shape, f32 frame, ModelDrawCallback draw_model);
void draw_model_blend_motion(void *model, void *motion, f32 blend_factor);
extern "C" {
void draw_model_motion(void *model, void *motion, f32 frame);
}
void draw_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame, ModelDrawCallback draw_model);
void draw_object_tree_recursive(void *arg);
// Motions sample packed (16-bit) rotation keys while set.
extern s32 motion_packed_rotation_mode;
void set_motion_packed_rotation();
void clear_motion_packed_rotation();
void traverse_animated_node_tree(void *arg);

#endif
