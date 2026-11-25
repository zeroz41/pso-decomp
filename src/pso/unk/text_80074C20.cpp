#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"

s32 TLobby::start_lobby_name_request() {
    clear_lobby_name();
    if (protocol_instance == NULL) {
        return 0;
    }
    protocol_instance->m_recv_handlers.handle_8A_lobby_name_packet = receive_lobby_name;
    protocol_instance->send_lobby_name_request();
    return 1;
}
