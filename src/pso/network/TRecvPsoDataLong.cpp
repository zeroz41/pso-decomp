#include "types.h"
#include "pso/network/TRecvPsoDataLong.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__16TRecvPsoDataLongFv(void) {
    bswap__13packet_headerFv();
}

}
