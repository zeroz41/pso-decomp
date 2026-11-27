#ifndef PSO_QUEST_BATTLE_RULES_H
#define PSO_QUEST_BATTLE_RULES_H

#include "types.h"

struct BattleRules {
    u8 tech_disk_mode;
    u8 weapon_and_armor_mode;
    u8 mag_mode;
    u8 tool_mode;
    u8 trap_mode;
    u8 unused_F817;
    u8 respawn_mode;
    u8 replace_char;
    u8 drop_weapon;
    u8 is_teams;
    u8 hide_target_reticle;
    u8 meseta_mode;
    s8 death_level_up;
    s8 trap_counts[4];
    u8 enable_sonar;
    s8 sonar_count;
    u8 forbid_scape_dolls;
    u32 pad_14;
    u32 lives;
    u32 max_tech_level;
    u32 char_level;
    u32 time_limit;
    s16 death_tech_level_up;
    u8 unused_2A[2];
};

extern "C" {
extern BattleRules battle_rules;
}

#endif
