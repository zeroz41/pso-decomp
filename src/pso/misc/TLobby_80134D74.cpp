#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/network/TProtocol.h"

extern void *TLobby__protocol_instance;

void TLobby::disconnect_protocol() {
    void *protocol;
    protocol = TLobby__protocol_instance;
    if (protocol != NULL) {
        ((TProtocol *)protocol)->send_logout();
    }
}
