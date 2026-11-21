#include "pso/network/TProtocol.h"
#include <stddef.h>
LAYOUT_ASSERT(ProtocolConnectedOffset, offsetof(TProtocol, m_connected) == 0x1910);
LAYOUT_ASSERT(PacketHeaderSize, sizeof(packet_header) == 4);
LAYOUT_ASSERT(PacketFlagsOffset, offsetof(packet_header, flags) == 1);
LAYOUT_ASSERT(PacketSizeOffset, offsetof(packet_header, size) == 2);

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
