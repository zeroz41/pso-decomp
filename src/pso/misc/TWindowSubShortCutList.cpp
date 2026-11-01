#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCardList_8026CB08.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowChat.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Obj_8027E558 { s32 f0; u8 pad[0x14]; void *vt; u8 pad2[0x88 - 0x1C]; void *list; };

extern "C" {
void TShopJudgmentItemWindow__sub_80267F9C(void *, int);
void *__nw__7TObjectFUl(int);
extern s32 lbl_8044FAA8[];
void fn_802683F4(void *, void *, s32, s16);
void *init__21TWindowSubComCardListFiii(void *, s8, s32, s32);
extern s32 __vt__22TWindowSubShortCutList[];
extern s32 TWindowSubShortCutList__class_name;
extern s32 local_client_id;
void *TWindowSubShortCutList__ct(void *arg0, void *arg1, void *arg2);
s32 get_shared_text_buffer();
s32 fn_80076BC4(s32 *);
int get_chat_shortcut(s32 arg0);
s32 get_symbol_chat_data__20TWindowSubSymbolChatFv();
s8 get_type__20TWindowSubStatusDispFv(s32);
s32 clamp_selection_to_valid_entry__20TShopArmorListWindowFv(void *);
s32 save_cursor_selection__20TShopArmorListWindowFv();
s32 reset_list__19TWindowMenuIconLineFv(void *);
s32 update_state__9TWindowDDFv(s32 *, s32, u16);
void *__dt__22TWindowSubShortCutListFv(void *arg0, s16 arg1);
void render__22TWindowSubShortCutListFv(u8 *arg0);
s32 handle_list_page_flip_input(s32);
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 run_task__19TWindowMenuIconLineFv();
s32 draw_list_page_indicator(s32, s32);
void __dl__7TObjectFPv(void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

void TWindowSubShortCutList::refresh_entries() {
    s32 *chat_shortcut;
    s32 temp_r0;
    s32 var_r30;
    s32 var_r29;
    save_cursor_selection__20TShopArmorListWindowFv();
    reset_list__19TWindowMenuIconLineFv(this);
    var_r29 = get_type__20TWindowSubStatusDispFv(this->m_88);
    var_r30 = 0;
    var_r29 *= 4;
    do {
        chat_shortcut = (s32 *)get_chat_shortcut(var_r29);
        switch (*chat_shortcut) {
        case 0:
            draw_entry(var_r29, 0x33, 0, var_r29);
            break;
        case 1:
            temp_r0 = fn_80076BC4(chat_shortcut + 1);
            draw_entry(var_r29, 0x12, temp_r0, var_r29);
            break;
        case 2:
            update_state__9TWindowDDFv(chat_shortcut + 1, get_shared_text_buffer(), (u16) local_client_id);
            draw_entry(var_r29, 0x10, get_shared_text_buffer(), var_r29);
            break;
        case 3:
            TWindowChat::open_symbol_chat(chat_shortcut + 1);
            {
                s32 d = get_symbol_chat_data__20TWindowSubSymbolChatFv();
                draw_entry(var_r29, 0x11, d, var_r29);
            }
            break;
        }
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r30 < 4);
    clamp_selection_to_valid_entry__20TShopArmorListWindowFv(this);
}

void *TWindowSubShortCutList::create(void *arg1) {
    void *p;
    TShopJudgmentItemWindow__sub_80267F9C(lbl_8044FAA8, 4);
    p = __nw__7TObjectFUl(0x8C);
    if (p != 0) {
        p = TWindowSubShortCutList__ct(p, this, arg1);
    }
    return p;
}

void render__22TWindowSubShortCutListFv(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    ((TWindowMenuIconLine *)arg0)->draw_selected_list_entry(temp_r3);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        forward_render__20TWindowSubStatusDispFv(*(u32 *)((s8 *)arg0 + 0x80), temp_r3);
    }
    if ((u32) ((TWindowSubShortCutList *)arg0)->m_88 != 0U) {
        draw_list_page_indicator(((TWindowSubShortCutList *)arg0)->m_88, temp_r3);
    }
}

void TWindowSubShortCutList::run_task() {
    run_task__19TWindowMenuIconLineFv();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->m_88) != 0)) {
        refresh_entries();
    }
}

void *__dt__22TWindowSubShortCutListFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TWindowSubShortCutList;
        delete_if_allocated((s32)(*(void **)((s8 *)arg0 + 0x88)), 1);
        ((TWindowSubStatusDisp *)arg0)->destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void *TWindowSubShortCutList__ct(void *window_sub_short_cut_list, void *arg1, void *arg2) {
    s32 row;
    s32 col;
    void *p;
    fn_802683F4(window_sub_short_cut_list, arg1, 4, local_client_id);
    ((Obj_8027E558 *)window_sub_short_cut_list)->vt = ((s32 *)&__vt__22TWindowSubShortCutList);
    ((Obj_8027E558 *)window_sub_short_cut_list)->f0 = TWindowSubShortCutList__class_name;
    row = (s32)arg2 / 4;
    col = (s32)arg2 % 4;
    ((TWindowMenuIconLine *)window_sub_short_cut_list)->ensure_status_display((s32)(TWindowSubStatusDisp::get_message_10(0x2D)));
    p = ::operator new(0xC);
    if (p != NULL) {
        p = init__21TWindowSubComCardListFiii(p, row, 5, local_client_id);
    }
    ((Obj_8027E558 *)window_sub_short_cut_list)->list = p;
    ((TWindowSubShortCutList *)window_sub_short_cut_list)->set_flag70_bit10();
    ((TWindowSubShortCutList *)window_sub_short_cut_list)->refresh_entries();
    ((TWindowSubShortCutList *)window_sub_short_cut_list)->set_cursor_index(col);
    return window_sub_short_cut_list;
}

}
