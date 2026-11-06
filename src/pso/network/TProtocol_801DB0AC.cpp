#include "pso/network/TProtocol.h"

void TProtocol::send_lobby_arrow(u8 arrow) {
    packet_header header;
    header.command = 0x89;
    header.flags = arrow;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
