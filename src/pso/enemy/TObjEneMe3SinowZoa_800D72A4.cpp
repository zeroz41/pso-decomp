#include "types.h"
#include "pso/enemy/TObjEneMe3SinowZoa_800D72A4.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TUnk_80494938.h"

struct O_800D72A4 { u8 pad[0x18]; f32 f18; };

extern "C" {
extern const float lbl_805DA348;
extern const f32 lbl_805DA34C;
extern const float lbl_805DA350;
extern const f32 lbl_805DA354;
extern const f32 lbl_805DA358;
s32 TObjEneMe3SinowZoa__sub_800D72A4(O_800D72A4 *self);

s32 TObjEneMe3SinowZoa__sub_800D72A4(O_800D72A4 *self) {
    return self->f18 > (*(const f32 *)&lbl_805DA348) && self->f18 < lbl_805DA34C;
}

s32 TUnk_80494938::has_visible_opacity() {
    return *(f32 *)&this->unk_18 > (*(const f32 *)&lbl_805DA348);
}

void TUnk_80494938::set_flags_and_apply_damage_color() { TObjPlayer::set_flags_and_apply_damage_color(); set_chunk_blend(8448); }

s32 TObjEneMe3SinowZoa::advance_timer(f32 farg0) {
    *(f32 *)((s8 *)((u8 *)this) + 0x18) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x18) + *(f32 *)&this->m_up);
    ((TUnk_80494938 *)((u8 *)this))->sub_800D741C();
    return *(f32 *)((s8 *)((u8 *)this) + 0x18) >= farg0;
}

s32 TUnk_80494938::advance_toward_max() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->unk_18 = (f32) ((*(f32 *)&this->unk_18) + *(f32 *)&this->unk_10);
    ((TUnk_80494938 *)arg0)->sub_800D741C();
    return *(f32 *)&this->unk_18 >= lbl_805DA34C;
}

s32 TUnk_80494938::decay_value_toward_floor() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->unk_18 = (f32) ((*(f32 *)&this->unk_18) - *(f32 *)&this->unk_10);
    ((TUnk_80494938 *)arg0)->sub_800D741C();
    return *(f32 *)&this->unk_18 <= (*(const f32 *)&lbl_805DA348);
}

void TUnk_80494938::sub_800D741C() {
    f32 temp_f2;
    temp_f2 = *(f32 *)&this->unk_18;
    if (temp_f2 <= (*(const f32 *)&lbl_805DA348)) {
        *(f32 *)&this->unk_0 = (f32) (*(const f32 *)&lbl_805DA350);
        return;
    }
    if (temp_f2 < lbl_805DA34C) {
        *(f32 *)&this->unk_0 = (f32) (temp_f2 - lbl_805DA354);
        if ((*(const f32 *)&lbl_805DA348) == *(f32 *)&this->unk_0) {
            *(f32 *)&this->unk_0 = (f32) lbl_805DA358;
        }
        return;
    }
    *(f32 *)&this->unk_0 = (f32) lbl_805DA354;
}

void TObjEneMe3SinowZoa::copy_position_vector(void* q) { *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); }

void TUnk_80494938::reset_obstruction_fade() { *(float *)&this->unk_18 = lbl_805DA348; *(float *)&this->unk_0 = lbl_805DA350; this->m_4 = lbl_805DA348; *(float *)&this->unk_8 = lbl_805DA348; this->m_c = lbl_805DA348; }

    extern const float lbl_805DA34C;
void TUnk_80494938::vfunc_4() { *(float *)&this->unk_18 = lbl_805DA34C; *(float *)&this->unk_0 = lbl_805DA348; this->m_4 = lbl_805DA348; *(float *)&this->unk_8 = lbl_805DA348; this->m_c = lbl_805DA348; }

void TObjEneMe3SinowZoa::set_field_10(f32 v) { *(f32 *)&this->m_up = v; }

}

struct B_800D758C { f32 f0; f32 f4; f32 f8; f32 fc; f32 f10; };

struct V_800D758C : B_800D758C {
    virtual void m0();
    virtual void m1(s32 x);
    f32 f18;
};

struct B_800D7524 { f32 f0; f32 f4; f32 f8; f32 fc; f32 f10; };

struct V_800D7524 : B_800D7524 {
    virtual void m0();
    virtual void m1(s32 x);
    f32 f18;
};

extern "C" {
extern const f32 lbl_805DA360;
extern const f32 lbl_805DA350;
extern const f32 lbl_805DA348;
void TObjEneMe3SinowZoa__sub_800D758C(V_800D758C *self);
extern const f32 lbl_805DA35C;
void TUnk_80494938::set_rate_from_divisor(s32 arg1) {
    *(f32 *)&this->unk_10 = (f32) (lbl_805DA34C / (f32) arg1);
}

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa::init_death_params() {
    ((V_800D7524 *)this)->m1(10);
    ((V_800D7524 *)this)->f18 = lbl_805DA35C * ((V_800D7524 *)this)->f10 + lbl_805DA34C;
    ((V_800D7524 *)this)->f0 = lbl_805DA354;
    ((V_800D7524 *)this)->f4 = lbl_805DA348;
    ((V_800D7524 *)this)->f8 = lbl_805DA348;
    ((V_800D7524 *)this)->fc = lbl_805DA348;
}
#pragma pop

void TObjEneMe3SinowZoa__sub_800D758C(V_800D758C *self) {
    self->m1(10);
    self->f18 = -(lbl_805DA360 * self->f10);
    self->f0 = lbl_805DA350;
    self->f4 = lbl_805DA348;
    self->f8 = lbl_805DA348;
    self->fc = lbl_805DA348;
}

extern s32 lbl_80494938[];

void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_80494938;
        __dt__13TUnk_80494AE0Fv(arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

int TObjPlayer__sub_800D9718(void);

void*TUnk_80494938::init_common() { TObjPlayer__sub_800D9718(); *(int*)((char*)this + 0x14) = (int)lbl_80494938; *(float *)&this->unk_18 = lbl_805DA348; return this; }

}
