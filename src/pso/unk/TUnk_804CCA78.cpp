#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804CCA78.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_80226070.h"


void TUnk_804CCA78::run_task() {
    age++;
    if (age > frames) {
        queue_destruction();
    }
}

TUnk_804CCA78::~TUnk_804CCA78() {
    if (sound_handle >= 0) {
        stop_sound_request(sound_handle);
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
