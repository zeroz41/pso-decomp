#include "types.h"
#include "pso/network/TRecvPsoData.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__12TRecvPsoDataFv(void) {
    bswap__13packet_headerFv();
}

}
