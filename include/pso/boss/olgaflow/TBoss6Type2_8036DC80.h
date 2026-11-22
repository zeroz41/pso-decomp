#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE2_8036DC80_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE2_8036DC80_H

#include "types.h"

struct TObjPlayer;

// Each client's look as the Olga Flow fight starts (boss6_type2_player_snapshot_table).
void restore_boss6_player_snapshot(TObjPlayer *player);
void capture_boss6_player_snapshots();
void clear_boss6_player_snapshots(void);

#endif
