#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/item/TItemData.h"

s32 format_item_description(u8 *item);
extern s32 lbl_805DCDE0;

void TWindowHelpItem::format_description_with_price() {
    text_builder_reset();
    text_builder_append((u8 *)(format_item_description((u8 *)this->m_68)));
    text_builder_append((u8 *)&lbl_805DCDE0);
    text_builder_append((u8 *)(((TItemData *)(this->m_68))->calc_buy_price()));
}
