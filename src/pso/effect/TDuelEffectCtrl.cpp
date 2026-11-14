#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/TDuelEffectCtrl.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/effect/TDuelEffectString.h"
#include "pso/system/task/TObject.h"

const char* TDuelEffectCtrl__class_name = "TDuelEffectCtrl";

// Screen positions handed to the countdown digits and the "end" banner (both the screen centre).
extern const f32 lbl_80438D40[2] = { 320.0f, 221.0f };
extern const f32 lbl_80438D48[2] = { 320.0f, 221.0f };

f32 duel_start_countdown_effect_pos[3] = { 320.0f, 221.0f, 0.5f };

void TDuelEffectCtrl::update_duel_end_effect() {
    switch (m_frameCount) {
    case 0:
        new TDuelEffectString(m_effect, (void *)lbl_80438D48, (void *)1);
        send_neg50__6TLobbyFPvPv((void *)"end.adx", (void *)0x96);
        break;
    case 30:
        queue_destruction();
        break;
    }
}

void TDuelEffectCtrl::update_duel_start_countdown() {
    switch (m_frameCount) {
    case 0x0:
        new TDuelEffectNumber(m_effect, (void *)lbl_80438D40, (void *)5);
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x1E:
        new TDuelEffectNumber(m_effect, (void *)lbl_80438D40, (void *)4);
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x3C:
        new TDuelEffectNumber(m_effect, (void *)lbl_80438D40, (void *)3);
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x5A:
        new TDuelEffectNumber(m_effect, (void *)lbl_80438D40, (void *)2);
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x78:
        new TDuelEffectNumber(m_effect, (void *)lbl_80438D40, (void *)1);
        play_sound_effect(0x4B210, 0, 0, 0);
        break;
    case 0x96:
        new TDuelEffectString(m_effect, (void *)lbl_80438D40, (void *)0);
        break;
    case 0xA0:
        spawn_particle_effect_with_flags(duel_start_countdown_effect_pos, 0x1F1, 0x48C0);
        play_cue_stream_file((s32)"start.adx");
        break;
    case 0xB4:
        queue_destruction();
        break;
    }
}

extern TObject* tl_clipout;

void TDuelEffectCtrl::render() {}

void TDuelEffectCtrl::run_task() {
    switch (m_state) {
    case 0:
        update_duel_start_countdown();
        break;
    case 1:
        update_duel_end_effect();
        break;
    }
    ++m_frameCount;
}

TDuelEffectCtrl::~TDuelEffectCtrl() {
    if (m_effect != NULL) {
        m_effect->queue_destruction();
        m_effect = NULL;
    }
}

TDuelEffectCtrl::TDuelEffectCtrl(TObject* parent, u8 state) : TObject(parent) {
    m_name = TDuelEffectCtrl__class_name;
    m_state = state;
    m_frameCount = 0;
    m_effect = new TObject(tl_clipout);
}
