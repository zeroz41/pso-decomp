#include "pso/player/GuildCardEntry.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowUserSort.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/system/ControllerInput.h"

#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowCtrl.h"

class TChCrTagPlBack;
#include "pso/ui/window/TWindowComCard.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/GuildCardRecord.h"

#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

const char *TWindowSubComCard::class_name = "TWindowSubComCard";

// Window sizes {width, height} passed to TWindowMessage::create / the choice-setting window.
static const f32 com_card_layout_message_size[2] = {188.0f, 120.0f};
static const f32 com_card_choice_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_entry_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_mode4_message_size[2] = {206.0f, 122.0f};
static const f32 com_card_message_size[2] = {206.0f, 82.0f};
static const saddr com_card_help_message_ids[] = {0x47, 0x48, 0x49, 0x4A, 0x4B, 0xF9, 0};

struct Ent_80272034 { u16 a; u16 b; u8 rest[0x1c]; };

struct Tbl_80272034 { u8 pad0; u8 count; u8 pad2[2]; Ent_80272034 e[1]; };

struct Win_80272034 { u8 pad[0x58]; Tbl_80272034 *tbl; };

struct Key_80272034 { u32 a; u32 b; };

extern "C" {
void set_value_by_key(void *, u16, s32);

}

struct Rec_80272290 { s32 f0; u8 f4[0xD0]; };
extern "C" {
void load_selected_guild_card_record(int, int);

}

struct Ent_80272CB0 {
    u16 type;
    u16 id;
    u8 name[0x1C];
};

struct List_80272CB0 {
    u8 pad0;
    u8 count;
    u8 pad2[2];
    Ent_80272CB0 ents[1];
};

struct Entry_80272B60 { u16 id; u16 val; u8 name[0x1C]; };

struct ChrSel_80272B60 { u8 f0; u8 count; u8 pad[2]; Entry_80272B60 e[1]; };

extern "C" {
struct ComCardRec_80272A98 { u32 id; char name[0xD0]; };

struct ComCardList_80272A98 { u8 pad0; u8 count; u8 pad2[2]; ComCardRec_80272A98 entries[1]; };


}

struct ComEntry_8027375C { u8 data[0xD4]; };

struct ComList_8027375C { u8 pad[4]; ComEntry_8027375C entries[1]; };
extern "C" {
s32 TWindowSubComCard__sub_800778B4(void *, int);
void TWindowSubComCard__sub_8007AF10(s32 client_id);
s32 TLobby__sub_8024259C();
}
extern "C" {

void TWindowSubComCard__sub_80077980(void *);
}

struct SelectedGuildCardRecord { s32 value; u8 remaining[0xB8]; };
extern SelectedGuildCardRecord selected_guild_card_record;

void TWindowSubComCard::set_display_page() {
    set_page((s16)((int) (((TWindowMenu *)this)->get_selected_value())));
}
void TWindowMenuInfomation::set_flag_10() { state_flags |= 0x10; }
void TWindowSubComCard::set_page(s16 v) { *(s16*)((char*)this + 0x7a) = v; }
s16 TWindowMenu::get_entry_count() { return entry_count; }
void TKeyBoardControl::set_soft_flag60_bit1() {
    if (m_soft != NULL) {
        m_soft->set_flag60_bit1();
    }
}
char *GuildCardRecord::get_sub_obj() { return name; }
char *GuildCardRecord::get_name() { return s19; }
char *TWindowSubComCard__sub_8027523C(GuildCardRecord *entry) { return entry->s2A; }

char *GuildCardRecord::get_card_data_ptr() { return s3B; }

s32 *get_selected_guild_card_record(void) {
    return &selected_guild_card_record.value;
}

void TWindowSubComCard::set_com_param(saddr client_id, s32 com_param) {
    TWindowKeyBoardHard::set_card_window_flags((void *)client_id, (s32)(com_param << 0x12), (s32)0xFFFBFFFF);
}

TWindowSubComCard::TWindowSubComCard(TObject *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    this->parent_menu = (TWindowMainMenu *)parent;
    client_id = client;
    this->menu_window = 0;
    this->com_card_menu = 0;
    this->com_card_window = NULL;
    this->user_sort_window = NULL;
    this->sub_menu = 0;
    this->message_window = 0;
    this->confirm_window = NULL;
    this->keyboard = 0;
    this->card_list = 0;
    this->entry_list_window = NULL;
    this->chr_select = 0;
    this->dirty_flags = 0;
    this->selected_card = -1;
    TWindowSubComCard__sub_80077980(choice_selections);
    this->state = 0;
}

TWindowSubComCard::~TWindowSubComCard() {
    handle_close_flag();
    send_state_if_dirty();
    if ((u8) state == 0x26) {
        TWindowCtrl::unlock_client_main_menu(client_id);
    }
    if (entry_list_window != NULL) {
        entry_list_window->close();
        entry_list_window = NULL;
    }
    if (confirm_window != 0U) {
        confirm_window->close();
        confirm_window = NULL;
    }
    if (card_list != 0U) {
        card_list->close();
        card_list = 0U;
    }
    if (keyboard != 0U) {
        keyboard->queue_destruction();
        keyboard = 0U;
    }
    if (sub_menu != 0U) {
        sub_menu->close();
        sub_menu = 0U;
    }
    if (com_card_menu != 0U) {
        com_card_menu->close();
        com_card_menu = 0U;
    }
    if (user_sort_window != NULL) {
        user_sort_window->close();
        user_sort_window = NULL;
    }
    if (com_card_window != NULL) {
        com_card_window->close();
        com_card_window = NULL;
    }
    if (message_window != 0U) {
        message_window->close();
        message_window = 0U;
    }
    if (menu_window != 0U) {
        menu_window->close();
        menu_window = 0U;
    }
}
void TWindowSubComCard::run_task() {
    saddr src;
    saddr character_save_record;
    CharacterSaveRecord *option_record;
    CharacterSaveRecord *chosen_record;
    saddr keyboard_mode;
    s32 idle_ticks;
    s32 record;
    s32 selected_value;
    s32 temp_r30_3;
    switch (this->state) {
    case 0x0:
    case 0x1:
        this->send_state_if_dirty();
        if ((u32) this->keyboard != 0U) {
            this->keyboard->queue_destruction();
            this->keyboard = 0U;
        }
        if (this->entry_list_window != NULL) {
            this->entry_list_window->close();
            this->entry_list_window = NULL;
        }
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if ((u32) this->card_list != 0U) {
            this->card_list->close();
            this->card_list = 0U;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->user_sort_window != NULL) {
            this->user_sort_window->close();
            this->user_sort_window = NULL;
        }
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if (this->message_window != 0U) {
            this->message_window->close();
            this->message_window = 0U;
        }
        if (this->menu_window == 0U) {
            this->menu_window = this->create_menu();
        }
        if (this->message_window == 0U) {
            this->message_window = this->open_layout_window();
            this->m_28 = -1;
        }
        this->menu_window->clear_flag_and_release();
        this->state = 2U;
    case 0x2:
        this->set_help_message((int) (this->menu_window->get_cursor_pos()));
        if (this->menu_window->is_cancelled() != 0) {
            this->parent_menu->on_submenu_closed();
            this->state = 0x4FU;
            return;
        }
        if (this->menu_window->is_decided() != 0) {
            if (this->message_window != 0U) {
                this->message_window->close();
                this->message_window = 0U;
            }
            this->state = this->menu_window->get_selected_value();
            return;
        }
        break;
    case 0x3:
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_window == NULL) {
            this->com_card_window = TWindowSubComCard::create_com_card_window(get_window_layout_position(0x81));
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->sub_8027353C();
        }
        this->com_card_menu->clear_flag_and_release();
        this->com_card_menu->clear_transition_flag();
        this->state = 4U;
    case 0x4:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = this->com_card_menu->get_selected_value();
            return;
        }
        break;
    case 0x5:
        if (this->sub_menu == 0U) {
            this->sub_menu = TWindowSubComCard::sub_8027337C();
        }
        this->com_card_menu->open();
        this->state = 6U;
    case 0x6:
        if (this->sub_menu->is_cancelled() != 0) {
            this->state = 3U;
            return;
        }
        if (this->sub_menu->is_decided() != 0) {
            TWindowSubComCard__sub_8007AF10(this->sub_menu->get_selected_value());
            this->state = 7U;
            return;
        }
        break;
    case 0x7:
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->sub_menu == 0U) {
            this->sub_menu = this->create_single_entry_window();
        }
        this->state = 8U;
    case 0x8:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
            this->state = 3U;
            return;
        }
        break;
    case 0x9:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if (this->menu_window != 0U) {
            this->menu_window->close();
            this->menu_window = 0U;
        }
        this->keyboard = create_keyboard();
        this->state = 0xAU;
    case 0xA:
        if (this->keyboard->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->keyboard->is_confirmed() != 0) {
            src = (saddr)this->keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            keyboard_mode = TWindowSubComCard::get_keyboard_mode();
            ((TWindowSubComCard *)keyboard_mode)->set_text((void *)(get_shared_text_buffer()));
            mem_free((void *)src);
            this->state = 1U;
            return;
        }
        break;
    case 0xB:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->message_window == 0U) {
            this->message_window = this->create();
            fn_802449E0((u8 *)this->message_window);
            this->m_28 = -1;
        }
        if ((u32) this->card_list == 0U) {
            this->card_list = TWindowSubComCard::send_cmd_133();
        }
        if (this->com_card_window == NULL) {
            this->selected_card = this->card_list->get_selected_value();
            this->com_card_window = send_command(this->selected_card);
        }
        this->message_window->snap_to((f32 *)get_window_layout_position(0x99));
        this->message_window->request_close();
        this->card_list->clear_flag_and_release();
        this->state = 0xCU;
    case 0xC:
        TWindowSubComCard::update_display_value(this->card_list, this->com_card_window, (s32 *)&this->selected_card);
        this->set_card_index((int) (this->card_list->get_selected_value()));
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) {
            if (this->message_window->is_open_and_unblocked() != 0) {
                this->message_window->request_close();
            } else {
                window_request_show(this->message_window);
            }
        }
        if (this->card_list->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->card_list->is_decided() != 0) {
            this->state = 0xDU;
            return;
        }
        break;
    case 0xD:
        if (this->message_window != 0U) {
            this->message_window->close();
            this->message_window = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->open_menu();
        }
        this->com_card_menu->clear_transition_flag();
        this->com_card_menu->clear_flag_and_release();
        this->state = 0xEU;
    case 0xE:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 0xBU;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = this->com_card_menu->get_selected_value();
            return;
        }
        break;
    case 0xF:
        ((s32 (*)(void))TWindowSubComCard::cleanup)();
        this->state = 0x10U;
    case 0x10:
        this->state = 0xBU;
        return;
    case 0x11:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->message_window == 0U) {
            this->message_window = this->create();
            this->m_28 = -1;
        }
        this->set_card_index((int) (this->card_list->get_selected_value()));
        this->state = 0x12U;
    case 0x12:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
            this->state = 0xBU;
            return;
        }
        break;
    case 0x13:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if ((u32) this->card_list != 0U) {
            this->selected_card = this->card_list->get_selected_value();
            this->card_list->close();
            this->card_list = 0U;
        }
        if (this->menu_window != 0U) {
            this->menu_window->close();
            this->menu_window = 0U;
        }
        this->keyboard = create_keyboard(this->selected_card);
        this->state = 0x14U;
    case 0x14:
        if (this->keyboard->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->keyboard->is_confirmed() != 0) {
            src = (saddr)this->keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            ((TWindowSubComCard *)(this->selected_card))->set_card_text((saddr) (get_shared_text_buffer()));
            mem_free((void *)src);
            this->state = 1U;
            return;
        }
        break;
    case 0x15:
        this->com_card_menu->open();
        this->confirm_window = this->confirm_and_free();
        this->state = 0x16U;
    case 0x16:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0xDU;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                TWindowSubComCard::remove_card_at(this->card_list->get_selected_value());
                this->state = 1U;
                return;
            }
            this->state = 0xDU;
            return;
        }
        break;
    case 0x19:
        this->card_list->clear_flag_and_release();
        this->state = 0x1AU;
    case 0x1A:
        TWindowSubComCard::update_display_value(this->card_list, this->com_card_window, (s32 *)&this->selected_card);
        if (this->card_list->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->card_list->is_decided() != 0) {
            this->state = 0x1BU;
            return;
        }
        break;
    case 0x1B:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if ((u32) this->card_list == 0U) {
            this->card_list = TWindowSubComCard::send_cmd_133();
        }
        if (this->com_card_window == NULL) {
            this->selected_card = this->card_list->get_selected_value();
            this->com_card_window = send_command(this->selected_card);
        }
        ((TWindowSubComCard *)(this->card_list))->set_display_page();
        this->card_list->clear_flag_and_release();
        this->state = 0x1CU;
    case 0x1C:
        TWindowSubComCard::update_display_value(this->card_list, this->com_card_window, (s32 *)&this->selected_card);
        if (this->card_list->is_cancelled() != 0) {
            this->card_list->reset_selection();
            this->state = 1U;
            return;
        }
        if (this->card_list->is_decided() != 0) {
            TWindowSubComCard::swap_cards((int) (this->card_list->get_selected_index()), (int) (this->card_list->get_selected_value()));
            this->card_list->reset_selection();
            this->card_list->sub_80275360();
            this->state = 0x19U;
            return;
        }
        break;
    case 0x1D:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->user_sort_window != NULL) {
            this->user_sort_window->close();
            this->user_sort_window = NULL;
        }
        this->sub_menu = this->sub_80273004();
        this->sub_menu->add_text_entry((saddr)(""), 0x15, -1);
        rebuild_com_card_list(this->sub_menu);
        this->state = 0x1EU;
    case 0x1E:
        if (is_com_card_active() != 0) {
            rebuild_com_card_list(this->sub_menu);
        }
        if (this->sub_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->sub_menu->is_decided() != 0) {
            find_and_load_com_card(this->sub_menu->get_selected_value());
            this->state = 0x1FU;
            return;
        }
        break;
    case 0x1F:
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->user_sort_window == NULL) {
            record = ((s32 (*)(void))get_selected_guild_card_record)();
            this->user_sort_window = new TWindowUserSort((saddr)get_window_layout_position(0x8A), reinterpret_cast<GuildCardRecord *>(record));
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->sub_8027346C();
        }
        this->state = 0x20U;
    case 0x20:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 0x1DU;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = this->com_card_menu->get_selected_value();
            return;
        }
        break;
    case 0x21:
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->user_sort_window != NULL) {
            this->user_sort_window->close();
            this->user_sort_window = NULL;
        }
        if (this->menu_window != 0U) {
            this->menu_window->close();
            this->menu_window = 0U;
        }
        if ((u32) this->keyboard == 0U) {
            this->keyboard = (TKeyBoardControl *)reinterpret_cast<uaddr>(TWindowSubShortMail::create_keyboard());
        }
        this->keyboard->set_position((void *)(get_window_layout_position(0xBB)));
        reinterpret_cast<TKeyBoardControl *>(keyboard)->clear_keyboard_flag60_bit1();
        this->keyboard->show();
        this->state = 0x22U;
    case 0x22:
        if (this->keyboard->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->keyboard->is_confirmed() != 0) {
            this->state = 0x23U;
            return;
        }
        break;
    case 0x23:
        this->keyboard->set_position((void *)(get_window_layout_position(0xBC)));
        this->keyboard->hide();
        this->confirm_window = (TWindowMessageYesNo *)TWindowSubShortMail::open_confirm_prompt(this, client_id);
        this->state = 0x24U;
    case 0x24:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0x21U;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                this->sub_802721D8();
                this->state = 1U;
                return;
            }
            this->state = 0x21U;
            return;
        }
        break;
    case 0x25:
        ((s32 (*)(void))get_selected_guild_card_record)();
        TLobby__sub_8024259C();
        TWindowCtrl::lock_client_main_menu((this->client_id));
        this->m_2c = 0;
        this->state = 0x26U;
    case 0x26:
        idle_ticks = this->m_2c;
        this->m_2c = (idle_ticks + 1);
        if ((f32) idle_ticks > 450.0f) {
            TWindowCtrl::unlock_client_main_menu((this->client_id));
            this->parent_menu->on_submenu_closed();
            this->state = 0x4FU;
            return;
        }
        break;
    case 0x27:
    case 0x33:
        if (TWindowSubComCard::get_chr_select() == 0U) {
            TLobby::protocol_instance->send_choice_search_options_request();
        }
        if ((u8) this->state == 0x27) {
            this->state = 0x28U;
        } else {
            this->state = 0x34U;
        }
    case 0x28:
    case 0x34:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 1U;
        }
        if (TWindowSubComCard::get_chr_select() != 0U) {
            if ((u32) this->chr_select == 0U) {
                this->chr_select = TWindowSubComCard::get_chr_select();
                character_save_record = get_character_save_record(0xFFFF);
                TWindowSubComCard__sub_800778B4(choice_selections, this->chr_select);
                TWindowSubComCard__sub_800778B4((void *)(character_save_record + 0x22EC), (int)this->chr_select);
            }
            if ((u8) this->state == 0x28) {
                this->state = 0x29U;
                return;
            }
            this->state = 0x35U;
            return;
        }
        break;
    case 0x29:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->entry_list_window == NULL) {
            this->entry_list_window = this->sub_80272DE0();
        }
        this->entry_list_window->begin_scroll(148.0f);
        this->entry_list_window->clear_flag_and_release2();
        this->state = 0x2AU;
    case 0x2A:
        if (this->entry_list_window->get_flag() != 0) {
            this->state = 1U;
            return;
        }
        if (this->entry_list_window->is_open() != 0) {
            if (this->entry_list_window->update_selected_entry() == 0) {
                this->state = 0x2DU;
                return;
            }
            this->state = 0x2BU;
            return;
        }
        break;
    case 0x2B:
        this->entry_list_window->sub_80249144();
        this->com_card_menu = this->create_option_list_window(choice_selections, (s32)((int) (this->entry_list_window->update_selected_entry())));
        this->state = 0x2CU;
    case 0x2C:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 0x29U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->set_choice_search_option(choice_selections, (int) (this->entry_list_window->update_selected_entry()), (int) (this->com_card_menu->get_selected_value()));
            this->state = 0x29U;
            return;
        }
        break;
    case 0x2D:
        TWindowSubComCard::release();
        send_choice_search(choice_selections);
        this->state = 0x2EU;
    case 0x2E:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 0x29U;
        }
        if (TWindowSubComCard::get_com_count() != 0U) {
            this->state = 0x2FU;
            return;
        }
        break;
    case 0x2F:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->entry_list_window != NULL) {
            this->entry_list_window->close();
            this->entry_list_window = NULL;
        }
        if (this->sub_menu == 0U) {
            this->sub_menu = this->sub_80272A98();
        }
        if (this->message_window == 0U) {
            this->message_window = this->open_mode4_window();
            this->m_28 = -1;
        }
        this->sub_menu->clear_flag_and_release();
        this->state = 0x30U;
    case 0x30:
        this->set_selected_card((int) (this->sub_menu->get_selected_value()));
        if (this->sub_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->sub_menu->is_decided() != 0) {
            this->state = 0x31U;
            return;
        }
        break;
    case 0x31:
        if (this->message_window != 0U) {
            this->message_window->close();
            this->message_window = 0U;
        }
        if (this->com_card_menu == 0U) {
            selected_value = this->sub_menu->get_selected_value();
            ComList_8027375C *cl = (ComList_8027375C *) TWindowSubComCard::get_com_count();
            ((s32 (*)(void*))load_selected_guild_card_record)(&cl->entries[selected_value]);
            this->com_card_menu = this->create_menu_window();
        }
        this->state = 0x32U;
    case 0x32:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 0x2FU;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = this->com_card_menu->get_selected_value();
            return;
        }
        break;
    case 0x35:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->entry_list_window == NULL) {
            this->entry_list_window = this->create_entry_list_window();
        }
        this->entry_list_window->begin_scroll(148.0f);
        this->entry_list_window->clear_flag_and_release2();
        this->state = 0x36U;
    case 0x36:
        if (this->entry_list_window->get_flag() != 0) {
            this->state = 1U;
            return;
        }
        if (this->entry_list_window->is_open() != 0) {
            this->state = 0x37U;
            return;
        }
        break;
    case 0x37:
        this->entry_list_window->sub_80249144();
        option_record = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
        this->com_card_menu = this->create_option_list_window(option_record->choice_search, (s32)((int) (this->entry_list_window->update_selected_entry())));
        this->state = 0x38U;
    case 0x38:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 0x35U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            chosen_record = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
            this->set_choice_search_option(chosen_record->choice_search, (int) (this->entry_list_window->update_selected_entry()), (int) (this->com_card_menu->get_selected_value()));
            this->state = 0x35U;
            return;
        }
        break;
    case 0x39:
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if ((u32) this->card_list != 0U) {
            this->card_list->close();
            this->card_list = 0U;
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->sub_802728CC();
        }
        this->com_card_menu->clear_flag_and_release();
        this->state = 0x3AU;
    case 0x3A:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = this->com_card_menu->get_selected_value();
            return;
        }
        break;
    case 0x3B:
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if (this->message_window != 0U) {
            this->message_window->close();
            this->message_window = 0U;
        }
        if ((u32) this->card_list == 0U) {
            this->card_list = TWindowSubComCard::init_layout();
        }
        if (this->com_card_window == NULL) {
            this->selected_card = this->card_list->get_selected_value();
            this->com_card_window = apply_selection(this->selected_card);
        }
        this->card_list->clear_flag_and_release();
        this->state = 0x3CU;
    case 0x3C:
        TWindowSubComCard::update_selection(this->card_list, this->com_card_window, (s32 *)&this->selected_card);
        if (this->card_list->is_cancelled() != 0) {
            this->state = 0x39U;
            return;
        }
        if (this->card_list->is_decided() != 0) {
            this->state = 0x3DU;
            return;
        }
        break;
    case 0x3D:
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->sub_802730E0();
        }
        this->state = 0x3EU;
    case 0x3E:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0x3BU;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                TWindowSubComCard::remove_entry(this->card_list->get_selected_value());
                this->dirty_flags |= 2;
                this->state = 1U;
                return;
            }
            this->state = 0x3BU;
            return;
        }
        break;
    case 0x3F:
        this->sub_menu = TWindowSubComCard::create_card_action_window();
        this->state = 0x40U;
    case 0x40:
        if (this->sub_menu->is_cancelled() != 0) {
            this->state = 0x39U;
            return;
        }
        if (this->sub_menu->is_decided() != 0) {
            this->state = this->sub_menu->get_selected_value();
            return;
        }
        break;
    case 0x41:
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
        if ((u32) this->card_list == 0U) {
            this->card_list = TWindowSubComCard::send_cmd_133();
        }
        if (this->com_card_window == NULL) {
            this->selected_card = this->card_list->get_selected_value();
            this->com_card_window = send_command(this->selected_card);
        }
        this->card_list->clear_flag_and_release();
        this->state = 0x42U;
    case 0x42:
        TWindowSubComCard::update_display_value(this->card_list, this->com_card_window, (s32 *)&this->selected_card);
        if (this->card_list->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->card_list->is_decided() != 0) {
            this->state = 0x43U;
            return;
        }
        break;
    case 0x43:
        if (this->com_card_window != NULL) {
            this->com_card_window->close();
            this->com_card_window = NULL;
        }
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x44U;
    case 0x44:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0x41U;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                ((TWindowSubComCard *)(saddr)(this->card_list->get_selected_value()))->update_press();
                this->dirty_flags |= 2;
                this->state = 1U;
                return;
            }
            this->state = 0x41U;
            return;
        }
        break;
    case 0x45:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
    case 0x46:
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->create_player_select_window();
        }
        this->com_card_menu->clear_flag_and_release();
        this->state = 0x47U;
    case 0x47:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = 0x48U;
            return;
        }
        break;
    case 0x48:
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x49U;
    case 0x49:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0x46U;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                TWindowSubComCard::init_and_press_b(this->com_card_menu->get_selected_value());
                this->dirty_flags |= 2;
                this->state = 1U;
                return;
            }
            this->state = 0x46U;
            return;
        }
        break;
    case 0x4A:
        if (this->com_card_menu != 0U) {
            this->com_card_menu->close();
            this->com_card_menu = 0U;
        }
    case 0x4B:
        if ((u32) this->confirm_window != 0U) {
            this->confirm_window->close();
            this->confirm_window = NULL;
        }
        if (this->sub_menu != 0U) {
            this->sub_menu->close();
            this->sub_menu = 0U;
        }
        if (this->com_card_menu == 0U) {
            this->com_card_menu = this->sub_80272640();
        }
        this->com_card_menu->clear_flag_and_release();
        this->state = 0x4CU;
    case 0x4C:
        if (this->com_card_menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->com_card_menu->is_decided() != 0) {
            this->state = 0x4DU;
            return;
        }
        break;
    case 0x4D:
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x4EU;
    case 0x4E:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 0x4BU;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                TWindowSubComCard::init_and_press_a(this->com_card_menu->get_selected_value());
                this->dirty_flags |= 2;
                this->state = 1U;
                return;
            }
            this->state = 0x4BU;
        }
        break;
    case 0x4F:
        break;
    }
}

void TWindowSubComCard::render() {  }

TWindowMenu *TWindowSubComCard::create_menu() {
    TWindowMenu *list;

    list = create_titled_window_menu_default(get_window_layout_position(0x7F), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x52)), 6, 3);
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x53)), 6, 0xB);
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x54)), 6, 0x1D);
    if (get_main_phase() == 0xF) {
        list->add_text_entry(get_message_text(0x49), 6, 0x27);
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x6D)), 6, 0x33);
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xF8)), 6, 0x39);
    } else {
        add_gray_text_entry(list, (const char *)(get_message_text(0x49)), 6, 0x27);
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x6D)), 6, 0x33);
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xF8)), 6, 0x39);
    }
    list->set_flag70_bit10();
    list->update_layout_height(179.0f);
    align_menu_entry_positions(list);
    return list;
}

TWindowMenu *TWindowSubComCard::sub_8027353C() {
    TWindowMenu *menu;
    saddr temp_r31_2;
    menu = create_titled_window_menu_default(get_window_layout_position(0x82), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1E));
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x55)), 6, 5);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x56)), 6, 9);
    menu->set_flag70_bit10();
    menu->update_layout_height(213.0f);
    align_menu_entry_positions(menu);
    return menu;
}

TWindowMenu *TWindowSubComCard::sub_8027346C() {
  TWindowMenu *list;
  list = create_titled_window_menu_default(get_window_layout_position(0x8B), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
  list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  else
  {
    add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  list->set_flag70_bit10();
  list->update_layout_height(186.0f);
  align_menu_entry_positions(list);
  return list;
}

TWindowMenu *TWindowSubComCard::sub_8027337C() {
    s32 i;
    void *p;
    TWindowMenu *w;
    u8 *name;
    w = create_titled_window_menu_default(get_window_layout_position(0x83), 0xC, (saddr)TWindowSubStatusDisp::get_message_10(0x1F));
    i = 0;
    do {
        if (i != local_client_id && (p = get_player_by_client_id(i)) != NULL &&
            ((TObjPlayer *)p)->is_script_controlled() == 0 && ((TObjChara *)p)->obj_isState3_324() == 0 &&
            (name = (u8 *)p + 0x85C) != NULL) {
            w->add_text_entry((saddr)name, 7, i);
        }
        i++;
    } while (i < 0xC);
    if (w->get_entry_count() <= 0) {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    w->set_flag70_bit10();
    w->set_scroll_target(213.0f, 124.0f);
    return w;
}

TWindowMenu *TWindowSubComCard::create_single_entry_window() {
  TWindowMenu *menu;
    menu = create_window_menu_default(get_window_layout_position(0x84), 1);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x38)), 3, 0);
    menu->set_flag_40();
    menu->set_scroll_target(213.0f, 64.0f);
    return menu;
}

TWindowMenu *TWindowSubComCard::open_menu() {
    TWindowMenu *list;

    list = create_titled_window_menu_default(get_window_layout_position(0x87), 5, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    if (get_main_phase() == 0xF) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    }
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x101)), 6, 0x11);
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x102)), 6, 0x13);
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 0x1B);
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 0x15);
    list->set_flag70_bit10();
    list->update_layout_height(206.0f);
    align_menu_entry_positions(list);
    return list;
}

TWindowMessageYesNo *TWindowSubComCard::confirm_and_free() {
    TWindowMessageYesNo *dialog;

    dialog = TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(dialog, ((saddr)TWindowSubStatusDisp::get_message_10(0x20)), ((saddr)TWindowSubStatusDisp::get_message_10(0x39)), get_window_layout_position(0x88), 205.0f);
    dialog->set_menu_selected_index(1);
    dialog->set_choice_menu_flag70_bit10();
    return dialog;
}

TWindowMessageYesNo *TWindowSubComCard::sub_802730E0() {
    TWindowMessageYesNo *window;
    window = TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    window->open_yes_no_prompt_with_text((saddr)(TWindowSubStatusDisp::get_message_10(0xFC)), get_window_layout_position(0x96), 213.0f);
    window->set_menu_selected_index(1);
    window->set_choice_menu_flag70_bit10();
    return window;
}

TWindowMessageYesNo *TWindowSubComCard::open_yesno_dialog() {
    TWindowMessageYesNo *dialog;

    dialog = TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(dialog, ((saddr)TWindowSubStatusDisp::get_message_10(0x20)), ((saddr)TWindowSubStatusDisp::get_message_10(0x100)), get_window_layout_position(0x97), 213.0f);
    dialog->set_menu_selected_index(1);
    dialog->set_choice_menu_flag70_bit10();
    return dialog;
}

TWindowMenu *TWindowSubComCard::sub_80273004() {
    TWindowMenu *r = create_titled_window_menu_default(get_window_layout_position(0x89), 8, (saddr)TWindowSubStatusDisp::get_message_10(0x21));
    r->set_flag70_bit10();
    return r;
}
#pragma push
#pragma opt_loop_invariants off
void TWindowSubComCard::rebuild_com_card_list(TWindowMenu *list_window) {
    s32 n;
    u32 cur;
    s32 i;
    s16 sel;
    s16 pos;
    void *e;
    cur = list_window->get_selected_value();
    sel = -1;
    TLobby::clear_flag_bit2();
    pos = list_window->get_cursor_pos();
    list_window->reset_entries();
    n = TLobby::get_com_card_data();
    for (i = n - 1; i >= 0; i--) {
        e = TLobby::get_com_card_entry(i);
        list_window->add_text_entry((saddr)(reinterpret_cast<GuildCardRecord *>(e)->get_sub_obj()), 7, ((GuildCardRecord *)e)->get_serial());
        if (cur == ((GuildCardRecord *)e)->get_serial()) {
            sel = (n - 1) - i;
        }
    }
    if (n <= 0) {
        add_gray_text_entry(list_window, (const char *)(TWindowSubStatusDisp::get_message_10(0xD3)), 6, -1);
    }
    list_window->update_layout_height(243.0f);
    if (sel == -1) {
        list_window->set_selected_index(pos);
    } else {
        list_window->set_selected_index(sel);
    }
}
#pragma pop

TWindowMessage *TWindowSubComCard::open_layout_window() {
    return TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x80)), com_card_layout_message_size, 1);
}
#pragma push
#pragma opt_loop_invariants off
TWindowChoiceSetting *TWindowSubComCard::sub_80272DE0() {
    s32 i;
    s32 count;
    s32 idx;
    TWindowChoiceSetting *w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    w = TWindowChoiceSetting::create_choice_setting_window((const NJS_POINT2 *)get_window_layout_position(0x8C), (const NJS_POINT2 *)com_card_choice_list_size, 6);
    w->create_sub_window((const char *)get_message_text(0x49));
    l = (List_80272CB0 *)this->chr_select;
    idx = 0;
    count = l->count;
    e = l->ents;
    for (i = 0; i < count; i++, e++) {
        if (e->type == 0) {
            w->update_next_entry(e->name, this->find_entry_rest(choice_selections, idx), e->id);
            idx++;
        }
    }
    w->add_text_entry(get_message_text(0x4A), 0);
    w->set_flag_10();
    return w;
}
#pragma pop

TWindowChoiceSetting *TWindowSubComCard::create_entry_list_window() {
    s32 i;
    u8 *card;
    u16 id;
    s32 n;
    s32 idx;
    saddr hard;
    TWindowChoiceSetting *w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    card = (u8 *)get_character_save_record(0xFFFF);
    hard = TLobby::open_hard_keyboard(client_id);
    w = TWindowChoiceSetting::create_choice_setting_window((const NJS_POINT2 *)get_window_layout_position(0x8C), (const NJS_POINT2 *)com_card_entry_list_size, 6);
    w->create_sub_window((const char *)TWindowSubStatusDisp::get_message_10(0x6D));
    w->update_next_entry(TWindowSubStatusDisp::get_message_10(0x6D), this->get_message_10(hard), 0);
    l = (List_80272CB0 *)this->chr_select;
    idx = -1;
    n = l->count;
    e = l->ents;
    for (i = 0; i < n; i++, e++) {
        if (e->type == 0) {
            idx++;
            if (e->id >= 500) {
                w->update_next_entry(e->name, this->find_entry_rest(card + 0x22EC, idx), e->id);
                if (hard != 0) {
                    w->disable_entry_by_id(e->id);
                }
            }
        }
    }
    w->set_flag_10();
    return w;
}
#pragma push
#pragma opt_loop_invariants off
TWindowMenu *TWindowSubComCard::create_option_list_window(ChoiceSearchSelection *selections, s32 key) {
    s32 i;
    s32 count;
    s32 idx;
    u16 val;
    u16 sel;
    TWindowMenu *win;
    Entry_80272B60 *e;
    ChrSel_80272B60 *cs;
    win = create_titled_window_menu_default(get_window_layout_position(0x8D), 0x20, (saddr)this->entry_list_window->find_entry_value_by_id(key));
    if (key == 0) {
        win->add_text_entry((saddr)this->get_message_10(0), 6, 0);
        win->add_text_entry((saddr)this->get_message_10(1), 6, 1);
        win->set_selected_index(TLobby::open_hard_keyboard(client_id));
    } else {
        sel = find_choice_search_value(selections, key);
        cs = (ChrSel_80272B60 *)TWindowSubComCard::get_chr_select();
        count = cs->count;
        e = cs->e;
        idx = 0;
        i = 0;
        while (i < count) {
            if (e->id == key) {
                val = e->val;
                win->add_text_entry((saddr)e->name, 6, val);
                if (sel == val) {
                    win->set_selected_index(idx);
                }
                idx++;
            }
            i++;
            e++;
        }
    }
    win->set_flag70_bit10();
    win->set_scroll_target(405.0f, 124.0f);
    align_menu_entry_positions(win);
    return win;
}
#pragma pop

TWindowMenu *TWindowSubComCard::sub_80272A98() {
    s32 i;
    s32 count;
    TWindowMenu *w;
    ComCardRec_80272A98 *e;
    ComCardList_80272A98 *l;
    w = create_titled_window_menu_default(get_window_layout_position(0x8E), 0x20, (saddr)TWindowSubStatusDisp::get_message_10(0x54));
    l = (ComCardList_80272A98 *)TWindowSubComCard::get_com_count();
    count = l->count;
    e = l->entries;
    for (i = 0; i < count; i++, e++) {
        w->add_text_entry((saddr)e->name, 6, i);
    }
    if (w->get_entry_count() <= 0) {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    w->set_flag70_bit10();
    w->set_scroll_target(223.0f, 124.0f);
    return w;
}
TWindowMessage *TWindowSubComCard::open_mode4_window() {
    return TWindowMessage::create(get_window_layout_position(0x8f), com_card_mode4_message_size, 1);
}

TWindowMenu *TWindowSubComCard::create_menu_window() {
  TWindowMenu *list;
  list = create_titled_window_menu_default(get_window_layout_position(0x8f), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
  list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  else
  {
    add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  list->set_flag70_bit10();
  list->update_layout_height(206.0f);
  align_menu_entry_positions(list);
  return list;
}

TWindowMenu *TWindowSubComCard::sub_802728CC() {
    TWindowMenu *w;
    w = create_titled_window_menu_default(get_window_layout_position(0x90), 2, (saddr)TWindowSubStatusDisp::get_message_10(0xF8));
    w->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFA)), 6, 0x3B);
    if (TWindowSubComCard::init_card() != 0) {
        w->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFB)), 6, 0x3F);
    } else {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xFB)), 6, 0x3F);
    }
    w->set_flag70_bit10();
    w->update_layout_height(233.0f);
    return w;
}

TWindowMenu *TWindowSubComCard::create_card_action_window() {
    TWindowMenu *menu;
    void *temp_r31_2;
    menu = create_titled_window_menu_default(get_window_layout_position(0x93), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFD)), 6, 0x41);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFE)), 6, 0x45);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFF)), 6, 0x4A);
    menu->set_flag70_bit10();
    menu->update_layout_height(193.0f);
    return menu;
}
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TWindowMenu *TWindowSubComCard::create_player_select_window() {
    s32 i;
    TObjPlayer *p;
    TWindowMenu *w;
    w = create_titled_window_menu_default(get_window_layout_position(0x94), 0xC, (saddr)TWindowSubStatusDisp::get_message_10(0x2D));
    i = 0;
    do {
        if (i != local_client_id && (p = get_player_by_client_id(i)) != NULL &&
            p->is_script_controlled() == 0 && p->obj_isState3_324() == 0) {
            w->add_text_entry((saddr)p->get_name(), 7, i);
        }
        i++;
    } while (i < 0xC);
    if (w->get_entry_count() <= 0) {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    w->set_flag70_bit10();
    w->set_scroll_target(223.0f, 184.0f);
    return w;
}
#pragma pop

TWindowMenu *TWindowSubComCard::sub_80272640() {
    s32 n;
    s32 i;
    ShortMailEntry *e;
    TWindowMenu *w;
    w = create_titled_window_menu_default(get_window_layout_position(0x95), 8, (saddr)TWindowSubStatusDisp::get_message_10(0x2E));
    n = TLobby::get_short_mail_ctrl();
    for (i = n - 1; i >= 0; i--) {
        e = get_short_mail_entry(i);
        w->add_text_entry((saddr)e->get_sender_name(), 7, e->get_id());
    }
    if (n <= 0) {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD1)), 7, 0);
    }
    w->set_flag70_bit10();
    w->set_scroll_target(223.0f, 184.0f);
    return w;
}

TWindowMessage *TWindowSubComCard::create() {
    TWindowMessage *window;

    window = TWindowMessage::create(get_window_layout_position(0x98), com_card_message_size, 1);
    window->set_depth(50090.0f);
    return window;
}

// Opens the keyboard over the text of the com card being written.
TKeyBoardControl *TWindowSubComCard::create_keyboard() {
    int keyboard_mode;
    TKeyBoardControl *control;

    keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    control = new TKeyBoardControl(this, 0xC6, 3, 4, local_client_id);
    control->set_text((char *)((TWindowComCard *)keyboard_mode)->get_kbd_ptr());
    control->set_sub_position((u8 *)get_window_layout_position(0xBB));
    control->set_flag62_bit2();
    control->set_soft_flag60_bit1();
    return control;
}

// Opens the keyboard over the note of the guild card `card_index`.
TKeyBoardControl *TWindowSubComCard::create_keyboard(s32 card_index) {
    TKeyBoardControl *control;

    control = new TKeyBoardControl(this, 0xC6, 3, 4, local_client_id);
    control->set_text(get_card_note_text(card_index));
    control->set_sub_position((u8 *)get_window_layout_position(0xBB));
    control->set_flag62_bit2();
    control->set_soft_flag60_bit1();
    return control;
}

void TWindowSubComCard::update_display_value(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected) {
    saddr card_entry;
    s32 selected_value;

    card_entry = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(0));
    if (list_window != NULL && card_window != NULL) {
        selected_value = list_window->get_selected_value();
        if (selected_value != *last_selected) {
            *last_selected = selected_value;
            card_window->set_display_value(selected_value, card_entry);
        }
    }
}

void TWindowSubComCard::update_selection(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected) {
    s32 card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard::update_selection(list_window, card_window, last_selected, card_slot);
}

void TWindowSubComCard::update_selection(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected, s32 cards) {
    s32 selected_value;

    if (list_window != NULL && card_window != NULL) {
        selected_value = list_window->get_selected_value();
        if (selected_value != *last_selected) {
            *last_selected = selected_value;
            card_window->set_display_entry(selected_value, cards);
        }
    }
}

void TWindowSubComCard::set_help_message(s32 help_index) {
    if ((s32) this->m_28 != help_index) {
        this->m_28 = help_index;
        this->message_window->append_line((s32)(saddr)TWindowSubStatusDisp::get_message_10((saddr)((void *)com_card_help_message_ids[help_index])), 0x80);
    }
}

void TWindowSubComCard::set_selected_card(s32 card_index) {
    u8 *card_data;
    saddr guild_card_record;
    Rec_80272290 *cnt;
    if ((s32)this->m_28 != card_index) {
        this->m_28 = (uaddr)card_index;
        cnt = (Rec_80272290 *)TWindowSubComCard::get_com_count();
        card_data = cnt[card_index].f4;
        load_selected_guild_card_record((saddr)card_data, card_index * 0xD4);
        guild_card_record = ((s32 (*)(void))get_selected_guild_card_record)();
        text_builder_reset();
        text_builder_append((card_data + 0x14));
        text_builder_append((u8 *)(reinterpret_cast<GuildCardRecord *>(guild_card_record)->get_name()));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(((void* (*)(int))TWindowSubComCard__sub_8027523C)(guild_card_record)));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(reinterpret_cast<GuildCardRecord *>(guild_card_record)->get_card_data_ptr()));
        this->message_window->append_line((saddr)get_shared_text_buffer(), 0x82);
    }
}

void TWindowSubComCard::set_card_index(s32 card_index) {
    if ((s32) this->m_28 != card_index) {
        this->m_28 = card_index;
        this->message_window->append_line((saddr)get_card_note_text(card_index), 0x82);
    }
}
#pragma push
#pragma scheduling off
void TWindowSubComCard::sub_802721D8() {
  u8 *new_var;
  saddr src;
  u8 *lobby;
  u8 *message;
  src = (saddr)this->keyboard->realloc_buffer();
  lobby = (u8 *) ((u8* (*)(void))get_selected_guild_card_record)();
  TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
  new_var = (u8 *)get_shared_text_buffer();
  message = new_var;
  TLobby::send_simple_mail(reinterpret_cast<GuildCardRecord *>(lobby)->get_id(), message);
  mem_free((void *)src);
}
#pragma pop
void TWindowSubComCard::cleanup(void *p) {
    TWindowMenu *menu = *reinterpret_cast<TWindowMenu **>(static_cast<u8 *>(p) + 0x84);
    const GuildCardSlot *slot = TWindowSubComCard::get_card_entry(menu->get_selected_value());
    TLobby::send_find_user_self_tag(slot->get_card_id());
}
TWindowSubComCardList *TWindowSubComCard::send_cmd_133() { return sub_802754EC(get_window_layout_position(133)); }
TWindowSubComCardList *TWindowSubComCard::init_layout() {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    return TWindowSubComCard::create_card_list(get_window_layout_position(0x91), card_slot, 0x1C, 1);
}
TWindowComCard *TWindowSubComCard::send_command(s32 index) {
    return TWindowComCard::create(get_window_layout_position(0x86), index);
}
TWindowComCard *TWindowSubComCard::apply_selection(s32 index) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    return TWindowComCard::create_for_card(get_window_layout_position(0x92), index, card_slot);
}

void *TWindowSubComCard::get_message_10(s32 index) { return TWindowSubStatusDisp::get_message_10(index + 0xa6); }

u8 *TWindowSubComCard::find_entry_rest(void *arg1_arg, s32 idx) {
    Key_80272034 *arg1 = (Key_80272034 *)arg1_arg;
    Tbl_80272034 *t = ((Win_80272034 *)this)->tbl;
    Ent_80272034 *e;
    Key_80272034 *k;
    s32 i;
    k = arg1 + idx;
    e = t->e;
    for (i = 0; i < t->count; i++, e++) {
        if (e->a == k->a && e->b == k->b) return e->rest;
    }
    return 0;
}
void TWindowSubComCard::set_choice_search_option(ChoiceSearchSelection *selections, s32 key, saddr val) {
    s32 i;
    if (key == 0) {
        if (val != TLobby::open_hard_keyboard(client_id)) {
            this->dirty_flags |= 1;
            set_com_param(client_id, val);
            this->entry_list_window->set_entry_string_by_id(this->get_message_10(val), 0);
            if (val != 0) {
                for (i = 0; i < 5; i++) {
                    if (selections[i].parent_choice_id != 0) {
                        this->entry_list_window->disable_entry_by_id(selections[i].parent_choice_id);
                    }
                }
            } else {
                for (i = 0; i < 5; i++) {
                    if (selections[i].parent_choice_id != 0) {
                        this->entry_list_window->mark_entry_by_id(selections[i].parent_choice_id);
                    }
                }
            }
        }
    } else if (val != find_choice_search_value(selections, key)) {
        this->dirty_flags |= 1;
        set_value_by_key(selections, key, val);
        this->entry_list_window->set_entry_string_by_id((void *)((TWindowSubComCard *)(this->com_card_menu->get_selected_entry()))->get_field_20(), key);
    }
}

void TWindowSubComCard::send_state_if_dirty() {
    if (this->dirty_flags & 1) {
        TLobby::send_card_window_state();
        this->dirty_flags = (s8) (this->dirty_flags & ~1);
    }
}

void TWindowSubComCard::handle_close_flag() {
    if (this->dirty_flags & 2) {
        TLobby::send_status_packet();
        this->dirty_flags &= ~2;
    }
}

void TWindowSubComCard::send_choice_search(ChoiceSearchSelection *selections) {
    TPlyChoiceSearchConfig parameters;

    copy_choice_search_selections(selections, &parameters);
    TLobby::protocol_instance->send_choice_search(parameters);
}
