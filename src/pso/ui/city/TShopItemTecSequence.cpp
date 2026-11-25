#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopItemListWindow.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_8022350C.h"
#include "pso/ui/window/WindowLayout.h"

extern "C" {
s32 TShopItemTecSequence::slot_table[4];
extern const char *shop_item_tec_sequence_class_name;
s32 shop_tec_pending_message;
s32 shop_tec_pending_state;
TShopItemTecSequence *item_tec_sequence_instance;
s32 get_shop_text(s32 index);


extern int shop_tool_stock_counts[];
}

#pragma readonly_strings on
struct ShopItemListWindowView { u8 pad[0x1c0]; void *cb0; };
const char *shop_item_tec_sequence_class_name = "TShopItemTecSequence";
void set_judgment_target_flag(TShopJudgmentItemWindow *window, TItemData *item) {
    TItem *found;
    if (TRaderMapCore::is_not_split_screen() == 1 && (found = find_item_by_id(item->id)) != NULL && window->at_tekker != 0) {
        found->add_item_flags(0x80);
    }
}

void TShopItemTecSequence__sub_80220560(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopItemTecSequence::slot_table[i] = 0;
    }
}

void TShopItemTecSequence__sub_80220538(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopItemTecSequence::slot_table[i] = 0;
    }
}

TShopItemTecSequence::TShopItemTecSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = shop_item_tec_sequence_class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    item_tec_sequence_instance = this;
    shop_tec_pending_message = 0;
    shop_tec_pending_state = 0;
    TShopItemTecSequence::slot_table[get_split_screen_slot()] = 1;
}

TShopItemTecSequence::~TShopItemTecSequence() {
    if (counter_camera != NULL) {
        ((TObject *)counter_camera)->queue_destruction();
        counter_camera = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    item_tec_sequence_instance = NULL;
    TShopItemTecSequence::slot_table[get_split_screen_slot()] = 0;
}

void TShopItemTecSequence::update_state() {
    switch (state) {
    case 0:
        TShopSequence::restore_player_state();
        set_state(1);
        return;
    case 1:
        open_greeting();
        return;
    case 2:
        update_buy_sell_choice();
        return;
    case 3:
        open_item_list_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 7:
        close_if_done();
        return;
    case 6:
        handle_select();
    default:
        return;
    }
}

void TShopItemTecSequence::open_greeting() {
    f32 pos[2];
    pos[0] = 332.0f;
    pos[1] = 80.0f;
    create_message_window(get_window_layout_position(0x2C), (saddr)pos);
    display_shop_message(0x2E, 1);
    meseta_window = (TWindowBase *)create_meseta_window((u16)get_player_entity_id());
    set_state(2);
    counter_camera = set_service_counter_camera(this, 5);
}

void TShopItemTecSequence::update_buy_sell_choice() {
    s32 r;
    if (choice_menu == NULL) {
        s32 id = player->get_entity_id();
        choice_menu = create_window_menu(get_window_layout_position(0x2B), 2, id);
        choice_menu->add_text_entry(get_shop_text(4), 6, 0);
        choice_menu->add_text_entry(get_shop_text(6), 6, 1);
        choice_menu->calc_window_size();
        align_menu_entry_positions(choice_menu);
        choice_menu->set_ready_flag();
        choice_menu->set_position_xy(get_scale(), get_scale());
    }
    if (choice_menu != NULL && choice_menu->is_decided() != 0) {
        r = choice_menu->get_selected_value();
        if (r == 0) {
            display_shop_message(0xB, 1);
            set_state(3);
            choice_menu->close();
            choice_menu = NULL;
            return;
        }
        if (r == 1) {
            set_state(4);
            choice_menu->close();
            choice_menu = NULL;
            return;
        }
    }
    if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
        display_shop_message(0x2C, 1);
        set_state(7);
        choice_menu->close();
        choice_menu = NULL;
    }
}

void TShopItemTecSequence::open_item_list_window() {
    ShopItemListWindowView *o = (ShopItemListWindowView *)new TShopItemListWindow(tl_05, this, player);
    o->cb0 = (void *)close__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    this->set_state(5);
}

void TShopItemTecSequence::open_sell_window() {
    TShopEquipmentSellWindow *o = new TShopEquipmentSellWindow(tl_05, this, player, 0x2d);
    o->on_close = close__20TShopItemTecSequenceFPv;
    o->on_empty = select_and_advance__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    set_state(5);
}

void TShopItemTecSequence::close_if_done() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

void TShopItemTecSequence::handle_select() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(shop_tec_pending_message, 1);
        set_state(shop_tec_pending_state);
    }
}

void close__20TShopItemTecSequenceFPv(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1A, 1);
        window->set_state(2);
    }
}

void select_and_advance__20TShopItemTecSequenceFPv(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1B, 1);
        window->set_state(6);
        shop_tec_pending_message = 0x1A;
        shop_tec_pending_state = 2;
    }
}

int TShopItemTecSequence__sub_8021FE6C(int a0) {  return shop_tool_stock_counts[a0]; }

