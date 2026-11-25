#ifndef PSO_BOSS_TBOSS3VOLOPTPARTICLESPRAY_H
#define PSO_BOSS_TBOSS3VOLOPTPARTICLESPRAY_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// Sprays the particle effect effect_id around pos for lifetime frames: rate
// particles per frame, each up to spread away in a random direction.
class TBoss3VoloptParticleSpray : public TObject {
public:
    s32 effect_id;
    s32 lifetime;
    f32 rate;
    f32 pending;
    Vec pos;
    s32 rotation[3];
    f32 spread;

    TBoss3VoloptParticleSpray(Vec *pos, s32 effect_id, s32 lifetime, s32 *rotation, f32 rate, f32 spread);
    virtual ~TBoss3VoloptParticleSpray();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss3VoloptParticleSpray_size, sizeof(TBoss3VoloptParticleSpray) == 0x48);

#endif
