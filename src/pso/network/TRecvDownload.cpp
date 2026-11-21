#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TRecvDownload.h"
#include "pso/system/byteswap.h"

extern "C" {


void bswap__13TRecvDownloadFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 0x414));
}

}
