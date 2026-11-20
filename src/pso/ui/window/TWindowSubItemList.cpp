#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItemList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#pragma readonly_strings on

void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 actor_frame_tick;

void TWindowSubItemList::sub_8027ACF8(u8 *window_key_board_soft) {
    s16 temp_r5;
    u16 *temp_r3;
    temp_r5 = this->m_88;
    if ((temp_r5 >= 0) && !(actor_frame_tick & 0x10)) {
        temp_r3 = (u16 *)(get_array_entry((s32) temp_r5));
        if (*temp_r3 & 1) {
            draw_selection_bar(window_key_board_soft, (u8 *)temp_r3, 1);
        }
    }
}

const char *TWindowSubItemList__class_name = "TWindowSubItemList";


extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_item_list_capacity(void *, int, int, int);
s32 draw_window_scrollbar(void *, int, void *);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);

u8 *create_sub_item_list_window(s32 parent, s32 position, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)position, 0x24);
    return (u8 *)new TWindowSubItemList((u8 *)parent, client);
}

}

#pragma push
#pragma fp_contract on
void TWindowSubItemList::render() {
    s32 window_key_board_soft;
    window_key_board_soft = get_draw_context__11TWindowBaseFPv();
    draw_window_frame((void *)window_key_board_soft);
    draw_visible_window_entries(this, (u8 *)this + 0x24, window_key_board_soft);
    draw_selected_list_entry(window_key_board_soft);
    sub_8027ACF8((u8 *)window_key_board_soft);
    draw_item_list_capacity(this, window_key_board_soft, this->m_8c, 0x1E);
    if ((uaddr) this->status_display != 0U) {
        forward_render__20TWindowSubStatusDispFv(this->status_display, window_key_board_soft);
    }
    if ((uaddr) this->scroll_bar != 0U) {
        draw_window_scrollbar(this->scroll_bar, window_key_board_soft, (u8 *)&this->m_68);
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
