#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/TRecvGenerateID.h"
#include "pso/system/byteswap.h"

extern "C" {


void bswap__15TRecvGenerateIDFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_generate_id_payload((void*)(arg0 + 8));
}
}

void bswap_generate_id_payload(void* p) { bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); }
