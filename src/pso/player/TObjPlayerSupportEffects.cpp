#include "types.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecCtrl.h"

extern "C" {
s32 TObjPlayer__sub_801AF868(TObjPlayer *player);
s32 check_flag_800000__10TObjPlayerFPv(TObjPlayer *player);
void emit_idle_water_effect(PlayerFollowParticles *particles);
}

s32 TObjPlayer::get_card_window_field_244() {
    return *(s32 *)((s8 *)(get_character_save_record((this->get_entity_id()))) + 0x244);
}

void TObjPlayer::init_local_pad_binding() {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        pad_binding.init(get_entity_id(), controller_port);
    }
}

void TObjPlayer::stop_force_if_alive() {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        pad_binding.set_controller(NULL);
    }
}

void TObjPlayer::update_battle_control_if_unlocked() {
    if (is_body_collision_inactive() == 0) {
        follow_particles.prepare_heavy_attack_particles_default();
    }
}

// The support-technique effects: none while the body is inactive or flag 0x800000 is set.
void TObjPlayer::enemy_spawn_zalure_effect() {
    if (is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv(this) != 0) {
        return;
    }
    follow_particles.emit_zalure_support();
}

void TObjPlayer::trigger_switch_attack() {
    if (is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv(this) != 0) {
        return;
    }
    follow_particles.emit_deband_support();
}

void TObjPlayer::enemy_spawn_jellen_effect() {
    if (is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv(this) != 0) {
        return;
    }
    follow_particles.emit_jellen_support_effect_default();
}

void TObjPlayer::apply_switch_attack() {
    if (is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv(this) != 0) {
        return;
    }
    follow_particles.emit_shifta_support();
}

void TObjPlayer::update_movement_effects() {
    if (TTecCtrl::is_technique_ready() != 0 && TObjPlayer__sub_801AF868(this) == 0 && update_movement_by_screen() != 0 &&
        test_action_mask(0x408000) == 0 && is_body_collision_inactive() == 0 &&
        check_flag_800000__10TObjPlayerFPv(this) == 0) {
        follow_particles.emit_movement_effect();
    }
    if (is_body_collision_inactive() == 0 && test_action_mask(2) != 0 && contact_surface.has_water_ground_flag() != 0) {
        emit_idle_water_effect(&follow_particles);
    }
}

int TObjPlayer::get_max_level() { return 199; }
