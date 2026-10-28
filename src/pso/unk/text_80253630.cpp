#include "types.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/item/TItem.h"

extern "C" {
void TWindowHelpItem::refresh_copied_items() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 temp_r3_3;
    u8 *item;
    u8 *temp_r3_4;
    temp_r3 = this->m_a0;
    if (temp_r3 != -1) {
        item = (u8 *)(find_item_by_id(temp_r3));
        if (item != NULL) {
            ((TItem *)item)->copy_to_item_data((TItemData *)((u8 *)&this->_pad74));
        }
    }
    temp_r3_3 = this->m_a4;
    if (temp_r3_3 != -1) {
        temp_r3_4 = (u8 *)(find_item_by_id(temp_r3_3));
        if (temp_r3_4 != NULL) {
            ((TItem *)temp_r3_4)->copy_to_item_data((TItemData *)(arg0 + 0x88));
        }
    }
}

}
