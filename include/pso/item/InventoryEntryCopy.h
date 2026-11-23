#ifndef PSO_ITEM_INVENTORYENTRYCOPY_H
#define PSO_ITEM_INVENTORYENTRYCOPY_H

#include "types.h"

class TPlyInventoryItem;

extern "C" {
const TPlyInventoryItem *get_class_starting_inventory(s32 class_index);
TPlyInventoryItem *fn_801C1BA8(TPlyInventoryItem *destination, const TPlyInventoryItem *source);
void copy_entries(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *destination);
void copy_item_entry_array(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *destination);
}
#endif
