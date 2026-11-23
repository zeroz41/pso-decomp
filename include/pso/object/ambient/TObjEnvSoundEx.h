#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUNDEX_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUNDEX_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEnvSoundEx : public TObjBase {
    TObjEnvSoundEx(TObject *parent, saddr set_data);
    virtual ~TObjEnvSoundEx();
    virtual void run_task();
    s32 max_volume;     // set param 1, clamped to -127..127
    f32 volume;         // fades by volume_step towards max_volume in range, towards -127 outside
    f32 volume_step;    // |scale.y|
    s32 sound_id;       // area table row picked by set param 0
    s32 mode;           // 1 positional, 2 volume-driven
    f32 range;          // scale.z, 200 when not positive
    s32 init_sound_params();
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSoundEx_size, sizeof(TObjEnvSoundEx) == 0xA8);
#endif
