#include "types.h"
#include "pso/network/TRecvPort.h"
#include "pso/system/byteswap.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__9TRecvPortFv(s32 arg0) {
    bswap__13packet_headerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 8));
}

}
