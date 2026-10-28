#include "pso/item/TItemData.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A5930.h"
#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"

void TUnk_804A5930::use() {
    s32 arg0 = (s32)this;
    TItemData item_data;
    if (((TItem *)arg0)->get_kill_count() >= 0x59D8U) {
        item_data.data1.data_u8[0] = 0;
        item_data.data1.data_u8[1] = 0x32;
        item_data.data1.data_u8[2] = 0;
        replace_item_with_new_code(&item_data, (TItem *)arg0);
    }
}
