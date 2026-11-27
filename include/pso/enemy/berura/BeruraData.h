#ifndef PSO_ENEMY_BERURA_BERURADATA_H
#define PSO_ENEMY_BERURA_BERURADATA_H

#include "types.h"

// The attack-stat ids (dispatch_shared_handler_b) and, per stat set (0 normal, 1 reload_stats_from_tables), the row
// of each handle table reset_hp/reload_stats_keep_hp_tp take.
extern const s32 berura_attack_stat_ids[];
extern const s32 re7_berura_base_stat_rows[];
extern const s32 re7_berura_attack_stat_rows[];
extern const s32 re7_berura_resist_stat_rows[];

#endif
