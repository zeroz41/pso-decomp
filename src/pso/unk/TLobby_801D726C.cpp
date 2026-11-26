#include "types.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/item/drop/TItemDrop.h"

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
        value = TItemDrop__sub_80107B04(this);
    }
    rules_active = value;
}

void LobbyRuleSettings::reset_settings_to_default() {
    s32 k;

    set_section_id(TItemDrop__sub_80107B04(this));
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
