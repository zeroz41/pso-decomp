#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUND_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUND_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// A row of an area's environment sound table (environment_sound_tables_by_area), picked by set
// parameter 0: the sound cue and how it plays (1 at the object's position, 2 with a volume).
struct EnvSoundRow {
    s32 cue;
    s32 mode;
};

struct TObjEnvSound : public TObjBase {
    TObjEnvSound(TObject *parent, void *set_data);
    virtual ~TObjEnvSound();
    f32 radius;        // scale.z, or 200 when that is not positive
    s32 attenuation;   // set_params[1] clamped to -127..127
    EnvSoundRow sound; // the area's table row; mode 1 plays once in range, 2 keeps playing with the attenuation
    virtual void render();
    virtual void run_task();
    // Whether the camera is within the given squared distance of the object.
    s32 is_camera_in_range(f32 radius_squared);
    s32 is_sound_enabled(s32 cue);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSound_size, sizeof(TObjEnvSound) == 0xA0);

#endif
