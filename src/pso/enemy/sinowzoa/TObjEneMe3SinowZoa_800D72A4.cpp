#include "types.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/TUnk_80494938.h"

// advance_timer, copy_position_vector, set_field_10 and init_death_params run on a
// TUnk_80494938 (callers pass &fade) although their symbols name TObjEneMe3SinowZoa.

extern "C" {
s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade);

s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade) {
    return fade->value > 0.0f && fade->value < 2.0f;
}

s32 TUnk_80494938::has_visible_opacity() {
    return this->value > 0.0f;
}

void TUnk_80494938::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(8448); }

s32 TObjEneMe3SinowZoa::advance_timer(f32 farg0) {
    ((TUnk_80494938 *)this)->value = ((TUnk_80494938 *)this)->value + ((TUnk_80494938 *)this)->rate;
    ((TUnk_80494938 *)this)->sub_800D741C();
    return ((TUnk_80494938 *)this)->value >= farg0;
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

void TObjEneMe3SinowZoa::copy_position_vector(void *q) {
    ((TUnk_80494938 *)this)->value = ((NJS_ARGB *)q)->a;
    ((TUnk_80494938 *)this)->color.a = ((NJS_ARGB *)q)->a;
    ((TUnk_80494938 *)this)->color.r = ((NJS_ARGB *)q)->r;
    ((TUnk_80494938 *)this)->color.g = ((NJS_ARGB *)q)->g;
    ((TUnk_80494938 *)this)->color.b = ((NJS_ARGB *)q)->b;
}

void TUnk_80494938::reset_obstruction_fade() { this->value = 0.0f; this->color.a = -1.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TUnk_80494938::reset_color() { this->value = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TObjEneMe3SinowZoa::set_field_10(f32 v) { ((TUnk_80494938 *)this)->rate = v; }

void TUnk_80494938::set_rate_from_divisor(s32 arg1) {
    this->rate = 2.0f / (f32)arg1;
}

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa::init_death_params() {
    ((TUnk_80494938 *)this)->set_rate_from_divisor(10);
    ((TUnk_80494938 *)this)->value = 10.0f * ((TUnk_80494938 *)this)->rate + 2.0f;
    ((TUnk_80494938 *)this)->color.a = 1.0f;
    ((TUnk_80494938 *)this)->color.r = 0.0f;
    ((TUnk_80494938 *)this)->color.g = 0.0f;
    ((TUnk_80494938 *)this)->color.b = 0.0f;
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

}
