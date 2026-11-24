#include "pso/system/memory.h"
#include "pso/system/TLanguage_801E4874.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyMovement.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
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
#include "pso/object/base/TObjBase.h"
extern "C" const char rappy_variant_na_name[3] = "NA";

// The Rag Rappy archive and its event variants (xs Christmas, es Easter, hw Halloween, picked by
// TLobby::event_theme_id); the "ap" archives are the ones load_resources takes on difficulty 3.
const char *lappy_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_lappy_base.nj", NULL,
};
const char *lappy_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_bml_descriptor = {
    "bm_ene_lappy.bml", lappy_model_names, lappy_motion_names, 2, 10,
};
const char *lappy_ap_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_lappy_base.nj", NULL,
};
const char *lappy_ap_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_ap_bml_descriptor = {
    "bm_ene_lappy_ap.bml", lappy_ap_model_names, lappy_ap_motion_names, 2, 10,
};
const char *lappy_es_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_elappy_base.nj", NULL,
};
const char *lappy_es_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_es_bml_descriptor = {
    "bm_ene_lappy_es.bml", lappy_es_model_names, lappy_es_motion_names, 2, 10,
};
const char *lappy_ap_es_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_elappy_base.nj", NULL,
};
const char *lappy_ap_es_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_ap_es_bml_descriptor = {
    "bm_ene_lappy_ap_es.bml", lappy_ap_es_model_names, lappy_ap_es_motion_names, 2, 10,
};
const char *lappy_hw_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_hlappy_base.nj", NULL,
};
const char *lappy_hw_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_hw_bml_descriptor = {
    "bm_ene_lappy_hw.bml", lappy_hw_model_names, lappy_hw_motion_names, 2, 10,
};
const char *lappy_ap_hw_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_hlappy_base.nj", NULL,
};
const char *lappy_ap_hw_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_ap_hw_bml_descriptor = {
    "bm_ene_lappy_ap_hw.bml", lappy_ap_hw_model_names, lappy_ap_hw_motion_names, 2, 10,
};
const char *lappy_xs_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_slappy_base.nj", NULL,
};
const char *lappy_xs_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_xs_bml_descriptor = {
    "bm_ene_lappy_xs.bml", lappy_xs_model_names, lappy_xs_motion_names, 2, 10,
};
const char *lappy_ap_xs_model_names[3] = {
    "re3_b_lappy_base.nj", "re3_s_slappy_base.nj", NULL,
};
const char *lappy_ap_xs_motion_names[11] = {
    "attack_re3_b_base.njm", "damage_re3_b_base.njm", "die_re3_b_base.njm", "run_re3_b_base.njm",
    "tumble_re3_b_base.njm", "wait2_re3_b_base.njm", "wait_re3_b_base.njm", "wake2_re3_b_base.njm",
    "wake_re3_b_base.njm", "walk_re3_b_base.njm", NULL,
};
BmlResourceDescriptor lappy_ap_xs_bml_descriptor = {
    "bm_ene_lappy_ap_xs.bml", lappy_ap_xs_model_names, lappy_ap_xs_motion_names, 2, 10,
};
TObjMotionAction lappy_motion_actions[10] = {
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
const char *lappy_variant_names[3] = {
    "RAG-LAPPY", "AL-LAPPY", rappy_variant_na_name,
};
LappyMovementParameters lappy_movement_params[2] = {
    {150.0f, 0.537037f, 0x400, {0x1E0000, 0, 1, 0}},
    {150.0f, 0.537037f, 0x400, {0x1E0000, 0, 1, 0}},
};
CollisionBody lappy_collision_bodies[1] = {
    {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneLappy__class_name = "TObjEneLappy";


const NpcAnimationBinding lappy_resource_binding_desc = { NULL, lappy_motion_actions, 1, 3, 10 };

const Vec lappy_target_zero_vec = {0.0f, 0.0f, 0.0f};

extern "C" __declspec(section ".data") f32 *lappy_variant_speed_ptr_table[2];


#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/object/ambient/TObjLight_80133568.h"




#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/dd/TObjEneDD_800B9AF8.h"
// Kept here: the owner headers (TObjPlayer_80011014.h, text_800FD930.h)
// give get_entity_id a u16 and is_item_light_interaction_blocked a bool
// return, and these callers zero-extend an int result.
void apply_actor_gravity(TObjEnemy *enemy, s32 *, f32 hover_height);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 is_item_light_interaction_blocked();
s32 check_path_obstructed(void *, void *);
f32 atan2_float(f32 y, f32 x);
s32 lappy_variant_id;
}
BmlResource *rappy_bml_resource;
extern "C" {
NJS_OBJECT *rappy_visibility_node;
NJS_TEXLIST *rappy_alternate_texture_list;
}

void TObjEneLappy::clear_flags_60() {
    s16 flags;

    flags = lappy_flags;
    if (flags & 0x60) {
        lappy_flags = flags & ~0x60;
        project_actor_to_ground(this, &position, 0);
        set_actor_flags(0x800000);
    }
}

s32 TObjEneLappy::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_flags_60();
        return 1;
    }
    return 0;
}

s32 TObjEneLappy::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        clear_flags_60();
        return 1;
    }
    return 0;
}

void TObjEneLappy::set_flag_and_notify() {
    s16 flags;

    flags = lappy_flags;
    if (!(flags & 0x80)) {
        lappy_flags = (s16)(flags | 0x80);
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
    lappy_motion_actions[6].speed = p[1];
    lappy_motion_actions[8].speed = p[2];
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
        play_sound_effect(remap_area_sound_id(0x3D20C, 5), &position, 0, 0);
    }
}
void TObjEneLappy::sub_800BFF54() {}

void TObjEneLappy::render() {
    s32 detail;
    if (test_actor_flags(0x02000000) == 0) {
        if (this->lappy_flags & LAPPY_NODE_VISIBLE) {
            rappy_visibility_node->evalflags &= ~NJD_EVAL_HIDE;
        } else {
            rappy_visibility_node->evalflags |= NJD_EVAL_HIDE;
        }
        detail = this->classify_actor_view_detail(150.0f, 400.0f, 10.0f);
        if (detail != 0) {
            set_speed_params(this->variant);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            if (this->lappy_flags & 0x400) {
                scale_matrix(0, 2.0f, 1.5f, 2.0f);
                TObjEneDD__sub_800B9B24(0.6666667f);
            }
            model_render_flags &= 0xFFFFFBFF;
            set_motion_packed_rotation();
            if (is_item_light_interaction_blocked() == 1) {
                draw_chunk_object(model);
            } else {
                model_render_flags |= 0x01000000;
                if (detail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                model_render_flags &= 0xFEFFFFFF;
            }
            clear_motion_packed_rotation();
            if (this->lappy_flags & 0x400) {
                TObjEneDD::init_lights();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(this->actorFlags & 0x800) && (test_actor_flags(0x800000) != 0)) {
                this->TObjEnemy::draw_ground_shadow(0, 0);
            }
        }
    }
}

void TObjEneLappy::start_fleeing() {
    s16 flags;
    flags = this->lappy_flags;
    if (!(flags & LAPPY_FLEEING)) {
        this->lappy_flags = (flags | LAPPY_FLEEING);
        flee_turn_timer = 0;
        this->flee_heading = (s32) (182.04445f * (360.0f * random_ratio()));
    }
    this->mode = 1;
    this->move_phase = 3;
    clear_harmful_statuses();
    this->hp = 1;
    this->actorFlags = (s32) (this->actorFlags & ~0xA00);
}
void TObjEneLappy::update_dying() {
    clear_flag_1();
    advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, 0, 0.0f);
    }
    refresh_collision_body_centers();
    if (this->frame < (0.5f * (30.0f * this->play_speed))) {
        move_with_wall_slide(this);
        this->velocity.x *= 0.5f;
        this->velocity.z *= 0.5f;
    }
}
void TObjEneLappy::run_death_reaction() {
    s16 flags;
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    flags = this->lappy_flags;
    if (flags & LAPPY_FLEEING) {
        if (!(flags & LAPPY_FLEE_KILLED)) {
            this->lappy_flags = (s16) (flags | LAPPY_FLEE_KILLED);
            play_sound_effect(remap_area_sound_id(0x3AD13, 5), &position, 0, 0);
            query_lobby_state();
            this->requested_action = 8;
        }
    } else if ((s16) this->mode != 5) {
        this->mode = 5;
        this->requested_action = 7;
        if (!(this->lappy_flags & LAPPY_NO_EXPERIENCE)) {
            play_sound_effect(remap_area_sound_id(0x3AE10, 5), &position, 0, 0);
            this->distribute_experience();
            set_flag_and_notify();
        }
        this->down_timer = 0;
    }
}

void TObjEneLappy::update_hurt() {
    advance_animation();
    Vec v = body_center;
    v.x += velocity.x;
    v.z += velocity.z;
    if (check_path_obstructed(this, &v) == 0) {
        move_with_wall_slide(this);
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
        if (this->lappy_flags & 2) {
            start_fleeing();
            this->requested_action = 4;
        }
    }
}

void TObjEneLappy::run_hit_reaction() {
    TObjPlayer *attacker;
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    if (this->lappy_flags & LAPPY_FLEEING) {
        this->clear_actor_flags(0x23F);
        return;
    }
    if ((s16) this->mode != 4) {
        this->mode = 4;
        this->requested_action = 6;
        attacker = get_player_by_client_id(this->attacker_id);
        if ((attacker != NULL) && !(xyz_distance_squared(&position, &attacker->position) < 10000.0f)) {
            this->lappy_flags = (s16) (this->lappy_flags | LAPPY_FLEEING);
            set_flag_and_notify();
        }
        play_sound_effect(remap_area_sound_id(0x3B10F, 5), &position, 0, 0);
    }
}

void TObjEneLappy::update_invuln_timer() {
    advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, NULL, 0.0f);
    }
    update_collisions();
    if (this->timer-- < 0) {
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
    TObjChara *hit;
    advance_animation();
    switch (phase) {
    case 0:
        enemy_turn_toward_dest(((LappyMovementParameters *)movementParameters)->turn_speed);
        apply_actor_gravity(this, NULL, 0.0f);
        if (is_passing_frame(11.0f) != 0) {
            enemy_set_heading_velocity(((LappyMovementParameters *)movementParameters)->move_speed, this, rotation_y);
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
            if (hit != NULL && hit->select_melee_contact_body(this, 1.0f) != 0) {
                target->receive_physical_attack(this, 1.0f);
                target->apply_knockback_from_attacker((u8 *)this, 3.0f);
            }
            play_sound_effect(remap_area_sound_id(0x3BC0D, 5), &position, 0, 0);
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
    u16 id;
    if (!(this->lappy_flags & (LAPPY_FLEEING | LAPPY_FALLING)) && (test_actor_flags(0xA02) == 0) && ((s16) this->mode != 2)) {
        this->mode = 2;
        this->requested_action = 5;
        this->phase = 0;
        this->actorFlags |= 0x200000;
        if ((s16) this->last_attack_target != (s32) (id = this->targetId)) {
            this->last_attack_target = (s16) id;
            this->attack_streak = 0;
        } else {
            this->attack_streak = (s16) (this->attack_streak + 1);
        }
        this->pad_388 = 0;
    }
}
#pragma push
#pragma opt_common_subs off

void TObjEneLappy::update_moving() {
    Vec probe;
    f32 dist;
    s32 turn;
    u32 flags;
    TObjChara *chased;
    LappyMovementParameters *params;
    advance_animation();
    if ((actorFlags & 0x1000) && !(lappy_flags & 2)) {
        chased = target;
        if (chased != NULL) {
            enemy_backstep_from_point(this, ((TObjChara *)chased)->body_center, ((LappyMovementParameters *)movementParameters)->move_speed);
            turn_toward_direction(((LappyMovementParameters *)movementParameters)->turn_speed, &velocity);
            apply_actor_gravity(this, NULL, 0.0f);
            update_collisions();
            return;
        }
    }
    flags = action_flags;
    if (flags == 1U) {
        switch (move_phase) {
        case 0:
            chased = target;
            if (chased != NULL) {
                dist = update_enemy_wander_move(this, ((TObjChara *)chased)->body_center, 1, ((LappyMovementParameters *)movementParameters)->move_speed);
                if ((test_actor_flags(2) == 0) && (dist < 10000.0f)) {
                    move_phase = 1;
                    pad_398 = 0;
                    random_ratio();
                    pad_39c = 0.0f;
                }
                params = (LappyMovementParameters *)movementParameters;
                if (params->target_range * params->target_range < dist || dist < params->move_speed * params->move_speed) {
                    target = NULL;
                }
            } else {
                params = (LappyMovementParameters *)movementParameters;
                enemy_wander_home(params->move_speed, 100.0f, 50.0f, params->turn_speed);
            }
            turn_toward_direction(((LappyMovementParameters *)movementParameters)->turn_speed, &velocity);
            play_walk_sound();
            goto block_48;
        case 1:
            chased = target;
            if (chased != NULL) {
                dist = update_enemy_wander_move(this, ((TObjChara *)chased)->body_center, 1, ((LappyMovementParameters *)movementParameters)->move_speed);
                if (dist > 22500.0f) {
                    move_phase = 0;
                }
                turn_toward_direction(((LappyMovementParameters *)movementParameters)->turn_speed, &velocity);
                params = (LappyMovementParameters *)movementParameters;
                if (params->target_range * params->target_range < dist || dist < params->move_speed * params->move_speed) {
                    target = NULL;
                }
            } else {
                move_phase = 0;
            }
            play_walk_sound();
            goto block_48;
        case 2:
            break;
        case 3:
            rotation_y = lerp_angle_half(rotation_y, flee_heading);
            if (action_flags == 1U) {
                actorFlags &= 0xFBFFFFFF;
                move_phase = 4;
                play_sound_effect(remap_area_sound_id(0x3AF12, 5), &position, 0, 0);
            }
            if (is_passing_frame(30.0f) != 0) {
                play_sound_effect(remap_area_sound_id(0x3AA11, 5), &position, 0, 0);
            }
            goto block_48;
        case 4:
            if (flags == 1U) {
                enemy_set_heading_velocity(3.5f * ((LappyMovementParameters *)movementParameters)->move_speed, this, rotation_y);
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
                if (--dust_timer < 0) {
                    spawn_particle_effect(&position, 0xF3);
                    dust_timer = 2;
                }
                play_persistent_sound(remap_sound_for_area(0x3AF12), this, &position, 0, 0);
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
    void *chased;
    if (!(this->lappy_flags & (LAPPY_FLEEING | LAPPY_FALLING)) && !(this->actorFlags & 0xA00)) {
        if ((s16) this->mode != 1) {
            chased = this->target;
            if (chased != NULL) {
                if (select_enemy_destination(this, ((TObjChara *)chased)->body_center, 1) == 1) {
                    switch ((s8)this->idle_mode) {
                    case 0:
                        this->requested_action = 3;
                        break;
                    case 1:
                        this->requested_action = 2;
                        break;
                    }
                    this->move_phase = 0;
                    this->down_timer = 0;
                    this->idle_mode = 0U;
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
void TObjEneLappy::update_idle_state() {
    f32 range;

    if (is_actor_cadence_frame(0x1E) != 0) {
        if ((s8)home_idle_mode != 0) {
            range = 10.0f;
        } else {
            range = 100.0f;
        }
        if (xz_distance_squared(&position, &home_position) > range * range) {
            idle_mode = 2;
            requested_action = 3;
        } else if ((s8)idle_mode != (s8)home_idle_mode) {
            idle_mode = home_idle_mode;
            phase = 0;
        }
    }
    switch ((s8)idle_mode) {
    case 0:
        switch (phase) {
        case 0:
            idle_timer = 45.0f * (1.0f + random_ratio());
            phase = requested_action = 1;
        case 1:
            idle_timer--;
            if (idle_timer < 0) {
                play_sound_effect(remap_area_sound_id(0x3B20B, 5), &position, 0, 0);
                phase = 2;
            }
            break;
        case 2:
            wander_distance = 30.0f;
            phase = requested_action = 3;
        case 3:
            enemy_wander_home(((LappyMovementParameters *)movementParameters)->move_speed, 100.0f, 100.0f, ((LappyMovementParameters *)movementParameters)->turn_speed);
            wander_distance -= ((LappyMovementParameters *)movementParameters)->move_speed;
            if (wander_distance < 0.0f) {
                phase = 0;
            }
            break;
        }
        advance_animation();
        break;
    case 1:
        requested_action = 0;
        advance_animation();
        idle_timer--;
        if (idle_timer < 0) {
            play_sound_effect(remap_area_sound_id(0x3B20B, 5), &position, 0, 0);
            idle_timer = 30.0f * (6.0f * (1.0f + random_ratio()));
        }
        break;
    case 2: {
        advance_animation();
        update_enemy_wander_move(this, home_position, 7, ((LappyMovementParameters *)movementParameters)->move_speed);
        turn_toward_direction(((LappyMovementParameters *)movementParameters)->turn_speed, &velocity);
        break;
    }
    }
    refresh_collision_body_centers();
    if (!(actorFlags & 0x800000)) {
        apply_actor_gravity(this, NULL, 0.0f);
    }
    if (actorFlags & 0x40000) {
        if (timer-- < 0) {
            actorFlags &= ~0x40000;
            timer = resetTimer;
        }
    }
}
#pragma pop

void TObjEneLappy::run_idle_action() {
    s16 flags;
    flags = this->lappy_flags;
    if (!(flags & 2) && !(this->actorFlags & 0xA00)) {
        if (flags & 0x20) {
            this->lappy_flags = flags & ~0x20;
            this->clear_actor_flags(0x02000000);
            Vec v = position;
            if (project_actor_to_ground(this, &v, 0) == 1) {
                position.y = 300.0f + v.y;
            }
        }
        if (this->mode != 0) {
            this->mode = 0;
            this->phase = 0;
            switch ((s8) this->idle_mode) {
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
    u16 best_id;
    s32 i;
    u16 id;
    TObjPlayer *p;
    f32 best;
    f32 d;
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (actorFlags & 0x1000) {
            if ((frame_timer -= 1.0f) < 0.0f) {
                targetId = 0xFFFFU;
                frame_timer = 0.0f;
            } else {
                targetId = find_nearest_visible_player(this, NULL, ((LappyMovementParameters *)movementParameters)->target_range);
            }
        } else if (test_actor_flags(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = lappy_target_zero_vec;
            best = ((LappyMovementParameters *)movementParameters)->target_range * ((LappyMovementParameters *)movementParameters)->target_range;
            for (; i < registered_player_count + registered_enemy_count; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = p->get_entity_id();
                if (id < 0x4000 && id != entity_id && !(p->actorFlags & 0x800)) {
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
            targetId = find_nearest_visible_player(this, NULL, ((LappyMovementParameters *)movementParameters)->target_range);
        }
    }
    if (attack_streak > 3 && last_attack_target == targetId) {
        s32 j;
        TObjPlayer *q;
        for (j = 0; j < registered_player_count; j++) {
            q = TObjPlayer::get_player_data(j);
            if (q != NULL && last_attack_target != q->get_entity_id() && !(q->actorFlags & 0x800)) {
                if (xz_distance_squared(&q->body_center, &body_center) < 2500.0f) {
                    targetId = j;
                }
                break;
            }
        }
    }
}

void TObjEneLappy::run_task() {
    set_flag_1();
    if (TObjPlayer::check_demo_mode() == 1) {
        apply_variant_speeds();
        sub_800BFF54();
        return;
    }
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    if (target != NULL && (target->actorFlags & 0x800)) {
        target = NULL;
        targetId = 0xFFFF;
    }
    switch (mode) {
    case 0:
        update_idle_state();
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
        update_dying();
        break;
    }
    update_prev_position();
    VecCopy(&center, &body_center);
    if ((test_actor_flags(0x06000000) == 0) && !(lappy_flags & 4)) {
        submit_cursor_candidate((u8 *)this, -1);
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    if (lappy_flags & 0x40) {
        velocity.y = (velocity.y > -6.0f) ? velocity.y : -6.0f;
        if (actorFlags & 0x800000) {
            lappy_flags = (s16)(lappy_flags & 0xFFFFFFBF);
            if (TLobby::get_instance() == 1) {
                play_sound_effect(0x3AB44, &position, 0, 0);
            } else {
                play_sound_effect(0x4003AB33, &position, 0, 0);
            }
            bodies->flags |= 1;
        }
    }
    if ((test_actor_flags(0x800) != 0) && !(lappy_flags & 2)) {
        down_timer++;
        if ((is_actor_cadence_frame(0x1E) != 0) && (((u16)find_nearest_visible_player(this, NULL, 120.0f) == 0xFFFFU) || (down_timer >= 0x384))) {
            start_fleeing();
            requested_action = 9;
        }
    }
}
#pragma pop




void *TObjEneLappy::create(void *set) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneLappy(control, set);
}


#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
__declspec(section ".data") player_stats *lappy_boss_stats_handles[2];
__declspec(section ".data") AttackParams *lappy_boss_stats_ptrs_b[2];
__declspec(section ".data") ActorParamBlock *lappy_object_handles[2];
__declspec(section ".data") f32 *lappy_variant_speed_ptr_table[2];
}

void TObjEneLappy::free_resources() {
    if (TLobby::get_instance() == 0) {
        if (rappy_alternate_texture_list != 0) {
            release_texture_list(rappy_alternate_texture_list);
            safe_free(rappy_alternate_texture_list);
            rappy_alternate_texture_list = 0;
        }
    } else {
        rappy_alternate_texture_list = NULL;
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
        switch (TLobby::event_theme_id) {
        case 1:
            lappy_variant_id = 1;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, &lappy_ap_xs_bml_descriptor, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, &lappy_xs_bml_descriptor, 0, 0, NULL);
            }
            break;
        case 4:
            lappy_variant_id = 2;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, &lappy_ap_es_bml_descriptor, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, &lappy_es_bml_descriptor, 0, 0, NULL);
            }
            break;
        case 5:
            lappy_variant_id = 3;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, &lappy_ap_hw_bml_descriptor, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, &lappy_hw_bml_descriptor, 0, 0, NULL);
            }
            break;
        default:
            lappy_variant_id = 0;
            if (rare) {
                rappy_bml_resource = new BmlResource(1, &lappy_ap_bml_descriptor, 0, 0, NULL);
            } else {
                rappy_bml_resource = new BmlResource(1, &lappy_bml_descriptor, 0, 0, NULL);
            }
            break;
        }
    } else {
        lappy_variant_id = 0;
        if (rare) {
            rappy_bml_resource = new BmlResource(1, &lappy_ap_bml_descriptor, 0, 0, NULL);
        } else {
            rappy_bml_resource = new BmlResource(1, &lappy_bml_descriptor, 0, 0, NULL);
        }
    }
    if (TLobby::get_instance() == 0) {
        if (rare) {
            rappy_alternate_texture_list = load_gvm_texture_file(re3_b_lappy_base_niji_gvm);
        } else {
            rappy_alternate_texture_list = load_gvm_texture_file(re3_b_lappy_base_ao_gvm);
        }
    } else {
        rappy_alternate_texture_list = rappy_bml_resource->models[1].texlist;
    }
    rappy_visibility_node = find_model_node(rappy_bml_resource->models[0].model, 0x12);
    for (i = 0; i < 2; i++) {
        lappy_boss_stats_handles[i] = TLobby::register_boss(i + 0x18);
        lappy_boss_stats_ptrs_b[i] = TLobby::dispatch_shared_handler_b(i + 0x18);
        lappy_object_handles[i] = TLobby::register_object(i + 0x18);
        lappy_variant_speed_ptr_table[i] = (f32 *)TLobby::dispatch_shared_handler_a(i + 0x18);
    }
    {
        BmlResource *res = rappy_bml_resource;
        NpcAnimationBinding d = lappy_resource_binding_desc;
        d.motions = res->motions;
        TObjNpcEnemy::register_animated_chunk(5, rappy_bml_resource->models[0].model, rappy_bml_resource->models[0].texlist, &d, 10.0f, 0.0f);
        if (TLobby::get_instance() == 0) {
            TObjNpcEnemy::register_animated_chunk(6, rappy_bml_resource->models[0].model, rappy_alternate_texture_list, &d, 10.0f, 0.0f);
        } else {
            TObjNpcEnemy::register_animated_chunk(6, rappy_bml_resource->models[1].model, rappy_bml_resource->models[1].texlist, &d, 10.0f, 0.0f);
        }
    }
}

__declspec(section ".rodata") const char re3_b_lappy_base_niji_gvm[] = "re3_b_lappy_base_niji.gvm";
__declspec(section ".rodata") const char re3_b_lappy_base_ao_gvm[] = "re3_b_lappy_base_ao.gvm";


TObjEneLappy::~TObjEneLappy() {
    free_collision_body_parts(this);
}

#pragma defer_codegen on

void TObjEneLappy::set_flag_1() {
    this->lappy_flags = (s16) (this->lappy_flags | LAPPY_NODE_VISIBLE);
}

void TObjEneLappy::clear_flag_1() {
    this->lappy_flags = (s16) (this->lappy_flags & ~LAPPY_NODE_VISIBLE);
}

void TObjEneLappy::set_speed_params(s32 variant) {
    void *body;
    NJS_TEXLIST *textures;

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
        textures = rappy_bml_resource->models[0].texlist;
    } else {
        textures = rappy_alternate_texture_list;
    }
    texlist = textures;
}

int TObjEneLappy::test_flag_256() { return 0; }

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) < (hi) ? (x) : (hi)))

TObjEneLappy::TObjEneLappy(TObject *parent, void *set_data) : TObjEnemy(parent) {
    LappySetData *set = (LappySetData *)set_data;
    s32 i;
    f32 scale;

    m_name = TObjEneLappy__class_name;
    apply_set_data(set);
    motion_list = rappy_bml_resource->motions;
    VecCopy(&position, &set->position);
    copy_xyz(&rotation_x, set->rotation);
    for (i = 0; i < 5; i++) {
        parameters[i] = set->parameters[i];
    }
    variant = set->variant != 0 ? 1 : 0;
    if (random_ratio() < 0.002f) {
        variant = 1;
        if (TLobby::get_instance() == 1) {
            rappy_visibility_node = find_model_node(rappy_bml_resource->models[1].model, 0x12);
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
    state36C = set->state;
    resetTimer = 0xF;
    timer = resetTimer;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    VecCopy(&move_origin, &position);
    VecCopy(&move_destination, &position);
    lappy_flags = 0;
    dust_timer = 0;
    last_attack_target = -1;
    attack_streak = 0;
    down_timer = 0;
    idle_mode = CLAMP((s16)parameters[0], 0, 1);
    move_phase = 0;
    movementParameters = lappy_movement_params;
    init_collision_body_parts(this, lappy_collision_bodies, 1);
    if (set->wave > 0) {
        lappy_flags |= LAPPY_DROP_IN | LAPPY_FALLING;
        idle_mode = 1;
        actorFlags &= ~0x800000;
        bodies->flags &= ~1;
    }
    bind_enemy_combat_stats(lappy_boss_stats_handles[variant], lappy_boss_stats_ptrs_b[variant], lappy_object_handles[variant]);
    apply_variant_speeds();
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    copy_position();
    register_object_by_id();
    scale = 6.0f * (1.0f + random_ratio());
    idle_timer = 30.0f * scale;
    add_flags_2e4(1);
    actorFlags |= 0x40000;
    action_table = lappy_motion_actions;
    set_action_table(action_table);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    home_idle_mode = idle_mode;
    if (TObjEneDD::check_v2_mode() != 0 && random_ratio() < 0.033333335f) {
        lappy_flags |= 0x400;
    }
    clear_lobby_object_state();
}
