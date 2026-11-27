#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowQuantity.h"
#include "pso/unk/TWindowLayoutNumber.h"

// Shows how many of the item the player carries (1 for an item that does not stack).
void TWindowQuantity::set_entry_count(TItem *item) {
    s32 amount;
    TWindowLayoutNumber *entry;

    entry = (TWindowLayoutNumber *)get_array_entry(1);
    if (item == NULL) {
        entry->value = 0;
        return;
    }
    amount = item->get_amount();
    if (amount <= 0) {
        entry->value = 1;
        return;
    }
    entry->value = amount;
}
