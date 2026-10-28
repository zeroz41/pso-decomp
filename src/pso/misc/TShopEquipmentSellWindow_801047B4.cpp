#include "types.h"
#include "pso/misc/TShopEquipmentSellWindow_801047B4.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/item/TItem.h"

s32 TShopEquipmentSellWindow::get_item_data_value(u32 arg0) {
    s32 sp8[4];

    if (arg0 != 0U) {
        ((TItem *)arg0)->copy_to_item_data((TItemData *)sp8);
        return ((TItemData *)sp8)->calc_price();
    }
    return 0;
}
s32 TShopEquipmentSellWindow::get_item_price_if_valid() {
    u32 arg0 = (u32)this;
    if (arg0 != 0U) {
        return ((TItemData *)arg0)->calc_price();
    }
    return 0;
}
s32 is_valid_drop_floor(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x12)) {
        return 1;
    }
    return 0;
}
s32 TObjPlayer__sub_80104840(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x24)) {
        return 1;
    }
    return 0;
}
