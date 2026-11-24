#ifndef PSO_TECHNIQUE_TTIMEDSOUNDEFFECT_H
#define PSO_TECHNIQUE_TTIMEDSOUNDEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// A sound effect played once at a position, kept alive for `frames` frames and stopped when it is
// destroyed (callers: TGoGoBallGoal::update_effects, TTecGrantsEffect::run_task).
class TTimedSoundEffect : public TObject {
public:
    TTimedSoundEffect(Vec *pos, s16 frames, s32 sound, s32 pitch, TObject *parent);
    virtual ~TTimedSoundEffect();
    virtual void run_task();
    s16 frames; // name inferred: run_task destroys the object once age passes it
    s16 age; // name inferred: counted up by run_task
    s32 sound; // name inferred: the sound effect id play_sound_effect takes
    s32 sound_handle; // name inferred: play_sound_effect's result, stopped by the dtor
};
LAYOUT_ASSERT(TTimedSoundEffect_size, sizeof(TTimedSoundEffect) == 0x28);

#endif
