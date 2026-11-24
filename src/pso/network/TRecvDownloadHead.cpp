#include "pso/network/protocol/packet_classes.h"

void TRecvDownloadHead::bswap() {
    header.bswap();
    bswap_32(&file_size);
}
