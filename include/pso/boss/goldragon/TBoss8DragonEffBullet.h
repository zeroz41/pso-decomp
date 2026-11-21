#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBULLET_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBULLET_H

#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TParticleCtrl;

struct DragonBulletParticles {
    s32 trail;
    s32 impact;
    s32 burst;
};

struct TBoss8DragonEffBullet : public TObject {
    TBoss8DragonEffBullet(TObject *parent, const Vec *source, const Vec *target,
                         s32 mode, u16 owner_id);
    virtual ~TBoss8DragonEffBullet();
    virtual void render();
    virtual void run_task();

    Vec position;
    Vec direction;
    s32 lifetime;
    s32 state; // Flight, impact, then delayed destruction.
    f32 traveled_distance;
    f32 target_distance;
    s32 mode;
    u16 owner_id;
    TParticleCtrl *trail;
    TParticleCtrl *secondary_emitter;
    const DragonBulletParticles *particles;
};

LAYOUT_ASSERT(TBoss8DragonEffBullet_position, offsetof(TBoss8DragonEffBullet, position) == 0x1C);
LAYOUT_ASSERT(TBoss8DragonEffBullet_direction, offsetof(TBoss8DragonEffBullet, direction) == 0x28);
LAYOUT_ASSERT(TBoss8DragonEffBullet_lifetime, offsetof(TBoss8DragonEffBullet, lifetime) == 0x34);
LAYOUT_ASSERT(TBoss8DragonEffBullet_state, offsetof(TBoss8DragonEffBullet, state) == 0x38);
LAYOUT_ASSERT(TBoss8DragonEffBullet_traveled_distance, offsetof(TBoss8DragonEffBullet, traveled_distance) == 0x3C);
LAYOUT_ASSERT(TBoss8DragonEffBullet_target_distance, offsetof(TBoss8DragonEffBullet, target_distance) == 0x40);
LAYOUT_ASSERT(TBoss8DragonEffBullet_mode, offsetof(TBoss8DragonEffBullet, mode) == 0x44);
LAYOUT_ASSERT(TBoss8DragonEffBullet_owner_id, offsetof(TBoss8DragonEffBullet, owner_id) == 0x48);
LAYOUT_ASSERT(TBoss8DragonEffBullet_trail, offsetof(TBoss8DragonEffBullet, trail) == 0x4C);
LAYOUT_ASSERT(TBoss8DragonEffBullet_secondary_emitter, offsetof(TBoss8DragonEffBullet, secondary_emitter) == 0x50);
LAYOUT_ASSERT(TBoss8DragonEffBullet_particles, offsetof(TBoss8DragonEffBullet, particles) == 0x54);
LAYOUT_ASSERT(TBoss8DragonEffBullet_size, sizeof(TBoss8DragonEffBullet) == 0x58);

#endif
