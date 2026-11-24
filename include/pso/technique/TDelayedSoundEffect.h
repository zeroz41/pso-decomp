#ifndef PSO_TECHNIQUE_TDELAYEDSOUNDEFFECT_H
#define PSO_TECHNIQUE_TDELAYEDSOUNDEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Plays a sound effect at a point once a delay in frames has run out, then
// destroys itself (spawned by Anti, Resta and Reverser).
class TDelayedSoundEffect : public TObject {
public:
    TDelayedSoundEffect(Vec *pos, s16 delay, s32 sound_id, TObject *parent);
    virtual ~TDelayedSoundEffect();
    virtual void run_task();

    s16 m_delay;
    s16 m_timer;
    s32 m_sound_id;
    Vec m_pos;
};
LAYOUT_ASSERT(TDelayedSoundEffect_size, sizeof(TDelayedSoundEffect) == 0x30);

#endif
