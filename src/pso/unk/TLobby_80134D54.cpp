#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"


void TLobby::clear_counters() {
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = NULL;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = NULL;
}
