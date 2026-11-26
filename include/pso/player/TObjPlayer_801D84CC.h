#ifndef PSO_PLAYER_TOBJPLAYER_801D84CC_H
#define PSO_PLAYER_TOBJPLAYER_801D84CC_H

#include "types.h"

struct TItemData;

// --- C functions defined in TObjPlayer_801D84CC.cpp ---
extern "C" {
void trade_item_by_group_kind(s32 player, s8 group, s8 kind);
void process_trade_target(saddr player, TItemData *item_data);
}
// --- end of C functions

#endif
