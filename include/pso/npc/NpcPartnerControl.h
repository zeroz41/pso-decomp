#ifndef PSO_NPC_NPCPARTNERCONTROL_H
#define PSO_NPC_NPCPARTNERCONTROL_H

#include "types.h"

extern "C" {
void TLobby__sub_8034DAA0(s32 client, u32 status);
s32 TNpcPlayer__get_lobby_entry_yaw(void);
void TNpcPlayer__sub_8034EDB8(void);
}
extern "C" {
void clear_partner_dialogue_flags(void);
u8 *get_party_position(void);
s32 get_party_yaw(void);
}

// The common partner remarks, one per remark kind; an empty text means none is set.
struct PartnerRemark {
    char text[0x36];
};

extern PartnerRemark npc_partner_dialogue_state[25];

// Custom partner remarks per player: up to six texts, each keyed by a remark kind (25 = free slot).
struct PartnerDialogueSet {
    const char *text[6];
    s32 kind[6];
};

extern PartnerDialogueSet partner_dialogue_table[4];

const char *get_partner_custom_text(s32 kind, u16 player);
void set_partner_dialogue_override(const char *text, s32 kind, u16 player);
void set_partner_common_remark(s32 kind, const char *text);
void show_partner_chatter_for_key(s16 key);
void quest_remove_npc_player(u16 client);

#endif
