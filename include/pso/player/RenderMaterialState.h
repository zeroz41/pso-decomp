#ifndef PSO_PLAYER_RENDERMATERIALSTATE_H
#define PSO_PLAYER_RENDERMATERIALSTATE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// A player's model draw state, saved around the body draw (save fills the
// first four fields, restore puts them back), and the constant colour the body
// is drawn with while it is translucent.
struct RenderMaterialState {
    s32 render_flags;      // model_render_flags
    s32 polygon_and_mask;  // chunk_polygon_flags_and_mask
    s32 polygon_or_mask;   // chunk_polygon_flags_or_mask
    NJS_ARGB color;        // model_material_color
    NJS_ARGB fade_color;   // fade_color.a is the opacity, 1.0 opaque

    RenderMaterialState();
    f32 get_alpha();
    void save();
    void restore();
    void reset_fade_color();
    void reset_opacity();
};

#endif
