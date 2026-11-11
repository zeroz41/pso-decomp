#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803E2F28.h"

s32 MaterialColorFade::has_visible_opacity() {
    return color.a > -1.0f;
}

void MaterialColorFade::clear_flag_and_notify() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
}

void MaterialColorFade::set_flags_and_apply_damage_color() {
    model_render_flags |= 0x8820;
    set_constant_material(&color);
    set_chunk_material_override_pair(0xFF00, 0x800);
}

s32 MaterialColorFade::advance_toward_max() {
    f32 a;
    s32 done;

    a = color.a;
    done = 0;
    if (a < 0.0f) {
        color.a = a + rate;
    } else {
        color.a = 0.0f;
        done = 1;
    }
    return done;
}

s32 MaterialColorFade::decay_value_toward_floor() {
    f32 a;
    s32 done;

    a = color.a;
    done = 0;
    if (a > -1.0f) {
        color.a = a - rate;
    } else {
        color.a = -1.0f;
        done = 1;
    }
    return done;
}

void MaterialColorFade::reset_obstruction_fade() {
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

void MaterialColorFade::reset_color() {
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

void MaterialColorFade::set_rate_from_divisor(s32 divisor) {
    rate = 1.0f / (f32)divisor;
}

MaterialColorFade::~MaterialColorFade() {}

MaterialColorFade::MaterialColorFade() {
    rate = 0.04f;
    reset_color();
}
