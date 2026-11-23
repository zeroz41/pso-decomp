#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/effect/enemy/TEneParticleCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

CollisionBody TEneParticleCtrl::collision_body = {{0.0f, 0.0f, 0.0f}, 20.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

const char *TEneParticleCtrl::class_name = "TEneParticleCtrl";

void *TEneParticleCtrl::get_center() { return get_position_ptr(); }

void TEneParticleCtrl::set_param(s32 index) { if (particle) particle->set_param_ptr(index); }
void TEneParticleCtrl::free_particle_ctrl() { if (particle) particle->enable(); }

TEneParticleCtrl::~TEneParticleCtrl() {
    if (particle != NULL) {
        TParticleCtrl::release(particle);
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TEneParticleCtrl::TEneParticleCtrl(TObjChara *owner, s32 effect_index) : TObjCollidable(owner) {
    m_name = class_name;
    init_collision_body_parts(this, &collision_body, 1);
    register_object_by_id();
    bodies->flags &= ~1;
    owner_id = owner->get_entity_id();
    set_position_from(&owner->center);
    VecCopy(&effect_pos, &owner->body_center);
    effect = effect_index;
    particle = spawn_continuous_particle_effect_with_flags(&effect_pos, effect, 0x10);
    if (particle != NULL) {
        particle->set_owner_id(entity_id);
    }
}

void *TEneParticleCtrl::get_position_ptr() { return &position; }
