#include "pso/player/GuildCardEntry.h"
#include "pso/math/FloatRound.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubCustomEquip_80275D9C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/HeadingEntry.h"
void TWindowSubComCardList::draw_card_list_selection(u8 *window_key_board_soft) {
  s16 page_row;
  u16 *array_entry;
  if (!(actor_frame_tick & 0x10))
  {
    page_row = (this->get_selected_index()) - (storage->get_type() * 7);
    if ((page_row >= 0) && (page_row < 7))
    {
      array_entry = (u16 *) this->get_array_entry((s32) page_row);
      if ((*array_entry) & 1)
      {
        draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (TWindowLayoutRect *)array_entry, 1);
      }
    }
  }
}

void TWindowSubComCardList::refresh_page() {
    GuildCardEntry *card;
    s32 n;
    s32 index;
    saddr msg;

    this->reset_entries();
    index = storage->get_type();
    index *= 7;
    for (n = 0; n < 7; n++, index++) {
        if (index >= (s32)this->card_count) {
            break;
        }
        if (this->cards != 0) {
            card = (GuildCardEntry *)(this->cards + index * 0x90);
        } else if (this->card_slots != 0) {
            card = (GuildCardEntry *)(this->card_slots + index * 0x100);
        } else {
            return;
        }
        if (card->is_active() == 0) {
            break;
        }
        this->add_text_entry((saddr)card->get_name(), 7, index);
    }
    if (this->get_entry_count() <= 0) {
        switch ((s8)this->empty_message) {
        case 0:
            msg = (saddr)TWindowSubStatusDisp::get_message_10(0xD4);
            break;
        case 1:
            msg = (saddr)TWindowSubStatusDisp::get_message_10(0xD2);
            break;
        }
        add_gray_text_entry((TWindowMenu *)this, (const char *)msg, 4, -1);
    }
}

TWindowSubComCardList *TWindowSubComCard::create_card_list(const NJS_POINT2 *position, s32 card_slot, s32 count, s32 empty_message) {
    set_window_menu_rows(7);
    return new TWindowSubComCardList(position, card_slot, count, empty_message);
}

TWindowSubComCardList *TWindowSubComCard::create_all_cards_list(const NJS_POINT2 *position) {
    set_window_menu_rows(7);
    return new TWindowSubComCardList(position);
}


#pragma readonly_strings on

const char *TWindowSubComCardList::class_name = "TWindowSubComCardList";

void TWindowSubComCardList::render() {
    WindowDrawContext *ctx;

    ctx = this->get_draw_context();
    draw_window_frame(ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
    this->render_selected_entry(ctx);
    this->draw_card_list_selection((u8 *)ctx);
    if (this->heading != 0) {
        this->heading->render(ctx);
    }
    if (this->storage != 0) {
        draw_list_page_indicator(this->storage, ctx);
    }
}

void TWindowSubComCardList::run_task() {
    TWindowMenu::run_task();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->storage) != 0)) {
        set_selected_index(0);
        refresh_page();
    }
}

TWindowSubComCardList::~TWindowSubComCardList() {
    delete_if_allocated(storage, 1);
}

TWindowSubComCardList::TWindowSubComCardList(const NJS_POINT2 *position) : TWindowMenu(7, 4, position) {
    s32 n;
    m_name = class_name;
    n = round_away_from_zero((f32)TWindowSubComCard::count_active_cards() / 7.0f);
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
    refresh_page();
    set_flag70_bit10();
    set_scroll_target(223.0f, 184.0f);
}

TWindowSubComCardList::TWindowSubComCardList(const NJS_POINT2 *position, saddr card_slot, s32 arg3, s32 arg4) : TWindowMenu(7, 4, position) {
    s32 n;
    m_name = class_name;
    n = round_away_from_zero((f32)TWindowSubComCard::count_leading_active((GuildCardEntry *)card_slot, arg3) / 7.0f);
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
    refresh_page();
    set_flag70_bit10();
    set_scroll_target(223.0f, 184.0f);
}
