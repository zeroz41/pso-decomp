#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TRecvPort.h"
#include "pso/system/byteswap.h"

extern "C" {


void bswap__9TRecvPortFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 8));
}

}
