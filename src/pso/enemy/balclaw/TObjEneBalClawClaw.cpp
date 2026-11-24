#include "pso/enemy/EnemyPlacement.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawBody.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjControl.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"


TObjMotionAction balclaw_claw_actions[7] = {
    {1, 0, 0xF, 1.0f, 0},
    {1, 0, 0xF, 1.0f, 1},
    {2, 0, 0xA, 0.8f, 4},
    {2, 0, 0xB, 0.7f, 8},
    {3, 0, 0xC, 0.5f, 0x10},
    {1, 0, 0xD, 0.7f, 1},
    {1, 0, 0xE, 0.7f, 1},
};
BalClawMovement balclaw_claw_movement = {{150.0f, 0.5555555f, 0x400}, 30, 0, 0, 1, 0};
CollisionBody TObjEneBalClawClaw__collision_body_template = {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

player_stats *balclaw_claw_base_params[1];
AttackParams *balclaw_claw_attack_params[1];
ActorParamBlock *balclaw_claw_resistance_params[1];
BalClawBehaviorParams *balclaw_claw_behavior_params[1];

const char *balclaw_claw_class_name = "TObjEneBalClawClaw";

TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, EnemyPlacement *set_data) : TObjEneBalClaw(parent) {
    apply_set_data(set_data);
    init();
    if (set_data->wave != 0) {
        start_appear();
    }
}

// Spawned by the body (TObjEneBalClawClaw::create_from_body): takes the body's room, group, home and wobble state.
TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, TObjEneBalClawBody *body, u16 id, s32 index, const Vec *pos,
                                       s32 rot_y, s32)
    : TObjEneBalClaw(parent) {
    entity_id = id;
    set_index = index;
    room = body->room;
    set_group = body->set_group;
    VecCopy(&position, pos);
    VecCopy(&home_position, &body->home_position);
    rotation_z = 0;
    rotation_x = 0;
    rotation_y = rot_y;
    init();
    set_entry = NULL;
    wobble_angle = body->wobble_angle;
    wobble_offset = body->wobble_offset;
    hover_height = body->hover_height;
    detach();
}

void TObjEneBalClawClaw::init() {
    this->m_name = balclaw_claw_class_name;
    this->motion_list = balclaw_bml_resource->motions;
    this->action_table = balclaw_claw_actions;
    this->set_action_table(this->action_table);
    init_collision_body_parts(this, &TObjEneBalClawClaw__collision_body_template, 1);
    this->variant = 0;
    this->movementParameters = &balclaw_claw_movement;
    this->bind_enemy_combat_stats(balclaw_claw_base_params[0], balclaw_claw_attack_params[0], balclaw_claw_resistance_params[0]);
    this->load_params();
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    this->hp = this->hpmax;
    this->tp = this->tpmax;
    this->referenceHp = this->hp;
    this->set_param(0x26);
    VecCopy(&this->body_center, &this->position);
    this->body_center.y += 5.0f;
    register_by_id();
    this->set_model(2);
    this->wobble_angle = 0;
    this->wobble_offset = 0.0f;
    this->hover_height_min = 15.0f;
    this->hover_height_max = 40.0f;
    this->hover_height = this->hover_height_min;
    this->clear_attack_flag();
    VecCopy(&this->move_origin, (const Vec *)VecCopy(&this->move_destination, &this->position));
    this->clear_lobby_object_state();
}

TObjEneBalClawClaw::~TObjEneBalClawClaw() {
    free_collision_body_parts(this);
}

void *TObjEneBalClawClaw::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneBalClawClaw(control, static_cast<EnemyPlacement *>(set_data));
}

TObjEneBalClawClaw *TObjEneBalClawClaw::create_from_body(TObjEneBalClawBody *body, u16 id, s32 index, const Vec *pos, s32 rot_y, s32 hp) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneBalClawClaw(control, body, id, index, pos, rot_y, hp);
}

void TObjEneBalClawClaw::run_task() {
    u32 flags;
    TObjBase *parent;
    scroll_part_uvs();
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        run_demo_task();
        return;
    }
    flags = behavior_flags;
    if (flags & 0x20000000) {
        update_if_active(0xA);
    } else if (flags & 0x10000000) {
        update_if_active(9);
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
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    release_destroyed_target();
    update_state();
    flags = behavior_flags;
    if (!(flags & 0x10000000)) {
        if (flags & 0x20000000) {
            wobble_offset = (0.2f + wobble_offset < 10.0f) ? 0.2f + wobble_offset : 10.0f;
        } else {
            update_wobble();
        }
        update_claw_angle();
        VecCopy(&body_center, &position);
        body_center.y += hover_height + wobble_offset;
        bodies->offset.y = hover_height + wobble_offset;
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
        return;
    }
    parent = (TObjBase *)find_entity_by_id(body_id);
    if (parent != NULL) {
        VecCopy(&position, &parent->position);
    }
}

void TObjEneBalClawClaw::update_state() {
    switch (mode) {
    case 0:
        update_wait();
        return;
    case 1:
        update_chase();
        return;
    case 2:
        update_attack();
        return;
    case 4:
        update_damage();
        return;
    case 5:
        run_death_sequence();
        return;
    case 7:
        update_appear();
        return;
    case 9:
        update_drop();
        return;
    case 10:
        update_follow_parent();
        return;
    case 11:
        run_active_state();
        return;
    case 8:
        update_return_home();
        return;
    case 12:
        update_retreat();
        break;
    }
}

void TObjEneBalClawClaw::update_attack_distance_state() {
    f32 dist;
    s32 next;
    s32 prev;
    TObjChara *chased;

    if (is_actor_cadence_frame(0x1E) != 0) {
        find_target_in_range(250.0f);
    }
    switch (mode) {
    case 8:
    case 0:
        if (is_actor_cadence_frame(0x1E) != 0) {
            if (target != NULL) {
                update_if_active(1);
                range_band = 2;
                return;
            }
            if (xz_distance_squared(&position, &home_position) > 100.0f) {
                update_if_active(8);
                return;
            }
            reset_active_state();
        }
        return;
    case 1:
        chased = target;
        if (chased != NULL) {
            dist = xz_distance_squared(&chased->position, &position);
            prev = range_band;
            switch (prev) {
            case 0:
                if (dist > 1600.0f) {
                    range_band = 1;
                }
                break;
            case 1:
                if (dist < 400.0f) {
                    clear_attack_flag();
                    range_band = 0;
                } else if (dist > 10000.0f) {
                    range_band = 2;
                }
                break;
            case 2:
                if (dist < 6400.0f) {
                    set_attack_distance_flag();
                    range_band = 1;
                }
                break;
            }
            next = range_band;
            if (prev != next) {
                switch (next) {
                case 0:
                    update_if_active(2);
                    return;
                case 1:
                    clear_attack_flag();
                    return;
                case 2:
                    set_attack_distance_flag();
                    return;
                }
            }
        } else {
            update_if_active(8);
        }
        break;
    }
}

void TObjEneBalClawClaw::run_demo_task() {
}

void TObjEneBalClawClaw::update_chase() {
    switch (state) {
    case 0:
        find_target_in_range(250.0f);
        if (targetId != 0xFFFF) {
            actorFlags &= 0xFBFFFEFF;
            clear_flags_30();
            state = requested_action = 1;
        } else {
            reset_active_state();
        }
        target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
        if (target != NULL) {
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
        }
        break;
    case 1: {
        if (target == NULL) {
            reset_active_state();
            break;
        }
        play_persistent_sound(0x4003B235, this, &position, 0, 0);
        update_enemy_wander_move(this, ((TObjChara *)target)->body_center, 1, ((EnemyMoveParams *)movementParameters)->min_distance);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawClaw::update_damage() {
    switch (state) {
    case 0:
        actorFlags &= ~0x200000;
        requested_action = 3;
        state = 1;
    case 1: {
        advance_animation();
        Vec next = body_center;
        next.x += velocity.x;
        next.z += velocity.z;
        if (check_path_obstructed(this, &next) == 0) {
            move_with_wall_slide(this);
        } else {
            velocity.x = velocity.z = 0.0f;
        }
        velocity.x *= 0.9f;
        velocity.z *= 0.9f;
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        play_persistent_sound(0x4003B235, this, &position, 0, 0);
        if (action_flags != 8) {
            actorFlags &= ~0x200;
            behavior_flags &= ~1;
            referenceHp = hp;
            reset_active_state();
        }
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawClaw::run_death_sequence() {
    switch (state) {
    case 0:
        refresh_lobby_state();
        requested_action = 4;
        fade.start_fade_out();
        fn_800D911C(&body_center);
        play_sound_effect(0x4003AD37, &position, 0, 0);
        state = 1;
    case 1:
        advance_animation();
        if (fade.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a(&position, 0);
            send_entity_set_flags();
            queue_destruction();
        }
        break;
    case -1:
        return;
    }
}

void TObjEneBalClawClaw::update_attack() {
    switch (state) {
    case -1:
        break;
    case 0:
        if (target == NULL) {
            reset_active_state();
            return;
        }
        clear_attack_flag();
        behavior_flags &= ~8;
        state = requested_action = 1;
        break;
    case 1: {
        if (target == NULL) {
            reset_active_state();
            return;
        }
        update_enemy_wander_move(this, ((TObjChara *)target)->body_center, 1, 0.7f);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        if (target_distance_sq <= attack_params->get_attack_range() * attack_params->get_attack_range()) {
            state = requested_action = 2;
        }
        break;
    }
    case 2: {
        if (target == NULL) {
            reset_active_state();
            return;
        }
        update_enemy_wander_move(this, ((TObjChara *)target)->body_center, 1, 0.7f);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        if (is_passing_frame(8.0f) != 0) {
            play_sound_effect(0x4003B032, &position, 0, 0);
            if (((TObjChara *)target)->select_melee_contact_body(this, 1.0f) != 0) {
                ((TObjChara *)target)->apply_knockback_from_attacker((u8 *)this, 3.0f);
                ((TObjChara *)target)->receive_physical_attack(this, 1.0f);
                behavior_flags |= 8;
            }
        }
        if (action_flags != 4) {
            timer = 0x5A;
            update_if_active(0xC);
        }
        break;
    }
    case 3:
        timer = timer - 1;
        if (timer <= 0) {
            reset_active_state();
        }
        break;
    }
    advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
}

void TObjEneBalClawClaw::update_appear() {
    s32 flags;
    s32 cleared;
    s32 old;

    switch (state) {
    case 0:
        behavior_flags |= 4;
        flags = actorFlags | 0x04000000;
        actorFlags = flags;
        requested_action = 0;
        play_area_se_with_particle(&position);
        fade.start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (fade.advance_toward_max() == 1) {
            old = behavior_flags;
            cleared = old & ~5;
            behavior_flags = cleared;
            state = -1;
            reset_active_state();
        }
        return;
    case -1:
        behavior_flags &= ~5;
        actorFlags &= 0xFBFFFFFF;
        break;
    }
}

void TObjEneBalClawClaw::update_wait() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        requested_action = 0;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case -1:
        actorFlags &= 0xFFFBFFFF;
        return;
    }
}

void TObjEneBalClawClaw::render() {
    s32 shadow;
    s32 detail;
    s32 visible;

    if (!(actorFlags & 0x02000000)) {
        detail = classify_actor_view_detail(120.0f, 400.0f, 10.0f);
        if (detail != 0) {
            shadow = 1;
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                post_translate_matrix(&position.x);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                draw_chunk_object(model);
            } else {
                translate_matrix(0, 0.0f, hover_height + wobble_offset, 0.0f);
                post_translate_matrix(&position.x);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                if (behavior_flags & 4) {
                    if (fade.has_visible_opacity() != 0) {
                        fade.set_flags_and_apply_damage_color();
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
                        fade.clear_flag_and_notify();
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
            render_scaled(shadow);
        }
    }
}

void TObjEneBalClawClaw::update_follow_parent() {
    TObjBase *parent = (TObjBase *)get_enemy_entity(body_id);
    if (parent == NULL || (parent->actorFlags & 0x800)) {
        clear_flag();
        return;
    }
    switch (state) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        clear_attack_flag();
        state = 1;
    case 1: {
        select_enemy_destination(this, parent->position, 1);
        target_distance_sq = update_enemy_wander_move(this, parent->position, 1, ((EnemyMoveParams *)movementParameters)->min_distance);
        enemy_turn_half_toward_dest(this);
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        break;
    }
    }
}

void TObjEneBalClawClaw::detach_at(Vec *pos, s32 rot_y, s16 hp) {
    VecCopy(&position, pos);
    rotation_y = rot_y;
    referenceHp = hp;
    this->hp = hp;
    detach();
    clear_all_status_effects();
}

s32 TObjEneBalClawClaw::check_active() {
    if (actorFlags & 0xA00) {
        return 0;
    }
    return (u32)__cntlzw(behavior_flags & 0x10000000) >> 5;
}

void TObjEneBalClawClaw::join_body(u16 body_id) {
    this->body_id = body_id;
    targetId = body_id;
    behavior_flags |= 0x20000000;
    actorFlags &= 0xFFFBFFFF;
    target_distance_sq = 100000.0f;
    update_if_active(0xA);
    clear_all_status_effects();
}

void TObjEneBalClawClaw::clear_flag() {
    behavior_flags &= 0xDFFFFFFF;
    reset_active_state();
}

void TObjEneBalClawClaw::update_return_home() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x100;
        requested_action = 1;
        VecCopy(&move_destination, &home_position);
        state = 1;
    case 1:
        velocity.y = 0.0f;
        VecCopy(&move_origin, &body_center);
        calc_velocity_toward_destination(this, move_origin, move_destination,
                                         ((EnemyMoveParams *)movementParameters)->min_distance);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        move_with_wall_slide(this);
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    }
}

void TObjEneBalClawClaw::reset_active_state() {
    update_if_active(0);
}

void TObjEneBalClawClaw::run_idle_action() {
}

void TObjEneBalClawClaw::load_params() {
}

void TObjEneBalClawClaw::attach() {
    set_actor_flags(0x04040000);
    behavior_flags &= 0xDFFFFFFF;
    behavior_flags |= 0x10000000;
}

void TObjEneBalClawClaw::detach() {
    behavior_flags &= 0xEFFFFFFF;
    clear_actor_flags(0x06040000);
    next_action = 0xB;
}

void TObjEneBalClawClaw::update_drop() {
    switch (state) {
    case -1:
        break;
    case 0:
        requested_action = 0;
        fade.reset_color();
        behavior_flags |= 4;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (fade.decay_value_toward_floor() == 1) {
            behavior_flags &= ~4;
            set_actor_flags(0x02000000);
            state = 2;
        }
        break;
    case 2:
        break;
    }
}

void TObjEneBalClawClaw::run_active_state() {
    switch (state) {
    case 0:
        fade.reset_obstruction_fade();
        behavior_flags |= 5;
        state = 1;
    case 1:
        if (fade.advance_toward_max() == 1) {
            behavior_flags &= ~5;
            reset_active_state();
        }
        return;
    case -1:
        behavior_flags &= ~4;
        break;
    }
}

void TObjEneBalClawClaw::update_retreat() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x100;
        requested_action = 1;
        state = 1;
        retreat_timer = 0x78;
        break;
    case 1:
        if (target == NULL || --retreat_timer <= 0) {
            update_if_active(0);
            break;
        }
        velocity.y = 0.0f;
        move_along_ground_avoiding_walls(((TObjChara *)target)->body_center, -0.6f, bodies->radius);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        break;
    }
}

// Registers the claw model (claw_body) and action table with the NPC model registry.
void TObjEneBalClawClaw::load_resources() {
    NpcAnimationBinding binding = { balclaw_bml_resource->motions, balclaw_claw_actions, 0, 1, 7 };
    BmlModelEntry *models;
    models = balclaw_bml_resource->models;
    TObjNpcEnemy::register_animated_chunk(0x14, models[2].model, models[2].texlist, &binding,
                            TObjEneBalClawClaw__collision_body_template.radius, 15.0f);
}

void TObjEneBalClawClaw::free_resources() {
}
