#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/effect/photon/TPhotonLaser.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/effect/photon/TPhotonLeilla.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on


const char *TPhotonLaser::class_name = "TPhotonLaser";

void TPhotonLaser::render() {
    TParticleCtrl::begin_effect_render();
    TParticleCtrl::end_effect_render();
}

void TPhotonLaser::run_task() {
    Vec step;
    Vec turned;
    TObjCollidable *owner;

    timer += 1.0f;
    step.y = step.x = 0.0f;
    step.z = 10.0f;
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(NULL, 182.04445f * (f32)angle);
    rotate_vector_by_matrix(0, &step, &turned);
    pop_matrices(1);
    vec3_add_to(&pos, &turned);
    angle += 0x24;
    vec3_add_to(&pos, &vel);
    if (emitter != NULL) {
        emitter->set_position(&pos);
    }
    owner = find_entity_by_id(owner_id);
    if (owner == NULL) {
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
    } else if (pos.y < owner->position.y) {
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
        spawn_particle_effect(&pos, 0x13D);
        queue_destruction();
    }
}

TPhotonLaser::~TPhotonLaser() {
    unregister_object_by_id();
    free_collision_body_parts(this);
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

TPhotonLaser::TPhotonLaser(PhotonLaserParams *params, TObject *parent, u16 owner) : TObjChara(parent) {
    m_name = class_name;
    VecCopy(&origin, VecCopy(&pos, &params->pos));
    owner_id = owner;
    VecCopy(&vel, &params->dir);
    vel.x *= params->speed;
    vel.y *= params->speed;
    vel.z *= params->speed;
    range = params->range;
    pad_35C = params->pad_2C;
    emitter = create_particle_emitter(&pos, 0x134);
    angle = 0;
}
