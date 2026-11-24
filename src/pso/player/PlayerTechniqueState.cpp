#include "types.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void set_slot_type_state__10TObjPlayerFllls(void *techs, s32 slot, s32 entity_id, s16 index);
u8 TObjPlayer__sub_801C010C(void *techs, s16 technique);
void TObjPlayer__sub_801D2CC4(void *techs, f32 value);
void set_technique_level_entry(void *techs, s16 technique, void *level);
u8 clamp_to_max__10TObjPlayerFlUcUc(s32 techs, u8 level, u8 max);
void TObjPlayer__sub_801D9C34(PlayerTechniqueState *techs, s16 technique, void *level);
u8 get_effective_technique_level__10TObjPlayerFPvs(PlayerTechniqueState *techs, s16 technique);
}

void PlayerTechniqueState::set_tech_level(s16 count) {
    s16 clamped;

    clamped = count;
    if ((clamped < 0) || (clamped > 0xA)) {
        clamped = 0;
    }
    target_count = clamped;
}

void TObjPlayer::set_all_technique_levels(void *level) {
    s32 i;
    s32 n = PlayerTechniqueState::technique_count();
    for (i = 0; i < n; i++) {
        set_technique_level_entry(this, i, level);
    }
}

void TObjPlayer::copy_all_technique_entries(void *level) {
    s32 i;
    s32 n = PlayerTechniqueState::technique_count();
    for (i = 0; i < n; i++) {
        TObjPlayer__sub_801D9C34((PlayerTechniqueState *)this, (s16)i, level);
    }
}

u8 get_effective_technique_level__10TObjPlayerFPvs(PlayerTechniqueState *techs, s16 technique) {
    u8 level = techs->caps[technique];
    u8 cap = TObjPlayer__sub_801C010C(techs, technique);
    return TObjPlayer::clamp_to_max((saddr)techs, level, cap);
}

void TObjPlayer__sub_801D9C34(PlayerTechniqueState *techs, s16 technique, void *level) {
    u8 cap = TObjPlayer__sub_801C010C(techs, technique);
    techs->caps[technique] =
        ((u8 (*)(s32, void *, u8))clamp_to_max__10TObjPlayerFlUcUc)((saddr)techs, level, cap);
}

void PlayerTechniqueState::reset_slots() {
    s32 i;

    target_count = 0;
    for (i = 0; i < 10; i++) {
        set_slot_type_state__10TObjPlayerFllls(this, i, 65535, 0);
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
    TObjPlayer__sub_801D2CC4(this, 0.0f);
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
    *(s16 *)techs->pad_8 = value;
}

PhotonBlastTarget *PlayerTechniqueState::get_target(s32 slot) {
    return &targets[slot];
}

void PlayerTechniqueState::clear_technique_level(s16 technique) {
    pad_48[technique] = 0xFF;
}

void PlayerTechniqueState::set_field_1c(f32 v) { pad_1c = v; }
void PlayerTechniqueState::set_field18(f32 v) { pad_18 = v; }
