#include "types.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/TDuelEffectCtrl.h"
struct Obj_8007FA94 { u8 pad[0x20]; s32 state; s32 value; };

struct Obj_8007FB14 { u8 pad[0x20]; s32 state; s32 value; };

extern "C" {
void *__nw__7TObjectFUl(int);
void *__ct__17TDuelEffectStringFP7TObjectPvPv(void *p, s32 v, void *s, s32 n);
extern u8 lbl_80438D48[];
extern u8 lbl_80438D50[];
void update_duel_end_effect(Obj_8007FA94 *self);
void *__ct__17TDuelEffectNumberFP7TObjectPvPv(void *p, s32 v, void *s, s32 n);
s32 play_sound_effect(s32, void *, s32, s32);
extern u8 lbl_80438D40[];
extern u8 lbl_80438D58[];
f32 duel_start_countdown_effect_pos[3] = { 320.0f, 221.0f, 0.5f };
void update_duel_end_effect(Obj_8007FA94 *self) {
    switch (self->state) {
    case 0: {
        void *p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectStringFP7TObjectPvPv(p, self->value, lbl_80438D48, 1);
        }
        send_neg50__6TLobbyFPvPv((void *)lbl_80438D50, (void *)(0x96));
        break;
    }
    case 30:
        queue_destruction__7TObjectFv(self);
        break;
    }
}
void TDuelEffectCtrl::update_duel_start_countdown() {
    void *p;
    switch (((Obj_8007FB14 *)this)->state) {
    case 0x0:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectNumberFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 5);
        }
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x1E:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectNumberFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 4);
        }
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x3C:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectNumberFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 3);
        }
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x5A:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectNumberFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 2);
        }
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x78:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectNumberFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 1);
        }
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x96:
        p = __nw__7TObjectFUl(0x2C);
        if (p != NULL) {
            __ct__17TDuelEffectStringFP7TObjectPvPv(p, ((Obj_8007FB14 *)this)->value, lbl_80438D40, 0);
        }
        break;
    case 0xA0:
        spawn_particle_effect_with_flags(duel_start_countdown_effect_pos, 0x1F1, 0x48C0);
        play_cue_stream_file((s32)lbl_80438D58);
        break;
    case 0xB4:
        queue_destruction__7TObjectFv(this);
        break;
    }
}

}

extern TObject* tl_clipout;
extern const char* TDuelEffectCtrl__class_name;

void TDuelEffectCtrl::render() {}

void TDuelEffectCtrl::run_task() {
    switch (m_state) {
    case 0:
        update_duel_start_countdown();
        break;
    case 1:
        update_duel_end_effect((Obj_8007FA94 *)this);
        break;
    }
    ++m_frameCount;
}

TDuelEffectCtrl::~TDuelEffectCtrl() {
    if (m_effect != NULL) {
        queue_destruction__7TObjectFv(m_effect);
        m_effect = NULL;
    }
}

TDuelEffectCtrl::TDuelEffectCtrl(TObject* parent, u8 state) : TObject(parent) {
    m_name = TDuelEffectCtrl__class_name;
    m_state = state;
    m_frameCount = 0;
    m_effect = new TObject(tl_clipout);
}
