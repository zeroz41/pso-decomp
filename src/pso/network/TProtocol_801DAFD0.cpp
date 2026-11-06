#include "pso/network/TProtocol.h"

void TProtocol::send_lobby_name_request() {
    packet_header header;
    header.command = 0x8A;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
