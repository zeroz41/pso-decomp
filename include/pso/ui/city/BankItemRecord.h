#ifndef PSO_UI_CITY_BANKITEMRECORD_H
#define PSO_UI_CITY_BANKITEMRECORD_H

#include "types.h"
#include "pso/item/TItemData.h"

// One of the 200 item records the bank keeps per player slot.
struct BankItemRecord {
    BankItemRecord();
    void init();
    BankItemRecord &operator=(BankItemRecord &src);
    void swap_item_data(BankItemRecord *other);
    void sort_records(s32 count, s32 key);
    s32 is_empty();

    TItemData item;
    s16 amount;     // the stack held
    s16 used;       // 0 for an empty record
};

// The bank's sort keys, as sort_shop_items': 1 when `a` sorts after `b`.
s32 item_code_greater(BankItemRecord *a, BankItemRecord *b);
s32 item_type_greater(BankItemRecord *a, BankItemRecord *b);
s32 item_class_greater(BankItemRecord *a, BankItemRecord *b);

#endif
