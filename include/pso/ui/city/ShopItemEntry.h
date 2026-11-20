#ifndef PSO_UI_CITY_SHOPITEMENTRY_H
#define PSO_UI_CITY_SHOPITEMENTRY_H

#include "types.h"

// One item a shop offers: the item's data with its price in place of the last data word.
struct ShopItemEntry {
    u8 data[12];
    u32 id;
    s32 price;
};

// The same entry seen as five words; the buy paths copy an entry this way.
struct ShopItemWords {
    u32 words[5];
};

typedef char ShopItemEntry_size[sizeof(ShopItemEntry) == 0x14 ? 1 : -1];

#endif
