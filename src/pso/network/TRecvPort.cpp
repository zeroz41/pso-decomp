#include "pso/network/protocol/packet_classes.h"

void TRecvPort::bswap() {
    header.bswap();
    bswap_32(&ip_addr);
    bswap_16((u16 *)&port);
}
