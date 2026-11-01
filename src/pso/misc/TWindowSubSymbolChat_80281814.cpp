#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_802A5748.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/TWindowSubSymbolChat_80076F88.h"
#include "pso/misc/TWindowSubSymbolChat_80281814.h"
#include "pso/misc/TWindowSubSymbolChat_8028239C.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TWindowSubSymbolChatParts.h"
#include "pso/misc/TWindowChatSymbol_802486A8.h"
#include "pso/misc/TWindowSubSymbolChatHelp.h"
#include "pso/misc/TWindowSubSymbolChat_802838C4.h"
#include "pso/misc/TWindowSubSymbolChat_80283954.h"
#include "pso/unk/text_802841FC.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubSymbolChatFaceType.h"
#include "pso/misc/TLobby.h"

struct Win_80281EA8 { u8 pad[0x24]; s32 f24; };

struct Ent_80281B18 { s8 c; u8 pad[3]; };

struct Data_80281B18 { u8 pad0[4]; u16 w[4]; Ent_80281B18 e[1]; };

struct Quad_80281840 { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct Sub_80281840 { u8 pad[0x5C]; s32 count; };

struct Win_80281840 { u8 pad[0x24]; s32 ctrl; u8 pad2[0x34 - 0x28]; Sub_80281840 *sub; };

extern "C" {
s32 get_window_layout_position(s32);
u8 *create_chat_symbol_window__20TWindowSubSymbolChatFll(void *, s32);
s32 add__20TWindowSubSymbolChatFlllll(int, int, int, int, int, int);
s32 get_cursor_pos__20TWindowSubSymbolChatFv(int);
s32 get_cursor_x__20TWindowSubSymbolChatFv(int);
extern s32 TWindowSubSymbolChat__data_805D6498;
extern s32 TWindowSubSymbolChat__data_805D649C;
extern s32 TWindowSubSymbolChat__help_window;
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, s32, s32, s32);

s32 draw_card_icon__17TWindowSubComCardFll(s32, s32, s32);
s32 TWindowSubSymbolChat__sub_800771B0(s32, s32);
s32 TWindowSubSymbolChat__sub_800771C4(s32, s32);
s32 set_entry_bits__20TWindowSubSymbolChatFUsllll(s32, s32, s32, s32, s32, s32);
Data_80281B18 *get_data_ptr__20TWindowSubSymbolChatFv();
extern s8 TWindowSubSymbolChat__data_805D6494;
f32 get_scale__15TWindowCtrlMainFv(s32);
extern s32 lbl_805D63F0;

void TWindowSubSymbolChat__sub_80281840(Win_80281840 *arg0);
s32 TKeyBoardControl__ct(s32, void *, s32, s32, s32, s32);
s32 TWindowSubComCard__sub_80265660(s32, s32);
s32 align_menu_entry_positions(s32);
s32 TWindowSubSymbolChatPartsSet__ct(s32, s32, s16, s32 *, s32 *);
s32 TWindowSubSymbolChatParts__ct(s32, s32, s32 *, s32 *);
s32 __nw__7TObjectFUl(int);

int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);
s32 get_keyboard_field_6c__15TWindowMakeTeamFv(s32, s32);
s32 get_keyboard_ptr__20TWindowSubSymbolChatFv(s32);
s32 refresh_parts__20TWindowSubSymbolChatFv();
s32 refresh_with_default_list__20TWindowSubStatusDispFll(s32, s32 *);
}
void update_chat_window(void *p);

extern void *TWindowSubSymbolChat__instance;

void TWindowSubSymbolChat::close_child() {
    void *temp_r3;
    temp_r3 = TWindowSubSymbolChat__instance;
    if (temp_r3 != NULL) {
        TWindowSubSymbolChat__sub_80281840((Win_80281840 *)(temp_r3));
    }
}

void TWindowSubSymbolChat__sub_80281840(Win_80281840 *arg0) {
    Quad_80281840 q;
    u32 color;
    f32 scale;
    Sub_80281840 *sub;
    sub = arg0->sub;
    if (sub != NULL) {
        if (sub->count < 6) {
            color = ((s32)(0.16666667f * (f32)(sub->count * 0xFF)) << 24) | 0xFFFFFF;
        } else {
            color = 0xFFFFFFFF;
        }
        scale = (-1.0f) / get_scale__15TWindowCtrlMainFv(arg0->ctrl);
        begin_screen_draw(1);
        TObjFish::set_global_param(lbl_805D63F0);
        set_draw_texture_and_color(0, color);
        q.x = 482.0f;
        q.y = 344.0f;
        q.x2 = 14.0f + q.x;
        q.y2 = 12.0f + q.y;
        q.u0 = 0.875f;
        q.v0 = 0.33984375f;
        q.u1 = 0.9296875f;
        q.v1 = 0.38671875f;
        draw_textured_quad_at_depth((f32 *)&q, scale);
        TWindowSubStatusDisp::get_player();
    }
}

s32 TWindowSubSymbolChat::is_card_confirmed() {
    if (((TWindowMenu *)this->m_38)->get_selected_value() != 0x20) {
        return 0;
    }
    s32 temp;
    s32 ret;

    temp = get_cursor_pos__20TWindowShortListCtrlFv(this->m_38);
    ret = TWindowSubComCard__sub_80265660(this->m_38, temp);
    return ret ? 1 : 0;
}

void TWindowSubSymbolChat::update_sub_window() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    if (is_card_confirmed() == 0) {
        temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
        if (temp_r3 != NULL) {
            ((TWindowBase *)temp_r3)->close();
            *(u8 **)((s8 *)arg0 + 0x34) = NULL;
            ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x30) + 0x30))->copy_vec2((void*)(get_window_layout_position(0x7B)));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x30)) + 0x50) = 6;
        }
    } else {
        if ((void *) *(u8 **)((s8 *)arg0 + 0x34) == NULL) {
            *(u8 **)((s8 *)arg0 + 0x34) = create_chat_symbol_window__20TWindowSubSymbolChatFll(arg0, 0);
            ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x34)))->set_selection((int) (TWindowSubSymbolChat__sub_8028379C()));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x34)) + 0x64) = 1;
            ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x30) + 0x30))->copy_vec2((void*)(get_window_layout_position(0x7C)));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x30)) + 0x50) = 6;
        }
        ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x34)))->update_visibility();
    }
}

void TWindowSubSymbolChat::update_state() {
    s32 selected_menu_value;

    selected_menu_value = ((TWindowMenu *)(*(s32 *)((s8 *)this + 0x38)))->get_selected_value();
    switch (selected_menu_value) {
    case 22:
        *(s8 *)((s8 *)this + 0x1C) = 0x18;
        return;
    case 26:
        select_symbol_chat_slot((TWindowSubSymbolChatParts *)*(s32 *)((s8 *)this + 0x4C));
        ((TWindowSubSymbolChatPartsSet *)(*(s32 *)((s8 *)this + 0x30)))->update_visibility();
        if (TWindowSubSymbolChat::compute_total_height() <= 0) {
            *(s8 *)((s8 *)this + 0x1C) = 4;
            return;
        }
        *(s8 *)((s8 *)this + 0x1C) = 0x14;
        return;
    }
}

extern s32 local_client_id;

void TWindowSubSymbolChat::draw_selected_entry() {
    Data_80281B18 *data;
    u8 v;
    s16 y;
    s16 x;
    s32 i;
    s32 n;
    s32 pos;
    s32 inst;
    s32 rem;
    x = get_cursor_x__20TWindowSubSymbolChatFv(this->m_50);
    y = get_cursor_pos__20TWindowSubSymbolChatFv(this->m_50);
    inst = TWindowSubSymbolChat::get_instance();
    data = get_data_ptr__20TWindowSubSymbolChatFv();
    rem = TWindowSubSymbolChat::calc_remaining_slots();
    if (rem > this->m_1e) {
        ((TWindowSubSymbolChat *)(this->m_28))->set_entry(this->m_1e, data->e[this->m_1e].c, x, y, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
        if (TWindowSubSymbolChat__help_window != 0) {
            add__20TWindowSubSymbolChatFlllll(this->m_28, data->e[this->m_1e].c, 0x40 - x, y, (u8)(TWindowSubSymbolChat__data_805D6498 == 0), TWindowSubSymbolChat__data_805D649C);
        }
    } else {
        n = this->m_1e - rem;
        pos = x + y * 2;
        for (i = 0; i < 4; i++) {
            if (TWindowSubSymbolChat__sub_800771C4(inst, i) != 0 && n-- <= 0) {
                v = data->w[i];
                TWindowSubSymbolChat__sub_800771B0(this->m_28, i);
                set_entry_bits__20TWindowSubSymbolChatFUsllll(this->m_28, v, TWindowSubSymbolChat__data_805D6494, pos, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
                return;
            }
        }
    }
}

void TWindowSubSymbolChat::sub_80281C60() {
    s16 x;
    s16 y;
    x = get_cursor_x__20TWindowSubSymbolChatFv(this->m_50);
    y = get_cursor_pos__20TWindowSubSymbolChatFv(this->m_50);
    set_entry_bits__20TWindowSubSymbolChatFUsllll(this->m_28, this->m_1e, TWindowSubSymbolChat__data_805D6494, x + y * 2, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
}

void TWindowSubSymbolChat::sub_80281CC4() {
  s16 temp_r31;
  s16 temp_r3;
  s32 new_var;
  temp_r31 = get_cursor_x__20TWindowSubSymbolChatFv(this->m_50);
  temp_r3 = get_cursor_pos__20TWindowSubSymbolChatFv(this->m_50);
  add__20TWindowSubSymbolChatFlllll(this->m_28, this->m_1e, (int) ((s32) temp_r31), (int) ((s32) temp_r3), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D6498), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  new_var = (s32) temp_r3;
  if (((s32) TWindowSubSymbolChat__help_window) != 0)
  {
    add__20TWindowSubSymbolChatFlllll(this->m_28, this->m_1e, (int) (0x40 - temp_r31), (int) new_var, (int) ((s32) ((u8) ((*(s32 *)&TWindowSubSymbolChat__data_805D6498) == 0))), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  }
}

s32 TWindowSubSymbolChat::create_keyboard_control() {
    s32 keyboard;

    keyboard = __nw__7TObjectFUl(0x2C);
    if (keyboard != 0) {
        keyboard = TKeyBoardControl__ct(keyboard, this, 0x90, 1, 4, local_client_id);
    }
    update_chat_window((void *)keyboard);
    get_keyboard_field_6c__15TWindowMakeTeamFv(keyboard, get_keyboard_ptr__20TWindowSubSymbolChatFv(this->m_28));
    ((TWindowMakeTeam *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TWindowMakeTeam *)keyboard)->set_keyboard_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

extern s32 lbl_804D2B48[];

s32 TWindowSubSymbolChat::create_confirm_window() {
    s32 temp_r31;

    temp_r31 = refresh_with_default_list__20TWindowSubStatusDispFll(get_window_layout_position(0x79), lbl_804D2B48);
    ((TWindowMenuIconLine *)temp_r31)->ensure_status_display(get_message_10__20TWindowSubStatusDispFl(0xAC));
    TWindowOptionCtrl::add_menu_item(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xBF), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xC0), 0);
    if (TWindowSubSymbolChat__sub_80076FE0((void *)this->m_28) != 0) {
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(0);
    } else {
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(1);
    }
    ((TWindowSubShortCutList *)temp_r31)->set_flag70_bit10();
    return temp_r31;
}

s32 TWindowSubSymbolChat::open_confirm_prompt() {
    Win_80281EA8 *arg0 = (Win_80281EA8 *)this;
    s32 r = create__19TWindowMessageYesNoFPvPvPvPv(arg0, arg0->f24, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)r), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x44)), (s32)(get_window_layout_position(0x7A)), (f32)178.0f);
    ((TWindowSubShortMail *)r)->notify_warp_flag70();
    return r;
}

s32 TWindowSubSymbolChat::create_menu() {
    s32 temp_r31;

    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x79), 9, get_message_10__20TWindowSubStatusDispFl(0xAB));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB6)), 0x26, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB7)), 0x26, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB8)), 0x26, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB9)), 0x26, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xBA)), 0x26, 4);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xBB)), 0x26, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xBC)), 0x26, 6);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xBD)), 0x26, 7);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xBE)), 0x26, 8);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 create_menu__20TWindowSubSymbolChatFPv(void *window_sub_symbol_chat) {
    s32 temp_r31;

    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x79), 3, get_message_10__20TWindowSubStatusDispFl(0xAA));
    if (TWindowSubSymbolChat::compute_total_height() <= 0) {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xB0), 6, 0x16);
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xB1), 6, 0x1A);
    } else {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB0)), 6, 0x16);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB1)), 6, 0x1A);
    }
    if (((TWindowSubSymbolChat *)(((TWindowSubSymbolChat *)window_sub_symbol_chat)->m_28))->is_initialized() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB2)), 6, 0x1C);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xB2), 6, 0x1C);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 TWindowSubSymbolChat::create_parts_set() {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0x98);
    if (var_r31 != 0) {
        var_r31 = TWindowSubSymbolChatPartsSet__ct(var_r31, get_window_layout_position(0x7D), this->m_1e, &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
    }
    return var_r31;
}

s32 TWindowSubSymbolChat::create_parts() {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0x90);
    if (var_r31 != 0) {
        var_r31 = TWindowSubSymbolChatParts__ct(var_r31, get_window_layout_position(0x7D), &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
    }
    return var_r31;
}

void TWindowSubSymbolChat::open_menu(s32 arg0, s32 arg1) {
    ((TWindowSubComCardList *)arg1)->reset_entries();
    if (refresh_parts__20TWindowSubSymbolChatFv() > 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)arg1, (int)(get_message_10__20TWindowSubStatusDispFl(0xAE)), 6, 0xC);
    } else {
        TWindowSubComCard::draw_text_gray(arg1, get_message_10__20TWindowSubStatusDispFl(0xAE), 6, 0xC);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)arg1, (int)(get_message_10__20TWindowSubStatusDispFl(0xAF)), 6, 0x10);
    ((TWindowSubComCardList *)arg1)->set_flag70_bit10();
    ((TWindowSubComCardList *)arg1)->set_scroll_target(193.0f, 127.0f);
    align_menu_entry_positions(arg1);
}
s32 TWindowSubSymbolChat__sub_8028233C(s32 arg0) {
    s32 r = draw_card_icon__17TWindowSubComCardFll((s32)(get_window_layout_position(0x79)), 6, (s32)(get_message_10__20TWindowSubStatusDispFl(0xA9)));
    TWindowSubSymbolChat::open_menu(arg0, r);
    return r;
}

struct RecoveredGlobal_8028379C_lbl_804FF968 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_8028351C___vt__20TWindowSubSymbolChat { s32 value; u8 remaining[0x14]; };

struct Win_80282600 { u8 pad[0x20]; s32 sel; };

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

extern "C" {
extern RecoveredGlobal_8028379C_lbl_804FF968 symbol_chat_receive_buffer;
s32 __dt__7TObjectFv(void *, int);
s32 queue_destruction__7TObjectFv(int);
s32 __dl__7TObjectFPv(void *);
s32 update_selected_item__17TWindowOptionCtrlFv(int);
s32 TWindowCtrlMain__sub_8024CE58();
extern s32 __vt__20TWindowSubSymbolChat[];
extern void *TWindowSubSymbolChat__instance;
s32 __nw__7TObjectFUl(int);
s32 get_window_layout_position(s32);
extern s32 lbl_8044FB20[];
s32 get_symbol_chat_data__20TWindowSubSymbolChatFv(s32);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 align_menu_entry_positions(s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 draw_card_icon__17TWindowSubComCardFll(s32, s32, s32);

s32 refresh_parts__20TWindowSubSymbolChatFv();
s32 play_symbol_sound__20TWindowSubSymbolChatFl();
void mem_free(void *p);
u32 create_menu__20TWindowSubSymbolChatFv(void *);
u32 create_parts__20TWindowSubSymbolChatFv(void *);
s32 TWindowSubSymbolChat__sub_80283944(int);
s32 fn_80285A28(int, void *);
extern s8 TWindowSubSymbolChat__data_805D6494;
extern s32 TWindowSubSymbolChat__data_805D6498;
extern s32 TWindowSubSymbolChat__data_805D649C;
extern s32 TWindowSubSymbolChat__help_window;
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
s32 __ct__7TObjectFP7TObject();
s8 get_global_4e54__20TWindowSubSymbolChatFv();
s32 update_display__20TWindowSubSymbolChatFl(s32 *);

s32 TWindowSubSymbolChat::open_edit_menu() {
    s32 temp_r31;

    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x79), 3, get_message_10__20TWindowSubStatusDispFl(0xA8));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB3)), 6, 8);
    if (((TWindowSubSymbolChat *)(this->m_28))->is_initialized() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB4)), 6, 0x1E);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xB4), 6, 0x1E);
    }
    if (get_global_4e54__20TWindowSubSymbolChatFv() > 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xB5)), 6, 0x20);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0xB5), 6, 0x20);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 TWindowSubSymbolChat::open_main_menu(void * _w0) {
    s32 temp_r31;

    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x78), 6, get_message_10__20TWindowSubStatusDispFl(0x1D));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xA8)), 6, 6);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xA9)), 6, 0xA);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xAA)), 6, 0x14);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xAB)), 6, 0x22);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xAC)), 6, 0x26);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0xAD)), 6, 0x28);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(193.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

void TWindowSubSymbolChat::apply_symbol() {
    TWindowSubComCard__sub_80265680((u8 *)this->m_38, (s16) this->m_20);
}

s32 TWindowSubSymbolChat::create_symbol_list_card() {
    Win_80282600 *arg0 = (Win_80282600 *)this;
    s32 i;
    s32 sym;
    s32 card;
    s32 data;
    card = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x77), 0xC, get_message_10__20TWindowSubStatusDispFl(0x31));
    for (i = 0; i < 0xC; i++) {
        sym = (s32)get_symbol_chat_preset(i);
        data = get_symbol_chat_data__20TWindowSubSymbolChatFv(sym);
        if (is_symbol_chat_preset_in_use((u32 *)sym) != 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)card, (int)data, 0x66, (int)i);
        } else {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)card, (int)data, 0x46, (int)i);
        }
    }
    ((TWindowSubComCardList *)card)->set_flag70_bit10();
    ((TWindowSubComCardList *)card)->set_scroll_target(2.2e+02f, 188.0f);
    align_menu_entry_positions(card);
    ((TWindowSubComCardList *)card)->set_selected_index(arg0->sel);
    return card;
}

s32 TWindowSubSymbolChat::create_chat_symbol_window(s32 arg0, s32 arg1) {
    s32 window_chat_symbol;
    window_chat_symbol = __nw__7TObjectFUl(0x68);
    if (window_chat_symbol != 0) {
        window_chat_symbol = (s32)TWindowChatSymbol__ct((TWindowChatSymbol *)((u8 *)window_chat_symbol), (((s32)get_window_layout_position(arg1 + 0x7B))), (s32)lbl_8044FB20);
    }
    return window_chat_symbol;
}

void TWindowSubSymbolChat::render() {  }

extern s32 close_child__20TWindowSubSymbolChatFv[];
extern s32 TWindowSubSymbolChat__class_name;

void TWindowSubSymbolChat::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3_2;
    u32 var_r0;
    u32 var_r0_2;
    u32 var_r0_3;
    u32 var_r0_4;
    u32 var_r30;
    u8 *temp_r5;
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->m_28 != 0U) {
            TWindowSubSymbolChat::clear_flag_bit2((s32 *)this->m_28);
            this->m_28 = 0U;
        }
        if ((u32) this->m_40 != 0U) {
            ((TWindowSubComCard *)(this->m_40))->close();
            this->m_40 = 0U;
        }
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
        if ((void *) this->m_30 == NULL) {
            *(u8 * *)&this->m_30 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((s32)arg0, 0));
        }
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->m_38 = ((u32)create_symbol_list_card());
        this->m_1c = 2U;
    case 2:
        ((TWindowSubSymbolChat *)(this->m_30))->set_from_key((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            ((VObj_18_204a81 *)(this->m_2c))->m7();
            this->m_1c = 0x2AU;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->m_20 = ((TWindowMenu *)this->m_38)->get_selected_value();
            ((TWindowSubSymbolChat *)(this->m_20))->update_symbol_chat_result();
            this->m_28 = TWindowSubSymbolChat::get_instance();
            ((TWindowSubSymbolChat *)(this->m_28))->update_selected_symbol();
            TWindowSubSymbolChat::set_flag_bit2((s32 *)this->m_28);
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->m_1c = 3U;
            return;
        }
        break;
    case 3:
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
    case 4:
        if ((u32) this->m_58 != 0U) {
            queue_destruction__7TObjectFv(this->m_58);
            this->m_58 = 0U;
        }
        if ((u32) this->m_44 != 0U) {
            ((TWindowBase *)this->m_44)->close();
            this->m_44 = 0U;
        }
        if ((u32) this->m_40 != 0U) {
            ((TWindowSubComCard *)(this->m_40))->close();
            this->m_40 = 0U;
        }
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->m_4c != 0U) {
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        if ((u32) this->m_48 != 0U) {
            ((TWindowBase *)this->m_48)->close();
            this->m_48 = 0U;
        }
        if ((void *) this->m_34 != NULL) {
            ((TWindowBase *)this->m_34)->close();
            this->m_34 = NULL;
        }
        if ((u32) this->m_38 != 0U) {
            ((TWindowBase *)this->m_38)->close();
            this->m_38 = 0U;
        }
        if ((void *) this->m_30 == NULL) {
            *(u8 * *)&this->m_30 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((s32)arg0, 0));
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->set_selection(this->m_28);
        }
        temp_r5 = (u8 *)this->m_30;
        ((TWindowSubSymbolChatPartsSet *)(this->m_30 + 0x30))->copy_vec2((void*)((s32)get_window_layout_position(0x7B)));
        *(s32 *)(this->m_30 + 0x50) = 6;
        if ((u32) this->m_3c == 0U) {
            this->m_3c = ((u32)TWindowSubSymbolChat::open_main_menu(arg0));
        }
        ((TWindowSubComCard *)(this->m_3c))->clear_flag_and_release();
        ((TWindowSubComCard *)(this->m_3c))->clear_transition_flag();
        this->m_1c = 5U;
    case 5:
        if (((TWindowMenu *)(this->m_3c))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_3c))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_3c)->get_selected_value();
            return;
        }
        break;
    case 6:
        ((TWindowOptionCtrl *)(this->m_3c))->open();
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->m_48 != 0U) {
            ((TWindowBase *)this->m_48)->close();
            this->m_48 = 0U;
        }
        if ((u32) this->m_38 == 0U) {
            this->m_38 = ((u32)open_edit_menu());
        }
        ((TWindowSubComCard *)(this->m_38))->clear_flag_and_release();
        this->m_1c = 7U;
    case 7:
        ((TWindowSubSymbolChat *)arg0)->update_sub_window();
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_38)->get_selected_value();
            return;
        }
        break;
    case 8:
        if ((u32) this->m_48 == 0U) {
            var_r30 = ((u32)__nw__7TObjectFUl(0x6C));
            if (var_r30 != 0U) {
                var_r30 = (u32)TWindowSubSymbolChatFaceType__ct((TWindowSubSymbolChatFaceType *)((u8 *)var_r30), (s32)(((s32)get_window_layout_position(0x7D))), (s32)((s32)&TWindowSubSymbolChat__data_805D6494));
            }
            this->m_48 = var_r30;
        }
        if ((u32) this->m_54 == 0U) {
            var_r0 = ((u32)__nw__7TObjectFUl(0x74));
            if (var_r0 != 0U) {
                var_r0 = (u32)TWindowSubSymbolChatHelp__ct((TWindowSubSymbolChatHelp *)((u8 *)var_r0), (s32)&TWindowSubSymbolChat__data_805D6494, (s32)&TWindowSubSymbolChat__help_window);
            }
            this->m_54 = var_r0;
        }
        ((TWindowSubSymbolChat *)(this->m_54))->set_flag60_bit2();
        this->m_1c = 9U;
    case 9:
        if (TWindowSubSymbolChat__sub_80283998((void *)this->m_48) != 0) {
            this->m_1c = 6U;
            return;
        }
        if (((TWindowSubSymbolChatFaceType *)(this->m_48))->is_open() != 0) {
            ((TWindowSubSymbolChat *)(this->m_28))->set_symbol_flags((int) (fn_802839A4((void *)this->m_48)), (int)TWindowSubSymbolChat__data_805D6494);
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->m_1c = 4U;
            return;
        }
        break;
    case 10:
        if ((u32) this->m_50 != 0U) {
            ((TWindowBase *)this->m_50)->close();
            this->m_50 = 0U;
        }
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->m_4c != 0U) {
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        ((TWindowOptionCtrl *)(this->m_3c))->open();
        if ((u32) this->m_38 == 0U) {
            this->m_38 = TWindowSubSymbolChat__sub_8028233C((s32)arg0);
        }
        ((TWindowSubComCard *)(this->m_38))->clear_flag_and_release();
        this->m_1c = 0xBU;
    case 11:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->m_1e = 0;
            this->m_1c = ((TWindowMenu *)this->m_38)->get_selected_value();
            return;
        }
        break;
    case 12:
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->m_50 != 0U) {
            ((TWindowBase *)this->m_50)->close();
            this->m_50 = 0U;
        }
        if ((u32) this->m_4c == 0U) {
            this->m_4c = create_parts__20TWindowSubSymbolChatFv(arg0);
            fn_80285A28(this->m_4c, &TWindowSubSymbolChat__help_window);
        }
        ((TWindowSubSymbolChat *)(this->m_4c))->select_index_and_scroll(this->m_1e);
        if ((u32) this->m_54 == 0U) {
            var_r0_2 = ((u32)__nw__7TObjectFUl(0x74));
            if (var_r0_2 != 0U) {
                var_r0_2 = (u32)TWindowSubSymbolChatHelp__ct((TWindowSubSymbolChatHelp *)((u8 *)var_r0_2), (s32)&TWindowSubSymbolChat__data_805D6494, (s32)&TWindowSubSymbolChat__help_window);
            }
            this->m_54 = var_r0_2;
        }
        if (refresh_parts__20TWindowSubSymbolChatFv() > 1) {
            ((TWindowSubSymbolChat *)(this->m_54))->set_flag60_bit1();
        } else {
            TWindowSubSymbolChat__sub_80283944(this->m_54);
        }
        ((TWindowSubSymbolChat *)(this->m_54))->set_pos_and_flag((s32)&TWindowSubSymbolChat__data_805D6498, (s32)&TWindowSubSymbolChat__data_805D649C);
        this->m_1c = 0xDU;
    case 13:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->m_4c) != 0) {
            this->m_1c = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->m_4c))->sub_80283974() != 0) {
            this->m_1c = 0xEU;
            return;
        }
        break;
    case 14:
        if ((u32) this->m_4c != 0U) {
            this->m_1e = ((TWindowSubSymbolChatParts *)(this->m_4c))->calc_symbol_index();
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        if ((u32) this->m_50 == 0U) {
            this->m_50 = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
            ((TWindowSubSymbolChat *)(this->m_50))->init_symbol_layout(&TWindowSubSymbolChat__help_window);
        }
        this->m_1c = 0xFU;
    case 15:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->m_50) != 0) {
            this->m_1c = 0xCU;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->m_50))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->sub_80281CC4();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            if (refresh_parts__20TWindowSubSymbolChatFv() > 0) {
                this->m_1c = 0xCU;
                return;
            }
            TWindowSubSymbolChat::open_menu((s32)arg0, (s32)this->m_38);
            this->m_1c = 0xAU;
            return;
        }
        break;
    case 16:
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->m_50 != 0U) {
            ((TWindowBase *)this->m_50)->close();
            this->m_50 = 0U;
        }
        if ((u32) this->m_4c == 0U) {
            this->m_4c = create_parts__20TWindowSubSymbolChatFv(arg0);
            ((TWindowSubSymbolChat *)(this->m_4c))->open((s32)&TWindowSubSymbolChat__data_805D6494);
        }
        ((TWindowSubSymbolChat *)(this->m_4c))->select_index_and_scroll(this->m_1e);
        if ((u32) this->m_54 == 0U) {
            var_r0_3 = ((u32)__nw__7TObjectFUl(0x74));
            if (var_r0_3 != 0U) {
                var_r0_3 = (u32)TWindowSubSymbolChatHelp__ct((TWindowSubSymbolChatHelp *)((u8 *)var_r0_3), (s32)&TWindowSubSymbolChat__data_805D6494, (s32)&TWindowSubSymbolChat__help_window);
            }
            this->m_54 = var_r0_3;
        }
        ((TWindowSubSymbolChat *)(this->m_54))->set_flag60_bit2();
        ((TWindowSubSymbolChat *)(this->m_54))->set_pos_and_flag((s32)&TWindowSubSymbolChat__data_805D6498, (s32)&TWindowSubSymbolChat__data_805D649C);
        this->m_1c = 0x11U;
    case 17:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->m_4c) != 0) {
            this->m_1c = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->m_4c))->sub_80283974() != 0) {
            this->m_1c = 0x12U;
            return;
        }
        break;
    case 18:
        if ((u32) this->m_4c != 0U) {
            this->m_1e = ((TWindowSubSymbolChatParts *)(this->m_4c))->calc_symbol_index();
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        if ((u32) this->m_50 == 0U) {
            this->m_50 = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
            ((TWindowSubSymbolChat *)(this->m_50))->set_selection_and_refresh((s32)&TWindowSubSymbolChat__data_805D6494);
        }
        this->m_1c = 0x13U;
    case 19:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->m_50) != 0) {
            this->m_1c = 0x10U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->m_50))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->sub_80281C60();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->m_1c = 0x10U;
            return;
        }
        break;
    case 20:
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->m_4c != 0U) {
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        ((TWindowOptionCtrl *)(this->m_3c))->open();
        if ((u32) this->m_38 == 0U) {
            this->m_38 = create_menu__20TWindowSubSymbolChatFPv((arg0));
        }
        ((TWindowSubComCard *)(this->m_38))->clear_flag_and_release();
        this->m_1c = 0x15U;
    case 21:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->m_1e = 0;
            this->m_1c = ((TWindowMenu *)this->m_38)->get_selected_value();
            return;
        }
        break;
    case 22:
    case 26:
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->m_50 != 0U) {
            ((TWindowBase *)this->m_50)->close();
            this->m_50 = 0U;
        }
        if ((u32) this->m_4c == 0U) {
            this->m_4c = create_parts__20TWindowSubSymbolChatFv(arg0);
            ((TWindowSubSymbolChat *)(this->m_4c))->update_height();
        }
        ((TWindowSubSymbolChat *)(this->m_4c))->select_index_and_scroll(this->m_1e);
        if ((u32) this->m_54 == 0U) {
            var_r0_4 = ((u32)__nw__7TObjectFUl(0x74));
            if (var_r0_4 != 0U) {
                var_r0_4 = (u32)TWindowSubSymbolChatHelp__ct((TWindowSubSymbolChatHelp *)((u8 *)var_r0_4), (s32)&TWindowSubSymbolChat__data_805D6494, (s32)&TWindowSubSymbolChat__help_window);
            }
            this->m_54 = var_r0_4;
        }
        ((TWindowSubSymbolChat *)(this->m_54))->clear_flag60_bit4();
        ((TWindowSubSymbolChat *)(this->m_54))->clear_flag60_bit2();
        TWindowSubSymbolChat__sub_80283944(this->m_54);
        this->m_1c = 0x17U;
    case 23:
    case 27:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->m_4c) != 0) {
            this->m_1c = 0x14U;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->m_4c))->sub_80283974() != 0) {
            ((TWindowSubSymbolChat *)arg0)->update_state();
            return;
        }
        break;
    case 24:
        if ((u32) this->m_4c != 0U) {
            this->m_1e = ((TWindowSubSymbolChatParts *)(this->m_4c))->calc_symbol_index();
            ((TWindowBase *)this->m_4c)->close();
            this->m_4c = 0U;
        }
        if ((u32) this->m_50 == 0U) {
            this->m_50 = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
        }
        if (((TWindowSubSymbolChat *)(this->m_50))->select_symbol_chat_record(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window) != 0) {
            ((TWindowSubSymbolChat *)(this->m_54))->set_flag60_bit2();
        } else if (refresh_parts__20TWindowSubSymbolChatFv() > 0) {
            ((TWindowSubSymbolChat *)(this->m_54))->set_flag60_bit1();
        }
        ((TWindowSubSymbolChat *)(this->m_54))->set_pos_and_flag((s32)&TWindowSubSymbolChat__data_805D6498, (s32)&TWindowSubSymbolChat__data_805D649C);
        this->m_1c = 0x19U;
    case 25:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->m_50) != 0) {
            this->m_1c = 0x16U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->m_50))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->draw_selected_entry();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->m_1c = 0x16U;
            return;
        }
        break;
    case 28:
        this->m_1c = 0x1DU;
    case 29:
        ((TWindowSubSymbolChat *)(this->m_28))->clear_entries();
        TWindowSubSymbolChat::set_flag_bit2((s32 *)this->m_28);
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->m_1c = 4U;
        return;
    case 30:
        if ((u32) this->m_38 != 0U) {
            ((TWindowBase *)this->m_38)->close();
            this->m_38 = 0U;
        }
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
        if ((void *) this->m_34 == NULL) {
            *(u8 * *)&this->m_34 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((s32)arg0, 1));
        }
        *(s32 *)(this->m_34 + 0x64) = 1;
        this->m_38 = ((u32)create_symbol_list_card());
        apply_symbol();
        this->m_1c = 0x1FU;
    case 31:
        ((TWindowSubSymbolChat *)(this->m_34))->set_from_key((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            ((TWindowSubSymbolChat *)((int) get_symbol_chat_preset(((TWindowMenu *)this->m_38)->get_selected_value())))->commit((s32 *)this->m_28);
            this->m_1c = 4U;
            return;
        }
        break;
    case 32:
        this->m_1c = 0x21U;
    case 33:
        ((TWindowSubSymbolChat *)(this->m_28))->commit((s32 *)((s32)TWindowSubSymbolChat__sub_8028379C()));
        TWindowSubSymbolChat::set_flag_bit1((s32 *)this->m_28);
        TWindowSubSymbolChat::set_flag_bit2((s32 *)this->m_28);
        ((TWindowSubSymbolChat *)(this->m_28))->set_entry_name((void *)(get_message_10__20TWindowSubStatusDispFl(0xB5)));
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->m_1c = 4U;
        return;
    case 34:
        ((TWindowOptionCtrl *)(this->m_3c))->open();
        if ((u32) this->m_40 != 0U) {
            ((TWindowSubComCard *)(this->m_40))->close();
            this->m_40 = 0U;
        }
        if ((u32) this->m_38 == 0U) {
            this->m_38 = create_menu__20TWindowSubSymbolChatFv(arg0);
        }
        ((TWindowSubComCard *)(this->m_38))->clear_flag_and_release();
        this->m_1c = 0x23U;
    case 35:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            ((TWindowMenu *)this->m_38)->get_selected_value();
            play_symbol_sound__20TWindowSubSymbolChatFl();
            this->m_1c = 0x24U;
            return;
        }
        break;
    case 36:
        this->m_40 = ((TWindowSubSymbolChat *)arg0)->open_confirm_prompt();
        this->m_1c = 0x25U;
    case 37:
        if (((TWindowSubComCard *)(this->m_40))->get_card_data() != 0) {
            this->m_1c = 0x22U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_40))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_40))->get_slot_or_neg1() == 0) {
                ((TWindowSubSymbolChat *)(this->m_28))->set_symbol_index((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
                this->m_1c = 4U;
                return;
            }
            this->m_1c = 0x22U;
            return;
        }
        break;
    case 38:
        ((TWindowOptionCtrl *)(this->m_3c))->open();
        if ((u32) this->m_44 == 0U) {
            this->m_44 = ((TWindowSubSymbolChat *)arg0)->create_confirm_window();
        }
        this->m_1c = 0x27U;
    case 39:
        if (((TWindowMenuIconLine *)(this->m_44))->is_cancelled() != 0) {
            ((TWindowSubSymbolChat *)(this->m_28))->set_flag_bit9((int) (update_selected_item__17TWindowOptionCtrlFv(this->m_44)));
            this->m_1c = 4U;
            return;
        }
        break;
    case 40:
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
        if ((void *) this->m_30 != NULL) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = NULL;
        }
        this->m_58 = ((TWindowSubSymbolChat *)arg0)->create_keyboard_control();
        this->m_1c = 0x29U;
    case 41:
        if (((TWindowSubComCard *)(this->m_58))->is_keyboard_active() != 0) {
            this->m_1c = 4U;
            return;
        }
        if (((TWindowSubComCard *)(this->m_58))->update_keyboard() != 0) {
            temp_r3_2 = ((TWindowSubComCard *)(this->m_58))->realloc_buffer();
            ((TWindowSubSymbolChat *)(this->m_28))->set_entry_name((void *)temp_r3_2);
            mem_free((void *)temp_r3_2);
            this->m_1c = 4U;
        }
        break;
    case 42:
        break;
    }
}

u8 *__dt__20TWindowSubSymbolChatFv(TWindowSubSymbolChat *arg0, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_10;
    u32 temp_r3_11;
    u32 temp_r3_12;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 temp_r3_6;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u32 temp_r3_9;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8028351C___vt__20TWindowSubSymbolChat *)&__vt__20TWindowSubSymbolChat).value;
        temp_r3 = arg0->m_58;
        if (temp_r3 != 0U) {
            queue_destruction__7TObjectFv(temp_r3);
            arg0->m_58 = 0U;
        }
        if ((u32) arg0->m_44 != 0U) {
            if ((TWindowCtrlMain__sub_8024CE58() != 0) && ((u8) arg0->m_1c == 0x27)) {
                ((TWindowSubSymbolChat *)(arg0->m_28))->set_flag_bit9((int) (update_selected_item__17TWindowOptionCtrlFv(arg0->m_44)));
            }
            ((TWindowBase *)arg0->m_44)->close();
            arg0->m_44 = 0U;
        }
        temp_r3_2 = arg0->m_40;
        if (temp_r3_2 != 0U) {
            ((TWindowSubComCard *)temp_r3_2)->close();
            arg0->m_40 = 0U;
        }
        temp_r3_3 = arg0->m_54;
        if (temp_r3_3 != 0U) {
            ((TWindowBase *)temp_r3_3)->close();
            arg0->m_54 = 0U;
        }
        temp_r3_4 = arg0->m_48;
        if (temp_r3_4 != 0U) {
            ((TWindowBase *)temp_r3_4)->close();
            arg0->m_48 = 0U;
        }
        temp_r3_5 = arg0->m_50;
        if (temp_r3_5 != 0U) {
            ((TWindowBase *)temp_r3_5)->close();
            arg0->m_50 = 0U;
        }
        temp_r3_6 = arg0->m_4c;
        if (temp_r3_6 != 0U) {
            ((TWindowBase *)temp_r3_6)->close();
            arg0->m_4c = 0U;
        }
        temp_r3_7 = arg0->m_3c;
        if (temp_r3_7 != 0U) {
            ((TWindowBase *)temp_r3_7)->close();
            arg0->m_3c = 0U;
        }
        temp_r3_8 = arg0->m_38;
        if (temp_r3_8 != 0U) {
            ((TWindowBase *)temp_r3_8)->close();
            arg0->m_38 = 0U;
        }
        temp_r3_9 = arg0->m_34;
        if (temp_r3_9 != 0U) {
            ((TWindowBase *)temp_r3_9)->close();
            arg0->m_34 = 0U;
        }
        temp_r3_10 = arg0->m_30;
        if (temp_r3_10 != 0U) {
            ((TWindowBase *)temp_r3_10)->close();
            arg0->m_30 = 0U;
        }
        temp_r3_11 = arg0->m_28;
        if (temp_r3_11 != 0U) {
            TWindowSubSymbolChat::clear_flag_bit2((s32 *)temp_r3_11);
            arg0->m_28 = 0U;
        }
        temp_r3_12 = arg0->m_5c;
        if (temp_r3_12 != 0U) {
            ((TWindowBase *)temp_r3_12)->close();
            arg0->m_5c = 0U;
        }
        (*(s32 *)&TWindowSubSymbolChat__instance) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}

void *TWindowSubSymbolChat__ct(TWindowSubSymbolChat *window_sub_symbol_chat, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_symbol_chat + 0x18) = __vt__20TWindowSubSymbolChat;
    *(s32 *)((s8 *)window_sub_symbol_chat + 0) = (s32) TWindowSubSymbolChat__class_name;
    window_sub_symbol_chat->m_2c = arg1;
    window_sub_symbol_chat->m_24 = arg2;
    window_sub_symbol_chat->m_30 = 0;
    window_sub_symbol_chat->m_34 = 0;
    window_sub_symbol_chat->m_38 = 0;
    window_sub_symbol_chat->m_3c = 0;
    window_sub_symbol_chat->m_48 = 0;
    window_sub_symbol_chat->m_4c = 0;
    window_sub_symbol_chat->m_50 = 0;
    window_sub_symbol_chat->m_54 = 0;
    window_sub_symbol_chat->m_40 = 0;
    window_sub_symbol_chat->m_44 = 0;
    window_sub_symbol_chat->m_58 = 0;
    window_sub_symbol_chat->m_28 = 0;
    TWindowSubSymbolChat__data_805D6494 = 0;
    TWindowSubSymbolChat__data_805D6498 = 0;
    TWindowSubSymbolChat__data_805D649C = 0;
    window_sub_symbol_chat->m_20 = 0;
    TWindowSubSymbolChat__instance = window_sub_symbol_chat;
    window_sub_symbol_chat->m_5c = update_display__20TWindowSubSymbolChatFl(close_child__20TWindowSubSymbolChatFv);
    window_sub_symbol_chat->m_1c = 0;
    return window_sub_symbol_chat;
}
typedef char RecoveredGlobal_8028379C_lbl_804FF968_size[sizeof(RecoveredGlobal_8028379C_lbl_804FF968) == 0x58 ? 1 : -1];
s32 *TWindowSubSymbolChat__sub_8028379C(void) {
    return &symbol_chat_receive_buffer.value;
}

}
