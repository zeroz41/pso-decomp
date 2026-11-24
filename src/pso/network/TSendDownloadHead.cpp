#include "pso/network/protocol/packet_classes.h"

void TSendDownloadHead::bswap() {
    header.bswap();
}
