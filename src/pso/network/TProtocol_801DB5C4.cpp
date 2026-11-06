#include "pso/network/TProtocol.h"

void TProtocol::send_quest_menu_closed() {
    packet_header header;
    memset(&header, 0, sizeof(header));
    header.command = 0xA9;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
