#include "types.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/data/pso_const_ids4.h"

void LobbyRuleSettings::set_lives(u8 count) {
    u8 clamped;

    clamped = count;
    if (clamped > 0x63U) {
        clamped = 0;
    }
    lives = clamped;
}

u8 LobbyRuleSettings::get_max_tech_level() {
    u8 v;
    s32 t;
    t = max_tech_level;
    v = t;
    if (TObjPlayer::is_invalid_slot(t) == 0 && v > 0x1DU) {
        v = 0;
    }
    return v;
}

void LobbyRuleSettings::set_max_tech_level(u8 level) {
    u8 max_level;

    max_level = level;
    if ((TObjPlayer::is_invalid_slot(max_level) == 0) && (max_level > 0x1DU)) {
        max_level = 0;
    }
    max_tech_level = max_level;
}

s16 LobbyRuleSettings::get_char_level() {
    s16 index;

    index = char_level;
    if ((index < 0) || (index > TObjPlayer::get_max_level())) {
        index = 0;
    }
    return index;
}

void LobbyRuleSettings::set_char_level(s16 level) {
    s16 down;

    down = level;
    if ((down < 0) || (down > TObjPlayer::get_max_level())) {
        down = 0;
    }
    char_level = down;
}

void LobbyRuleSettings::set_time_limit(s32 value) {
    s32 clamped;

    clamped = value;
    if ((clamped < 0) || (clamped > 0x278D0)) {
        clamped = 0;
    }
    time_limit = clamped;
}

u8 LobbyRuleSettings::get_death_tech_level_up() {
    s16 level;

    level = death_tech_level_up;
    if (level >= 0x1E) {
        return default_setting_18(this);
    }
    return (u8) level;
}
s16 LobbyRuleSettings::get_death_level_up() {
    if (death_level_up >= 200) {
        return default_setting_16(this);
    }
    return death_level_up;
}

u8 LobbyRuleSettings::get_forbid_scape_dolls() {
    if (forbid_scape_dolls >= 2) {
        return default_setting_0E(this);
    }
    return forbid_scape_dolls;
}

u8 LobbyRuleSettings::get_enable_sonar() {
    if (enable_sonar >= 2) {
        return default_setting_0D(this);
    }
    return enable_sonar;
}

u8 LobbyRuleSettings::get_meseta_mode() {
    if (meseta_mode >= 3) {
        return default_setting_0C(this);
    }
    return meseta_mode;
}

u8 LobbyRuleSettings::get_hide_target_reticle() {
    if (hide_target_reticle >= 2) {
        return default_setting_0B(this);
    }
    return hide_target_reticle;
}
u8 LobbyRuleSettings::get_is_teams() {
    if (is_teams >= 2) {
        return default_setting_0A(this);
    }
    return is_teams;
}

u8 LobbyRuleSettings::get_drop_weapon() {
    if (drop_weapon >= 2) {
        return default_setting_09(this);
    }
    return drop_weapon;
}

u8 LobbyRuleSettings::get_replace_char() {
    if (replace_char >= 2) {
        return default_setting_08(this);
    }
    return replace_char;
}
u8 LobbyRuleSettings::get_respawn_mode() {
    if (respawn_mode >= 3) {
        return default_setting_07(this);
    }
    return respawn_mode;
}
