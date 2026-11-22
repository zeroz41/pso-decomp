#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyMovement.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
extern "C" const u8 rappy_variant_na_name[3] = "NA";
void *TObjEneLappy__model_filename_table[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_lappy_base.nj", (void *)0x0,
};
void *lbl_80492BE4[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492C10[4] = {
    (void *)"bm_ene_lappy.bml", (void *)&TObjEneLappy__model_filename_table, (void *)&lbl_80492BE4, (void *)0x2000a,
};
void *lbl_80492C20[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_lappy_base.nj", (void *)0x0,
};
void *lbl_80492C2C[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492C58[4] = {
    (void *)"bm_ene_lappy_ap.bml", (void *)&lbl_80492C20, (void *)&lbl_80492C2C, (void *)0x2000a,
};
void *lbl_80492C68[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_elappy_base.nj", (void *)0x0,
};
void *lbl_80492C74[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492CA0[4] = {
    (void *)"bm_ene_lappy_es.bml", (void *)&lbl_80492C68, (void *)&lbl_80492C74, (void *)0x2000a,
};
void *lbl_80492CB0[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_elappy_base.nj", (void *)0x0,
};
void *lbl_80492CBC[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492CE8[4] = {
    (void *)"bm_ene_lappy_ap_es.bml", (void *)&lbl_80492CB0, (void *)&lbl_80492CBC, (void *)0x2000a,
};
void *lbl_80492CF8[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_hlappy_base.nj", (void *)0x0,
};
void *TObjEneLappy__resource_name_table[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492D30[4] = {
    (void *)"bm_ene_lappy_hw.bml", (void *)&lbl_80492CF8, (void *)&TObjEneLappy__resource_name_table, (void *)0x2000a,
};
void *lbl_80492D40[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_hlappy_base.nj", (void *)0x0,
};
void *TObjEneLappy__resource_list[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492D78[4] = {
    (void *)"bm_ene_lappy_ap_hw.bml", (void *)&lbl_80492D40, (void *)&TObjEneLappy__resource_list, (void *)0x2000a,
};
void *lbl_80492D88[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_slappy_base.nj", (void *)0x0,
};
void *lbl_80492D94[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492DC0[4] = {
    (void *)"bm_ene_lappy_xs.bml", (void *)&lbl_80492D88, (void *)&lbl_80492D94, (void *)0x2000a,
};
void *lbl_80492DD0[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_slappy_base.nj", (void *)0x0,
};
void *lbl_80492DDC[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492E08[4] = {
    (void *)"bm_ene_lappy_ap_xs.bml", (void *)&lbl_80492DD0, (void *)&lbl_80492DDC, (void *)0x2000a,
};
TObjMotionAction rappy_variant_speed_table[10] = {
    {1, 0, 6, 0.9f, 0},
    {1, 1, 5, 0.7f, 0},
    {2, 3, 8, 0.7f, 0},
    {1, 3, 9, 1.8f, 1},
    {1, 4, 3, 1.2f, 1},
    {2, 1, 0, 1.0f, 4},
    {2, 1, 1, 1.0f, 8},
    {3, 6, 2, 0.6f, 0x10},
    {2, 4, 4, 0.9f, 1},
    {2, 4, 7, 0.5f, 0},
};
void *lbl_80492EB8[3] = {
    (void *)"RAG-LAPPY", (void *)"AL-LAPPY", (void *)&rappy_variant_na_name,
};
void *lbl_80492EC4[14] = {
    (void *)0x43160000, (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x43160000,
    (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};
CollisionBody lbl_80492EFC[1] = {
    {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneLappy__class_name = "TObjEneLappy";


const NpcAnimationBinding lappy_resource_binding_desc = { NULL, rappy_variant_speed_table, 1, 3, 10 };

const Vec lappy_target_zero_vec = {0.0f, 0.0f, 0.0f};

extern "C" __declspec(section ".data") f32 *lappy_variant_speed_ptr_table[2];


#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/object/ambient/TObjLight_80133568.h"




void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 play_sound_effect(s32, u32, s32, s32);
s32 TObjEneDD__sub_800B9B24(f32);
s32 is_item_light_interaction_blocked();
f32 post_translate_matrix(void *);
s32 lappy_variant_id;
BmlResource *rappy_bml_resource;
s32 *rappy_visibility_node;
uaddr rappy_alternate_texture_list;
extern s32 model_render_flags;
void TObjPlayer__sub_800BFF54(void * _w0);
s32 minimap_render_dot(void *, int, int, int);
s32 check_path_obstructed(void *, void *);
s32 get_entity_id(void *);
}
extern f32 identity_matrix[3][4];
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
f32 atan2_float(f32 y, f32 x);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 obj_setFlags30(void *, s32);

void TObjEneLappy::clear_flags_60() {
    s16 flags;

    flags = m_374;
    if (flags & 0x60) {
        m_374 = flags & ~0x60;
        project_actor_to_ground(this, &position, 0);
        obj_setFlags30(this, 0x800000);
    }
}

s32 TObjEneLappy::update_movement_status() {
    saddr self = (saddr)this;
    if (TObjChara::update_movement_status() != 0) {
        ((TObjEneLappy *)self)->clear_flags_60();
        return 1;
    }
    return 0;
}

s32 TObjEneLappy::update_action_hold_status() {
    saddr self = (saddr)this;
    if (TObjChara::update_action_hold_status() != 0) {
        ((TObjEneLappy *)self)->clear_flags_60();
        return 1;
    }
    return 0;
}

void TObjEneLappy::set_flag_and_notify() {
    s16 flags;

    flags = m_374;
    if (!(flags & 0x80)) {
        m_374 = (s16)(flags | 0x80);
        send_entity_set_flags();
    }
}

void TObjEneLappy::apply_variant_speeds() {
    f32 *p;
    if (variant >= 2) {
        return;
    }
    bodies->radius = lappy_variant_speed_ptr_table[variant][0];
    p = lappy_variant_speed_ptr_table[variant];
    rappy_variant_speed_table[6].speed = p[1];
    rappy_variant_speed_table[8].speed = p[2];
}

s32 TObjEneLappy::advance_flee_step() {
    Vec next;
    Vec step;
    Vec probe;
    s32 angle;
    s32 dir;
    s32 tries;
    VecCopy(&prev_position, &position);
    VecCopy(&next, &body_center);
    vec3_add_to(&next, &velocity);
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (csnVector(&body_center, &next, -1) != NULL) {
            return 0;
        }
        if (random_ratio() < 0.5f) {
            dir = -1;
        } else {
            dir = 1;
        }
        tries = 0;
        angle = 0;
loop_7:
        if (tries == 0) {
            VecCopy(&step, &velocity);
        } else {
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, (int)(dir * angle));
            rotate_vector_by_matrix(0, &velocity, &step);
            pop_matrices(1);
        }
        VecCopy(&probe, &position);
        vec3_add_to(&probe, &step);
        if (project_actor_to_ground(this, &probe, 0) == 1) {
            VecCopy(&position, &probe);
            VecCopy(&velocity, &position);
            subtract_vector(&velocity, &prev_position);
            return 1;
        }
        tries += 1;
        angle += 0x1000;
        if (tries >= 0xF) {
            return 0;
        }
        goto loop_7;
    }
    if (project_actor_to_ground(this, &next, 0) == 1) {
        VecCopy(&position, &next);
        VecCopy(&velocity, &position);
        subtract_vector(&velocity, &prev_position);
        return 1;
    }
    return 0;
}

void TObjEneLappy::play_walk_sound() {
    if ((requested_action == 3) && ((is_passing_frame(10.0f) != 0) || (is_passing_frame(30.0f) != 0))) {
        play_sound_effect(remap_area_sound_id(0x3D20C, 5), (uaddr)&position, 0, 0);
    }
}
void TObjPlayer__sub_800BFF54(void * _w0) {  }

void TObjEneLappy::render() {
    s32 temp_r3;
    if (obj_testFlags30(0x02000000) == 0) {
        if (this->m_374 & 1) {
            *rappy_visibility_node &= 0xFFFFFFF7;
        } else {
            *rappy_visibility_node |= 8;
        }
        temp_r3 = this->classify_actor_view_detail(150.0f, 400.0f, 10.0f);
        if (temp_r3 != 0) {
            set_speed_params(this->variant);
            TObjFish::set_global_param(this->texlist);
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(&position);
            rotate_matrix_y(0, this->rotation_y);
            if (this->m_374 & 0x400) {
                scale_matrix(0, 2.0f, 1.5f, 2.0f);
                TObjEneDD__sub_800B9B24(0.6666667f);
            }
            model_render_flags &= 0xFFFFFBFF;
            set_motion_packed_rotation();
            if (is_item_light_interaction_blocked() == 1) {
                draw_chunk_object(model);
            } else {
                model_render_flags |= 0x01000000;
                if (temp_r3 == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                model_render_flags &= 0xFEFFFFFF;
            }
            clear_motion_packed_rotation();
            if (this->m_374 & 0x400) {
                TObjEneDD::init_lights();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(this->actorFlags & 0x800) && (obj_testFlags30(0x800000) != 0)) {
                this->TObjEnemy::draw_ground_shadow(0, 0);
            }
        }
    }
}

void TObjEneLappy::set_boss4_state() {
    s16 temp_r4;
    temp_r4 = this->m_374;
    if (!(temp_r4 & 2)) {
        this->m_374 = (temp_r4 | 2);
        flee_turn_timer = 0;
        this->m_390 = (s32) (182.04445f * (360.0f * random_ratio()));
    }
    this->mode = 1;
    this->m_37a = 3;
    clear_harmful_statuses();
    this->hp = 1;
    this->actorFlags = (s32) (this->actorFlags & ~0xA00);
}
void TObjEneLappy::apply_move_friction() {
    sub_800C20B0();
    advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, 0, 0.0f);
    }
    refresh_collision_body_centers();
    if (this->frame < (0.5f * (30.0f * this->play_speed))) {
        move_with_wall_slide((u8 *)this);
        this->velocity.x *= 0.5f;
        this->velocity.z *= 0.5f;
    }
}
void TObjEneLappy::run_death_reaction() {
    s16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    temp_r3 = this->m_374;
    if (temp_r3 & 2) {
        if (!(temp_r3 & 4)) {
            this->m_374 = (s16) (temp_r3 | 4);
            play_sound_effect(remap_area_sound_id(0x3AD13, 5), (uaddr)&position, 0, 0);
            ((TObjPlayer *)((u8 *)this))->query_lobby_state();
            this->requested_action = 8;
        }
    } else if ((s16) this->mode != 5) {
        this->mode = 5;
        this->requested_action = 7;
        if (!(this->m_374 & 0x10)) {
            play_sound_effect(remap_area_sound_id(0x3AE10, 5), (uaddr)&position, 0, 0);
            this->distribute_experience();
            set_flag_and_notify();
        }
        this->m_380 = 0;
    }
}

void TObjEneLappy::update_hurt() {
    advance_animation();
    Vec v = body_center;
    v.x += velocity.x;
    v.z += velocity.z;
    if (check_path_obstructed(this, &v) == 0) {
        move_with_wall_slide((u8 *)this);
    } else {
        velocity.x = velocity.z = 0.0f;
    }
    velocity.x *= 0.5f;
    velocity.z *= 0.5f;
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
    if (this->action_flags != 8U) {
        this->actorFlags &= ~0x200;
        this->referenceHp = this->hp;
        if (this->m_374 & 2) {
            set_boss4_state();
            this->requested_action = 4;
        }
    }
}

void TObjEneLappy::run_hit_reaction() {
    saddr temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    if (this->m_374 & 2) {
        this->obj_clearFlags30(0x23F);
        return;
    }
    if ((s16) this->mode != 4) {
        this->mode = 4;
        this->requested_action = 6;
        temp_r3 = (saddr)get_player_by_client_id(this->attacker_id);
        if ((temp_r3 != 0) && !(xyz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(temp_r3 + 0x38)) < 10000.0f)) {
            this->m_374 = (s16) (this->m_374 | 2);
            set_flag_and_notify();
        }
        play_sound_effect(remap_area_sound_id(0x3B10F, 5), (uaddr)(((u8 *)this) + 0x38), 0, 0);
    }
}

void TObjEneLappy::update_invuln_timer() {
    u8 *self = (u8 *)this;
    s16 temp_r4;
    ((TObjMotion *)self)->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity((TObjEnemy *)self, (s32 *)NULL, 0.0f);
    }
    update_collisions();
    temp_r4 = this->timer;
    this->timer = (temp_r4 - 1);
    if (temp_r4 < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->timer = (s16) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
}

void TObjEneLappy::run_miss_reaction() {
    if ((s16) this->mode != 3) {
        this->mode = 3;
        this->requested_action = 1;
        this->actorFlags = (s32) (this->actorFlags & 0xFF9FFFFF);
    }
}

void TObjEneLappy::update_attacking() {
    u8 *hit;
    advance_animation();
    switch (phase) {
    case 0:
        enemy_turn_toward_dest(*(s32 *)((u8 *)movementParameters + 8));
        apply_actor_gravity(this, NULL, 0.0f);
        if (is_passing_frame(11.0f) != 0) {
            enemy_set_heading_velocity(*(f32 *)((u8 *)movementParameters + 4), this, rotation_y);
            velocity.y = 0.0f;
            phase = 1;
        }
        break;
    case 1:
        VecCopy(&prev_position, &position);
        position.x += velocity.x;
        velocity.x *= 0.95f;
        position.z += velocity.z;
        velocity.z *= 0.95f;
        apply_actor_gravity(this, NULL, 0.0f);
        if (is_passing_frame(14.0f) != 0) {
            hit = target;
            if (hit != NULL && ((TObjChara *)hit)->select_melee_contact_body(this, 1.0f) != 0) {
                ((TObjChara *)target)->receive_physical_attack(this, 1.0f);
                ((TObjChara *)target)->apply_knockback_from_attacker((u8 *)this, 3.0f);
            }
            play_sound_effect(remap_area_sound_id(0x3BC0D, 5), (uaddr)&position, 0, 0);
            phase = 2;
            timer = 0x1E;
        }
        break;
    case 2:
        apply_actor_gravity(this, NULL, 0.0f);
        timer--;
        if (timer < 0) {
            phase = 3;
        }
        break;
    case 3:
        VecCopy(&prev_position, &position);
        position.x += velocity.x;
        position.z += velocity.z;
        apply_actor_gravity(this, NULL, 0.0f);
        if (action_flags != 4U) {
            velocity.x = velocity.y = velocity.z = 0.0f;
            actorFlags &= 0xFFDFFFFF;
            run_move_action();
            timer = 0;
        }
        break;
    }
    update_collisions();
}

void TObjEneLappy::run_attack_action() {
    u16 temp_r4;
    if (!(this->m_374 & 0x42) && (obj_testFlags30(0xA02) == 0) && ((s16) this->mode != 2)) {
        this->mode = 2;
        this->requested_action = 5;
        this->phase = 0;
        *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags | 0x200000);
        if ((s16) this->m_382 != (s32) (temp_r4 = this->targetId)) {
            this->m_382 = (s16) temp_r4;
            this->m_384 = 0;
        } else {
            this->m_384 = (s16) (this->m_384 + 1);
        }
        this->m_388 = 0;
    }
}
#pragma push
#pragma opt_common_subs off

void TObjEneLappy::update_moving() {
    Vec probe;
    f32 dist;
    s32 turn;
    u32 flags;
    u8 *chased;
    f32 *params;
    advance_animation();
    if ((actorFlags & 0x1000) && !(m_374 & 2)) {
        chased = target;
        if (chased != NULL) {
            enemy_backstep_from_point(this, ((TObjChara *)chased)->body_center, *(f32 *)((u8 *)movementParameters + 4));
            turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), &velocity);
            apply_actor_gravity(this, NULL, 0.0f);
            update_collisions();
            return;
        }
    }
    flags = action_flags;
    if (flags == 1U) {
        switch (m_37a) {
        case 0:
            chased = target;
            if (chased != NULL) {
                dist = update_enemy_wander_move(this, ((TObjChara *)chased)->body_center, 1, *(f32 *)((u8 *)movementParameters + 4));
                if ((obj_testFlags30(2) == 0) && (dist < 10000.0f)) {
                    m_37a = 1;
                    pad_398 = 0;
                    random_ratio();
                    m_39c = 0.0f;
                }
                params = (f32 *)movementParameters;
                if (params[0] * params[0] < dist || dist < params[1] * params[1]) {
                    target = NULL;
                }
            } else {
                params = (f32 *)movementParameters;
                enemy_wander_home(params[1], 100.0f, 50.0f, *(s32 *)((u8 *)params + 8));
            }
            turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), &velocity);
            play_walk_sound();
            goto block_48;
        case 1:
            chased = target;
            if (chased != NULL) {
                dist = update_enemy_wander_move(this, ((TObjChara *)chased)->body_center, 1, *(f32 *)((u8 *)movementParameters + 4));
                if (dist > 22500.0f) {
                    m_37a = 0;
                }
                turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), &velocity);
                params = (f32 *)movementParameters;
                if (params[0] * params[0] < dist || dist < params[1] * params[1]) {
                    target = NULL;
                }
            } else {
                m_37a = 0;
            }
            play_walk_sound();
            goto block_48;
        case 2:
            break;
        case 3:
            rotation_y = lerp_angle_half(rotation_y, m_390);
            if (action_flags == 1U) {
                actorFlags &= 0xFBFFFFFF;
                m_37a = 4;
                play_sound_effect(remap_area_sound_id(0x3AF12, 5), (uaddr)&position, 0, 0);
            }
            if (is_passing_frame(30.0f) != 0) {
                play_sound_effect(remap_area_sound_id(0x3AA11, 5), (uaddr)&position, 0, 0);
            }
            goto block_48;
        case 4:
            if (flags == 1U) {
                enemy_set_heading_velocity(3.5f * *(f32 *)((u8 *)movementParameters + 4), this, rotation_y);
                flee_turn_timer++;
                if (((f32)flee_turn_timer > 15.0f) && (find_nearest_visible_player(this, &probe, 300.0f) != 0xFFFFU) && (angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(probe.x, probe.z))) < 0xAAA)) {
                    if (random_ratio() >= 0.5f) {
                        turn = -0x4000;
                    } else {
                        turn = 0x4000;
                    }
                    rotation_y = rotation_y + turn;
                    flee_turn_timer = 0;
                }
                if (advance_flee_step() == 0) {
                    queue_destruction();
                    return;
                }
                if (--m_396 < 0) {
                    spawn_particle_effect(&position, 0xF3);
                    m_396 = 2;
                }
                play_persistent_sound(remap_sound_for_area(0x3AF12), (saddr)this, (uaddr)&position, 0, 0);
                goto block_47;
            }
block_47:
            apply_actor_gravity(this, NULL, 0.0f);
            refresh_collision_body_centers();
            return;
        }
    }
block_48:
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
}

void TObjEneLappy::run_move_action() {
    s32 temp_r6;
    void *temp_r3;
    void *temp_r7;
    if (!(this->m_374 & 0x42) && !(this->actorFlags & 0xA00)) {
        if ((s16) this->mode != 1) {
            temp_r7 = this->target;
            if (temp_r7 != NULL) {
                if (select_enemy_destination(this, ((TObjChara *)temp_r7)->body_center, 1) == 1) {
                    switch ((s8)this->m_378) {
                    case 0:
                        this->requested_action = 3;
                        break;
                    case 1:
                        this->requested_action = 2;
                        break;
                    }
                    this->m_37a = 0;
                    this->m_380 = 0;
                    this->m_378 = 0U;
                    this->mode = 1;
                    this->actorFlags = (s32) (this->actorFlags & 0xFFDBFFFF);
                }
            }
        }
        this->bodies->flags |= 1;
    }
}

#pragma push
#pragma opt_common_subs on
void TObjEneLappy::update_idle_state(void *ov) {
    TObjEneLappy *self = (TObjEneLappy *)ov;
    f32 range;

    if (self->is_actor_cadence_frame(0x1E) != 0) {
        if ((s8)self->m_379 != 0) {
            range = 10.0f;
        } else {
            range = 100.0f;
        }
        if (xz_distance_squared(&self->position, &self->home_position) > range * range) {
            self->m_378 = 2;
            self->requested_action = 3;
        } else if ((s8)self->m_378 != (s8)self->m_379) {
            self->m_378 = self->m_379;
            self->phase = 0;
        }
    }
    switch ((s8)self->m_378) {
    case 0:
        switch (self->phase) {
        case 0:
            self->m_37e = 45.0f * (1.0f + self->random_ratio());
            self->phase = self->requested_action = 1;
        case 1:
            self->m_37e--;
            if (self->m_37e < 0) {
                play_sound_effect(remap_area_sound_id(0x3B20B, 5), (uaddr)&self->position, 0, 0);
                self->phase = 2;
            }
            break;
        case 2:
            self->wander_distance = 30.0f;
            self->phase = self->requested_action = 3;
        case 3:
            self->enemy_wander_home(*(f32 *)((u8 *)self->movementParameters + 4), 100.0f, 100.0f, *(s32 *)((u8 *)self->movementParameters + 8));
            self->wander_distance -= *(f32 *)((u8 *)self->movementParameters + 4);
            if (self->wander_distance < 0.0f) {
                self->phase = 0;
            }
            break;
        }
        self->advance_animation();
        break;
    case 1:
        self->requested_action = 0;
        self->advance_animation();
        self->m_37e--;
        if (self->m_37e < 0) {
            play_sound_effect(remap_area_sound_id(0x3B20B, 5), (uaddr)&self->position, 0, 0);
            self->m_37e = 30.0f * (6.0f * (1.0f + self->random_ratio()));
        }
        break;
    case 2: {
        self->advance_animation();
        update_enemy_wander_move(self, self->home_position, 7, *(f32 *)((u8 *)self->movementParameters + 4));
        self->turn_toward_direction(*(s32 *)((u8 *)self->movementParameters + 8), &self->velocity);
        break;
    }
    }
    self->refresh_collision_body_centers();
    if (!(self->actorFlags & 0x800000)) {
        apply_actor_gravity(self, NULL, 0.0f);
    }
    if (self->actorFlags & 0x40000) {
        if (self->timer-- < 0) {
            self->actorFlags &= ~0x40000;
            self->timer = self->resetTimer;
        }
    }
}
#pragma pop

void TObjEneLappy::run_idle_action() {
    s16 flags;
    flags = this->m_374;
    if (!(flags & 2) && !(this->actorFlags & 0xA00)) {
        if (flags & 0x20) {
            this->m_374 = flags & ~0x20;
            this->obj_clearFlags30(0x02000000);
            Vec v = position;
            if (project_actor_to_ground(this, &v, 0) == 1) {
                position.y = 300.0f + v.y;
            }
        }
        if (this->mode != 0) {
            this->mode = 0;
            this->phase = 0;
            switch ((s8) this->m_378) {
            case 0:
                this->requested_action = 3;
                break;
            case 1:
                this->requested_action = 0;
                break;
            }
        }
    }
}

void TObjEneLappy::refresh_target() {
    s32 best_id;
    s32 i;
    s32 id;
    TObjPlayer *p;
    f32 best;
    f32 d;
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (actorFlags & 0x1000) {
            if ((m_2b4 -= 1.0f) < 0.0f) {
                targetId = 0xFFFFU;
                m_2b4 = 0.0f;
            } else {
                targetId = find_nearest_visible_player(this, NULL, *(f32 *)movementParameters);
            }
        } else if (obj_testFlags30(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = lappy_target_zero_vec;
            best = *(f32 *)movementParameters * *(f32 *)movementParameters;
            for (; i < registered_player_count + registered_enemy_count; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(p->actorFlags & 0x800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy(&v, &p->body_center);
                    subtract_vector(&v, &body_center);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(this, &p->body_center) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            targetId = best_id;
        } else {
            targetId = find_nearest_visible_player(this, NULL, *(f32 *)movementParameters);
        }
    }
    if (m_384 > 3 && m_382 == targetId) {
        s32 j;
        TObjPlayer *q;
        for (j = 0; j < registered_player_count; j++) {
            q = TObjPlayer::get_player_data(j);
            if (q != NULL && m_382 != (u16) get_entity_id(q) && !(q->actorFlags & 0x800)) {
                if (xz_distance_squared(&q->body_center, &body_center) < 2500.0f) {
                    targetId = j;
                }
                break;
            }
        }
    }
}

void TObjEneLappy::run_task() {
    sub_800C20C0();
    if (TObjPlayer::check_demo_mode() == 1) {
        apply_variant_speeds();
        TObjPlayer__sub_800BFF54(this);
        return;
    }
    target = (u8 *)find_active_entity_by_id(targetId);
    if (target != NULL && (((TObjChara *)target)->actorFlags & 0x800)) {
        target = NULL;
        targetId = 0xFFFF;
    }
    switch (mode) {
    case 0:
        TObjEneLappy::update_idle_state(this);
        break;
    case 1:
        update_moving();
        break;
    case 2:
        update_attacking();
        break;
    case 3:
        update_invuln_timer();
        break;
    case 4:
        update_hurt();
        break;
    case 5:
        apply_move_friction();
        break;
    }
    update_prev_position();
    VecCopy(&center, &body_center);
    if ((obj_testFlags30(0x06000000) == 0) && !(m_374 & 4)) {
        submit_cursor_candidate((u8 *)this, -1);
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    if (m_374 & 0x40) {
        velocity.y = (velocity.y > -6.0f) ? velocity.y : -6.0f;
        if (actorFlags & 0x800000) {
            m_374 = (s16)(m_374 & 0xFFFFFFBF);
            if (TLobby::get_instance() == 1) {
                play_sound_effect(0x3AB44, (uaddr)&position, 0, 0);
            } else {
                play_sound_effect(0x4003AB33, (uaddr)&position, 0, 0);
            }
            bodies->flags |= 1;
        }
    }
    if ((obj_testFlags30(0x800) != 0) && !(m_374 & 2)) {
        m_380++;
        if ((is_actor_cadence_frame(0x1E) != 0) && (((u16)find_nearest_visible_player(this, NULL, 120.0f) == 0xFFFFU) || (m_380 >= 0x384))) {
            set_boss4_state();
            requested_action = 9;
        }
    }
}
#pragma pop



}

extern void *tl_04;

void *TObjEneLappy::create(void *set) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneLappy(control, set);
}


#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Set_800C1C4C {
    u8 pad0[0xA];
    s16 fa;
    u8 padC[0x10 - 0xC];
    f32 pos[3];
    f32 rot[3];
    f32 params[5];
    s16 f3c;
    s16 f3e;
};
struct Lappy_800C1C4C { u8 pad[0x354]; f32 params[5]; };

extern "C" {
__declspec(section ".data") saddr lappy_boss_stats_handles[2];
__declspec(section ".data") saddr lappy_boss_stats_ptrs_b[2];
__declspec(section ".data") saddr lappy_object_handles[2];
__declspec(section ".data") f32 *lappy_variant_speed_ptr_table[2];

s32 release_texture_list(void*);
}
u8 *load_gvm_texture_file(saddr name);
extern s32 game_difficulty_selection;
extern s32 TLobby__event_theme_id;

void TObjEneLappy::free_resources() {
    if (TLobby::get_instance() == 0) {
        if (rappy_alternate_texture_list != 0) {
            release_texture_list((void *)rappy_alternate_texture_list);
            TAdSinglePlyChrSelectGC::safe_free(rappy_alternate_texture_list);
            rappy_alternate_texture_list = 0;
        }
    } else {
        rappy_alternate_texture_list = 0;
    }
    if (rappy_bml_resource != NULL) {
        delete rappy_bml_resource;
        rappy_bml_resource = NULL;
    }
}


void TObjEneLappy::load_resources() {
    int rare;
    s32 i;

    rare = game_difficulty_selection == 3;
    if (get_main_phase() == 0xF) {
        switch (TLobby__event_theme_id) {
        case 1:
            lappy_variant_id = 1;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492E08, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492DC0, 0, 0, NULL);
            }
            break;
        case 4:
            lappy_variant_id = 2;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492CE8, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492CA0, 0, 0, NULL);
            }
            break;
        case 5:
            lappy_variant_id = 3;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492D78, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492D30, 0, 0, NULL);
            }
            break;
        default:
            lappy_variant_id = 0;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C58, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C10, 0, 0, NULL);
            }
            break;
        }
    } else {
        lappy_variant_id = 0;
        if (rare) {
            rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C58, 0, 0, NULL);
        } else {
            rappy_bml_resource = new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C10, 0, 0, NULL);
        }
    }
    if (TLobby::get_instance() == 0) {
        if (rare) {
            rappy_alternate_texture_list = (uaddr)load_gvm_texture_file((saddr)re3_b_lappy_base_niji_gvm);
        } else {
            rappy_alternate_texture_list = (uaddr)load_gvm_texture_file((saddr)re3_b_lappy_base_ao_gvm);
        }
    } else {
        rappy_alternate_texture_list = (uaddr)rappy_bml_resource->models[1].m_c;
    }
    rappy_visibility_node = (s32 *)find_model_node((uaddr)rappy_bml_resource->models[0].model, 0x12);
    for (i = 0; i < 2; i++) {
        lappy_boss_stats_handles[i] = (saddr)TLobby::register_boss(i + 0x18);
        lappy_boss_stats_ptrs_b[i] = (saddr)TLobby::dispatch_shared_handler_b(i + 0x18);
        lappy_object_handles[i] = (saddr)TLobby::register_object(i + 0x18);
        lappy_variant_speed_ptr_table[i] = (f32 *)TLobby::dispatch_shared_handler_a(i + 0x18);
    }
    {
        BmlResource *res = rappy_bml_resource;
        NpcAnimationBinding d = lappy_resource_binding_desc;
        d.motions = res->motions;
        NpcModelRegistry::register_animated_chunk(5, rappy_bml_resource->models[0].model, rappy_bml_resource->models[0].m_c, &d, 10.0f, 0.0f);
        if (TLobby::get_instance() == 0) {
            NpcModelRegistry::register_animated_chunk(6, rappy_bml_resource->models[0].model, (void *)rappy_alternate_texture_list, &d, 10.0f, 0.0f);
        } else {
            NpcModelRegistry::register_animated_chunk(6, rappy_bml_resource->models[1].model, rappy_bml_resource->models[1].m_c, &d, 10.0f, 0.0f);
        }
    }
}

__declspec(section ".rodata") const char re3_b_lappy_base_niji_gvm[] = "re3_b_lappy_base_niji.gvm";
__declspec(section ".rodata") const char re3_b_lappy_base_ao_gvm[] = "re3_b_lappy_base_ao.gvm";


TObjEneLappy::~TObjEneLappy() {
    free_collision_body_parts(this);
}

#pragma defer_codegen on

void TObjEneLappy::sub_800C20C0() {
    this->m_374 = (s16) (this->m_374 | 1);
}

void TObjEneLappy::sub_800C20B0() {
    this->m_374 = (s16) (this->m_374 & 0xFFFFFFFE);
}

void TObjEneLappy::set_speed_params(s32 variant) {
    void *body;
    GinjaTextureList *textures;

    if (TLobby::get_instance() == 0) {
        model = rappy_bml_resource->models[0].model;
    } else {
        if (variant == 0) {
            body = rappy_bml_resource->models[0].model;
        } else {
            body = rappy_bml_resource->models[1].model;
        }
        model = body;
    }
    if (variant == 0) {
        textures = rappy_bml_resource->models[0].m_c;
    } else {
        textures = (GinjaTextureList *)rappy_alternate_texture_list;
    }
    texlist = (saddr)textures;
}

int TObjEneLappy::test_flag_256() { return 0; }

#define CLAMP_800C1C4C(x, lo, hi) ((x) < (lo) ? (lo) : ((x) < (hi) ? (x) : (hi)))

TObjEneLappy::TObjEneLappy(TObject *parent, void *set_data) : TObjEnemy(parent) {
    Set_800C1C4C *set = (Set_800C1C4C *)set_data;
    s32 i;
    f32 scale;

    m_name = TObjEneLappy__class_name;
    apply_set_data(set);
    motion_list = rappy_bml_resource->motions;
    VecCopy(&position, (const Vec *)set->pos);
    copy_xyz(&rotation_x, set->rot);
    for (i = 0; i < 5; i++) {
        parameters[i] = set->params[i];
    }
    variant = set->f3c != 0 ? 1 : 0;
    if (random_ratio() < 0.002f) {
        variant = 1;
        if (TLobby::get_instance() == 1) {
            rappy_visibility_node = (s32 *)find_model_node((uaddr)rappy_bml_resource->models[1].model, 0x12);
        }
    }
    if (variant == 0) {
        set_param(5);
    } else if (TLobby::get_instance() == 1) {
        switch (lappy_variant_id) {
        case 1:
            set_param(0x4F);
            break;
        case 2:
            set_param(0x51);
            break;
        case 3:
            set_param(0x50);
            break;
        default:
            set_param(0x33);
            break;
        }
    } else {
        set_param(6);
    }
    state36C = set->f3e;
    resetTimer = 0xF;
    timer = resetTimer;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    VecCopy(&move_origin, &position);
    VecCopy(&move_destination, &position);
    m_374 = 0;
    m_396 = 0;
    m_382 = -1;
    m_384 = 0;
    m_380 = 0;
    m_378 = CLAMP_800C1C4C((s16)parameters[0], 0, 1);
    m_37a = 0;
    movementParameters = lbl_80492EC4;
    init_collision_body_parts(this, lbl_80492EFC, 1);
    if (set->fa > 0) {
        m_374 |= 0x60;
        m_378 = 1;
        actorFlags &= ~0x800000;
        bodies->flags &= ~1;
    }
    bind_enemy_combat_stats((u8 *)(lappy_boss_stats_handles[variant]), (u8 *)(lappy_boss_stats_ptrs_b[variant]), (u8 *)(lappy_object_handles[variant]));
    apply_variant_speeds();
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    register_object_by_id();
    scale = 6.0f * (1.0f + random_ratio());
    m_37e = 30.0f * scale;
    add_flags_2e4(1);
    actorFlags |= 0x40000;
    action_table = rappy_variant_speed_table;
    set_field_d8((saddr)action_table);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    m_379 = m_378;
    if (TObjEneDD::check_v2_mode() != 0 && random_ratio() < 0.033333335f) {
        m_374 |= 0x400;
    }
    clear_lobby_object_state();
}



