#include "pso/network/TPlyJoinLobby.h"
#include "pso/network/TPlyJoinLobbyEntry_801DFA18.h"

void TPlyJoinLobby::bswap() {
    header.bswap();
    for (int i = 0; i < 12; ++i) {
        bswap__18TPlyJoinLobbyEntryFv((s32)&entries[i]);
    }
}
