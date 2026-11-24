#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/AreaAttackContact.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter_Eff_Rush.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter_Eff_TpAbsorb1.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
}

const char *TObjEneDellBiter_Eff_Rush__name = "TObjEneDellBiter_Eff_Rush";
const char *TObjEneDellBiter_Eff_TpAbsorb1__class_name = "TObjEneDellBiter_Eff_TpAbsorb1";
extern const AreaAttackContact dell_biter_tp_absorb_hit_params = {3.0f, 3};
extern const DirectAttackPayload dell_biter_tp_absorb_attack = {0, 20.0f};

#pragma fp_contract on

TObjEneDellBiter_Eff_Rush::TObjEneDellBiter_Eff_Rush(
    TObject *parent, TObjBase *source, TObjChara *recipient, f32 speed)
    : TObject(parent) {
    Vec displacement;
    m_name = TObjEneDellBiter_Eff_Rush__name;
    target = recipient;
    strength = speed;
    pad_30 = 0;
    VecCopy(&displacement, &recipient->position);
    subtract_vector(&displacement, &source->position);
    displacement.y = 0.0f;
    direction.x = sin_table_lookup(source->rotation_y);
    direction.y = 0.0f;
    direction.z = cos_table_lookup(source->rotation_y);
    if (is_vec_xz_cross_negative(&direction, &displacement) != 0) {
        rotate_xz_pair_by_angle(&direction.x, &direction.z, -0x1800);
    } else {
        rotate_xz_pair_by_angle(&direction.x, &direction.z, 0x1800);
    }
}

TObjEneDellBiter_Eff_Rush::~TObjEneDellBiter_Eff_Rush() {}

void TObjEneDellBiter_Eff_Rush::run_task() {
    if (is_player_entity_id(target->get_entity_id()) != 0) {
        queue_destruction();
        return;
    }
    if (target->is_alive() == 0) {
        queue_destruction();
        return;
    }
    if (target->obj_isState2_324() != 0) {
        queue_destruction();
        return;
    }
    f32 speed = strength;
    if (speed <= 0.02f) {
        queue_destruction();
        return;
    }
    target->velocity.x = direction.x * speed;
    target->velocity.z = direction.z * strength;
    strength *= 0.8f;
}

void TObjEneDellBiter_Eff_Rush::render() {}

TObjEneDellBiter_Eff_TpAbsorb1::TObjEneDellBiter_Eff_TpAbsorb1(
    TObject *parent, TObjBase *owner, const Vec *origin, s32 angle, AreaAttackHistory *history, f32 attack_power)
    : TUnk_804928CC(parent, owner) {
    m_name = TObjEneDellBiter_Eff_TpAbsorb1__class_name;
    power = attack_power;
    distance = 0.0f;
    sample_distance = 0.0f;
    VecCopy(&position, origin);
    direction.x = sin_table_lookup(angle);
    direction.y = 0.0f;
    direction.z = cos_table_lookup(angle);
    attack_history = history;
    bodies->shape = 1;
    DelbiterParticleAngles angles = {0, angle - 0x4000, 0x4000};
    effect = (TParticleCtrl *)create_particle_controller_with_angles(&position, &angles, 0x210, 0x32, 2);
    effect->clear_active_flag();
}

TObjEneDellBiter_Eff_TpAbsorb1::~TObjEneDellBiter_Eff_TpAbsorb1() {
    if (effect != NULL) {
        effect->queue_destruction();
    }
}

void TObjEneDellBiter_Eff_TpAbsorb1::run_task() {
    Vec destination;
    Vec sample;
    DirectAttackPayload attack;
    f32 step;
    if (effect != NULL) {
        VecCopy(&destination, &position);
        destination.x += 5.0f * direction.x;
        step = 16.0f;
        destination.z += 5.0f * direction.z;
        distance += 5.0f;
        while (distance > sample_distance) {
            VecCopy(&sample, &position);
            sample.x += sample_distance * direction.x;
            sample.z += sample_distance * direction.z;
            if (effect != NULL) {
                effect->set_position(&sample);
            }
            sample_distance += step;
        }
        sample_distance -= 5.0f;
        distance -= 5.0f;
        if (csnVector(&position, &destination, 0x1EFF) != 0) {
            queue_destruction();
            return;
        }
        VecCopy(&position, &destination);
        bodies->half_width = 2.5f;
        bodies->radius = 2.5f;
        update_enemy_collision_flags();
        if (bodies->flags & 0x200000) {
            queue_destruction();
            return;
        }
        attack.kind = dell_biter_tp_absorb_attack.kind;
        attack.power = power;
        call_vt13_with_default((void *)&dell_biter_tp_absorb_hit_params, &attack, (saddr)attack_history);
        return;
    }
    queue_destruction();
}

void TObjEneDellBiter_Eff_TpAbsorb1::render() {}
