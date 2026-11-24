#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804CCA78.h"
#include "pso/unk/TUnk_804CCA90.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_80226070.h"

// defer_codegen emits these in reverse source order: the last function in the file comes first in .text.
#pragma defer_codegen on

TUnk_804CCA90::TUnk_804CCA90(Vec *pos, s16 delay, s32 sound_id, TObject *parent) : TObject(parent) {
    m_delay = delay;
    m_timer = 0;
    m_sound_id = sound_id;
    VecCopy(&m_pos, pos);
}

TUnk_804CCA90::~TUnk_804CCA90() {
}

void TUnk_804CCA90::run_task() {
    m_timer++;
    if (m_timer > m_delay) {
        play_sound_effect(m_sound_id, &m_pos, 0, 0);
        queue_destruction();
    }
}

TUnk_804CCA78::TUnk_804CCA78(Vec *pos, s16 frames, s32 sound, s32 pitch, TObject *parent) : TObject(parent) {
    this->frames = frames;
    age = 0;
    this->sound = sound;
    sound_handle = play_sound_effect(this->sound, pos, 0, 0);
    if (sound_handle >= 0 && pitch != 0) {
        set_sound_pitch_request(sound_handle, pitch, 0);
    }
}

TUnk_804CCA78::~TUnk_804CCA78() {
    if (sound_handle >= 0) {
        stop_sound_request(sound_handle);
    }
}

void TUnk_804CCA78::run_task() {
    age++;
    if (age > frames) {
        queue_destruction();
    }
}
