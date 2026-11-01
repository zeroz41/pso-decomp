#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/quest/TQuestThread.h"
class TChCrTagPlBack;
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TUnk_804D1AD0.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/ui/TAdChrSelASlotGC.h"

extern "C" {
s32 get_message_10__20TWindowSubStatusDispFl(s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 get_window_layout_position(s32);
s32 create_confirm_menu_window__19TWindowSubShortMailFv();
s32 align_menu_entry_positions(s32);
s32 build_menu__19TWindowSubShortMailFv();
int get_cursor_value__19TWindowMenuIconLineFv(void *);
u8 get_field_cc__19TWindowSubShortMailFPv(void *);
s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *, s32);
s32 create_keyboard__19TWindowSubShortMailFv();
s32 create_list_item__19TWindowSubShortMailFv(void *);
s32 create_menu__19TWindowSubShortMailFv();
s32 create_window__19TWindowSubShortMailFv();
s32 open_confirm_dialog__19TWindowSubShortMailFv(void *);
s32 open_delete_confirm_dialog__19TWindowSubShortMailFv(void *);
s32 open_menu__19TWindowSubShortMailFv();
void *find_short_mail_by_id__6TLobbyFUi(u32 id);
int get_card_entry__17TWindowSubComCardFi();
void TWindowSubShortMail__sub_8027FAD0(u8 *);
void mem_free(void *p);
s32 get_card_window_area__6TLobbyFv();
void * get_mail_ptr__19TWindowSubShortMailFPv(void *);
s32 realloc_buffer__17TWindowSubComCardFv(s32);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
s32 get_main_phase();
s32 draw_card_icon__17TWindowSubComCardFll(s32, s32, s32);
extern const f32 TWindowSubShortMail__data_805DD6C8;
s32 fn_8007B83C(s32);
void *TLobby__sub_8022598C(int a0);
u32 get_lobby_id__6TLobbyFPv();
int get_short_mail_ctrl__6TLobbyFv(void);
void clear_lobby_flag__6TLobbyFv(void);
s32 add_status_entry__20TWindowSubStatusDispFScll(void *, s32, s32, u32);
void *create__14TWindowMessageFPvll(s32, void *, s32);
extern s32 lbl_8044FACC[];
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, s32, s32, s32);
s32 free_member__17TWindowSubComCardFv(s32, s32);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);
extern const f32 lbl_805DD6D0;
void TWindowSubShortMail__sub_8027E620(void* p);
s32 TKeyBoardControl__ct(s32, s32, s32, s32, s32, s32);
s32 get_shared_text_buffer();
void send_simple_mail__6TLobbyFiPv(s32 arg0, void *arg1);
int send_find_user_self_tag__6TLobbyFi(void*);
s32 __nw__7TObjectFUl(s32);
u8 *fn_80267F38(s32 arg0, s32 arg1, s32 arg2, s16 arg3);
int get_flag_bit0__6TLobbyFv(void);
}
void update_chat_window(void *p);

void TWindowSubShortMail__sub_8027E620(void* p) { ((TWindowMenuIconLine *)(*(void**)((char*)p + 0x38)))->get_cursor_value(); get_card_entry__17TWindowSubComCardFi(); send_find_user_self_tag__6TLobbyFi(*(void**)((char*)p + 0x2c)); }

void TWindowSubShortMail::close() {
    s32 temp_r31;
    s32 temp_r31_2;
    s32 temp_r30;
    s32 var_r29;

    temp_r31 = realloc_buffer__17TWindowSubComCardFv(this->m_5c);
    TWindowSubComCard::mask_profanity_words((char *)temp_r31, (char *)get_shared_text_buffer());
    send_simple_mail__6TLobbyFiPv(this->m_2c, (void *)(get_shared_text_buffer()));
    mem_free((void *)temp_r31);
    temp_r31_2 = get_short_mail_ctrl__6TLobbyFv();
    for (var_r29 = 0; var_r29 < temp_r31_2; var_r29 += 1) {
        temp_r30 = (s32)TLobby__sub_8022598C(var_r29);
        if ((u32) this->m_30 == get_lobby_id__6TLobbyFPv()) {
            ((s32 (*)(s32)) TWindowSubShortMail__sub_8027FAD0)(temp_r30);
            return;
        }
    }
}

void TWindowSubShortMail::update_mail_count() {
    s32 temp_r3;

    if ((u32) this->m_3c != 0U) {
        temp_r3 = ((TWindowMenuIconLine *)this->m_38)->get_cursor_value();
        if ((s32) this->m_24 != temp_r3) {
            this->m_24 = temp_r3;
            if (find_short_mail_by_id__6TLobbyFUi(this->m_24) != 0U) {
                ((TWindowMessage *)(this->m_3c))->append_line(((s32 (*)()) get_mail_ptr__19TWindowSubShortMailFPv)(), 0x482);
            }
        }
    }
}

s32 TWindowSubShortMail::open_delete_confirm_dialog() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x104)), (s32)(get_window_layout_position(0xa3)), (f32)TWindowSubShortMail__data_805DD6C8);
    free_member__17TWindowSubComCardFv(temp_r29, 0);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 TWindowSubShortMail::open_confirm_dialog() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x3e)), (s32)(get_window_layout_position(0x9f)), (f32)TWindowSubShortMail__data_805DD6C8);
    free_member__17TWindowSubComCardFv(temp_r29, 0);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 open_menu__19TWindowSubShortMailFv(void) {
    s32 window_layout_position;
    s32 temp_r31;

    window_layout_position = get_window_layout_position(0xA2);
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(window_layout_position, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x105)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x106)), 6, 0);
    if (get_flag_bit0__6TLobbyFv() == 0) {
        ((TWindowSubComCardList *)temp_r31)->set_selected_index(1);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(TWindowSubShortMail__data_805DD6C8);
    return temp_r31;
}

extern const f32 lbl_805DD6CC;

s32 create_window__19TWindowSubShortMailFv(void) {
    s32 window_layout_position;
    s32 temp_r31;

    window_layout_position = get_window_layout_position(0xA1);
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(window_layout_position, 2);
    if (get_flag_bit0__6TLobbyFv() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x105)), 0, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_card_window_area__6TLobbyFv()), 0, 0);
    } else {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x106)), 0, 0);
        TWindowSubComCard::draw_text_gray(temp_r31, get_card_window_area__6TLobbyFv(), 0, 0);
    }
    ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)temp_r31);
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(TWindowSubShortMail__data_805DD6C8, lbl_805DD6CC);
    return temp_r31;
}

extern s32 local_client_id;
extern s32 tl_00;

s32 create_confirm_menu_window__19TWindowSubShortMailFv(void) {
    s32 temp_r31;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((s32)((void *)(((s32)get_window_layout_position(0xA0)))), 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (get_message_10__20TWindowSubStatusDispFl(0x107))), 6, 0x16);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (get_message_10__20TWindowSubStatusDispFl(0x108))), 6, 0x18);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(TWindowSubShortMail__data_805DD6C8);
    return temp_r31;
}

s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *window_message_yes_no, s32 arg1) {
    s32 temp_r29;
    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(window_message_yes_no, arg1, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x3f)), (s32)(get_window_layout_position(0x9e)), (f32)lbl_805DD6D0);
    free_member__17TWindowSubComCardFv(temp_r29, 0);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 create_keyboard__19TWindowSubShortMailFv(void) {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0x2C);
    if (var_r31 != 0) {
        var_r31 = TKeyBoardControl__ct(var_r31, tl_00, 0xC6, 5, 4, local_client_id);
    }
    update_chat_window((void *)var_r31);
    ((TWindowMakeTeam *)var_r31)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TWindowMakeTeam *)var_r31)->set_keyboard_flag62_bit2();
    ((TWindowSubComCard *)var_r31)->destroy_keyboard();
    return var_r31;
}

extern const f32 lbl_805DD6D4;

#pragma push
#pragma fp_contract on
s32 build_menu__19TWindowSubShortMailFv(void) {
    s32 temp_r31;
    s32 msg;
    temp_r31 = draw_card_icon__17TWindowSubComCardFll((s32)(get_window_layout_position(0x9D)), 3, (s32)(get_message_10__20TWindowSubStatusDispFl(0x1E)));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x7F)), 6, 0xB);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x59)), 6, 0xF);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0x7F), 6, 0xB);
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0x59), 6, 0xF);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x5A)), 6, 0x11);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(TWindowSubShortMail__data_805DD6C8);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}
#pragma pop

s32 create_menu__19TWindowSubShortMailFv(void) {
    s32 temp_r31;

    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x9A), 3, get_message_10__20TWindowSubStatusDispFl(0x1D));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x57)), 6, 3);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0x57), 6, 3);
    }
    if (get_short_mail_ctrl__6TLobbyFv() > 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xCE)), 6, 7);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xCE), 6, 7);
    }
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x103)), 6, 0x13);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0x103), 6, 0x13);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD6D4);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

extern s32 lbl_8044FAC4[];

s32 TWindowSubShortMail::refresh_mail_list(void *arg1) {
    s32 n;
    u32 id;
    s32 i;
    s16 sel;
    s32 e;
    id = get_cursor_value__19TWindowMenuIconLineFv(arg1);
    sel = -1;
    clear_lobby_flag__6TLobbyFv();
    ((TShopArmorListWindow *)arg1)->save_cursor_selection();
    ((TWindowMenuIconLine *)arg1)->reset_list();
    n = get_short_mail_ctrl__6TLobbyFv();
    i = n - 1;
    while (i >= 0) {
        e = (s32)TLobby__sub_8022598C(i);
        add_status_entry__20TWindowSubStatusDispFScll(arg1, ((s32 (*)(s32)) get_field_cc__19TWindowSubShortMailFPv)(e), fn_8007B83C(e), ((u32 (*)(s32))get_lobby_id__6TLobbyFPv)(e));
        if (id == ((u32 (*)(s32))get_lobby_id__6TLobbyFPv)(e)) {
            sel = (n - 1) - i;
        }
        i--;
    }
    if (n <= 0) {
        ((TWindowSubShortMail *)arg1)->advance_line(-1);
        if (this->m_3c != 0) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0;
        }
    } else if (this->m_3c == 0) {
        *(void * *)&this->m_3c = create__14TWindowMessageFPvll(get_window_layout_position(0x9C), lbl_8044FACC, 1);
        this->m_24 = -1;
    }
    if (sel == -1) {
        ((TShopArmorListWindow *)arg1)->clamp_selection_to_valid_entry();
        return 0;
    }
    ((TWindowSubShortCutList *)arg1)->set_cursor_index(sel);
    return 1;
}

s32 TWindowSubShortMail::create_list_item() {
    s32 temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0x9B);
    temp_r31 = (s32)fn_80267F38(window_layout_position, (s32)lbl_8044FAC4, 8, (s16) this->m_20);
    ((TWindowMenuIconLine *)temp_r31)->ensure_status_display(get_message_10__20TWindowSubStatusDispFl(0x2E));
    ((TWindowSubShortCutList *)temp_r31)->set_flag70_bit10();
    return temp_r31;
}

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
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
void queue_destruction__7TObjectFv(void *arg0);
void *send_cmd_133__17TWindowSubComCardFv(void);
void *send_command__17TWindowSubComCardFi(s32);
void update_display_value__17TWindowSubComCardFUiUiPv(u32 arg0, u32 arg1, s32 *arg2);
s32 TWindowSubShortMail__sub_8007B834(void *);
void TWindowSubShortMail__sub_80131998(void *);
void TWindowSubShortMail__sub_8027E620(void *p);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern const f32 lbl_805DD6D8;
void remove_short_mail_by_id(u32 id);
extern "C" {
void get_keyboard_field_6c__15TWindowMakeTeamFv(void *, void *);
struct VObj_8027FBF0_Base_8027fbf0_8027E620 { char pad[0x18]; };
struct VObj_8027FBF0_8027E620 : VObj_8027FBF0_Base_8027fbf0_8027E620 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

void *__dt__19TWindowSubShortMailFv(TWindowSubShortMail *arg0, s16 arg1);
void TLobby__sub_802258C8(void);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void fn_8027FD94(void *p, s16 v);
s32 is_player_input_active(s32);

void TWindowSubShortMail::render() {  }

extern s32 __vt__19TWindowSubShortMail[];

void TWindowSubShortMail::run_task() {
    ShortMail_8027EF98 *o = (ShortMail_8027EF98 *)this;
    switch (o->state) {
    case 0:
    case 1:
        if (o->w48 != NULL) { ((TWindowBase *)o->w48)->close(); o->w48 = NULL; }
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w5c != NULL) { queue_destruction__7TObjectFv(o->w5c); o->w5c = NULL; }
        if (o->w38 != NULL) { ((TWindowBase *)o->w38)->close(); o->w38 = NULL; }
        if (o->w58 != NULL) { ((TWindowBase *)o->w58)->close(); o->w58 = NULL; }
        if (o->w54 != NULL) { ((TWindowBase *)o->w54)->close(); o->w54 = NULL; }
        if (o->w40 == NULL) {
            o->w40 = ((void * (*)(void *)) create_menu__19TWindowSubShortMailFv)(o);
        }
        ((TWindowSubComCard *)(o->w40))->clear_flag_and_release();
        o->state = 2;
    case 2:
        if (((TWindowMenu *)((s32)o->w40))->is_cancelled() != 0) {
            o->parent->m7();
            o->state = 0x1C;
        } else if (((TWindowMenu *)(o->w40))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->w40)->get_selected_value();
        }
        break;
    case 3:
        if (o->w44 != NULL) { ((TWindowBase *)o->w44)->close(); o->w44 = NULL; }
        if (o->w54 == NULL) {
            o->w54 = send_cmd_133__17TWindowSubComCardFv();
        }
        if (o->w58 == NULL) {
            o->f28 = ((TWindowMenu *)o->w54)->get_selected_value();
            o->w58 = send_command__17TWindowSubComCardFi(o->f28);
        }
        ((TWindowSubComCard *)(o->w54))->clear_flag_and_release();
        o->state = 4;
    case 4:
        update_display_value__17TWindowSubComCardFUiUiPv((u32)o->w54, (u32)o->w58, (s32 *)&o->f28);
        if (((TWindowMenu *)((s32)o->w54))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TWindowMenu *)(o->w54))->is_decided() != 0) {
            void *p;
            o->f30 = -1;
            p = ((void * (*)(s32)) get_card_entry__17TWindowSubComCardFi)(((TWindowMenu *)o->w54)->get_selected_value());
            if (p != NULL) {
                o->f2c = ((TWindowSubComCard *)p)->get_card_id();
            }
            o->state = 0xB;
        }
        break;
    case 7:
        if (o->w50 != NULL) { ((TWindowSubComCard *)(o->w50))->close(); o->w50 = NULL; }
        if (o->w5c != NULL) { queue_destruction__7TObjectFv(o->w5c); o->w5c = NULL; }
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
            o->w44 = ((void * (*)(void *)) build_menu__19TWindowSubShortMailFv)(o);
        }
        ((TWindowSubComCard *)(o->w44))->clear_flag_and_release();
        ((TWindowSubComCard *)(o->w44))->clear_transition_flag();
        o->state = 0xA;
    case 10:
        if (TWindowSubShortMail::is_active() != 0 && refresh_mail_list(o->w38) == 0) {
            o->state = 7;
        } else if (((TWindowMenu *)((s32)o->w44))->is_cancelled() != 0) {
            o->state = 7;
        } else if (((TWindowMenu *)(o->w44))->is_decided() != 0) {
            void *p;
            o->f30 = ((s32 (*)(void *)) get_cursor_value__19TWindowMenuIconLineFv)(o->w38);
            p = find_short_mail_by_id__6TLobbyFUi(o->f30);
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
            o->w5c = ((void * (*)()) create_keyboard__19TWindowSubShortMailFv)();
        }
        ((TWindowSubShortMail *)(o->w5c))->set_position(((void *)((s32 (*)(int)) get_window_layout_position)(0xBB)));
        free_menu_object(o->w5c);
        ((TWindowSubShortMail *)(o->w5c))->hide_window();
        o->state = 0xC;
    case 12:
        if (((TWindowSubComCard *)(o->w5c))->is_keyboard_active() != 0) {
            o->state = 1;
        } else if (((TWindowSubComCard *)(o->w5c))->update_keyboard() != 0) {
            o->state = 0xD;
        }
        break;
    case 13:
        ((TWindowSubShortMail *)(o->w5c))->set_position(((void *)((s32 (*)(int)) get_window_layout_position)(0xBC)));
        TWindowSubShortMail__sub_80131998(o->w5c);
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
                remove_short_mail_by_id(((s32 (*)(void *)) get_cursor_value__19TWindowMenuIconLineFv)(o->w38));
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
            o->w44 = ((void * (*)(void *)) create_confirm_menu_window__19TWindowSubShortMailFv)(o);
        }
        if (o->w48 == NULL) {
            o->w48 = ((void * (*)(void *)) create_window__19TWindowSubShortMailFv)(o);
        }
        ((TWindowSubComCard *)(o->w44))->clear_flag_and_release();
        o->state = 0x15;
    case 21:
        if (((TWindowMenu *)((s32)o->w44))->is_cancelled() != 0) {
            o->state = 1;
        } else if (((TWindowMenu *)(o->w44))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->w44)->get_selected_value();
        }
        break;
    case 22:
        if (o->w4c == NULL) {
            o->w4c = ((void * (*)()) open_menu__19TWindowSubShortMailFv)();
        }
        o->state = 0x17;
    case 23:
        if (((TWindowMenu *)((s32)o->w4c))->is_cancelled() != 0) {
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
            o->w5c = ((void * (*)()) create_keyboard__19TWindowSubShortMailFv)();
            get_keyboard_field_6c__15TWindowMakeTeamFv(o->w5c, ((void * (*)()) get_card_window_area__6TLobbyFv)());
        }
        ((TWindowSubShortMail *)(o->w5c))->set_position(((void *)((s32 (*)(int)) get_window_layout_position)(0xBB)));
        free_menu_object(o->w5c);
        ((TWindowSubShortMail *)(o->w5c))->hide_window();
        o->state = 0x19;
    case 25:
        if (((TWindowSubComCard *)(o->w5c))->is_keyboard_active() != 0) {
            o->state = 1;
        } else if (((TWindowSubComCard *)(o->w5c))->update_keyboard() != 0) {
            o->state = 0x1A;
        }
        break;
    case 26:
        ((TWindowSubShortMail *)(o->w5c))->set_position(((void *)((s32 (*)(int)) get_window_layout_position)(0xBC)));
        TWindowSubShortMail__sub_80131998(o->w5c);
        if (o->w50 == NULL) {
            o->w50 = ((void * (*)(void *)) open_delete_confirm_dialog__19TWindowSubShortMailFv)(o);
        }
        o->state = 0x1B;
    case 27:
        if (((TWindowSubComCard *)(o->w50))->get_card_data() != 0) {
            o->state = 0x18;
        } else if (((TWindowMessageYesNo *)(o->w50))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->w50))->get_slot_or_neg1() == 0) {
                void *b = ((void * (*)(void *)) realloc_buffer__17TWindowSubComCardFv)(o->w5c);
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

void *__dt__19TWindowSubShortMailFv(TWindowSubShortMail *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSubShortMail;
        if ((u32) arg0->m_50 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x50)))->close();
            arg0->m_50 = 0U;
        }
        if ((u32) arg0->m_5c != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x5C));
            arg0->m_5c = 0U;
        }
        if ((u32) arg0->m_4c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
            arg0->m_4c = 0U;
        }
        if ((u32) arg0->m_48 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x48)))->close();
            arg0->m_48 = 0U;
        }
        if ((u32) arg0->m_44 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x44)))->close();
            arg0->m_44 = 0U;
        }
        if ((u32) arg0->m_3c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            arg0->m_3c = 0U;
        }
        if ((u32) arg0->m_38 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
            arg0->m_38 = 0U;
        }
        if ((u32) arg0->m_58 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x58)))->close();
            arg0->m_58 = 0U;
        }
        if ((u32) arg0->m_54 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x54)))->close();
            arg0->m_54 = 0U;
        }
        if ((u32) arg0->m_40 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            arg0->m_40 = 0U;
        }
        TLobby__sub_802258C8();
        TLobby::sync_auto_reply_state();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

extern void *TWindowSubShortMail__class_name;
TWindowSubShortMail::TWindowSubShortMail(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TWindowSubShortMail__class_name;
    *(void **)((s8 *)this + 0x34) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_40 = 0;
    this->m_54 = 0;
    this->m_58 = 0;
    this->m_38 = 0;
    this->m_3c = 0;
    this->m_44 = 0;
    this->m_48 = 0;
    this->m_4c = 0;
    this->m_5c = 0;
    this->m_50 = 0;
    this->m_24 = -1;
    this->m_28 = -1;
    this->m_2c = 0;
    this->m_30 = 0;
    *(u8 *)((s8 *)this + 0x1C) = 0;
}

void TWindowSubShortMail__sub_8027FAD0(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0xCC) = (u8) (*(u8 *)((s8 *)arg0 + 0xCC) & ~0xA);
    *(u8 *)((s8 *)arg0 + 0xCC) = (u8) (*(u8 *)((s8 *)arg0 + 0xCC) | 4);
}

void* get_mail_ptr__19TWindowSubShortMailFPv(void* p) { return (char*)p + 0x20; }

u8 get_field_cc__19TWindowSubShortMailFPv(void* p) { return *(u8*)((char*)p + 0xcc); }

s32 TUnk_804D1AD0::create_status_category_menu() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r31;
  s32 var_r31;
  if (TCameraCtrl::get_camera_id() > 2)
  {
    temp_r31 = ((s32 (*)(int)) get_window_layout_position)(0x18);
    var_r31 = create_window_menu(temp_r31, 3, (*((s32 *) (((s8 *) arg0) + 0x1C))));
  }
  else
  {
    temp_r31 = ((s32 (*)(int)) get_message_10__20TWindowSubStatusDispFl)(0x1D);
    var_r31 = create_titled_window_menu((int) ((s32 (*)(int)) get_window_layout_position)(0x18), 3, temp_r31, (*((s32 *) (((s8 *) arg0) + 0x1C))));
  }
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int) ((s32 (*)(int)) get_message_10__20TWindowSubStatusDispFl)(0x10A), 0x36, 0);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int) ((s32 (*)(int)) get_message_10__20TWindowSubStatusDispFl)(0x10B), 0x36, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int) ((s32 (*)(int)) get_message_10__20TWindowSubStatusDispFl)(0x10C), 0x36, 2);
  ((TWindowSubComCardList *)var_r31)->set_flag70_bit10();
  ((TWindowSubComCardList *)var_r31)->update_layout_height((f32) lbl_805DD6D8);
  ((s32 (*)(int)) align_menu_entry_positions)((int) var_r31);
  return var_r31;
}

void TUnk_804D1AD0::render() {  }

void TUnk_804D1AD0::run_task() {
    is_player_input_active(*(s32 *)&this->unk_1C);
    if (((TWindowMenu *)(*(s32 *)&this->unk_24))->is_cancelled() != 0) {
        ((VObj_8027FBF0_8027E620 *) this->m_20)->m7();
    }
    fn_8027FD94((void *)this->m_28, ((TWindowMenu *)(*(s32 *)&this->unk_24))->get_selected_value());
}

extern s32 status_category_window_vtable[];

void *TUnk_804D1AD0::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = status_category_window_vtable;
        if (*(void * *)&this->m_28 != NULL) { ((TWindowBase *)(*(void * *)&this->m_28))->close(); *(s32 *)&this->m_28 = 0; }
        if (*(void * *)&(*(u32 *)&this->unk_24) != NULL) { ((TWindowBase *)(*(void * *)&(*(u32 *)&this->unk_24)))->close(); *(s32 *)&(*(u32 *)&this->unk_24) = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
