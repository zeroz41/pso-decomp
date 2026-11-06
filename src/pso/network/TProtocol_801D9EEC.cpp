#include "pso/network/TProtocol.h"

void TProtocol::send_quest_barrier() {
    packet_header header;
    header.command = 0xAC;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
