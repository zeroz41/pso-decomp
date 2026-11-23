#ifndef PSO_UNK_TLOBBY_80291D94_H
#define PSO_UNK_TLOBBY_80291D94_H

#include "types.h"

struct TLobby;
extern "C" {
void TLobby__sub_80291DF8(s32 v);
void TLobby__sub_80291EAC(s32 arg0);
s32 TLobby__sub_80291F9C(void);
s32 TLobby__sub_8029204C(void);
void TLobby__sub_80292200(s32 seed);
int TLobby__sub_80292268(void);
s32 TLobby__sub_80292270(s32 seed, s32 card);
s32 TLobby__sub_802923C4(s32 idx, s32 value, s32 arg);
s32 TLobby__sub_802924B4(s32 arg0, u16 slot_index);
s32 TLobby__sub_8029299C(void);
s32 TLobby__sub_80292A34(void);
s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
s32 TLobby__sub_80292F34(s32 limit);
int TLobby__sub_80292F5C(void *p);
void TLobby__sub_802930A8(void);
int TLobby__sub_80293124(void *p);
void TLobby__sub_80293218(s32 client);
s32 count_card_layout_entries(s32 client);
void enable_split_screen_challenge_mode(void);
s32 is_challenge_mode_active(void);
void set_split_screen_name__6TLobbyFv(s32 arg0);
}
void setup_split_screen(void);

#endif
