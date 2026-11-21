#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBULLET_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBULLET_H

#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>
class TParticleCtrl;

struct Vec;

struct TBoss1DragonEffBullet : public TObject {
    TBoss1DragonEffBullet(TObject *parent, const Vec *start, const Vec *target);
    virtual ~TBoss1DragonEffBullet();
    virtual void render();
    virtual void run_task();

    Vec position;
    Vec direction;
    s32 lifetime;
    s32 state; // 0: flight, 1: impact, 2: delayed destruction.
    f32 traveled_distance;
    f32 target_distance;
    TParticleCtrl *trail;
    TParticleCtrl *secondary_emitter;
};

typedef char TBoss1DragonEffBullet_position[offsetof(TBoss1DragonEffBullet, position) == 0x1C ? 1 : -1];
typedef char TBoss1DragonEffBullet_direction[offsetof(TBoss1DragonEffBullet, direction) == 0x28 ? 1 : -1];
typedef char TBoss1DragonEffBullet_lifetime[offsetof(TBoss1DragonEffBullet, lifetime) == 0x34 ? 1 : -1];
typedef char TBoss1DragonEffBullet_state[offsetof(TBoss1DragonEffBullet, state) == 0x38 ? 1 : -1];
typedef char TBoss1DragonEffBullet_traveled[offsetof(TBoss1DragonEffBullet, traveled_distance) == 0x3C ? 1 : -1];
typedef char TBoss1DragonEffBullet_target[offsetof(TBoss1DragonEffBullet, target_distance) == 0x40 ? 1 : -1];
typedef char TBoss1DragonEffBullet_trail[offsetof(TBoss1DragonEffBullet, trail) == 0x44 ? 1 : -1];
typedef char TBoss1DragonEffBullet_secondary[offsetof(TBoss1DragonEffBullet, secondary_emitter) == 0x48 ? 1 : -1];
typedef char TBoss1DragonEffBullet_size[sizeof(TBoss1DragonEffBullet) == 0x4C ? 1 : -1];
#endif
