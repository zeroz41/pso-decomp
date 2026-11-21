#include "types.h"
#include "pso/item/TItemData.h"


s32 TItemData::get_stack_count() {
    u8 count;

    if (TItemData::lookup_item_def(this) != 0) {
        count = data1.data_u8[5];
        if (count != 0) {
            return count;
        }
    }
    return 1;
}
