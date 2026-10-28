#include "types.h"
#include "pso/item/TItemData.h"

extern "C" {
s32 lookup_item_def__9TItemDataFPv();
}

s32 TItemData::get_stack_count() {
    u8 count;

    if (lookup_item_def__9TItemDataFPv() != 0) {
        count = data1.data_u8[5];
        if (count != 0) {
            return count;
        }
    }
    return 1;
}
