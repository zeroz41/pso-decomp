#include "pso/ui/window/WindowScrollBar.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/HeadingEntry.h"


TWindowSubEquipKind *create_equip_kind_window(const NJS_POINT2 *position, const NJS_POINT2 *size, s32 client) {
    set_menu_icon_line_params(size, 0x1F);
    return new TWindowSubEquipKind((u8 *)position, client);
}


void TWindowSubEquipKind::render() {
    WindowDrawContext *context;

    context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    if (trade_state != 4) {
        draw_tab_label(context);
    }
    if (status_display != NULL) {
        status_display->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowSubEquipKind::run_task() {
    int count;

    TWindowMenuIconLine::run_task();
    count = state_timer;
    if (count != 0) {
        state_timer = count - 1;
    }
}

TWindowSubEquipKind::~TWindowSubEquipKind() {}

TWindowSubEquipKind::TWindowSubEquipKind(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x1F, client) {
    m_name = TWindowSubEquipKind::class_name;
    create_menu_scroll_bar();
    trade_state = 4;
    state_timer = 0;
}
