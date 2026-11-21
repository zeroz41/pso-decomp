#ifndef PSO_OBJECT_BASE_TOBJBASE_H
#define PSO_OBJECT_BASE_TOBJBASE_H

#include "types.h"

// --- C functions defined in TObjBase.cpp ---
extern "C" {
u16 alloc_enemy_ids(s32 arg);
void TLobby__sub_801A2550(void);
void reset_id_counters(void);
u16 alloc_player_ids(s32 n);
}
// --- end of C functions

#endif
