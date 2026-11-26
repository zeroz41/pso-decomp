#include "pso/enemy/EnemyPlacement.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/balclaw/TObjEneBalClawBody.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/network/TLobby.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/TObjControl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/DebugFont.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/system/MatrixOps.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/TDeadSpot.h"

static const char balclaw_body_class_name_text[] = "TObjEneBalClawBody";

// The body's actions (TObjMotion::action_table, installed by the ctor).
TObjMotionAction balclaw_body_actions[12] = {
    {1, 0, 9, 0.8f, 0},
    {1, 1, 9, 0.8f, 1},
    {2, 0, 6, 0.5f, 4},
    {2, 0, 7, 0.6f, 8},
    {3, 4, 8, 0.5f, 0x10},
    {1, 5, 5, 0.8f, 0},
    {1, 5, 5, 0.8f, 1},
    {2, 5, 0, 0.6f, 4},
    {2, 5, 2, 0.7f, 8},
    {3, 5, 3, 0.6f, 0x10},
    {2, 5, 4, 0.5f, 1},
    {2, 5, 1, 0.6f, 1},
};

// Movement rows; TObjEnemy::movementParameters points at one.
BalClawMovement balclaw_body_movement[2] = {
    {{150.0f, 0.5555555f, 0x400}, 30, 0, 0, 1, 0},
    {{150.0f, 0.5555555f, 0x400}, 30, 0, 0, 1, 0},
};

// The body's one collision sphere (init_collision_body_parts in the ctor).
CollisionBody balclaw_body_collision = {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

player_stats *balclaw_body_base_params[2];
AttackParams *balclaw_body_attack_params[2];
ActorParamBlock *balclaw_body_resistance_params[2];
BalClawBehaviorParams *balclaw_body_behavior_params[2];
const char *balclaw_body_class_name = balclaw_body_class_name_text;


// int_params[0] is the hp percent at which the body turns on its target (update_damage).
s32 TObjEneBalClawBody::get_int_parameter(s32 i) {
    return balclaw_body_behavior_params[variant]->int_params[i];
}

int TObjEneBalClawBody::is_form_1() { return (behavior_flags >> 24) & 0x1; }

void TObjEneBalClaw::set_attack_distance_flag() { this->behavior_flags |= 0x10000; }

// Picks this part's model and texture list (index into the Bal Claw BML models).
void TObjEneBalClaw::set_model(s32 i) {
    model = balclaw_bml_resource->models[i].model;
    texlist = balclaw_bml_resource->models[i].texlist;
}

TObjEneBalClawBody::TObjEneBalClawBody(TObject *parent, EnemyPlacement *set_data) : TObjEneBalClaw(parent) {
    s32 i;
    m_name = balclaw_body_class_name;
    apply_set_data(set_data);
    VecCopy(&move_origin, (const Vec *)(VecCopy(&move_destination, (const Vec *)(&position))));
    motion_list = balclaw_bml_resource->motions;
    action_table = balclaw_body_actions;
    set_action_table(action_table);
    init_collision_body_parts(this, &balclaw_body_collision, 1);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    wobble_angle = 0;
    wobble_offset = 0.0f;
    clear_attack_flag();
    if (set_data->wave != 0) {
        start_appear();
    }
    hover_height_min = 25.0f;
    hover_height_max = 40.0f;
    hover_height = hover_height_min;
    child_count = 4;
    for (i = 0; i < 4; i++) {
        child_ids[i] = 0xFFFF;
    }
    this->set_form(1);
    bind_enemy_combat_stats(balclaw_body_base_params[0], balclaw_body_attack_params[0], balclaw_body_resistance_params[0]);
    effects[0] = NULL;
    effects[1] = NULL;
    effects[2] = NULL;
    effects[3] = NULL;
    clear_lobby_object_state();
}

TObjEneBalClawBody::~TObjEneBalClawBody() {
    s32 i;
    TObject *child;
    free_collision_body_parts(this);
    if (effects[0] != NULL) {
        effects[0]->queue_destruction();
    }
    if (effects[1] != NULL) {
        effects[1]->queue_destruction();
    }
    if (effects[2] != NULL) {
        effects[2]->queue_destruction();
    }
    if (effects[3] != NULL) {
        effects[3]->queue_destruction();
    }
    if (is_form_1() != 0) {
        for (i = 0; i < child_count; i++) {
            child = find_entity_by_id(child_ids[i]);
            if (child != NULL) {
                child->queue_destruction();
            }
        }
    }
}

void *TObjEneBalClawBody::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneBalClawBody(control, static_cast<EnemyPlacement *>(set_data));
}

void TObjEneBalClawBody::run_task() {
    scroll_part_uvs();
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        run_demo_task();
        return;
    }
    if ((behavior_flags & 0x02000000) && is_form_1() == 0) {
        update_if_active(2);
    } else {
        update_attack_distance_state();
    }
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            update_state();
        }
        mode = next_action;
        state = 0;
    }
    update_state();
    update_wobble();
    update_claw_angle();
    VecCopy(&body_center, &position);
    body_center.y += hover_height + wobble_offset;
    bodies->offset.y = hover_height + wobble_offset;
    submit_cursor_candidate(this, -1);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneBalClawBody::update_state() {
    switch (mode) {
    case 0:
        update_wait();
        return;
    case 1:
        this->update_chase();
        return;
    case 2:
        this->update_attack();
        return;
    case 9:
        this->update_combined_attack();
        return;
    case 4:
        this->update_damage();
        return;
    case 5:
        this->run_death_sequence();
        return;
    case 7:
        this->update_appear();
        return;
    case 10:
        this->update_combine();
        return;
    case 11:
        this->update_split();
        return;
    case 12:
        this->update_retreat();
        return;
    case 8:
        this->update_return_home();
        break;
    }
}

void TObjEneBalClawBody::update_attack_distance_state() {
    f32 d;
    s32 old;
    if (mode != 0 && mode != 8) {
        form_timer++;
    }
    if (is_form_1() != 0) {
        switch (mode) {
        case 0:
        case 1:
            if (form_timer > 0x708 || melee_hit_count >= 2) {
                update_if_active(0xB);
                return;
            }
            break;
        }
        if (is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range(250.0f);
        }
        switch (mode) {
        case 0:
        case 8:
            if (target != NULL) {
                update_if_active(1);
                range_band = 2;
            } else {
                return_home_or_idle();
            }
            break;
        case 1:
            if (target != NULL) {
                d = xz_distance_squared(&((TObjChara *)target)->position, &position);
                old = range_band;
                switch (old) {
                case 0:
                    if (d > 3600.0f) {
                        range_band = 1;
                    }
                    break;
                case 1:
                    if (d < 1600.0f) {
                        range_band = 0;
                    } else if (d > 14400.0f) {
                        range_band = 2;
                    }
                    break;
                case 2:
                    if (d < 10000.0f) {
                        range_band = 1;
                    }
                    break;
                }
                if (old != range_band) {
                    switch (range_band) {
                    case 0:
                        update_if_active(9);
                        break;
                    case 1:
                        clear_attack_flag();
                        break;
                    case 2:
                        set_attack_distance_flag();
                        break;
                    }
                }
            } else {
                update_if_active(8);
            }
            break;
        }
    } else {
        if (is_actor_cadence_frame(0x1E) != 0 && mode != 2) {
            find_target_in_range(250.0f);
        }
        switch (mode) {
        case 0:
            if (is_actor_cadence_frame(0x1E) != 0 && target == NULL) {
                update_if_active(0xA);
                return;
            }
            break;
        case 1:
        case 12:
            if (form_timer > 0x708) {
                update_if_active(0xA);
                return;
            }
            break;
        }
        switch (mode) {
        case 0:
        case 8:
            if (target != NULL) {
                update_if_active(0xC);
            } else {
                return_home_or_idle();
            }
            break;
        case 1:
            if (target == NULL) {
                update_if_active(8);
            }
            break;
        }
    }
}

void TObjEneBalClawBody::run_demo_task() {
}

void TObjEneBalClawBody::update_chase() {
    s16 v;
    switch (this->state) {
    case 0:
        this->actorFlags &= 0xFBFFFEFF;
        this->clear_flags_30();
        v = 6;
        if (this->behavior_flags & 0x01000000) {
            v = 1;
        }
        this->requested_action = v;
        this->state = 1;
        if (this->target != NULL) {
            VecCopy(&this->move_destination, &((TObjChara *)this->target)->body_center);
        }
        break;
    case 1:
        if (this->target == NULL) {
            this->reset_enemy_state();
            break;
        }
        play_persistent_sound(0x4003B235, this, &this->position, 0, 0);
        this->velocity.y = 0.0f;
        {
            update_enemy_wander_move(this, ((TObjChara *)this->target)->body_center, 1, ((EnemyMoveParams *)this->movementParameters)->min_distance);
        }
        this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        this->update_collisions();
        break;
    case -1:
        break;
    }
}

void TObjEneBalClawBody::update_damage() {
    s32 next_mode;
    s32 percent;
    switch (this->state) {
    case -1:
        break;
    case 0:
        this->actorFlags &= ~0x200000;
        this->requested_action = this->is_form_1() != 0 ? 3 : 8;
        this->state = 1;
    case 1: {
        this->advance_animation();
        this->velocity.y = 0.0f;
        Vec v = this->body_center;
        v.x += this->velocity.x;
        v.z += this->velocity.z;
        if (check_path_obstructed(this, &v) == 0) {
            move_with_wall_slide(this);
        } else {
            this->velocity.x = this->velocity.z = 0.0f;
        }
        this->velocity.x *= 0.9f;
        this->velocity.z *= 0.9f;
        apply_actor_gravity(this, NULL, 0.0f);
        this->update_collisions();
        if (this->action_flags != 8U) {
            next_mode = 0;
            this->referenceHp = this->hp;
            this->actorFlags &= ~0x200;
            this->behavior_flags &= ~1;
            if (this->is_form_1() == 0) {
                percent = this->get_int_parameter(0);
                if (percent <= 0) {
                    percent = 0xA;
                }
                if (this->hp <= (this->hpmax * percent) / 100) {
                    if (!(this->behavior_flags & 0x02000000)) {
                        this->targetId = this->attacker_id;
                        this->behavior_flags |= 0x02000000;
                    }
                    next_mode = 2;
                }
            }
            this->update_if_active(next_mode);
        }
        break;
    }
    }
}

void TObjEneBalClawBody::run_death_sequence() {
    s32 i;
    TObjEnemy *claw;
    switch (this->state) {
    case 0:
        refresh_lobby_state();
        this->behavior_flags &= ~0x20000;
        if (this->is_form_1() != 0) {
            this->requested_action = 4;
            this->state = 1;
            for (i = 0; i < this->child_count; i++) {
                claw = (TObjEnemy *)find_entity_by_id(this->child_ids[i]);
                if (claw != NULL) {
                    claw->send_entity_set_flags();
                    claw->queue_destruction();
                }
            }
        } else {
            this->requested_action = 9;
            this->velocity.y = this->hover_height / 11.666666f;
            this->state = 2;
        }
        play_sound_effect(0x4003AD37, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        break;
    case 1:
        this->advance_animation();
        if (this->frame >= 20.0f) {
            this->state = 3;
        }
        break;
    case 2:
        this->advance_animation();
        if (this->frame >= 10.0f) {
            this->hover_height -= this->velocity.y;
            if (this->hover_height <= 0.0f) {
                this->hover_height = 0.0f;
                this->state = 3;
            }
        }
        break;
    case 3:
        this->fade.start_fade_out();
        spawn_enemy_death_particles(&this->body_center);
        this->behavior_flags |= 4;
        this->state = 4;
    case 4:
        this->advance_animation();
        if ((&this->fade)->decay_value_toward_floor() == 1) {
            TDeadSpot::spawn_kind0_scale7_5(&this->position, 0);
            this->send_entity_set_flags();
            this->queue_destruction();
        }
        break;
    }
}

void TObjEneBalClawBody::update_attack() {
    switch (this->state) {
    case 0:
        if (this->is_form_1() != 0) {
            this->reset_enemy_state();
            return;
        }
        if (this->attacker_id < 0x1000) {
            this->targetId = this->attacker_id;
            this->target = static_cast<TObjChara *>(find_active_entity_by_id(this->targetId));
            if (this->target != NULL && (((TObjChara *)this->target)->actorFlags & 0x04000800)) {
                this->targetId = 0xFFFF;
                this->target = NULL;
            }
        } else {
            this->find_target_in_range(250.0f);
        }
        if (this->targetId != 0xFFFF) {
            this->behavior_flags &= ~0x20000;
            this->requested_action = 6;
            this->state = 1;
        } else {
            this->run_idle_action();
        }
        break;
    case 1:
        if (this->target == NULL) {
            this->reset_enemy_state();
        } else {
            this->velocity.y = 0.0f;
            calc_velocity_toward_destination(this, this->body_center, ((TObjChara *)this->target)->body_center, 0.7f);
            {
                Vec n1 = this->body_center;
                n1.x += this->velocity.x;
                n1.z += this->velocity.z;
                if (check_path_obstructed(this, &n1) == 0) {
                    move_with_wall_slide(this);
                }
            }
            this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
            this->target_distance_sq = xz_distance_squared(&this->body_center, &((TObjChara *)this->target)->body_center);
            if (this->target_distance_sq <= this->attack_params->get_attack_range() * this->attack_params->get_attack_range()) {
                this->requested_action = 7;
                this->state = 2;
                this->effects[2] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->body_center, this->attack_effect_angle, 0x12B, 2);
                this->effects[2]->enable();
                this->effects[3] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->body_center, this->attack_effect_angle, 0x12C, 2);
                this->effects[3]->enable();
            }
        }
        break;
    case 2:
        push_matrix_from(identity_matrix);
        post_translate_matrix(&this->body_center.x);
        rotate_matrix_y(0, this->rotation_y);
        this->calc_joint_matrices(this->frame);
        pop_matrix();
        this->get_anim_node_position(8, &this->attack_effect_position);
        this->attack_effect_angle[0] = 0;
        this->attack_effect_angle[1] = this->rotation_y + 0x4000;
        this->attack_effect_angle[2] = -0x4000;
        if (this->frame >= 9.0f && this->frame < 17.0f) {
            this->effects[2]->set_position(&this->attack_effect_position);
            this->effects[2]->set_direction(this->attack_effect_angle);
        } else {
            this->effects[2]->enable();
        }
        if (this->frame >= 12.0f && this->frame < 17.0f) {
            this->effects[3]->set_position(&this->attack_effect_position);
            this->effects[3]->set_direction(this->attack_effect_angle);
        } else {
            this->effects[3]->enable();
        }
        this->velocity.y = 0.0f;
        calc_velocity_toward_destination(this, this->body_center, ((TObjChara *)this->target)->body_center, 0.7f);
        {
            Vec n2 = this->body_center;
            n2.x += this->velocity.x;
            n2.z += this->velocity.z;
            if (check_path_obstructed(this, &n2) == 0) {
                move_with_wall_slide(this);
            }
        }
        this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
        if (this->is_passing_frame(10.0f) != 0) {
            play_sound_effect(0x4003B034, &this->position, 0, 0);
            if (((TObjChara *)this->target)->select_melee_contact_body(this, 1.0f) != 0) {
                ((TObjChara *)this->target)->receive_physical_attack(this, 1.0f);
                ((TObjChara *)this->target)->apply_knockback_from_attacker(this, 3.0f);
                if (!(((TObjChara *)this->target)->actorFlags & 0x800) && ((TObjChara *)(this->target))->get_actor_hp() > 0) {
                    send_6x2F_change_player_hp(this->entity_id, this->targetId, 1);
                }
            }
        }
        if (this->action_flags != 4) {
            this->set_actor_flags(0x800);
        }
        break;
    case -1:
        if (this->effects[2] != NULL) {
            this->effects[2]->queue_destruction();
            this->effects[2] = NULL;
        }
        if (this->effects[3] != NULL) {
            this->effects[3]->queue_destruction();
            this->effects[3] = NULL;
        }
        this->behavior_flags |= 0x20000;
        break;
    }
    this->advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    this->check_object_collisions();
    check_enemy_body_collisions(this);
}

void TObjEneBalClawBody::update_combined_attack() {
    switch (this->state) {
    case 0:
        if (this->is_form_1() == 0) {
            this->reset_enemy_state();
            return;
        }
        this->find_target_in_range(250.0f);
        if (this->targetId != 0xFFFF) {
            this->requested_action = 1;
            this->state = 1;
            if (select_enemy_destination(this, this->body_center, 1) != 0) {
                copy_position_if_valid(this, this->body_center);
            }
        } else {
            this->reset_enemy_state();
        }
        break;
    case 1:
        if (this->target == NULL) {
            this->reset_enemy_state();
        } else {
            this->velocity.y = 0.0f;
            calc_velocity_toward_destination(this, this->body_center, ((TObjChara *)this->target)->body_center, 0.7f);
            {
                Vec n1 = this->body_center;
                n1.x += this->velocity.x;
                n1.z += this->velocity.z;
                if (check_path_obstructed(this, &n1) == 0) {
                    move_with_wall_slide(this);
                }
            }
            this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
            this->target_distance_sq = xz_distance_squared(&this->body_center, &((TObjChara *)this->target)->body_center);
            if (this->target_distance_sq <= this->attack_params->get_attack_range() * this->attack_params->get_attack_range()) {
                this->requested_action = 2;
                this->state = 2;
                play_sound_effect(0x4003B033, &this->position, 0, 0);
            }
        }
        break;
    case 2:
        if (this->target == NULL) {
            this->reset_enemy_state();
        } else {
            this->velocity.y = 0.0f;
            calc_velocity_toward_destination(this, this->body_center, ((TObjChara *)this->target)->body_center, 0.7f);
            move_with_wall_slide(this);
            {
                Vec n2 = this->body_center;
                n2.x += this->velocity.x;
                n2.z += this->velocity.z;
                if (check_path_obstructed(this, &n2) == 0) {
                    move_with_wall_slide(this);
                }
            }
            if (this->is_passing_frame(10.0f) != 0) {
                if (((TObjChara *)this->target)->select_melee_contact_body(this, 1.0f) != 0) {
                    if (this->random_ratio() <= 0.1f) {
                        DirectAttackPayload q = {0xF, 0.0f};
                        ((TObjChara *)this->target)->receive_direct_attack(this, q, 0, -1, -1);
                    }
                    ((TObjChara *)this->target)->receive_physical_attack(this, 1.0f);
                    ((TObjChara *)this->target)->apply_knockback_from_attacker(this, 3.0f);
                }
                this->melee_hit_count++;
            }
            if (this->action_flags != 4) {
                this->reset_enemy_state();
            }
        }
        break;
    case -1:
        break;
    }
    this->advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    this->update_collisions();
}

// Shows the arm models of the first count claw slots and hides the rest.
void TObjEneBalClawBody::show_claw_arms(s32 count) {
    s32 i;
    s32 j;
    NJS_OBJECT *e;
    for (i = 0; i < count; i++) {
        for (j = 0; (e = balclaw_arm_part_models[i][j]) != NULL; j++) {
            e->evalflags &= ~NJD_EVAL_HIDE;
        }
    }
    for (; i < 4; i++) {
        for (j = 0; (e = balclaw_arm_part_models[i][j]) != NULL; j++) {
            e->evalflags |= NJD_EVAL_HIDE;
        }
    }
}

void TObjEneBalClawBody::update_appear() {
    s32 cleared;
    s32 flags;
    switch (this->state) {
    case 0:
        this->behavior_flags |= 4;
        this->actorFlags |= 0x04000000;
        this->requested_action = (this->behavior_flags & 0x01000000) ? 0 : 5;
        play_area_se_with_particle(&this->position);
        this->fade.start_fade_in();
        this->state = 1;
    case 1:
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if ((&this->fade)->advance_toward_max() == 1) {
            flags = this->behavior_flags;
            cleared = flags & ~5;
            this->behavior_flags = cleared;
            this->state = -1;
            this->reset_enemy_state();
        }
        return;
    case -1:
        this->behavior_flags &= ~5;
        this->actorFlags &= 0xFBFFFFFF;
        break;
    }
}

void TObjEneBalClawBody::update_wait() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        requested_action = (behavior_flags & 0x01000000) ? 0 : 5;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case -1:
        actorFlags &= ~0x40000;
        return;
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneBalClawBody::set_form(s32 form) {
    Vec a;
    Vec b;
    s32 angA;
    s32 angB;
    s32 i;
    s32 id;
    saddr id2;
    s32 n;
    s32 k;
    TObjChara *ent;
    s32 j;
    if (form == 1) {
        this->behavior_flags |= 0x01000000;
        this->set_param(0x28);
        this->requested_action = 0;
        this->set_model(1);
        this->melee_hit_count = 0;
        this->clear_all_status_effects();
    } else {
        this->behavior_flags &= ~0x01000000;
        this->set_param(0x27);
        this->requested_action = 5;
        this->set_model(0);
        this->clear_all_status_effects();
        if (!(this->behavior_flags & 0x40000)) {
            this->hp = this->hp / (this->child_count + 1);
            if (this->hp <= 0) {
                this->hp = 1;
            }
            this->referenceHp = this->hp;
            if (this->set_entry != NULL) {
                this->behavior_flags |= 0x40000;
                for (i = 0; i < 4; i++) {
                    id = this->entity_id + i;
                    id2 = this->set_index + i;
                    id++;
                    id2++;
                    this->calc_slot_offset_position(i, &a, &angA);
                    TObjEneBalClawClaw::create_from_body(this, id, id2, &a, angA, this->hp);
                }
            }
        } else {
            n = 0;
            for (k = 0; k < this->child_count; k++) {
                ent = get_enemy_entity(this->child_ids[k]);
                if (ent != NULL) {
                    this->calc_slot_offset_position(k, &b, &angB);
                    ((TObjEneBalClawClaw *)ent)->detach_at(&b, angB, this->hp);
                    n++;
                }
            }
            if (n > 0) {
                this->hp = this->hp / (n + 1);
                for (j = 0; j < this->child_count; j++) {
                    if ((ent = get_enemy_entity(this->child_ids[j])) != NULL) {
                        ((TObjPlayer *)ent)->set_hp_clamped(this->hp);
                    }
                }
            }
        }
        this->child_count = 0;
    }
    this->set_requested_action(this->requested_action);
    this->movementParameters = &balclaw_body_movement[form];
    this->load_params();
    this->variant = form;
    this->form_timer = 0;
}
#pragma pop

void TObjEneBalClawBody::render() {
    s32 shadow;
    s32 detail;
    s32 visible;

    if (!(actorFlags & 0x02000000)) {
        saved_model_render_flags = model_render_flags;
        detail = classify_actor_view_detail(150.0f, 400.0f, 30.0f);
        if (detail != 0) {
            shadow = 1;
            set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texlist));
            select_actor_lighting(this);
            toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                show_claw_arms(4);
                post_translate_matrix(&position.x);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                draw_chunk_object(model);
            } else {
                show_claw_arms(child_count);
                translate_matrix(0, 0.0f, hover_height + wobble_offset, 0.0f);
                post_translate_matrix(&position.x);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                if (behavior_flags & 4) {
                    if ((&fade)->has_visible_opacity() != 0) {
                        (&fade)->set_flags_and_apply_damage_color();
                        visible = 1;
                        if (defer_render() != 0) {
                            visible = 0;
                        }
                        if (visible != 0) {
                            if (detail == 1) {
                                draw();
                            } else {
                                draw_motion_model();
                            }
                        }
                        (&fade)->clear_flag_and_notify();
                    } else {
                        shadow = 0;
                    }
                } else if (detail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            model_render_flags = saved_model_render_flags;
            render_scaled(shadow);
        }
    }
}

void TObjEneBalClawBody::run_attack_action() {
    update_if_active(is_form_1() ? 9 : 2);
}

void TObjEneBalClawBody::update_combine() {
    s32 all;
    s32 cnt;
    TObjEneBalClawClaw *claw;
    f32 lim;
    switch (this->state) {
    case 0:
        if (this->is_form_1() != 0) {
            this->reset_enemy_state();
            return;
        }
        this->form_timer = 0;
        if (this->summon_claws() == 0) {
            this->reset_enemy_state();
            return;
        }
        this->behavior_flags |= 1;
        this->behavior_flags &= ~0x04020000;
        this->state_timer = 0x258;
        this->state = 1;
        this->requested_action = 5;
        this->effects[0] = create_particle_emitter(&this->body_center, 0x128);
        break;
    case 1:
        this->effects[0]->set_position(&this->body_center);
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        all = 1;
        cnt = 0;
        lim = 225.0f;
        for (s32 i = 0; i < this->child_count; i++) {
            claw = (TObjEneBalClawClaw *)find_entity_by_id(this->child_ids[i]);
            if (claw != NULL) {
                cnt++;
                if (claw->target_distance_sq > lim) {
                    all = 0;
                }
            } else {
                this->child_ids[i] = 0xFFFF;
            }
        }
        if (--this->state_timer <= 0 || cnt == 0) {
            this->behavior_flags &= ~1;
            this->reset_enemy_state();
            return;
        }
        if (all == 1) {
            for (s32 i = 0; i < this->child_count; i++) {
                TObjEneBalClawClaw *claw2 = (TObjEneBalClawClaw *)find_entity_by_id(this->child_ids[i]);
                if (claw2 != NULL) {
                    claw2->attach();
                    this->hp += ((TObjChara *)claw2)->get_actor_hp();
                }
            }
            this->effects[1] = create_particle_emitter(&this->body_center, 0x12A);
            this->effects[1]->enable();
            this->requested_action = 0xB;
            this->behavior_flags |= 0x04000000;
            this->state = 2;
        }
        break;
    case 2:
        this->effects[0]->set_position(&this->body_center);
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (this->frame < 9.0f) {
            this->effects[1]->enable();
        } else {
            this->effects[1]->clear_active_flag();
            this->effects[1]->set_position(&this->body_center);
        }
        if (this->requested_action != 0xB) {
            this->effects[0]->queue_destruction();
            this->effects[0] = NULL;
            spawn_particle_effect(&this->body_center, 0x129);
            this->set_form(1);
            this->advance_animation();
            this->behavior_flags &= ~0x04000000;
            this->timer = 0x1E;
            this->state = 3;
            play_sound_effect(0x4003AD30, &this->position, 0, 0);
        }
        break;
    case 3:
        this->effects[1]->set_position(&this->body_center);
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (--this->timer <= 0) {
            this->behavior_flags &= ~1;
            this->reset_enemy_state();
        }
        break;
    case -1:
        if (this->behavior_flags & 0x04000000) {
            this->set_form(1);
            this->advance_animation();
        }
        if (this->is_form_1() == 0) {
            for (s32 i = 0; i < this->child_count; i++) {
                claw = (TObjEneBalClawClaw *)find_entity_by_id(this->child_ids[i]);
                if (claw != NULL) {
                    claw->clear_flag();
                }
            }
        }
        this->behavior_flags |= 0x20000;
        if (this->effects[0] != NULL) {
            this->effects[0]->queue_destruction();
            this->effects[0] = NULL;
        }
        if (this->effects[1] != NULL) {
            this->effects[1]->queue_destruction();
            this->effects[1] = NULL;
        }
        break;
    }
}

void TObjEneBalClawBody::update_split() {
    switch (this->state) {
    case -1:
        break;
    case 0:
        if (this->is_form_1() == 0) {
            this->reset_enemy_state();
            return;
        }
        this->form_timer = 0;
        this->set_form(0);
        this->timer = 0x1E;
        this->state = 1;
        return;
    case 1:
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        this->timer--;
        if (this->timer <= 0) {
            this->reset_enemy_state();
        }
        return;
    }
}

void TObjEneBalClawBody::calc_slot_offset_position(s32 slot, Vec *out, s32 *angle_out) {
    s32 angle;
    push_matrix();
    angle = (s32)(182.04445f * (f32)(slot * 0x5A + 0x2D));
    *angle_out = this->rotation_y + angle;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 13.0f;
    set_matrix_identity(0);
    rotate_matrix_y(0, angle);
    matrix_mult_vec(0, out, out);
    vec3_add_to(out, &this->position);
    pop_matrix();
}

s32 TObjEneBalClawBody::summon_claws() {
    s32 i;
    TObjEneBalClawClaw *p;
    s32 j;
    this->child_count = 0;
    for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
        p = (TObjEneBalClawClaw *)TObjPlayer::get_player_data(i);
        if (p != NULL && p->get_rt_index() == 0x26 &&
            this->room == p->room && p->check_active() != 0) {
            this->child_ids[this->child_count++] = p->get_entity_id();
            if (this->child_count >= 4) {
                break;
            }
        }
    }
    for (j = 0; j < this->child_count; j++) {
        TObjEneBalClawClaw *claw = static_cast<TObjEneBalClawClaw *>(find_entity_by_id(this->child_ids[j]));
        claw->join_body(this->entity_id);
    }
    return this->child_count;
}

void TObjEneBalClawBody::update_retreat() {
    switch (this->state) {
    case -1:
        break;
    case 0: {
        this->actorFlags &= ~0x100;
        this->requested_action = this->is_form_1() != 0 ? 1 : 6;
        Vec d = this->body_center;
        subtract_vector(&d, &((TObjChara *)this->target)->body_center);
        this->pick_open_direction((f32 *)&d, 60.0f, 30.0f);
        this->state = 1;
        break;
    }
    case 1: {
        if (this->target == NULL) {
            reset_enemy_state();
            break;
        }
        if (this->is_actor_cadence_frame(0x5A) != 0) {
            Vec d2 = this->body_center;
            subtract_vector(&d2, &((TObjChara *)this->target)->body_center);
            this->pick_open_direction((f32 *)&d2, 60.0f, 30.0f);
        }
        VecCopy(&this->move_origin, &this->body_center);
        calc_velocity_toward_destination(this, this->move_origin, this->move_destination, ((EnemyMoveParams *)this->movementParameters)->min_distance);
        this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
        Vec v = this->body_center;
        v.x += this->velocity.x;
        v.z += this->velocity.z;
        if (check_path_obstructed(this, &v) == 0) {
            move_with_wall_slide(this);
        }
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        this->update_collisions();
        break;
    }
    }
}

void TObjEneBalClawBody::update_return_home() {
    s16 mode;
    switch (this->state) {
    case 0:
        this->actorFlags &= 0xFFFBFEFF;
        mode = 6;
        if (this->behavior_flags & 0x01000000) {
            mode = 1;
        }
        this->requested_action = mode;
        this->state = 1;
        VecCopy(&this->move_destination, (const Vec *)&this->home_position);
        break;
    case 1: {
        this->velocity.y = 0.0f;
        VecCopy(&this->move_origin, &this->body_center);
        calc_velocity_toward_destination(this, this->move_origin, this->move_destination, ((EnemyMoveParams *)this->movementParameters)->min_distance);
        this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed, &this->velocity);
        Vec v = this->body_center;
        v.x += this->velocity.x;
        v.z += this->velocity.z;
        if (check_path_obstructed(this, &v) == 0) {
            move_with_wall_slide(this);
        }
        if (xz_distance_squared(&this->position, &this->home_position) < 100.0f) {
            this->reset_enemy_state();
        }
        this->advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawBody::reset_enemy_state() {
    update_if_active(0);
}

void TObjEneBalClawBody::run_idle_action() {
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        update_if_active(8);
        return;
    }
    update_if_active(0);
}

void TObjEneBalClawBody::load_params() {
}

// Registers the combined body's model (bcbody) and action table with the NPC model registry.
void TObjEneBalClawBody::load_resources() {
    NpcAnimationBinding params = { balclaw_bml_resource->motions, balclaw_body_actions, 0, 1, 12 };
    TObjNpcEnemy::register_animated_chunk(0x13, balclaw_bml_resource->models[1].model, balclaw_bml_resource->models[1].texlist, &params,
                            balclaw_body_collision.radius, 15.0f);
}

void TObjEneBalClawBody::free_resources() {
}
