#ifndef PSO_PLAYER_RENDERMATERIALSTATE_H
#define PSO_PLAYER_RENDERMATERIALSTATE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// A player's saved model draw state (save_render_material_state fills the
// first four fields) and the opacity it is drawn with.
struct RenderMaterialState {
    s32 render_flags;      // model_render_flags
    s32 polygon_and_mask;  // chunk_polygon_flags_and_mask
    s32 polygon_or_mask;   // chunk_polygon_flags_or_mask
    NJS_ARGB color;        // model_material_color
    f32 alpha;             // 1.0 opaque; reset by reset_player_appearance_opacity

    f32 get_alpha();
};

#endif
