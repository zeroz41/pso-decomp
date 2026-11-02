#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TObjEneDellBiter_Eff_Rush.h"
#include "pso/unk/TObjEneDellBiter_Eff_TpAbsorb1.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/system/vector.h"
#include "pso/player/TObjChara.h"

extern "C" {
u32 csnVector(void *, void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void *create_particle_controller_with_angles(void *, void *, s32, s32, u16);
extern const char *TObjEneDellBiter_Eff_TpAbsorb1__class_name;
extern u8 lbl_8047511C[];
extern s32 lbl_80475124[];
extern DelbiterParticleAngles lbl_8047512C;
}

extern "C" {
u16 get_entity_id(void *);
s32 is_player_entity_id(u16);
f32 subtract_vector(void *, void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 is_vec_xz_cross_negative(void *, void *);
s32 rotate_xz_pair_by_angle(void *, void *, s32);
extern const char *TObjEneDellBiter_Eff_Rush__name;
}

#pragma fp_contract on

TObjEneDellBiter_Eff_Rush::TObjEneDellBiter_Eff_Rush(
    TObject *parent, TObjBase *source, TObjChara *recipient, f32 speed)
    : TObject(parent) {
    Vec displacement;
    m_name = TObjEneDellBiter_Eff_Rush__name;
    target = recipient;
    strength = speed;
    field_30 = 0;
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
    if (is_player_entity_id(get_entity_id(target)) != 0) {
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
    target->x_speed = direction.x * speed;
    target->m_310 = direction.z * strength;
    strength *= 0.8f;
}

void TObjEneDellBiter_Eff_Rush::render() {}

TObjEneDellBiter_Eff_TpAbsorb1::TObjEneDellBiter_Eff_TpAbsorb1(
    TObject *parent, TObjBase *owner, const Vec *origin, s32 angle, AreaAttackHistory *history, f32 attack_power)
    : TUnk_804928CC(parent, owner) {
    DelbiterParticleAngles angles;
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
    angles.y = lbl_8047512C.y;
    angles.x = lbl_8047512C.x;
    angles.z = lbl_8047512C.z;
    angles.y = angle - 0x4000;
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
        attack.kind = lbl_80475124[0];
        attack.power = power;
        call_vt13_with_default(lbl_8047511C, &attack, (s32)attack_history);
        return;
    }
    queue_destruction();
}

void TObjEneDellBiter_Eff_TpAbsorb1::render() {}
