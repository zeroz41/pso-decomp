#ifndef PSO_PLAYER_REQUIREMENT_STATS_H
#define PSO_PLAYER_REQUIREMENT_STATS_H
#include "types.h"
struct TObjPlayer;
struct AttackParams;
struct ActorParamBlock;
struct player_stats;

// A player's stats as the status and item windows show them: the base stats
// plus what the equipment adds (ATA is shown in tenths), then the five
// resistances.
struct PlayerRequirementStats {
    s16 atp;
    s16 dfp;
    s16 mst;
    s16 ata;
    s16 evp;
    s16 lck;
    s16 resist[5];

    void clear_fields();
    void set(TObjPlayer *player, player_stats *base_stats, AttackParams *attack_stats,
             ActorParamBlock *resistance_stats);
};

// The stats a level-up compares: the shown stats plus HP and TP maxima.
struct PlayerLevelStats : public PlayerRequirementStats {
    s16 hp_max;
    s16 tp_max;

    PlayerLevelStats();
    void copy_stat_block(const PlayerLevelStats *src);
    void set(TObjPlayer *player, player_stats *base_stats, AttackParams *attack_stats,
             ActorParamBlock *resistance_stats);
    void calc_delta(PlayerLevelStats *after, PlayerLevelStats *delta);
};

extern "C" {
AttackParams *get_class_attack_template(TObjPlayer *player);
ActorParamBlock *get_class_defense_template(TObjPlayer *player);
}

extern "C" s32 build_player_equipment_requirement_stats(TObjPlayer *, PlayerRequirementStats *);
extern "C" s32 build_player_class_stat_template(TObjPlayer *player, PlayerRequirementStats *out);
#endif
