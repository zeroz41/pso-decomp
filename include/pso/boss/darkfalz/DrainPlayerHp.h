#ifndef PSO_BOSS_DARKFALZ_DRAINPLAYERHP_H
#define PSO_BOSS_DARKFALZ_DRAINPLAYERHP_H

#include "types.h"

// Takes up to `damage` HP from a player in Dark Falz's arena; returns what was taken.
u32 drain_player_hp(s32 client, u32 damage);

#endif
