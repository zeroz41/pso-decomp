#include "types.h"
#include "pso/item/TItemData.h"


void TItemData::set_stack_count(u8 count) {
    if (TItemData::lookup_item_def(this) != 0) {
        data1.data_u8[5] = count;
        return;
    }
    if (data1.data_u8[0] == 3) {
        data1.data_u8[5] = 0;
    }
}
