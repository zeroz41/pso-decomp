#ifndef PSO_NPC_TNPCPLAYER_8034DAA0_H
#define PSO_NPC_TNPCPLAYER_8034DAA0_H

#include "types.h"

// --- C functions defined in TNpcPlayer_8034DAA0.cpp ---
extern "C" {
void TLobby__sub_8034DAA0(s32 client, u32 arg1);
s32 TNpcPlayer__get_lobby_entry_yaw(void);
void TNpcPlayer__sub_8034EDB8(void);
}
void build_6x69_npc_control(void *p);
extern "C" {
void clear_partner_dialogue_flags(void);
u8 *get_party_position(void);
s32 get_party_yaw(void);
}
// --- end of C functions

void set_partner_dialogue_override(const char *text, s32 kind, u16 player);
void set_partner_common_remark(s32 kind, const char *text);
void show_partner_chatter_for_key(s16 key);
void quest_remove_npc_player(u16 client);

#endif
