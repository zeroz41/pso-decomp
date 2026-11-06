#include "pso/network/TProtocol.h"

void TProtocol::send_server_time_request() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0xB1;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}

void TProtocol::send_server_time_accepted() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0x99;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}
