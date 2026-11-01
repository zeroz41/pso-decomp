#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_80268384.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubItemList.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowSubItemList__class_name = "TWindowSubItemList";
}


struct RecoveredGlobal_8027AEDC___vt__18TWindowSubItemList { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_8027AEDC___vt__18TWindowSubItemList_size[sizeof(RecoveredGlobal_8027AEDC___vt__18TWindowSubItemList) == 0x20 ? 1 : -1];

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_item_list_capacity(void *, int, int, int);
s32 draw_window_scrollbar(void *, int, void *);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
u8 *__nw__7TObjectFUl(s32);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);
extern s32 __vt__18TWindowSubItemList[];
extern const char *TWindowSubItemList__class_name;
void __dl__7TObjectFPv(void *);

u8 *create_sub_item_list_window(s32 arg0, s32 arg1, s16 arg2) {
    u8 *temp_r3;
    u8 *var_r0;
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 0x24);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x90));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowSubItemList__ct(temp_r3, arg0, arg2));
    }
    return var_r0;
}

#pragma push
#pragma fp_contract on
void TWindowSubItemList::render() {
    u8 *arg0 = (u8 *)this;
    s32 window_key_board_soft;
    window_key_board_soft = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)window_key_board_soft);
    draw_visible_window_entries(arg0, arg0 + 0x24, window_key_board_soft);
    ((TWindowMenuIconLine *)arg0)->draw_selected_list_entry(window_key_board_soft);
    ((TWindowSubItemList *)arg0)->sub_8027ACF8((u8 *)window_key_board_soft);
    draw_item_list_capacity(arg0, window_key_board_soft, this->m_8c, 0x1E);
    if ((u32) *(u32 *)&this->status_display != 0U) {
        forward_render__20TWindowSubStatusDispFv(this->status_display, window_key_board_soft);
    }
    if ((u32) *(u32 *)&this->unk_84 != 0U) {
        draw_window_scrollbar(*(void * *)&this->unk_84, window_key_board_soft, (u8 *)&this->m_68);
    }
}
#pragma pop

void TWindowSubItemList::run_task() { { (void)(run_task__19TWindowMenuIconLineFv((u8 *)this)); return; } }

void *__dt__18TWindowSubItemListFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TWindowSubItemList;
        ((TWindowSubStatusDisp *)arg0)->destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowSubItemList__ct(u8 *arg0, s32 arg1, s16 arg2) {
    fn_802683F4((arg0), (arg1), 0x24, (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8027AEDC___vt__18TWindowSubItemList *)&__vt__18TWindowSubItemList).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TWindowSubItemList__class_name;
    ((TWindowMenuIconLine *)arg0)->ensure_status_display((int) (TWindowSubStatusDisp::get_message_10(0x24)));
    ((TWindowMenuIconLine *)arg0)->create_menu_scroll_bar();
    ((TWindowSubItem *)arg0)->reset_selected();
    ((TWindowSubItemList *)arg0)->m_8c = 0;
    return arg0;
}

}
