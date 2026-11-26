#include "types.h"
#include "pso/item/shop/ShopItemSort.h"
#include "pso/item/TItemData.h"

s32 get_item_def(TItemData *item) {
    if (item != NULL) {
        return TItemData::lookup_item_def(item);
    }
    return 0;
}

void sort_shop_items(TItemData *items, s32 count, s32 mode) {
    s32 i;
    s32 j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            switch (mode) {
            case 0:
                if (item_class_greater(&items[i], &items[j]) != 0) {
                    swap_shop_items(&items[i], &items[j]);
                }
                break;
            case 1:
                if (item_type_greater(&items[i], &items[j]) != 0) {
                    swap_shop_items(&items[i], &items[j]);
                }
                break;
            case 2:
                if (item_code_greater(&items[i], &items[j]) != 0) {
                    swap_shop_items(&items[i], &items[j]);
                }
                break;
            }
        }
    }
}

s32 item_code_greater(TItemData *a, TItemData *b) {
    u32 b_class, a_class;

    a_class = a->data1.data_u8[0];
    b_class = b->data1.data_u8[0];
    if (a_class > b_class) {
        return 1;
    }
    if (a_class == b_class) {
        u32 b_type, a_type;
        a_type = a->data1.data_u8[1];
        b_type = b->data1.data_u8[1];
        if (a_type > b_type) {
            return 1;
        }
        if (a_type == b_type) {
            if (a->data1.data_u8[2] > b->data1.data_u8[2]) {
                return 1;
            }
        }
    }
    return 0;
}

s32 item_type_greater(TItemData *a, TItemData *b) {
    u8 b_class;
    u8 a_class;

    a_class = a->data1.data_u8[0];
    b_class = b->data1.data_u8[0];
    if (a_class > b_class) {
        return 1;
    }
    if (a_class == b_class && a->data1.data_u8[1] > b->data1.data_u8[1]) {
        return 1;
    }
    return 0;
}

s32 item_class_greater(TItemData *a, TItemData *b) {
    return a->data1.data_u8[0] > b->data1.data_u8[0];
}

void swap_shop_items(TItemData *a, TItemData *b) {
    TItemData tmp;

    tmp.copy_from(a);
    a->copy_from(b);
    b->copy_from(&tmp);
}
