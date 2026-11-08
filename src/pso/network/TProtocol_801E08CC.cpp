#include "types.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"

extern "C" {

s32 heap_free__5THeapFPv(s32, s32);

extern s32 obj_heap;

void __dl__9TProtocolFPv(s32 arg0) {
    heap_free__5THeapFPv(obj_heap, arg0);
}

    extern int lobby_count_value;
void set_lobby_count_value(void) { lobby_count_value = 1; }

void bswap_ply_smth_pair(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); }

}
