#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DF280.h"

// The lobby registers a no-argument function as the B1 handler; the protocol passes it the time text.
typedef void (*server_time_handler)(char *time);

void TProtocol::handle_cmd_B1(packet &pkt) {
    TRecvServerTime recv = as(TRecvServerTime &, pkt);
    server_time_handler handler;
    s32 low = recv.time_flags_low;
    s32 mid = recv.time_flags_mid;
    s32 high = recv.time_flags_high;

    lobby_state_flags = 0;
    lobby_state_flags = (lobby_state_flags & ~0xFF) | (low & 0xFF);
    lobby_state_flags = (lobby_state_flags & ~0xFF00) | ((mid << 8) & 0xFF00);
    lobby_state_flags = (lobby_state_flags & ~0xFF0000) | ((high << 16) & 0xFF0000);
    bswap_packet_header_cmd_b1(&recv);
    handler = (server_time_handler)m_recv_handlers.handle_B1_current_time_packet;
    if (handler != NULL) {
        handler(recv.time);
    }
}
