#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/PageIndicator.h"
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
extern s32 local_client_id;
s32 count_leading_active__17TWindowSubComCardFPvi(s32, s32);
void render__21TWindowSubComCardListFv(TWindowSubComCardList *arg0);
void __dl__7TObjectFPv(void *);
void *__dt__11TWindowMenuFv(void *arg0, s16 arg1);

void render__21TWindowSubComCardListFv(TWindowSubComCardList *arg0) {
    saddr temp_r3;

    temp_r3 = reinterpret_cast<saddr>(arg0->get_draw_context());
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)arg0 + 0x24),
        reinterpret_cast<WindowDrawContext *>(temp_r3));
    ((TWindowMenu *)arg0)->render_selected_entry(temp_r3);
    arg0->draw_card_list_selection((u8 *)temp_r3);
    if (arg0->m_88 != 0) {
        arg0->m_88->forward_render((void *)(temp_r3));
    }
    if (arg0->m_8c != 0) {
        draw_list_page_indicator(arg0->m_8c, reinterpret_cast<WindowDrawContext *>(temp_r3));
    }
}

void TWindowSubComCardList::run_task() {
    TWindowMenu::run_task();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->m_8c) != 0)) {
        set_selected_index(0);
        sub_80275360();
    }
}

TWindowSubComCardList::~TWindowSubComCardList() {
    delete_if_allocated(m_8c, 1);
}

TWindowSubComCardList::TWindowSubComCardList(void *parent) : TWindowMenu(7, 4, (saddr)parent) {
    s32 n;
    #define window_menu ((u8 *)this)
    *(s32 *)(window_menu + 0) = ((saddr)TWindowSubComCardList__class_name);
    n = TWindowSubStatusDisp::round_away_from_zero((f32)TWindowSubComCard::count_active_cards() / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    m_8c = new PageIndicator(0, (s8)n, local_client_id);
    *(s32 *)(window_menu + 0x90) = 0;
    *(s32 *)(window_menu + 0x94) = get_card_entry__17TWindowSubComCardFi(0);
    *(s32 *)(window_menu + 0x98) = 0xD2;
    *(s8 *)(window_menu + 0x9C) = 0;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    ((TWindowSubComCardList *)window_menu)->sub_80275360();
    ((TWindowMenu *)window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)window_menu)->set_scroll_target(223.0f, 184.0f);
    #undef window_menu
}

TWindowSubComCardList::TWindowSubComCardList(void *parent, s32 card_slot, s32 arg3, s32 arg4) : TWindowMenu(7, 4, (saddr)parent) {
    s32 n;
    #define window_menu ((u8 *)this)
    *(s32 *)(window_menu + 0) = ((saddr)TWindowSubComCardList__class_name);
    n = TWindowSubStatusDisp::round_away_from_zero((f32)count_leading_active__17TWindowSubComCardFPvi(card_slot, arg3) / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    m_8c = new PageIndicator(0, (s8)n, local_client_id);
    *(s32 *)(window_menu + 0x90) = card_slot;
    *(s32 *)(window_menu + 0x94) = 0;
    *(s32 *)(window_menu + 0x98) = arg3;
    *(s8 *)(window_menu + 0x9C) = arg4;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    ((TWindowSubComCardList *)window_menu)->sub_80275360();
    ((TWindowMenu *)window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)window_menu)->set_scroll_target(223.0f, 184.0f);
    #undef window_menu
}
}
