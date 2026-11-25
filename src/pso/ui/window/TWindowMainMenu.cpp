#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/network/TradeSession.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowSubTradeMessage.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"

struct TWindowSubItem;

#include "pso/ui/window/TWindowSubMag.h"

#include "pso/ui/window/TCustomizeMenuCtrl.h"
#include "pso/ui/window/TWindowSubEquip_80277E48.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/ui/window/TWindowSubOption.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/unk/TWindowStatusCategoryMenu.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80263A20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMenuMainMenu.h"
#include "pso/ui/window/TWindowMainMenu4P.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/camera/TCameraCtrl.h"

const char *TWindowMainMenu::class_name = "TWindowMainMenu";

extern const f32 lbl_8044F2E0[2] = {206.0f, 140.0f};
#include "pso/player/TObjPlayer_801AF2F0.h"





extern "C" {
s32 select_main_menu_item_10(s32);
}

#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubAreaMap.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/ui/window/TWindowSubShortCut.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"
#include "pso/ui/TAdMultiPlyChrSelectTransitionGC.h"


int test_keyboard_card_flag4(void* p) { return TWindowKeyBoardHard::test_card_flag((saddr)p, 4); }
void TWindowMainMenu::on_submenu_closed() {  }

void TWindowMainMenu::on_menu_opened() {  }

TWindowMainMenu::TWindowMainMenu(TObject *parent, s32 client) : TObject(parent) {
    s32 i;
    m_name = TWindowMainMenu::class_name;
    client_index = client;
    menu_flags = 0;
    submenu_depth = 0;
    selected_slot = 0;
    description_item_id = 0x1F;
    for (i = 0; i < 4; i++) {
        slots[i].first = 0;
        slots[i].second = 0;
        slots[i].value = 0;
    }
    menu_window = NULL;
    submenu = 0;
    help_window = NULL;
    active_entries = NULL;
    reset_depth_base();
}

TWindowMainMenu::~TWindowMainMenu() {
    TObjPlayer *player;
    if (menu_flags & 1) {
        player = get_player_by_client_id(this->client_index);
        if (player != 0) {
            player->init_parts();
        }
    }
    close_child_window();
    destroy_submenu();
    close();
}
void TWindowMainMenu::run_task() {  }

void TWindowMainMenu::render() {  }

void TWindowMainMenu::handle_menu_selection() {
    s32 id;
    TWindowMenuMainMenu *node;
    TWindowMainMenuEntry *submenu;
    if ((menu_flags & 1) && !(menu_flags & 4) && (node = menu_window) != NULL) {
        selected_slot = node->get_selected_slot();
        id = node->get_selected_item_type();
        update_description_text(id);
        if (node->get_menu_flag() != 0) {
            add_menu_entry(id);
            submenu = active_entries[selected_slot].submenu;
            if (submenu != NULL) {
                active_entries = submenu;
                submenu_depth++;
                update_keyboard_card_state();
                refresh_submenu(active_entries);
                return;
            }
            close_child_window();
            this->update_submenu();
            create_submenu(id);
            return;
        }
        if (node->is_flag_set() != 0) {
            if (submenu_depth <= 0) {
                close_main_menu();
                return;
            }
            add_menu_entry(id);
            submenu_depth--;
            sub_80263D7C();
            update_selection_value();
            close_submenu(active_entries);
        }
    }
}

void TWindowMainMenu::populate_menu(const TWindowMainMenuEntry *window_main_menu_entry) {
    s32 flag;
    s16 id;
    s32 i;
    if (menu_window == NULL) {
        menu_window = create_menu(get_window_layout_position(0x1A), client_index);
        description_item_id = 0x1F;
    }
    TWindowMenuMainMenu *menu = menu_window;
    for (i = 0; i < 8; i++, window_main_menu_entry++) {
        id = window_main_menu_entry->id;
        if (id == 0x1F) {
            break;
        }
        if (filter_menu_entry(&id, &flag) != 0) {
            if (flag != 0) {
                menu->append_child_rows(id);
            } else {
                menu->update_if_active(id);
            }
        }
    }
    menu->update_scaled_position();
    menu->set_selected_slot(selected_slot);
    s32 description_item = menu->get_selected_item_type();
    update_description_text(description_item);
}

void TWindowMainMenu::open_menu_with_entry(s16 id) {
    TWindowMenuMainMenu *menu;
    if (menu_window == NULL) {
        menu_window = create_menu(get_window_layout_position(0x1A), client_index);
    }
    menu = menu_window;
    menu->append_child_rows(id);
    menu->set_selected_slot(0);
    this->update_submenu();
}

void TWindowMainMenu::close() {
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
}

void TWindowMainMenu::refresh_submenu(void *window_main_menu_entry) {
    if (menu_window != NULL) {
        menu_window->park_selection();
        menu_window->clear_menu_flags();
        populate_menu(static_cast<TWindowMainMenuEntry *>(window_main_menu_entry));
    }
}

void TWindowMainMenu::close_submenu(void *window_main_menu_entry) {
    if (menu_window != NULL) {
        menu_window->pop_level();
        menu_window->clear_menu_flags();
        populate_menu(static_cast<TWindowMainMenuEntry *>(window_main_menu_entry));
    }
}

void TWindowMainMenu::update_submenu() {
    if (menu_window != NULL) {
        menu_window->park_selection();
        menu_window->update_scaled_position();
    }
    if (is_split_screen() != 0) {
        update_trade_submenu();
    }
}

void TWindowMainMenu::update_trade_submenu() {
    if (menu_window != NULL) {
        menu_window->request_close();
    }
}

void TWindowMainMenu::show_child_window() {
    if (menu_window != NULL) {
        window_request_show(menu_window);
        menu_window->update_scaled_position();
    }
}

void TWindowMainMenu::create_submenu(u32 id) {
    menu_flags = (s32) (menu_flags | 4);
    destroy_submenu();
    reset_depth_base();
    switch (id) {
    case 25:
        this->submenu = (saddr)new TWindowStatusCategoryMenu(this, this->client_index);
        return;
    case 0:
    case 1:
        this->submenu = (saddr)new TCustomizeMenuCtrl(this, this->client_index);
        return;
    case 9:
    case 10:
        this->submenu = (saddr)new TWindowSubEquip(this, this->client_index);
        return;
    case 11:
        this->submenu = (saddr)new TWindowSubItem(this, this->client_index);
        return;
    case 23:
    case 24:
        this->submenu = (saddr)new TWindowSubMag(this, this->client_index);
        return;
    case 26:
    case 27:
    case 28:
        submenu = reinterpret_cast<saddr>(new TWindowSubTrade(this, client_index));
        return;
    case 29:
        submenu = reinterpret_cast<saddr>(new TWindowSubTradeMain(this, client_index));
        return;
    case 30:
        submenu = reinterpret_cast<saddr>(new TWindowSubTradeMessage(this, client_index));
        return;
    case 12:
    case 13:
        this->submenu = (saddr)new TWindowSubAreaMap(this, this->client_index);
        return;
    case 15:
    case 16:
        this->submenu = reinterpret_cast<saddr>(new TWindowSubQuestBoard(this, reinterpret_cast<void *>(static_cast<saddr>(client_index))));
        return;
    case 3:
    case 4:
        this->submenu = (saddr)new TWindowSubTechnique(this, this->client_index);
        return;
    case 18:
        this->submenu = (saddr)new TWindowSubSymbolChat(this, this->client_index);
        return;
    case 14:
        this->submenu = (saddr)new TWindowSubComCard(this, this->client_index);
        return;
    case 21:
        this->submenu = (saddr)new TWindowSubLog(this, this->client_index);
        return;
    case 6:
        this->submenu = (saddr)new TWindowSubOption(this, this->client_index);
        return;
    case 19:
    case 20:
        this->submenu = reinterpret_cast<saddr>(new TWindowSubShortMail(this, client_index));
        return;
    case 22:
        this->submenu = (saddr)new TWindowSubInformationBoard(this, this->client_index);
        return;
    case 17:
        this->submenu = (saddr)new TWindowSubShortCut(this, this->client_index);
        return;
    case 7:
    case 8:
        this->submenu = (saddr)new TWindowSubGameEnd(this, this->client_index);
    default:
        return;
    }
}

void TWindowMainMenu1P::create_char_select_slot() {
    destroy_submenu();
    reset_depth_base();
    *(void * *)&this->submenu = new TAdMultiPlyChrSelectTransitionGC(this, client_index);
}

void TWindowMainMenu::destroy_submenu() { if (*(unsigned int *)&this->submenu != 0) { ((TObject *)(*(void* *)&this->submenu))->queue_destruction(); *(int *)&this->submenu = 0; } }

void TWindowMainMenu::update_description_text(s32 id) {
    if ((s32)description_item_id != id) {
        description_item_id = id;
        if (help_window == NULL) {
            const NJS_POINT2 *tmp = get_window_layout_position(0x1B);
            help_window = TWindowMessage::create(tmp, lbl_8044F2E0, 1, this->client_index);
            help_window->set_depth(49999.0f);
            call_if_split_screen((uaddr)help_window, this->client_index);
        }
        help_window->append_line(select_main_menu_item_10(id), 0x80);
    }
}

void TWindowMainMenu::close_child_window() { if (help_window != NULL) { this->help_window->close(); help_window = NULL; } }

void TWindowMainMenu::sub_80263FE0() {
    toggle_help_window_on_button((uaddr)help_window, this->client_index);
}

s32 TWindowMainMenu::filter_menu_entry(s16 *id, s32 *enabled) {
    u8 *base;
    u8 *p;
    s32 area;
    base = (u8 *)get_player_by_client_id(this->client_index);
    if (base == NULL) {
        return 0;
    }
    p = base + 0x85C;
    if (p == NULL) {
        return 0;
    }
    *enabled = 1;
    area = get_current_floor_area();
    switch (*id) {
    case 0:
    case 9:
    case 23:
        if (area == AREA_LOBBY) {
            *enabled = 0;
        }
        break;
    case 26:
        if (get_main_phase() != 0xF) {
            *id += 1;
            *enabled = 0;
        } else if (is_trade_range_bit_set(local_client_id) == 0) {
            *enabled = 0;
        }
        break;
    case 15:
        if (is_quest_active() != 1) {
            *enabled = 0;
        }
        break;
    case 3:
        if (*(s32 *)((s8 *)p + 0x34) & 0x10) {
            return 0;
        }
        if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
            *id = 4;
        }
        break;
    case 12:
        if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
            *enabled = 0;
        }
        break;
    case 19:
        if (get_main_phase() != 0xF && TLobby::get_short_mail_ctrl() <= 0) {
            *enabled = 0;
        }
        break;
    case 7:
        if (get_main_phase() == 0xF) {
            *id = 8;
        }
        break;
    }
    if (*enabled == 0) {
        *id += 1;
    }
    return 1;
}

void TWindowMainMenu::update_keyboard_card_state() {
    if (test_keyboard_card_flag4((void *)client_index) != 0) {
        selected_slot = 0;
        return;
    }
    update_selection_value();
}

void TWindowMainMenu::update_selection_value() {
    MainMenuSlotState *e = &slots[submenu_depth];
    if ((u32)e->value != (u32)active_entries) {
        selected_slot = 0;
    } else {
        selected_slot = e->first;
    }
}

void TWindowMainMenu::add_menu_entry(s16 id) {
    MainMenuSlotState *e = &slots[submenu_depth];
    e->first = selected_slot;
    e->second = id;
    e->value = (s32)active_entries;
}

void TWindowMainMenu::sub_80263D7C() {
    this->active_entries = (TWindowMainMenuEntry *)*(s32 *)((u8 *)this + this->submenu_depth * 8 + 0x2c);
}

void TWindowMainMenu::open(s32 entries) {
    TObjPlayer *player;

    player = get_player_by_client_id((s32)this->client_index);
    if (player != 0) {
        menu_flags = menu_flags | 1;
        active_entries = (TWindowMainMenuEntry *)entries;
        submenu_depth = 0;
        update_keyboard_card_state();
        populate_menu(active_entries);
        player->reset_equip_slots();
    }
}

void TWindowMainMenu::close_and_clear_flags() {
    void *player;

    menu_flags = (s32) (menu_flags & ~5);
    close_child_window();
    destroy_submenu();
    close();
    if ((player = (void *)get_player_by_client_id((s32)this->client_index)) != 0U) {
        ((TObjPlayer *)player)->init_parts();
    }
}

s32 TWindowMainMenu::close_active_submenu() {
    menu_flags = (s32) (menu_flags & 0xFFFFFFFB);
    destroy_submenu();
    if ((u32)active_entries == 0U) {
        this->close_main_menu();
        return 0;
    }
    description_item_id = 0x1F;
    sub_80263D7C();
    update_selection_value();
    close_submenu((void*)active_entries);
    return 1;
}

void TWindowMainMenu::try_open_battle_menu(s16 key) {
    s32 spC;
    s16 id;
    TObjPlayer *player;

    id = key;
    player = get_player_by_client_id(this->client_index);
    if ((player != 0) && !(menu_flags & 1) && (filter_menu_entry(&id, &spC) != 0) && (spC != 0)) {
        menu_flags = (s32) (menu_flags | 1);
        active_entries = 0;
        open_menu_with_entry(id);
        this->create_submenu(id);
        player->reset_equip_slots();
        this->on_menu_opened();
    }
}

void TWindowMainMenu::replace_submenu(s16 id) {
    destroy_submenu();
    create_submenu(id);
}

void TWindowMainMenu::reset_depth_base() { depth_base = 50300.0f; }

f32 get_main_menu_layer_depth(u8 *parent, u32 layer) {
    return ((TWindowMainMenu *)parent)->depth_base - (f32) layer;
}
extern "C" {

void TWindowSubEquip__sub_80263AF4(void *, s32) {}
}

void call_if_split_screen(uaddr object, s32 client_id) {
    if ((is_split_screen() != 0) && (object != 0U)) {
        fn_802449E0((u8 *)object);
    }
}
