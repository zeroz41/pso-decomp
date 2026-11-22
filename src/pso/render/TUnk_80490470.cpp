// ---- pso/unk/text_800A0320
#include "types.h"
#include "pso/unk/text_800A0320.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/player/TObjPlayer.h"


s32 TUnk_80490470::has_visible_opacity() {
    return phase > 0.0f;
}

void TUnk_80490470::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(7424); }
s32 TUnk_80490470::advance_toward_max() {
    f32 temp_f1;
    temp_f1 = phase;
    phase = (f32) (temp_f1 + this->rate);
    this->calc_recoil_offsets();
    return phase >= 2.0f;
}
s32 TUnk_80490470::decay_value_toward_floor() {
    f32 temp_f1;
    temp_f1 = this->phase;
    this->phase = (f32) (temp_f1 - this->rate);
    this->calc_recoil_offsets();
    return this->phase <= 0.0f;
}


// ---- pso/player/TObjPlayer_800A0408

#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_800A0408.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"


void TUnk_80490470::calc_recoil_offsets() {
    f32 temp_f1;
    f32 var_f0;

    temp_f1 = phase;
    if (temp_f1 > 1.0f) {
        if (temp_f1 > 2.0f) {
            this->color.a = 0.0f;
        } else {
            this->color.a = (f32) (temp_f1 - 2.0f);
        }
        this->color.r = 0.0f;
        this->color.g = 0.0f;
        this->color.b = 0.0f;
        return;
    }
    this->color.a = -1.0f;
    var_f0 = phase - 1.0f;
    if (var_f0 < (-1.0f)) {
        var_f0 = (-1.0f);
    }
    this->color.r = var_f0;
    this->color.g = var_f0;
    this->color.b = var_f0;
}

    
    
void TUnk_80490470::reset_obstruction_fade() { phase = 0.0f; this->color.a = (-1.0f); this->color.r = (-1.0f); this->color.g = (-1.0f); this->color.b = (-1.0f); }

    
void TUnk_80490470::reset_color() { phase = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

struct Base_800A04F0 { f32 v0, v4, v8, vc; f32 rate; };

struct Obj_800A04F0 : Base_800A04F0 {
    virtual void m0();
    virtual void m1(s32);
    f32 f18;
};

struct Base_800A0554 { f32 v0, v4, v8, vc; f32 rate; };

struct Obj_800A0554 : Base_800A0554 {
    virtual void m0();
    virtual void m1(s32);
    f32 f18;
};

extern "C" {

void TObjPlayer__sub_800A04F0(Obj_800A04F0 *self);

void TObjPlayer__sub_800A0554(Obj_800A0554 *self);
void TUnk_80490470::set_rate_from_divisor(s32 arg1) {
    this->rate = (f32) (2.0f / (f32) arg1);
}
#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800A04F0(Obj_800A04F0 *self) {
    self->m1(10);
    self->f18 = 1e+01f * self->rate + 2.0f;
    self->v0 = 1.0f;
    self->v4 = 1.0f;
    self->v8 = 1.0f;
    self->vc = 1.0f;
}
#pragma pop

void TObjPlayer__sub_800A0554(Obj_800A0554 *self) {
    self->m1(10);
    self->f18 = -(2e+01f * self->rate);
    self->v0 = 0.0f;
    self->v4 = 0.0f;
    self->v8 = 0.0f;
    self->vc = 0.0f;
}


TUnk_80490470::~TUnk_80490470() {}

}


TUnk_80490470::TUnk_80490470() : MaterialColorFade(), phase(0.0f) {}
