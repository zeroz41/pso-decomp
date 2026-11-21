#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TRecvDownloadHead.h"
#include "pso/system/byteswap.h"

extern "C" {


void bswap__17TRecvDownloadHeadFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 0x38));
}

}
