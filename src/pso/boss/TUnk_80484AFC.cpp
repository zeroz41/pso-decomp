#pragma fp_contract on

#include "pso/boss/TUnk_80484AFC.h"
#include "pso/system/NinjaUtil.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptP02.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjChara.h"
#include "pso/system/BmlResource.h"
#include "pso/system/GinjaTextureMatrices.h"
#include "pso/system/vector.h"
#include "pso/unk/text_800870BC.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include <stdlib.h>
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/TObjButterflyLobby_8007A5D8.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/TParticleCtrl.h"

extern "C" {
s32 push_matrix(void);
void post_translate_matrix(const Vec *v);
void rotate_matrix_x(s32 matrix, s32 angle);
void matrix_mult_vec(s32 matrix, const Vec *src, Vec *dst);
void vec3_add_to(Vec *v, const Vec *add);
void subtract_vector(Vec *v, const Vec *sub);
void play_sound_effect(s32 id, const Vec *pos, s32 a2, s32 a3);
void play_persistent_sound(s32 id, void *owner, const Vec *pos, s32 a3, s32 flags);
s32 obj_is_hit_receivable(TObjChara *actor);
extern GC_Mtx identity_matrix;
}


static CollisionBody volopt_missile_collision_body[1] = {
    {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x8101},
};

static s32 volopt_missile_expire_tick;

void TUnk_80484AFC::explode_and_destroy() {
    DirectAttackPayload attack = {0, 0.0f};
    s32 i;
    TObjChara *target;
    attack.power = TBoss3VoloptP02::get_int_param(0);
    if (TBoss3Volopt::is_v2_mode() != 0 && 3.0517578e-05f * (f32)rand() < 0.16666667f) {
        attack.kind = 0x11;
    }
    play_sound_effect(0x4003AD15, &position, 0, 0);
    play_sound_effect(0x4001C112, &position, 0, 0);
    bodies->radius = 15.0f;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)this)->check_object_collisions();
    if (bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(target) != 0) {
                target->receive_direct_attack(m_up, attack, NULL, -1, -1);
            }
        }
    }
    spawn_particle_effect(&position, 0xFB);
    queue_destruction();
}

void TUnk_80484AFC::render() {
    TObjFish::set_global_param(textures);
    push_matrix();
    post_translate_matrix(&position);
    rotate_matrix_x(0, rotation_x);
    rotate_matrix_y(0, rotation_y);
    model_render_flags &= ~0x400;
    draw_chunk_object((void *)model);
    pop_matrix();
}

void TUnk_80484AFC::run_task() {
    TObjPlayer *player = get_player_by_client_id(target_id);
    if (player != NULL) {
        Vec steer = *(Vec *)&player->m_2fc;
        subtract_vector(&steer, &position);
        vec_set_length((Vec *)&steer, TBoss3VoloptP02::get_float_param(1));
        vec3_add_to(&velocity, &steer);
        vec_set_length((Vec *)&velocity, TBoss3VoloptP02::get_float_param(0));
    }
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    direction_to_rotation_xy((u8 *)&velocity, &rotation_x, &rotation_y);
    if (trail != NULL) {
        Vec back = velocity;
        back.x = -back.x;
        back.y = -back.y;
        back.z = -back.z;
        direction_to_rotation_yx((u8 *)&back, &trail_rotation[1], &trail_rotation[2]);
        trail_rotation[2] -= 0x4000;
        ((TParticleCtrl *)trail)->set_direction(trail_rotation);
        vec_set_length(&back, 10.0f);
        vec3_add_to(&back, &position);
        ((TParticleCtrl *)trail)->set_position(&back);
    }
    if (csnVector(&prev_position, &position, -1) != 0) {
        explode_and_destroy();
        return;
    }
    bodies->flags &= ~6;
    if (position.y < 22.0f) {
        bodies->flags |= 2;
    } else {
        bodies->flags |= 4;
    }
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    if (bodies->flags & 0x180000) {
        explode_and_destroy();
        return;
    }
    age++;
    if (age > volopt_missile_expire_tick) {
        explode_and_destroy();
        return;
    }
    play_persistent_sound(0x4003C114, this, &position, 0, 0);
}

TUnk_80484AFC::~TUnk_80484AFC() {
    free_collision_body_parts(this);
    if (trail != NULL) {
        ((TObject *)trail)->queue_destruction();
    }
}

TUnk_80484AFC::TUnk_80484AFC(TObject *parent, Vec *pos, s32 angle, s32 target) : TObjCollidable(parent) {
    init_collision_body_parts(this, volopt_missile_collision_body, 1);
    bodies->radius = 5.0f;
    VecCopy(&position, pos);
    target_id = target;
    rotation_x = 0;
    rotation_y = angle;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = TBoss3VoloptP02::get_float_param(0);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, rotation_x);
    matrix_mult_vec(0, &velocity, &velocity);
    pop_matrix();
    model = boss3_volopt_resources->models[0x16].model;
    textures = boss3_volopt_resources->models[0x16].m_c;
    age = 0;
    trail_rotation[2] = 0;
    trail_rotation[1] = 0;
    trail_rotation[0] = 0;
    trail = spawn_particle_effect_with_rotation(&position, trail_rotation, 0x112, 2);
    volopt_missile_expire_tick = (s32)TBoss3VoloptP02::get_float_param(3) + 0xF0;
}
