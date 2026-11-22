#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/system/SoundEffect.h"

void TBoss6Mag::update_revival() {
    fade += -1.0f / 30.0f;
    if (fade < 0.0f) {
        fade = 0.0f;
    }
    action_timer = (action_timer + 1);
    if (action_timer >= 0x5A) {
        revive();
        if (chase_target.on_shoulder != 0) {
            set_action(1);
            return;
        }
        set_action(2);
    }
}

void TBoss6Mag::act_revival() { action_timer = 0; play_sound_effect(438292, &position, 0, 0); destroy_part_object(0); }

void TBoss6Mag::update_dead() {
    fade += 1.0f / 30.0f;
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    action_timer = (action_timer + 1);
    if (action_timer >= dead_duration) {
        set_action(5);
    }
}

void TBoss6Mag::act_dead() { action_timer = 0; ensure_particle_emitter(0); }
void TBoss6Mag::update_shoot() {
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

void TBoss6Mag::act_shoot() {
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

void TBoss6Mag::update_chase_pl() {
    turn_toward_target();
    apply_random_drift();
    push_out_from_target();
    push_out_from_points();
    enforce_min_distance();
    if (chase_target.on_shoulder != 0) {
        set_action(1);
    }
}
void TBoss6Mag::act_chase_pl() {  }
void TBoss6Mag::update_set_shoulder() {
    fly_toward_target();
    push_out_from_target();
    enforce_min_distance();
    if (chase_target.on_shoulder == 0) {
        set_action(2);
    }
}
void TBoss6Mag::act_set_shoulder() {  }
void TBoss6Mag::update_start() {
    snap_to_shoulder();
    action_timer = (action_timer + 1);
    if (action_timer >= 4) {
        set_action(1);
    }
}
void TBoss6Mag::act_start() { action_timer = 0; }

TBoss6MagAction boss6_type2_action_table[6] = {
    {"START", 0, 1, &TBoss6Mag::act_start, &TBoss6Mag::update_start},
    {"SET_SHOLDER", 0, 0, &TBoss6Mag::act_set_shoulder, &TBoss6Mag::update_set_shoulder},
    {"CHASE_PL", 0, 1, &TBoss6Mag::act_chase_pl, &TBoss6Mag::update_chase_pl},
    {"SHOOT", 1, 1, &TBoss6Mag::act_shoot, &TBoss6Mag::update_shoot},
    {"DEAD", 2, 0, &TBoss6Mag::act_dead, &TBoss6Mag::update_dead},
    {"REVIVAL", 4, 0, &TBoss6Mag::act_revival, &TBoss6Mag::update_revival},
};
