#include "types.h"
#include "pso/player/TPlyInventoryItem.h"
#include "pso/system/byteswap.h"
#include "pso/item/TItemData.h"


void bswap__17TPlyInventoryItemFv(saddr arg0) {
    bswap_32((u32 *)(arg0 + 4));
    ((TItemData *)(arg0 + 8))->bswap();
}

