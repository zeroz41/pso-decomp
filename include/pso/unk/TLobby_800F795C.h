#ifndef PSO_UNK_TLOBBY_800F795C_H
#define PSO_UNK_TLOBBY_800F795C_H

#include "types.h"

extern "C" {
f32 TLobby__sub_800F7A6C(void);
f32 TLobby__sub_800F7A7C(void);
int get_attack_credit_slot_count(void);
}
void init_6x0A_enemy_state_packet(void *p);
void init_6x9C_enemy_low_game_flags_packet(u8 *arg0);
s32 load_current_floor_resources(void);
s32 load_floor_resources(s32 arg0);
void send_6x0A_enemy_state_packet(void *p);
void unload_current_floor_resources(void);
void unload_floor_resources(s32 arg0);

// --- C functions defined in TLobby_800F795C.cpp ---
extern "C" {
f32 TLobby__sub_800F7A6C(void);
f32 TLobby__sub_800F7A7C(void);
int get_attack_credit_slot_count(void);
}
// --- end of C functions

#endif
