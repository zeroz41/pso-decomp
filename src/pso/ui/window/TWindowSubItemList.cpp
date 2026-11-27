#include "pso/ui/window/WindowScrollBar.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItemList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/player/LocalClientId.h"
#pragma readonly_strings on

void TWindowSubItemList::draw_blinking_selection(WindowDrawContext *context) {
    s16 selected;
    TWindowLayoutRect *entry;
    selected = this->selected_index;
    if ((selected >= 0) && !(actor_frame_tick & 0x10)) {
        entry = (TWindowLayoutRect *)get_array_entry((s32) selected);
        if (entry->flags & 1) {
            draw_selection_bar(context, entry, 1);
        }
    }
}

const char *TWindowSubItemList::class_name = "TWindowSubItemList";



TWindowSubItemList *create_sub_item_list_window(const NJS_POINT2 *anchor, const NJS_POINT2 *position, s32 client) {
    set_menu_icon_line_params(position, 0x24);
    return new TWindowSubItemList((u8 *)anchor, client);
}


#pragma push
#pragma fp_contract on
void TWindowSubItemList::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    draw_blinking_selection(context);
    draw_item_list_capacity(context, item_count, 0x1E);
    if (status_display != NULL) {
        status_display->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}
#pragma pop

void TWindowSubItemList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubItemList::~TWindowSubItemList() {}

TWindowSubItemList::TWindowSubItemList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x24, client) {
    m_name = TWindowSubItemList::class_name;
    ensure_status_display(TWindowSubStatusDisp::get_message_10(0x24));
    create_menu_scroll_bar();
    reset_selected();
    item_count = 0;
}
