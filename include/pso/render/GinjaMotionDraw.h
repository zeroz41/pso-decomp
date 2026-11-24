#ifndef PSO_RENDER_GINJAMOTIONDRAW_H
#define PSO_RENDER_GINJAMOTIONDRAW_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// Draw a Ginja model posed by a motion at a frame.
void draw_ginja_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);
// Draw each node of a model tree at its current motion pose (apply_motion_node_transform).
void render_model_tree(NJS_OBJECT *model);
// Draw each node of a model tree at its composed motion matrix (compose_motion_node_matrix).
void render_matrix_chain(NJS_OBJECT *model);

#endif
