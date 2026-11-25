#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/barbaray/TBoss7PhotonBullet.h"
#include "pso/boss/barbaray/TBoss7PhotonPad.h"
#include "pso/boss/barbaray/TBoss7BreakUp.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/vector.h"

#pragma fp_contract on
// The original emits code in reverse definition order, including the bullet and pad vtables.
#pragma defer_codegen on

struct Boss7PhotonLevel {
    s32 shots;
    s32 interval;
    s32 spread;
    f32 speed;
};

// The level table, hit-check arguments and class strings occupy consecutive .rodata.
extern const Boss7PhotonLevel boss7_photon_bullet_level_table[3] = {
    {3, 1, 0x3000, 3.5f},
    {5, 1, 0x2000, 5.0f},
    {5, 1, 0x4000, 5.0f},
};
extern const DirectAttackPayload boss7_photon_bullet_attack[1] = {{0, 3.0f}};
extern const AreaAttackContact boss7_photon_bullet_hit_args = {3.0f, 1};
const char *TBoss7PhotonPad::name = "TBoss7PhotonPad";
const char *TBoss7PhotonBullet::name = "TBoss7PhotonBullet";


TBoss7PhotonPad::TBoss7PhotonPad(TObject *parent, const Vec *shot_origin, const Vec *direction, s32 shot_level)
    : TObject(parent) {
    m_name = TBoss7PhotonPad::name;
    origin = shot_origin;
    level = shot_level;
    VecCopy(&pos, direction);
    rotate_xz_pair_by_angle(&pos.x, &pos.z, (s32)(-(boss7_photon_bullet_level_table[level].spread / 2)));
    shots = boss7_photon_bullet_level_table[level].shots;
    timer = 0;
}

TBoss7PhotonPad::~TBoss7PhotonPad() {}

void TBoss7PhotonPad::run_task() {
    timer--;
    if (timer <= 0) {
        TBoss7DeRolLeC *boss = TBoss7Joint::get_state();
        if (boss != NULL) {
            new TBoss7PhotonBullet(m_up, boss, origin, &pos, 1.5f * boss7_photon_bullet_level_table[level].speed);
        }
        timer = boss7_photon_bullet_level_table[level].interval;
        rotate_xz_pair_by_angle(&pos.x, &pos.z, (s32)(boss7_photon_bullet_level_table[level].spread / boss7_photon_bullet_level_table[level].shots));
        shots--;
        if (shots == 0) {
            queue_destruction();
        }
    }
}

void TBoss7PhotonPad::render() {  }

TBoss7PhotonBullet::TBoss7PhotonBullet(TObject *parent, TObjBase *owner, const Vec *origin, const Vec *aim, f32 scale)
    : TAttackCollider(parent, owner) {
    m_name = TBoss7PhotonBullet::name;
    VecCopy(&position, VecCopy(&travel, origin));
    VecCopy(&this->aim, aim);
    bodies->radius = 3.0f;
    shadow_pos.x = 0.0f;
    shadow_pos.y = 0.0f;
    shadow_pos.z = 0.0f;
    shadow_scale.x = 1.0f;
    shadow_scale.y = 1.0f;
    shadow_scale.z = 1.0f;
    speed = scale;
    age = 0;
    grounded = 0;
    fall = 0.0f;
    effects[0] = spawn_continuous_particle_effect_with_flags(&travel, 0x202, 0x40);
    effects[1] = spawn_continuous_particle_effect_with_flags(&travel, 0x203, 0x40);
}

TBoss7PhotonBullet::~TBoss7PhotonBullet() {
    if (effects[0] != NULL) {
        effects[0]->queue_destruction();
    }
    if (effects[1] != NULL) {
        effects[1]->queue_destruction();
    }
}

#pragma push
#pragma opt_loop_invariants off
void TBoss7PhotonBullet::run_task() {
    s32 i;
    if (travel.y > 18.7f) {
        fall += 0.05f;
        if (fall >= 3.0f) {
            fall = 3.0f;
        }
        travel.y -= fall;
        travel.x = (2.0f) * aim.x + travel.x;
        travel.z = (2.0f) * aim.z + travel.z;
    } else {
        travel.y = 18.7f;
        travel.x = aim.x * speed + travel.x;
        travel.z = aim.z * speed + travel.z;
    }
    position.x = travel.x;
    position.z = travel.z;
    for (i = 0; i != 2; i++) {
        if (effects[i] != NULL) {
            effects[i]->set_position(&travel);
        }
    }
    if (age % 16 == 0) {
        if (project_actor_to_ground(this, &position, &shadow_pos) != 0) {
            grounded |= 1;
        } else {
            grounded &= ~1;
        }
    }
    if (position.x <= boss7_deck_max_x && position.x >= boss7_deck_min_x) {
        DirectAttackPayload attack = boss7_photon_bullet_attack[0];
        attack.power = TBoss7PhotonBullet::get_target_pos_y();
        if (deliver_direct_no_history(&boss7_photon_bullet_hit_args, &attack) != 0) {
            queue_destruction();
            return;
        }
    }
    age++;
    if (age >= 0x78) {
        queue_destruction();
    }
}

#pragma pop

void TBoss7PhotonBullet::render() {
    if (grounded & 1) {
        TObjEneDD::draw_oriented_shadow(&position, &shadow_pos, 0, &shadow_scale);
    }
}
