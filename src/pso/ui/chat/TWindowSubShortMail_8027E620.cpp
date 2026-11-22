#include "pso/player/GuildCardEntry.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
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
const char *TWindowSubShortMail__class_name = "TWindowSubShortMail";

// Size arguments of the mail list item and the mail text window.
static const f32 lbl_8044FAC4[2] = {218.0f, 184.0f};
static const f32 lbl_8044FACC[2] = {206.0f, 120.0f};

extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
saddr get_window_layout_position(s32);
s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *, saddr);
s32 create_list_item__19TWindowSubShortMailFv(void *);
s32 open_confirm_dialog__19TWindowSubShortMailFv(void *);
s32 open_delete_confirm_dialog__19TWindowSubShortMailFv(void *);
void TWindowSubShortMail__sub_8027FAD0(u8 *);
saddr get_card_window_area__6TLobbyFv();
s32 fn_8007B83C(s32);
s32 add_status_entry__20TWindowSubStatusDispFScll(void *, s32, s32, u32);
s32 *get_shared_text_buffer(void);
s32 __nw__7TObjectFUl(s32);
int get_flag_bit0__6TLobbyFv(void);
}

extern s32 local_client_id;
extern saddr tl_00;
struct VBase_18_8027EF98 { char pad[0x18]; };

struct VObj_18_8027EF98 : VBase_18_8027EF98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7();
};

struct ShortMail_8027EF98 {
    u8 pad0[0x1C];
    u8 state;
    u8 pad1D[3];
    s32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2c;
    s32 f30;
    VObj_18_8027EF98 *parent;
    void *w38;
    void *w3c;
    void *w40;
    void *w44;
    void *w48;
    void *w4c;
    void *w50;
    void *w54;
    void *w58;
    void *w5c;
};

extern "C" {
void update_display_value__17TWindowSubComCardFUiUiPv(uaddr arg0, uaddr arg1, s32 *arg2);
s32 TWindowSubShortMail__sub_8007B834(void *);
void TWindowSubShortMail__sub_8027E620(void *p);
}

void remove_short_mail_by_id(u32 id);

extern "C" {
extern s32 __vt__19TWindowSubShortMail[];
}

u8 TWindowSubShortMail::get_field_cc(void* p) { return *(u8*)((char*)p + 0xcc); }

void* TWindowSubShortMail::get_mail_ptr(void* p) { return (char*)p + 0x20; }

void TWindowSubShortMail__sub_8027FAD0(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0xCC) = (u8) (*(u8 *)((s8 *)arg0 + 0xCC) & ~0xA);
    *(u8 *)((s8 *)arg0 + 0xCC) = (u8) (*(u8 *)((s8 *)arg0 + 0xCC) | 4);
}

TWindowSubShortMail::TWindowSubShortMail(TObject *object, void *arg2) : TObject(object) {
    m_name = TWindowSubShortMail__class_name;
    *(void **)((s8 *)this + 0x34) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_40 = 0;
    this->m_54 = 0;
    this->m_58 = 0;
    this->m_38 = 0;
    this->message_window = 0;
    this->m_44 = 0;
    this->m_48 = 0;
    this->m_4c = 0;
    this->keyboard = 0;
    this->m_50 = 0;
    this->mail_id = -1;
    this->m_28 = -1;
    this->m_2c = 0;
    this->m_30 = 0;
    *(u8 *)((s8 *)this + 0x1C) = 0;
}

extern "C" {
TWindowSubShortMail::~TWindowSubShortMail() {
    if (m_50 != 0U) {
        ((TWindowSubComCard *)m_50)->close();
        m_50 = 0U;
    }
    if (keyboard != 0U) {
        ((TObject *)keyboard)->queue_destruction();
        keyboard = 0U;
    }
    if (m_4c != 0U) {
        ((TWindowBase *)m_4c)->close();
        m_4c = 0U;
    }
    if (m_48 != 0U) {
        ((TWindowBase *)m_48)->close();
        m_48 = 0U;
    }
    if (m_44 != 0U) {
        ((TWindowBase *)m_44)->close();
        m_44 = 0U;
    }
    if (message_window != 0U) {
        ((TWindowBase *)message_window)->close();
        message_window = 0U;
    }
    if (m_38 != 0U) {
        ((TWindowBase *)m_38)->close();
        m_38 = 0U;
    }
    if (m_58 != 0U) {
        ((TWindowBase *)m_58)->close();
        m_58 = 0U;
    }
    if (m_54 != 0U) {
        ((TWindowBase *)m_54)->close();
        m_54 = 0U;
    }
    if (m_40 != 0U) {
        ((TWindowBase *)m_40)->close();
        m_40 = 0U;
    }
    TLobby__sub_802258C8();
    TLobby::sync_auto_reply_state();
}

void TWindowSubShortMail::run_task() {
    ShortMail_8027EF98 *o = (ShortMail_8027EF98 *)this;
    switch (o->state) {
    case 0:
    case 1:
        if (o->w48 != NULL) { ((TWindowBase *)o->w48)->close(); o->w48 = NULL; }
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w5c != NULL) { ((TObject *)o->w5c)->queue_destruction(); o->w5c = NULL; }
        if (o->w38 != NULL) { ((TWindowBase *)o->w38)->close(); o->w38 = NULL; }
        if (o->w58 != NULL) { ((TWindowBase *)o->w58)->close(); o->w58 = NULL; }
        if (o->w54 != NULL) { ((TWindowBase *)o->w54)->close(); o->w54 = NULL; }
        if (o->w40 == NULL) {
            o->w40 = ((void * (*)(void *)) TWindowSubShortMail::create_menu)(o);
        }
        ((TWindowMenu *)(o->w40))->clear_flag_and_release();
        o->state = 2;
    case 2:
        if (((TWindowMenu *)((saddr)o->w40))->is_cancelled() != 0) {
            o->parent->m7();
            o->state = 0x1C;
        } else if (((TWindowMenu *)(o->w40))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->w40)->get_selected_value();
        }
        break;
    case 3:
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w54 == NULL) {
            o->w54 = TWindowSubComCard::send_cmd_133();
        }
        if (o->w58 == NULL) {
            o->f28 = ((TWindowMenu *)o->w54)->get_selected_value();
            o->w58 = TWindowSubComCard::send_command(o->f28);
        }
        ((TWindowMenu *)(o->w54))->clear_flag_and_release();
        o->state = 4;
    case 4:
        update_display_value__17TWindowSubComCardFUiUiPv((uaddr)o->w54, (uaddr)o->w58, (s32 *)&o->f28);
        if (((TWindowMenu *)((saddr)o->w54))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TWindowMenu *)(o->w54))->is_decided() != 0) {
            void *p;
            o->f30 = -1;
            p = get_card_entry__17TWindowSubComCardFi(((TWindowMenu *)o->w54)->get_selected_value());
            if (p != NULL) {
                o->f2c = reinterpret_cast<GuildCardEntry *>(p)->get_card_id();
            }
            o->state = 0xB;
        }
        break;
    case 7:
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w5c != NULL) { ((TObject *)o->w5c)->queue_destruction(); o->w5c = NULL; }
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w38 == NULL) {
            o->w38 = ((void * (*)(void *)) create_list_item__19TWindowSubShortMailFv)(o);
            ((TWindowSubShortMail *)(o->w38))->advance_line(-1);
        }
        refresh_mail_list(o->w38);
        ((TWindowMenuIconLine *)(o->w38))->clear_decided();
        o->state = 8;
    case 8:
        if (TWindowSubShortMail::is_active() != 0) {
            refresh_mail_list(o->w38);
        }
        update_mail_count();
        if (((TWindowMenuIconLine *)(o->w38))->is_cancelled() != 0) {
            o->parent->m7();
            o->state = 0x1C;
        } else if (((TWindowMenuIconLine *)(o->w38))->is_decided() != 0) {
            o->state = 9;
        }
        break;
    case 9:
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w3c != NULL) { ((TWindowBase *)o->w3c)->close(); o->w3c = NULL; }
        if (o->w44 == NULL) {
            o->w44 = ((void * (*)(void *)) TWindowSubShortMail::build_menu)(o);
        }
        ((TWindowMenu *)(o->w44))->clear_flag_and_release();
        ((TWindowMenu *)(o->w44))->clear_transition_flag();
        o->state = 0xA;
    case 10:
        if (TWindowSubShortMail::is_active() != 0 && refresh_mail_list(o->w38) == 0) {
            o->state = 7;
        } else if (((TWindowMenu *)((saddr)o->w44))->is_cancelled() != 0) {
            o->state = 7;
        } else if (((TWindowMenu *)(o->w44))->is_decided() != 0) {
            void *p;
            o->f30 = ((TWindowMenuIconLine *)(o->w38))->get_cursor_value();
            p = TLobby::find_short_mail_by_id(o->f30);
            if (p != NULL) {
                o->f2c = TWindowSubShortMail__sub_8007B834(p);
            }
            o->state = ((TWindowMenu *)o->w44)->get_selected_value();
        }
        break;
    case 11:
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w3c != NULL) { ((TWindowBase *)o->w3c)->close(); o->w3c = NULL; }
        if (o->w38 != NULL) { ((TWindowBase *)o->w38)->close(); o->w38 = NULL; }
        if (o->w58 != NULL) { ((TWindowBase *)o->w58)->close(); o->w58 = NULL; }
        if (o->w54 != NULL) { ((TWindowBase *)o->w54)->close(); o->w54 = NULL; }
        if (o->w40 != NULL) { ((TWindowBase *)o->w40)->close(); o->w40 = NULL; }
        if (o->w5c == NULL) {
            o->w5c = ((void * (*)()) TWindowSubShortMail::create_keyboard)();
        }
        ((TKeyBoardControl *)(o->w5c))->set_position(((void *)((saddr (*)(int)) get_window_layout_position)(0xBB)));
        reinterpret_cast<TKeyBoardControl *>(o->w5c)->clear_keyboard_flag60_bit1();
        ((TKeyBoardControl *)(o->w5c))->show();
        o->state = 0xC;
    case 12:
        if (((TKeyBoardControl *)(o->w5c))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TKeyBoardControl *)(o->w5c))->is_confirmed() != 0) {
            o->state = 0xD;
        }
        break;
    case 13:
        ((TKeyBoardControl *)(o->w5c))->set_position((void *)get_window_layout_position(0xBC));
        ((TKeyBoardControl *)o->w5c)->hide();
        o->w50 = ((void * (*)(void *, s32)) open_confirm_prompt__19TWindowSubShortMailFPvi)(o, o->f20);
        o->state = 0xE;
    case 14:
        if (((TWindowSubComCard *)(o->w50))->get_card_data() != 0) {
            o->state = 0xB;
        } else if (((TWindowMessageYesNo *)(o->w50))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->w50))->get_slot_or_neg1() == 0) {
                close();
                o->state = 1;
            } else {
                o->state = 0xB;
            }
        }
        break;
    case 15:
        TWindowSubShortMail__sub_8027E620(o);
        o->state = 0x10;
    case 16:
        o->state = 1;
        break;
    case 17:
        ((TWindowOptionCtrl *)(o->w44))->open();
        o->w50 = ((void * (*)(void *)) open_confirm_dialog__19TWindowSubShortMailFv)(o);
        o->state = 0x12;
    case 18:
        if (TWindowSubShortMail::is_active() != 0 && refresh_mail_list(o->w38) == 0) {
            o->state = 7;
        } else if (((TWindowSubComCard *)(o->w50))->get_card_data() != 0) {
            o->state = 9;
        } else if (((TWindowMessageYesNo *)(o->w50))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->w50))->get_slot_or_neg1() == 0) {
                remove_short_mail_by_id(((TWindowMenuIconLine *)(o->w38))->get_cursor_value());
                o->state = 7;
            } else {
                o->state = 9;
            }
        }
        break;
    case 19:
        if (TLobby::is_active() != 0) {
            o->state = 0x14;
        } else {
            o->state = 0x18;
        }
        break;
    case 20:
        if (o->w4c != NULL) { ((TWindowBase *)o->w4c)->close(); o->w4c = NULL; }
        if (o->w44 == NULL) {
            o->w44 = ((void * (*)(void *)) TWindowSubShortMail::create_confirm_menu_window)(o);
        }
        if (o->w48 == NULL) {
            o->w48 = ((void * (*)(void *)) TWindowSubShortMail::create_window)(o);
        }
        ((TWindowMenu *)(o->w44))->clear_flag_and_release();
        o->state = 0x15;
    case 21:
        if (((TWindowMenu *)((saddr)o->w44))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TWindowMenu *)(o->w44))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->w44)->get_selected_value();
        }
        break;
    case 22:
        if (o->w4c == NULL) {
            o->w4c = ((void * (*)()) TWindowSubShortMail::open_menu)();
        }
        o->state = 0x17;
    case 23:
        if (((TWindowMenu *)((saddr)o->w4c))->is_cancelled() != 0) {
            o->state = 0x14;
        } else if (((TWindowMenu *)(o->w4c))->is_decided() != 0) {
            if (TLobby::set_flag_bit0(((TWindowMenu *)o->w4c)->get_selected_value()) != 0) {
                if (o->w48 != NULL) { ((TWindowBase *)o->w48)->close(); o->w48 = NULL; }
            }
            o->state = 0x14;
        }
        break;
    case 24:
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w48 != NULL) { ((TWindowBase *)o->w48)->close(); o->w48 = NULL; }
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w40 != NULL) { ((TWindowBase *)o->w40)->close(); o->w40 = NULL; }
        if (o->w5c == NULL) {
            o->w5c = ((void * (*)()) TWindowSubShortMail::create_keyboard)();
            ((TKeyBoardControl *)o->w5c)->set_text((char *)((void * (*)()) get_card_window_area__6TLobbyFv)());
        }
        ((TKeyBoardControl *)(o->w5c))->set_position(((void *)((saddr (*)(int)) get_window_layout_position)(0xBB)));
        reinterpret_cast<TKeyBoardControl *>(o->w5c)->clear_keyboard_flag60_bit1();
        ((TKeyBoardControl *)(o->w5c))->show();
        o->state = 0x19;
    case 25:
        if (((TKeyBoardControl *)(o->w5c))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TKeyBoardControl *)(o->w5c))->is_confirmed() != 0) {
            o->state = 0x1A;
        }
        break;
    case 26:
        ((TKeyBoardControl *)(o->w5c))->set_position((void *)get_window_layout_position(0xBC));
        ((TKeyBoardControl *)o->w5c)->hide();
        if (o->w50 == NULL) {
            o->w50 = ((void * (*)(void *)) open_delete_confirm_dialog__19TWindowSubShortMailFv)(o);
        }
        o->state = 0x1B;
    case 27:
        if (((TWindowSubComCard *)(o->w50))->get_card_data() != 0) {
            o->state = 0x18;
        } else if (((TWindowMessageYesNo *)(o->w50))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->w50))->get_slot_or_neg1() == 0) {
                void *b = ((TKeyBoardControl *)o->w5c)->realloc_buffer();
                ((TLobby *)b)->set_short_mail_text();
                mem_free(b);
                o->state = 1;
            } else {
                o->state = 0x18;
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
}

s32 TWindowSubShortMail::create_list_item() {
    saddr temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0x9B);
    temp_r31 = (saddr)fn_80267F38(window_layout_position, (saddr)lbl_8044FAC4, 8, (s16) this->m_20);
    ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x2E));
    ((TWindowSubShortCutList *)temp_r31)->set_flag70_bit10();
    return temp_r31;
}

s32 TWindowSubShortMail::refresh_mail_list(void *arg1) {
    s32 n;
    u32 id;
    s32 i;
    s16 sel;
    saddr e;
    id = ((TWindowMenuIconLine *)arg1)->get_cursor_value();
    sel = -1;
    TLobby::clear_lobby_flag();
    ((TShopArmorListWindow *)arg1)->save_cursor_selection();
    ((TWindowMenuIconLine *)arg1)->reset_list();
    n = TLobby::get_short_mail_ctrl();
    i = n - 1;
    while (i >= 0) {
        e = (saddr)get_short_mail_entry(i);
        add_status_entry__20TWindowSubStatusDispFScll(arg1, ((s32 (*)(s32)) TWindowSubShortMail::get_field_cc)(e), fn_8007B83C(e), (u32)reinterpret_cast<ShortMailEntry *>(e)->get_id());
        if (id == (u32)reinterpret_cast<ShortMailEntry *>(e)->get_id()) {
            sel = (n - 1) - i;
        }
        i--;
    }
    if (n <= 0) {
        ((TWindowSubShortMail *)arg1)->advance_line(-1);
        if (this->message_window != 0) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0;
        }
    } else if (this->message_window == 0) {
        *(void * *)&this->message_window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x9C)), (const f32 *)lbl_8044FACC, 1);
        this->mail_id = -1;
    }
    if (sel == -1) {
        ((TShopArmorListWindow *)arg1)->clamp_selection_to_valid_entry();
        return 0;
    }
    ((TWindowSubShortCutList *)arg1)->set_cursor_index(sel);
    return 1;
}

s32 TWindowSubShortMail::create_menu(void) {
    saddr list;

    list = create_titled_window_menu_default(get_window_layout_position(0x9A), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x57)), 6, 3);
    } else {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 3);
    }
    if (TLobby::get_short_mail_ctrl() > 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0xCE)), 6, 7);
    } else {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xCE)), 6, 7);
    }
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x103)), 6, 0x13);
    } else {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x103)), 6, 0x13);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(179.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

#pragma push
#pragma fp_contract on
s32 TWindowSubShortMail::build_menu(void) {
    saddr list;
    s32 msg;
    list = create_titled_window_menu_default((s32)(get_window_layout_position(0x9D)), 3, (s32)((saddr)TWindowSubStatusDisp::get_message_10(0x1E)));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x7F)), 6, 0xB);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    } else {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x7F)), 6, 0xB);
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x5A)), 6, 0x11);
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(206.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

#pragma pop
TKeyBoardControl *TWindowSubShortMail::create_keyboard() {
    TKeyBoardControl *keyboard = new TKeyBoardControl(reinterpret_cast<TObject *>(tl_00), 0xC6, 5, 4, local_client_id);
    keyboard->set_composer_flag62_bit4();
    keyboard->set_sub_position(reinterpret_cast<u8 *>(get_window_layout_position(0xBB)));
    keyboard->set_flag62_bit2();
    keyboard->set_soft_flag60_bit1();
    return keyboard;
}

s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *window_message_yes_no, saddr arg1) {
    saddr temp_r29;
    temp_r29 = (saddr)TWindowMessageYesNo::create((void *)(window_message_yes_no), arg1, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x3f)), (s32)(get_window_layout_position(0x9e)), 205.0f);
    ((TWindowMessageYesNo *)temp_r29)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)temp_r29)->set_choice_menu_flag70_bit10();
    return temp_r29;
}

s32 TWindowSubShortMail::create_confirm_menu_window(void) {
    saddr menu;
    menu = create_window_menu_default((saddr)((void *)(((saddr)get_window_layout_position(0xA0)))), 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)menu, (int)((int) ((saddr)TWindowSubStatusDisp::get_message_10(0x107))), 6, 0x16);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)menu, (int)((int) ((saddr)TWindowSubStatusDisp::get_message_10(0x108))), 6, 0x18);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(206.0f);
    return menu;
}

s32 TWindowSubShortMail::create_window(void) {
    s32 window_layout_position;
    saddr list;

    window_layout_position = get_window_layout_position(0xA1);
    list = create_window_menu_default(window_layout_position, 2);
    if (get_flag_bit0__6TLobbyFv() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x105)), 0, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)(get_card_window_area__6TLobbyFv()), 0, 0);
    } else {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)list, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x106)), 0, 0);
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(get_card_window_area__6TLobbyFv()), 0, 0);
    }
    ((TAdChrSelASlotGC *)list)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)list);
    ((TWindowSubComCardList *)list)->set_scroll_target(206.0f, 140.0f);
    return list;
}

s32 TWindowSubShortMail::open_menu(void) {
    s32 window_layout_position;
    saddr menu;

    window_layout_position = get_window_layout_position(0xA2);
    menu = create_window_menu_default(window_layout_position, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)menu, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x105)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)menu, (int)((saddr)TWindowSubStatusDisp::get_message_10(0x106)), 6, 0);
    if (get_flag_bit0__6TLobbyFv() == 0) {
        ((TWindowSubComCardList *)menu)->set_selected_index(1);
    }
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(206.0f);
    return menu;
}

s32 TWindowSubShortMail::open_confirm_dialog() {
    saddr temp_r29;

    temp_r29 = (saddr)TWindowMessageYesNo::create((void *)(this), this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x3e)), (s32)(get_window_layout_position(0x9f)), 206.0f);
    ((TWindowMessageYesNo *)temp_r29)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)temp_r29)->set_choice_menu_flag70_bit10();
    return temp_r29;
}

s32 TWindowSubShortMail::open_delete_confirm_dialog() {
    saddr temp_r29;

    temp_r29 = (saddr)TWindowMessageYesNo::create((void *)(this), this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (uaddr)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (saddr)((saddr)TWindowSubStatusDisp::get_message_10(0x104)), (s32)(get_window_layout_position(0xa3)), 206.0f);
    ((TWindowMessageYesNo *)temp_r29)->set_menu_selected_index(0);
    ((TWindowMessageYesNo *)temp_r29)->set_choice_menu_flag70_bit10();
    return temp_r29;
}

void TWindowSubShortMail::update_mail_count() {
    s32 temp_r3;

    if ((u32) this->message_window != 0U) {
        temp_r3 = ((TWindowMenuIconLine *)this->m_38)->get_cursor_value();
        if ((s32) this->mail_id != temp_r3) {
            this->mail_id = temp_r3;
            if (TLobby::find_short_mail_by_id(this->mail_id) != 0U) {
                ((TWindowMessage *)(this->message_window))->append_line(((s32 (*)()) TWindowSubShortMail::get_mail_ptr)(), 0x482);
            }
        }
    }
}

void TWindowSubShortMail::close() {
    saddr src;
    s32 short_mail_ctrl;
    saddr temp_r30;
    s32 i;

    src = (saddr)((TKeyBoardControl *)this->keyboard)->realloc_buffer();
    TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
    TLobby::send_simple_mail(this->m_2c, (void *)(get_shared_text_buffer()));
    mem_free((void *)src);
    short_mail_ctrl = TLobby::get_short_mail_ctrl();
    for (i = 0; i < short_mail_ctrl; i += 1) {
        temp_r30 = (saddr)get_short_mail_entry(i);
        if ((u32) this->m_30 == reinterpret_cast<ShortMailEntry *>(temp_r30)->get_id()) {
            ((s32 (*)(s32)) TWindowSubShortMail__sub_8027FAD0)(temp_r30);
            return;
        }
    }
}

void TWindowSubShortMail__sub_8027E620(void *p) {
    u8 *storage = static_cast<u8 *>(p);
    TWindowMenuIconLine *mail_list = *reinterpret_cast<TWindowMenuIconLine **>(storage + 0x38);
    get_card_entry__17TWindowSubComCardFi(mail_list->get_cursor_value());
    TLobby::send_find_user_self_tag(*reinterpret_cast<saddr *>(storage + 0x2C));
}
