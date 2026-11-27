#include "types.h"
#include "pso/item/TItemData.h"


void TItemData::set_stack_count(u8 count) {
    if (lookup_item_def() != 0) {
        data1.data_u8[5] = count;
        return;
    }
    if (data1.data_u8[0] == 3) {
        data1.data_u8[5] = 0;
    }
}
