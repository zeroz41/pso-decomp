#ifndef PSO_RENDER_MODEL_RENDER_STATE_H
#define PSO_RENDER_MODEL_RENDER_STATE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// Global state the Ginja chunk-model draw reads: render flags, the polygon
// flag masks and the material colour, and the copies code keeps while it
// draws with its own settings.
extern u32 model_render_flags;
extern u32 chunk_polygon_flags_and_mask;
extern u32 chunk_polygon_flags_or_mask;
extern NJS_ARGB model_material_color;
extern NJS_ARGB saved_model_draw_color;
extern u32 lbl_805D5660;
extern u32 lbl_805D5664;
extern u32 lbl_805D5668;

#endif
