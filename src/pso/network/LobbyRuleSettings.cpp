#include "types.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/item/drop/TItemDrop.h"

s8 LobbyRuleSettings::get_trap_count(s32 index) {
    s8 count = trap_counts[index];
    if (count < 0 || count > 20) {
        trap_counts[index] = 0;
    }
    return trap_counts[index];
}

void LobbyRuleSettings::set_rule_slot_clamped(s8 count, s32 index) {
    if ((count < 0) || (count > 20)) {
        count = 20;
    }
    trap_counts[index] = count;
}

u8 LobbyRuleSettings::get_lives() {
    u8 v = lives;
    if (v > 99) {
        v = 0;
    }
    return v;
}

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

u8 LobbyRuleSettings::get_trap_mode() {
    if (trap_mode >= 2) {
        return default_setting_05(this);
    }
    return trap_mode;
}

u8 LobbyRuleSettings::get_tool_mode() {
    if (tool_mode >= 3) {
        return default_setting_04(this);
    }
    return tool_mode;
}

u8 LobbyRuleSettings::get_mag_mode() {
    if (mag_mode >= 2) {
        return default_setting_03(this);
    }
    return mag_mode;
}

u8 LobbyRuleSettings::get_weapon_and_armor_mode() {
    if (weapon_and_armor_mode >= 4) {
        return default_setting_02(this);
    }
    return weapon_and_armor_mode;
}

u8 LobbyRuleSettings::get_tech_disk_mode() {
    if (tech_disk_mode >= 3) {
        return default_setting_01(this);
    }
    return tech_disk_mode;
}

u8 LobbyRuleSettings::get_rules_active() {
    if (rules_active >= 2) {
        return default_rule_value_stub(this);
    }
    return rules_active;
}

void LobbyRuleSettings::set_death_tech_level_up(u8 value) {
    if (value >= 0x1E) {
        value = default_setting_18(this);
    }
    death_tech_level_up = value;
}

void LobbyRuleSettings::set_death_level_up(s16 value) {
    if (value >= 0xC8) {
        value = default_setting_16(this);
    }
    death_level_up = value;
}

void LobbyRuleSettings::set_forbid_scape_dolls(u8 value) {
    if (value >= 2) {
        value = default_setting_0E(this);
    }
    forbid_scape_dolls = value;
}

void LobbyRuleSettings::set_enable_sonar(u8 value) {
    if (value >= 2) {
        value = default_setting_0D(this);
    }
    enable_sonar = value;
}

void LobbyRuleSettings::set_meseta_mode(u8 value) {
    if (value >= 3) {
        value = default_setting_0C(this);
    }
    meseta_mode = value;
}

void LobbyRuleSettings::set_hide_target_reticle(u8 value) {
    if (value >= 2) {
        value = default_setting_0B(this);
    }
    hide_target_reticle = value;
}

void LobbyRuleSettings::set_is_teams(u8 value) {
    if (value >= 2) {
        value = default_setting_0A(this);
    }
    is_teams = value;
}

void LobbyRuleSettings::set_drop_weapon(u8 value) {
    if (value >= 2) {
        value = default_setting_09(this);
    }
    drop_weapon = value;
}

void LobbyRuleSettings::set_replace_char(u8 value) {
    if (value >= 2) {
        value = default_setting_08(this);
    }
    replace_char = value;
}

void LobbyRuleSettings::set_respawn_mode(u8 value) {
    if (value >= 3) {
        value = default_setting_07(this);
    }
    respawn_mode = value;
}

void LobbyRuleSettings::set_unused_F817(u8 value) {
    if (value >= 2) {
        value = default_setting_06(this);
    }
    unused_F817 = value;
}

void LobbyRuleSettings::set_trap_mode(u8 value) {
    if (value >= 2) {
        value = default_setting_05(this);
    }
    trap_mode = value;
}

void LobbyRuleSettings::set_tool_mode(u8 value) {
    if (value >= 3) {
        value = default_setting_04(this);
    }
    tool_mode = value;
}

void LobbyRuleSettings::set_mag_mode(u8 value) {
    if (value >= 2) {
        value = default_setting_03(this);
    }
    mag_mode = value;
}

void LobbyRuleSettings::set_weapon_and_armor_mode(u8 value) {
    if (value >= 4) {
        value = default_setting_02(this);
    }
    weapon_and_armor_mode = value;
}

void LobbyRuleSettings::set_tech_disk_mode(u8 value) {
    if (value >= 3) {
        value = default_setting_01(this);
    }
    tech_disk_mode = value;
}

void LobbyRuleSettings::set_section_id(u8 value) {
    if (value >= 2) {
        value = default_rule_value_stub(this);
    }
    rules_active = value;
}

void LobbyRuleSettings::reset_settings_to_default() {
    s32 k;

    set_section_id(default_rule_value_stub(this));
    set_tech_disk_mode(default_setting_01(this));
    set_weapon_and_armor_mode(default_setting_02(this));
    set_mag_mode(default_setting_03(this));
    set_tool_mode(default_setting_04(this));
    set_trap_mode(default_setting_05(this));
    set_unused_F817(default_setting_06(this));
    set_respawn_mode(default_setting_07(this));
    set_replace_char(default_setting_08(this));
    set_drop_weapon(default_setting_09(this));
    set_is_teams(default_setting_0A(this));
    set_hide_target_reticle(default_setting_0B(this));
    set_meseta_mode(default_setting_0C(this));
    set_enable_sonar(default_setting_0D(this));
    set_forbid_scape_dolls(default_setting_0E(this));
    set_lives(0);
    set_max_tech_level(0xFF);
    set_char_level(0);
    set_time_limit(0xA);
    pad_12 = 0;
    for (k = 0; k < 4; k++) {
        trap_counts[k] = 0x14;
    }
    pad_0F = 0;
}
