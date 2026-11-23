#include "types.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include "pso/system/THeap.h"
#include "pso/system/GbaAramCache.h"

extern "C" {

void __dl__9TProtocolFPv(saddr arg0) {
    obj_heap->heap_free((void *)arg0);
}

void set_lobby_count_value(void) { lobby_count_value = 1; }
}

void bswap_ply_smth_pair(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); }
