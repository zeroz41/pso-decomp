#pragma push

#include "types.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/map/CurrentArea.h"
class TChCrTagPlBack;
#include "pso/misc/TWindowComCard.h"
#include "pso/TProtocol.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TUnk_804D0658.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/ShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TPlyGuildCardTag_8007B7EC.h"

struct Ent_80272034 { u16 a; u16 b; u8 rest[0x1c]; };

struct Tbl_80272034 { u8 pad0; u8 count; u8 pad2[2]; Ent_80272034 e[1]; };

struct Win_80272034 { u8 pad[0x58]; Tbl_80272034 *tbl; };

struct Key_80272034 { u32 a; u32 b; };

struct Ent_80271F04 {
    u32 id;
    u32 value;
};

extern "C" {
u8 *get_shared_text_buffer(void);
void mem_free(void *p);
void send_simple_mail__6TLobbyFiPv(s32 arg0, void *arg1);
}
s32 *get_selected_guild_card_record(void);
extern "C" {
void set_value_by_key(void *, u16, s32);
s32 open_hard_keyboard__6TLobbyFPv(void *);
void *get_field_20__17TWindowSubComCardFv(void *);
void *get_selected_entry__11TWindowMenuFv(void *);
void get_message_10__17TWindowSubComCardFPvPv(void* p, void* a1);
void apply_selection__17TWindowSubComCardFi(s32 arg0);
void cleanup__17TWindowSubComCardFPv(void* p);
void init_layout__17TWindowSubComCardFv(void);
void send_cmd_133__17TWindowSubComCardFv(void);
void send_command__17TWindowSubComCardFi(s32 arg0);
int send_find_user_self_tag__6TLobbyFi(void);
s32 get_card_entry_data__17TWindowSubComCardFv(s32);
int get_card_entry__17TWindowSubComCardFi(void);
int get_selected_menu_value(void*);
s32 get_window_layout_position(s32 a0 = 0);
int fn_802754EC(void);
int get_card_id__17TWindowSubComCardFv(void);
int get_message_10__20TWindowSubStatusDispFl(void*);

void TWindowSubComCard::handle_close_flag() {
    if (this->m_1d & 2) {
        TLobby::send_status_packet();
        this->m_1d = (u8) (this->m_1d & 0xFFFFFFFD);
    }
}

void TWindowSubComCard::send_state_if_dirty() {
    if (this->m_1d & 1) {
        TLobby::send_card_window_state();
        this->m_1d = (s8) (this->m_1d & ~1);
    }
}

typedef void *(*GetMsg_80271F04)(void *, void *);
void TWindowSubComCard::sub_80271F04(void *arr, s32 key, s32 arg3) {
    s32 i;
    if (key == 0) {
        if (arg3 != open_hard_keyboard__6TLobbyFPv(*(void **)(((u8 *)this) + 0x20))) {
            ((u8 *)this)[0x1D] |= 1;
            ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x20)))->set_com_param(arg3);
            ((TWindowMakeTeam *)(*(void **)(((u8 *)this) + 0x7C)))->set_entry_string_by_id(((GetMsg_80271F04)get_message_10__17TWindowSubComCardFPvPv)(this, (void *)arg3), 0);
            if (arg3 != 0) {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x7C)))->disable_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            } else {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x7C)))->mark_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            }
        }
    } else if (arg3 != ((TWindowSubComCard *)((Ent_80271F04 *)arr))->find_value_by_key(key)) {
        ((u8 *)this)[0x1D] |= 1;
        set_value_by_key(((Ent_80271F04 *)arr), key, arg3);
        ((TWindowMakeTeam *)(*(void **)(((u8 *)this) + 0x7C)))->set_entry_string_by_id(get_field_20__17TWindowSubComCardFv(get_selected_entry__11TWindowMenuFv(*(void **)(((u8 *)this) + 0x64))), key);
    }
}

u8 *TWindowSubComCard::find_entry_rest(void *arg1_arg, s32 arg2) {
    Key_80272034 *arg1 = (Key_80272034 *)arg1_arg;
    Tbl_80272034 *t = ((Win_80272034 *)this)->tbl;
    Ent_80272034 *e;
    Key_80272034 *k;
    s32 i;
    k = arg1 + arg2;
    e = t->e;
    for (i = 0; i < t->count; i++, e++) {
        if (e->a == k->a && e->b == k->b) return e->rest;
    }
    return 0;
}

void get_message_10__17TWindowSubComCardFPvPv(void* p, void* a1) { get_message_10__20TWindowSubStatusDispFl((char*)a1 + 0xa6); }
void apply_selection__17TWindowSubComCardFi(s32 arg0) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowComCard::create_for_card(get_window_layout_position(0x92), arg0, card_slot);
}
void send_command__17TWindowSubComCardFi(s32 arg0) {
    TWindowComCard::create((void *)(get_window_layout_position(0x86)), (void *)arg0);
}
void init_layout__17TWindowSubComCardFv(void) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard::create_card_list(get_window_layout_position(0x91), card_slot, 0x1C, 1);
}
void send_cmd_133__17TWindowSubComCardFv(void) { get_window_layout_position(133); fn_802754EC(); }
void cleanup__17TWindowSubComCardFPv(void* p) { get_selected_menu_value(*(void**)((char*)p + 0x84)); get_card_entry__17TWindowSubComCardFi(); get_card_id__17TWindowSubComCardFv(); send_find_user_self_tag__6TLobbyFi(); }
#pragma scheduling off
void TWindowSubComCard::sub_802721D8() {
  u8 *new_var;
  s32 temp_r30;
  u8 *lobby;
  u8 *temp_r31;
  temp_r30 = ((TWindowSubComCard *)(*((u8 **) (((s8 *) ((u8 *)this)) + 0x80))))->realloc_buffer();
  lobby = (u8 *) ((u8* (*)(void))get_selected_guild_card_record)();
  TWindowSubComCard::mask_profanity_words((char *)temp_r30, (char *)get_shared_text_buffer());
  new_var = get_shared_text_buffer();
  temp_r31 = (u8 *) new_var;
  send_simple_mail__6TLobbyFiPv(((TLobby *)lobby)->get_id(), temp_r31);
  mem_free((void *)temp_r30);
}
}

#pragma pop

struct RecoveredGlobal_8034CC68_lbl_80478C3C {
    s32 value;
    u8 remaining[0x8];
};

struct Rec_80272290 { s32 f0; u8 f4[0xD0]; };

extern const RecoveredGlobal_8034CC68_lbl_80478C3C com_card_help_message_id_table;
extern "C" {
Rec_80272290 *get_com_count__17TWindowSubComCardFv();
void text_builder_append(u8 *str);
}
void text_builder_reset();
extern "C" {
void load_selected_guild_card_record(int, int);
void* TWindowSubComCard__sub_8027523C(void* p);
extern u8 lbl_805DD4F8;

void TWindowSubComCard::set_card_index(s32 arg1) {
    if ((s32) this->m_28 != arg1) {
        this->m_28 = arg1;
        ((TLobby *)(this->m_6c))->send_and_handle(get_card_entry_data__17TWindowSubComCardFv(arg1), 0x82);
    }
}
typedef char RecoveredGlobal_8034CC68_lbl_80478C3C_size[sizeof(RecoveredGlobal_8034CC68_lbl_80478C3C) == 0xC ? 1 : -1];

void TWindowSubComCard::set_selected_card(s32 arg1) {
    u8 *temp_r31;
    s32 temp_r30;
    Rec_80272290 *cnt;
    if (*(s32 *)&this->m_28 != arg1) {
        *(s32 *)&this->m_28 = arg1;
        cnt = get_com_count__17TWindowSubComCardFv();
        temp_r31 = cnt[arg1].f4;
        load_selected_guild_card_record((int)temp_r31, arg1 * 0xD4);
        temp_r30 = ((s32 (*)(void))get_selected_guild_card_record)();
        text_builder_reset();
        text_builder_append((temp_r31 + 0x14));
        text_builder_append((u8 *)(((TWindowSubComCard *)temp_r30)->get_name()));
        text_builder_append(&lbl_805DD4F8);
        text_builder_append((u8 *)(((void* (*)(int))TWindowSubComCard__sub_8027523C)(temp_r30)));
        text_builder_append(&lbl_805DD4F8);
        text_builder_append((u8 *)(((TWindowSubComCard *)temp_r30)->get_card_data_ptr()));
        ((TLobby *)(*(s32 *)&this->m_6c))->send_and_handle(((s32 (*)(void))get_shared_text_buffer)(), 0x82);
    }
}

void TWindowSubComCard::set_help_message(s32 arg1) {
    if ((s32) this->m_28 != arg1) {
        this->m_28 = arg1;
        ((TLobby *)(this->m_6c))->send_and_handle((s32)((s32)(((s32)get_message_10__20TWindowSubStatusDispFl((void*)((int) (*(s32 *)((s8 *)&com_card_help_message_id_table.value + (arg1 * 4)))))))), 0x80);
    }
}

void update_selection__17TWindowSubComCardFUiUiPvi(u32 arg0, u32 arg1, s32 *arg2, s32 arg3);
void TWindowComCard__sub_80249920(s32 arg0, s32 arg1, s32 arg2);

void update_selection__17TWindowSubComCardFUiUiPvi(u32 arg0, u32 arg1, s32 *arg2, s32 arg3) {
    s32 temp_r3;

    if ((arg0 != 0U) && (arg1 != 0U)) {
        temp_r3 = ((s32 (*)(void))get_selected_menu_value)();
        if (temp_r3 != (s32) *arg2) {
            *arg2 = temp_r3;
            TWindowComCard__sub_80249920(arg1, temp_r3, arg3);
        }
    }
}
}

#pragma push

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

struct VBase_18_80272714 { char pad[0x18]; };

struct VObj_18_80272714 : VBase_18_80272714 {
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
    virtual void *m10();
};

extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 draw_card_icon__17TWindowSubComCardFll(int, int, void *);
extern const f32 lbl_805DD508;
s32 align_menu_entry_positions(s32);
extern const f32 lbl_805DD510;
s32 create_menu_window__17TWindowSubComCardFv(void);
s32 set_window_mode_4__6TLobbyFPvll(s32, s32 *, s32);
extern char lbl_8044F6C4[];
void open_mode4_window__17TWindowSubComCardFv(void);
extern char lbl_8044F6AC[];
void open_layout_window__17TWindowSubComCardFv(void);
s32 TWindowSubComCard__sub_80273004(void);
s32 get_character_save_record(u32 arg0);
s32 create_choice_setting_window__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2);
void create_sub_window__20TWindowChoiceSettingFPvi(void *arg0, s32 arg1);
extern u8 lbl_8044F6BC[];
s32 init_card__17TWindowSubComCardFv();
extern const f32 lbl_805DD50C;
s32 TWindowSubComCard__sub_802728CC(void);
ChrSel_80272B60 *get_chr_select__17TWindowSubComCardFv();
void *find_entry_value_by_id__17TWindowSubComCardFl(s32, s32);
extern const f32 TWindowSubComCard__data_805DD514;
extern const f32 lbl_805DD518;
s32 obj_isState3_324__9TObjCharaFv(void *);
s32 is_script_controlled__10TObjPlayerFv(void *);
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
extern const f32 TWindowSubComCard__data_805DD500;
extern const f32 lbl_805DD504;
s32 create_player_select_window__17TWindowSubComCardFv(void);
void *get_com_card_entry__6TLobbyFi(int a0);
s32 TLobby__sub_802428F8(void *p);
int get_com_card_data__6TLobbyFv(void);
extern const f32 lbl_805DD51C;
void rebuild_com_card_list__17TWindowSubComCardFii(s32 arg0, s32 arg1);
s32 create__17TWindowSubComCardFv(void);
s32 create_keyboard__17TWindowSubComCardFi(s32 arg0);
s32 create_keyboard__17TWindowSubComCardFii(s32 arg0, s32 arg1);
void update_display_value__17TWindowSubComCardFUiUiPv(u32 arg0, u32 arg1, s32 *arg2);
void update_selection__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2);
s32 TKeyBoardControl__ct(s32, s32, s32, s32, s32, s32);
s32 __nw__7TObjectFUl(s32);
s32 get_kbd_ptr__14TWindowComCardFv(s32);
s32 get_keyboard_field_6c__15TWindowMakeTeamFv(s32, s32);
s32 set_field_1c__6TLobbyFf(f32);

void update_selection__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    ((s32 (*)(s32, s32, s32, s32))update_selection__17TWindowSubComCardFUiUiPvi)(arg0, arg1, arg2, tmp);
}

void update_display_value__17TWindowSubComCardFUiUiPv(u32 arg0, u32 arg1, s32 *arg2) {
    s32 temp_r31;
    s32 temp_r3;

    temp_r31 = ((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0);
    if ((arg0 != 0U) && (arg1 != 0U)) {
        temp_r3 = ((s32 (*)(u32))get_selected_menu_value)(arg0);
        if (temp_r3 != (s32) *arg2) {
            *arg2 = temp_r3;
            ((TWindowComCard *)arg1)->set_display_value(temp_r3, temp_r31);
        }
    }
}

s32 create_keyboard__17TWindowSubComCardFii(s32 arg0, s32 arg1) {
    s32 keyboard;

    keyboard = __nw__7TObjectFUl(0x2C);
    if (keyboard != 0) {
        keyboard = TKeyBoardControl__ct(keyboard, arg0, 0xC6, 3, 4, local_client_id);
    }
    get_keyboard_field_6c__15TWindowMakeTeamFv(keyboard, get_card_entry_data__17TWindowSubComCardFv(arg1));
    ((TWindowMakeTeam *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TWindowMakeTeam *)keyboard)->set_keyboard_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

s32 create_keyboard__17TWindowSubComCardFi(s32 arg0) {
    s32 keyboard;
    s32 keyboard_mode;

    keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    keyboard = __nw__7TObjectFUl(0x2C);
    if (keyboard != 0) {
        keyboard = TKeyBoardControl__ct(keyboard, arg0, 0xC6, 3, 4, local_client_id);
    }
    get_keyboard_field_6c__15TWindowMakeTeamFv(keyboard, get_kbd_ptr__14TWindowComCardFv(keyboard_mode));
    ((TWindowMakeTeam *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TWindowMakeTeam *)keyboard)->set_keyboard_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

extern s32 lbl_8044F6CC[];
extern f32 lbl_805DD4FC;

s32 create__17TWindowSubComCardFv(void) {
    s32 temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0x98);
    temp_r31 = set_window_mode_4__6TLobbyFPvll(window_layout_position, lbl_8044F6CC, 1);
    set_field_1c__6TLobbyFf(lbl_805DD4FC);
    return temp_r31;
}

u32 TWindowSubComCard__sub_80272640(void *) {
    s32 n;
    s32 i;
    void *e;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x95), 8, TWindowSubStatusDisp::get_message_10(0x2E));
    n = get_short_mail_ctrl__6TLobbyFv();
    for (i = n - 1; i >= 0; i--) {
        e = TLobby__sub_8022598C(i);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)fn_8007B83C(e), 7, get_lobby_id__6TLobbyFPv(e));
    }
    if (n <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD1), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(TWindowSubComCard__data_805DD500, lbl_805DD504);
    return w;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
s32 create_player_select_window__17TWindowSubComCardFv(void) {
    s32 i;
    VObj_18_80272714 *p;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x94), 0xC, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x2D));
    i = 0;
    do {
        if (i != local_client_id && (p = (VObj_18_80272714 *)get_player_by_client_id(i)) != NULL &&
            is_script_controlled__10TObjPlayerFv(p) == 0 && obj_isState3_324__9TObjCharaFv(p) == 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(p->m10()), 7, (int)i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(TWindowSubComCard__data_805DD500, lbl_805DD504);
    return w;
}
#pragma pop

s32 TWindowSubComCard::create_card_action_window() {
    s32 temp_r31;
    void *temp_r31_2;
    temp_r31 = draw_card_icon__17TWindowSubComCardFll(((s32)get_window_layout_position(0x93)), 3, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFD)), 6, 0x41);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFE)), 6, 0x45);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFF)), 6, 0x4A);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD508);
    return temp_r31;
}

s32 TWindowSubComCard__sub_802728CC(void) {
    void *msg;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x90), 2, msg = ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xF8));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFA)), 6, 0x3B);
    if (init_card__17TWindowSubComCardFv() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFB)), 6, 0x3F);
    } else {
        TWindowSubComCard::draw_text_gray(w, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFB), 6, 0x3F);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->update_layout_height(lbl_805DD50C);
    return w;
}

s32 create_menu_window__17TWindowSubComCardFv(void) {
  s32 temp_r31;
  s32 title;
  title = (0, ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x1D)));
  temp_r31 = draw_card_icon__17TWindowSubComCardFll((int)((s32)((int) get_window_layout_position(0x8f))), 2, (void *)((s32)((int) title)));
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((s32)((int) temp_r31)), (int)((s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x57)))), 6, 0x21);
  if (get_current_area() == 0xF)
  {
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((s32)((int) temp_r31)), (int)((s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x58)))), 6, 0x25);
  }
  else
  {
    TWindowSubComCard::draw_text_gray((s32)((int) temp_r31), (s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x58))), 6, 0x25);
  }
  ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
  title = temp_r31;
  ((TWindowSubComCardList *)title)->update_layout_height((f32) lbl_805DD510);
  align_menu_entry_positions((s32)((int) title));
  return title;
}
void open_mode4_window__17TWindowSubComCardFv(void) {
    set_window_mode_4__6TLobbyFPvll((s32)(get_window_layout_position(0x8f)), (s32 *)lbl_8044F6C4, 1);
}

struct ComCardRec_80272A98 { u32 id; char name[0xD0]; };

struct ComCardList_80272A98 { u8 pad0; u8 count; u8 pad2[2]; ComCardRec_80272A98 entries[1]; };

u32 TWindowSubComCard__sub_80272A98(void *) {
    s32 i;
    s32 count;
    s32 w;
    ComCardRec_80272A98 *e;
    ComCardList_80272A98 *l;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x8E), 0x20, TWindowSubStatusDisp::get_message_10(0x54));
    l = (ComCardList_80272A98 *)get_com_count__17TWindowSubComCardFv();
    count = l->count;
    e = l->entries;
    for (i = 0; i < count; i++, e++) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)e->name, 6, i);
    }
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(TWindowSubComCard__data_805DD500, TWindowSubComCard__data_805DD514);
    return w;
}

typedef void *(*GetMsg_80272CB0)(void *, void *);

#pragma push
#pragma opt_loop_invariants off
s32 TWindowSubComCard::create_option_list_window(s32 arg1, s32 key) {
    s32 i;
    s32 count;
    s32 idx;
    u16 val;
    u16 sel;
    s32 win;
    Entry_80272B60 *e;
    ChrSel_80272B60 *cs;
    win = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x8D), 0x20, find_entry_value_by_id__17TWindowSubComCardFl(this->m_7c, key));
    if (key == 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)(((u8* (*)(void*, void*))get_message_10__17TWindowSubComCardFPvPv)(this, (void *)(0))), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)(((u8* (*)(void*, void*))get_message_10__17TWindowSubComCardFPvPv)(this, (void *)(1))), 6, 1);
        ((TWindowSubComCardList *)win)->set_selected_index(open_hard_keyboard__6TLobbyFPv((void *)this->m_20));
    } else {
        sel = ((TWindowSubComCard *)arg1)->find_value_by_key(key);
        cs = get_chr_select__17TWindowSubComCardFv();
        count = cs->count;
        e = cs->e;
        idx = 0;
        i = 0;
        while (i < count) {
            if (e->id == key) {
                val = e->val;
                forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)e->name, 6, (int)val);
                if (sel == val) {
                    ((TWindowSubComCardList *)win)->set_selected_index(idx);
                }
                idx++;
            }
            i++;
            e++;
        }
    }
    ((TWindowSubComCardList *)win)->set_flag70_bit10();
    ((TWindowSubComCardList *)win)->set_scroll_target(lbl_805DD518, TWindowSubComCard__data_805DD514);
    align_menu_entry_positions(win);
    return win;
}
#pragma pop

s32 TWindowSubComCard::create_entry_list_window() {
    s32 i;
    u8 *card;
    u16 id;
    s32 n;
    s32 idx;
    s32 hard;
    s32 w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    card = (u8 *)get_character_save_record(0xFFFF);
    hard = open_hard_keyboard__6TLobbyFPv(*(void **)(((u8 *)this) + 0x20));
    w = create_choice_setting_window__17TWindowSubComCardFiii((s32)(get_window_layout_position(0x8C)), (s32)lbl_8044F6BC, 6);
    create_sub_window__20TWindowChoiceSettingFPvi((void *)w, (s32)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x6D)));
    ((TWindowSubComCard *)w)->update_next_entry((s32)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x6D)), (s32)(((GetMsg_80272CB0)get_message_10__17TWindowSubComCardFPvPv)(this, (void *)hard)), 0);
    l = *(List_80272CB0 **)(((u8 *)this) + 0x58);
    idx = -1;
    n = l->count;
    e = l->ents;
    for (i = 0; i < n; i++, e++) {
        if (e->type == 0) {
            idx++;
            if (e->id >= 500) {
                ((TWindowSubComCard *)w)->update_next_entry((s32)e->name, (s32)(this->find_entry_rest(card + 0x22EC, idx)), (s32)e->id);
                if (hard != 0) {
                    ((TWindowSubComCard *)w)->disable_entry_by_id(e->id);
                }
            }
        }
    }
    ((TWindowSubComCard *)w)->set_flag_10();
    return w;
}

extern u8 lbl_8044F6B4[];
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32);

#pragma push
#pragma opt_loop_invariants off
u32 TWindowSubComCard__sub_80272DE0(TWindowSubComCard *window_sub_com_card) {
    s32 i;
    s32 count;
    s32 idx;
    s32 w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    w = create_choice_setting_window__17TWindowSubComCardFiii((s32)(get_window_layout_position(0x8C)), (s32)lbl_8044F6B4, 6);
    create_sub_window__20TWindowChoiceSettingFPvi((void *)w, TQuestVmDownLoadServer__sub_8006EF6C(0x49));
    l = (List_80272CB0 *)window_sub_com_card->m_58;
    idx = 0;
    count = l->count;
    e = l->ents;
    for (i = 0; i < count; i++, e++) {
        if (e->type == 0) {
            ((TWindowSubComCard *)w)->update_next_entry((s32)e->name, (s32)window_sub_com_card->find_entry_rest(&window_sub_com_card->m_30, idx), (s32)e->id);
            idx++;
        }
    }
    ((TWindowSubStatusDisp *)w)->add_text_entry(TQuestVmDownLoadServer__sub_8006EF6C(0x4A), 0);
    ((TWindowSubComCard *)w)->set_flag_10();
    return w;
}
#pragma pop

void open_layout_window__17TWindowSubComCardFv(void) {
    set_window_mode_4__6TLobbyFPvll((s32)(get_window_layout_position(0x80)), (s32 *)lbl_8044F6AC, 1);
}

#pragma push
#pragma opt_loop_invariants off
void rebuild_com_card_list__17TWindowSubComCardFii(s32 arg0, s32 arg1) {
    s32 n;
    u32 cur;
    s32 i;
    s16 sel;
    s16 pos;
    void *e;
    cur = ((s32 (*)(u32))get_selected_menu_value)(arg1);
    sel = -1;
    TLobby::clear_flag_bit2();
    pos = ((TWindowShortListCtrl *)arg1)->get_cursor_pos();
    ((TWindowSubComCardList *)arg1)->reset_entries();
    n = get_com_card_data__6TLobbyFv();
    for (i = n - 1; i >= 0; i--) {
        e = get_com_card_entry__6TLobbyFi(i);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)arg1, (int)(((TWindowSubComCard *)e)->get_sub_obj()), 7, (int)(TLobby__sub_802428F8((void *)e)));
        if (cur == TLobby__sub_802428F8(e)) {
            sel = (n - 1) - i;
        }
    }
    if (n <= 0) {
        TWindowSubComCard::draw_text_gray(arg1, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xD3), 6, -1);
    }
    ((TWindowSubComCardList *)arg1)->update_layout_height(lbl_805DD51C);
    if (sel == -1) {
        ((TWindowSubComCardList *)arg1)->set_selected_index(pos);
    } else {
        ((TWindowSubComCardList *)arg1)->set_selected_index(sel);
    }
}
#pragma pop

s32 TWindowSubComCard__sub_80273004(void) {
    s32 r = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x89), 8, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x21));
    ((TWindowSubComCardList *)r)->set_flag70_bit10();
    return r;
}

}

#pragma pop

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

struct ComEntry_8027375C { u8 data[0xD4]; };

struct ComList_8027375C { u8 pad[4]; ComEntry_8027375C entries[1]; };

extern "C" {
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
extern const f32 lbl_805DD528;
s32 create_single_entry_window__17TWindowSubComCardFv(void);
s32 TWindowSubComCard__sub_8027353C(void);
extern const f32 lbl_805DD52C;
s32 TWindowSubComCard__sub_8027346C(void);
void queue_destruction__7TObjectFv(void *arg0);
s32 TWindowSubComCard__sub_800778B4(void *, int);
void TWindowSubComCard__sub_8007AF10(s32 arg0);
s32 update_press__17TWindowSubComCardFv(int);
void TWindowSubShortMail__sub_80131998(void *arg0);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
void free_menu_object(void *p);
s32 play_sound_effect(int, int, int, int);
void find_and_load_com_card__6TLobbyFUi(u32 arg0);
s32 TLobby__sub_8024259C();
s32 fn_80244958(int, int);
void fn_802449E0(u8 *arg0);
void TWindow__close(u8 *arg0);
}
void window_request_show(void *arg0);
s32 is_com_card_active();
extern "C" {
void TWindowSubComCard__sub_80249144(void *arg0);
void fn_8024AB54(s32 arg0);
void TWindowSubComCard__sub_8024AB98(s32 arg0);
s32 update_selected_entry__17TWindowSubComCardFv(int);
s32 send_packet__6TLobbyFll(void *, void *);
u32 TWindowSubComCard__sub_80272640(void *);
u32 TWindowSubComCard__sub_80272A98(void *);
u32 TWindowSubComCard__sub_80272DE0(TWindowSubComCard *);
s32 open_menu__17TWindowSubComCardFv(void);
u32 TWindowSubComCard__sub_8027337C();
s32 create_menu__17TWindowSubComCardFv(void);
s32 TWindowSubComCardList__sub_80275360(int);
s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *arg0, s32 arg1);
s32 create_keyboard__19TWindowSubShortMailFv(void);
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2);
extern s32 controller_input_state[];
extern s32 TLobby__protocol_instance;
extern s32 lbl_805DD534;
extern const f32 lbl_805DD538;
extern const f32 lbl_805DD53C;
void run_task__17TWindowSubComCardFv(TWindowSubComCard *arg0);
s32 free_member__17TWindowSubComCardFv(s32, s32);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(s32, s32, s32, f32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, s32, s32, s32);
extern const f32 TWindowSubComCard__data_805DD520;
void render__17TWindowSubComCardFv(void);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);
s32 get_main_phase();

s32 TWindowSubComCard::open_yesno_dialog() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x20)), (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x100)), (s32)(get_window_layout_position(0x97)), (f32)TWindowSubComCard__data_805DD520);
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

extern const f32 lbl_805DD524;

s32 TWindowSubComCard::sub_802730E0() {
    s32 temp_r30;
    temp_r30 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r30, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xFC), get_window_layout_position(0x96), (*(f32 *)&TWindowSubComCard__data_805DD520));
    free_member__17TWindowSubComCardFv(temp_r30, 1);
    ((TWindowSubShortMail *)temp_r30)->notify_warp_flag70();
    return temp_r30;
}

s32 TWindowSubComCard::confirm_and_free() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x20)), (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x39)), (s32)(get_window_layout_position(0x88)), (f32)lbl_805DD524);
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 open_menu__17TWindowSubComCardFv(void) {
    s32 temp_r31;

    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)(get_window_layout_position(0x87), 5, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x59)), 6, 0xF);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x59), 6, 0xF);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x101)), 6, 0x11);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x102)), 6, 0x13);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x63)), 6, 0x1B);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x5A)), 6, 0x15);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD510);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

extern const f32 lbl_805DD530;

s32 create_single_entry_window__17TWindowSubComCardFv(void) {
    s32 temp_r31;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((void *)(((s32)get_window_layout_position(0x84))), 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x38))), 3, 0);
    ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(TWindowSubComCard__data_805DD520, lbl_805DD528);
    return temp_r31;
}

u32 TWindowSubComCard__sub_8027337C() {
    s32 i;
    void *p;
    s32 w;
    u8 *name;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x83), 0xC, TWindowSubStatusDisp::get_message_10(0x1F));
    i = 0;
    do {
        if (i != local_client_id && (p = get_player_by_client_id(i)) != NULL &&
            is_script_controlled__10TObjPlayerFv(p) == 0 && obj_isState3_324__9TObjCharaFv(p) == 0 &&
            (name = (u8 *)p + 0x85C) != NULL) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)name, 7, (int)i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(TWindowSubComCard__data_805DD520, TWindowSubComCard__data_805DD514);
    return w;
}

s32 TWindowSubComCard__sub_8027346C(void) {
  s32 temp_r31;
  s32 temp_r31_2;
  temp_r31_2 = (0, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
  temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)((s32)((int) get_window_layout_position(0x8B)), 2, (s32)((int) temp_r31_2));
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((int) temp_r31), (int)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x57)), 6, 0x21);
  if (get_current_area() == 0xF)
  {
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((int) temp_r31), (int)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x58)), 6, 0x25);
  }
  else
  {
    TWindowSubComCard::draw_text_gray((s32)((int) temp_r31), (s32)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x58)), 6, 0x25);
  }
  ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
  temp_r31_2 = temp_r31;
  ((TWindowSubComCardList *)temp_r31_2)->update_layout_height((f32) lbl_805DD52C);
  align_menu_entry_positions((s32)((int) temp_r31_2));
  return temp_r31_2;
}

s32 TWindowSubComCard__sub_8027353C(void) {
    s32 temp_r31;
    s32 temp_r31_2;
    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)((s32)(((s32)get_window_layout_position(0x82))), 2, (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1E)));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x55))), 6, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x56))), 6, 9);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(TWindowSubComCard__data_805DD520);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 create_menu__17TWindowSubComCardFv(void) {
    s32 temp_r31;

    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)(get_window_layout_position(0x7F), 6, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x52)), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x53)), 6, 0xB);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x54)), 6, 0x1D);
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x49)), 6, 0x27);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x6D)), 6, 0x33);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xF8)), 6, 0x39);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, TQuestVmDownLoadServer__sub_8006EF6C(0x49), 6, 0x27);
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x6D), 6, 0x33);
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xF8), 6, 0x39);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD530);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

void render__17TWindowSubComCardFv(void) {  }
void run_task__17TWindowSubComCardFv(TWindowSubComCard *window_sub_com_card) {
    s32 temp_r29;
    s32 character_save_record;
    s32 temp_r29_7;
    s32 temp_r29_8;
    s32 keyboard_mode;
    u32 temp_r30_2;
    s32 temp_r4;
    s32 var_r29;
    u8 temp_r0;
    s32 temp_r29_6;
    s32 temp_r30_3;
    u8 *temp_r3;
    u8 *temp_r3_2;
    temp_r0 = window_sub_com_card->m_1c;
    switch (temp_r0) {
    case 0x0:
    case 0x1:
        window_sub_com_card->send_state_if_dirty();
        if ((u32) window_sub_com_card->m_80 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)window_sub_com_card + 0x80));
            window_sub_com_card->m_80 = 0U;
        }
        if ((u32) window_sub_com_card->m_7c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_7c);
            window_sub_com_card->m_7c = 0U;
        }
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_84 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_84);
            window_sub_com_card->m_84 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_78 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_78);
            window_sub_com_card->m_78 = 0U;
        }
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_6c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_6c);
            window_sub_com_card->m_6c = 0U;
        }
        if ((u32) window_sub_com_card->m_60 == 0U) {
            window_sub_com_card->m_60 = ((s32 (*)(void *)) create_menu__17TWindowSubComCardFv)((void *)window_sub_com_card);
        }
        if ((u32) window_sub_com_card->m_6c == 0U) {
            window_sub_com_card->m_6c = ((u32 (*)(void*))open_layout_window__17TWindowSubComCardFv)((void *)window_sub_com_card);
            window_sub_com_card->m_28 = -1;
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_60))->clear_flag_and_release();
        window_sub_com_card->m_1c = 2U;
    case 0x2:
        window_sub_com_card->set_help_message((int) (((TWindowShortListCtrl *)(window_sub_com_card->m_60))->get_cursor_pos()));
        if (((TWindowSubComCard *)(window_sub_com_card->m_60))->get_status_flag() != 0) {
            temp_r3 = (u8 *)(*(u8 **)((s8 *)window_sub_com_card + 0x5C));
            ((VObj_18_204a81 *)(temp_r3))->m7();
            window_sub_com_card->m_1c = 0x4FU;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_60))->is_visible() != 0) {
            if ((u32) window_sub_com_card->m_6c != 0U) {
                TWindow__close((u8 *)window_sub_com_card->m_6c);
                window_sub_com_card->m_6c = 0U;
            }
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_60);
            return;
        }
        break;
    case 0x3:
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_74 == 0U) {
            window_sub_com_card->m_74 = TWindowSubComCard::create_com_card_window(get_window_layout_position(0x81));
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = ((s32 (*)(void *)) TWindowSubComCard__sub_8027353C)((void *)window_sub_com_card);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_flag_and_release();
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_transition_flag();
        window_sub_com_card->m_1c = 4U;
    case 0x4:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64);
            return;
        }
        break;
    case 0x5:
        if ((u32) window_sub_com_card->m_68 == 0U) {
            window_sub_com_card->m_68 = TWindowSubComCard__sub_8027337C();
        }
        ((TWindowOptionCtrl *)(window_sub_com_card->m_64))->open();
        window_sub_com_card->m_1c = 6U;
    case 0x6:
        if (((TWindowSubComCard *)(window_sub_com_card->m_68))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 3U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_68))->is_visible() != 0) {
            TWindowSubComCard__sub_8007AF10(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_68));
            window_sub_com_card->m_1c = 7U;
            return;
        }
        break;
    case 0x7:
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 == 0U) {
            window_sub_com_card->m_68 = ((s32 (*)(void *)) create_single_entry_window__17TWindowSubComCardFv)((void *)window_sub_com_card);
        }
        window_sub_com_card->m_1c = 8U;
    case 0x8:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
            window_sub_com_card->m_1c = 3U;
            return;
        }
        break;
    case 0x9:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_60 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_60);
            window_sub_com_card->m_60 = 0U;
        }
        window_sub_com_card->m_80 = ((u32 (*)(void*))create_keyboard__17TWindowSubComCardFi)((void *)window_sub_com_card);
        window_sub_com_card->m_1c = 0xAU;
    case 0xA:
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->is_keyboard_active() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->update_keyboard() != 0) {
            temp_r29 = ((TWindowSubComCard *)(window_sub_com_card->m_80))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)temp_r29, (char *)get_shared_text_buffer());
            keyboard_mode = TWindowSubComCard::get_keyboard_mode();
            ((TWindowSubComCard *)keyboard_mode)->set_text((void *)(((s32 (*)(void))get_shared_text_buffer)()));
            mem_free((void *)temp_r29);
            window_sub_com_card->m_1c = 1U;
            return;
        }
        break;
    case 0xB:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_6c == 0U) {
            window_sub_com_card->m_6c = ((u32 (*)(void*))create__17TWindowSubComCardFv)((void *)window_sub_com_card);
            fn_802449E0((u8 *)window_sub_com_card->m_6c);
            window_sub_com_card->m_28 = -1;
        }
        if ((u32) window_sub_com_card->m_84 == 0U) {
            window_sub_com_card->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) window_sub_com_card->m_74 == 0U) {
            window_sub_com_card->m_24 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84);
            window_sub_com_card->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(window_sub_com_card->m_24);
        }
        fn_80244958(window_sub_com_card->m_6c, (int) (get_window_layout_position(0x99)));
        ((TWindowLockOn *)(window_sub_com_card->m_6c))->request_close();
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0xCU;
    case 0xC:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(window_sub_com_card->m_84, window_sub_com_card->m_74, (void *) ((u8 *)window_sub_com_card + 0x24));
        window_sub_com_card->set_card_index((int) (((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84)));
        if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 0x400) != 0) {
            if (((TUnk_804CE018 *)(window_sub_com_card->m_6c))->sub_80244994() != 0) {
                ((TWindowLockOn *)(window_sub_com_card->m_6c))->request_close();
            } else {
                window_request_show((void *)window_sub_com_card->m_6c);
            }
        }
        if (((TWindowSubComCard *)(window_sub_com_card->m_84))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_84))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0xDU;
            return;
        }
        break;
    case 0xD:
        if ((u32) window_sub_com_card->m_6c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_6c);
            window_sub_com_card->m_6c = 0U;
        }
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = ((s32 (*)(void *)) open_menu__17TWindowSubComCardFv)((void *)window_sub_com_card);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_transition_flag();
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0xEU;
    case 0xE:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0xBU;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64);
            return;
        }
        break;
    case 0xF:
        ((s32 (*)(void))cleanup__17TWindowSubComCardFPv)();
        window_sub_com_card->m_1c = 0x10U;
    case 0x10:
        window_sub_com_card->m_1c = 0xBU;
        return;
    case 0x11:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_6c == 0U) {
            window_sub_com_card->m_6c = ((u32 (*)(void*))create__17TWindowSubComCardFv)((void *)window_sub_com_card);
            window_sub_com_card->m_28 = -1;
        }
        window_sub_com_card->set_card_index((int) (((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84)));
        window_sub_com_card->m_1c = 0x12U;
    case 0x12:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
            window_sub_com_card->m_1c = 0xBU;
            return;
        }
        break;
    case 0x13:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_84 != 0U) {
            window_sub_com_card->m_24 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84);
            TWindow__close((u8 *)window_sub_com_card->m_84);
            window_sub_com_card->m_84 = 0U;
        }
        if ((u32) window_sub_com_card->m_60 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_60);
            window_sub_com_card->m_60 = 0U;
        }
        window_sub_com_card->m_80 = ((u32 (*)(void*, int))create_keyboard__17TWindowSubComCardFii)((void *)window_sub_com_card, window_sub_com_card->m_24);
        window_sub_com_card->m_1c = 0x14U;
    case 0x14:
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->is_keyboard_active() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->update_keyboard() != 0) {
            temp_r29 = ((TWindowSubComCard *)(window_sub_com_card->m_80))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)temp_r29, (char *)get_shared_text_buffer());
            ((TWindowSubComCard *)(window_sub_com_card->m_24))->set_card_text((int) (((s32 (*)(void))get_shared_text_buffer)()));
            mem_free((void *)temp_r29);
            window_sub_com_card->m_1c = 1U;
            return;
        }
        break;
    case 0x15:
        ((TWindowOptionCtrl *)(window_sub_com_card->m_64))->open();
        window_sub_com_card->m_70 = window_sub_com_card->confirm_and_free();
        window_sub_com_card->m_1c = 0x16U;
    case 0x16:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0xDU;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::remove_card_at(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84));
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0xDU;
            return;
        }
        break;
    case 0x19:
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x1AU;
    case 0x1A:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(window_sub_com_card->m_84, window_sub_com_card->m_74, (void *) ((u8 *)window_sub_com_card + 0x24));
        if (((TWindowSubComCard *)(window_sub_com_card->m_84))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_84))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x1BU;
            return;
        }
        break;
    case 0x1B:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_84 == 0U) {
            window_sub_com_card->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) window_sub_com_card->m_74 == 0U) {
            window_sub_com_card->m_24 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84);
            window_sub_com_card->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(window_sub_com_card->m_24);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->set_display_page();
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x1CU;
    case 0x1C:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(window_sub_com_card->m_84, window_sub_com_card->m_74, (void *) ((u8 *)window_sub_com_card + 0x24));
        if (((TWindowSubComCard *)(window_sub_com_card->m_84))->get_status_flag() != 0) {
            ((TWindowMenu *)(window_sub_com_card->m_84))->reset_selection();
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_84))->is_visible() != 0) {
            TWindowSubComCard::swap_cards((int) (((TWindowSubComCardList *)(window_sub_com_card->m_84))->get_selected_index()), (int) (((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84)));
            ((TWindowMenu *)(window_sub_com_card->m_84))->reset_selection();
            TWindowSubComCardList__sub_80275360(window_sub_com_card->m_84);
            window_sub_com_card->m_1c = 0x19U;
            return;
        }
        break;
    case 0x1D:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_78 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_78);
            window_sub_com_card->m_78 = 0U;
        }
        window_sub_com_card->m_68 = ((u32 (*)(void*))TWindowSubComCard__sub_80273004)((void *)window_sub_com_card);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_sub_com_card->m_68, (int)&lbl_805DD534, 0x15, -1);
        ((s32 (*)(void*, int))rebuild_com_card_list__17TWindowSubComCardFii)((void *)window_sub_com_card, window_sub_com_card->m_68);
        window_sub_com_card->m_1c = 0x1EU;
    case 0x1E:
        if (is_com_card_active() != 0) {
            ((s32 (*)(void*, int))rebuild_com_card_list__17TWindowSubComCardFii)((void *)window_sub_com_card, window_sub_com_card->m_68);
        }
        if (((TWindowSubComCard *)(window_sub_com_card->m_68))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_68))->is_visible() != 0) {
            find_and_load_com_card__6TLobbyFUi(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_68));
            window_sub_com_card->m_1c = 0x1FU;
            return;
        }
        break;
    case 0x1F:
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_78 == 0U) {
            var_r29 = ((s32 (*)(void))get_selected_guild_card_record)();
            temp_r30_2 = ((u32 (*)(int))__nw__7TObjectFUl)(0x64);
            if (temp_r30_2 != 0U) {
                temp_r30_2 = (u32)TWindowUserSort__ct((u8 *)temp_r30_2, (get_window_layout_position(0x8A)), (var_r29));
            }
            window_sub_com_card->m_78 = temp_r30_2;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = ((s32 (*)(void *)) TWindowSubComCard__sub_8027346C)((void *)window_sub_com_card);
        }
        window_sub_com_card->m_1c = 0x20U;
    case 0x20:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x1DU;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64);
            return;
        }
        break;
    case 0x21:
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_78 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_78);
            window_sub_com_card->m_78 = 0U;
        }
        if ((u32) window_sub_com_card->m_60 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_60);
            window_sub_com_card->m_60 = 0U;
        }
        if ((u32) window_sub_com_card->m_80 == 0U) {
            window_sub_com_card->m_80 = create_keyboard__19TWindowSubShortMailFv();
        }
        ((TWindowSubShortMail *)(window_sub_com_card->m_80))->set_position((void *)(get_window_layout_position(0xBB)));
        free_menu_object((void *)window_sub_com_card->m_80);
        ((TWindowSubShortMail *)(window_sub_com_card->m_80))->hide_window();
        window_sub_com_card->m_1c = 0x22U;
    case 0x22:
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->is_keyboard_active() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowSubComCard *)(window_sub_com_card->m_80))->update_keyboard() != 0) {
            window_sub_com_card->m_1c = 0x23U;
            return;
        }
        break;
    case 0x23:
        ((TWindowSubShortMail *)(window_sub_com_card->m_80))->set_position((void *)(get_window_layout_position(0xBC)));
        TWindowSubShortMail__sub_80131998((void *)window_sub_com_card->m_80);
        window_sub_com_card->m_70 = open_confirm_prompt__19TWindowSubShortMailFPvi((window_sub_com_card), (window_sub_com_card->m_20));
        window_sub_com_card->m_1c = 0x24U;
    case 0x24:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0x21U;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                window_sub_com_card->sub_802721D8();
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0x21U;
            return;
        }
        break;
    case 0x25:
        ((s32 (*)(void))get_selected_guild_card_record)();
        TLobby__sub_8024259C();
        fn_8024AB54((window_sub_com_card->m_20));
        window_sub_com_card->m_2c = 0;
        window_sub_com_card->m_1c = 0x26U;
    case 0x26:
        temp_r4 = window_sub_com_card->m_2c;
        window_sub_com_card->m_2c = (temp_r4 + 1);
        if ((f32) temp_r4 > lbl_805DD538) {
            TWindowSubComCard__sub_8024AB98((window_sub_com_card->m_20));
            temp_r3_2 = (u8 *)(*(u8 **)((s8 *)window_sub_com_card + 0x5C));
            ((VObj_18_204a81 *)(temp_r3_2))->m7();
            window_sub_com_card->m_1c = 0x4FU;
            return;
        }
        break;
    case 0x27:
    case 0x33:
        if (((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)() == 0U) {
            ((TProtocol *)TLobby__protocol_instance)->send_choice_search_options_request();
        }
        if ((u8) window_sub_com_card->m_1c == 0x27) {
            window_sub_com_card->m_1c = 0x28U;
        } else {
            window_sub_com_card->m_1c = 0x34U;
        }
    case 0x28:
    case 0x34:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            window_sub_com_card->m_1c = 1U;
        }
        if (((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)() != 0U) {
            if ((u32) window_sub_com_card->m_58 == 0U) {
                window_sub_com_card->m_58 = ((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)();
                character_save_record = get_character_save_record(0xFFFF);
                TWindowSubComCard__sub_800778B4((void *) ((u8 *)window_sub_com_card + 0x30), window_sub_com_card->m_58);
                TWindowSubComCard__sub_800778B4((void *)(character_save_record + 0x22EC), (int)window_sub_com_card->m_58);
            }
            if ((u8) window_sub_com_card->m_1c == 0x28) {
                window_sub_com_card->m_1c = 0x29U;
                return;
            }
            window_sub_com_card->m_1c = 0x35U;
            return;
        }
        break;
    case 0x29:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_7c == 0U) {
            window_sub_com_card->m_7c = TWindowSubComCard__sub_80272DE0((TWindowSubComCard *)((void *)window_sub_com_card));
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_7c))->begin_scroll((f32)lbl_805DD53C);
        ((TWindowSubComCard *)(window_sub_com_card->m_7c))->clear_flag_and_release2();
        window_sub_com_card->m_1c = 0x2AU;
    case 0x2A:
        if (((TWindowSubComCard *)(window_sub_com_card->m_7c))->get_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TUnk_804D0658 *)(window_sub_com_card->m_7c))->is_open() != 0) {
            if (update_selected_entry__17TWindowSubComCardFv(window_sub_com_card->m_7c) == 0) {
                window_sub_com_card->m_1c = 0x2DU;
                return;
            }
            window_sub_com_card->m_1c = 0x2BU;
            return;
        }
        break;
    case 0x2B:
        TWindowSubComCard__sub_80249144((void *)window_sub_com_card->m_7c);
        window_sub_com_card->m_64 = window_sub_com_card->create_option_list_window((s32)((void *) ((u8 *)window_sub_com_card + 0x30)), (s32)((int) (update_selected_entry__17TWindowSubComCardFv(window_sub_com_card->m_7c))));
        window_sub_com_card->m_1c = 0x2CU;
    case 0x2C:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x29U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            ((TWindowSubComCard *)window_sub_com_card)->sub_80271F04((void *) ((u8 *)window_sub_com_card + 0x30), (int) (update_selected_entry__17TWindowSubComCardFv(window_sub_com_card->m_7c)), (int) (((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64)));
            window_sub_com_card->m_1c = 0x29U;
            return;
        }
        break;
    case 0x2D:
        TWindowSubComCard::release();
        send_packet__6TLobbyFll((void *)window_sub_com_card, (void *) ((u8 *)window_sub_com_card + 0x30));
        window_sub_com_card->m_1c = 0x2EU;
    case 0x2E:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            window_sub_com_card->m_1c = 0x29U;
        }
        if (((u32 (*)(void))get_com_count__17TWindowSubComCardFv)() != 0U) {
            window_sub_com_card->m_1c = 0x2FU;
            return;
        }
        break;
    case 0x2F:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_7c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_7c);
            window_sub_com_card->m_7c = 0U;
        }
        if ((u32) window_sub_com_card->m_68 == 0U) {
            window_sub_com_card->m_68 = TWindowSubComCard__sub_80272A98((void *)window_sub_com_card);
        }
        if ((u32) window_sub_com_card->m_6c == 0U) {
            window_sub_com_card->m_6c = ((u32 (*)(void*))open_mode4_window__17TWindowSubComCardFv)((void *)window_sub_com_card);
            window_sub_com_card->m_28 = -1;
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_68))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x30U;
    case 0x30:
        window_sub_com_card->set_selected_card((int) (((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_68)));
        if (((TWindowSubComCard *)(window_sub_com_card->m_68))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_68))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x31U;
            return;
        }
        break;
    case 0x31:
        if ((u32) window_sub_com_card->m_6c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_6c);
            window_sub_com_card->m_6c = 0U;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            temp_r29_6 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_68);
            ComList_8027375C *cl = (ComList_8027375C *) ((u32 (*)(void))get_com_count__17TWindowSubComCardFv)();
            ((s32 (*)(void*))load_selected_guild_card_record)(&cl->entries[temp_r29_6]);
            window_sub_com_card->m_64 = ((u32 (*)(void*))create_menu_window__17TWindowSubComCardFv)((void *)window_sub_com_card);
        }
        window_sub_com_card->m_1c = 0x32U;
    case 0x32:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x2FU;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64);
            return;
        }
        break;
    case 0x35:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_7c == 0U) {
            window_sub_com_card->m_7c = window_sub_com_card->create_entry_list_window();
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_7c))->begin_scroll((f32)lbl_805DD53C);
        ((TWindowSubComCard *)(window_sub_com_card->m_7c))->clear_flag_and_release2();
        window_sub_com_card->m_1c = 0x36U;
    case 0x36:
        if (((TWindowSubComCard *)(window_sub_com_card->m_7c))->get_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TUnk_804D0658 *)(window_sub_com_card->m_7c))->is_open() != 0) {
            window_sub_com_card->m_1c = 0x37U;
            return;
        }
        break;
    case 0x37:
        TWindowSubComCard__sub_80249144((void *)window_sub_com_card->m_7c);
        temp_r29_7 = get_character_save_record(0xFFFF);
        window_sub_com_card->m_64 = window_sub_com_card->create_option_list_window(temp_r29_7 + 0x22EC, (s32)((int) (update_selected_entry__17TWindowSubComCardFv(window_sub_com_card->m_7c))));
        window_sub_com_card->m_1c = 0x38U;
    case 0x38:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x35U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            temp_r29_8 = get_character_save_record(0xFFFF);
            ((TWindowSubComCard *)window_sub_com_card)->sub_80271F04((void *)(temp_r29_8 + 0x22EC), (int) (update_selected_entry__17TWindowSubComCardFv((int)window_sub_com_card->m_7c)), (int) (((s32 (*)(int))get_selected_menu_value)((int)window_sub_com_card->m_64)));
            window_sub_com_card->m_1c = 0x35U;
            return;
        }
        break;
    case 0x39:
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_84 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_84);
            window_sub_com_card->m_84 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = ((u32 (*)(void*))TWindowSubComCard__sub_802728CC)((void *)window_sub_com_card);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x3AU;
    case 0x3A:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64);
            return;
        }
        break;
    case 0x3B:
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_6c != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_6c);
            window_sub_com_card->m_6c = 0U;
        }
        if ((u32) window_sub_com_card->m_84 == 0U) {
            window_sub_com_card->m_84 = ((u32 (*)(void))init_layout__17TWindowSubComCardFv)();
        }
        if ((u32) window_sub_com_card->m_74 == 0U) {
            window_sub_com_card->m_24 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84);
            window_sub_com_card->m_74 = ((u32 (*)(int))apply_selection__17TWindowSubComCardFi)(window_sub_com_card->m_24);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x3CU;
    case 0x3C:
        ((s32 (*)(int, int, void*))update_selection__17TWindowSubComCardFiii)(window_sub_com_card->m_84, window_sub_com_card->m_74, (void *) ((u8 *)window_sub_com_card + 0x24));
        if (((TWindowSubComCard *)(window_sub_com_card->m_84))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x39U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_84))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x3DU;
            return;
        }
        break;
    case 0x3D:
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_70 == 0U) {
            window_sub_com_card->m_70 = window_sub_com_card->sub_802730E0();
        }
        window_sub_com_card->m_1c = 0x3EU;
    case 0x3E:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0x3BU;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::remove_entry(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84));
                window_sub_com_card->m_1d = (u8) (window_sub_com_card->m_1d | 2);
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0x3BU;
            return;
        }
        break;
    case 0x3F:
        window_sub_com_card->m_68 = TWindowSubComCard::create_card_action_window();
        window_sub_com_card->m_1c = 0x40U;
    case 0x40:
        if (((TWindowSubComCard *)(window_sub_com_card->m_68))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 0x39U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_68))->is_visible() != 0) {
            window_sub_com_card->m_1c = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_68);
            return;
        }
        break;
    case 0x41:
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
        if ((u32) window_sub_com_card->m_84 == 0U) {
            window_sub_com_card->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) window_sub_com_card->m_74 == 0U) {
            window_sub_com_card->m_24 = ((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84);
            window_sub_com_card->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(window_sub_com_card->m_24);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_84))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x42U;
    case 0x42:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(window_sub_com_card->m_84, window_sub_com_card->m_74, (void *) ((u8 *)window_sub_com_card + 0x24));
        if (((TWindowSubComCard *)(window_sub_com_card->m_84))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_84))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x43U;
            return;
        }
        break;
    case 0x43:
        if ((u32) window_sub_com_card->m_74 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_74);
            window_sub_com_card->m_74 = 0U;
        }
        if ((u32) window_sub_com_card->m_70 == 0U) {
            window_sub_com_card->m_70 = window_sub_com_card->open_yesno_dialog();
        }
        window_sub_com_card->m_1c = 0x44U;
    case 0x44:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0x41U;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                update_press__17TWindowSubComCardFv(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_84));
                window_sub_com_card->m_1d = (u8) (window_sub_com_card->m_1d | 2);
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0x41U;
            return;
        }
        break;
    case 0x45:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
    case 0x46:
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = ((u32 (*)(void*))create_player_select_window__17TWindowSubComCardFv)((void *)window_sub_com_card);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x47U;
    case 0x47:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x48U;
            return;
        }
        break;
    case 0x48:
        if ((u32) window_sub_com_card->m_70 == 0U) {
            window_sub_com_card->m_70 = window_sub_com_card->open_yesno_dialog();
        }
        window_sub_com_card->m_1c = 0x49U;
    case 0x49:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0x46U;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::init_and_press_b(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64));
                window_sub_com_card->m_1d = (u8) (window_sub_com_card->m_1d | 2);
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0x46U;
            return;
        }
        break;
    case 0x4A:
        if ((u32) window_sub_com_card->m_64 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_64);
            window_sub_com_card->m_64 = 0U;
        }
    case 0x4B:
        if ((u32) window_sub_com_card->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_sub_com_card + 0x70)))->close();
            window_sub_com_card->m_70 = 0U;
        }
        if ((u32) window_sub_com_card->m_68 != 0U) {
            TWindow__close((u8 *)window_sub_com_card->m_68);
            window_sub_com_card->m_68 = 0U;
        }
        if ((u32) window_sub_com_card->m_64 == 0U) {
            window_sub_com_card->m_64 = TWindowSubComCard__sub_80272640((void *)window_sub_com_card);
        }
        ((TWindowSubComCard *)(window_sub_com_card->m_64))->clear_flag_and_release();
        window_sub_com_card->m_1c = 0x4CU;
    case 0x4C:
        if (((TWindowSubComCard *)(window_sub_com_card->m_64))->get_status_flag() != 0) {
            window_sub_com_card->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(window_sub_com_card->m_64))->is_visible() != 0) {
            window_sub_com_card->m_1c = 0x4DU;
            return;
        }
        break;
    case 0x4D:
        if ((u32) window_sub_com_card->m_70 == 0U) {
            window_sub_com_card->m_70 = window_sub_com_card->open_yesno_dialog();
        }
        window_sub_com_card->m_1c = 0x4EU;
    case 0x4E:
        if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_card_data() != 0) {
            window_sub_com_card->m_1c = 0x4BU;
            return;
        }
        if (((TWindowMessageYesNo *)(window_sub_com_card->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(window_sub_com_card->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::init_and_press_a(((s32 (*)(int))get_selected_menu_value)(window_sub_com_card->m_64));
                window_sub_com_card->m_1d = (u8) (window_sub_com_card->m_1d | 2);
                window_sub_com_card->m_1c = 1U;
                return;
            }
            window_sub_com_card->m_1c = 0x4BU;
        }
        break;
    case 0x4F:
        break;
    }
}

void *__dt__17TWindowSubComCardFv(TWindowSubComCard *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);

extern void* __vt__17TWindowSubComCard[];

void *__dt__17TWindowSubComCardFv(TWindowSubComCard *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = (void *) __vt__17TWindowSubComCard;
        arg0->handle_close_flag();
        arg0->send_state_if_dirty();
        if ((u8) arg0->m_1c == 0x26) {
            TWindowSubComCard__sub_8024AB98(arg0->m_20);
        }
        if ((u32) arg0->m_7c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x7C)));
            arg0->m_7c = 0U;
        }
        if ((u32) arg0->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x70)))->close();
            arg0->m_70 = 0U;
        }
        if ((u32) arg0->m_84 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x84)));
            arg0->m_84 = 0U;
        }
        if ((u32) arg0->m_80 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x80));
            arg0->m_80 = 0U;
        }
        if ((u32) arg0->m_68 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x68)));
            arg0->m_68 = 0U;
        }
        if ((u32) arg0->m_64 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x64)));
            arg0->m_64 = 0U;
        }
        if ((u32) arg0->m_78 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x78)));
            arg0->m_78 = 0U;
        }
        if ((u32) arg0->m_74 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x74)));
            arg0->m_74 = 0U;
        }
        if ((u32) arg0->m_6c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x6C)));
            arg0->m_6c = 0U;
        }
        if ((u32) arg0->m_60 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x60)));
            arg0->m_60 = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TWindowSubComCard__sub_80077980(void *);
}

extern void *TWindowSubComCard__class_name;
TWindowSubComCard::TWindowSubComCard(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TWindowSubComCard__class_name;
    *(void **)((s8 *)this + 0x5C) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_60 = 0;
    this->m_64 = 0;
    this->m_74 = 0;
    this->m_78 = 0;
    this->m_68 = 0;
    this->m_6c = 0;
    this->m_70 = 0;
    this->m_80 = 0;
    this->m_84 = 0;
    this->m_7c = 0;
    this->m_58 = 0;
    this->m_1d = 0;
    this->m_24 = -1;
    TWindowSubComCard__sub_80077980((void *)((char *)this + 48));
    this->m_1c = 0;
}

struct RecoveredGlobal_80275228_lbl_80517EE0 {
    s32 value;
    u8 remaining[0xB8];
};

extern RecoveredGlobal_80275228_lbl_80517EE0 selected_guild_card_record;
extern "C" {
void fn_80247ED8(void *p);

void TWindowSubComCard::set_com_param(s32 arg1) {
    s32 arg0 = (s32)this;
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 0x12), (s32)0xFFFBFFFF);
}
}

typedef char RecoveredGlobal_80275228_lbl_80517EE0_size[sizeof(RecoveredGlobal_80275228_lbl_80517EE0) == 0xBC ? 1 : -1];
s32 *get_selected_guild_card_record(void) {
    return &selected_guild_card_record.value;
}

void*TWindowSubComCard::get_card_data_ptr() { return (char*)this + 0x3b; }
void* TWindowSubComCard__sub_8027523C(void* p) { return (char*)p + 0x2a; }
void*TWindowSubComCard::get_name() { return (char*)this + 0x19; }
void*TWindowSubComCard::get_sub_obj() { return (char*)this + 0x8; }
void TWindowSubComCard::destroy_keyboard() { void* m = *(void* *)&this->m_28; if (m) fn_80247ED8(m); }
s16 TWindowSubComCardList::get_field_72() { return *(s16 *)&this->m_72; }
void TWindowSubComCard::set_page(s16 v) { *(s16*)((char*)this + 0x7a) = v; }
void TWindowSubComCard::set_flag_10() { *(u16*)((char*)this + 0x70) |= 0x10; }
void TWindowSubComCard::set_display_page() {
    s32 arg0 = (s32)this;
    set_page((s16)((int) (((s16 (*)(void))get_selected_menu_value)())));
}
