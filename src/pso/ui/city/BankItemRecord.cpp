#include "types.h"
#include "pso/ui/city/BankItemRecord.h"

void BankItemRecord::sort_records(s32 count, s32 key) {
    s32 i;
    s32 j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            switch (key) {
            case 0:
                if (item_class_greater(&this[i], &this[j]) != 0) {
                    this[i].swap_item_data(&this[j]);
                }
                break;
            case 1:
                if (item_type_greater(&this[i], &this[j]) != 0) {
                    this[i].swap_item_data(&this[j]);
                }
                break;
            case 2:
                if (item_code_greater(&this[i], &this[j]) != 0) {
                    this[i].swap_item_data(&this[j]);
                }
                break;
            }
        }
    }
}

s32 item_code_greater(BankItemRecord *a, BankItemRecord *b) {
    u32 b_class, a_class;

    a_class = a->item.data1.data_u8[0];
    b_class = b->item.data1.data_u8[0];
    if (a_class > b_class) {
        return 1;
    }
    if (a_class == b_class) {
        u32 b_type, a_type;
        a_type = a->item.data1.data_u8[1];
        b_type = b->item.data1.data_u8[1];
        if (a_type > b_type) {
            return 1;
        }
        if (a_type == b_type) {
            if (a->item.data1.data_u8[2] > b->item.data1.data_u8[2]) {
                return 1;
            }
        }
    }
    return 0;
}

s32 item_type_greater(BankItemRecord *a, BankItemRecord *b) {
    u8 b_class;
    u8 a_class;

    a_class = a->item.data1.data_u8[0];
    b_class = b->item.data1.data_u8[0];
    if (a_class > b_class) {
        return 1;
    }
    if (a_class == b_class && a->item.data1.data_u8[1] > b->item.data1.data_u8[1]) {
        return 1;
    }
    return 0;
}

s32 item_class_greater(BankItemRecord *a, BankItemRecord *b) {
    return a->item.data1.data_u8[0] > b->item.data1.data_u8[0];
}

void BankItemRecord::swap_item_data(BankItemRecord *other) {
    BankItemRecord tmp;

    tmp = *this;
    *this = *other;
    *other = tmp;
}
