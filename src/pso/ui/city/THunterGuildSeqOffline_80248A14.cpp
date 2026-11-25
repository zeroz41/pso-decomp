#include "pso/unk/TWindowLayoutEntry.h"
#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowCheckBox.h"

void TWindowCheckBox::advance_matching_entries(s32 arg1, s32 arg2) {
    s32 i;
    ItemListRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = static_cast<ItemListRow *>(get_array_entry(i));
        if (e != NULL && e->is_flag_4_set() != 0 && arg2 == e->get_item()) {
            if (arg1 != 0) {
                e->finalize_state();
            } else {
                e->advance_state();
            }
        }
    }
}
