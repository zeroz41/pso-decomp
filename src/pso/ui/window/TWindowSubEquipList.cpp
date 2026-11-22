#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"


#pragma readonly_strings on


const char *TWindowSubEquipList__class_name = "TWindowSubEquipList";


extern "C" {
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);

u8 *create_equip_list_window(saddr parent, saddr position, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)position, 8);
    return (u8 *)new TWindowSubEquipList((u8 *)parent, client);
}

}

#pragma push
#pragma fp_contract on
void TWindowSubEquipList::render() {
    saddr draw_context;
    draw_context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((void *) (((u8 *)this) + 0x24)),
        reinterpret_cast<WindowDrawContext *>(draw_context));
    draw_selected_list_entry(draw_context);
    if ((uaddr) this->status_display != 0U) {
        ((TWindowSubStatusDisp *)((void *)(this->status_display)))->forward_render((void *)(draw_context));
    }
}
#pragma pop

void TWindowSubEquipList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubEquipList::~TWindowSubEquipList() {}

TWindowSubEquipList::TWindowSubEquipList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 8, client) {
    m_name = TWindowSubEquipList__class_name;
    ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x25));
}
