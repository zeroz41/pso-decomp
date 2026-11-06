#include "types.h"
#include "pso/player/TPlyInventoryItem.h"
#include "pso/system/byteswap.h"

extern "C" {

void bswap__9TItemDataFv(s32 arg0);

void bswap__17TPlyInventoryItemFv(s32 arg0) {
    bswap_32((u32 *)(arg0 + 4));
    bswap__9TItemDataFv(arg0 + 8);
}

}
