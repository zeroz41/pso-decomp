#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TUnk_804F3A20.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/TAdMultiChgGameModeGC_8036DE10.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"

#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/ui/Language.h"

struct RecoveredGlobal_8036E8DC_lbl_804C88C0 { s32 value; u8 remaining[0x50]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C88C0_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C88C0) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8036E8DC_lbl_804C8914 { char value[0xB]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C8914_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C8914) == 0xB ? 1 : -1];

struct RecoveredGlobal_8036E8DC_lbl_804C89BC { s32 value; u8 remaining[0x74]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C89BC_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C89BC) == 0x78 ? 1 : -1];

struct RecoveredGlobal_8036DE10_lbl_804F37A8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8036DE10_lbl_804F37D4 {
    s32 value;
    u8 remaining[0x130];
};

#include <stddef.h>
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
struct Stack_8036EA24 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8036EA24 { s32 words[3]; void (TAdMultiChgGameModeGC::*action)(); };

struct RecoveredGlobal_8036EA24_lbl_804F3908 {
    s32 value;
    u8 remaining[0x104];
};

struct Stack_8036E858 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8036E858 { s32 words[3]; void (TAdMultiChgGameModeGC::*action)(); };

struct RecoveredGlobal_8036E858_lbl_804F3908 {
    s32 value;
    u8 remaining[0x104];
};

struct Self_8036E2AC {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    void *win;
};

extern "C" {
void *__nw__7TObjectFUl(int);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
s32 load_system_file(s32 arg0);
void refresh_char_slots__23TAdSinglePlyChrSelectGCFv(void);
s32 encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv();
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);
int init_change_mode__21TAdMultiChgGameModeGCFv(void*);
void queue_destruction__7TObjectFv(void *arg0);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
extern RecoveredGlobal_8036E8DC_lbl_804C88C0 lbl_804C88C0;
extern RecoveredGlobal_8036E8DC_lbl_804C8914 pso_system_card_filename;
extern RecoveredGlobal_8036E8DC_lbl_804C89BC lbl_804C89BC;
extern RecoveredGlobal_8036DE10_lbl_804F37A8 multi_chg_game_mode_text_table_a;
extern RecoveredGlobal_8036DE10_lbl_804F37D4 multi_chg_game_mode_text_table_b;
extern RecoveredGlobal_8036EA24_lbl_804F3908 multi_chg_game_mode_entry_table;
u32 load_system_file_flag__23TAdSinglePlyChrSelectGCFv(void);
u32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
extern s32 lbl_8047B8A0[];
extern s32 multi_chg_game_mode_window_extent[];
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 align_menu_entry_positions(void *);
extern u8 lbl_804F3A18[];
extern const f32 lbl_805D7020;
s32 all_players_loaded__23TAdSinglePlyChrSelectGCFv();
s32 TAdPlayerLoadGC__sub_801FD770();
void TKeyBoardControl__sub_8000F90C(s32 arg0);

typedef char RecoveredGlobal_8036DE10_lbl_804F37A8_size[sizeof(RecoveredGlobal_8036DE10_lbl_804F37A8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8036DE10_lbl_804F37D4_size[sizeof(RecoveredGlobal_8036DE10_lbl_804F37D4) == 0x134 ? 1 : -1];
s32 TAdMultiChgGameModeGC__sub_8036DE10(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == -1) {
        return TQuestVmDownLoadServer__sub_8006EF6C((arg1));
    }
    if (arg2 == 0) {
        return *(s32 *)((s8 *)((u8 *)&multi_chg_game_mode_text_table_b.value + (arg1 * 4)) + 0);
    }
    return *(s32 *)((s8 *)((u8 *)&multi_chg_game_mode_text_table_a.value + (arg1 * 4)) + 0);
}

void TAdMultiChgGameModeGC::close_windows_on_selection() {
    void *temp_r3;
    if (handle_mode_selection() == 0) {
        temp_r3 = *(void **)((s8 *)this + 0x30);
        if ((u32) temp_r3 != 0U) {
            queue_destruction__7TObjectFv(temp_r3);
            *(u32 *)((s8 *)this + 0x30) = 0U;
        }
        temp_r3 = *(void **)((s8 *)this + 0x34);
        if ((u32) temp_r3 != 0U) {
            queue_destruction__7TObjectFv(temp_r3);
            *(u32 *)((s8 *)this + 0x34) = 0U;
        }
        set_state(3);
    }
}

void TAdMultiChgGameModeGC__sub_8036DEDC(void *self) {
    if (((TAdMultiChgGameModeGC *)self)->handle_mode_selection() != 0) {
        return;
    }
}

void TAdMultiChgGameModeGC::update_confirm_selection() {
    s32 selected_menu_value;
    u32 temp_r3_2;

    if (handle_mode_selection() == 0) {
        temp_r3_2 = *(u32 *)((s8 *)this + 0x34);
        if (temp_r3_2 != 0U) {
            if (((TWindowMenu *)temp_r3_2)->is_decided() != 0) {
                selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)this + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    set_state(6);
                    close_window_30();
                    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 8);
                    return;
                case 1:
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}
}

void close_windows_and_cleanup(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close();
        *(u32 *)((s8 *)arg0 + 0x30) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(arg0, 0);
    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)arg0, 4);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)arg0 + 0x30)))->append_line(TAdMultiChgGameModeGC__sub_8036DE10((s32)arg0, 3, (s32)(*(s32 *)((s8 *)arg0 + 0x24))), 3);
    }
}

void TAdMultiChgGameModeGC::update_card_confirm_selection() {
    s32 selected_menu_value;

    if (handle_mode_selection() == 0) {
        if (*(void **)((s8 *)this + 0x34) != 0) {
            if (((TWindowMenu *)(*(void **)((s8 *)this + 0x34)))->is_decided() != 0) {
                selected_menu_value = ((TWindowMenu *)(*(void **)((s8 *)this + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(5);
                    return;
                case 1:
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}

void TAdMultiChgGameModeGC::close_windows_and_reopen() {
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(this, 0);
    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 4);
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->append_line(TAdMultiChgGameModeGC__sub_8036DE10((s32)this, 1, (s32)(*(s32 *)((s8 *)this + 0x24))), 3);
    }
}

void TAdMultiChgGameModeGC__sub_8036E19C(u8 *arg0, s32 arg1) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close();
        *(u32 *)((s8 *)arg0 + 0x30) = 0U;
    }
    *(u32 *)((s8 *)arg0 + 0x30) = update_window_mode_from_progress__6TLobbyFPv(multi_chg_game_mode_window_extent, lbl_8047B8A0);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)arg0 + 0x30)))->append_line((s32)((int) (TAdMultiChgGameModeGC__sub_8036DE10((s32)arg0, (s32)arg1, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x24)))))), 3);
    }
}

void TAdMultiChgGameModeGC::close_window_30() {
    void *temp_r3 = *(void **)((s8 *)this + 0x30);
    if ((u32) temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    close_window__21TAdMultiChgGameModeGCFPv(this);
}
void close_window__21TAdMultiChgGameModeGCFPv(void* p) { if (*(unsigned int*)((char*)p + 0x34) != 0) { ((TWindowBase *)((void*)(*(void**)((char*)p + 0x34))))->close(); *(int*)((char*)p + 0x34) = 0; } }

#define self ((Self_8036E2AC *)arg0)
s32 TAdMultiChgGameModeGC::setup_mode_menu(void *arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    self->win = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_804F3A18, 2);
    a = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 6, self->f24);
    b = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 7, self->f24);
    c = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 2, self->f24);
    d = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 5, self->f24);
    if (self->win != 0) {
        if (arg1 == 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, a, 5, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, b, 5, 1);
            ((TWindowSubComCardList *)(self->win))->set_selected_index(1);
        } else {
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, c, 5, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, d, 5, 1);
            ((TWindowSubComCardList *)(self->win))->set_selected_index(0);
        }
        ((TWindowSubComCardList *)(self->win))->update_layout_height(lbl_805D7020);
        align_menu_entry_positions(self->win);
    }
}
#undef self

void TAdMultiChgGameModeGC::handle_menu_input() {
    s32 selected_menu_value;
    u8 *window_menu;
    if (handle_mode_selection() == 0) {
        window_menu = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x34));
        if (window_menu != NULL) {
            if (((int)((TWindowMenu *)window_menu)->is_decided()) != 0) {
                selected_menu_value = ((TWindowMenu *)(*(u8 **)((s8 *)((u8 *)this) + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(4);
                    return;
                case 1:
                    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x24) == 0) {
                        *(s32 *)((s8 *)((u8 *)this) + 0x24) = 1;
                    } else {
                        *(s32 *)((s8 *)((u8 *)this) + 0x24) = 0;
                    }
                    set_state(0xA);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}
void TAdMultiChgGameModeGC::create_back_objects() {
    void *o;
    void *o2;
    if (*(void **)((s8 *)this + 0x28) == NULL) {
        o = __nw__7TObjectFUl(0x24);
        if (o != NULL) {
            o = __ct__9TAdBackGCFv(o, this);
        }
        *(void **)((s8 *)this + 0x28) = o;
    }
    if (*(void **)((s8 *)this + 0x2C) == NULL) {
        o2 = __nw__7TObjectFUl(0x28);
        if (o2 != NULL) {
            o2 = __ct__12TAdBackTxtGCFv(o2, this);
        }
        *(void **)((s8 *)this + 0x2C) = o2;
    }
}
void TAdMultiChgGameModeGC__sub_8036E51C(u8 *ad_multi_chg_game_mode_gc) {
    if ((u32) *(u32 *)((s8 *)ad_multi_chg_game_mode_gc + 0x34) != 0U) {
        ((TWindowBase *)((void*)(*(void **)((s8 *)ad_multi_chg_game_mode_gc + 0x34))))->close();
        *(u32 *)((s8 *)ad_multi_chg_game_mode_gc + 0x34) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(ad_multi_chg_game_mode_gc, 1);
    TAdMultiChgGameModeGC__sub_8036E19C(ad_multi_chg_game_mode_gc, 4);
    if ((u32) *(u32 *)((s8 *)ad_multi_chg_game_mode_gc + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)ad_multi_chg_game_mode_gc + 0x30)))->append_line((s32)((int) (TAdMultiChgGameModeGC__sub_8036DE10((s32)ad_multi_chg_game_mode_gc, 0, (s32)((s32)((int) (*(s32 *)((s8 *)ad_multi_chg_game_mode_gc + 0x24))))))), 3);
    }
    ((TAdMultiChgGameModeGC *)ad_multi_chg_game_mode_gc)->create_back_objects();
}
void TAdMultiChgGameModeGC::update_mode_selection() {
    s32 arg0 = (s32)this;
    if ((handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        set_state(2);
    }
}
void TAdMultiChgGameModeGC::load_system_on_mode_default() { if (handle_mode_selection() == 0) { load_system_file((s32)((void*)0)); } }
s32 TAdMultiChgGameModeGC::handle_mode_selection() {
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)this + 0x20);
    if (temp_r4 & 1) {
        set_state(9);
        return 1;
    }
    if (temp_r4 & 2) {
        return 0;
    }
    if (temp_r4 & 4) {
        set_state(9);
        return 1;
    }
    if (temp_r4 & 8) {
        set_state(9);
        return 1;
    }
    return 0;
}
void TAdMultiChgGameModeGC__sub_8036E6A0(s32 arg0) {
    if ((((TAdMultiChgGameModeGC *)arg0)->handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        ((TAdMultiChgGameModeGC *)arg0)->set_state(8);
    }
}
void TAdMultiChgGameModeGC__sub_8036E6EC(void) {  }
void TAdMultiChgGameModeGC::update_mode_selection_and_save() {
    s32 arg0 = (s32)this;
    if (((int)handle_mode_selection()) == 0) {
        refresh_char_slots__23TAdSinglePlyChrSelectGCFv();
        if (encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv() != 0) {
            set_state((s32)((s32)((void*)(7))));
            return;
        }
        set_state((s32)((s32)((void*)(8))));
    }
}
void TAdMultiChgGameModeGC__sub_8036E750(void) {  }

void TAdMultiChgGameModeGC::check_player_load_result() {
    if (handle_mode_selection() != 0) {
        return;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return;
    }
    switch (TAdPlayerLoadGC__sub_801FD770()) {
    case 5:
        if (all_players_loaded__23TAdSinglePlyChrSelectGCFv() != 0) {
            set_state(3);
        } else {
            set_state(8);
        }
        break;
    default:
        set_state(8);
        break;
    }
}

void update_mode_selection__21TAdMultiChgGameModeGCFPv(void *self) {
    if (((TAdMultiChgGameModeGC *)self)->handle_mode_selection() != 0) {
        return;
    }
    if (load_system_file_flag__23TAdSinglePlyChrSelectGCFv() == 0xFFFFFF05) {
        return;
    }
}

int TAdMultiChgGameModeGC::request_scene_change_vt() { return request_scene_change__21TAdMultiChgGameModeGCFv(this); }
void TAdMultiChgGameModeGC__sub_8036E830(void) {  }
int init_change_mode__21TAdMultiChgGameModeGCFPv(void* p) { return init_change_mode__21TAdMultiChgGameModeGCFv(p); }
void TAdMultiChgGameModeGC__sub_8036E854(void) {  }

typedef char MemberActionStorage_8036E858_size[sizeof(MemberActionStorage_8036E858) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8036E858_lbl_804F3908_size[sizeof(RecoveredGlobal_8036E858_lbl_804F3908) == 0x108 ? 1 : -1];
void TAdMultiChgGameModeGC::set_state(s32 arg1) {
    MemberActionStorage_8036E858 member_action;
    typedef char sp8_offset[(offsetof(Stack_8036E858, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8036E858, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8036E858, sp10) == 0x8) ? 1 : -1];
    Stack_8036E858 stack;
    u8 *temp_r6;
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x1C) != arg1) {
        *(s32 *)((s8 *)((u8 *)this) + 0x1C) = arg1;
        temp_r6 = (u8 *)&(*(RecoveredGlobal_8036E858_lbl_804F3908 *)&multi_chg_game_mode_entry_table).value + (*(s32 *)((s8 *)((u8 *)this) + 0x1C) * 0x18);
        member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0);
        member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 4);
        member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 8);
        if (member_action.action != 0) {
            (this->*member_action.action)();
        }
    }
}

s32 check_system_file_status__23TAdSinglePlyChrSelectGCFv(void) {
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        return 1;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        return 2;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        return 4;
    }
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 4;
    }
    if ((TAdPlayerLoadGC::find_card_file(0, (const char *)&lbl_804C88C0.value) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)((const char *)&lbl_804C89BC.value)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)((const char *)&pso_system_card_filename.value)) != 0)) {
        return 8;
    }
    return 0;
}

void TAdMultiChgGameModeGC::confirm_mode_selection() { if (((int)handle_mode_selection()) == 0) { set_state((s32)((s32)((void*)((void*)1)))); } }
void TAdMultiChgGameModeGC__sub_8036E9EC(void* p) { ((TAdMultiChgGameModeGC *)p)->close_window_30(); TAdMultiChgGameModeGC__sub_8036E19C((u8 *)p, (s32)((s32)((void*)4))); }

typedef char MemberActionStorage_8036EA24_size[sizeof(MemberActionStorage_8036EA24) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8036EA24_lbl_804F3908_size[sizeof(RecoveredGlobal_8036EA24_lbl_804F3908) == 0x108 ? 1 : -1];
void TUnk_804F3A20::run_task() {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_8036EA24 member_action;
    typedef char sp8_offset[(offsetof(Stack_8036EA24, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8036EA24, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8036EA24, sp10) == 0x8) ? 1 : -1];
    Stack_8036EA24 stack;
    u8 *temp_r6;
    this->m_20 = check_system_file_status__23TAdSinglePlyChrSelectGCFv();
    if (this->m_20 & 1) {
        ((TAdMultiChgGameModeGC *)arg0)->set_state(9);
    }
    temp_r6 = (u8 *)&multi_chg_game_mode_entry_table.value + (*(s32 *)&this->unk_1C * 0x18);
    member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0xC);
    member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 0x10);
    member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 0x14);
    if (member_action.action != 0) {
        (((TAdMultiChgGameModeGC *)(arg0))->*member_action.action)();
    }
}

TUnk_804F3A20::~TUnk_804F3A20() {
    if (*(void **)((s8 *)this + 0x30) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x30)); this->m_30 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x34)); *(s32 *)((s8 *)this + 0x34) = 0; }
}

TUnk_804F3A20::TUnk_804F3A20(TObject *object) : TObject(object) {
    *(s32 *)((s8 *)this + 0x1C) = -1;
    this->m_20 = 1;
    *(s32 *)((s8 *)this + 0x24) = current_language;
    this->m_30 = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    this->m_28 = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    this->m_20 = ((s32 (*)(void *))check_system_file_status__23TAdSinglePlyChrSelectGCFv)(this);
    if (this->m_20 & 1) {
        ((TAdMultiChgGameModeGC *)this)->set_state(0);
    } else {
        ((TAdMultiChgGameModeGC *)this)->set_state(1);
    }
    TLobby::stop_audio_streams();
    TKeyBoardControl__sub_8000F90C(9);
}
