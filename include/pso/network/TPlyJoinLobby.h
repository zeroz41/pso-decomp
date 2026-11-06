#ifndef PSO_NETWORK_TPLYJOINLOBBY_H
#define PSO_NETWORK_TPLYJOINLOBBY_H

#include "pso/network/protocol/packet_classes.h"

#include <stddef.h>
typedef char TPlyJoinLobbyEntrySize[(sizeof(TPlyJoinLobbyEntry) == 0x43C) ? 1 : -1];
typedef char TPlyJoinLobbyEntriesOffset[(offsetof(TPlyJoinLobby, entries) == 0x10) ? 1 : -1];
typedef char TPlyJoinLobbySize[(sizeof(TPlyJoinLobby) == 0x32E0) ? 1 : -1];

extern "C" {
u8 *__ct__13TPlyJoinLobbyFRC13TPlyJoinLobby(u8 *arg0, u8 *arg1);
s32 __dt__13TPlyJoinLobbyFv(s32 arg0, s16 arg1);
}

// --- C functions defined in TPlyJoinLobby.cpp ---
extern "C" {
u8 *__ct__13TPlyJoinLobbyFRC13TPlyJoinLobby(u8 *arg0, u8 *arg1);
s32 __dt__13TPlyJoinLobbyFv(s32 arg0, s16 arg1);
}
// --- end of C functions

#endif
