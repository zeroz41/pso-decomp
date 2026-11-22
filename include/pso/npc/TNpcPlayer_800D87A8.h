#ifndef PSO_NPC_TNPCPLAYER_800D87A8_H
#define PSO_NPC_TNPCPLAYER_800D87A8_H

#include "types.h"

extern "C" {
void *find_active_entity_by_id(u16 id);
}

// --- C functions defined in TNpcPlayer_800D87A8.cpp ---
extern "C" {
void *find_active_entity_by_id(u16 id);
}
// --- end of C functions

// The player in battle slot `id` (TObjPlayer::get_battle_param), or 0 when that
// slot is not a valid, active player.
void *get_valid_target_player(int id);

#endif
