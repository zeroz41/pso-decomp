#ifndef PSO_BOSS_OLGAFLOW_BOSS6SUBORDINATEACTIONS_H
#define PSO_BOSS_OLGAFLOW_BOSS6SUBORDINATEACTIONS_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

void send_subordinate_actions_group0(const s32 *ids, s32 cnt, s32 force);
void send_6xAD_grid_positions(s32 index, Vec *points, s32 count);
void send_subordinate_actions(s32 kind, const s32 *ids, s32 n, s32 force);

#endif
