#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

struct NJS_OBJECT;
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/enemy/epsilon/TObjEneEpsilonBody.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"

player_stats *epsilon_guard_boss_stat_handle;
AttackParams *epsilon_guard_shared_handler_b;
ActorParamBlock *epsilon_guard_registered_object_handle;
TObjEneEpsilonGuardParams *TObjEneEpsilonGuard__movement_params;
Vec epsilon_guard_node_origin;
s32 epsilon_guard_camera_step;
Vec *epsilon_guard_camera_ctrl_ptr;
extern const BreakUpParamRow epsilon_guard_breakup_params = { 0x14, 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f };
const char *TObjEneEpsilonGuard__class_name = "TObjEneEpsilonGuard";

extern CollisionBody TObjEneEpsilonGuard__model_desc[];


f32 TObjEneEpsilonGuard::receive_weapon_special_attack(void *, void *) {
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard::receive_physical_attack(void *, f32) {
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard::receive_direct_attack(void *attacker, DirectAttackPayload msg, void *body, s32 tech, s32 flags) {
    if (msg.kind == 0x14) {
        return TObjChara::receive_direct_attack(attacker, msg, body, tech, flags);
    }
    try_apply_damage(&body_center, 0);
    return 0.0f;
}

s32 TObjEneEpsilonGuard::test_flag_80() { return ((u32)flags >> 7) & 0x1; }

s32 TObjEneEpsilonGuard::is_following_body() {
    if (actorFlags & 0xA00) {
        return 0;
    }
    return ((u32)flags >> 4) & 1;
}

s32 TObjEneEpsilonGuard::is_guard_active() {
    if (actorFlags & 0xA00) {
        return 0;
    }
    if (mode != 1) {
        return 0;
    }
    return ((u32)flags >> 9) & 1;
}

s32 TObjEneEpsilonGuard::is_state_flag_set() {
    if (actorFlags & 0xa00) {
        return 0;
    }
    if (flags & 0x10) {
        return 0;
    }
    if (flags & 0x20) {
        return 0;
    }
    return (flags & 4) ? 1 : 0;
}

s32 TObjEneEpsilonGuard::is_guard_ready() {
    if (actorFlags & 0xa00) {
        return 0;
    }
    if (flags & 0x10) {
        return 0;
    }
    if (flags & 0x20) {
        return 0;
    }
    return (flags & 4) ? 1 : 0;
}

void TObjEneEpsilonGuard::clear_and_flag_state() {
    effect_step = 0;
    flags |= 0x20;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_flag_8_and_notify() {
    flags |= 8;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_flag_2_and_clear_status() {
    flags |= 2;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_target(const Vec *pos, s32 angle, s32 reverse) {
    VecCopy(&position, pos);
    rotation_y = angle;
    if (reverse != 0) {
        flags |= 0x100;
    } else {
        flags &= ~0x100;
    }
    flags |= 1;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::render_guard_effect() {
    f32 scale;

    if ((flags & 0x20) && ((s32)main_task.get_task_flags() & 0x200)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, 24.0f, 0.0f);
        scale = effect_scale;
        scale_matrix(0, scale, scale, scale);
        set_motion_packed_rotation();
        draw_model_motion(effect_model, effect_motion, effect_frame);
        clear_motion_packed_rotation();
        pop_matrix();
    }
}

void TObjEneEpsilonGuard::render_with_fade(s32 detail) {
    s32 i;
    RenderFadeState *fade;
    i = 0;
    if (is_split_screen() != 0) {
        i = TCameraCtrl::get_camera_mode();
    }
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    fade = &this->fades[i];
    fade->update();
    if (fade->updateFromCamera(&this->body_center.x) != 0) {
        fade->set_flags_and_apply_damage_color();
        if (!((s32)main_task.get_task_flags() & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (this->mode == 3) {
        this->fade.set_flags_and_apply_damage_color();
        if (!((s32)main_task.get_task_flags() & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x200) {
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        return;
    }
    this->update_secondary_light();
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    push_matrix();
    post_translate_matrix(&this->position.x);
    translate_matrix(0, 0.0f, 24.0f, 0.0f);
    rotate_matrix_y(0, this->rotation_y);
    TObjEneDD::clear_global_flag_400();
    epsilon_guard_camera_step = 0;
    epsilon_guard_camera_ctrl_ptr = &this->effect_anchor;
    this->effect_anchor.x = 0.0f;
    this->effect_anchor.y = 0.0f;
    this->effect_anchor.z = 0.0f;
    set_chunk_model_node_callback(TObjEneEpsilonGuard::advance_camera_ctrl_step);
    TObjPlayer::toggle_particle_effect();
    if (detail == 1) {
        this->TObjMotion::draw();
    } else {
        this->draw_motion_model();
    }
    TParticleCtrl::end_effect_render();
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    this->update_primary_light();
    if (fade->updateFromCamera(&this->body_center.x) != 0) {
        fade->clear_flag_and_notify();
    } else if (this->mode == 3) {
        this->fade.clear_flag_and_notify();
    }
    model_render_flags = saved_model_render_flags;
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
}

void TObjEneEpsilonGuard::render() {
    s32 detail;
    if ((TObjPlayer::check_demo_mode() == 0) && !(actorFlags & 0x02000000)) {
        detail = 0;
        if (!(flags & 0x10)) {
            if (TObjEneDD::is_main_phase_15() != 0) {
                detail = classify_actor_view_detail(6e+02f, 6e+02f, 15.0f);
            } else if (update_object_view_visibility(6e+02f, 15.0f) != 0) {
                detail = 1;
            } else {
                detail = 0;
            }
        }
        if (detail != 0) {
            draw_ground_shadow(0, 0);
            defer_render();
            render_with_fade(detail);
            render_guard_effect();
            return;
        }
        effect_anchor.x = 0.0f;
        effect_anchor.y = 0.0f;
        effect_anchor.z = 0.0f;
        calc_joint_position(&effect_anchor, 0);
    }
}

void TObjEneEpsilonGuard::advance_camera_ctrl_step(NJS_OBJECT *) {
    if ((s32) epsilon_guard_camera_step == 0) {
        forward_transform_to_view(&epsilon_guard_node_origin, epsilon_guard_camera_ctrl_ptr);
    }
    epsilon_guard_camera_step += 1;
}

void TObjEneEpsilonGuard::handle_message(s32 msg) {
    switch (msg) {
    case 4:
        set_intangible();
        flags |= 0x14;
        send_entity_set_flags();
        return;
    case 3:
        queue_destruction();
    case 5:
    case 0:
        return;
    }
}


void TObjEneEpsilonGuard::handle_break_state(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(4);
        flags |= 0x40;
        flags &= ~0x14;
        clear_intangible();
        spawn_effect_f8(&effect_anchor, 0x14);
        state_step = 0;
        break_timer = 0;
        break;
    case 3:
        if (state_step == 1) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        break_timer++;
        if (break_timer >= 0x14) {
            clear_intangible();
            TBoss3Volopt::create_breakup_mdl(epsilon_guard_breakup_model, &epsilon_guard_breakup_params,
                               texlist, &position, rotation_y);
            play_sound_effect(0x4003AD4C, &body_center, 0, 0);
            trigger_dell_biter_events(&body_center);
            state_step = 1;
        }
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::state_fade_out(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(3);
        fade.set_rate_from_divisor(0x14);
        fade.reset_color();
        flags &= ~0x14;
        clear_intangible();
        break;
    case 3:
        if (fade.decay_value_toward_floor() != 0) {
            transition_enemy_state(0);
            flags |= 0x10;
            set_intangible();
            break;
        }
    case 5:
        break;
    case 0:
        advance_animation();
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::state_orbit(s32 msg) {
    TObjEneEpsilonBody *body;

    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        flags |= 4;
        flags &= ~0x18;
        clear_intangible();
        state_step = 0;
        orbit_angle = rotation_y;
        orbit_angle_step = 0;
        return;
    case 3:
        if (flags & 8) {
            transition_enemy_state(3);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            if (flags & 0x100) {
                orbit_angle_step = (s32) ((-65536.0f * TObjEneEpsilonGuard__movement_params->orbit_speed) / (6.283184f * TObjEneEpsilonGuard__movement_params->orbit_radius));
            } else {
                orbit_angle_step = (s32) ((65536.0f * TObjEneEpsilonGuard__movement_params->orbit_speed) / (6.283184f * TObjEneEpsilonGuard__movement_params->orbit_radius));
            }
            state_step = 1;
            break;
        case 1:
            body = (TObjEneEpsilonBody *)find_entity_by_id(body_id);
            if (body != NULL) {
                if (TObjEneEpsilonBody::is_orbit_paused() == 1) {
                    flags &= ~4;
                    state_step = 2;
                } else if (body->test_flag_20() != 1) {
                    goto orbit;
                }
            } else {
orbit:
                orbit_angle += orbit_angle_step;
                set_orbit_destination(orbit_angle);
                update_velocity();
                this->move_with_wall_slide_commit(destination_direction.x, destination_direction.z, TObjEneEpsilonGuard__movement_params->orbit_speed);
            }
            break;
        case 2:
            if ((find_entity_by_id(body_id) != 0U) && (TObjEneEpsilonBody::is_orbit_paused() == 0)) {
                flags |= 4;
                state_step = 1;
            }
            break;
        }
        rotation_y = calc_angle_to_target();
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::state_move_out(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(1);
        flags &= ~0x216;
        clear_intangible();
        return;
    case 3:
        if (flags & 2) {
            transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        enemy_copy_target_destination();
        update_velocity();
        if (!(flags & 0x200)) {
            TObjEneEpsilonGuardParams *d = TObjEneEpsilonGuard__movement_params;
            if (destination_distance > d->orbit_radius + d->move_out_speed) {
                flags |= 0x200;
            } else {
                move_with_wall_slide_commit(-destination_direction.x, -destination_direction.z, d->move_out_speed);
            }
        }
        rotation_y = calc_angle_to_target();
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::handle_event(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(0);
        set_intangible();
        flags |= 0x10;
        flags &= ~5;
        return;
    case 3:
        if (flags & 1) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        flags |= 0x10;
        break;
    }
}
void TObjEneEpsilonGuard::update_effect_attack() {
    f32 lim;
    s32 i;
    TObjChara *p;
    uaddr body;
    if (flags & 0x20) {
        switch (effect_step) {
        case 0:
            effect_scale = 0.0f;
            effect_timer = 0;
            effect_frame = 0.0f;
            effect_step = 1;
            emitter = create_particle_emitter(&body_center, 0x221);
            break;
        case 1:
            effect_scale += 0.1f;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_scale >= 1.0f) {
                effect_scale = 1.0f;
                effect_step = 2;
            }
            break;
        case 2:
            effect_timer++;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_timer >= TObjEneEpsilonGuard__movement_params->attack_hold_frames) {
                effect_scale = 1.0f;
                effect_step = 3;
            }
            break;
        case 3:
            effect_scale -= 0.1f;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_scale <= 0.0f) {
                effect_scale = 0.0f;
                flags &= ~0x20;
                if (emitter != NULL) {
                    emitter->queue_destruction();
                    emitter = NULL;
                }
            }
            break;
        default:
            flags &= ~0x20;
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            break;
        }
        lim = (f32)effect_motion->nbFrame - 1.0f;
        effect_frame += 0.5f;
        if (lim < effect_frame) {
            effect_frame -= lim;
        }
        TObjEneEpsilonGuard__model_desc[1].radius = 36.0f * effect_scale;
        VecCopy(&collider->position, &position);
        TObjPlayer::init_all_slots();
        collider->check_object_collisions();
        if (collider->bodies->flags & 0x80000) {
            for (i = 0; i < 16; i++) {
                p = (TObjChara *)TObjPlayer::get_battle_param(i);
                if (p == NULL) {
                    break;
                }
                if (obj_is_hit_receivable(p) != 0) {
                    body = (uaddr)find_entity_by_id(body_id);
                    if (body != 0 && p->has_flag_0x800() == 0) {
                        DirectAttackPayload attack;
                        f32 damage;
                        attack.kind = ((TObjEneEpsilonBody *)body)->get_table_value_by_index();
                        attack.power = TObjEneEpsilonGuard__movement_params->attack_power;
                        damage = p->receive_direct_attack(this, attack, 0, -1, -1);
                        p->apply_knockback_from_attacker((u8 *)this, damage);
                    }
                }
            }
        }
    } else if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

void TObjEneEpsilonGuard::update_guard_state() {
    s16 state;
    TObjCollidable *body;

    if (!(flags & 0x40)) {
        body = find_entity_by_id(body_id);
        if ((body == NULL) || (((TObjEneEpsilonBody *)body)->test_flag_800() == 1)) {
            if (flags & 0x10) {
                transition_enemy_state(5);
            } else {
                transition_enemy_state(4);
            }
        } else {
            current_target = (TObjChara *)body;
            target_id = current_target->get_entity_id();
            enemy_copy_target_destination();
            update_effect_attack();
        }
        if (flags & 0x20) {
            play_persistent_sound(0x4003A846, this, &position, 0, 0);
            return;
        }
        state = mode;
        if ((state != 4) && (state != 5)) {
            play_persistent_sound(0x4003AD43, this, &position, 0, 0);
        }
    }
}

void TObjEneEpsilonGuard::check_collisions() {
    TObjEneDD::check_collisions();
    if (bodies->flags & 0x400000) {
        flags |= 0x80;
    } else {
        flags &= ~0x80;
    }
    update_center_position();
}

void TObjEneEpsilonGuard::update_center_position() {
    body_center.x = position.x;
    body_center.y = 24.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}
void TObjEneEpsilonGuard::update_body_colliders() { set_part_local_pos(&body_center, 0); }

TObjEneEpsilonMovement epsilon_guard_params = {
    150.0f, 0.5555555f, 0x400, { 0x1E0000, 0, 1, 0 },
};
TObjMotionAction epsilon_guard_action_table[1] = {
    { 1, 0, 2, 1.0f, 0 },
};
CollisionBody TObjEneEpsilonGuard__model_desc[2] = {
    {{0.0f, 12.0f, 0.0f}, 2.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 36.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

s32 TObjEneEpsilonGuard::calc_angle_to_target() {
    f32 x;

    enemy_copy_target_destination();
    x = position.x;
    return (s32) (10430.38043493439 * atan2_float(x - destination.x, position.z - destination.z));
}

#pragma push
#pragma fp_contract on
void TObjEneEpsilonGuard::set_orbit_destination(s32 angle) {
    enemy_copy_target_destination();
    destination.x = (TObjEneEpsilonGuard__movement_params->orbit_radius * sin_table_lookup(angle)) + destination.x;
    destination.z = (TObjEneEpsilonGuard__movement_params->orbit_radius * cos_table_lookup(angle)) + destination.z;
}
#pragma pop

void TObjEneEpsilonGuard::run_miss_reaction() {  }
void TObjEneEpsilonGuard::run_hit_reaction() {  }
void TObjEneEpsilonGuard::run_death_reaction() {  }
void TObjEneEpsilonGuard::refresh_target() {  }


void TObjEneEpsilonGuard::dispatch_action(u32 state, s32 msg) {
    switch (state) {
    case 0:
        handle_event(msg);
        return;
    case 1:
        state_move_out(msg);
        return;
    case 2:
        state_orbit(msg);
        return;
    case 3:
        state_fade_out(msg);
        return;
    case 4:
        handle_break_state(msg);
        return;
    case 5:
        handle_message(msg);
        return;
    }
}

void TObjEneEpsilonGuard::run_task() {
    TObjCollidable *body;
    if (update_status_effects() != 4) {
        update_guard_state();
        update_action_state();
        if (!(flags & 0x10)) {
            update_body_colliders();
            update_center_position();
            submit_default_cursor_candidate();
            render_minimap_dot();
            return;
        }
        body = find_entity_by_id(body_id);
        if (body != NULL) {
            VecCopy(&position, &body->position);
            update_center_position();
        }
    } else if (mode == 0) {
        transition_enemy_state(0);
    }
}

TObjEneEpsilonGuard *TObjEneEpsilonGuard::create(TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle) {
    TObjEneEpsilonGuard *o;
    o = new TObjEneEpsilonGuard(tl_04, body, entity_id, set_index, pos, angle);
    return o;
}

TObjEneEpsilonGuard::~TObjEneEpsilonGuard() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    if (collider != NULL) {
        free_collision_body_parts(collider);
        delete collider;
        collider = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneEpsilonGuard::init_model_and_state() {
    init_position_vectors();
    model = (void *)get_bml_model(epsilon_bml_resource, 2);
    texlist = get_bml_texlist(epsilon_bml_resource, 0);
    init_model(TObjEneEpsilonGuard__model_desc, 1);
    set_action_table(epsilon_guard_action_table);
    set_motion_list(epsilon_bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(epsilon_guard_boss_stat_handle, epsilon_guard_shared_handler_b, epsilon_guard_registered_object_handle);
    set_indexed_flags(0, 0x80020);
    set_state_flag_4();
    movementParameters = &epsilon_guard_params;
    initialize_enemy_state(0x57);
    VecCopy(&effect_anchor, &position);
    flags = 0;
    flags |= 0x10;
    set_intangible();
    effect_model = (void *)get_bml_model(epsilon_bml_resource, 3);
    effect_motion = (NJS_MOTION *)get_bml_motion(epsilon_bml_resource, 3);
    effect_frame = 0.0f;
    effect_timer = 0;
    state_step = 0;
    break_timer = 0;
    orbit_angle = 0;
    orbit_angle_step = 0;
    mode = 0;
    dispatch_action(mode, 4);
    collider = new TObjCollidable(NULL);
    init_collision_body_parts(collider, &TObjEneEpsilonGuard__model_desc[1], 1);
    emitter = NULL;
    sub_800F5874(0x3F);
}

TObjEneEpsilonGuard::TObjEneEpsilonGuard(TObject *parent, TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle)
    : TObjEneEpsilon(parent) {
    s32 i;
    m_name = TObjEneEpsilonGuard__class_name;
    body_id = body->get_entity_id();
    init_common_from(body);
    this->entity_id = entity_id;
    this->set_index = set_index;
    room = body->room;
    set_group = body->set_group;
    VecCopy(&position, pos);
    VecCopy(&home_position, &body->home_position);
    rotation_z = 0;
    rotation_x = 0;
    rotation_y = angle;
    init_model_and_state();
    set_intangible();
    flags |= 0x10;
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
}

s32 TObjEneEpsilon::is_target_in_attack_range() { return 0; }
s32 TObjEneEpsilon::update_movement_status() { return 0; }
