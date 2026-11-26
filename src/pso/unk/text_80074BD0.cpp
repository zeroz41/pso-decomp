#include "types.h"
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"

char lobby_name[0x18] = { 0 };

void receive_lobby_name(char *name) {
    clear_lobby_name();
    strncpy(lobby_name, name, 0x10);
    lobby_name[0x10] = 0;
}

s32 TLobby::start_lobby_name_request() {
    clear_lobby_name();
    if (protocol_instance == NULL) {
        return 0;
    }
    protocol_instance->m_recv_handlers.handle_8A_lobby_name_packet = receive_lobby_name;
    protocol_instance->send_lobby_name_request();
    return 1;
}

void clear_lobby_name() {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        lobby_name[i] = 0;
    }
}
