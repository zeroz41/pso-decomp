#ifndef PSO_TECHNIQUE_TTECGRANTSEFFECT_H
#define PSO_TECHNIQUE_TTECGRANTSEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TParticleCtrl;
class TObjBase;

// The Grants effect TTecGrants::run_task spawns on its target: keeps one particle emitter per
// grants_effect_emitter_table part and a looping sound alive, spawns a TTecGrantsFlash flash every fifth
// frame and, after 30 frames, the closing effects of technique_effect_entry_table and a timed sound.

class TTecGrantsEffect : public TObject {
public:
    TTecGrantsEffect(TObjBase *src, s32 level, TObject *parent);
    virtual ~TTecGrantsEffect();
    virtual void run_task();
    TParticleCtrl **emitters; // one per part of grants_effect_emitter_table[tier]
    s32 sound;                // play_sound_effect handle, stopped by the dtor
    s32 tier;                 // get_technique_level_tier(level)
    s32 level;                // technique level, clamped to 0..30
    s16 timer;                // frames since spawn; the effect ends at 30
    u16 owner_id;             // entity id of the target the effect follows
    Vec position;             // the target's position at spawn
};
LAYOUT_ASSERT(TTecGrantsEffect_size, sizeof(TTecGrantsEffect) == 0x3C);

#endif
