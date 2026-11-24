#include "pso/network/TProtocol.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include "pso/system/GbaAramCache.h"

void TProtocol::operator delete(void *ptr) {
    obj_heap->heap_free(ptr);
}

void set_lobby_count_value() {
    lobby_count_value = 1;
}

void bswap_ply_smth_pair(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); }
