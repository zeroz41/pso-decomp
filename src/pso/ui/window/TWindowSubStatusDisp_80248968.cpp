#include "types.h"
#include "pso/ui/window/TWindowCheckBox.h"

void TWindowCheckBox::set_selected_index(s16 selected_index) {
    this->selected_index = selected_index;
    cursor = selected_index;
    refresh_selected_entry(0);
}
