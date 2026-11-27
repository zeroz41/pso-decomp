#include "types.h"
#include "pso/enemy/TObjEnemyColorFade.h"
#include "pso/render/ChunkModelDraw.h"

s32 TObjEnemyColorFade::has_partial_opacity() {
    return value > 0.0f && value < 2.0f;
}

s32 TObjEnemyColorFade::has_visible_opacity() {
    return this->value > 0.0f;
}

void TObjEnemyColorFade::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(8448); }

s32 TObjEnemyColorFade::advance_timer(f32 limit) {
    this->value = this->value + this->rate;
    update_fade_alpha();
    return this->value >= limit;
}

s32 TObjEnemyColorFade::advance_toward_max() {
    this->value = this->value + this->rate;
    update_fade_alpha();
    return this->value >= 2.0f;
}

s32 TObjEnemyColorFade::decay_value_toward_floor() {
    this->value = this->value - this->rate;
    update_fade_alpha();
    return this->value <= 0.0f;
}

void TObjEnemyColorFade::update_fade_alpha() {
    f32 fade_value;
    fade_value = this->value;
    if (fade_value <= 0.0f) {
        this->color.a = -1.0f;
        return;
    }
    if (fade_value < 2.0f) {
        this->color.a = fade_value - 1.0f;
        if (0.0f == this->color.a) {
            this->color.a = 0.01f;
        }
        return;
    }
    this->color.a = 1.0f;
}

void TObjEnemyColorFade::copy_color(NJS_ARGB *src) {
    this->value = src->a;
    this->color.a = src->a;
    this->color.r = src->r;
    this->color.g = src->g;
    this->color.b = src->b;
}

void TObjEnemyColorFade::reset_obstruction_fade() { this->value = 0.0f; this->color.a = -1.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TObjEnemyColorFade::reset_color() { this->value = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TObjEnemyColorFade::set_rate(f32 new_rate) { this->rate = new_rate; }

void TObjEnemyColorFade::set_rate_from_divisor(s32 divisor) {
    this->rate = 2.0f / (f32)divisor;
}

#pragma push
#pragma fp_contract on
void TObjEnemyColorFade::init_death_params() {
    set_rate_from_divisor(10);
    value = 10.0f * rate + 2.0f;
    color.a = 1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}
#pragma pop

void TObjEnemyColorFade::start_fade_in() {
    set_rate_from_divisor(10);
    value = -(30.0f * rate);
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

TObjEnemyColorFade::~TObjEnemyColorFade() {}

TObjEnemyColorFade::TObjEnemyColorFade() : value(0.0f) {}
