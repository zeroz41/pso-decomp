#include "pso/network/TPlyJoinLobby.h"

void TPlyJoinLobby::bswap() {
    header.bswap();
    for (int i = 0; i < 12; ++i) {
        entries[i].bswap();
    }
}
