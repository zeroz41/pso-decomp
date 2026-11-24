#pragma readonly_strings on
#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type1_802B20C0.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>

TBoss6Type1Action boss6_type1_action_table[41] = {
    { "APPEAR", 2, 1, &TBoss6Type1::init_effect_slot_1, 0, &TBoss6Type1::update_appear },
    { "RND_FLOAT", 2, 1, &TBoss6Type1::init_attack_timers, &TBoss6Type1::choose_next_action, &TBoss6Type1::tick_countdown },
    { "RND_MOVE", 2, 1, &TBoss6Type1::start_attack, 0, &TBoss6Type1::update_attack_countdown_reset },
    { "KAKUSAN", 11, 1, &TBoss6Type1::init_state_90, 0, &TBoss6Type1::update_kakusan },
    { "KAKUSAN_MV", 11, 1, &TBoss6Type1::init_hp_state, 0, &TBoss6Type1::update_action_timer },
    { "SWORD", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD2", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD3", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD_MV", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::update_sword_mv },
    { "SWORD_MV2", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::update_sword_mv },
    { "SWORD_MV3", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::update_sword_mv },
    { "SWORD_U", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_U2", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_U3", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_U4", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_U5", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_D", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_D2", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_D3", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_D4", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "SWORD_D5", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::update_sword_ud },
    { "TAILATK_MV", 14, 1, &TBoss6Type1::init_dice_state, 0, &TBoss6Type1::update_attack_timer2 },
    { "FLLSR_MV", 15, 1, &TBoss6Type1::act_fllsr_mv, 0, &TBoss6Type1::update_fllsr_mv },
    { "SCREAM", 20, 0, &TBoss6Type1::act_scream, 0, &TBoss6Type1::update_timer },
    { "CHAL_UD", 0, 1, &TBoss6Type1::set_phase_90, &TBoss6Type1::start_action_if_idle, &TBoss6Type1::update_charge },
    { "CHAL_FLOAT", 0, 1, &TBoss6Type1::init_hp_and_state, &TBoss6Type1::idle_chal_float, &TBoss6Type1::tick_trap_countdown },
    { "GOTO_CENTOP", 3, 0, &TBoss6Type1::init_state, 0, &TBoss6Type1::update_timer_transition },
    { "CENTOP_D", 0, 0, &TBoss6Type1::act_centop_d, 0, &TBoss6Type1::tick_flee_countdown },
    { "CENTOP_U", 0, 0, &TBoss6Type1::act_centop_u, &TBoss6Type1::trigger_falz_phase, &TBoss6Type1::update_phase },
    { "DOWN_CENTOP", 5, 0, &TBoss6Type1::init_params, 0, &TBoss6Type1::update_down_centop },
    { "LAND_CENTOP", 8, 2, &TBoss6Type1::advance_plot_to_state2, &TBoss6Type1::update_attack_state, &TBoss6Type1::update_hit_timer },
    { "BOMB_CENTOP", 8, 2, &TBoss6Type1::init_move_attack, 0, &TBoss6Type1::tick_state_410_timer },
    { "TKOF_CENTOP", 9, 0, &TBoss6Type1::enter_release_state, &TBoss6Type1::update_if_idle, &TBoss6Type1::update_tkof_centop },
    { "RET_RND_UD", 2, 0, &TBoss6Type1::init_charge, 0, &TBoss6Type1::tick_attack_sequence },
    { "GOTO_CENBTM", 2, 0, &TBoss6Type1::init_work, 0, &TBoss6Type1::update_attack_timer },
    { "CENBTM_D", 2, 0, &TBoss6Type1::act_cenbtm_d, 0, &TBoss6Type1::update_cenbtm_d },
    { "CENBTM_U", 2, 0, &TBoss6Type1::reset_effects, &TBoss6Type1::update_state, &TBoss6Type1::update_countdown },
    { "PUT_MINE", 2, 0, &TBoss6Type1::set_phase_555, &TBoss6Type1::update_if_ready, &TBoss6Type1::update_countdown_state },
    { "RET_RND_DU", 2, 0, &TBoss6Type1::init_charge_attack, 0, &TBoss6Type1::update_attack_countdown },
    { "WAITNEXT", -1, 0, 0, &TBoss6Type1::enter_flag800_state, 0 },
    { "DEAD", -1, 0, 0, 0, 0 },
};

static const Vec centop_pos = {0.0f, 275.0f, 0.0f};
static const Vec centop_down_pos = {0.0f, 225.0f, 0.0f};
static const Vec down_centop_pos = {0.0f, 144.0f, 0.0f};
static const Vec down_centop_land_pos = {0.0f, 64.0f, 0.0f};
static const Vec cenbtm_pos = {0.0f, -145.0f, 0.0f};
static const Vec cenbtm_down_pos = {0.0f, -180.0f, 0.0f};
static Vec tkof_centop_low_pos = {0.0f, 114.0f, 0.0f};
static Vec tkof_centop_high_pos = {0.0f, 264.0f, 0.0f};

void TBoss6Type1::enter_flag800_state() {
    if (actorFlags & 0x800) {
        send_flow_action_if_idle(this, 0x28);
        return;
    }
    send_flow_action_if_idle(this, 1);
}

void TBoss6Type1::update_attack_countdown() {
    s32 motion_frame;
    s32 attack_frame;

    interpolate_pos_to_target(action_timer, action_duration);
    ease_toward_target(action_timer, action_duration);
    motion_frame = action_duration - 2;
    attack_frame = motion_frame - 10;
    if (action_timer == motion_frame) {
        set_motion_set(6);
    } else if (action_timer == attack_frame) {
        attack_mode = 1;
    }
    if (--action_timer < 0) {
        latch_phase_counter();
        target_mode = 0;
        set_action_state(1);
    }
}

void TBoss6Type1::init_charge_attack() {
    action_duration = 0x3C;
    action_timer = 0x3C;
    play_sound_effect(0x4003A811, &position, 0, 1);
    release_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_countdown_state() {
    if ((s32)action_timer == (s32)((f32)action_duration - 30.0f)) {
        release_effect_slot(3);
    }
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::update_if_ready() {
    if (((s32)action_timer == 0) || (is_timer_expired() != 0)) {
        send_ret_rnd();
    }
}

void TBoss6Type1::set_phase_555() {
    action_duration = 555;
    action_timer = 555;
    spawn_mines();
    release_effect_slot(0);
    release_effect_slot(1);
    spawn_effect_slot(3);
}

void TBoss6Type1::update_countdown() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::update_state() {
    if ((s32)action_timer == 0) {
        if (is_normal_difficulty() != 0) {
            send_ret_rnd();
            return;
        }
        if (is_field3F8_over_0x20() != 0) {
            send_flow_action_if_idle(this, 0x25);
            return;
        }
        send_ret_rnd();
    }
}

void TBoss6Type1::reset_effects() {
    action_duration = 0x1E;
    action_timer = 0x1E;
    VecCopy(&target_position.v, &cenbtm_pos);
    release_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_cenbtm_d() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(0x14 - (random_factor & 1));
    }
}

void TBoss6Type1::act_cenbtm_d() {
    action_duration = 0x1E;
    action_timer = 0x1E;
    VecCopy(&target_position.v, &cenbtm_down_pos);
    release_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_attack_timer() {
    s32 motion_frame;
    s32 attack_frame;

    interpolate_pos_to_target(action_timer, action_duration);
    ease_toward_target(action_timer, action_duration);
    motion_frame = action_duration - 2;
    attack_frame = motion_frame - 10;
    if (action_timer == motion_frame) {
        set_motion_set(6);
    } else if (action_timer == attack_frame) {
        attack_mode = 0;
    }
    if (--action_timer < 0) {
        set_action_state(0x23);
    }
}

void TBoss6Type1::init_work() {
    action_duration = 0x3C;
    action_timer = 0x3C;
    VecCopy(&target_position.v, &cenbtm_pos);
    play_sound_effect(0x39403, &node_points[1], 0, 1);
    play_sound_effect(0x4003A811, &position, 0, 1);
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::tick_attack_sequence() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (action_timer == 0x23) {
        set_motion_set(6);
    } else if (action_timer == 0x19) {
        attack_mode = 1;
    }
    if (--action_timer < 0) {
        latch_phase_counter();
        target_mode = 0;
        set_action_state(1);
    }
}

void TBoss6Type1::init_charge() {
    action_duration = 0x3C;
    action_timer = 0x3C;
    play_sound_effect(0x4003A811, &position, 0, 1);
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::update_tkof_centop() {
    if (action_timer == 0x4A) {
        VecCopy(&target_position.v, &tkof_centop_low_pos);
    } else if (action_timer == 0x3B) {
        VecCopy(&target_position.v, &tkof_centop_high_pos);
    }
    if (action_timer <= 0x4A) {
        if (action_timer > 0x3B) {
            interpolate_pos_to_target(action_timer - 0x3B, 0xF);
        } else {
            interpolate_pos_to_target(action_timer, action_duration);
        }
    }
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::update_if_idle() {
    if (action_timer == 0) {
        send_ret_rnd();
    }
}

void TBoss6Type1::enter_release_state() {
    action_duration = 0x5A;
    action_timer = 0x5A;
    release_map_csn();
    play_sound_effect(0x4003B515, &position, 0, 0);
    spawn_effect_slot(0);
    release_effect_slot(1);
    plot_falz->activate_warp();
    plot_falz->reset_state();
    if (count_matches(0x1F, 4) == 0) {
        play_sound_effect(0x68A24, &position, 0, 1);
    }
}

void TBoss6Type1::tick_state_410_timer() {
    if (--action_timer < 0) {
        set_action_state(0x20);
    }
}

void TBoss6Type1::init_move_attack() {
    action_duration = 0x1E;
    action_timer = 0x1E;
    damage_players_in_range();
    play_sound_effect(0x40039C19, &position, 0, 0);
}

void TBoss6Type1::update_hit_timer() {
    play_persistent_sound(0x40032614, this, NULL, 0, 0);
    if ((s32)action_timer == 0x3C) {
        play_sound_effect(0x39403, &position, 0, 1);
    }
    if (action_timer > 0) {
        action_timer--;
        return;
    }
    action_timer = 0;
}

void TBoss6Type1::update_attack_state() {
    if ((s32)action_timer == 0) {
        if (is_field4b0_delta_reached() != 0) {
            send_flow_action_if_idle(this, 0x20);
            return;
        }
        send_flow_action_if_idle(this, 0x1F);
    }
}

void TBoss6Type1::advance_plot_to_state2() {
    action_duration = 0x12C;
    action_timer = 0x12C;
    plot_falz->free_child();
    plot_falz->set_state_2();
    spawn_map_csn();
    play_sound_effect(0x40039C13, &position, 0, 0);
    release_effect_slot(0);
    release_effect_slot(1);
    latch_phase_counter();
}

void TBoss6Type1::update_down_centop() {
    f32 height;

    interpolate_pos_to_target(action_timer, action_duration);
    if ((s32)action_timer == (s32)((f32)action_duration - 10.0f)) {
        attack_mode = 0;
    }
    height = position.y;
    if ((height <= 230.0f) && (height > 228.0f)) {
        set_motion_set(1);
    } else if (action_timer == 0x46) {
        set_motion_set(7);
    } else if (action_timer == 0xF) {
        VecCopy(&target_position.v, &down_centop_land_pos);
    }
    play_persistent_sound(0x4003B012, this, &position, 0, 0);
    if (--action_timer < 0) {
        set_action_state(0x1E);
    }
}

void TBoss6Type1::init_params() {
    spawn_grav_ball();
    action_duration = 300;
    action_timer = 300;
    VecCopy(&target_position.v, &down_centop_pos);
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_phase() {
    interpolate_pos_to_target(action_timer, action_duration);
    if ((--action_timer < 0) && (is_normal_difficulty() == 0)) {
        set_action_state(0x1D);
    }
}

void TBoss6Type1::trigger_falz_phase() {
    if (((s32)action_timer == 0) && (is_normal_difficulty() != 0)) {
        send_ret_rnd();
    }
}

void TBoss6Type1::act_centop_u() {
    action_duration = 0x1E;
    action_timer = 0x1E;
    VecCopy(&target_position.v, &centop_pos);
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::tick_flee_countdown() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(0xF - (random_factor & 1));
    }
}

void TBoss6Type1::act_centop_d() {
    action_duration = 0x1E;
    action_timer = 0x1E;
    VecCopy(&target_position.v, &centop_down_pos);
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_timer_transition() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(0x1B);
    }
}

void TBoss6Type1::init_state() {
    action_duration = 0x3C;
    action_timer = 0x3C;
    VecCopy(&target_position.v, &centop_pos);
    play_sound_effect(0x39403, &node_points[1], 0, 1);
    play_sound_effect(0x4003A811, &position, 0, 1);
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::tick_trap_countdown() {
    play_persistent_sound(0x40038F0F, this, &position, 0, 0);
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::idle_chal_float() {
    if ((((f32)action_timer / (f32)action_duration) < 0.5f) && (check_field4b0_threshold() != 0)) {
        do_attack();
        return;
    }
    if ((s32)action_timer == 0) {
        if (is_raised() != 0) {
            send_flow_action_if_idle(this, 0x1A);
            return;
        }
        send_flow_action_if_idle(this, 0x22);
    }
}

void TBoss6Type1::init_hp_and_state() {
    action_duration = 300;
    action_timer = 300;
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_charge() {
    interpolate_pos_to_target(action_timer, action_duration);
    play_persistent_sound(0x40038F0F, this, &position, 0, 0);
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::start_action_if_idle() {
    if (action_timer == 0) {
        send_flow_action_if_idle(this, 25);
    }
}

void TBoss6Type1::set_phase_90() {
    action_duration = 90;
    action_timer = 90;
    latch_phase_counter();
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_timer() {
    s32 move_start;

    move_start = action_duration - 0xF;
    if (action_timer >= move_start) {
        interpolate_pos_to_target(action_timer - move_start, 0xF);
    }
    set_flag_on_threshold();
    if (--action_timer < 0) {
        latch_phase_counter();
        target_mode = 1;
        set_action_state(1);
    }
}

void TBoss6Type1::act_scream() {
    action_duration = 123;
    action_timer = 123;
    clamp_to_arena_radius(&target_position.v);
    play_sound_effect(231170, 0, 0, 0);
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_fllsr_mv() {
    s32 fire_start;
    s32 fire_end;
    s32 sound;

    fire_start = laser_charge_time + laser_fire_time + 30 - laser_charge_time;
    fire_end = fire_start - laser_fire_time;
    if (action_timer == fire_start) {
        set_motion_set(0x11);
    } else if (action_timer == fire_end) {
        release_effect_slot(2);
        set_motion_set(0x13);
    }
    rotate_around_center(action_timer, action_duration);
    if ((action_timer <= laser_fire_time) && (action_timer >= 0x1E)) {
        increase_field_clamped_max();
        check_laser_hits();
    } else {
        decrease_field_clamped_min();
    }
    if ((s32)action_timer >= 0x1E) {
        sound = 0x4003B50C;
        if (laser_scale > 0.0f) {
            sound = 0x4003AD0D;
        }
        play_persistent_sound(sound, this, &node_points[7], 0, 1);
    }
    if (laser_scale > 0.0f) {
        count_laser_frame();
    } else {
        release_slot_particles();
    }
    if (--action_timer < 0) {
        reset_param();
        set_action_state(1);
    }
}

void TBoss6Type1::act_fllsr_mv() {
    action_timer = action_duration = laser_charge_time + laser_fire_time + 30;
    play_sound_effect(0x4003A608, &node_points[7], 0, 0);
    release_effect_slot(0);
    spawn_effect_slot(1);
    spawn_effect_slot(2);
}

void TBoss6Type1::update_attack_timer2() {
    check_sweep_hits();
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_dice_state() {
    action_duration = 62;
    action_timer = 62;
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::update_sword_ud() {
    s32 state;

    spawn_sword_shots();
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        state = action_state;
        switch (state) {
        case 11:
            set_action_state(0x1C);
            return;
        case 16:
            set_action_state(0x24);
            return;
        default:
            set_action_state(state - 1);
            break;
        }
    }
}

void TBoss6Type1::init_action_timer() {
    s32 state;

    action_duration = 0x3E;
    state = action_state;
    if ((state == 0xB) || (state == 0x10)) {
        action_duration = action_duration + 0x1E;
    }
    action_timer = action_duration;
    calc_grid_cell_position(&target_position.v);
    play_sound_effect(0x40039C21, &node_points[9], 0, 0);
    release_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_sword_mv() {
    s32 state;

    update_beam_attack();
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        state = action_state;
        if (state == 8) {
            set_action_state(1);
            return;
        }
        set_action_state(state - 1);
    }
}

void TBoss6Type1::init_attack_timer() {
    action_duration = 0x3E;
    if ((s32)action_state == 8) {
        action_duration = action_duration + 0x1E;
    }
    action_timer = action_duration;
    pick_sword_move_target(&target_position.v);
    play_sound_effect(0x4003BF07, &node_points[9], 0, 0);
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::update_timer_state() {
    s32 state;

    update_beam_attack();
    if (--action_timer < 0) {
        state = action_state;
        if (state == 5) {
            set_action_state(1);
            return;
        }
        set_action_state(state - 1);
    }
}

void TBoss6Type1::set_phase_timer_3E() {
    action_duration = 0x3E;
    if ((s32)action_state == 5) {
        action_duration = action_duration + 0x1E;
    }
    action_timer = action_duration;
    action_duration = 0x3E;
    action_timer = 0x3E;
    play_sound_effect(0x4003BF07, &node_points[9], 0, 0);
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_action_timer() {
    interpolate_pos_to_target(action_timer, action_duration);
    switch (action_timer) {
    case 0x48:
    case 0x3E:
    case 0x52:
        fire_kakusan_shots();
        break;
    }
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_hp_state() {
    action_duration = 90;
    action_timer = 90;
    release_effect_slot(0);
    spawn_effect_slot(1);
}

void TBoss6Type1::update_kakusan() {
    if ((s32)action_timer == 0x3E) {
        fire_kakusan_shots();
    }
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_state_90() {
    action_duration = 90;
    action_timer = 90;
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_attack_countdown_reset() {
    interpolate_pos_to_target(action_timer, action_duration);
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::start_attack() {
    if ((s32)target_mode == 0) {
        action_duration = 0x1E;
        action_timer = 0x1E;
    } else {
        action_duration = 0x1E;
        action_timer = 0x1E;
    }
    play_sound_effect(0x40039706, &position, 0, 0);
    release_effect_slot(0);
    spawn_effect_slot(1);
    if (count_matches(0x19, 4) > 0) {
        latch_phase_counter();
        play_sound_effect(0x68A24, &position, 0, 1);
    }
}

void TBoss6Type1::tick_countdown() {
    if (--action_timer < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::choose_next_action() {
    if ((s32)action_timer == 0) {
        if ((s32)target_mode == 0) {
            if (is_ready() != 0) {
                send_flow_action_if_idle(this, 0x17);
                return;
            }
            if (count_matches(2, 0x10) == 0) {
                do_attack();
                return;
            }
            if (((count_matches(3, 0xA) + count_matches(5, 0xA)) == 0) || (((1.0f / 32768.0f) * (f32)rand()) < 0.4f)) {
                choose_attack();
                return;
            }
            do_attack();
            return;
        }
        if (is_time_up() != 0) {
            send_chal_ud();
            return;
        }
        choose_attack();
    }
}

void TBoss6Type1::init_attack_timers() {
    if ((s32)target_mode == 0) {
        action_duration = 0x5A;
        action_timer = 0x5A;
    } else if ((s32)low_hp_flag != 0) {
        action_timer = action_duration = low_hp_float_time;
    } else {
        action_timer = action_duration = float_time;
    }
    spawn_effect_slot(0);
    release_effect_slot(1);
}

void TBoss6Type1::update_appear() {
    if ((s32)action_timer < 0x1E) {
        update_appear_position(action_timer, 0x1E);
    }
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_effect_slot_1() {
    VecCopy(&target_position.v, &boss6_type1_base_position);
    action_duration = 0x5A;
    action_timer = 0x5A;
    spawn_effect_slot(1);
}
