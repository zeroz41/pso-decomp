#include "types.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerClassTechniques.h"

u8 PlayerTechniqueState::clamp_to_max(u8 level, u8 max) {
    u8 clamped;

    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return level;
    }
    clamped = level;
    if (level > max) {
        clamped = max;
    }
    return clamped;
}

s32 TObjPlayer::validate_and_clear_slot(PlayerTechniqueState *techs, s16 tech) {
    return is_invalid_slot(techs->get_cast_technique_level(tech));
}

s32 TObjPlayer::is_invalid_slot(u8 level) {
    return (u8)((u8)(level == 0xFF));
}

bool TObjPlayer::is_slot_within_limit(s8 cls, s16 tech, u8 level) {
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return 1;
    }
    return level <= get_class_technique_cap(cls, tech);
}

s32 PlayerTechniqueState::is_valid_technique_id(s16 technique) {
    s32 valid;

    valid = 0;
    if ((technique >= 0) && (technique < 0x13)) {
        valid = 1;
    }
    return (u8)((u8)valid);
}

s32 is_valid_technique_slot(u8 slot) {
    return (u8)((u8)(slot <= 0xFU));
}

s32 PlayerTechniqueState::check_technique_level(s16 technique, u8 level) {
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return 1;
    }
    if (level > get_technique_level(technique)) {
        return 0;
    }
    return level <= get_effective_technique_level(technique) ? 1 : 0;
}

void PlayerTechniqueState::set_target(s32 slot, u16 entity_id, s16 index) {
    PhotonBlastTarget *target = get_target(slot);
    target->set_entity_id(entity_id);
    target->set_index(index);
}

