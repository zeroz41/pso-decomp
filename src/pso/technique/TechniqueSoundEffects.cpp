#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TTimedSoundEffect.h"
#include "pso/technique/TDelayedSoundEffect.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_80226070.h"

// defer_codegen emits these in reverse source order: the last function in the file comes first in .text.
#pragma defer_codegen on

TDelayedSoundEffect::TDelayedSoundEffect(Vec *pos, s16 delay, s32 sound_id, TObject *parent) : TObject(parent) {
    m_delay = delay;
    m_timer = 0;
    m_sound_id = sound_id;
    VecCopy(&m_pos, pos);
}

TDelayedSoundEffect::~TDelayedSoundEffect() {
}

void TDelayedSoundEffect::run_task() {
    m_timer++;
    if (m_timer > m_delay) {
        play_sound_effect(m_sound_id, &m_pos, 0, 0);
        queue_destruction();
    }
}

TTimedSoundEffect::TTimedSoundEffect(Vec *pos, s16 frames, s32 sound, s32 pitch, TObject *parent) : TObject(parent) {
    this->frames = frames;
    age = 0;
    this->sound = sound;
    sound_handle = play_sound_effect(this->sound, pos, 0, 0);
    if (sound_handle >= 0 && pitch != 0) {
        set_sound_pitch_request(sound_handle, pitch, 0);
    }
}

TTimedSoundEffect::~TTimedSoundEffect() {
    if (sound_handle >= 0) {
        stop_sound_request(sound_handle);
    }
}

void TTimedSoundEffect::run_task() {
    age++;
    if (age > frames) {
        queue_destruction();
    }
}
