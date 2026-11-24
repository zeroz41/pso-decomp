#include "pso/network/protocol/packet_classes.h"

void TRecvPsoDataLong::bswap() {
    header.bswap();
}
