#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"


void TLobby::disconnect_protocol() {
    TProtocol *protocol;
    protocol = protocol_instance;
    if (protocol != NULL) {
        protocol->send_logout();
    }
}
