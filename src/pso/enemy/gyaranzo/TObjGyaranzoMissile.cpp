#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TUnk_8049442C.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/base/TObjBase.h"


CollisionBody gyaranzo_missile_collision_body_b = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f};

const char *TObjGyaranzoMissile__class_name = "TObjGyaranzoMissile";
static const DirectAttackPayload gyaranzo_missile_explosion_attack[] = {{0, 0.0f}};

void TObjGyaranzoMissile::explode() {
    TObjCollidable *owner;
    s32 i;
    TObjChara *target;
    owner = find_entity_by_id(owner_id);
    bodies->radius = 6.0f;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    check_enemy_body_collisions(this);
    if (bodies->flags & 0x180000) {
        for (i = 0; i < 0x10; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (TObjPlayer::is_valid_and_active((uaddr)target) != 0) {
                DirectAttackPayload hit = gyaranzo_missile_explosion_attack[0];
                hit.power = get_gyaranzo_missile_int_parameter(2);
                target->receive_direct_attack(owner, hit, NULL, -1, -1);
            }
        }
    }
    spawn_particle_effect(&position, 0xFB);
    play_sound_effect(remap_area_sound_id(0x4003A80C, 0x19), &position, 0, 0);
    queue_destruction();
}

void TObjGyaranzoMissile::render() {
    TObjFish::set_global_param(get_bml_texlist(gyaranzo_bml_resource, 6));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_x(0, rotation_x);
    rotate_matrix_y(0, rotation_y);
    translate_matrix(0, 0.0f, wobble_height * sin_table_lookup(wobble_phase), 0.0f);
    model_render_flags &= ~0x400;
    draw_chunk_object(get_bml_model(gyaranzo_bml_resource, 6));
    pop_matrix();
}

void TObjGyaranzoMissile::run_task() {
    TObjChara *chased;
    f32 dist;
    chased = (TObjChara *)find_active_entity_by_id(target_id);
    if (chased != NULL) {
        Vec d = chased->body_center;
        subtract_vector(&d, &position);
        dist = vector_length(&d);
        if (timer >= 15 && dist > TObjGyaranzoMissile__max_range) {
            vec_set_length(&d, TObjGyaranzoMissile__max_range);
            vec3_add_to(&velocity, &d);
            vec_set_length(&velocity, TObjGyaranzoMissile__speed_scale);
        }
    }
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    direction_to_rotation_xy((u8 *)&velocity, &rotation_x, &rotation_y);
    wobble_phase += wobble_speed;
    if (timer >= 10) {
        if (csnVector(&prev_position, &position, -1) != NULL) {
            explode();
            return;
        }
        Vec ground = position;
        if (project_actor_to_ground(this, &ground, 0) == 1) {
            if (position.y - ground.y < 22.0f) {
                bodies->flags |= 2;
                bodies->flags &= ~4;
                check_object_collisions();
                check_enemy_body_collisions(this);
                if (bodies->flags & 0x180000) {
                    explode();
                    return;
                }
            } else {
                bodies->flags &= ~2;
                bodies->flags |= 4;
            }
        }
    }
    timer++;
    if (timer > gyaranzo_missile_volley_end_time) {
        explode();
    }
}

TObjGyaranzoMissile::~TObjGyaranzoMissile() {
    free_collision_body_parts(this);
}

#pragma push
#pragma fp_contract on
TObjGyaranzoMissile::TObjGyaranzoMissile(TObjEneGyaranzo *owner, GyaranzoMissileLaunch *launch, u16 target) : TObjCollidable(tl_04) {
    m_name = TObjGyaranzoMissile__class_name;
    init_collision_body_parts(this, &gyaranzo_missile_collision_body_b, 1);
    bodies->radius = 4.0f;
    VecCopy(&position, launch->position);
    target_id = target;
    rotation_x = launch->rotation_x;
    rotation_y = launch->rotation_y;
    wobble_phase = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    wobble_speed = (s32)(launch->wobble_speed * (0.5f * ((3.0517578e-05f * (f32)rand()) + 1.0f)));
    wobble_height = launch->wobble_height;
    room = owner->room;
    owner_id = owner->get_entity_id();
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = TObjGyaranzoMissile__speed_scale;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, rotation_x);
    matrix_mult_vec(NULL, &velocity, &velocity);
    pop_matrix();
    timer = 0;
}
#pragma pop
