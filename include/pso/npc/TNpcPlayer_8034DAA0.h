#ifndef PSO_NPC_TNPCPLAYER_8034DAA0_H
#define PSO_NPC_TNPCPLAYER_8034DAA0_H

#include "types.h"

// --- C functions defined in TNpcPlayer_8034DAA0.cpp ---
extern "C" {
void TLobby__sub_8034DAA0(s32 arg0, u32 arg1);
s32 TNpcPlayer__sub_8034DE40(void);
void TNpcPlayer__sub_8034EDB8(void);
}
void build_6x69_npc_control(void *p);
extern "C" {
void clear_partner_dialogue_flags(void);
u8 *get_party_position(void);
s32 get_party_yaw(void);
}
// --- end of C functions

#endif
