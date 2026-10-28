// ---- pso/unk/text_800A0320
#include "types.h"
#include "pso/unk/text_800A0320.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 calc_recoil_offsets__13TUnk_80490470Fv(f32);


s32 TUnk_80490470::has_visible_opacity() {
    return *(f32 *)&this->unk_18 > 0.0f;
}

void TUnk_80490470::set_flags_and_apply_damage_color() { TObjPlayer::set_flags_and_apply_damage_color(); set_chunk_blend(7424); }
s32 TUnk_80490470::advance_toward_max() {
    f32 temp_f1;
    temp_f1 = *(f32 *)&this->unk_18;
    *(f32 *)&this->unk_18 = (f32) (temp_f1 + *(f32 *)&this->unk_10);
    calc_recoil_offsets__13TUnk_80490470Fv(temp_f1);
    return *(f32 *)&this->unk_18 >= 2.0f;
}
s32 TUnk_80490470::decay_value_toward_floor() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x18);
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x10));
    calc_recoil_offsets__13TUnk_80490470Fv(temp_f1);
    return *(f32 *)((s8 *)arg0 + 0x18) <= 0.0f;
}

}

// ---- pso/player/TObjPlayer_800A0408
#include "types.h"
#include "pso/enemy/DarkGunner.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_800A0408.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/player/TUnk_80490470.h"






void TUnk_80490470::calc_recoil_offsets() {
    f32 temp_f1;
    f32 var_f0;

    temp_f1 = *(f32 *)&this->unk_18;
    if (temp_f1 > 1.0f) {
        if (temp_f1 > 2.0f) {
            *(f32 *)&this->unk_0 = (f32) 0.0f;
        } else {
            *(f32 *)&this->unk_0 = (f32) (temp_f1 - 2.0f);
        }
        this->m_4 = (f32) 0.0f;
        *(f32 *)&this->unk_8 = (f32) 0.0f;
        this->m_c = (f32) 0.0f;
        return;
    }
    *(f32 *)&this->unk_0 = (f32) (-1.0f);
    var_f0 = *(f32 *)&this->unk_18 - 1.0f;
    if (var_f0 < (-1.0f)) {
        var_f0 = (-1.0f);
    }
    this->m_4 = var_f0;
    *(f32 *)&this->unk_8 = var_f0;
    this->m_c = var_f0;
}

    
    
void TUnk_80490470::reset_obstruction_fade() { *(float *)&this->unk_18 = 0.0f; *(float *)&this->unk_0 = (-1.0f); this->m_4 = (-1.0f); *(float *)&this->unk_8 = (-1.0f); this->m_c = (-1.0f); }

    
void TUnk_80490470::vfunc_4() { *(float *)&this->unk_18 = 2.0f; *(float *)&this->unk_0 = 0.0f; this->m_4 = 0.0f; *(float *)&this->unk_8 = 0.0f; this->m_c = 0.0f; }

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
    *(f32 *)&this->unk_10 = (f32) (2.0f / (f32) arg1);
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

extern s32 lbl_80490470[];

void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_80490470;
        __dt__13TUnk_80494AE0Fv(arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

}

#include "pso/player/TObjPlayer.h"

struct Obj_800A0654 { u8 pad[0x37c]; s32 count; u8 pad2[4]; u16 ids[1]; };

struct Obj_800A06B4 { u8 pad[0x37c]; s32 count; u8 pad2[4]; u16 ids[1]; };

struct Obj_800A0728 { u8 pad[0x374]; s32 mode; s32 timer; s32 count; u8 pad2[4]; u16 ids[1]; };

extern "C" {
void TObjPlayer__sub_800A0654(Obj_800A0654 *self);
s32 TObjPlayer__sub_800A06B4(Obj_800A06B4 *self);
int TObjPlayer__sub_800D9718(void);

void*TUnk_80490470::init_vtable_and_field18() { TObjPlayer__sub_800D9718(); *(int*)((char*)this + 0x14) = (int)lbl_80490470; *(float *)&this->unk_18 = 0.0f; return this; }
void TObjPlayer__sub_800A0654(Obj_800A0654 *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        void *e = get_enemy_entity(self->ids[i]);
        if (e != 0) {
            ((TObjPlayer *)e)->apply_fall_damage_flag();
        }
    }
}
s32 TObjPlayer__sub_800A06B4(Obj_800A06B4 *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        void *e = get_enemy_entity(self->ids[i]);
        if (e != 0) {
            if (TObjPlayer__sub_800A1808(e) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
void TObjPlayer::trigger_targets_action() {
    Obj_800A0728 *self = (Obj_800A0728 *)this;
    s32 i;
    self->timer = 0x78;
    self->mode = 6;
    for (i = 0; i < this->m_37c; i++) {
        void *e = get_enemy_entity(self->ids[i]);
        if (e != 0) {
            ((TObjPlayer *)e)->trigger_action_if_not_flagged();
        }
    }
}

}
