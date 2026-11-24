#pragma readonly_strings on
#pragma fp_contract on

#include "pso/boss/volopt/TObjVoloptPillar.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/TObjChip.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3VoloptP02.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/TUnk_80484888.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer_80011014.h"

const char *TObjVoloptPillar_name = "TObjVoloptPillar";
const DirectAttackPayload volopt_pillar_attack = {0, 0.0f};
const Vec volopt_pillar_push = {0.0f, 0.0f, 0.0f};

// Throws three debris chips from the pillar's position.
void TObjVoloptPillar::spawn_debris_chips() {
    const TObjChipParams params = {
        0.5f, 0.03f, 0.25f,
        {this->position.x, this->position.y, this->position.z},
        {4.5f, -3.0f, 4.5f},
        {0x400, 0x100, 0x400},
        4, 60,
        0.0f, 1.0f,
        boss3_volopt_resources->models[0xE].model,
        boss3_volopt_resources->models[0xE].texlist,
        2,
    };
    new TObjChip(tl_05, (TObjChipParams *)&params);
    new TObjChip(tl_05, (TObjChipParams *)&params);
    new TObjChip(tl_05, (TObjChipParams *)&params);
}

extern "C" {
void post_translate_matrix(const Vec *v);
}


static saddr volopt_pillar_model;
static saddr volopt_pillar_base_model;
static s32 volopt_pillar_textures;
static s32 volopt_pillar_base_textures;

static CollisionBody volopt_pillar_collision_body[1] = {
    {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8005},
};

void TObjVoloptPillar::render() {
    f32 scale;
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
        select_actor_lighting(this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        post_translate_matrix(&position);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(volopt_pillar_textures));
        draw_chunk_object((void *)volopt_pillar_model);
        pop_matrix();
        push_matrix();
        translate_matrix(0, position.x, start_y, position.z);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(volopt_pillar_base_textures));
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
    TObjChara *target;
    s32 angle;
    switch (state) {
    case 0:
        timer = TBoss3VoloptP02::get_int_param(5);
        state = 1;
    case 1:
        if (--timer <= 0) {
            spawn_debris_chips();
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
            this->check_object_collisions();
            if (bodies->flags & 0x80000) {
                for (i = 0; i < 16; i++) {
                    target = (TObjChara *)TObjPlayer::get_battle_param(i);
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
                                angle = 10430.38043493439 * atan2_float(away.x, away.z);
                                {
                                    Vec push = volopt_pillar_push;
                                    push.x = TBoss3VoloptP02::get_float_param(2);
                                    rotate_matrix_y(0, angle);
                                    matrix_mult_vec(0, &push, &target->velocity);
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
    volopt_pillar_model = (saddr)boss3_volopt_resources->models[0x17].model;
    volopt_pillar_textures = (saddr)boss3_volopt_resources->models[0x17].texlist;
    volopt_pillar_base_model = (saddr)boss3_volopt_resources->models[0x15].model;
    volopt_pillar_base_textures = (saddr)boss3_volopt_resources->models[0x15].texlist;
}

TObjVoloptPillar::~TObjVoloptPillar() {
    free_collision_body_parts(this);
}

TObjVoloptPillar::TObjVoloptPillar(Vec *pos, TObject *owner) : TObjCollidable(tl_04) {
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
