#include "pso/boss/TUnk_80484A94.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"

extern "C" {
extern GC_Mtx identity_matrix;
}

static const Vec volopt_shot_forward = {0.0f, 0.0f, 0.0f};

static CollisionBody volopt_shot_collision_body[1] = {
    {{0.0f, 0.0f, 0.0f}, 5.0f, 0.0f, 0, 0x10103},
};

s32 TUnk_80484A94::try_capture_target() {
    s32 i;
    TObjChara *target;
    TObject *owner;
    TObjPlayer::init_all_slots();
    this->check_object_collisions();
    if (bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(reinterpret_cast<const TObjCollidable *>(target)) != 0) {
                DirectAttackPayload hit = {0, 0.0f};
                target->receive_direct_attack(m_up, hit, NULL, -1, -1);
                owner = m_up;
                if (owner != NULL) {
                    ((TBoss3Volopt *)owner)->create_cage(target->get_entity_id());
                }
                return 1;
            }
        }
    }
    return 0;
}

void TUnk_80484A94::render() {}

void TUnk_80484A94::run_task() {
    TObjPlayer *player = get_player_by_client_id(target_id);
    if (player != NULL) {
        Vec steer = player->body_center;
        subtract_vector(&steer, &position);
        vec_set_length(&steer, TObjVoloptCage::get_float_param(1));
        vec3_add_to(&velocity, &steer);
        vec_set_length(&velocity, TObjVoloptCage::get_float_param(0));
    }
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    direction_to_rotation_yx((u8 *)&velocity, &rotation_y, &rotation_z);
    rotation_z -= 0x4000;
    if (trail != NULL) {
        ((TParticleCtrl *)trail)->set_position(&position);
        ((TParticleCtrl *)trail)->set_direction(&rotation_x);
    }
    if (glow != NULL) {
        ((TParticleCtrl *)glow)->set_position(&position);
        ((TParticleCtrl *)glow)->set_direction(&rotation_x);
    }
    if (csnVector(&prev_position, &position, -1) != 0) {
        queue_destruction();
        return;
    }
    if (position.y < 25.0f && try_capture_target() != 0) {
        queue_destruction();
    }
    if (--lifetime <= 0) {
        queue_destruction();
        return;
    }
    play_persistent_sound(0x4003C11D, this, &position, 0, 0);
}

TUnk_80484A94::~TUnk_80484A94() {
    free_collision_body_parts(this);
    if (trail != NULL) {
        ((TObject *)trail)->queue_destruction();
    }
    if (glow != NULL) {
        ((TObject *)glow)->queue_destruction();
    }
    if (m_up != NULL) {
        clear_cage_shot_in_flight((TObjEnemyCustom *)m_up);
    }
}

TUnk_80484A94::TUnk_80484A94(TObjEnemy *owner, Vec *pos, s32 target) : TObjCollidable(owner) {
    init_collision_body_parts(this, volopt_shot_collision_body, 1);
    entity_id = owner->get_entity_id();
    VecCopy(&position, pos);
    target_id = target;
    rotation_x = 0;
    trail = spawn_particle_effect_with_rotation(&position, &rotation_x, 0x11C, 2);
    glow = spawn_particle_effect_with_rotation(&position, &rotation_x, 0x11D, 2);
    push_matrix_from(identity_matrix);
    {
        Vec dir = volopt_shot_forward;
        dir.z = TObjVoloptCage::get_float_param(0);
        rotate_matrix_y(0, ((TObjBase *)owner)->rotation_y);
        rotate_vector_by_matrix(0, &dir, &velocity);
    }
    pop_matrix();
    lifetime = TObjVoloptCage::get_int_param(0);
}

// Float twin of TObjVoloptCage::get_int_param (volopt_cage_params).
f32 TObjVoloptCage::get_float_param(s32 index) {
    return volopt_cage_params->float_params[index];
}

void clear_cage_shot_in_flight(TObjEnemyCustom *boss) {
    boss->behavior_flags &= ~0x100000;
}
