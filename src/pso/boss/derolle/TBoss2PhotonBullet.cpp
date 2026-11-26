#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TBoss2BreakUp.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"

#include "pso/boss/derolle/TBoss2PhotonPad.h"

#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"

#include "pso/boss/derolle/TBoss2PhotonBullet.h"


#include "pso/system/vector.h"

#include "pso/object/base/TAttackCollider.h"

#include <stddef.h>

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/ActorCollision.h"

#include "pso/effect/particle/TParticleCtrl.h"


// The bullet level table, the two hit-check arguments and the class names, in their original .rodata order.
const Boss2PhotonLevel TBoss2PhotonPad::bullet_level_param_table[3] = {
    { 3, 1, 0x3000, 3.5f },
    { 5, 1, 0x2000, 5.0f },
    { 5, 1, 0x4000, 5.0f },
};

extern const DirectAttackPayload boss2_photon_bullet_attack[1] = { { 0, 3.0f } };

extern const AreaAttackContact boss2_photon_bullet_hit_args = {3.0f, 1};

const char *TBoss2PhotonPad::name = "TBoss2PhotonPad";

const char *TBoss2PhotonBullet::name = "TBoss2PhotonBullet";

TBoss2PhotonPad::TBoss2PhotonPad(TObject *parent, Vec *start, Vec *dir, s32 level) : TObject(parent) {
    m_name = TBoss2PhotonPad::name;
    origin = start;
    this->level = level;
    VecCopy(&pos, dir);
    rotate_xz_pair_by_angle(&pos.x, &pos.z, (s32)(-(bullet_level_param_table[this->level].spread / 2)));
    shots = bullet_level_param_table[this->level].shots;
    timer = 0;
}

TBoss2PhotonPad::~TBoss2PhotonPad() {

}

void TBoss2PhotonPad::run_task() {
    timer--;
    if (timer <= 0) {
        TBoss2DeRolLe *boss = TBoss2DeRolLe::get_instance();
        if (boss != NULL) {
            new TBoss2PhotonBullet(m_up, boss, origin, &pos, (1.5f) * bullet_level_param_table[level].speed);
        }
        timer = bullet_level_param_table[level].interval;
        rotate_xz_pair_by_angle(&pos.x, &pos.z, (s32)(bullet_level_param_table[level].spread / bullet_level_param_table[level].shots));
        shots--;
        if (shots == 0) {
            queue_destruction();
        }
    }
}

void TBoss2PhotonPad::render() {  }

TBoss2PhotonBullet::TBoss2PhotonBullet(TObject *parent, TObjBase *owner, Vec *pos, Vec *dir, f32 speed) : TAttackCollider(parent, owner) {
    m_name = TBoss2PhotonBullet::name;
    VecCopy(&travel, pos);
    VecCopy(&position, &travel);
    VecCopy(&aim, dir);
    bodies->radius = 3.0f;
    shadow_pos.x = 0.0f;
    shadow_pos.y = 0.0f;
    shadow_pos.z = 0.0f;
    this->speed = speed;
    age = 0;
    grounded = 0;
    fall = 0.0f;
    effect = NULL;
}

TBoss2PhotonBullet::~TBoss2PhotonBullet() {
    if (effect != NULL) { effect->queue_destruction(); effect = NULL; }
}

#pragma push
#pragma fp_contract on
void TBoss2PhotonBullet::run_task() {
    if (travel.y > 8.7f) {
        fall += 0.05f;
        if (fall >= 3.0f) {
            fall = 3.0f;
        }
        travel.y = travel.y - fall;
        travel.x = 2.0f * aim.x + travel.x;
        travel.z = 2.0f * aim.z + travel.z;
    } else {
        travel.y = 8.7f;
        travel.x = aim.x * speed + travel.x;
        travel.z = aim.z * speed + travel.z;
    }
    position.x = travel.x;
    position.z = travel.z;
    if (effect == NULL) {
        effect = spawn_continuous_particle_effect_with_flags(&travel, 0xDF, 0x40);
    } else {
        effect->set_position(&travel);
    }
    if (age % 15 == 0) {
        if (project_actor_to_ground(this, &position, &shadow_pos) != 0) {
            grounded |= 1;
        } else {
            grounded &= ~1;
        }
    }
    if (position.x <= boss2_platform_max && position.x >= boss2_platform_min) {
        DirectAttackPayload attack = boss2_photon_bullet_attack[0];
        attack.power = TBoss2DeRolLe::get_bullet_power();
        if (deliver_direct_no_history(&boss2_photon_bullet_hit_args, &attack) != 0) {
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
void TBoss2PhotonBullet::render() {
    if (grounded & 1) {
        Vec scale = { 1.0f, 1.0f, 1.0f };
        TObjEneDD::draw_oriented_shadow(&position, &shadow_pos, 0, &scale);
    }
}
