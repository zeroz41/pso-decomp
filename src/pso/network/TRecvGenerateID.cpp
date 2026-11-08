#include "types.h"
#include "pso/network/TRecvGenerateID.h"
#include "pso/system/byteswap.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__15TRecvGenerateIDFv(s32 arg0) {
    bswap__13packet_headerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_generate_id_payload((void*)(arg0 + 8));
}

void bswap_generate_id_payload(void* p) { bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); }

}
