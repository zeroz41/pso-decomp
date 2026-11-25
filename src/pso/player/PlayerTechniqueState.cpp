#include "types.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/TObjPlayer.h"

void PlayerTechniqueState::set_tech_level(s16 count) {
    s16 clamped;

    clamped = count;
    if ((clamped < 0) || (clamped > 0xA)) {
        clamped = 0;
    }
    target_count = clamped;
}

void PlayerTechniqueState::set_all_technique_levels(u8 level) {
    s32 i;
    s32 n = technique_count();
    for (i = 0; i < n; i++) {
        set_learned_level(i, level);
    }
}

void PlayerTechniqueState::copy_all_technique_entries(u8 level) {
    s32 i;
    s32 n = technique_count();
    for (i = 0; i < n; i++) {
        set_technique_cap(i, level);
    }
}

u8 PlayerTechniqueState::get_effective_technique_level(s16 technique) {
    u8 level = caps[technique];
    u8 cap = get_technique_level(technique);
    return clamp_to_max(level, cap);
}

void PlayerTechniqueState::set_technique_cap(s16 technique, u8 level) {
    u8 cap = get_technique_level(technique);
    caps[technique] = clamp_to_max(level, cap);
}

void PlayerTechniqueState::reset_slots() {
    s32 i;

    target_count = 0;
    for (i = 0; i < 10; i++) {
        set_target(i, 0xFFFF, 0);
    }
}

void PlayerTechniqueState::reset_all_tech_slots() {
    s32 i = 0;
    do {
        clear_technique_level(i);
        i++;
    } while (i < 0x13);
}

void PlayerTechniqueState::reset_tech_state() {
    s32 n;
    u8 v;
    s32 i;
    n = technique_count();
    v = TObjPlayer::get_item_count_max();
    for (i = 0; i < n; i++) {
        levels[i] = v;
        caps[i] = v;
    }
    set_level(0xFF);
    set_tech_override(0);
    set_technique_id(0);
    set_tech_level(0);
    TObjPlayer__sub_801D9E10(this, 0);
    set_technique_state(0);
    set_charge_step(0.0f);
    set_field18(0.0f);
    set_field_1c(1.5f);
    reset_all_tech_slots();
    reset_slots();
    pad_a = 0;
    pad_3 = 0;
    pad_2 = 0;
}

s32 PlayerTechniqueState::technique_count() {
    return 19;
}

void TObjPlayer__sub_801D9E10(PlayerTechniqueState *techs, s16 value) {
    techs->pad_8 = value;
}

PhotonBlastTarget *PlayerTechniqueState::get_target(s32 slot) {
    return &targets[slot];
}

void PlayerTechniqueState::clear_technique_level(s16 technique) {
    learned_levels[technique] = 0xFF;
}

void PlayerTechniqueState::set_field_1c(f32 v) { pad_1c = v; }
void PlayerTechniqueState::set_field18(f32 v) { pad_18 = v; }
