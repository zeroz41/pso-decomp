#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTPARTICLE_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTPARTICLE_H
#include "types.h"
#include "pso/weapon/shoot/TItemShoot.h"

class TParticleCtrl;

class TItemShootParticle : public TItemShoot {
public:
    TItemShootParticle(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemShootParticle();
    virtual void hook();
    TParticleCtrl *m_emitters[2]; // the effects spawn_slot_emitter puts in its two slots
    u16 m_effect_flags;           // OR'd with 0x40 into each spawned effect's flags
    u8 pad_62[0x2];
public:
    s32 spawn_slot_emitter(s32 effect_id, s32 slot);
    void set_particle_flags(s16 flags);
};
LAYOUT_ASSERT(TItemShootParticle_size, sizeof(TItemShootParticle) == 0x64);

#endif
