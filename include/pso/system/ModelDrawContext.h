#ifndef PSO_SYSTEM_MODELDRAWCONTEXT_H
#define PSO_SYSTEM_MODELDRAWCONTEXT_H

#include "types.h"

extern "C" {
void apply_cached_blend_mode(s32 arg0);
// Draws a model posed by motion at the given frame.
void draw_ginja_model_with_motion(void *model, void *motion, f32 frame);
}
void draw_ginja_motion_node_tree(u8 *arg0);
extern "C" {
void select_render_context(s32 arg0);
void set_model_node_callback(s32 arg0);
}
// Sets the source (target 0) or destination (target 1) blend factor of the
// current render context. Modes: 2 dest alpha, 3 dest color, 4 inv dest alpha,
// 5 inv dest color, 6 inv src alpha, 7 inv src color, 8 src alpha, 9 src color,
// 10 one, 11 zero.
void set_color_blending_mode(s32 target, s32 mode);

#endif
