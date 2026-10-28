#include "types.h"
#include "pso/item/TItemData.h"

extern "C" {
s32 lookup_item_def__9TItemDataFPv();
}

void TItemData::set_stack_count(u8 count) {
    if (lookup_item_def__9TItemDataFPv() != 0) {
        data1.data_u8[5] = count;
        return;
    }
    if (data1.data_u8[0] == 3) {
        data1.data_u8[5] = 0;
    }
}
