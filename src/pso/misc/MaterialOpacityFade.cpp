#include "pso/misc/MaterialOpacityFade.h"
#include "pso/unk/text_803E2D70.h"

s32 MaterialOpacityFade::has_partial_opacity() {
    return opacity > 0.0f && opacity < 2.0f;
}

s32 MaterialOpacityFade::has_visible_opacity() {
    return opacity > 0.0f;
}

void MaterialOpacityFade::set_flags_and_apply_damage_color() {
    MaterialColorFade::set_flags_and_apply_damage_color();
    set_chunk_blend(0x2100);
}

s32 MaterialOpacityFade::advance_to(f32 target) {
    opacity += rate;
    update_alpha();
    return opacity >= target;
}

s32 MaterialOpacityFade::advance_toward_max() {
    opacity += rate;
    update_alpha();
    return opacity >= 2.0f;
}

s32 MaterialOpacityFade::decay_value_toward_floor() {
    opacity -= rate;
    update_alpha();
    return opacity <= 0.0f;
}

void MaterialOpacityFade::update_alpha() {
    f32 current = opacity;
    if (current <= 0.0f) {
        color.a = -1.0f;
        return;
    }
    if (current < 2.0f) {
        color.a = current - 1.0f;
        if (color.a == 0.0f) {
            color.a = 0.01f;
        }
        return;
    }
    color.a = 1.0f;
}

#pragma push
#pragma optimization_level 0
void MaterialOpacityFade::set_color(const NJS_ARGB *source) {
    opacity = source->a;
    color.a = source->a;
    color.r = source->r;
    color.g = source->g;
    color.b = source->b;
}

#pragma pop

void MaterialOpacityFade::reset_obstruction_fade() {
    opacity = 0.0f;
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

void MaterialOpacityFade::reset_color() {
    opacity = 2.0f;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

void MaterialOpacityFade::set_rate(f32 value) {
    rate = value;
}

void MaterialOpacityFade::set_rate_from_divisor(s32 divisor) {
    rate = 2.0f / (f32)divisor;
}

#pragma push
#pragma fp_contract on
void MaterialOpacityFade::start_fade_out() {
    set_rate_from_divisor(10);
    opacity = 10.0f * rate + 2.0f;
    color.a = 1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}
#pragma pop

void MaterialOpacityFade::start_fade_in() {
    set_rate_from_divisor(10);
    opacity = -(30.0f * rate);
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

MaterialOpacityFade::~MaterialOpacityFade() {}

MaterialOpacityFade::MaterialOpacityFade() : opacity(0.0f) {}
