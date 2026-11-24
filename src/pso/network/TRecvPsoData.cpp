#include "pso/network/protocol/packet_classes.h"

void TRecvPsoData::bswap() {
    header.bswap();
}
