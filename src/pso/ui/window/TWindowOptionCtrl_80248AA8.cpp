#include "types.h"
#include "pso/ui/window/TUnk_804CE7E8.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

void TWindowOptionCtrl::add_menu_item(saddr check_box_window, s32 arg2, s32 item) {
    ((TWindowSubStatusDisp *)check_box_window)->append_entry(0, arg2, item, 1, 0);
}

void TWindowSubStatusDisp::draw_status(saddr window, s32 arg2, s32 item) {
    ((TWindowSubStatusDisp *)window)->append_entry(0, arg2, item, 0, 1);
}

void TWindowSubStatusDisp::dispatch_without_flags(saddr window, s32 arg2, s32 item) {
    ((TWindowSubStatusDisp *)window)->append_entry(0, arg2, item, 0, 0);
}

void TWindowCheckBox::sync_level_field() {
    s16 cursor;

    if (*(s16 *)((s8 *)this + 0x88) != (cursor = this->cursor)) {
        *(s16 *)((s8 *)this + 0x88) = cursor;
        advance_all_entries(1);
    }
}
