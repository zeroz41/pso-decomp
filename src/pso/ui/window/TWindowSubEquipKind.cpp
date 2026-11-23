#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 draw_window_scrollbar(void *, s32, void *);

TWindowSubEquipKind *create_equip_kind_window(saddr position, const NJS_POINT2 *size, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C(size, 0x1F);
    return new TWindowSubEquipKind(reinterpret_cast<u8 *>(position), client);
}

}

void TWindowSubEquipKind::render() {
    saddr context;

    context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        reinterpret_cast<WindowDrawContext *>(context));
    draw_selected_list_entry(context);
    if (m_88 != 4) {
        draw_tab_label((void *)context);
    }
    if (status_display != NULL) {
        ((TWindowSubStatusDisp *)((void *)(status_display)))->forward_render((void *)(context));
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, (u8 *)&scroll_offset[0]);
    }
}

void TWindowSubEquipKind::run_task() {
    int count;

    TWindowMenuIconLine::run_task();
    count = m_8a;
    if (count != 0) {
        m_8a = count - 1;
    }
}

TWindowSubEquipKind::~TWindowSubEquipKind() {}

TWindowSubEquipKind::TWindowSubEquipKind(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x1F, client) {
    m_name = TWindowSubEquipKind__class_name;
    create_menu_scroll_bar();
    m_88 = 4;
    m_8a = 0;
}
