#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
s32 TWindowMessagePage::is_message_window_ready() {
    WindowTextEntry *e;
    u32 i;
    if (is_window_reveal_complete() == 0) {
        return 0;
    }
    if (scroll_offset[1] != target_scroll_y) {
        return 0;
    }
    for (i = 0; i < line_count; i++) {
        e = (WindowTextEntry *)get_array_entry(i);
        if (e->get_text() != NULL && !(e->flags & 0x10)) {
            return 0;
        }
    }
    return 1;
}

void TWindowMessage::complete_reveal() {
    TWindowMessageLine *line_list;
    u32 i;
    WindowTextEntry *e;
    open_tick = 0x01000000;
    scroll_offset[1] = target_scroll_y;
    for (i = 0; i < line_count; i++) {
        e = (WindowTextEntry *)get_array_entry(i);
        line_list = lines;
        if (e->get_text() != NULL) {
            if (line_list[i].flags & 8) {
                line_list[i].flags &= ~8;
                e->flags &= ~8;
            }
            e->reveal_all();
        }
    }
}
