#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerTechniqueState.h"

extern "C" {
u8 get_cast_technique_level(PlayerTechniqueState *techs, s16 technique);
}

s16 PlayerTechniqueState::get_section_clamped() {
    s16 section;

    section = this->target_count;
    if ((section < 0) || (section > 0xA)) {
        this->target_count = 0;
    }
    return this->target_count;
}

s16 PlayerTechniqueState::get_technique_id() {
    if (is_valid_technique_id(technique) == 0) {
        set_technique_id((s16)0);
    }
    return technique;
}

void TObjPlayer::split_capped_value(u8 level, u8 *capped, u8 *overflow) {
    if ((TObjPlayer::is_invalid_slot(level) != 0) || (level <= 0xEU)) {
        *capped = level;
        *overflow = 0;
        return;
    }
    *capped = 0xE;
    *overflow = level - 0xE;
}

u8 PlayerTechniqueState::get_valid_technique() {
    u8 technique;

    technique = this->level_override;
    if (TObjPlayer::is_valid_technique_slot(technique) == 0) {
        technique = 0;
    }
    return technique;
}

u8 PlayerTechniqueState::get_castable_technique_level() {
    u8 level = this->level;
    u8 cap;
    if (check_technique_level(technique, level) == 0) {
        level = 0x1D;
    }
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return level;
    }
    cap = get_effective_technique_level(technique);
    if (TObjPlayer::is_invalid_slot(cap) != 0) {
        return get_item_count_max();
    }
    if (level > cap) {
        level = cap;
    }
    return level;
}

void PlayerTechniqueState::set_learned_technique_levels(u8 level) {
    s32 i;

    i = 0;
    do {
        if (TObjPlayer::is_invalid_slot(get_cast_technique_level(this, i)) == 0) {
            set_learned_level(i, level);
        }
        i += 1;
    } while (i < 0x13);
}

void PlayerTechniqueState::level_up_all_techniques(u8 add) {
    s32 i = 0;
    do {
        u8 level = get_cast_technique_level(this, i);
        if (TObjPlayer::is_invalid_slot(level) == 0) {
            level += add;
            level = clamp_to_max(level, get_effective_technique_level(i));
            set_learned_level(i, clamp_to_max(level, get_technique_level(i)));
        }
        i++;
    } while (i < 0x13);
}
