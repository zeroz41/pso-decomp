#ifndef PSO_EFFECT_ENEMY_TENEPARTICLECTRL_H
#define PSO_EFFECT_ENEMY_TENEPARTICLECTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
class TObjChara;

// A collidable that carries a continuous particle effect at its owner's body centre.
struct TEneParticleCtrl : public TObjCollidable {
    TEneParticleCtrl(TObjChara *owner, s32 effect_index);
    virtual ~TEneParticleCtrl();
    virtual void *get_center();
    u16 owner_id;  // get_entity_id(owner) in the ctor
    u8 pad_ae[0x2];
    u32 effect;  // the effect index the particle control was spawned with
    Vec effect_pos;  // the owner's body centre at spawn, the effect's anchor
    TParticleCtrl *particle;  // spawn_continuous_particle_effect_with_flags(&effect_pos, effect, 0x10)
    void set_param(s32 index);
    void free_particle_ctrl();
    void *get_position_ptr();

    static const char *class_name;
    static CollisionBody collision_body;  // the one body the constructor registers
};

LAYOUT_ASSERT(TEneParticleCtrl_size, sizeof(TEneParticleCtrl) == 0xC4);

#endif
