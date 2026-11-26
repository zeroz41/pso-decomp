#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_80156B18.h"
#include "pso/network/TGameProtocol.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/subcmd_6x.h"


void bswap_object_state(G_UpdateObjectState_6x0B *packet) { packet->bswap(); }

void G_UpdateObjectState_6x0B::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_32(&flags);
    bswap_32(&object_index);
}

void G_UpdateObjectState_6x0B::send() {
    bswap_object_state(this);
    send_subcommand(this);
}

void G_UpdateObjectState_6x0B::init() {
    header.subcommand = 0x0B;
    header.size = 3;
}

