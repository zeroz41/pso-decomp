#ifndef PSO_UNK_TLOBBY_80070A00_H
#define PSO_UNK_TLOBBY_80070A00_H

#include "types.h"

// --- C functions defined in TLobby_80070A00.cpp ---
extern "C" {
s32 *TLobby__sub_80070ACC(void);
u32 TLobby__sub_80070AD8(s32 arg0);
void TLobby__sub_80070B34(s32 v);
void TLobby__sub_80070BE8(s32 arg0);
void TLobby__sub_80070C50(void);
s32 TLobby__sub_80070DA8(void);
void TLobby__sub_80070EE4(saddr clear_time);
s32 TLobby__sub_80070F4C(void);
s32 TLobby__sub_80070FD8(void);
void TLobby__sub_80071064(s32 arg0);
s32 TLobby__sub_800710D8(s32 arg0);
s32 TLobby__sub_8007119C(s32 arg0);
s32 TLobby__sub_800712D8(s32 idx, s32 value, s32 arg);
s32 *TLobby__sub_800713C8(void);
u32 TLobby__sub_80071640(u32 c);
s32 TLobby__sub_80071654(s32 arg0);
s32 add_entry__6TLobbyFiii(saddr src, saddr arg1, s32 arg2);
void set_challenge_mode_split_flag(void);
}
// --- end of C functions

// The challenge rank title of a character record, decoded for display.
extern char challenge_rank_title[0xC];

#endif
