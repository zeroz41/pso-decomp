#include "types.h"
#include "pso/network/ObjectStateSend.h"
#include "pso/network/TGameProtocol.h"
#include "pso/network/UpdateObjectStateCmd.h"

void send_object_state(G_UpdateObjectState_6x0B *packet) {
    bswap_object_state(packet);
    send_subcommand(packet);
}
