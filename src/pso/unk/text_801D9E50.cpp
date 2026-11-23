#include "types.h"
#include "pso/network/TProtocol.h"

void TProtocol::send_keepalive() {
    packet_header tmp;
    tmp.command = 0x1D;
    tmp.flags = 0;
    tmp.size = sizeof(tmp);
    tmp.bswap();
    send((u8 *)&tmp, sizeof(tmp));
}
