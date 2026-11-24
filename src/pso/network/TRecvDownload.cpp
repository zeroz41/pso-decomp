#include "pso/network/protocol/packet_classes.h"

void TRecvDownload::bswap() {
    header.bswap();
    bswap_32(&data_size);
}
