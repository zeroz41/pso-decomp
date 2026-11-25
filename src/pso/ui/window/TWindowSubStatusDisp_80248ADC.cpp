#include "types.h"
#include "pso/ui/window/TWindowCheckBox.h"

void TWindowCheckBox::draw_status(s32 text, s32 item) {
    append_entry(0, text, item, 0, 1);
}

void TWindowCheckBox::dispatch_without_flags(s32 text, s32 item) {
    append_entry(0, text, item, 0, 0);
}

void TWindowCheckBox::sync_level_field() {
    s16 cursor;

    if (selected_index != (cursor = this->cursor)) {
        selected_index = cursor;
        advance_all_entries(1);
    }
}
