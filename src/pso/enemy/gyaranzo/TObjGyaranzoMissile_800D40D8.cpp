#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"
#include "pso/object/TUnk_8049442C.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"

#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/base/TObjBase.h"

void TObjEneGyaranzo::run_miss_reaction() {  }
void TObjEneGyaranzo::run_move_action() {  }
s32 TObjEneGyaranzo::is_target_in_attack_range() { return 0; }
void TObjEneGyaranzo::run_idle_action() {  }

f32 get_gyaranzo_missile_float_parameter(s32 i) {
    return gyaranzo_missile_param_table->floats[i];
}

s32 get_gyaranzo_missile_int_parameter(s32 i) {
    return gyaranzo_missile_param_table->ints[i];
}

void TUnk_8049442C::update_ground_fall(Vec *ground, f32 height) {
    Vec ground_pos;
    s32 hit;
    VecCopy(&ground_pos, &position);
    hit = project_actor_to_ground(this, &ground_pos, 0);
    if (ground != NULL) {
        VecCopy(ground, &ground_pos);
    }
    if (hit == 1) {
        velocity.y += -0.10888889f;
        position.y += velocity.y;
        ground_pos.y += height;
        if (position.y <= ground_pos.y) {
            position.y = ground_pos.y;
            velocity.y = 0.0f;
            actorFlags |= 0x800000;
            return;
        }
        actorFlags &= ~0x800000;
        return;
    }
    actorFlags &= ~0x800000;
}

void TUnk_8049442C::explode() {
    TObjCollidable *owner;
    s32 i;
    TObjChara *target;
    owner = find_entity_by_id(owner_id);
    bodies->radius = 5.0f;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    check_enemy_body_collisions(this);
    if (bodies->flags & 0x180000) {
        for (i = 0; i < 0x10; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(target) != 0 && target != owner) {
                DirectAttackPayload hit = {0, 0.0f};
                hit.power = get_gyaranzo_missile_int_parameter(3);
                target->receive_direct_attack(owner, hit, NULL, -1, -1);
            }
        }
    }
    spawn_particle_effect(&position, 0xFB);
    play_sound_effect(remap_area_sound_id(0x4003A80C, 0x19), &position, 0, 0);
    queue_destruction();
}

void TUnk_8049442C::render() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(mine_textures));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, yaw);
    rotate_matrix_x(0, pitch);
    model_render_flags &= ~0x400;
    draw_chunk_object(mine_model);
    pop_matrix();
}
void TUnk_8049442C::run_task() {
    timer++;
    switch (state) {
    case 0:
        pitch += 0x200;
        if (pitch >= 0) {
            pitch = 0;
        }
        position.x += velocity.x;
        position.z += velocity.z;
        update_ground_fall(NULL, 0.0f);
        if (actorFlags & 0x800000) {
            push_matrix_from(identity_matrix);
            velocity.x = 0.0f;
            velocity.y = 0.0f;
            velocity.z = 0.8f;
            yaw += spin;
            rotate_matrix_y(0, yaw);
            rotate_vector_by_matrix(0, &velocity, &velocity);
            pop_matrix();
            pitch = 0;
            spawn_particle_effect(&position, 0xF3);
            state = 1;
        }
        break;
    case 1: {
        Vec next = probe_position;
        next.x += velocity.x;
        next.z += velocity.z;
        if (csnVector(&probe_position, &next, -1) == NULL) {
            position.x = next.x;
            position.z = next.z;
        } else {
            state = 2;
        }
        update_ground_fall(NULL, 0.0f);
        if (arm_delay > 0) {
            arm_delay--;
        } else {
            update_collisions();
            if (bodies->flags & 0x380000) {
                explode();
                break;
            }
        }
        roll_distance += 0.8f;
        if (roll_distance >= 50.0f) {
            state = 2;
        }
        break;
    }
    case 2:
        update_ground_fall(NULL, 0.0f);
        break;
    }
    VecCopy(&probe_position, &position);
    probe_position.y += 5.0f;
    if (timer >= 0x96) {
        explode();
    }
}

CollisionBody gyaranzo_missile_collision_body = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x10D03, {0.0f, 0.0f, 0.0f}, 0.0f};

TUnk_8049442C::~TUnk_8049442C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}


TUnk_8049442C::TUnk_8049442C(TObjBase *owner, Vec *pos, s32 angle, s32 spin) : TObjCollidable(tl_04) {
    VecCopy(&position, pos);
    VecCopy(&probe_position, &position);
    probe_position.y += 5.0f;
    this->spin = spin;
    mine_model = gyaranzo_bml_resource->models[5].model;
    mine_textures = (saddr)gyaranzo_bml_resource->models[5].texlist;
    room = owner->room;
    owner_id = owner->get_entity_id();
    pad_B8 = 0;
    yaw = angle + 0x8000;
    pitch = -0x4000;
    state = 0;
    timer = 0;
    push_matrix_from(identity_matrix);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.5f;
    rotate_matrix_y(0, yaw);
    rotate_vector_by_matrix(0, &velocity, &velocity);
    pop_matrix();
    roll_distance = 0.0f;
    init_collision_body_parts(this, &gyaranzo_missile_collision_body, 1);
    bodies->radius = 3.0f;
    register_object_by_id();
    arm_delay = 15;
}
