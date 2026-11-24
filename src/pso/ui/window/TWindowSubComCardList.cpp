#include "pso/player/GuildCardEntry.h"
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
#include "pso/network/client_id.h"

#pragma readonly_strings on

const char *TWindowSubComCardList::class_name = "TWindowSubComCardList";

extern "C" {
s32 count_leading_active__17TWindowSubComCardFPvi(s32, s32);

void TWindowSubComCardList::render() {
    WindowDrawContext *ctx;

    ctx = this->get_draw_context();
    draw_window_frame(ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
    ((TWindowMenu *)this)->render_selected_entry(ctx);
    this->draw_card_list_selection((u8 *)ctx);
    if (this->heading != 0) {
        this->heading->forward_render(ctx);
    }
    if (this->storage != 0) {
        draw_list_page_indicator(this->storage, ctx);
    }
}

void TWindowSubComCardList::run_task() {
    TWindowMenu::run_task();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->storage) != 0)) {
        set_selected_index(0);
        sub_80275360();
    }
}

TWindowSubComCardList::~TWindowSubComCardList() {
    delete_if_allocated(storage, 1);
}

TWindowSubComCardList::TWindowSubComCardList(void *parent) : TWindowMenu(7, 4, (saddr)parent) {
    s32 n;
    m_name = class_name;
    n = TWindowSubStatusDisp::round_away_from_zero((f32)TWindowSubComCard::count_active_cards() / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    storage = new PageIndicator(0, (s8)n, local_client_id);
    cards = 0;
    card_slots = (uaddr)TWindowSubComCard::get_card_entry(0);
    card_count = 0xD2;
    empty_message = 0;
    set_flag70_bit100();
    set_selected_index(0);
    sub_80275360();
    set_flag70_bit10();
    set_scroll_target(223.0f, 184.0f);
}

TWindowSubComCardList::TWindowSubComCardList(void *parent, s32 card_slot, s32 arg3, s32 arg4) : TWindowMenu(7, 4, (saddr)parent) {
    s32 n;
    m_name = class_name;
    n = TWindowSubStatusDisp::round_away_from_zero((f32)count_leading_active__17TWindowSubComCardFPvi(card_slot, arg3) / 7.0f);
    if (n <= 0) {
        n = 1;
    }
    storage = new PageIndicator(0, (s8)n, local_client_id);
    cards = card_slot;
    card_slots = 0;
    card_count = arg3;
    empty_message = arg4;
    set_flag70_bit100();
    set_selected_index(0);
    sub_80275360();
    set_flag70_bit10();
    set_scroll_target(223.0f, 184.0f);
}
}
