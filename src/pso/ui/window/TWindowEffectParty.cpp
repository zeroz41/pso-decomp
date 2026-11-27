#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/NinjaTypes.h"



extern "C" {
extern const f64 party_marker_angle_scale;
}

// Built with deferred code generation (the vtable precedes the switch table
// in .data), so the functions are written from the last one back.
#pragma fp_contract on
TWindowSimpleStatus *get_simple_status_window(s8 i) {
    if (TWindowCtrl::instance == 0) return 0;
    return TWindowCtrl::instance->simple_status[i];
}

TWindowEffectParty::TWindowEffectParty(TObject *object, u16 source, u16 target, s32 effect_id) : TObject(object) {
    Vec position;
    m_name = TWindowEffectParty::class_name;
    this->source_slot = source;
    set_slot_position(this->source_slot, &this->pos_x);
    this->target_slot = target;
    set_slot_position(this->target_slot, &this->target_x);
    this->calc_effect_position(&position);
    this->m_particle = spawn_continuous_particle_effect_with_flags(&position, effect_id, 0xC0);
    this->state = 0;
}

TWindowEffectParty::~TWindowEffectParty() {
    TParticleCtrl::release(this->m_particle);
}

void TWindowEffectParty::run_task() {
    Vec pos;
    u8 slot;

    TWindowBase *window;

    slot = this->target_slot;
    if (((s8) slot > 0) && (((window = get_simple_status_window(slot - 1)) == 0) || (window->is_open_and_unblocked() == 0))) {
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
const char *TWindowEffectParty::class_name = "TWindowEffectParty";

void *TWindowEffectParty::create(TObject *owner, u16 from, u16 to, u32 kind) {
    s32 id;
    u16 b;
    u16 a;
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
    return new TWindowEffectParty(owner, a, b, id);
}

void TWindowEffectParty::set_slot_position(s32 slot, f32 *position) {
    TWindowBase *window;

    if (slot <= 0) {
        copy_vec2(position, (void*)(get_window_layout_position(0x1C)));
        position[0] += 228.0f;
        position[1] += 32.0f;
        return;
    }
    window = get_simple_status_window(slot - 1);
    if (window != NULL) {
        position[0] = (f32) (111.0f + window->target_position[0]);
        position[1] = (f32) (19.0f + window->target_position[1]);
    }
}

void TWindowEffectParty::calc_effect_position(Vec *out) {
    out->x = this->pos_x;
    out->y = this->pos_y;
    out->z = (f32)(-1.0f / TWindowCtrlMain::get_scale(local_client_id));
}

s32 TWindowEffectParty::step_toward_target(f32 to_x, f32 to_y) {
  f32 scr;
  f32 y;
  s32 angle;
  y = to_y - pos_y;
  scr = pos_x;
  scr = to_x - scr;
  if (((scr * scr) + (y * y)) < 25.0f)
  {
    pos_x = to_x;
    pos_y = to_y;
    return 1;
  }
  angle = (s32) (party_marker_angle_scale * atan2_float((f64) y, (f64) scr));
  pos_x = (f32) ((5.0f * cos_table_lookup(angle)) + pos_x);
  pos_y = (f32) ((5.0f * sin_table_lookup(angle)) + pos_y);
  return 0;
}

extern const f64 party_marker_angle_scale = 10430.38043493439;
