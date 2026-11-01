#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_8033BDB0.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"

struct VBase { char pad[0x18]; };

struct VObj : VBase { virtual void m0(int); };

#include <stddef.h>
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TCheckMemoryCard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowOptionCtrl.h"
struct Stack_8033C024 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8033C024 { s32 words[3]; void (TWindowSubComCard::*action)(); };

struct RecoveredGlobal_8033C024_lbl_804EF940 {
    s32 value;
    u8 remaining[0x5C];
};

struct O_8033C1CC { u8 pad[0x34]; void *p; u8 pad2[0x44 - 0x38]; s32 f44; };

extern "C" {
s32 sub_8033BB14__16TCheckMemoryCardFv(void *);
extern RecoveredGlobal_8033C024_lbl_804EF940 lbl_804EF940;
u32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 align_menu_entry_positions(u32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32 *, s32);
u32 create__14TWindowMessageFllUls(s32 *, s32 *, s32, s32);
u32 update_window_mode_from_progress__6TLobbyFPv(s32 *, s32 *);
extern s32 lbl_80477DB4[];
extern s32 lbl_80477DBC[];
extern s32 lbl_804EF8D8[];
extern const f32 lbl_805D6D98;
int update_card_display__17TWindowSubComCardFPvPvPvPv(void*, int, int, int, int);

void TWindowSubComCard::create_message_and_menu(u32 arg1, s32 sel, u32 arg3, u32 arg4) {
    u32 msg;
    if (*(u32 *)((s8 *)this + 0x30) != 0U || *(u32 *)((s8 *)this + 0x34) != 0U) {
        return;
    }
    if (*(s32 *)((s8 *)this + 0x4C) != 0) {
        *(u32 *)((s8 *)this + 0x30) = create__14TWindowMessageFllUls(lbl_80477DB4, lbl_80477DBC, 1, 4);
    } else {
        *(u32 *)((s8 *)this + 0x30) = update_window_mode_from_progress__6TLobbyFPv(lbl_80477DB4, lbl_80477DBC);
    }
    if (*(u32 *)((s8 *)this + 0x30) == 0U) {
        return;
    }
    if (*(u32 *)((s8 *)this + 0x30) != 0U && *(s32 *)((s8 *)this + 0x4C) != 0) {
        ((TWindowSubComCard *)(*(s32 *)((s8 *)this + 0x30)))->reparent_to_main_ctrl();
    }
    if (arg1 != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->append_line(arg1, 3);
    }
    ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->complete_reveal();
    if (sel == -1) {
        return;
    }
    if (*(s32 *)((s8 *)this + 0x4C) != 0) {
        *(u32 *)((s8 *)this + 0x34) = create_window_menu((s32)lbl_804EF8D8, 2, 4);
    } else {
        *(u32 *)((s8 *)this + 0x34) = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_804EF8D8, 2);
    }
    if (*(u32 *)((s8 *)this + 0x30) == 0U) {
        return;
    }
    if (*(u32 *)((s8 *)this + 0x34) != 0U && *(s32 *)((s8 *)this + 0x4C) != 0) {
        ((TWindowSubComCard *)(*(s32 *)((s8 *)this + 0x34)))->reparent_to_main_ctrl();
    }
    msg = arg3;
    if (arg3 == 0U) {
        msg = get_message_10__20TWindowSubStatusDispFl(0x5B);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x34)), (int)msg, 5, 0);
    if (sel != -2) {
        msg = arg4;
        if (arg4 == 0U) {
            msg = get_message_10__20TWindowSubStatusDispFl(0x5C);
        }
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x34)), (int)msg, 5, 1);
    }
    ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0x34)))->update_layout_height(lbl_805D6D98);
    align_menu_entry_positions(*(u32 *)((s8 *)this + 0x34));
    if (sel != -2) {
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0x34)))->set_selected_index(sel);
    } else {
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0x34)))->set_selected_index(0);
    }
    ((TWindowOptionCtrl *)(*(u32 *)((s8 *)this + 0x34)))->clear_flag70_bit4();
}

#pragma push
#pragma fp_contract on
void TWindowSubComCard::close_windows() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *temp_r3_2;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if (temp_r3 != NULL) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4C) != 0) {
            if (temp_r3 != NULL) {
                ((VObj *)temp_r3)->m0(1);
            }
        } else {
            ((TWindowBase *)temp_r3)->close();
        }
        *(u8 **)((s8 *)arg0 + 0x30) = NULL;
        *(s32 *)((s8 *)arg0 + 0x38) = 7;
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
    if (temp_r3_2 != NULL) {
        ((TWindowBase *)temp_r3_2)->close();
        *(u8 **)((s8 *)arg0 + 0x34) = NULL;
        *(s32 *)((s8 *)arg0 + 0x38) = 7;
    }
}
#pragma pop

typedef char MemberActionStorage_8033C024_size[sizeof(MemberActionStorage_8033C024) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8033C024_lbl_804EF940_size[sizeof(RecoveredGlobal_8033C024_lbl_804EF940) == 0x60 ? 1 : -1];
void TWindowSubComCard::set_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_8033C024 member_action;
    typedef char sp8_offset[(offsetof(Stack_8033C024, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8033C024, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8033C024, sp10) == 0x8) ? 1 : -1];
    Stack_8033C024 stack;
    u8 *temp_r6;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x20) != arg1) {
        *(s32 *)((s8 *)arg0 + 0x20) = arg1;
        temp_r6 = (u8 *)&lbl_804EF940.value + (*(s32 *)((s8 *)arg0 + 0x20) * 0x18);
        member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0);
        member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 4);
        member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 8);
        if (member_action.action != 0) {
            (((TWindowSubComCard *)(arg0))->*member_action.action)();
        }
    }
}

void TWindowSubComCard::reset() {
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    *(s32 *)((s8 *)this + 0x24) = 0;
    *(s32 *)((s8 *)this + 0x28) = sub_8033BB14__16TCheckMemoryCardFv(this);
    *(s32 *)((s8 *)this + 0x3C) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0;
    *(s32 *)((s8 *)this + 0x44) = 0;
    set_state(0);
}

void TWindowSubComCard::poll_card_status() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x38) <= 0) {
        *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        *(s32 *)((s8 *)arg0 + 0x28) = sub_8033BB14__16TCheckMemoryCardFv(arg0);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x28) != 0) {
            set_state(1);
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x3C) = 1;
    }
}

void TWindowSubComCard__sub_8033C178(void* p) { ((TWindowSubComCard *)p)->close_windows(); }
void TWindowSubComCard__sub_8033C198(void) {  }
int TWindowSubComCard__sub_8033C19C(void* p) { return update_card_display__17TWindowSubComCardFPvPvPvPv(p, 0, -1, -1, -1); }
void TWindowSubComCard::handle_menu_selection() {
    O_8033C1CC *arg0 = (O_8033C1CC *)this;
    if (arg0->p == 0 || ((TWindowMenu *)(arg0->p))->is_decided() == 0) {
        return;
    }
    switch (((TWindowMenu *)arg0->p)->get_selected_value()) {
    case 0:
        arg0->f44 = 1;
        break;
    }
}

}
