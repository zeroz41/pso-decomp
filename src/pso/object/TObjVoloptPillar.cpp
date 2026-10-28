#pragma fp_contract on

#include "pso/object/TObjVoloptPillar.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss3VoloptP02.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/TUnk_80484888.h"
#include "pso/unk/text_80049FD8.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"

extern "C" {
f32 atan2_float(f32 y, f32 x);
s32 obj_is_hit_receivable(TUnk_804806E8 *actor);
s32 push_matrix(void);
void post_translate_matrix(const Vec *v);
void rotate_matrix_x(s32 matrix, s32 angle);
void scale_matrix(s32 matrix, f32 x, f32 y, f32 z);
void matrix_mult_vec(s32 matrix, const Vec *src, Vec *dst);
void subtract_vector(Vec *v, const Vec *sub);
void play_sound_effect(s32 id, const Vec *pos, s32 a2, s32 a3);
extern GC_Mtx identity_matrix;
}


static s32 volopt_pillar_model;
static s32 volopt_pillar_base_model;
static s32 volopt_pillar_textures;
static s32 volopt_pillar_base_textures;

static CollisionBody volopt_pillar_collision_body[1] = {
    {{0.0f, 18.0f, 0.0f}, 5.0f, {0}, 0x8005, {0}},
};

void TObjVoloptPillar::render() {
    f32 scale;
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
        select_actor_lighting((s32)this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        post_translate_matrix(&position);
        TObjFish::set_global_param(volopt_pillar_textures);
        draw_chunk_object((void *)volopt_pillar_model);
        pop_matrix();
        push_matrix();
        translate_matrix(0, position.x, start_y, position.z);
        TObjFish::set_global_param(volopt_pillar_base_textures);
        draw_chunk_object((void *)volopt_pillar_base_model);
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        scale = 0.011111111f * (90.0f - position.y) + 1.0f;
        push_matrix();
        translate_matrix(0, position.x, 0.3f, position.z);
        rotate_matrix_y(0, rotation_y);
        rotate_matrix_x(0, -0x4000);
        scale_matrix(0, scale, scale, scale);
        draw_blob_shadow(0);
        pop_matrix();
    }
}

void TObjVoloptPillar::run_task() {
    s32 i;
    TUnk_804806E8 *target;
    s32 angle;
    switch (state) {
    case 0:
        timer = TBoss3VoloptP02::get_int_param(5);
        state = 1;
    case 1:
        if (--timer <= 0) {
            fn_80049FD8(this);
            state = 2;
        }
        break;
    case 2:
        position.y += -16.0f;
        if (position.y <= 0.0f) {
            timer = 15;
            state = 3;
            bodies->flags |= 2;
            TObjPlayer::init_all_slots();
            ((TObjPlayer *)this)->check_object_collisions();
            if (bodies->flags & 0x80000) {
                for (i = 0; i < 16; i++) {
                    target = (TUnk_804806E8 *)TObjPlayer::get_battle_param(i);
                    if (target == NULL) {
                        break;
                    }
                    if (obj_is_hit_receivable(target) != 0) {
                        DirectAttackPayload attack = volopt_pillar_attack;
                        attack.power = TBoss3VoloptP02::get_int_param(1);
                        target->receive_direct_attack(owner, attack, NULL, -1, -1);
                        if (!(target->actorFlags & 0x04000000)) {
                            push_matrix_from(identity_matrix);
                            {
                                Vec away = *&target->position;
                                subtract_vector(&away, &boss3_volopt_spawn_pos);
                                angle = volopt_pillar_rad_to_angle * atan2_float(away.x, away.z);
                                {
                                    Vec push = volopt_pillar_push;
                                    push.x = TBoss3VoloptP02::get_float_param(2);
                                    rotate_matrix_y(0, angle);
                                    matrix_mult_vec(0, &push, (Vec *)target->unk_308);
                                }
                            }
                            pop_matrix();
                        }
                    }
                }
            }
            bodies->flags &= ~1;
            {
                Vec pos = *&position;
                pos.y = 5.0f;
                new TUnk_80484888(&pos, 0x11E, 0xF, NULL, 0.25f, 40.0f);
            }
            TCameraCtrl::set_shake_preset(1);
            play_sound_effect(0x4003AD09, &position, 0, 0);
        }
        break;
    case 3:
        if (--timer <= 0) {
            state = 4;
        }
        break;
    case 4:
        position.y += 16.0f;
        if (position.y >= 90.0f) {
            queue_destruction();
        }
        break;
    }
}

void TObjVoloptPillar::cache_target_values() {
    volopt_pillar_model = boss3_volopt_resources->models[0x17].model;
    volopt_pillar_textures = boss3_volopt_resources->models[0x17].m_c;
    volopt_pillar_base_model = boss3_volopt_resources->models[0x15].model;
    volopt_pillar_base_textures = boss3_volopt_resources->models[0x15].m_c;
}

TObjVoloptPillar::~TObjVoloptPillar() {
    free_collision_body_parts(this);
}

TObjVoloptPillar::TObjVoloptPillar(Vec *pos, TObject *owner) : TUnk_804AF8A0(tl_04) {
    f32 dist;
    m_name = TObjVoloptPillar_name;
    init_collision_body_parts(this, volopt_pillar_collision_body, 1);
    VecCopy(&position, pos);
    dist = vec_xz_distance(&position, (Vec *)(u8 *)&boss3_volopt_spawn_pos);
    if (dist < 60.0f) {
        position.y = 90.0f;
    } else {
        position.y = 90.0f - 0.33333334f * (dist - 60.0f);
    }
    start_y = position.y;
    state = 0;
    this->owner = owner;
}
