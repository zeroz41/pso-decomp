#include "types.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer.h"

extern const f32 lbl_805D8ADC;
extern const u32 lbl_805D8AE8;
extern const f32 lbl_805D8AEC;

void TObjPlayer::sync_player_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }

// Draws what follows with the constant material faded to `alpha` (0..1);
// sync_player_globals restores the render flags it saves.
void TObjPlayer::begin_alpha_blend(f32 alpha) {
    NJS_ARGB color;
    u32 flags = model_render_flags;
    model_render_flags = flags & ~0x10;
    saved_model_render_flags = flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= lbl_805D8AE8;
    set_chunk_material_override_pair(0xFF00, 0x800);
    color.a = lbl_805D8AEC + alpha;
    color.r = color.g = color.b = lbl_805D8ADC;
    set_constant_material(&color);
}
