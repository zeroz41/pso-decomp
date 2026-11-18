#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_80268384.h"
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
extern s32 __vt__19TWindowSubEquipList[];
extern const char *TWindowSubEquipList__class_name;
void __dl__7TObjectFPv(void *);

u8 *create_equip_list_window(s32 arg0, s32 arg1, s16 arg2) {
    u8 *temp_r3;
    u8 *var_r0;
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 8);
    temp_r3 = (u8 *)(TObject::operator new(0x88));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowSubEquipList__ct(temp_r3, arg0, arg2));
    }
    return var_r0;
}

#pragma push
#pragma fp_contract on
void TWindowSubEquipList::render() {
    s32 temp_r3;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, (void *) (((u8 *)this) + 0x24), temp_r3);
    draw_selected_list_entry(temp_r3);
    if ((u32) this->status_display != 0U) {
        forward_render__20TWindowSubStatusDispFv(this->status_display, temp_r3);
    }
}
#pragma pop

void TWindowSubEquipList::run_task() { { (void)(this->TWindowMenuIconLine::run_task()); return; } }

void *__dt__19TWindowSubEquipListFv(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(s32 **)((s8 *)window_sub_status_disp + 0x18) = __vt__19TWindowSubEquipList;
        __dt__19TWindowMenuIconLineFv(window_sub_status_disp, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}
u8 *TWindowSubEquipList__ct(u8 *window_menu_icon_line, s32 arg1, s16 arg2) {
    fn_802683F4((window_menu_icon_line), (arg1), 8, (arg2));
    *(s32 **)((s8 *)window_menu_icon_line + 0x18) = __vt__19TWindowSubEquipList;
    *(s32 *)((s8 *)window_menu_icon_line + 0) = (s32) ((s32)TWindowSubEquipList__class_name);
    ((TWindowMenuIconLine *)window_menu_icon_line)->ensure_status_display((int) (TWindowSubStatusDisp::get_message_10(0x25)));
    return window_menu_icon_line;
}

}
