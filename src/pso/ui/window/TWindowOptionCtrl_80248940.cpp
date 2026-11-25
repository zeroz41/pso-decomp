#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowCheckBox.h"

s32 TWindowCheckBox::update_selected_item() {
    return static_cast<ItemListRow *>(get_array_entry(selected_index))->get_item();
}
