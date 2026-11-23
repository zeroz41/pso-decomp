#ifndef PSO_PLAYER_REQUIREMENT_STATS_H
#define PSO_PLAYER_REQUIREMENT_STATS_H
#include "types.h"
struct TObjPlayer;
struct AttackParams;
struct ActorParamBlock;
struct player_stats;

extern "C" {
void set_params__10TObjPlayerFPvPvPviPv(void *out, void *player, player_stats *base_stats,
                                      AttackParams *attack_stats, ActorParamBlock *resistance_stats);
void init_shield_params(void *out, void *player, player_stats *base_stats,
                        AttackParams *attack_stats, ActorParamBlock *resistance_stats);
AttackParams *get_class_attack_template(TObjPlayer *player);
ActorParamBlock *get_class_defense_template(TObjPlayer *player);
}

struct PlayerRequirementStats { s16 values[11]; };
extern "C" s32 build_player_equipment_requirement_stats(TObjPlayer *, PlayerRequirementStats *);
#endif
