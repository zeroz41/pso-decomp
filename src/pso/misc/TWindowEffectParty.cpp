#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TWindowEffectParty.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TParticleCtrl.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowEffectParty__name = "TWindowEffectParty";
}


struct Obj_8024FB80 { u8 pad[0x78]; void *arr[1]; };

struct Pos_8024FAD8 { s32 a, b, c; };

extern "C" {
extern Obj_8024FB80 *TWindowCtrl__active_window;
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
extern s32 __vt__18TWindowEffectParty[];
extern const char *TWindowEffectParty__name;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 sub_80244994__11TWindowBaseFv();

void TWindowEffectParty::render() {  }

extern const f32 lbl_805DCCD4;

void TWindowEffectParty::run_task() {
    s32 sp8;
    u8 temp_r3;

    temp_r3 = this->m_1e;
    if (((s8) temp_r3 > 0) && ((((u32)TWindowCtrl__sub_8024FB80(temp_r3 - 1)) == 0U) || (sub_80244994__11TWindowBaseFv() == 0))) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    switch ((s8) this->m_1c) {
    case 0:
        this->m_1c = 1U;
    case 1:
        if (step_toward_target(lbl_805DCCD4, *(f32 *)&this->_pad24) != 0) {
            this->m_1c = 2U;
        }
        break;
    case 2:
        if (step_toward_target(lbl_805DCCD4, *(f32 *)&this->_pad2C) != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if (step_toward_target(*(f32 *)&this->m_28, *(f32 *)&this->_pad2C) != 0) {
            this->m_1c = 4U;
        }
        break;
    case 4:
        queue_destruction__7TObjectFv(this);
        break;
    }
    if ((u32) this->m_30 != 0U) {
        calc_effect_position(&sp8);
        ((TParticleCtrl *)this->m_30)->set_position(&sp8);
    }
}

void *__dt__18TWindowEffectPartyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TWindowEffectParty;
        TParticleCtrl::release(*(void **)((s8 *)arg0 + 0x30));
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
TWindowEffectParty::TWindowEffectParty(TObject *object, s8 arg2, s8 arg3, void *arg4) : TObject(object) {
    Pos_8024FAD8 p;
    *(s32 *)this = ((s32)TWindowEffectParty__name);
    *(s8 *)&this->m_1d = arg2;
    TWindowEffectParty::set_slot_position((s32)this, (s32)(*(s8 *)&this->m_1d), (void *)(((u8 *)this) + 0x20));
    *(s8 *)&this->m_1e = arg3;
    TWindowEffectParty::set_slot_position((s32)this, (s32)(*(s8 *)&this->m_1e), (void *)(((u8 *)this) + 0x28));
    this->calc_effect_position(&p);
    *(s32 *)&this->m_30 = (s32)spawn_continuous_particle_effect_with_flags((void *)&p, (s32)arg4, 0xC0);
    *(s8 *)&this->m_1c = 0;
}

void *TWindowCtrl__sub_8024FB80(s8 i) {
    if (TWindowCtrl__active_window == 0) return 0;
    return TWindowCtrl__active_window->arr[i];
}
