#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include <stdlib.h>
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"

// Its own TU: the u32-to-float bias double and the 1/32768 scale are pooled again here, after
// TObjDFJisin's copies of both.
s32 TBoss4Type2::pick_weighted_random(s32 n, f32 *w, s32 *t) {
    s32 i;
    f32 acc;
    f32 r;
    r = 3.0517578e-05f * (f32)rand();
    acc = w[0];
    for (i = 0; i < n - 1; i++) {
        if (r < acc) {
            return t[i];
        }
        acc += w[i];
    }
    return t[n - 1];
}

void end_alpha_blend() {
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

// Draws what follows with the constant material faded to `alpha` (0..1);
// end_alpha_blend restores the render flags it saves.
void begin_alpha_blend(f32 alpha) {
    NJS_ARGB color;
    u32 flags = model_render_flags;
    model_render_flags = flags & ~0x10;
    saved_model_render_flags = flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= alpha_blend_render_flags;
    set_chunk_material_override_pair(0xFF00, 0x800);
    color.a = alpha_blend_alpha_bias + alpha;
    color.r = color.g = color.b = alpha_blend_color;
    set_constant_material(&color);
}

__declspec(section ".sdata2") extern const f32 alpha_blend_color = 0.0f;
__declspec(section ".sdata2") extern const f32 boss4_float_one = 1.0f;
__declspec(section ".sdata2") extern const f32 boss4_float_half = 0.5f;
__declspec(section ".sdata2") extern const u32 alpha_blend_render_flags = 0x00008829;
__declspec(section ".sdata2") extern const f32 alpha_blend_alpha_bias = -1.0f;
__declspec(section ".sdata2") extern const f32 boss4_half_turn_scale = 32768.0f;
