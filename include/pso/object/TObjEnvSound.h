#ifndef PSO_OBJECT_TOBJENVSOUND_H
#define PSO_OBJECT_TOBJENVSOUND_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjEnvSound : public TObjBase {
    virtual ~TObjEnvSound();
    u8 unk_90[0x4];
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    virtual void render();
    virtual void run_task();
    static s32 is_sound_enabled(void *self, s32 cue);
};

typedef char TObjEnvSound_size[sizeof(TObjEnvSound) == 0xA0 ? 1 : -1];

extern "C" {
void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjEnvSound.cpp ---
extern "C" {
void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
