#include "types.h"
#include "pso/ui/window/TWindowCheckBox.h"

void TWindowCheckBox::add_menu_item(s32 text, s32 item) {
    append_entry(0, text, item, 1, 0);
}
