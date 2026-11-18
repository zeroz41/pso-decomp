#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItemList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_80268384.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#pragma readonly_strings on

void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 actor_frame_tick;

void TWindowSubItemList::sub_8027ACF8(u8 *window_key_board_soft) {
    u8 *arg0 = (u8 *)this;
    s16 temp_r5;
    u16 *temp_r3;
    temp_r5 = *(s16 *)((s8 *)arg0 + 0x88);
    if ((temp_r5 >= 0) && !(actor_frame_tick & 0x10)) {
        temp_r3 = (u16 *)(((TWindowBase *)arg0)->get_array_entry((s32) temp_r5));
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
    if ((u32) this->status_display != 0U) {
        forward_render__20TWindowSubStatusDispFv(this->status_display, window_key_board_soft);
    }
    if ((u32) this->unk_84 != 0U) {
        draw_window_scrollbar(this->unk_84, window_key_board_soft, (u8 *)&this->m_68);
    }
}
#pragma pop

void TWindowSubItemList::run_task() { { (void)(this->TWindowMenuIconLine::run_task()); return; } }

void *__dt__18TWindowSubItemListFv(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(s32 **)((s8 *)window_sub_status_disp + 0x18) = __vt__18TWindowSubItemList;
        __dt__19TWindowMenuIconLineFv(window_sub_status_disp, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}
u8 *TWindowSubItemList__ct(u8 *arg0, s32 arg1, s16 arg2) {
    fn_802683F4((arg0), (arg1), 0x24, (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TWindowSubItemList;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TWindowSubItemList__class_name;
    ((TWindowMenuIconLine *)arg0)->ensure_status_display((int) (TWindowSubStatusDisp::get_message_10(0x24)));
    ((TWindowMenuIconLine *)arg0)->create_menu_scroll_bar();
    ((TWindowSubItem *)arg0)->reset_selected();
    ((TWindowSubItemList *)arg0)->m_8c = 0;
    return arg0;
}

}
