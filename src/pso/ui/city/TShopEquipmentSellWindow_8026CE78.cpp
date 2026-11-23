#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowQuantity.h"

// Shows how many of the item the player carries (1 for an item that does not stack).
void TWindowQuantity::set_entry_count(TItem *item) {
    s32 amount;
    void *entry;

    entry = get_array_entry(1);
    if (item == NULL) {
        *(s32 *)((s8 *)entry + 0x20) = 0;
        return;
    }
    amount = item->get_amount();
    if (amount <= 0) {
        *(s32 *)((s8 *)entry + 0x20) = 1;
        return;
    }
    *(s32 *)((s8 *)entry + 0x20) = amount;
}
