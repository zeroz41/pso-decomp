#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/network/client_id.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"

void TWindowMenuIconLine::add_list_entry(u8 icon, s32 arg2, s32 arg3) {
    if (this->entry_count < this->entry_capacity) {
        ((ItemListRow *)get_array_entry(entry_count))->init_list_entry(icon, arg2, arg3);
        this->entry_count = (this->entry_count + 1);
    }
}

#pragma readonly_strings on



const char *TWindowShop::class_name = "TWindowShop";

// Item list window position per camera id (1, 2, 3-4).
static const NJS_POINT2 TShopJudgmentItemWindow__item_list_rect_table[3] = {
    { 385.0f, 184.0f }, { 385.0f, 104.0f }, { 300.0f, 104.0f }
};


void TWindowShop::init_list_window(s32 title) {
    this->m_name = TWindowShop::class_name;
    ensure_status_display(title);
    create_menu_scroll_bar();
    this->set_depth(39000.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        set_position_xy(0.75f, 0.75f);
    }
    this->capacity = 0;
}


TWindowShop *create_item_list_window(s32 title, s32 count, s32 client) {
    s32 camera_id;
    camera_id = TCameraCtrl::get_camera_id();
    switch (camera_id) {
    case 1:
        set_menu_icon_line_params(&TShopJudgmentItemWindow__item_list_rect_table[0], count);
        break;
    case 2:
        set_menu_icon_line_params(&TShopJudgmentItemWindow__item_list_rect_table[1], count);
        break;
    case 3:
    case 4:
        set_menu_icon_line_params(&TShopJudgmentItemWindow__item_list_rect_table[2], count);
        break;
    }
    return new TWindowShop(title, count, client);
}


TWindowShop *TShopJudgmentItemWindow::open_default(s32 title) {
    return create_item_list_window(title, 0x40, local_client_id);
}

#pragma push
#pragma fp_contract on
void TWindowShop::render() {
    WindowDrawContext *context;
    s32 n;
    context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        context);
    if (!(this->state_flags & 0x80)) {
        draw_selected_list_entry(context);
    }
    n = this->capacity;
    if (n > 0) {
        draw_item_list_capacity(context, this->entry_count, n);
    }
    if (status_display != NULL) {
        status_display->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}
#pragma pop

void TWindowShop::run_task() { TWindowMenuIconLine::run_task(); }

TWindowShop::~TWindowShop() {}

TWindowShop::TWindowShop(u8 *parent, s32 title, u32 count, u8 *descriptor)
    : TWindowMenuIconLine(parent, count, local_client_id, descriptor) {
    init_list_window(title);
}

TWindowShop::TWindowShop(s32 title, u32 count, s32 client)
    : TWindowMenuIconLine((u8 *)get_window_layout_position(0x26), count, client) {
    init_list_window(title);
}
