#ifndef PSO_PLAYER_TOBJPLAYER_801D84CC_H
#define PSO_PLAYER_TOBJPLAYER_801D84CC_H

#include "types.h"

struct TItemData;

// --- C functions defined in TObjPlayer_801D84CC.cpp ---
extern "C" {
void TObjPlayer__sub_801D8664(s32 player, s8 group, s8 kind);
void TObjPlayer__sub_801D8A38(void *entry);
void process_trade_target__10TObjPlayerFiPv(saddr player, TItemData *item_data);
}
// --- end of C functions

#endif
