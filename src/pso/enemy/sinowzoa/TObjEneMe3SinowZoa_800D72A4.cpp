#include "types.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/unk/text_803E2F28.h"

s32 TUnk_80494938::has_partial_opacity() {
    return value > 0.0f && value < 2.0f;
}

s32 TUnk_80494938::has_visible_opacity() {
    return this->value > 0.0f;
}

void TUnk_80494938::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(8448); }

s32 TUnk_80494938::advance_timer(f32 limit) {
    this->value = this->value + this->rate;
    sub_800D741C();
    return this->value >= limit;
}

s32 TUnk_80494938::advance_toward_max() {
    this->value = this->value + this->rate;
    sub_800D741C();
    return this->value >= 2.0f;
}

s32 TUnk_80494938::decay_value_toward_floor() {
    this->value = this->value - this->rate;
    sub_800D741C();
    return this->value <= 0.0f;
}

void TUnk_80494938::sub_800D741C() {
    f32 temp_f2;
    temp_f2 = this->value;
    if (temp_f2 <= 0.0f) {
        this->color.a = -1.0f;
        return;
    }
    if (temp_f2 < 2.0f) {
        this->color.a = temp_f2 - 1.0f;
        if (0.0f == this->color.a) {
            this->color.a = 0.01f;
        }
        return;
    }
    this->color.a = 1.0f;
}

void TUnk_80494938::copy_color(NJS_ARGB *src) {
    this->value = src->a;
    this->color.a = src->a;
    this->color.r = src->r;
    this->color.g = src->g;
    this->color.b = src->b;
}

void TUnk_80494938::reset_obstruction_fade() { this->value = 0.0f; this->color.a = -1.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TUnk_80494938::reset_color() { this->value = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TUnk_80494938::set_rate(f32 new_rate) { this->rate = new_rate; }

void TUnk_80494938::set_rate_from_divisor(s32 divisor) {
    this->rate = 2.0f / (f32)divisor;
}

#pragma push
#pragma fp_contract on
void TUnk_80494938::init_death_params() {
    set_rate_from_divisor(10);
    value = 10.0f * rate + 2.0f;
    color.a = 1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}
#pragma pop

void TUnk_80494938::start_fade_in() {
    set_rate_from_divisor(10);
    value = -(30.0f * rate);
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

TUnk_80494938::~TUnk_80494938() {}

TUnk_80494938::TUnk_80494938() : value(0.0f) {}
