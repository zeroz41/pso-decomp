#include "types.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/system/data/pso_const_ids4.h"

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
