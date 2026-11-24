#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3VoloptCore.h"
#include "pso/boss/volopt/TBoss3VoloptMonitor.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/TUnk_80484888.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/network/client_id.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

struct TBoss3VoloptOrbitSpeeds {
    u8 pad_0[0x18];
    s32 speeds[1];
};

extern "C" {
void set_matrix_identity(s32 matrix, f32 scale);
void rotate_vector_by_matrix(saddr matrix, Vec *src, Vec *dst);
}

#pragma readonly_strings on
static const char *TBoss3VoloptCore_name = "TBoss3VoloptCore";
static void *core_combat_stats_a;
static void *core_combat_stats_b;
static void *core_combat_stats_c;
static TBoss3VoloptOrbitSpeeds *core_orbit_speeds;
static BmlResource *core_resources;
s32 boss3_volopt_core_active_flag;
static s32 core_turn_angle_limit;

static TObjMotionAction core_motions[5] = {
    { 1, 0, 0xE, 0.7f, 0x0 },
    { 1, 0, 0xE, 0.7f, 0x1 },
    { 2, 0, 0xE, 0.7f, 0x4 },
    { 2, 0, 0x2, 0.8f, 0x8 },
    { 1, 0, 0x2, 0.8f, 0x10 },
};
static TBoss3VoloptCoreMovement core_movement = {
    150.0f, 0.55555552f, 0x400, { 0x1E0000, 0, 1, 0 },
};
static CollisionBody core_body_parts[1] = {
    { { 0.0f, 0.0f, 0.0f }, 0.001f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

extern saddr player_battle_param_table[];

void TObjEnemyCustom::set_state(s32 action) {
    s16 current = mode;
    if (current != action) {
        previous_action = current;
        next_action = action;
    }
}

void TObjEnemyCustom::update_if_active(s32 action) {
    if (!(behavior_flags & 1)) {
        set_state(action);
    }
}

saddr TObjPlayer::get_battle_param(int index) {
    return player_battle_param_table[index];
}

void TBoss3VoloptCore::load_entry_params_volopt(s32 index) {
    model = (void *)core_resources->models[index].model;
    texlist = core_resources->models[index].texlist;
}

s32 TBoss3VoloptCore::get_orbit_speed(s32 index) {
    return core_orbit_speeds->speeds[index];
}

s32 TBoss3VoloptCore::is_target_in_attack_range() {
    return 0;
}

TBoss3VoloptCore::TBoss3VoloptCore(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    apply_set_data(set_data);
    init_params();
}

TBoss3VoloptCore::TBoss3VoloptCore(TBoss3Volopt *parent, u16 id, s32 param) : TObjEnemyCustom(parent) {
    entity_id = id;
    this->set_index = param;
    set_entry = 0;
    room = parent->room;
    set_group = parent->set_group;
    init_params();
}

void TBoss3VoloptCore::init_params() {
    m_name = TBoss3VoloptCore_name;
    motion_list = core_resources->motions;
    action_table = core_motions;
    set_action_table(action_table);
    init_collision_body_parts(this, core_body_parts, 1);
    variant = 0;
    movementParameters = &core_movement;
    recalc_combat_stats((player_stats *)core_combat_stats_a, (AttackParams *)core_combat_stats_b, (ActorParamBlock *)core_combat_stats_c, 1.0f, 1.0f);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    register_by_id();
    load_entry_params_volopt(0x18);
    behavior_flags |= 0x10000;
    orbit_angle = 0;
    bodies->flags |= 0xC00;
    run_idle_action();
    add_flags_2e4(4);
    hit_cooldown = 0;
    set_actor_flags(0x8000);
    if (TBoss3Volopt::is_v2_mode() != 0) {
        core_turn_angle_limit = 0xA00;
    } else {
        core_turn_angle_limit = 0x200;
    }
    clear_lobby_object_state();
}

TBoss3VoloptCore::~TBoss3VoloptCore() {
    free_collision_body_parts(this);
    TBoss3Volopt::set_camera_focus(NULL);
}

void *TBoss3VoloptCore::create(void *set_data) {
    return new TBoss3VoloptCore(tl_04, set_data);
}

void TBoss3VoloptCore::load_resources() {
    core_resources = boss3_volopt_resources;
    core_combat_stats_a = TLobby::register_boss(0x21);
    core_combat_stats_b = TLobby::dispatch_shared_handler_b(0x21);
    core_combat_stats_c = TLobby::register_object(0x21);
    core_orbit_speeds = (TBoss3VoloptOrbitSpeeds *)TLobby::dispatch_shared_handler_a(0x21);
}

void TBoss3VoloptCore::release() {}

void TBoss3VoloptCore::run_task() {
    vol_opt_active_hit_zone = calc_hit_zone_index();
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    VecCopy(&prev_position, &position);
    if (hit_cooldown > 0) {
        hit_cooldown--;
    }
    if (has_flag_0x800() != 0) {
        run_death_reaction();
    } else if (test_flag30_512() != 0) {
        if (hit_cooldown > 0) {
            clear_actor_flags(0x200);
        } else {
            run_hit_reaction();
        }
    }
    if (test_actor_flags(0x4000) != 0) {
        if (this->add_status_effect_timer(4, -1) <= 0) {
            status_effects[4].clear();
            clear_actor_flags(0x4000);
        }
    } else {
        if (mode != next_action) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_reaction_state();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_reaction_state();
        position.y = (position.y > 7.0f) ? position.y : 7.0f;
        update_prev_position();
        TBoss3Volopt::set_camera_focus(&body_center);
        clear_all_status_effects();
    }
}

void TBoss3VoloptCore::dispatch_reaction_state() {
    switch (mode) {
    case 0:
        run_freeze_state();
        return;
    case 1:
        update_orbit_state();
        return;
    case 2:
        update_charge_state();
        return;
    case 4:
        update_grabbed_state();
        return;
    case 5:
        update_reaction_animation();
        return;
    case 7:
        update_state_spin();
        return;
    case 9:
        update_orbit_end_state();
        return;
    case 10:
        update_topple_state();
        break;
    }
}

void TBoss3VoloptCore::run_demo_task() {}

void TBoss3VoloptCore::render() {
    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(&position.x);
        rotate_matrix_x(0, rotation_x);
        if (behavior_flags & 0x10000) {
            rotate_matrix_y(0, facing_angle);
            scale_matrix(0, 1.0f, 1.0f, 0.05f);
            rotate_matrix_y(0, rotation_y - facing_angle);
        } else {
            rotate_matrix_y(0, rotation_y);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        pop_matrix();
    }
}

void TBoss3VoloptCore::update_charge_state() {
    s32 angles[3];
    f32 distance;
    TObjPlayer *player;
    target = get_player_by_client_id(targetId);
    switch (state) {
    case 0:
        behavior_flags &= ~0x10000;
        this->requested_action = 0;
        rotation_x = 0;
        if ((s32)previous_action == 4) {
            state = charge_step;
        } else {
            VecCopy(&home_pos, &position);
            charge_step = 1;
            state = 1;
            charge_timer = 0x1E;
        }
        break;
    case 1:
        VecCopy(&velocity, &((TObjPlayer *)target)->position);
        subtract_vector(&velocity, &position);
        turn_toward_direction(0x800, &velocity);
        if (--charge_timer <= 0) {
            charge_timer = 0x96;
            charge_step = 2;
            state = 2;
            angles[1] = facing_angle;
            angles[0] = 0;
            angles[2] = 0x4000;
            new TUnk_80484888(&volopt_slot_positions[slot_index], 0x11B, 8, angles, 0.5f, 0.0f);
        }
        break;
    case 2:
        player = (TObjPlayer *)target;
        if (player == NULL) {
            charge_step = 4;
            state = 4;
            return;
        }
        VecCopy(&velocity, &player->body_center);
        subtract_vector(&velocity, &position);
        vec_set_length(&velocity, 5.0f);
        turn_toward_direction(0x800, &velocity);
        vec3_add_to(&position, &velocity);
        if (check_target_collision() != 0) {
            charge_step = 4;
            state = 4;
        }
        if (--charge_timer <= 0) {
            charge_step = 4;
            state = 4;
        }
        break;
    case 4:
        VecCopy(&velocity, &home_pos);
        subtract_vector(&velocity, &position);
        distance = vec_set_length(&velocity, 5.0f);
        turn_toward_direction(0x800, &velocity);
        vec3_add_to(&position, &velocity);
        check_target_collision();
        if (distance < 10.0f) {
            targetId = 0xFFFF;
            run_move_action();
        }
        break;
    }
    advance_animation();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TBoss3VoloptCore::update_grabbed_state() {
    switch (state) {
    case 0:
        if (test_actor_flags(0x02000000) != 0) {
            behavior_flags |= 0x40000;
        }
        clear_actor_flags(0x02200200);
        referenceHp = hp;
        this->requested_action = 3;
        play_sound_effect(0x4003A81F, NULL, 0, 0);
        play_sound_effect(0x4003BC20, NULL, 0, 0);
        if (local_client_id == attacker_id) {
            start_camera_shake(0x1E, 0.08f);
        }
        hit_cooldown = 0x14;
        state = 1;
    case 1:
        advance_animation();
        if (this->action_flags != 8) {
            behavior_flags &= ~1;
            if (behavior_flags & 0x40000) {
                set_grabbed_state(0xF);
            } else {
                this->update_if_active(previous_action);
            }
        }
        return;
    case -1:
        behavior_flags &= ~0x40000;
        break;
    }
}

void TBoss3VoloptCore::update_reaction_animation() {
    switch (state) {
    case 0:
        this->requested_action = 4;
        state = 1;
    case 1:
        advance_animation();
        break;
    case -1:
        return;
    }
}

void TBoss3VoloptCore::run_freeze_state() {
    switch (state) {
    case 0:
        boss3_volopt_core_active_flag = 1;
        actorFlags |= 0x02040000;
        state = 1;
        break;
    case 1:
        break;
    case -1:
        actorFlags &= ~0x02040000;
        break;
    }
}

s32 TBoss3VoloptCore::check_target_collision() {
    s32 found;
    s32 i;
    TObjChara *object;
    if (target == NULL) {
        return 0;
    }
    found = 0;
    TObjPlayer::init_all_slots();
    this->check_object_collisions();
    if (bodies->flags & 0x80000) {
        for (i = 0; i < 0x10; i++) {
            object = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (object == NULL) {
                break;
            }
            if (obj_is_hit_receivable(object) != 0) {
                if (object->select_melee_contact_body(this, 1.0f) != 0) {
                    object->apply_knockback_from_attacker((u8 *)this, 3.0f);
                    object->receive_physical_attack(this, 1.0f);
                }
                if (object == target) {
                    found = 1;
                }
            }
        }
    }
    return found;
}

void TBoss3VoloptCore::update_state_spin() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        behavior_flags |= 0x20000;
        orbit_angle = 0x4000;
        sweep_angle = -0x1555;
        targetId = 0xFFFF;
        behavior_flags |= 0x10000;
        this->requested_action = 0;
        rotation_x = 0;
        update_orbit_position();
        facing_angle = calc_spin_value();
        rotation_y = facing_angle;
        timer = 0x5A;
        state = 1;
    case 1:
        advance_animation();
        if (--timer <= 0) {
            actorFlags &= ~0x40000;
            behavior_flags &= ~1;
            run_idle_action();
        }
        break;
    case -1:
        break;
    }
}

s32 TBoss3VoloptCore::calc_spin_value() {
    return (s32)(182.04445f * (f32)((((s32)(u16)orbit_angle / 10922) * 0x3C) + 0x78));
}

void TBoss3VoloptCore::update_orbit_position() {
    f32 radius;
    s32 offset = ((u16)orbit_angle % 10922) - 0x1555;
    if (behavior_flags & 0x20000) {
        orbit_radius = 134.0f / cos_table_lookup(offset);
        position.y = 50.0f;
    } else {
        orbit_radius = 128.0f / cos_table_lookup(offset);
        position.y = 15.0f;
    }
    push_matrix();
    radius = orbit_radius;
    position.x = radius;
    position.z = 0.0f;
    set_matrix_identity(0, radius);
    rotate_matrix_y(0, orbit_angle);
    rotate_vector_by_matrix(0, &position, &position);
    pop_matrix();
}

s32 TBoss3VoloptCore::calc_hit_zone_index() {
    s32 zone;
    s32 offset;
    s32 angle;
    TObjEnemyCustom *monitor;
    if (mode == 0) {
        return -1;
    }
    angle = orbit_angle;
    zone = -1;
    offset = (u16)angle % 0x2AAA - 0x1555;
    if (position.y >= 25.0f) {
        if (__abs(offset) <= 0x8DC) {
            zone = 0;
        }
    } else if (offset <= 0xDB2) {
        if (offset >= 0x510) {
            zone = 1;
        } else if (offset >= -0x510) {
            zone = 2;
        } else if (offset >= -0xDB2) {
            zone = 3;
        }
    }
    if (zone >= 0) {
        zone += ((u16)(angle - 0x2AAA) / 0x2AAA) * 4;
        monitor = (TObjEnemyCustom *)find_entity_by_id(boss3_volopt_monitor_base_actor_id + zone);
        if (monitor == NULL || (monitor->actorFlags & 0x800)) {
            zone = -1;
        }
    }
    return zone;
}

void TBoss3VoloptCore::set_boss_target_pos(s32 slot, s32 moves, s32 delay_frames) {
    if (test_actor_flags(0x800) == 0) {
        behavior_flags |= 0x20000;
        target_slot = slot;
        moves_left = moves;
        delay = delay_frames;
        boss3_volopt_core_active_flag = 0;
        alloc_boss_target_slot();
        behavior_flags &= ~1;
        run_move_action();
    }
}

void TBoss3VoloptCore::update_orbit_state() {
    switch (state) {
    case 0:
        behavior_flags |= 0x10000;
        this->requested_action = 0;
        rotation_x = 0;
        state = 1;
        break;
    case 1:
        advance_animation();
        orbit_angle -= get_orbit_speed(0);
        sweep_angle -= get_orbit_speed(0);
        update_orbit_position();
        facing_angle = calc_spin_value();
        rotation_y = facing_angle - 0x4000;
        if (moves_left > 1) {
            if (sweep_angle <= -0x238E) {
                moves_left--;
                if (--target_slot < 0) {
                    target_slot = 5;
                }
                if (alloc_boss_target_slot() == 1) {
                    state = 0;
                }
                break;
            }
        } else if (sweep_angle < -0x1555) {
            drop_angle = orbit_angle;
            this->update_if_active(9);
        }
        play_persistent_sound(0x4003BC05, this, &position, 0, 0);
        break;
    case -1:
        break;
    }
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
}

void TBoss3VoloptCore::update_orbit_end_state() {
    switch (state) {
    case 0:
        behavior_flags |= 0x10000;
        this->requested_action = 0;
        timer = 5;
        effect = NULL;
        state = 1;
    case 1:
        rotation_y = approach_angle_limited(rotation_y, facing_angle - 0x8000, core_turn_angle_limit);
        if (angle_difference_abs(rotation_y, facing_angle - 0x8000) <= core_turn_angle_limit) {
            timer = (TBoss3Volopt::is_v2_mode() != 0) ? 5 : 0x1E;
            state = 2;
        }
        break;
    case 2:
        if (--timer <= 0) {
            Vec pos = *&position;
            pos.y -= 20.0f;
            effect = create_particle_emitter(&pos, 0x31);
            play_sound_effect(0x4003AD1E, reinterpret_cast<const Vec *>(&position.x), 0, 0);
            state = 3;
        }
        break;
    case 3:
        if (--timer < 0) {
            boss3_volopt_core_active_flag = 1;
            run_idle_action();
        }
        break;
    case -1:
        if (effect != NULL) {
            effect->queue_destruction();
            effect = NULL;
        }
        break;
    }
    advance_animation();
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
}

s32 TBoss3VoloptCore::alloc_boss_target_slot() {
    s32 i;
    s32 slot;
    for (i = 0; i < 6; i++) {
        slot = (target_slot + 6 - i) % 6;
        if (volopt_target_slot_used[slot * 4] == 0) {
            target_slot = slot;
            break;
        }
    }
    if (i == 6) {
        boss3_volopt_core_active_flag = 1;
        run_idle_action();
        return 0;
    }
    orbit_angle = (s32)(182.04445f * (f32)((target_slot + 2) * 60 - 10));
    sweep_angle = -0x71C;
    return 1;
}

void TBoss3VoloptCore::link_photon(u16 id, s32) {
    TBoss3VoloptCore *core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id);
    if (core != NULL && core->hit_cooldown <= 0) {
        TObject *source = (TObject *)find_entity_by_id(id);
        if (source != NULL) {
            core->bodies->flags |= 0x04000000;
            core->receive_physical_attack(source, 1.0f);
        }
    }
}

void TBoss3VoloptCore::update_topple_state() {
    switch (state) {
    case -1:
        break;
    case 0:
        behavior_flags |= 0x10000;
        this->requested_action = 0;
        if (angle_difference_abs(rotation_y, facing_angle - 0x4000) <= core_turn_angle_limit) {
            state = 3;
        } else {
            state = 1;
        }
        break;
    case 1:
        if (--delay <= 0) {
            state = 2;
        }
        break;
    case 2:
        rotation_y = approach_angle_limited(rotation_y, facing_angle - 0x4000, core_turn_angle_limit);
        if (angle_difference_abs(rotation_y, facing_angle - 0x4000) <= core_turn_angle_limit) {
            state = 3;
        }
        break;
    case 3:
        play_persistent_sound(0x4003BC05, this, &position, 0, 0);
        advance_animation();
        orbit_angle -= get_orbit_speed(0);
        sweep_angle -= get_orbit_speed(0);
        update_orbit_position();
        facing_angle = calc_spin_value();
        if (sweep_angle <= -0x238E) {
            run_idle_action();
        }
        break;
    }
    advance_animation();
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
}

void TBoss3VoloptCore::set_grabbed_state(s32 delay) {
    TBoss3VoloptCore *core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id);
    if (core != NULL && core->mode != 10) {
        core->update_if_active(10);
        core->delay = delay;
    }
}
