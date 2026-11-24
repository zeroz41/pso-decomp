#ifndef PSO_PLAYER_PALETTEX_H
#define PSO_PLAYER_PALETTEX_H

#include "types.h"

// The palettex quest opcodes: each acts on the state of client_index when that client is the local player.
extern "C" {
// Starts the quest label set by set_palettex_callback.
void run_palettex_callback(u16 client_index);
void set_palettex_callback(u16 client_index, s32 label);
// is_palettex_enabled.
u8 TObjPlayer__sub_80354C7C(u16 client_index);
// disable_palettex.
void TObjPlayer__sub_80354CCC(u16 client_index);
// enable_palettex.
void TObjPlayer__sub_80354D14(u16 client_index);
s32 is_palettex_activated(u16 client_index);
// restore_palettex.
void TObjPlayer__sub_80354DAC(u16 client_index);
void activate_palettex(u16 client_index);
// 1 when client_index is a player controlled on this console.
s32 is_local_client(u16 client_index);
// Clears the palettex state of every client.
void reset_client_quest_slot_table();
}

#endif
