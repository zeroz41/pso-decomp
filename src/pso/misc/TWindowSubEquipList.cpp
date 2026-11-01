#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_80268384.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubEquipList.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowSubEquipList__class_name = "TWindowSubEquipList";
}


struct RecoveredGlobal_802793E4___vt__19TWindowSubEquipList { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_802793E4___vt__19TWindowSubEquipList_size[sizeof(RecoveredGlobal_802793E4___vt__19TWindowSubEquipList) == 0x20 ? 1 : -1];

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
u8 *__nw__7TObjectFUl(s32);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);
extern s32 __vt__19TWindowSubEquipList[];
extern const char *TWindowSubEquipList__class_name;
void __dl__7TObjectFPv(void *);

u8 *create_equip_list_window(s32 arg0, s32 arg1, s16 arg2) {
    u8 *temp_r3;
    u8 *var_r0;
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 8);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x88));
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

void TWindowSubEquipList::run_task() { { (void)(run_task__19TWindowMenuIconLineFv((u8 *)this)); return; } }

void *__dt__19TWindowSubEquipListFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSubEquipList;
        ((TWindowSubStatusDisp *)arg0)->destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowSubEquipList__ct(u8 *arg0, s32 arg1, s16 arg2) {
    fn_802683F4((arg0), (arg1), 8, (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802793E4___vt__19TWindowSubEquipList *)&__vt__19TWindowSubEquipList).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((s32)TWindowSubEquipList__class_name);
    ((TWindowMenuIconLine *)arg0)->ensure_status_display((int) (TWindowSubStatusDisp::get_message_10(0x25)));
    return arg0;
}

}
