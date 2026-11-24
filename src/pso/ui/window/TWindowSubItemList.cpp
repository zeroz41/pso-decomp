#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItemList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#pragma readonly_strings on

extern s32 actor_frame_tick;

void TWindowSubItemList::draw_blinking_selection(WindowDrawContext *context) {
    s16 temp_r5;
    u16 *entry;
    temp_r5 = this->selected_index;
    if ((temp_r5 >= 0) && !(actor_frame_tick & 0x10)) {
        entry = (u16 *)(get_array_entry((s32) temp_r5));
        if (*entry & 1) {
            draw_selection_bar(context, (u8 *)entry, 1);
        }
    }
}

const char *TWindowSubItemList__class_name = "TWindowSubItemList";


extern "C" {

TWindowSubItemList *create_sub_item_list_window(const NJS_POINT2 *anchor, const NJS_POINT2 *position, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C(position, 0x24);
    return new TWindowSubItemList((u8 *)anchor, client);
}

}

#pragma push
#pragma fp_contract on
void TWindowSubItemList::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    draw_blinking_selection(context);
    draw_item_list_capacity(this, context, item_count, 0x1E);
    if (status_display != NULL) {
        static_cast<TWindowSubStatusDisp *>(status_display)->forward_render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}
#pragma pop

void TWindowSubItemList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubItemList::~TWindowSubItemList() {}

TWindowSubItemList::TWindowSubItemList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x24, client) {
    m_name = TWindowSubItemList__class_name;
    ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    create_menu_scroll_bar();
    reset_selected();
    item_count = 0;
}
