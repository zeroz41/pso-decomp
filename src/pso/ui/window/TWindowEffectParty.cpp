#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"
#include "pso/ui/window/WindowLayout.h"



struct Pos_8024FAD8 { s32 a, b, c; };
extern "C" {
extern const f64 lbl_8044ECF0;
void *__ct__18TWindowEffectPartyFP7TObjectScScPv(void *, void *, u16, u16, s32);
extern s32 local_client_id;
f32 get_scale__15TWindowCtrlMainFv(s32);
extern const char *TWindowEffectParty__name;
}

// Built with deferred code generation (the vtable precedes the switch table
// in .data), so the functions are written from the last one back.
#pragma fp_contract on
void *TWindowCtrl__sub_8024FB80(s8 i) {
    if (TWindowCtrl::instance == 0) return 0;
    return TWindowCtrl::instance->simple_status[i];
}

TWindowEffectParty::TWindowEffectParty(TObject *object, s8 arg2, s8 arg3, void *idx) : TObject(object) {
    Pos_8024FAD8 p;
    *(s32 *)this = ((saddr)TWindowEffectParty__name);
    this->source_slot = arg2;
    TWindowEffectParty::set_slot_position((saddr)this, (s32)this->source_slot, &this->pos_x);
    this->target_slot = arg3;
    TWindowEffectParty::set_slot_position((saddr)this, (s32)this->target_slot, &this->target_x);
    this->calc_effect_position(&p);
    this->m_particle = spawn_continuous_particle_effect_with_flags((void *)&p, (saddr)idx, (s32)(0xC0));
    this->state = 0;
}

TWindowEffectParty::~TWindowEffectParty() {
    TParticleCtrl::release(this->m_particle);
}

void TWindowEffectParty::run_task() {
    s32 pos;
    u8 temp_r3;

    void *window;

    temp_r3 = this->target_slot;
    if (((s8) temp_r3 > 0) && (((window = TWindowCtrl__sub_8024FB80(temp_r3 - 1)) == 0) || (((TWindowBase *)window)->sub_80244994() == 0))) {
        queue_destruction();
        return;
    }
    switch (this->state) {
    case 0:
        this->state = 1;
    case 1:
        if (step_toward_target(296.0f, this->pos_y) != 0) {
            this->state = 2;
        }
        break;
    case 2:
        if (step_toward_target(296.0f, this->target_y) != 0) {
            this->state = 3;
        }
        break;
    case 3:
        if (step_toward_target(this->target_x, this->target_y) != 0) {
            this->state = 4;
        }
        break;
    case 4:
        queue_destruction();
        break;
    }
    if (this->m_particle != NULL) {
        calc_effect_position(&pos);
        this->m_particle->set_position(&pos);
    }
}

void TWindowEffectParty::render() {  }

#pragma readonly_strings on
const char *TWindowEffectParty__name = "TWindowEffectParty";

void *TWindowEffectParty::create(void *owner, u16 from, u16 to, u32 kind) {
    s32 id;
    u16 b;
    u16 a;
    void *w;
    if (from == to) {
        return 0;
    }
    if (from >= 4) {
        return 0;
    }
    if (to >= 4) {
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
    a = from;
    a -= local_client_id;
    if (a & 0xFFFC) {
        a += 4;
    }
    b = to;
    b -= local_client_id;
    if (b & 0xFFFC) {
        b += 4;
    }
    w = TObject::operator new(0x34);
    if (w != 0) {
        w = __ct__18TWindowEffectPartyFP7TObjectScScPv(w, owner, a, b, id);
    }
    return w;
}

void TWindowEffectParty::set_slot_position(s32 arg0, s32 arg1, void *window_sub_symbol_chat_parts_set) {
    void *temp_r3;
    (void)arg0;

    if (arg1 <= 0) {
        copy_vec2(window_sub_symbol_chat_parts_set, (void*)(get_window_layout_position(0x1C)));
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

void TWindowEffectParty::calc_effect_position(void *arg1) {
    f32 *out = (f32 *)arg1;
    out[0] = this->pos_x;
    out[1] = this->pos_y;
    out[2] = (f32)(-1.0f / get_scale__15TWindowCtrlMainFv(local_client_id));
}

s32 TWindowEffectParty::step_toward_target(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
  f32 scr;
  f32 y;
  s32 angle;
  y = farg1 - (*((f32 *) (((s8 *) arg0) + 0x24)));
  scr = *((f32 *) (((s8 *) arg0) + 0x20));
  scr = farg0 - scr;
  if (((scr * scr) + (y * y)) < 25.0f)
  {
    *((f32 *) (((s8 *) arg0) + 0x20)) = farg0;
 do { *((f32 *) (((s8 *) arg0) + 0x24)) = farg1; return 1; } while (0);
  }
  angle = (s32) (lbl_8044ECF0 * atan2_float((f64) y, (f64) scr));
  *((f32 *) (((s8 *) arg0) + 0x20)) = (f32) ((5.0f * cos_table_lookup(angle)) + (*((f32 *) (((s8 *) arg0) + 0x20))));
  *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) ((5.0f * sin_table_lookup(angle)) + (*((f32 *) (((s8 *) arg0) + 0x24))));
  return 0;
}

extern const f64 lbl_8044ECF0 = 10430.38043493439;
