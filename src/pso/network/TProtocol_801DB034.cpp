#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DF280.h"

void TProtocol::handle_cmd_8A(packet &pkt) {
    TRecvLobbyName tmp = as(TRecvLobbyName &, pkt);
    bswap_cmd_8a_header(&tmp);
    if (m_recv_handlers.handle_8A_lobby_name_packet != NULL) {
        m_recv_handlers.handle_8A_lobby_name_packet(tmp.name);
    }
}
