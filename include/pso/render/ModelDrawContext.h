#ifndef PSO_RENDER_MODELDRAWCONTEXT_H
#define PSO_RENDER_MODELDRAWCONTEXT_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
void apply_cached_blend_mode(s32 enable_blend);
// Draws a model posed by motion at the given frame.
void draw_ginja_model_with_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);
#ifdef __cplusplus
}
#endif
// Called with every node draw_ginja_motion_node_tree visits (0 = none).
typedef void (*ModelNodeCallback)(NJS_OBJECT *node);
#ifdef __cplusplus
void draw_ginja_motion_node_tree(NJS_OBJECT *node);
#endif
// Called for every node draw_ginja_motion_node_tree visits (NULL: none); init_projection_state clears it.
extern ModelNodeCallback motion_node_draw_callback;
#ifdef __cplusplus
extern "C" {
#endif
void select_render_context(s32 index);
void set_model_node_callback(ModelNodeCallback callback);
// Walks a node tree like draw_ginja_motion_node_tree, without motion, handing each model to draw.
void traverse_model_node_tree(NJS_OBJECT *node, s32 (*draw)(void *model));
#ifdef __cplusplus
}
#endif
extern ModelNodeCallback model_node_callback;
#ifdef __cplusplus
// Sets the source (target 0) or destination (target 1) blend factor of the
// current render context. Modes: 2 dest alpha, 3 dest color, 4 inv dest alpha,
// 5 inv dest color, 6 inv src alpha, 7 inv src color, 8 src alpha, 9 src color,
// 10 one, 11 zero.
void set_color_blending_mode(s32 target, s32 mode);
#endif

// The blend factor index of each colour blending mode, copied whole by set_color_blending_mode.
struct BlendModeFactorTable { u32 factor[12]; };

#endif
