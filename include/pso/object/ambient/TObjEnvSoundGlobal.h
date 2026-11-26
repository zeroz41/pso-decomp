#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEnvSoundGlobal : public TObjBase {
    TObjEnvSoundGlobal(TObject *parent, saddr set_data);
    virtual ~TObjEnvSoundGlobal();
    f32 attenuation;   // set_params[1] clamped to -127..127
    u32 cue;           // the sound cue of the area's table row, -1 for none
    s32 mode;          // the row's mode: 1 plays at its position, 2 plays everywhere with the attenuation
    s32 setup_sound();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSoundGlobal_size, sizeof(TObjEnvSoundGlobal) == 0x9C);

extern "C" {
void copy_env_sound_row(void *p, void *q);
}

#endif
