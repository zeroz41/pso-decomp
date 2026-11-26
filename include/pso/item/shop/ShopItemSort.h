#ifndef PSO_ITEM_SHOP_SHOPITEMSORT_H
#define PSO_ITEM_SHOP_SHOPITEMSORT_H

#include "types.h"

struct TItemData;

// TItemData::lookup_item_def of the item, 0 for a null item.
s32 get_item_def(TItemData *item);

// Sorts a shop's stock in place: mode 0 by item class (data1[0]), 1 by class and type
// (data1[0..1]), 2 by the whole item code (data1[0..2]).
void sort_shop_items(TItemData *items, s32 count, s32 mode);
// 1 when `a` sorts after `b`.
s32 item_code_greater(TItemData *a, TItemData *b);
s32 item_type_greater(TItemData *a, TItemData *b);
s32 item_class_greater(TItemData *a, TItemData *b);
void swap_shop_items(TItemData *a, TItemData *b);

#endif
