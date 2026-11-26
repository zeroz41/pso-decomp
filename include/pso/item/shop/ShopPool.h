#ifndef PSO_ITEM_SHOP_SHOPPOOL_H
#define PSO_ITEM_SHOP_SHOPPOOL_H

#include "types.h"

// A draw pool of up to 100 entry ids (shop stock kinds, bonus types, appraisal steps): an id
// goes in as many times as its weight, the pool is shuffled and draws take the last id.
class ShopPool {
public:
    s32 pop();
    void shuffle_n_times(s32 times);
    void shuffle();
    void push(u8 entry);
    void clear();

    u8 entries[100];
    s32 count;
};
LAYOUT_ASSERT(ShopPoolSize, sizeof(ShopPool) == 0x68);

#endif
