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

void TWindowSubItemList::sub_8027ACF8(u8 *window_key_board_soft) {
    s16 temp_r5;
    u16 *entry;
    temp_r5 = this->m_88;
    if ((temp_r5 >= 0) && !(actor_frame_tick & 0x10)) {
        entry = (u16 *)(get_array_entry((s32) temp_r5));
        if (*entry & 1) {
            draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (u8 *)entry, 1);
        }
    }
}

const char *TWindowSubItemList__class_name = "TWindowSubItemList";


extern "C" {
s32 draw_item_list_capacity(void *, int, int, int);
s32 draw_window_scrollbar(void *, int, void *);

u8 *create_sub_item_list_window(saddr parent, saddr position, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C(reinterpret_cast<const NJS_POINT2 *>(position), 0x24);
    return (u8 *)new TWindowSubItemList((u8 *)parent, client);
}

}

#pragma push
#pragma fp_contract on
void TWindowSubItemList::render() {
    saddr window_key_board_soft;
    window_key_board_soft = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)window_key_board_soft);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        reinterpret_cast<WindowDrawContext *>(window_key_board_soft));
    draw_selected_list_entry(window_key_board_soft);
    sub_8027ACF8((u8 *)window_key_board_soft);
    draw_item_list_capacity(this, window_key_board_soft, this->m_8c, 0x1E);
    if ((uaddr) this->status_display != 0U) {
        ((TWindowSubStatusDisp *)((void *)(this->status_display)))->forward_render((void *)(window_key_board_soft));
    }
    if ((uaddr) this->scroll_bar != 0U) {
        draw_window_scrollbar(this->scroll_bar, window_key_board_soft, (u8 *)&this->scroll_offset[0]);
    }
}
#pragma pop

void TWindowSubItemList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubItemList::~TWindowSubItemList() {}

TWindowSubItemList::TWindowSubItemList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x24, client) {
    m_name = TWindowSubItemList__class_name;
    ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    create_menu_scroll_bar();
    ((TWindowSubItem *)this)->reset_selected();
    m_8c = 0;
}
