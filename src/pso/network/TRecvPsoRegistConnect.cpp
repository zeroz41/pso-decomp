#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TRecvPsoRegistConnect.h"
#include "pso/system/byteswap.h"

extern "C" {


void bswap__21TRecvPsoRegistConnectFv(s32 arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 0x44));
    bswap_32((u32 *)(arg0 + 0x48));
}

}
