#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/effect/photon/TPhotonConcentrate.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"

const char *TPhotonConcentrate::class_name = "TPhotonConcentrate";

void TPhotonConcentrate::render() {
    TParticleCtrl::begin_effect_render();
    TParticleCtrl::end_effect_render();
}

void TPhotonConcentrate::run_task() {
    Vec delta;
    TObjCollidable *owner_obj;
    u32 phase;

    VecCopy(&delta, &pos);
    subtract_vector(&delta, &target);
    dist = vector_length(&delta);
    if (dist < 10.0f) {
        emitter->queue_destruction();
        emitter = NULL;
        spawn_particle_effect(&pos, 0xC6);
        queue_destruction();
        return;
    }
    if (xyz_distance(&origin, &pos) > range) {
        queue_destruction();
        return;
    }
    vec3_add_to(&pos, &vel);
    {
        Vec span = target;
        subtract_vector(&span, &origin);
        total = vector_length(&span);
        if (0.0f == total) {
            total = 0.00001f;
        }
        phase = 180.0f * (dist / total);
        {
            Vec offset;
            Vec turned;
            offset.x = 4.0f * (total / 10.0f) * sin_table_lookup(182.04445f * (f32)phase);
            offset.y = (offset.z = 0.0f);
            push_matrix_from(&identity_matrix);
            rotate_matrix_z(NULL, 182.04445f * (f32)angle);
            rotate_vector_by_matrix(0, &offset, &turned);
            pop_matrices(1);
            VecCopy(&offset, &turned);
            push_matrix_from(&identity_matrix);
            owner_obj = owner;
            if (owner_obj != NULL) {
                rotate_matrix_y(NULL, 182.04445f * (f32)(owner_obj->rotation_y - 0x5A));
                rotate_vector_by_matrix(0, &offset, &turned);
            }
            pop_matrices(1);
            {
                Vec emit_pos = pos;
                vec3_add_to(&emit_pos, &turned);
                if (emitter != NULL) {
                    emitter->set_position(&emit_pos);
                }
            }
        }
    }
}

TPhotonConcentrate::~TPhotonConcentrate() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

TPhotonConcentrate::TPhotonConcentrate(PhotonConcentrateParams *params, TObject *parent, u16 owner_id)
    : TObjCollidable(parent) {
    m_name = class_name;
    VecCopy(&origin, VecCopy(&pos, &params->origin));
    VecCopy(&target, &params->target);
    VecCopy(&vel, &params->direction);
    vel.x *= params->speed;
    vel.y *= params->speed;
    vel.z *= params->speed;
    range = params->range;
    pad_E8 = params->pad_2C;
    target_object = params->target_object;
    angle = params->angle;
    owner = find_entity_by_id(owner_id);
    emitter = create_particle_emitter(&pos, 0x135);
}
