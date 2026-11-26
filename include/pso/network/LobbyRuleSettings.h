#ifndef PSO_NETWORK_LOBBYRULESETTINGS_H
#define PSO_NETWORK_LOBBYRULESETTINGS_H

#include "types.h"

// The live battle-rule set (the global lobby_rule_settings). Each getter returns its field, or the
// field's default_setting_* value when the field is out of range; each setter clamps the same way.
// Field names: TPlayerBattleCtrl copies the quest's BattleRules (pso/quest/BattleRules.h) into
// these fields one setter each, and apply_battle_rules_to_players uses them the same way.
class LobbyRuleSettings {
public:
    u8 rules_active;          // inferred: set to 1 once TPlayerBattleCtrl has loaded the rules; every
                              // battle-only path (apply_battle_rules_to_players, mines) checks == 1
    u8 tech_disk_mode;        // 1: techniques removed, 2: capped at max_tech_level
    u8 weapon_and_armor_mode; // 1-3: weapons and armor cleared
    u8 mag_mode;              // 1: mags cleared
    u8 tool_mode;             // 1-2: tools cleared
    u8 trap_mode;             // 1: trap_counts handed to every player
    u8 unused_F817;           // quest BattleRules.unused_F817 (qst_op_ba_set_unused_F817)
    u8 respawn_mode;          // 2: lives limit the respawns
    u8 replace_char;          // 1: level reset to char_level
    u8 drop_weapon;
    u8 is_teams;
    u8 hide_target_reticle;
    u8 meseta_mode;           // nonzero: meseta set to 0
    u8 enable_sonar;          // 1: sonar stock set to sonar_count
    u8 forbid_scape_dolls;
    u8 pad_0F;
    u8 lives;
    u8 max_tech_level;
    u8 pad_12;
    s8 sonar_count;
    s16 char_level;
    s16 death_level_up;
    s16 death_tech_level_up;
    u8 pad_1A[2];
    s32 time_limit;
    s8 trap_counts[4];

    LobbyRuleSettings();
    // Stores count in trap_counts[index], 20 when it is outside 0..20.
    void set_trap_count(s8 count, s32 index);
    // sonar_count, or 0 when it is outside 0..99.
    s32 get_sonar_count();
    // Stores count as sonar_count, 0 when it is outside 0..99.
    void set_sonar_count(s32 count);
    s8 get_trap_count(s32 index);
    u8 get_lives();
    void set_lives(u8 count);
    u8 get_max_tech_level();
    void set_max_tech_level(u8 level);
    s16 get_char_level();
    void set_char_level(s16 level);
    void set_time_limit(s32 value);
    u8 get_death_tech_level_up();
    s16 get_death_level_up();
    u8 get_forbid_scape_dolls();
    u8 get_enable_sonar();
    u8 get_meseta_mode();
    u8 get_hide_target_reticle();
    u8 get_is_teams();
    u8 get_drop_weapon();
    u8 get_replace_char();
    u8 get_respawn_mode();
    u8 get_trap_mode();
    u8 get_tool_mode();
    u8 get_mag_mode();
    u8 get_weapon_and_armor_mode();
    u8 get_tech_disk_mode();
    u8 get_rules_active();
    void set_death_tech_level_up(u8 value);
    void set_death_level_up(s16 value);
    void set_forbid_scape_dolls(u8 value);
    void set_enable_sonar(u8 value);
    void set_meseta_mode(u8 value);
    void set_hide_target_reticle(u8 value);
    void set_is_teams(u8 value);
    void set_drop_weapon(u8 value);
    void set_replace_char(u8 value);
    void set_respawn_mode(u8 value);
    void set_unused_F817(u8 value);
    void set_trap_mode(u8 value);
    void set_tool_mode(u8 value);
    void set_mag_mode(u8 value);
    void set_weapon_and_armor_mode(u8 value);
    void set_tech_disk_mode(u8 value);
    void set_section_id(u8 value);
    void reset_settings_to_default();
};

extern LobbyRuleSettings lobby_rule_settings;

#endif
