#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyMovement.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/player/PlayerAttackParams.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/flower/TObjEneRe2Flower_EffCurse3.h"

#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"


#include "pso/object/base/TObjChara.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/ScratchVectors.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


extern const Vec beast_zero_vector = { 0.0f, 0.0f, 0.0f };

#define BEAST_HUNTER_NEAR_EXIT_DISTANCE_SQ 10000.0f
#define BEAST_HUNTER_NEAR_ENTER_DISTANCE_SQ 2500.0f
#define BEAST_OTHER_NEAR_EXIT_DISTANCE_SQ 22500.0f
#define BEAST_OTHER_NEAR_ENTER_DISTANCE_SQ 10000.0f
#define BEAST_DEATH_EFFECT_FRAME 16.0f
#define BEAST_DEATH_SLIDE_FRAME_COUNT 30.0f
#define BEAST_ATTACK_HIT_FRAME 7.0f
#define BEAST_ATTACK_KNOCKBACK 3.0f
#define BEAST_HOME_CHASE_FRAME_COUNT 60.0f
#define BEAST_ANGLE_UNITS_PER_RADIAN 10430.38043493439
#define BEAST_DEATH_SLIDE_FRAME_SCALE 0.5f
#define BEAST_HORIZONTAL_SPEED_DAMPING 0.5f
#define BEAST_ATTACK_CHOICE_THRESHOLD 0.5f
#define BEAST_TARGET_HOLD_BASE_FRAMES 150.0f
#define BEAST_DESTINATION_TIMEOUT_FRAMES 150.0f
#define BEAST_GROUP_APPROACH_DISTANCE_SQ 22500.0f
#define BEAST_ANIMATION_START_FRAME 0.0f
#define BEAST_GROUND_HEIGHT_OFFSET 0.0f
#define BEAST_TARGET_HOLD_BASE_SCALE 1.0f
#define BEAST_ATTACK_SCALE 1.0f
#define BEAST_FRAME_INCREMENT 1.0f
#define BEAST_ZERO_SPEED 0.0f
#define BEAST_MIN_WANDER_RANGE 0.0f
#define BEAST_CORPSE_RETIRE_START 0.0f
#define BEAST_CORPSE_RETIRE_STEP 0.1f
#define BEAST_CORPSE_RETIRE_THRESHOLD (-20.0f)
#define BEAST_DEFAULT_MOVEMENT_RATE 0.8f
#define BEAST_NEAR_TARGET_MOVEMENT_RATE 0.4f
#define BEAST_ZERO_VECTOR_COMPONENT 0.0f


// TObjPlayer member defined in TObjControl.cpp with no declaration in TObjPlayer.h.

void TUnk_80493450::select_move_speed() {
    if (test_actor_flags(0x100000) != 0) {
        move_speed = near_move_speed;
        play_speed = near_anim_speed;
        return;
    }
    move_speed = far_move_speed;
    play_speed = far_anim_speed;
}

void TUnk_80493450::update_target_near_flag() {
    TObjPlayer *player;
    f32 dist;

    if (target == NULL) {
        clear_actor_flags(0x100000);
        return;
    }
    if (((TObjBase *)target)->get_entity_id() < 0x1000 && is_actor_cadence_frame(0x1E) != 0) {
        player = (TObjPlayer *)target;
        dist = horizontal_distance_squared(&player->position, &position);
        switch (player->class_flags & CLASS_FLAG_TYPE_MASK) {
        case CLASS_FLAG_HUNTER:
            if (test_actor_flags(0x100000) != 0) {
                if (BEAST_HUNTER_NEAR_EXIT_DISTANCE_SQ < dist) {
                    clear_actor_flags(0x100000);
                }
            } else if (dist < BEAST_HUNTER_NEAR_ENTER_DISTANCE_SQ) {
                set_actor_flags(0x100000);
            }
            break;
        default:
            if (test_actor_flags(0x100000) != 0) {
                if (BEAST_OTHER_NEAR_EXIT_DISTANCE_SQ < dist) {
                    clear_actor_flags(0x100000);
                }
            } else if (dist < BEAST_OTHER_NEAR_ENTER_DISTANCE_SQ) {
                set_actor_flags(0x100000);
            }
            break;
        }
    } else {
        set_actor_flags(0x100000);
    }
}

void TUnk_80493450::beast_retire_corpse() { TObject::queue_destruction(); }
void TUnk_80493450::beast_update_dead() {
    advance_animation();
    if (is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
        play_death_sound();
    }
    if (is_passing_frame(BEAST_DEATH_EFFECT_FRAME) != 0) {
        spawn_particle_effect(&position, 0xF3);
        spawn_death_effect();
    }
    if (frame < (BEAST_DEATH_SLIDE_FRAME_SCALE * (BEAST_DEATH_SLIDE_FRAME_COUNT * play_speed))) {
        move_with_wall_slide(this);
        velocity.x *= BEAST_HORIZONTAL_SPEED_DAMPING;
        velocity.z *= BEAST_HORIZONTAL_SPEED_DAMPING;
    } else if (test_actor_flags(0x800000) == 0) {
        apply_actor_gravity(this, NULL, BEAST_GROUND_HEIGHT_OFFSET);
    }
    corpse_offset_y -= corpse_sink_speed;
    if (corpse_offset_y <= corpse_sink_limit) {
        beast_retire_corpse();
    }
}
void TUnk_80493450::run_death_reaction() {
    if (mode != 8) {
        mode = 8;
        requested_action = 8;
        unlink_enemy_group_relations();
        clear_player_status_flag(0, 1);
        refresh_lobby_state();
        send_entity_set_flags();
    }
}
void TUnk_80493450::beast_update_hurt() {
    Vec v;

    advance_animation();
    VecCopy(&v, &body_center);
    scratch_vec.x = scratch_vec.y = BEAST_ZERO_VECTOR_COMPONENT;
    scratch_vec.z = get_collision_body_radius(0);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, -rotation_y);
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&v, &scratch_vec);
    v.x += velocity.x;
    v.z += velocity.z;
    if (check_path_obstructed(this, &v) == 0) {
        move_with_wall_slide(this);
        velocity.x *= BEAST_HORIZONTAL_SPEED_DAMPING;
        velocity.z *= BEAST_HORIZONTAL_SPEED_DAMPING;
    } else {
        velocity.x = velocity.z = BEAST_ZERO_SPEED;
    }
    update_collisions();
    if (is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
        play_hurt_sound();
    }
    if (action_flags != 8) {
        clear_actor_flags(0x600);
        clear_player_status_flag(0, 0x04000000);
        if ((s32)subtype == 0) {
            if ((f32)hp < (f32)hpmax * parameters[0]) {
                clear_actor_flags(0x1000);
                retreat_timer = (s16)(BEAST_TARGET_HOLD_BASE_FRAMES * (BEAST_TARGET_HOLD_BASE_SCALE + parameters[0]));
            }
        }
        referenceHp = hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
void TUnk_80493450::run_hit_reaction() {
    if (mode != 7) {
        mode = 7;
        requested_action = 6;
    }
    clear_actor_flags(0x240000);
}
void TUnk_80493450::vfunc_89() {  }
void TUnk_80493450::run_miss_reaction() { clear_actor_flags(256); }

void TUnk_80493450::beast_update_attack() {
    if (targetId < 0x1000) {
        TObjPlayer *player = get_player_by_client_id(targetId);
        if (player != NULL && player->get_floor() == get_current_floor()) {
            target = player;
        } else {
            target = NULL;
        }
    } else if (targetId < 0x4000) {
        target = get_enemy_entity(targetId);
    } else {
        target = NULL;
    }
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
    case 1:
        if (is_passing_frame(BEAST_ATTACK_HIT_FRAME) != 0) {
            if (target != NULL && target->select_melee_contact_body(this, BEAST_ATTACK_SCALE) != 0) {
                target->receive_physical_attack(this, BEAST_ATTACK_SCALE);
                target->apply_knockback_from_attacker((u8 *)this, BEAST_ATTACK_KNOCKBACK);
            }
            play_attack_sound();
        }
        update_attack_trail();
        if (action_flags != 4) {
            phase = 2;
            requested_action = 0;
            timer = 0xF;
        }
        break;
    case 2:
        timer--;
        if (timer < 0) {
            clear_actor_flags(0x200000);
            timer = 0;
            select_post_attack_mode();
        }
        break;
    }
    apply_actor_gravity(this, 0, BEAST_GROUND_HEIGHT_OFFSET);
    enemy_turn_toward_dest(((BeastMovementParams *)movementParameters)->turnSpeed);
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TUnk_80493450::run_attack_action() {
    switch (mode) {
    case 0:
        break;
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 10;
        }
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    case 2:
        break;
    default:
        mode = 5;
        phase = 1;
        if (BEAST_ATTACK_CHOICE_THRESHOLD < random_ratio()) {
            requested_action = 3;
        } else {
            requested_action = 4;
        }
        set_actor_flags(0x200000);
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    }
}

s32 TUnk_80493450::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (mode) {
        case 0:
            appearing = 0;
            mode = 1;
            phase = 0;
            requested_action = 0;
            clear_actor_flags(0x04040000);
            clear_player_status_flag(0, 0x0A000000);
            break;
        }
        return 1;
    }
    return 0;
}

s32 TUnk_80493450::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (mode) {
        case 0:
            appearing = 0;
            mode = 1;
            phase = 0;
            requested_action = 0;
            clear_actor_flags(0x04040000);
            clear_player_status_flag(0, 0x0A000000);
            break;
        }
        return 1;
    }
    return 0;
}

void TUnk_80493450::beast_update_group_chase() {
    f32 d;
    f32 r;
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
        play_group_chase_sound();
        break;
    }
    if (target != NULL) {
        d = enemy_backstep_from_point(this, target->body_center, far_move_speed);
        turn_toward_direction(((BeastMovementParams *)movementParameters)->turnSpeed, &velocity);
        r = far_move_speed + bodies->radius;
        if (d < r * r) {
            mode = 3;
            phase = 0;
            clear_actor_flags(0x1000);
            retreat_timer = 0;
        }
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TUnk_80493450::beast_update_approach() {
    Vec dest;
    f32 r;
    switch (phase) {
    case 0:
        apply_actor_gravity(this, NULL, BEAST_GROUND_HEIGHT_OFFSET);
        advance_animation();
        if (is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
            play_alert_sound();
        }
        if (action_flags != 0x20) {
            phase = 1;
            requested_action = 2;
        }
        break;
    default:
        if (target != NULL) {
            if (test_elt_flag(0, 0x300000) != 0) {
                if (home_chase_frames++ < BEAST_HOME_CHASE_FRAME_COUNT) {
                    VecCopy(&dest, &home_position);
                } else {
                    VecCopy(&dest, &target->body_center);
                }
            } else {
                home_chase_frames = 0;
                VecCopy(&dest, &target->body_center);
            }
            update_target_near_flag();
            select_move_speed();
            advance_animation();
            enemy_move_toward(this, ((BeastMovementParams *)movementParameters)->turnSpeed, dest, 0, move_speed);
            if (targetId == 0xFFFF) {
                if (horizontal_distance_squared(&move_destination, &position) < (r = move_speed + bodies->radius) * r ||
                    BEAST_DESTINATION_TIMEOUT_FRAMES < (f32)(*(s32 *)&m_2ac)++) {
                    target = NULL;
                    m_2ac = 0;
                }
            }
        }
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x200000);
}

void TUnk_80493450::update_turn_toward_target() {
    s32 ang;
    advance_animation();
    switch (phase) {
    case 0:
        if (is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
            play_alert_sound();
        }
        if (action_flags != 0x20) {
            phase = 1;
            requested_action = 2;
        }
        break;
    case 1:
        if (target != NULL && is_actor_cadence_frame(0x1E) != 0) {
            Vec d;
            VecCopy(&d, &target->body_center);
            subtract_vector(&d, &body_center);
            ang = turn_toward_direction(((BeastMovementParams *)movementParameters)->turnSpeed, &d);
            if (d.x * d.x + d.z * d.z < BEAST_GROUP_APPROACH_DISTANCE_SQ || children == 0) {
                mode = 3;
                phase = 1;
                requested_action = 2;
            } else if (ang <= attack_params->get_attack_angle()) {
                phase = 2;
                requested_action = 0;
            }
        }
        break;
    case 2:
        if (target != NULL && is_actor_cadence_frame(0x1E) != 0) {
            Vec d;
            VecCopy(&d, &target->body_center);
            subtract_vector(&d, &body_center);
            ang = angle_difference_abs(rotation_y, (s32)(BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(d.x, d.z)));
            if (d.x * d.x + d.z * d.z < BEAST_GROUP_APPROACH_DISTANCE_SQ || children == 0) {
                mode = 3;
                phase = 1;
                requested_action = 2;
            } else if (attack_params->get_attack_angle() < ang) {
                phase = 1;
                requested_action = 2;
            }
        }
        break;
    }
    apply_actor_gravity(this, 0, BEAST_GROUND_HEIGHT_OFFSET);
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TUnk_80493450::run_move_action() {
    if (test_actor_flags(0x1000) != 0) {
        mode = 4;
    }
    switch (mode) {
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 0xA;
        }
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    case 2:
    case 3:
        break;
    case 4:
        requested_action = 5;
        break;
    default:
        mode = 3;
        phase = 1;
        requested_action = 2;
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    }
}

void TUnk_80493450::beast_idle_update() {
    f32 r;
    f32 dist;
    f32 range;
    s32 diff;
    s32 angle;
    s32 angle2;
    TUnk_80493450 *other;

    update_target_near_flag();
    select_move_speed();
    advance_animation();
    if (phase != 1) {
        phase = 1;
        link_into_group_chain();
        in_group = has_group();
    }
    child_count = countChildren();
    other = (TUnk_80493450 *)next;
    if (other != NULL) {
        diff = other->child_count - child_count;
        if (diff > 1) {
            link_chain_nodes(other, this);
            child_count = child_count + 1;
            other->child_count = other->child_count - 1;
        } else if (diff < -1) {
            link_chain_nodes(this, other);
            child_count = child_count - 1;
            other->child_count = other->child_count + 1;
        }
    }
    dist = horizontal_distance_squared(&position, &home_position);
    range = parameters[1] + (((BeastMovementParams *)movementParameters)->wanderSpeed + bodies->radius);
    if (range * range < dist) {
        VecCopy(&move_destination, &home_position);
        VecCopy(&move_origin, &body_center);
        VecCopy(&prev_position, &position);
        VecCopy(&scratch_vec, &home_position);
        subtract_vector(&scratch_vec, &position);
        angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, scratch_vec.z);
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = move_speed;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &position);
        if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
            requested_action = 2;
            VecCopy(&position, &lbl_8050BF00);
            rotation_y = approach_angle_limited(rotation_y, angle, ((BeastMovementParams *)movementParameters)->turnSpeed);
            goto end;
        }
        r = fabs_float(scratch_vec.z);
        if (fabs_float(scratch_vec.x) < r) {
            angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, BEAST_ZERO_VECTOR_COMPONENT);
        } else {
            angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(BEAST_ZERO_VECTOR_COMPONENT, scratch_vec.z);
        }
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = move_speed;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &position);
        if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
            requested_action = 2;
            VecCopy(&position, &lbl_8050BF00);
            rotation_y = approach_angle_limited(rotation_y, angle, ((BeastMovementParams *)movementParameters)->turnSpeed);
            goto end;
        }
        r = fabs_float(scratch_vec.z);
        if (fabs_float(scratch_vec.x) < r) {
            angle2 = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(BEAST_ZERO_VECTOR_COMPONENT, scratch_vec.z);
        } else {
            angle2 = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, BEAST_ZERO_VECTOR_COMPONENT);
        }
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = move_speed;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle2);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &position);
        if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
            requested_action = 2;
            VecCopy(&position, &lbl_8050BF00);
            rotation_y = approach_angle_limited(rotation_y, angle2, ((BeastMovementParams *)movementParameters)->turnSpeed);
        } else {
            requested_action = 2;
        }
    } else if (child_count == 0 && BEAST_MIN_WANDER_RANGE < parameters[1]) {
        requested_action = 2;
        enemy_wander_home(((BeastMovementParams *)movementParameters)->wanderSpeed, parameters[1], parameters[1], ((BeastMovementParams *)movementParameters)->turnSpeed);
    } else {
        request_stand_action();
    }
end:
    if (test_actor_flags(0x800000) == 0) {
        apply_actor_gravity(this, NULL, BEAST_GROUND_HEIGHT_OFFSET);
    }
    refresh_collision_body_centers();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x04240000);
    clear_player_status_flag(0, 0x0A000000);
}

void TUnk_80493450::run_idle_action() {
    switch (mode) {
    case 1:
        if (appearing != 0) {
            mode = 0;
            phase = 0;
        }
        break;
    case 0:
        switch (phase) {
        case 2:
            if (appearing != 0) {
                phase = 0;
            }
            break;
        }
        break;
    default:
        if (appearing != 0) {
            mode = 0;
        } else {
            mode = 1;
        }
        phase = 0;
        request_stand_action();
        set_actor_flags(0x04040000);
        set_indexed_flags(0, 0x0A000000);
        break;
    }
}


void TUnk_80493450::refresh_target() {
    u16 best;
    TObjPlayer *player;
    u16 id;
    f32 best_dist;
    f32 dist;

    if (appearing == 1) {
        targetId = 0xFFFF;
        set_actor_flags(0x04040000);
    } else if (test_actor_flags(0x1000) != 0) {
        if (--retreat_timer < 0) {
            targetId = 0xFFFF;
            retreat_timer = 0;
            set_actor_flags(0x1000);
        } else {
            targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
        }
    } else if (test_actor_flags(0x10) != 0) {
        if (is_actor_cadence_frame(0x1E) != 0) {
            s32 i = 0;
            best = 0xFFFF;
            Vec d = beast_zero_vector;
            best_dist = ((BeastMovementParams *)movementParameters)->detectionRadius * ((BeastMovementParams *)movementParameters)->detectionRadius;
            for (; i < registered_player_count + registered_enemy_count; i++) {
                player = TObjPlayer::get_player_data(i);
                if (player == NULL) {
                    break;
                }
                id = player->get_entity_id();
                if (id < 0x4000 && id != entity_id && player->test_actor_flags(0x03000800) == 0) {
                    VecCopy(&d, &player->body_center);
                    subtract_vector(&d, &body_center);
                    dist = d.x * d.x + d.z * d.z;
                    if (dist < best_dist && check_path_obstructed(this, &player->body_center) != 1 &&
                        csnVector(&body_center, &player->body_center, -1) == 0) {
                        best = id;
                        best_dist = dist;
                    }
                }
            }
            targetId = best;
        }
    } else if (in_group != 0) {
        targetId = get_enemy_target_id(groupRoot());
    } else if (is_actor_cadence_frame(0x1E) != 0) {
        targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
    }
    if (targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = p;
        } else {
            target = NULL;
        }
    } else if (targetId < 0x4000) {
        target = get_enemy_entity(targetId);
    } else {
        target = NULL;
    }
}

#pragma defer_codegen on
TUnk_80493450::TUnk_80493450(TObject *parent) : TObjEnemy(parent) {
    mode = 0;
    phase = 0;
    retreat_timer = 0;
    pad_376 = 0;
    in_group = 0;
    child_count = 0;
    corpse_offset_y = BEAST_CORPSE_RETIRE_START;
    corpse_sink_speed = BEAST_CORPSE_RETIRE_STEP;
    corpse_sink_limit = BEAST_CORPSE_RETIRE_THRESHOLD;
    home_chase_frames = 0;
    appearing = 0;
    far_move_speed = BEAST_DEFAULT_MOVEMENT_RATE;
    near_move_speed = BEAST_NEAR_TARGET_MOVEMENT_RATE;
    move_speed = BEAST_DEFAULT_MOVEMENT_RATE;
    far_anim_speed = BEAST_DEFAULT_MOVEMENT_RATE;
    near_anim_speed = BEAST_NEAR_TARGET_MOVEMENT_RATE;
}
TUnk_80493450::~TUnk_80493450() {}

void TUnk_80493450::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    switch (mode) {
    case 0:
        beast_update_appear();
        break;
    case 1:
        beast_idle_update();
        break;
    case 2:
        update_turn_toward_target();
        break;
    case 3:
        beast_update_approach();
        break;
    case 4:
        beast_update_group_chase();
        break;
    case 5:
        beast_update_attack();
        break;
    case 6:
        vfunc_89();
        break;
    case 7:
        beast_update_hurt();
        break;
    case 8:
        beast_update_dead();
        break;
    case 9:
        beast_retire_corpse();
        break;
    }
    update_prev_position();
    copy_position();
    submit_cursor_candidate(this, -1);
    frame_timer += BEAST_FRAME_INCREMENT;
}

