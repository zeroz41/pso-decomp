#ifndef PSO_ITEM_SHOP_SHOPPOOL_H
#define PSO_ITEM_SHOP_SHOPPOOL_H

#include "types.h"

// Shop stock draw pool: up to 100 entry ids and their count (pop_byte/push_shop_pool_entry).
struct ShopPool {
    u8 entries[0x64];
    s32 count;
    u8 pad_68[0xC];
};

#endif
