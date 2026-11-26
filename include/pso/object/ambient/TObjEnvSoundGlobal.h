#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ambient/TObjEnvSound.h"

struct TObjEnvSoundGlobal : public TObjBase {
    TObjEnvSoundGlobal(TObject *parent, void *set_data);
    virtual ~TObjEnvSoundGlobal();
    f32 attenuation;   // set_params[1] clamped to -127..127
    EnvSoundRow sound; // the area's table row, cue -1 for none; mode 1 plays at its position, 2 everywhere with the attenuation
    s32 setup_sound();
    // Copies an area table row (cue and mode) into an object's sound.
    static void copy_pair(EnvSoundRow *dst, EnvSoundRow *src);
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSoundGlobal_size, sizeof(TObjEnvSoundGlobal) == 0x9C);

#endif
