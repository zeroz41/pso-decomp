#include "pso/player/GuildCardEntry.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_8027FD88.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"

class TChCrTagPlBack;
const char *TWindowSubShortMail::class_name = "TWindowSubShortMail";

// Size arguments of the mail list item and the mail text window.
static const f32 lbl_8044FAC4[2] = {218.0f, 184.0f};
static const f32 lbl_8044FACC[2] = {206.0f, 120.0f};

extern "C" {
s32 *get_shared_text_buffer(void);
int get_flag_bit0__6TLobbyFv(void);
}

extern s32 local_client_id;
extern saddr tl_00;

s8 ShortMailEntry::get_flags() { return flags; }

char *ShortMailEntry::get_body() { return body; }

void ShortMailEntry::set_replied() {
    flags &= ~0xA;
    flags |= 4;
}

TWindowSubShortMail::TWindowSubShortMail(TWindowMainMenu *parent, s32 client_id) : TObject(parent) {
    m_name = class_name;
    this->parent = parent;
    this->client_id = client_id;
    main_menu = NULL;
    card_list = NULL;
    card_window = NULL;
    mail_list = NULL;
    message_window = NULL;
    action_menu = NULL;
    auto_reply_window = NULL;
    auto_reply_menu = NULL;
    keyboard = NULL;
    confirm_window = NULL;
    mail_id = -1;
    card_index = -1;
    target_card_id = 0;
    reply_mail_id = 0;
    state = 0;
}

TWindowSubShortMail::~TWindowSubShortMail() {
    if (confirm_window != NULL) {
        ((TWindowMessageYesNo *)confirm_window)->close();
        confirm_window = NULL;
    }
    if (keyboard != NULL) {
        keyboard->queue_destruction();
        keyboard = NULL;
    }
    if (auto_reply_menu != NULL) {
        ((TWindowBase *)auto_reply_menu)->close();
        auto_reply_menu = NULL;
    }
    if (auto_reply_window != NULL) {
        ((TWindowBase *)auto_reply_window)->close();
        auto_reply_window = NULL;
    }
    if (action_menu != NULL) {
        ((TWindowBase *)action_menu)->close();
        action_menu = NULL;
    }
    if (message_window != NULL) {
        message_window->close();
        message_window = NULL;
    }
    if (mail_list != NULL) {
        mail_list->close();
        mail_list = NULL;
    }
    if (card_window != NULL) {
        ((TWindowBase *)card_window)->close();
        card_window = NULL;
    }
    if (card_list != NULL) {
        ((TWindowBase *)card_list)->close();
        card_list = NULL;
    }
    if (main_menu != NULL) {
        ((TWindowBase *)main_menu)->close();
        main_menu = NULL;
    }
    TLobby__sub_802258C8();
    TLobby::sync_auto_reply_state();
}

void TWindowSubShortMail::run_task() {
    switch (state) {
    case 0:
    case 1:
        if (auto_reply_window != NULL) { ((TWindowBase *)auto_reply_window)->close(); auto_reply_window = NULL; }
        if (action_menu != NULL) { ((TWindowBase *)action_menu)->close(); action_menu = NULL; }
        if (confirm_window != NULL) { ((TWindowMessageYesNo *)confirm_window)->close(); confirm_window = NULL; }
        if (keyboard != NULL) { keyboard->queue_destruction(); keyboard = NULL; }
        if (mail_list != NULL) { mail_list->close(); mail_list = NULL; }
        if (card_window != NULL) { ((TWindowBase *)card_window)->close(); card_window = NULL; }
        if (card_list != NULL) { ((TWindowBase *)card_list)->close(); card_list = NULL; }
        if (main_menu == NULL) {
            main_menu = (void *)create_menu();
        }
        ((TWindowMenu *)main_menu)->clear_flag_and_release();
        state = 2;
    case 2:
        if (((TWindowMenu *)main_menu)->is_cancelled() != 0) {
            parent->on_submenu_closed();
            state = 0x1C;
        } else if (((TWindowMenu *)main_menu)->is_decided() != 0) {
            state = ((TWindowMenu *)main_menu)->get_selected_value();
        }
        break;
    case 3:
        if (action_menu != NULL) { ((TWindowBase *)action_menu)->close(); action_menu = NULL; }
        if (card_list == NULL) {
            card_list = TWindowSubComCard::send_cmd_133();
        }
        if (card_window == NULL) {
            card_index = ((TWindowMenu *)card_list)->get_selected_value();
            card_window = TWindowSubComCard::send_command(card_index);
        }
        ((TWindowMenu *)card_list)->clear_flag_and_release();
        state = 4;
    case 4:
        TWindowSubComCard::update_display_value((uaddr)card_list, (uaddr)card_window, (s32 *)&card_index);
        if (((TWindowMenu *)card_list)->is_cancelled() != 0) {
            state = 1;
        } else if (((TWindowMenu *)card_list)->is_decided() != 0) {
            void *p;
            reply_mail_id = -1;
            p = TWindowSubComCard::get_card_entry(((TWindowMenu *)card_list)->get_selected_value());
            if (p != NULL) {
                target_card_id = reinterpret_cast<GuildCardEntry *>(p)->get_card_id();
            }
            state = 0xB;
        }
        break;
    case 7:
        if (confirm_window != NULL) { ((TWindowMessageYesNo *)confirm_window)->close(); confirm_window = NULL; }
        if (keyboard != NULL) { keyboard->queue_destruction(); keyboard = NULL; }
        if (action_menu != NULL) { ((TWindowBase *)action_menu)->close(); action_menu = NULL; }
        if (mail_list == NULL) {
            mail_list = create_list_item();
            mail_list->advance_line(-1);
        }
        refresh_mail_list(mail_list);
        mail_list->clear_decided();
        state = 8;
    case 8:
        if (TWindowSubShortMail::is_active() != 0) {
            refresh_mail_list(mail_list);
        }
        update_mail_count();
        if (mail_list->is_cancelled() != 0) {
            parent->on_submenu_closed();
            state = 0x1C;
        } else if (mail_list->is_decided() != 0) {
            state = 9;
        }
        break;
    case 9:
        if (confirm_window != NULL) { ((TWindowMessageYesNo *)confirm_window)->close(); confirm_window = NULL; }
        if (message_window != NULL) { message_window->close(); message_window = NULL; }
        if (action_menu == NULL) {
            action_menu = (void *)build_menu();
        }
        ((TWindowMenu *)action_menu)->clear_flag_and_release();
        ((TWindowMenu *)action_menu)->clear_transition_flag();
        state = 0xA;
    case 10:
        if (TWindowSubShortMail::is_active() != 0 && refresh_mail_list(mail_list) == 0) {
            state = 7;
        } else if (((TWindowMenu *)action_menu)->is_cancelled() != 0) {
            state = 7;
        } else if (((TWindowMenu *)action_menu)->is_decided() != 0) {
            ShortMailEntry *mail;
            reply_mail_id = mail_list->get_cursor_value();
            mail = TLobby::find_short_mail_by_id(reply_mail_id);
            if (mail != NULL) {
                target_card_id = mail->get_sender_card_id();
            }
            state = ((TWindowMenu *)action_menu)->get_selected_value();
        }
        break;
    case 11:
        if (confirm_window != NULL) { ((TWindowMessageYesNo *)confirm_window)->close(); confirm_window = NULL; }
        if (action_menu != NULL) { ((TWindowBase *)action_menu)->close(); action_menu = NULL; }
        if (message_window != NULL) { message_window->close(); message_window = NULL; }
        if (mail_list != NULL) { mail_list->close(); mail_list = NULL; }
        if (card_window != NULL) { ((TWindowBase *)card_window)->close(); card_window = NULL; }
        if (card_list != NULL) { ((TWindowBase *)card_list)->close(); card_list = NULL; }
        if (main_menu != NULL) { ((TWindowBase *)main_menu)->close(); main_menu = NULL; }
        if (keyboard == NULL) {
            keyboard = create_keyboard();
        }
        keyboard->set_position(const_cast<NJS_POINT2 *>(get_window_layout_position(0xBB)));
        keyboard->clear_keyboard_flag60_bit1();
        keyboard->show();
        state = 0xC;
    case 12:
        if (keyboard->is_cancelled() != 0) {
            state = 1;
        } else if (keyboard->is_confirmed() != 0) {
            state = 0xD;
        }
        break;
    case 13:
        keyboard->set_position(const_cast<NJS_POINT2 *>(get_window_layout_position(0xBC)));
        keyboard->hide();
        confirm_window = (void *)open_confirm_prompt(this, client_id);
        state = 0xE;
    case 14:
        if (((TWindowMessageYesNo *)confirm_window)->is_cancelled() != 0) {
            state = 0xB;
        } else if (((TWindowMessageYesNo *)confirm_window)->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)confirm_window)->get_selected_value() == 0) {
                close();
                state = 1;
            } else {
                state = 0xB;
            }
        }
        break;
    case 15:
        find_target_user();
        state = 0x10;
    case 16:
        state = 1;
        break;
    case 17:
        ((TWindowMenu *)action_menu)->open();
        confirm_window = (void *)open_confirm_dialog();
        state = 0x12;
    case 18:
        if (TWindowSubShortMail::is_active() != 0 && refresh_mail_list(mail_list) == 0) {
            state = 7;
        } else if (((TWindowMessageYesNo *)confirm_window)->is_cancelled() != 0) {
            state = 9;
        } else if (((TWindowMessageYesNo *)confirm_window)->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)confirm_window)->get_selected_value() == 0) {
                remove_short_mail_by_id(mail_list->get_cursor_value());
                state = 7;
            } else {
                state = 9;
            }
        }
        break;
    case 19:
        if (TLobby::is_active() != 0) {
            state = 0x14;
        } else {
            state = 0x18;
        }
        break;
    case 20:
        if (auto_reply_menu != NULL) { ((TWindowBase *)auto_reply_menu)->close(); auto_reply_menu = NULL; }
        if (action_menu == NULL) {
            action_menu = (void *)create_confirm_menu_window();
        }
        if (auto_reply_window == NULL) {
            auto_reply_window = (void *)create_window();
        }
        ((TWindowMenu *)action_menu)->clear_flag_and_release();
        state = 0x15;
    case 21:
        if (((TWindowMenu *)action_menu)->is_cancelled() != 0) {
            state = 1;
        } else if (((TWindowMenu *)action_menu)->is_decided() != 0) {
            state = ((TWindowMenu *)action_menu)->get_selected_value();
        }
        break;
    case 22:
        if (auto_reply_menu == NULL) {
            auto_reply_menu = (void *)open_menu();
        }
        state = 0x17;
    case 23:
        if (((TWindowMenu *)auto_reply_menu)->is_cancelled() != 0) {
            state = 0x14;
        } else if (((TWindowMenu *)auto_reply_menu)->is_decided() != 0) {
            if (TLobby::set_flag_bit0(((TWindowMenu *)auto_reply_menu)->get_selected_value()) != 0) {
                if (auto_reply_window != NULL) { ((TWindowBase *)auto_reply_window)->close(); auto_reply_window = NULL; }
            }
            state = 0x14;
        }
        break;
    case 24:
        if (confirm_window != NULL) { ((TWindowMessageYesNo *)confirm_window)->close(); confirm_window = NULL; }
        if (auto_reply_window != NULL) { ((TWindowBase *)auto_reply_window)->close(); auto_reply_window = NULL; }
        if (action_menu != NULL) { ((TWindowBase *)action_menu)->close(); action_menu = NULL; }
        if (main_menu != NULL) { ((TWindowBase *)main_menu)->close(); main_menu = NULL; }
        if (keyboard == NULL) {
            keyboard = create_keyboard();
            keyboard->set_text(reinterpret_cast<char *>(TLobby::get_card_window_area()));
        }
        keyboard->set_position(const_cast<NJS_POINT2 *>(get_window_layout_position(0xBB)));
        keyboard->clear_keyboard_flag60_bit1();
        keyboard->show();
        state = 0x19;
    case 25:
        if (keyboard->is_cancelled() != 0) {
            state = 1;
        } else if (keyboard->is_confirmed() != 0) {
            state = 0x1A;
        }
        break;
    case 26:
        keyboard->set_position(const_cast<NJS_POINT2 *>(get_window_layout_position(0xBC)));
        keyboard->hide();
        if (confirm_window == NULL) {
            confirm_window = (void *)open_delete_confirm_dialog();
        }
        state = 0x1B;
    case 27:
        if (((TWindowMessageYesNo *)confirm_window)->is_cancelled() != 0) {
            state = 0x18;
        } else if (((TWindowMessageYesNo *)confirm_window)->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)confirm_window)->get_selected_value() == 0) {
                void *b = keyboard->realloc_buffer();
                ((TLobby *)b)->set_short_mail_text();
                mem_free(b);
                state = 1;
            } else {
                state = 0x18;
            }
        }
        break;
    case 5:
    case 6:
    case 28:
        break;
    }
}

void TWindowSubShortMail::render() {  }

TWindowMenuIconLine *TWindowSubShortMail::create_list_item() {
    const NJS_POINT2 *position = get_window_layout_position(0x9B);
    TWindowMenuIconLine *list = fn_80267F38(reinterpret_cast<saddr>(position),
        reinterpret_cast<saddr>(lbl_8044FAC4), 8, static_cast<s16>(client_id));
    list->ensure_status_display(reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0x2E)));
    list->set_flag70_bit10();
    return list;
}

s32 TWindowSubShortMail::refresh_mail_list(TWindowMenuIconLine *mail_list) {
    s32 n;
    u32 id;
    s32 i;
    s16 sel;
    ShortMailEntry *e;
    id = mail_list->get_cursor_value();
    sel = -1;
    TLobby::clear_lobby_flag();
    mail_list->save_cursor_selection();
    mail_list->reset_list();
    n = TLobby::get_short_mail_ctrl();
    i = n - 1;
    while (i >= 0) {
        e = get_short_mail_entry(i);
        mail_list->add_status_entry(e->get_flags(), (saddr)e->get_sender_name(), e->get_id());
        if (id == e->get_id()) {
            sel = (n - 1) - i;
        }
        i--;
    }
    if (n <= 0) {
        mail_list->advance_line(-1);
        if (this->message_window != 0) {
            this->message_window->close();
            this->message_window = 0;
        }
    } else if (this->message_window == 0) {
        this->message_window = reinterpret_cast<TWindowMessage *>(
            TWindowMessage::create(get_window_layout_position(0x9C), lbl_8044FACC, 1));
        this->mail_id = -1;
    }
    if (sel == -1) {
        mail_list->clamp_selection_to_valid_entry();
        return 0;
    }
    mail_list->set_cursor_index(sel);
    return 1;
}

saddr TWindowSubShortMail::create_menu(void) {
    saddr list;

    list = create_titled_window_menu_default(reinterpret_cast<saddr>(get_window_layout_position(0x9A)), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    if (get_main_phase() == 0xF) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 3);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 3);
    }
    if (TLobby::get_short_mail_ctrl() > 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xCE)), 6, 7);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xCE)), 6, 7);
    }
    if (get_main_phase() == 0xF) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x103)), 6, 0x13);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x103)), 6, 0x13);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(179.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

#pragma push
#pragma fp_contract on
saddr TWindowSubShortMail::build_menu(void) {
    saddr list;
    s32 msg;
    list = create_titled_window_menu_default((s32)(get_window_layout_position(0x9D)), 3, (s32)((saddr)TWindowSubStatusDisp::get_message_10(0x1E)));
    if (get_main_phase() == 0xF) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x7F)), 6, 0xB);
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x7F)), 6, 0xB);
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    }
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 0x11);
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(206.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

#pragma pop
TKeyBoardControl *TWindowSubShortMail::create_keyboard() {
    TKeyBoardControl *keyboard = new TKeyBoardControl(reinterpret_cast<TObject *>(tl_00), 0xC6, 5, 4, local_client_id);
    keyboard->set_composer_flag62_bit4();
    keyboard->set_sub_position(reinterpret_cast<u8 *>(const_cast<NJS_POINT2 *>(get_window_layout_position(0xBB))));
    keyboard->set_flag62_bit2();
    keyboard->set_soft_flag60_bit1();
    return keyboard;
}

saddr TWindowSubShortMail::open_confirm_prompt(void *parent, int client_id) {
    saddr dialog;
    dialog = (saddr)TWindowMessageYesNo::create(parent, client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x3f)), (s32)(get_window_layout_position(0x9e)), 205.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

saddr TWindowSubShortMail::create_confirm_menu_window(void) {
    saddr menu;
    menu = create_window_menu_default(reinterpret_cast<saddr>(get_window_layout_position(0xA0)), 2);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x107)), 6, 0x16);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x108)), 6, 0x18);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(206.0f);
    return menu;
}

saddr TWindowSubShortMail::create_window(void) {
    s32 window_layout_position;
    saddr list;

    window_layout_position = reinterpret_cast<saddr>(get_window_layout_position(0xA1));
    list = create_window_menu_default(window_layout_position, 2);
    if (get_flag_bit0__6TLobbyFv() != 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x105)), 0, 0);
        ((TWindowMenu *)list)->add_text_entry(TLobby::get_card_window_area(), 0, 0);
    } else {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x106)), 0, 0);
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TLobby::get_card_window_area()), 0, 0);
    }
    ((TWindowMenu *)list)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)list);
    ((TWindowSubComCardList *)list)->set_scroll_target(206.0f, 140.0f);
    return list;
}

saddr TWindowSubShortMail::open_menu(void) {
    s32 window_layout_position;
    saddr menu;

    window_layout_position = reinterpret_cast<saddr>(get_window_layout_position(0xA2));
    menu = create_window_menu_default(window_layout_position, 2);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x105)), 6, 1);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x106)), 6, 0);
    if (get_flag_bit0__6TLobbyFv() == 0) {
        ((TWindowSubComCardList *)menu)->set_selected_index(1);
    }
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(206.0f);
    return menu;
}

saddr TWindowSubShortMail::open_confirm_dialog() {
    saddr dialog;

    dialog = (saddr)TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x3e)), (s32)(get_window_layout_position(0x9f)), 206.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

saddr TWindowSubShortMail::open_delete_confirm_dialog() {
    saddr dialog;

    dialog = (saddr)TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x104)), (s32)(get_window_layout_position(0xa3)), 206.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

void TWindowSubShortMail::update_mail_count() {
    s32 cursor_id;
    ShortMailEntry *mail;

    if (message_window != NULL) {
        cursor_id = mail_list->get_cursor_value();
        if ((s32) mail_id != cursor_id) {
            mail_id = cursor_id;
            mail = TLobby::find_short_mail_by_id(mail_id);
            if (mail != NULL) {
                message_window->append_line((saddr)mail->get_body(), 0x482);
            }
        }
    }
}

void TWindowSubShortMail::close() {
    saddr src;
    s32 short_mail_ctrl;
    ShortMailEntry *mail;
    s32 i;

    src = (saddr)this->keyboard->realloc_buffer();
    TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
    TLobby::send_simple_mail(this->target_card_id, (void *)(get_shared_text_buffer()));
    mem_free((void *)src);
    short_mail_ctrl = TLobby::get_short_mail_ctrl();
    for (i = 0; i < short_mail_ctrl; i += 1) {
        mail = get_short_mail_entry(i);
        if (reply_mail_id == mail->get_id()) {
            mail->set_replied();
            return;
        }
    }
}

void TWindowSubShortMail::find_target_user() {
    TWindowSubComCard::get_card_entry(mail_list->get_cursor_value());
    TLobby::send_find_user_self_tag(target_card_id);
}
