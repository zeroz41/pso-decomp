#ifndef PSO_PLAYER_TPLYITEMTYPES_H
#define PSO_PLAYER_TPLYITEMTYPES_H

#include "types.h"

struct InventorySortEntry {
    u32 key;
    TItem *val;
    InventorySortEntry();
    void set_key(TItem *item);
    // Non-const source: the original reloads other.val after storing key.
    InventorySortEntry &operator=(InventorySortEntry &other);
};

// The 8-byte list TPlyItem::sort_items allocates with new and frees with
// delete (the destructor's s16 argument is MWCC's delete flag).
struct InventorySortBuffer {
    s32 count;
    InventorySortEntry *items;
    InventorySortBuffer(s32 n);
    ~InventorySortBuffer();
    // Bubble-sorts records by key.
    void sort_by_key();
};

#endif
