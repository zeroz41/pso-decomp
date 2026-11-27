#ifndef PSO_BOSS_OLGAFLOW_BOSS6PLAYERSNAPSHOTS_H
#define PSO_BOSS_OLGAFLOW_BOSS6PLAYERSNAPSHOTS_H

#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"

struct TObjPlayer;

// Each client's look as the Olga Flow fight starts (boss6_type2_player_snapshot_table).
void restore_boss6_player_snapshot(TObjPlayer *player);
void capture_boss6_player_snapshots();
void clear_boss6_player_snapshots(void);

// One client's look as the Olga Flow fight starts; free_chara_making puts it back.
struct Boss6PlayerSnapshot {
    s32 active;
    Boss6PlayerLook look;
};

#endif
