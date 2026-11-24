#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TUnk_804909C4.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/AngleUnits.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjBase.h"

CollisionBody dark_gunner_shot_collision_body[] = {
    {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f}
};

s32 TUnk_804909C4::check_player_hits(u16 id) {
    TObjCollidable *owner;
    s32 result = 0;
    s32 i;
    TObjChara *target;
    owner = find_entity_by_id(id);
    if (owner == NULL) {
        return 0;
    }
    owner->bodies->flags &= ~1;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    check_enemy_body_collisions(this);
    owner->bodies->flags |= 1;
    if (bodies->flags & 0x180000) {
        for (i = 0; i < 16; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(target) != 0 && target != owner) {
                DirectAttackPayload hit = {0, 0.0f};
                hit.power = TObjEneDarkGunner::get_int_parameter(3);
                target->receive_direct_attack(owner, hit, NULL, -1, -1);
                target->apply_knockback_from_attacker((u8 *)owner, 3.0f);
                result = 1;
            }
        }
    }
    return result;
}

void TUnk_804909C4::run_task() {
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    if (trail != NULL) {
        trail->set_position(&position);
    }
    if (check_player_hits(owner_id) != 0) {
        queue_destruction();
        return;
    }
    if (--lifetime <= 0) {
        queue_destruction();
    }
}

TUnk_804909C4::~TUnk_804909C4() {
    free_collision_body_parts(this);
    if (trail != NULL) {
        trail->queue_destruction();
    }
}

TUnk_804909C4::TUnk_804909C4(u8 *owner, saddr start, saddr target) : TObjCollidable(tl_04) {
    CsnHit *wall;
    init_collision_body_parts(this, dark_gunner_shot_collision_body, 1);
    bodies->radius = 0.75f * dark_gunner_shot_speed;
    owner_id = ((TObjBase *)owner)->get_entity_id();
    trail_particle_id = ((TObjEneDarkGunner *)owner)->is_death_gunner() != 0 ? 0xDA : 0xD5;
    room = ((TObjBase *)owner)->room;
    VecCopy(&position, (const Vec *)start);
    VecCopy(&velocity, (const Vec *)target);
    subtract_vector(&velocity, (const Vec *)start);
    velocity.y = 0.0f;
    vec_set_length(&velocity, dark_gunner_shot_speed);
    trail_rotation[0] = 0;
    trail_rotation[1] = (s32)(RADIANS_TO_ANGLE * atan2_float(velocity.x, velocity.z)) + 0x4000;
    trail_rotation[2] = 0x4000;
    trail = (TParticleCtrl *)spawn_particle_effect_with_rotation(&position, trail_rotation, trail_particle_id, 0x42);
    {
        Vec end = velocity;
        vec_set_length(&end, 500.0f);
        vec3_add_to(&end, &position);
        wall = csnVector(&position, &end, -1);
    }
    if (wall != NULL) {
        lifetime = (s32)(vec_xz_distance(&position, &wall->contact->point) / dark_gunner_shot_speed);
    } else {
        lifetime = (s32)(500.0f / dark_gunner_shot_speed);
    }
}
