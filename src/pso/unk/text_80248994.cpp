#include "pso/unk/TWindowLayoutEntry.h"
#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowCheckBox.h"

void TWindowCheckBox::sub_80248994(u32 color, s32 item) {
    s32 i;
    ItemListRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = static_cast<ItemListRow *>(get_array_entry(i));
        if (e != NULL && e->is_flag_4_set() != 0 && item == e->get_item()) {
            e->category_style = color;
            e->style = color;
        }
    }
}
