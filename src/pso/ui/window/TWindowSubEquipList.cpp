#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"


#pragma readonly_strings on


const char *TWindowSubEquipList__class_name = "TWindowSubEquipList";


extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);

u8 *create_equip_list_window(s32 parent, s32 position, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)position, 8);
    return (u8 *)new TWindowSubEquipList((u8 *)parent, client);
}

}

#pragma push
#pragma fp_contract on
void TWindowSubEquipList::render() {
    s32 temp_r3;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, (void *) (((u8 *)this) + 0x24), temp_r3);
    draw_selected_list_entry(temp_r3);
    if ((uaddr) this->status_display != 0U) {
        forward_render__20TWindowSubStatusDispFv(this->status_display, temp_r3);
    }
}
#pragma pop

void TWindowSubEquipList::run_task() { TWindowMenuIconLine::run_task(); }

TWindowSubEquipList::~TWindowSubEquipList() {}

TWindowSubEquipList::TWindowSubEquipList(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 8, client) {
    m_name = TWindowSubEquipList__class_name;
    ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x25));
}
