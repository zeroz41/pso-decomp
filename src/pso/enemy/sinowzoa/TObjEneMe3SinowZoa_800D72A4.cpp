#include "types.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa_800D72A4.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/TUnk_80494938.h"

struct O_800D72A4 { u8 pad[0x18]; f32 f18; };

extern "C" {
s32 TObjEneMe3SinowZoa__sub_800D72A4(O_800D72A4 *self);

s32 TObjEneMe3SinowZoa__sub_800D72A4(O_800D72A4 *self) {
    return self->f18 > 0.0f && self->f18 < 2.0f;
}

s32 TUnk_80494938::has_visible_opacity() {
    return this->value > 0.0f;
}

void TUnk_80494938::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(8448); }

s32 TObjEneMe3SinowZoa::advance_timer(f32 farg0) {
    *(f32 *)((s8 *)((u8 *)this) + 0x18) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x18) + *(f32 *)&this->m_up);
    ((TUnk_80494938 *)((u8 *)this))->sub_800D741C();
    return *(f32 *)((s8 *)((u8 *)this) + 0x18) >= farg0;
}

s32 TUnk_80494938::advance_toward_max() {
    u8 *arg0 = (u8 *)this;
    this->value = (f32) ((this->value) + this->rate);
    ((TUnk_80494938 *)arg0)->sub_800D741C();
    return this->value >= 2.0f;
}

s32 TUnk_80494938::decay_value_toward_floor() {
    u8 *arg0 = (u8 *)this;
    this->value = (f32) ((this->value) - this->rate);
    ((TUnk_80494938 *)arg0)->sub_800D741C();
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
        this->color.a = (f32) (temp_f2 - 1.0f);
        if (0.0f == this->color.a) {
            this->color.a = 0.01f;
        }
        return;
    }
    this->color.a = 1.0f;
}

void TObjEneMe3SinowZoa::copy_position_vector(void* q) { *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); }

void TUnk_80494938::reset_obstruction_fade() { this->value = 0.0f; this->color.a = -1.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TUnk_80494938::reset_color() { this->value = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void TObjEneMe3SinowZoa::set_field_10(f32 v) { *(f32 *)&this->m_up = v; }

}

struct B_800D7524 { f32 f0; f32 f4; f32 f8; f32 fc; f32 f10; };

struct V_800D7524 : B_800D7524 {
    virtual void m0();
    virtual void m1(s32 x);
    f32 f18;
};

extern "C" {
void TUnk_80494938::set_rate_from_divisor(s32 arg1) {
    this->rate = (f32) (2.0f / (f32) arg1);
}

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa::init_death_params() {
    ((V_800D7524 *)this)->m1(10);
    ((V_800D7524 *)this)->f18 = 10.0f * ((V_800D7524 *)this)->f10 + 2.0f;
    ((V_800D7524 *)this)->f0 = 1.0f;
    ((V_800D7524 *)this)->f4 = 0.0f;
    ((V_800D7524 *)this)->f8 = 0.0f;
    ((V_800D7524 *)this)->fc = 0.0f;
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
