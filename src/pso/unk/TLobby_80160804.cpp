#include "types.h"
#include "pso/unk/TLobby_80160804.h"
#include "pso/network/TGameProtocol.h"
#include "pso/unk/TLobby_80156B18.h"

void send_object_state(G_UpdateObjectState_6x0B *packet) {
    bswap_object_state(packet);
    send_subcommand(packet);
}
