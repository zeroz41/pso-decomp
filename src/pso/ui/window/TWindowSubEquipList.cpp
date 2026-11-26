#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/HeadingEntry.h"


#pragma readonly_strings on


const char *TWindowSubEquipList::class_name = "TWindowSubEquipList";



TWindowSubEquipList *create_equip_list_window(const NJS_POINT2 *parent, const NJS_POINT2 *position, s32 client) {
    set_menu_icon_line_params(position, 8);
    return new TWindowSubEquipList((u8 *)parent, client);
}


#pragma push
#pragma fp_contract on
void TWindowSubEquipList::render() {
    WindowDrawContext *draw_context;
    draw_context = get_draw_context();
    draw_window_frame(draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((((u8 *)this) + 0x24)),
        draw_context);
    draw_selected_list_entry(draw_context);
    if (this->status_display != NULL) {
        this->status_display->render(draw_context);
    }
}
#pragma pop

void TWindowSubEquipList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubEquipList::~TWindowSubEquipList() {}

TWindowSubEquipList::TWindowSubEquipList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 8, client) {
    m_name = TWindowSubEquipList::class_name;
    ensure_status_display(TWindowSubStatusDisp::get_message_10(0x25));
}
