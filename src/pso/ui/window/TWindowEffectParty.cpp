#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"


extern "C" {
f32 atan2_float(f32 y, f32 x);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f64 lbl_8044ECF0;
void *__nw__7TObjectFUl(u32);
void *__ct__18TWindowEffectPartyFP7TObjectScScPv(void *, void *, u16, u16, s32);
extern s32 local_client_id;
void *TWindowCtrl__sub_8024FB80(s8);
s32 get_window_layout_position(s32);
f32 get_scale__15TWindowCtrlMainFv(s32);


#pragma fp_contract on
s32 TWindowEffectParty::step_toward_target(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f4;
  f32 temp_f5;
  s32 temp_r31;
  temp_f5 = farg1 - (*((f32 *) (((s8 *) arg0) + 0x24)));
  temp_f4 = *((f32 *) (((s8 *) arg0) + 0x20));
  temp_f4 = farg0 - temp_f4;
  if (((temp_f4 * temp_f4) + (temp_f5 * temp_f5)) < 25.0f)
  {
    *((f32 *) (((s8 *) arg0) + 0x20)) = farg0;
 do { *((f32 *) (((s8 *) arg0) + 0x24)) = farg1; return 1; } while (0);
  }
  temp_r31 = (s32) (lbl_8044ECF0 * atan2_float((f64) temp_f5, (f64) temp_f4));
  *((f32 *) (((s8 *) arg0) + 0x20)) = (f32) ((5.0f * cos_table_lookup(temp_r31)) + (*((f32 *) (((s8 *) arg0) + 0x20))));
  *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) ((5.0f * sin_table_lookup(temp_r31)) + (*((f32 *) (((s8 *) arg0) + 0x24))));
  return 0;
}

void TWindowEffectParty::calc_effect_position(void *arg1) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) *(f32 *)&this->m_20;
    *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)&this->_pad24;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (-1.0f / get_scale__15TWindowCtrlMainFv(local_client_id));
}


void TWindowEffectParty::set_slot_position(s32 arg0, s32 arg1, void *window_sub_symbol_chat_parts_set) {
    void *temp_r3;
    (void)arg0;

    if (arg1 <= 0) {
        ((TWindowSubSymbolChatPartsSet *)window_sub_symbol_chat_parts_set)->copy_vec2((void*)(get_window_layout_position(0x1C)));
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0) += 228.0f;
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 4) += 32.0f;
        return;
    }
    temp_r3 = TWindowCtrl__sub_8024FB80(arg1 - 1);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0) = (f32) (111.0f + *(f32 *)((s8 *)temp_r3 + 0x30));
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 4) = (f32) (19.0f + *(f32 *)((s8 *)temp_r3 + 0x34));
    }
}
void *TWindowEffectParty::create(void *owner, s32 from, s32 to, u32 kind) {
    s32 id;
    u16 b;
    u16 a;
    void *w;
    if ((u16)from == (u16)to) {
        return 0;
    }
    if ((u16)from >= 4) {
        return 0;
    }
    if ((u16)to >= 4) {
        return 0;
    }
    switch (kind) {
    case 6:
    case 8:
        id = 0x99;
        break;
    case 7:
        id = 0x98;
        break;
    case 9:
        id = 0x96;
        break;
    case 10:
        id = 0x95;
        break;
    case 0:
        id = 0x97;
        break;
    default:
        return 0;
    }
    a = from - local_client_id;
    if (a & 0xFFFC) {
        a += 4;
    }
    b = to - local_client_id;
    if (b & 0xFFFC) {
        b += 4;
    }
    w = __nw__7TObjectFUl(0x34);
    if (w != 0) {
        w = __ct__18TWindowEffectPartyFP7TObjectScScPv(w, owner, a, b, id);
    }
    return w;
}

}

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


void TWindowEffectParty::run_task() {
    s32 sp8;
    u8 temp_r3;

    temp_r3 = this->m_1e;
    if (((s8) temp_r3 > 0) && ((((u32)TWindowCtrl__sub_8024FB80(temp_r3 - 1)) == 0U) || (sub_80244994__11TWindowBaseFv() == 0))) {
        queue_destruction();
        return;
    }
    switch ((s8) this->m_1c) {
    case 0:
        this->m_1c = 1U;
    case 1:
        if (step_toward_target(296.0f, *(f32 *)&this->_pad24) != 0) {
            this->m_1c = 2U;
        }
        break;
    case 2:
        if (step_toward_target(296.0f, *(f32 *)&this->_pad2C) != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if (step_toward_target(*(f32 *)&this->m_28, *(f32 *)&this->_pad2C) != 0) {
            this->m_1c = 4U;
        }
        break;
    case 4:
        queue_destruction();
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
