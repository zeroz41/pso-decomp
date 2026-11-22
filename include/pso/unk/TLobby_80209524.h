#ifndef PSO_UNK_TLOBBY_80209524_H
#define PSO_UNK_TLOBBY_80209524_H

#include "types.h"

struct EventShuffleTable;

struct ChallengeRandomEvent;

// --- C functions defined in TLobby_80209524.cpp ---
extern "C" {
EventShuffleTable *TLobby__sub_80209584(EventShuffleTable *table, s32 capacity);
void TLobby__sub_802097B0(s16 id);
void TLobby__sub_8020A2AC(void);
void TLobby__sub_8020A394(void *p);
void TLobby__sub_8020A3D0(void *arg0, void *arg1);
void TLobby__sub_8020A48C(void *p);
void TLobby__sub_8020A568(void *p);
void TLobby__sub_8020A618(ChallengeRandomEvent *dst, ChallengeRandomEvent *src);
void TLobby__sub_8020A6B0(s32 player);
s32 TLobby__sub_8020B308(void);
s32 pick_random_slot__6TLobbyFPv(s16 *arg0);
}
// --- end of C functions

#endif
