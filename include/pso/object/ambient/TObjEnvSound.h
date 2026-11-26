#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUND_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUND_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEnvSound : public TObjBase {
    TObjEnvSound(TObject *parent, void *arg2);
    virtual ~TObjEnvSound();
    f32 radius;        // scale.z, or 200 when that is not positive
    s32 attenuation;   // set_params[1] clamped to -127..127
    u32 cue;           // the sound cue of the area's table row
    s32 mode;          // the row's mode: 1 plays once in range, 2 keeps playing with the attenuation
    virtual void render();
    virtual void run_task();
    s32 is_sound_enabled(s32 cue);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSound_size, sizeof(TObjEnvSound) == 0xA0);

extern "C" {
void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjEnvSound.cpp ---
extern "C" {
void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
