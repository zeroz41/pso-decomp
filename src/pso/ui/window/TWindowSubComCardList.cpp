#include "types.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/TWindowSubComCardList_8026CB08.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubCustomEquip_80275D9C.h"
#include "pso/ui/window/TWindowSubCustomSelect_80275D84.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on


const char *TWindowSubComCardList__class_name = "TWindowSubComCardList";


extern "C" {
u8 *TWindowMenu__ct(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void *init__21TWindowSubComCardListFiii(void *, s32, s8, s32);
extern s32 __vt__21TWindowSubComCardList[];
extern const char *TWindowSubComCardList__class_name;
extern s32 local_client_id;
u8 *TWindowSubComCardList__ct(u8 *arg0, void *arg1);
s32 count_leading_active__17TWindowSubComCardFPvi(s32, s32);
u8 *TWindowSubComCardList__sub_802757AC(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s8 arg4);
void render__21TWindowSubComCardListFv(TWindowSubComCardList *arg0);
s32 handle_list_page_flip_input(s32);
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_list_page_indicator(s32, s32);
void __dl__7TObjectFPv(void *);
void *__dt__11TWindowMenuFv(void *arg0, s16 arg1);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);
s32 run_task__11TWindowMenuFv();

void render__21TWindowSubComCardListFv(TWindowSubComCardList *arg0) {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, (u8 *)arg0 + 0x24, temp_r3);
    ((TWindowMenu *)arg0)->render_selected_entry(temp_r3);
    arg0->draw_card_list_selection((u8 *)temp_r3);
    if ((u32) arg0->m_88 != 0U) {
        forward_render__20TWindowSubStatusDispFv(arg0->m_88, temp_r3);
    }
    if ((u32) arg0->m_8c != 0U) {
        draw_list_page_indicator(arg0->m_8c, temp_r3);
    }
}

void TWindowSubComCardList::run_task() {
    run_task__11TWindowMenuFv();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->m_8c) != 0)) {
        set_selected_index(0);
        sub_80275360();
    }
}

TWindowSubComCardList::~TWindowSubComCardList() {
    delete_if_allocated((s32)m_8c, 1);
}

u8 *TWindowSubComCardList__ct(u8 *window_menu, void *arg1) {
    void *list;
    s32 n;
    TWindowMenu__ct(window_menu, 7, 4, (s32)arg1);
    *(s32 **)(window_menu + 0x18) = __vt__21TWindowSubComCardList;
    *(s32 *)(window_menu + 0) = ((s32)TWindowSubComCardList__class_name);
    n = TWindowSubStatusDisp::round_away_from_zero((f32)TWindowSubComCard::count_active_cards() / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    list = ::operator new(0xC);
    if (list != NULL) {
        list = init__21TWindowSubComCardListFiii(list, 0, n, local_client_id);
    }
    *(void **)(window_menu + 0x8C) = list;
    *(s32 *)(window_menu + 0x90) = 0;
    *(s32 *)(window_menu + 0x94) = get_card_entry__17TWindowSubComCardFi(0);
    *(s32 *)(window_menu + 0x98) = 0xD2;
    *(s8 *)(window_menu + 0x9C) = 0;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    ((TWindowSubComCardList *)window_menu)->sub_80275360();
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)window_menu)->set_scroll_target(223.0f, 184.0f);
    return window_menu;
}

u8 *TWindowSubComCardList__sub_802757AC(u8 *window_menu, void *arg1, s32 arg2, s32 arg3, s8 arg4) {
    void *list;
    s32 n;
    TWindowMenu__ct(window_menu, 7, 4, (s32)arg1);
    *(s32 **)(window_menu + 0x18) = __vt__21TWindowSubComCardList;
    *(s32 *)(window_menu + 0) = ((s32)TWindowSubComCardList__class_name);
    n = TWindowSubStatusDisp::round_away_from_zero((f32)count_leading_active__17TWindowSubComCardFPvi(arg2, arg3) / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    list = ::operator new(0xC);
    if (list != NULL) {
        list = init__21TWindowSubComCardListFiii(list, 0, n, local_client_id);
    }
    *(void **)(window_menu + 0x8C) = list;
    *(s32 *)(window_menu + 0x90) = arg2;
    *(s32 *)(window_menu + 0x94) = 0;
    *(s32 *)(window_menu + 0x98) = arg3;
    *(s8 *)(window_menu + 0x9C) = arg4;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    ((TWindowSubComCardList *)window_menu)->sub_80275360();
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)window_menu)->set_scroll_target(223.0f, 184.0f);
    return window_menu;
}
}
