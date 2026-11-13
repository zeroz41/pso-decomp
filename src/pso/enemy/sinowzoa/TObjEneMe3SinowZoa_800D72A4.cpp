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
extern const f32 lbl_805DA348;
extern const f32 lbl_805DA34C;
extern const f32 lbl_805DA350;
extern const f32 lbl_805DA354;
extern const f32 lbl_805DA358;
extern const f32 lbl_805DA35C;
extern const f32 lbl_805DA360;
s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade);

s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade) {
    return fade->value > lbl_805DA348 && fade->value < lbl_805DA34C;
}

s32 TUnk_80494938::has_visible_opacity() {
    return this->value > lbl_805DA348;
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
    return this->value >= lbl_805DA34C;
}

s32 TUnk_80494938::decay_value_toward_floor() {
    this->value = this->value - this->rate;
    sub_800D741C();
    return this->value <= lbl_805DA348;
}

void TUnk_80494938::sub_800D741C() {
    f32 temp_f2;
    temp_f2 = this->value;
    if (temp_f2 <= lbl_805DA348) {
        this->color.a = lbl_805DA350;
        return;
    }
    if (temp_f2 < lbl_805DA34C) {
        this->color.a = temp_f2 - lbl_805DA354;
        if (lbl_805DA348 == this->color.a) {
            this->color.a = lbl_805DA358;
        }
        return;
    }
    this->color.a = lbl_805DA354;
}

void TObjEneMe3SinowZoa::copy_position_vector(void *q) {
    ((TUnk_80494938 *)this)->value = ((NJS_ARGB *)q)->a;
    ((TUnk_80494938 *)this)->color.a = ((NJS_ARGB *)q)->a;
    ((TUnk_80494938 *)this)->color.r = ((NJS_ARGB *)q)->r;
    ((TUnk_80494938 *)this)->color.g = ((NJS_ARGB *)q)->g;
    ((TUnk_80494938 *)this)->color.b = ((NJS_ARGB *)q)->b;
}

void TUnk_80494938::reset_obstruction_fade() { this->value = lbl_805DA348; this->color.a = lbl_805DA350; this->color.r = lbl_805DA348; this->color.g = lbl_805DA348; this->color.b = lbl_805DA348; }

void TUnk_80494938::reset_color() { this->value = lbl_805DA34C; this->color.a = lbl_805DA348; this->color.r = lbl_805DA348; this->color.g = lbl_805DA348; this->color.b = lbl_805DA348; }

void TObjEneMe3SinowZoa::set_field_10(f32 v) { ((TUnk_80494938 *)this)->rate = v; }

void TUnk_80494938::set_rate_from_divisor(s32 arg1) {
    this->rate = lbl_805DA34C / (f32)arg1;
}

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa::init_death_params() {
    ((TUnk_80494938 *)this)->set_rate_from_divisor(10);
    ((TUnk_80494938 *)this)->value = lbl_805DA35C * ((TUnk_80494938 *)this)->rate + lbl_805DA34C;
    ((TUnk_80494938 *)this)->color.a = lbl_805DA354;
    ((TUnk_80494938 *)this)->color.r = lbl_805DA348;
    ((TUnk_80494938 *)this)->color.g = lbl_805DA348;
    ((TUnk_80494938 *)this)->color.b = lbl_805DA348;
}
#pragma pop

void TUnk_80494938::start_fade_in() {
    set_rate_from_divisor(10);
    value = -(lbl_805DA360 * rate);
    color.a = lbl_805DA350;
    color.r = lbl_805DA348;
    color.g = lbl_805DA348;
    color.b = lbl_805DA348;
}

TUnk_80494938::~TUnk_80494938() {}

TUnk_80494938::TUnk_80494938() : value(lbl_805DA348) {}

}
