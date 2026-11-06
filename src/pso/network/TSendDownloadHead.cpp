#include "types.h"
#include "pso/network/TSendDownloadHead.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__17TSendDownloadHeadFv(void) {
    bswap__13packet_headerFv();
}

}
