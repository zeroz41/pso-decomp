#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/system/SoundEffect.h"

void TBoss6Mag::update_recover_timer() {
    fade += -1.0f / 30.0f;
    if (fade < 0.0f) {
        fade = 0.0f;
    }
    action_timer = (action_timer + 1);
    if (action_timer >= 0x5A) {
        sub_8032F5C4();
        if (chase_target.on_shoulder != 0) {
            set_action(1);
            return;
        }
        set_action(2);
    }
}

void TBoss6Mag::sub_80336F00() { action_timer = 0; play_sound_effect(438292, &position, 0, 0); destroy_part_object(0); }

void TBoss6Mag::update_ramp_timer() {
    fade += 1.0f / 30.0f;
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    action_timer = (action_timer + 1);
    if (action_timer >= dead_duration) {
        set_action(5);
    }
}

void TBoss6Mag::sub_80336FB8() { action_timer = 0; ensure_particle_emitter(0); }
void TBoss6Mag::tick_attack_timer() {
    action_timer = (action_timer - 1);
    if (action_timer < 0) {
        destroy_part_object(3);
        if (chase_target.on_shoulder != 0) {
            set_action(1);
            return;
        }
        set_action(2);
    }
}

void TBoss6Mag::start_mag_mines_state() {
    action_timer = 0x25;
    switch (mines_spawned) {
    case 0:
        spawn_mag_mines();
        break;
    default:
        break;
    }
    ensure_particle_emitter(3);
}

void TBoss6Mag::update_effect_subsystems() {
    turn_toward_target();
    apply_random_drift();
    push_out_from_target();
    push_out_from_points();
    enforce_min_distance();
    if (chase_target.on_shoulder != 0) {
        set_action(1);
    }
}
void TBoss6Mag::sub_80337108() {  }
void TBoss6Mag::update_attack_state() {
    fly_toward_target();
    push_out_from_target();
    enforce_min_distance();
    if (chase_target.on_shoulder == 0) {
        set_action(2);
    }
}
void TBoss6Mag::sub_80337160() {  }
void TBoss6Mag::advance_phase_counter() {
    sub_8032FB84();
    action_timer = (action_timer + 1);
    if (action_timer >= 4) {
        set_action(1);
    }
}
void TBoss6Mag::sub_803371B4() { action_timer = 0; }

TBoss6MagAction boss6_type2_action_table[6] = {
    {"START", 0, 1, &TBoss6Mag::sub_803371B4, &TBoss6Mag::advance_phase_counter},
    {"SET_SHOLDER", 0, 0, &TBoss6Mag::sub_80337160, &TBoss6Mag::update_attack_state},
    {"CHASE_PL", 0, 1, &TBoss6Mag::sub_80337108, &TBoss6Mag::update_effect_subsystems},
    {"SHOOT", 1, 1, &TBoss6Mag::start_mag_mines_state, &TBoss6Mag::tick_attack_timer},
    {"DEAD", 2, 0, &TBoss6Mag::sub_80336FB8, &TBoss6Mag::update_ramp_timer},
    {"REVIVAL", 4, 0, &TBoss6Mag::sub_80336F00, &TBoss6Mag::update_recover_timer},
};
