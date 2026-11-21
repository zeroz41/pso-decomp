#ifndef PSO_UNK_TLOBBY_803CBF50_H
#define PSO_UNK_TLOBBY_803CBF50_H

#include "types.h"

class TLobby;

extern "C" {
void TLobby__sub_803CBF50(TLobby *stream, s32 ch, s32 pan);
void TLobby__sub_803CBF90(TLobby *stream, s32 rate);
void TLobby__sub_803CBFB0(void);
s32 TLobby__sub_803CBFF0(TLobby *stream);
void TLobby__sub_803CC030(void);
}

// --- C functions defined in TLobby_803CBF50.cpp ---
extern "C" {
void TLobby__sub_803CBF50(TLobby *stream, s32 ch, s32 pan);
void TLobby__sub_803CBF90(TLobby *stream, s32 rate);
void TLobby__sub_803CBFB0(void);
s32 TLobby__sub_803CBFF0(TLobby *stream);
void TLobby__sub_803CC030(void);
}
// --- end of C functions

#endif
