#include "pso/network/protocol/packet_classes.h"
#include <stddef.h>
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/protocol.h"

typedef char LobbyExitSize[(sizeof(TRecvExit<true>) == 8) ? 1 : -1];
typedef char GameExitSize[(sizeof(TRecvExit<false>) == 8) ? 1 : -1];
typedef char GameExitClientOffset[(offsetof(TRecvExit<false>, client_id) == 4) ? 1 : -1];
typedef char GameExitLeaderOffset[(offsetof(TRecvExit<false>, leader_id) == 5) ? 1 : -1];
typedef char GameExitUdpOffset[(offsetof(TRecvExit<false>, disable_udp) == 6) ? 1 : -1];

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
