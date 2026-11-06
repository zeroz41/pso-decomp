#include "pso/network/TProtocol.h"
#include <stddef.h>
typedef char ProtocolConnectedOffset[(offsetof(TProtocol, m_connected) == 0x1910) ? 1 : -1];
typedef char PacketHeaderSize[(sizeof(packet_header) == 4) ? 1 : -1];
typedef char PacketFlagsOffset[(offsetof(packet_header, flags) == 1) ? 1 : -1];
typedef char PacketSizeOffset[(offsetof(packet_header, size) == 2) ? 1 : -1];

void TProtocol::send_choice_search_options_request() {
    packet_header header;
    if (m_connected != 0) {
        memset(&header, 0, sizeof(header));
        header.command = 0xC0;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}
