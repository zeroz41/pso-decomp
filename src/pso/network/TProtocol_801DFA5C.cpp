#include "pso/network/protocol/packet_classes.h"
#include <stddef.h>
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/protocol.h"

LAYOUT_ASSERT(LobbyExitSize, sizeof(TRecvExit<true>) == 8);
LAYOUT_ASSERT(GameExitSize, sizeof(TRecvExit<false>) == 8);
LAYOUT_ASSERT(GameExitClientOffset, offsetof(TRecvExit<false>, client_id) == 4);
LAYOUT_ASSERT(GameExitLeaderOffset, offsetof(TRecvExit<false>, leader_id) == 5);
LAYOUT_ASSERT(GameExitUdpOffset, offsetof(TRecvExit<false>, disable_udp) == 6);

template<> void TRecvExit<false>::bswap() {
    header.bswap();
}

void TCreateGame::bswap() {
    header.bswap();
    tag.bswap();
}

void TFindUser::bswap() {
    header.bswap();
    tag.bswap();
    bswap_32(&target_gc);
}

TFindUser::TFindUser() {}

void TRoomChange::bswap() {
    header.bswap();
    tag.bswap();
}

TRoomChange::TRoomChange() {}
