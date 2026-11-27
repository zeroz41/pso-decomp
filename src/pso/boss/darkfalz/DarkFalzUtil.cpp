#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include <stdlib.h>
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/boss/darkfalz/DarkFalzUtil.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/math/AngleLookup.h"

// Its own TU: the u32-to-float bias double and the 1/32768 scale are pooled again here, after
// TObjDFJisin's copies of both.
s32 TBoss4Type2::pick_weighted_random(s32 n, f32 *w, s32 *values) {
    s32 i;
    f32 acc;
    f32 r;
    r = 3.0517578e-05f * (f32)rand();
    acc = w[0];
    for (i = 0; i < n - 1; i++) {
        if (r < acc) {
            return values[i];
        }
        acc += w[i];
    }
    return values[n - 1];
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
    color.r = color.g = color.b = 0.0f;
    set_constant_material(&color);
}

// Takes up to `damage` HP from the player in Dark Falz's arena and returns what was taken
// (the arena twin of TBoss6PlotFalz::damage_player_hp).
u32 drain_player_hp(u16 client, u32 damage) {
    u32 drained;
    TObjPlayer *p;
    s32 hp;
    drained = damage;
    if (client == 0xFFFF || (p = get_player_by_client_id(client)) == NULL ||
        is_player_in_boss_area(client) == 0) {
        return 0;
    }
    hp = p->get_actor_hp();
    if (hp < drained) {
        drained = hp;
    }
    if (p->obj_isState2_324() != 0) {
        return drained;
    }
    hp -= drained;
    send_6x2F_change_player_hp(0xFFFF, client, hp);
    p->gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(p, drained));
    return drained;
}

#pragma push
#pragma fp_contract on
f32 ease_out_pow6(f32 t) {
    f32 rest;
    rest = 1.0f - t;
    return -((rest * (rest * (rest * (rest * (rest * rest))))) - 1.0f);
}
#pragma pop

f32 compute_wave_offset(f32 wave) {
    return 0.5f * (1.0f - cos_table_lookup((s32) (boss4_half_turn_scale * wave)));
}

s32 is_player_in_boss_area(u16 id) {
    TObjPlayer *p;
    if (id != 0xFFFF) {
        p = get_player_by_client_id(id);
        if (p != 0 && !(p->actorFlags & 0x2000800) && p->get_area() == 0xE) {
            return 1;
        }
    }
    return 0;
}

__declspec(section ".sdata2") extern const u32 alpha_blend_render_flags = 0x00008829;
__declspec(section ".sdata2") extern const f32 alpha_blend_alpha_bias = -1.0f;
__declspec(section ".sdata2") extern const f32 boss4_half_turn_scale = 32768.0f;
