#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/Boss6Type2Data.h"
#include "pso/boss/olgaflow/TBoss6Type2BattleAction.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/player/PlayerSlots.h"

// TBoss6Type2 state handlers and their state-action table (one TU: the table's
// strings and "DPB" lead this TU's .rodata and .sdata2, its __sinit ends the .text).
// Built with -inline off,deferred, so the functions are written last-to-first: the
// function-local statics' .sbss slots run backwards against the code, which only the
// deferred build of a reversed source gives.
//
// 36 rows of {name, s32, s32, enter / idle / update handler}. The handlers are pointers
// to members, so CodeWarrior builds the table in __sinit from a per-handler template
// (the 97 0xC objects at 0x804DFC50).
TBoss6Type2BattleAction boss6_type2_battle_actions[36] = {
    { "WAIT", 0, 1, &TBoss6Type2::act_wait, &TBoss6Type2::select_attack_state, &TBoss6Type2::tick_timer_460 },
    { "INFO_STAT", 4, 1, &TBoss6Type2::reset_state_timers, 0, &TBoss6Type2::update_info_stat },
    { "SEARCH", 1, 1, &TBoss6Type2::init_timer_and_play_sound, &TBoss6Type2::pick_next_zako, &TBoss6Type2::tick_action_timer },
    { "NIRAMU", 0, 1, &TBoss6Type2::act_niramu, &TBoss6Type2::check_state_0x460_eq0, &TBoss6Type2::update_niramu },
    { "WALK_CMN", 2, 1, &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase },
    { "WALK_DEF", 3, 1, &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase },
    { "WALK_CMNx1", 2, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "WALK_CMNx2", 2, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "WALK_CMNx3", 2, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "WALK_DEFx1", 3, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "WALK_DEFx2", 3, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "WALK_DEFx3", 3, 1, &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer },
    { "KAMAE", 4, 1, &TBoss6Type2::start_death_sequence, &TBoss6Type2::update_when_timer_zero, &TBoss6Type2::update_timer },
    { "BKJUMP", 6, 1, &TBoss6Type2::init_timers_and_copy_pos, &TBoss6Type2::idle_bkjump, &TBoss6Type2::update_death_sequence },
    { "DPB", 7, 0, &TBoss6Type2::init_attack_timers, &TBoss6Type2::update_state_34, &TBoss6Type2::update_attack_sequence },
    { "IAI_L", 9, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_R", 8, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_F", 10, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_L2", 9, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_R2", 8, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_F2", 10, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_L3", 9, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_R3", 8, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "IAI_F3", 10, 1, &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::update_iai },
    { "CHG_TO_BSK", 11, 0, &TBoss6Type2::spawn_death_soul, 0, &TBoss6Type2::update_chg_to_bsk },
    { "BSK_AGAIN", 11, 0, &TBoss6Type2::act_bsk_again, 0, &TBoss6Type2::update_attack_timer },
    { "CHG_TO_CMN", 12, 0, &TBoss6Type2::start_flow_soul_effect, 0, &TBoss6Type2::update_charge_timer },
    { "B_WAIT", 13, 1, &TBoss6Type2::init_speed_from_ratio, &TBoss6Type2::select_next_state, &TBoss6Type2::tick_timer_0x460 },
    { "B_BJ_WAIT", 13, 1, &TBoss6Type2::act_b_bj_wait, &TBoss6Type2::update_rock_spawn_state, &TBoss6Type2::tick_timer_0x460 },
    { "B_WALKx1", 14, 1, &TBoss6Type2::act_b_walk, &TBoss6Type2::idle_b_walk, &TBoss6Type2::update_zako_timer },
    { "B_WALKx2", 14, 1, &TBoss6Type2::act_b_walk, &TBoss6Type2::idle_b_walk, &TBoss6Type2::update_zako_timer },
    { "B_WALKx3", 14, 1, &TBoss6Type2::act_b_walk, &TBoss6Type2::idle_b_walk, &TBoss6Type2::update_zako_timer },
    { "B_WALKx4", 14, 1, &TBoss6Type2::act_b_walk, &TBoss6Type2::idle_b_walk, &TBoss6Type2::update_zako_timer },
    { "B_WALKx5", 14, 1, &TBoss6Type2::act_b_walk, &TBoss6Type2::idle_b_walk, &TBoss6Type2::update_zako_timer },
    { "WAITNEXT", -1, 0, 0, &TBoss6Type2::select_action, 0 },
    { "DEAD", -1, 0, 0, 0, 0 },
};




void TBoss6Type2::act_wait() { state_duration = 90; state_timer = 90; }

void TBoss6Type2::select_attack_state() {
    if ((s32) state_timer == 0) {
        if (should_back_jump() != 0) {
            send_action_packet(0xD);
            return;
        }
        if ((get_phase() == 0xD) && (is_ready_to_attack() != 0)) {
            possess_target = is_falz_ready();
            send_action_packet(0x18);
            return;
        }
        if (should_use_dpb() != 0) {
            send_action_packet(0xE);
            return;
        }
        if (get_phase() == 0xD) {
            target_mode = pick_random_other_index();
            target_state = choose_next_index();
            send_action_packet(1);
            return;
        }
        send_action_packet(2);
    }
}

void TBoss6Type2::tick_timer_460() {
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::reset_state_timers() {
    s32 duration = info_stat_duration;
    state_duration = duration;
    state_timer = duration;
    call_mags_to_shoulders();
}

void TBoss6Type2::update_info_stat() {
    play_persistent_sound(0x4006A612, this, &position, 0, 1);
    if (--state_timer < 0) {
        play_sound_effect(0x40069E13, &position, 0, 1);
        set_action_state(2);
    }
}

void TBoss6Type2::init_timer_and_play_sound() {
    static s32 dur = (s32)(30.0f / boss6_type2_search_speed);
    state_timer = (state_duration = dur);
    play_sound_effect(0x69126, &position, 0, 1);
}

void TBoss6Type2::pick_next_zako() {
    if ((s32) state_timer == 0) {
        target_client = pick_target_client();
        if (target_client == 0xFFFF) {
            update_action_state();
            return;
        }
        send_action_packet(3);
    }
}

void TBoss6Type2::tick_action_timer() {
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::act_niramu() { state_duration = 45; state_timer = 45; }

void TBoss6Type2::check_state_0x460_eq0() { if (state_timer == 0) { send_state_action_packet(); } }

void TBoss6Type2::update_niramu() {
    if ((state_timer == state_duration - 0x1E) && (target_client != 0xFFFF)) {
        play_sound_effect(0x4006A10A, &position, 0, 1);
        play_sound_effect(0x69E27, &position, 0, 1);
        spawn_particle_effect_with_flags(&node_positions[12], 0x223, 0x40);
    }
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::init_attack_params() {

    state_duration = 0x4B;
    state_timer = 0x4B;
    turn_done = 0;
    switch (action_state) {
    case 4:
        last_walk_def = 0;
        break;
    case 5:
        last_walk_def = 1;
        break;
    default:
        last_walk_def = 0;
        break;
    }
    release_mags();
    switch ((s32) action_state) {
    case 5:
        spawn_particle_slot(0xD);
        break;
    }
}

void TBoss6Type2::update_zako_phase() {
    if (((s32) turn_done == 0) && (turn_toward_target_position() == 0)) {
        turn_done = 1;
    }
    update_zako();
    if (--state_timer < 0) {
        set_action_state(0xC);
    }
}

void TBoss6Type2::reset_timers_and_spawn_particle() {
    state_duration = 0x4B;
    state_timer = 0x4B;
    turn_done = 0;
    release_mags();
    switch (action_state) {
    case 9:
    case 10:
    case 11:
        spawn_particle_slot(0xD);
        break;
    }
}

void TBoss6Type2::send_state_action() {
    if ((s32) state_timer == 0) {
        switch (action_state) {
        case 6:
            last_walk_def = 0;
            send_action_packet(0xC);
            return;
        case 9:
            last_walk_def = 1;
            send_action_packet(0xC);
            return;
        default:
            send_state_action_packet();
            break;
        }
    }
}

void TBoss6Type2::update_zako_spawn_timer() {
    if (((s32) turn_done == 0) && (turn_toward_target_position() == 0)) {
        turn_done = 1;
    }
    update_zako();
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::start_death_sequence() {
    s32 sound;
    s32 duration = kamae_duration;
    state_duration = duration;
    state_timer = duration;
    switch (next_motion) {
    case 15:
        sound = 0x68522;
        break;
    case 16:
        sound = 0x68521;
        break;
    case 17:
        sound = 0x68523;
        break;
    }
    play_sound_effect(sound, &position, 0, 1);
    destroy_part(0xD);
}

void TBoss6Type2::update_when_timer_zero() { if (state_timer == 0) { send_action_packet(next_motion); } }

void TBoss6Type2::update_timer() {
    if ((s32) state_timer == (s32) (state_duration - 7)) {
        play_sound_effect(0x4006A604, &position, 0, 0);
    }
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::init_timers_and_copy_pos() {
    static s32 dur = (s32)(15.0f + (30.0f / boss6_type2_bkjump_speed));
    state_timer = (state_duration = (s32) dur);
    VecCopy(&move_origin, &position);
    iai_count = 0;
    if ((s32) berserk == 0) {
        call_mags_to_shoulders();
    }
}

void TBoss6Type2::idle_bkjump() { if (state_timer == 45) { drop_random_rocks(0); } }

void TBoss6Type2::update_death_sequence() {
    s32 d;
    move_to_arena_center(state_timer, state_duration);
    d = state_duration;
    s32 d16 = d - 0x16;
    if (state_timer == d - 7) {
        play_sound_effect(0x4006A601, &position, 0, 0);
    }
    if (state_timer == d16) {
        play_sound_effect(0x40069E03, &position, 0, 1);
    }
    trigger_screen_pos();
    switch (state_timer) {
    case 0x2D:
    case 0x37:
    case 0x41:
        spawn_particle_effect_with_flags(&position, 0x221, 0x40);
        spawn_particle_effect_with_flags(&position, 0x22F, 0x40);
        break;
    }
    if (state_timer == 0x41) {
        TCameraCtrl::set_shake_preset(1);
    }
    if (--state_timer < 0) {
        if ((s32) berserk != 0) {
            set_action_state(0x1C);
        } else {
            set_action_state(0);
        }
    }
}

void TBoss6Type2::init_attack_timers() {
    state_duration = 0xB4;
    state_timer = 0xB4;
    play_sound_effect(0x4006970E, &position, 0, 1);
    if ((s32) berserk == 0) {
        release_mags();
        return;
    }
    call_mags_to_shoulders();
}

void TBoss6Type2::update_state_34() { if (state_timer == 34) { drop_random_rocks(0); } }

void TBoss6Type2::update_attack_sequence() {
    if ((s32) state_timer == (s32) (state_duration - 0x3C)) {
        play_sound_effect(0x69C0F, &position, 0, 1);
    }
    if ((s32) state_timer == (s32) (state_duration - 0x78)) {
        create_dpbs();
    }
    switch (state_timer) {
    case 0xA0:
        spawn_particle_slot(8);
        spawn_particle_slot(9);
        spawn_particle_slot(0xA);
        break;
    case 0x50:
        destroy_part(8);
        destroy_part(9);
        destroy_part(0xA);
        break;
    case 0x82:
        spawn_particle_slot(0xB);
        spawn_particle_slot(0xC);
        break;
    case 0x49:
        destroy_part(0xB);
        destroy_part(0xC);
        break;
    }
    if ((s32) state_timer == 0x36) {
        TCameraCtrl::set_shake_preset(1);
    }
    if (--state_timer < 0) {
        reset_attack_counter();
        if ((s32) berserk != 0) {
            set_action_state(0x1B);
            return;
        }
        set_action_state(0);
    }
}

void TBoss6Type2::init_timer() {
    static s32 dur = (s32)(30.0f / boss6_type2_iai_speed);
    s32 duration = dur;
    state_duration = duration;
    state_timer = duration;
    iai_count++;
}

void TBoss6Type2::check_state_0x460_eq4() { if (state_timer == 4) { drop_random_rocks(0); } }

void TBoss6Type2::update_iai() {
    s32 sound;
    s32 n;
    saddr idx;
    s32 grp;
    static s32 swing_sound_time = (s32)(10.0f / boss6_type2_iai_speed - 10.0f);
    if (state_timer == state_duration - swing_sound_time) {
        sound = 0x40069C05;
        switch ((s32) action_state) {
        case 17:
        case 20:
        case 23:
            sound = 0x40069C06;
            break;
        }
        play_sound_effect(sound, &position, 0, 0);
    }
    static s32 hit_time = (s32)(10.0f / boss6_type2_iai_speed);
    if (state_timer == state_duration - hit_time) {
        switch ((s32) action_state) {
        case 17:
        case 20:
        case 23:
            play_sound_effect(0x40069C07, &position, 0, 0);
            break;
        }
        spawn_sword_wave();
    }
    if (state_timer == 24) {
        TCameraCtrl::set_shake_preset(1);
    }
    if (--state_timer < 0) {
        switch ((s32) action_state) {
        case 15:
        case 16:
        case 17:
            if ((s32) berserk != 0) {
                set_action_state(27);
            } else {
                set_action_state(0);
            }
            break;
        default:
            n = (s32) action_state - 15;
            grp = n / 3;
            idx = n % 3;
            idx = ((random_factor & 1) + idx);
            idx = (idx + 1) % 3;
            set_action_state((idx + ((grp - 1) * 3) + 15));
            break;
        }
    }
}

void TBoss6Type2::spawn_death_soul() {
    static s32 dur = (s32)(60.0f / boss6_type2_bsk_speed);
    s32 duration = dur;
    state_duration = duration;
    state_timer = duration;
    berserk_wait_count = 0;
    play_sound_effect(0x68A25, &position, 0, 1);
    spawn_particle_slot(6);
    call_mags_to_shoulders();
    if (possess_target != 0xFFFF) {
        create_flow_soul(this, &node_positions[11], possess_target, state_duration);
        TBoss6EffHyoui::create(possess_target, 0, state_duration);
    }
}

void TBoss6Type2::update_chg_to_bsk() {
    f32 ratio;
    TObjPlayer *player;
    state_progress = (f32) (1.0f - ((f32) state_timer / (f32) state_duration));
    ratio = state_progress;
    if (ratio < 0.0f) {
        state_progress = 0.0f;
    } else if (ratio > 1.0f) {
        state_progress = 1.0f;
    }
    play_persistent_sound(0x4006A30B, this, &position, 0, 1);
    if (--state_timer < 0) {
        berserk = 1;
        state_progress = 1.0f;
        if (check_target() != 0) {
            if (is_target_valid() == 0) {
                play_sound_effect(0x40069E13, &position, 0, 1);
            }
            player = get_player_by_client_id(possessed_client);
            if (player != NULL) {
                spawn_particle_effect(&player->position, 0x36);
            }
        }
        copy_anim_state();
        destroy_part(6);
        set_action_state(0x1B);
    }
}

void TBoss6Type2::act_bsk_again() {
    static s32 dur = (s32)(60.0f / boss6_type2_bsk_speed);
    s32 duration = dur;
    state_duration = duration;
    state_timer = duration;
    play_sound_effect(0x68A25, &position, 0, 1);
    call_mags_to_shoulders();
    if (possess_target != 0xFFFF) {
        create_flow_soul(this, &node_positions[11], possess_target, state_duration);
        TBoss6EffHyoui::create(possess_target, 0, state_duration);
    }
}

void TBoss6Type2::update_attack_timer() {
    TObjPlayer *player;

    play_persistent_sound(0x4006A30B, this, &position, 0, 1);
    if (--state_timer < 0) {
        if (check_target() != 0) {
            if (is_target_valid() == 0) {
                play_sound_effect(0x40069E13, &position, 0, 1);
            }
            player = get_player_by_client_id(possessed_client);
            if (player != NULL) {
                spawn_particle_effect(&player->position, 0x36);
            }
        }
        set_action_state(0x1B);
    }
}

void TBoss6Type2::start_flow_soul_effect() {
    static s32 dur = (s32)(60.0f / boss6_type2_chg_to_cmn_speed);
    Vec v;
    TObjPlayer *player;
    s32 duration = dur;
    state_duration = duration;
    state_timer = duration;
    play_sound_effect(0x68A25, &position, 0, 1);
    spawn_particle_slot(7);
    call_mags_to_shoulders();
    if (possessed_client != 0xFFFF) {
        player = get_player_by_client_id(possessed_client);
        if (player != NULL) {
            VecCopy(&v, &player->position);
            v.y += 10.0f;
            spawn_flow_soul(this, &v, state_duration);
            spawn_particle_effect(&player->position, 0x36);
        }
        TBoss6EffHyoui::create(possessed_client, 1, state_duration);
        if (is_target_valid() == 0) {
            play_sound_effect(0x40069E13, &position, 0, 1);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::update_charge_timer() {
    f32 progress;
    state_progress = (f32)state_timer / (f32)state_duration;
    progress = state_progress;
    if (progress < 0.0f) {
        state_progress = 0.0f;
    } else if (progress > 1.0f) {
        state_progress = 1.0f;
    }
    play_persistent_sound(0x4006A30B, this, NULL, 0, 0);
    if (--state_timer < 0) {
        berserk = 0;
        state_progress = 0.0f;
        copy_anim_state();
        destroy_part(7);
        set_action_state(0);
    }
}
#pragma pop

void TBoss6Type2::init_speed_from_ratio() {
    static s32 speed_from_ratio = (s32)(30.0f / boss6_type2_b_wait_speed);
    s32 duration = speed_from_ratio;
    state_duration = duration;
    state_timer = duration;
    berserk_wait_count++;
}

void TBoss6Type2::select_next_state() {
    u16 client;

    if ((s32) state_timer == 0) {
        if (get_phase() == 0xD) {
            if (is_phase_complete() != 0) {
                send_action_packet(0x1A);
                return;
            }
            if (possessed_client == 0xFFFF) {
                client = is_falz_ready();
                if (client != 0xFFFF) {
                    possess_target = client;
                    send_action_packet(0x19);
                    return;
                }
            }
            goto block_7;
        }
block_7:
        if (should_back_jump() != 0) {
            send_action_packet(0xD);
            return;
        }
        if (should_use_dpb() != 0) {
            send_action_packet(0xE);
            return;
        }
        update_attack_target();
    }
}

void TBoss6Type2::tick_timer_0x460() {
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::act_b_bj_wait() {
    s32 duration = bj_wait_duration;
    state_duration = duration;
    state_timer = duration;
    berserk_wait_count++;
}

void TBoss6Type2::update_rock_spawn_state() {
    s32 d = state_duration - state_timer;
    if (state_timer >= 0x1E && d % 30 == 0) {
        spawn_rocks_around_players();
        TCameraCtrl::set_shake_preset(1);
    }
    select_next_state();
}

void TBoss6Type2::act_b_walk() {
    state_duration = 0x4B;
    state_timer = 0x4B;
    turn_done = 0;
    call_mags_to_shoulders();
}

void TBoss6Type2::idle_b_walk() {
    if (state_timer == 0) {
        if ((s32) action_state == 0x1D) {
            send_action_packet(choose_random_motion());
            return;
        }
        update_attack_target();
    }
}

void TBoss6Type2::update_zako_timer() {
    if (((s32) turn_done == 0) && (turn_toward_target_position() == 0)) {
        turn_done = 1;
    }
    update_zako();
    if (--state_timer < 0) {
        set_action_state(0x22);
    }
}

void TBoss6Type2::select_action() {
    if (actorFlags & 0x800) {
        send_action_packet(0x23);
        return;
    }
    if ((s32) berserk != 0) {
        send_action_packet(0x1B);
        return;
    }
    send_action_packet(0);
}
