#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"

void TShopEquipmentSellWindow::set_entry_count(void *window, void *item) {
    s32 amount;
    void *entry;

    entry = ((TWindowBase *)window)->get_array_entry(1);
    if (item == NULL) {
        *(s32 *)((s8 *)entry + 0x20) = 0;
        return;
    }
    amount = ((TItem *)item)->get_amount();
    if (amount <= 0) {
        *(s32 *)((s8 *)entry + 0x20) = 1;
        return;
    }
    *(s32 *)((s8 *)entry + 0x20) = amount;
}
