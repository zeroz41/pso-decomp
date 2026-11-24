#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerTechniqueState.h"

extern "C" {
s32 is_invalid_slot__10TObjPlayerFUc(s32 level);


s32 set_technique_level_entry(s32, s16, s32);
s32 get_cast_technique_level(s32, s16);
u8 get_effective_technique_level__10TObjPlayerFPvs(void *, int);
s32 TObjPlayer__sub_801C010C(void *, s16);
s32 clamp_to_max__20PlayerTechniqueStateFUcUc(void *, s32, s32);

s16 PlayerTechniqueState::get_section_clamped() {
    s16 section;

    section = this->target_count;
    if ((section < 0) || (section > 0xA)) {
        this->target_count = 0;
    }
    return this->target_count;
}

s16 PlayerTechniqueState::get_or_init_field_4() {
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
    cap = get_effective_technique_level__10TObjPlayerFPvs(this, technique);
    if (TObjPlayer::is_invalid_slot(cap) != 0) {
        return TObjPlayer::get_item_count_max();
    }
    if (level > cap) {
        level = cap;
    }
    return level;
}

void TObjPlayer::update_all_units(s32 levels, s32 level) {
    s32 i;

    i = 0;
    do {
        if (is_invalid_slot__10TObjPlayerFUc(get_cast_technique_level(levels, (s16) i)) == 0) {
            set_technique_level_entry(levels, (s16) i, level);
        }
        i += 1;
    } while (i < 0x13);
}

void TObjPlayer::level_up_all_techniques(s32 add) {
    s32 i = 0;
    do {
        s32 level = ((s32 (*)(void *, s16))get_cast_technique_level)(this, i);
        if (is_invalid_slot__10TObjPlayerFUc(level) == 0) {
            level += add;
            level = clamp_to_max__20PlayerTechniqueStateFUcUc(this, level, ((s32 (*)(void *, s16))get_effective_technique_level__10TObjPlayerFPvs)(this, i));
            ((void (*)(void *, s16, s32))set_technique_level_entry)(this, i, clamp_to_max__20PlayerTechniqueStateFUcUc(this, level, TObjPlayer__sub_801C010C(this, i)));
        }
        i++;
    } while (i < 0x13);
}

}
