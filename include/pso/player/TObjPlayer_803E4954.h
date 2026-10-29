#ifndef PSO_PLAYER_TOBJPLAYER_803E4954_H
#define PSO_PLAYER_TOBJPLAYER_803E4954_H

#include "types.h"

extern "C" {
// Draws model posed by motion and deformed by shape (a Ninja shape motion) at frame.
void draw_chunk_model_with_shape_motion(void *model, void *motion, void *shape, f32 frame);
void draw_blend_motion_tree__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
}
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
void draw_motion_tree__10TObjPlayerFPvPvi(void *arg0, void *arg1, s32 arg2);
}
s32 draw_object_tree_recursive(void *arg);
void traverse_animated_node_tree(void *arg);

#endif
