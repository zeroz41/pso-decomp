#include "types.h"
#include "pso/network/TRecvDownload.h"
#include "pso/system/byteswap.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__13TRecvDownloadFv(saddr arg0) {
    bswap__13packet_headerFv();
    bswap_32((u32 *)(arg0 + 0x414));
}

}
