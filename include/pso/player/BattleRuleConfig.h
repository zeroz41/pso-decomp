#ifndef PSO_PLAYER_BATTLERULECONFIG_H
#define PSO_PLAYER_BATTLERULECONFIG_H

#include "types.h"

// A battle's rule settings as the lobby sends them; apply_rule_configuration hands each one to
// the matching lobby_rule_settings setter.
struct BattleRuleConfig {
    u8 rules[0xC];            // rules[9] == 1 splits the players into two teams (game mode 4)
    s8 value_c;
    s8 slot_rules[4];         // one trap count per slot (lobby_rule_settings.set_rule_slot_clamped)
    u8 rule_d;
    s8 level;
    u8 rule_e;
    u8 pad_14[4];
    s32 volume;
    s32 max_tech_level;
    s32 clamped_index;
    s32 time_limit_seconds;   // the battle's length (get_time_limit scales it to frames)
    s16 value_28;
};

#endif
