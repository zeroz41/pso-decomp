#ifndef PSO_PLAYER_INVENTORYITEMLIST_H
#define PSO_PLAYER_INVENTORYITEMLIST_H

#include "types.h"
#include "pso/player/TPlyInventory.h"

// A player's inventory records saved as a count and up to 30 items.
struct InventoryItemList {
    s32 count;
    TPlyInventoryItem items[30];

    InventoryItemList();
    void bswap();
};

#endif
