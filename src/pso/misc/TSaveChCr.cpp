#include "types.h"
#include "pso/TSaveChCr.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/menu/CreationInput.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/TChCrCharSelect.h"

#include <stddef.h>

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_20 { u8 bytes[0x20]; };

struct RecoveredGlobal_80339F98_lbl_80477CBC {
    s32 value;
    u8 remaining[0x20];
};

struct Stack_8033A184 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8033A184 { s32 words[3]; void (TSaveChCr::*action)(); };

struct RecoveredGlobal_8033A184_lbl_804EF658 {
    s32 value;
    u8 remaining[0x74];
};

extern TSaveChCrStateActions lbl_804EF658[];

extern "C" {
int close_and_advance__9TSaveChCrFPv(void*, int);
extern s32 lbl_804C88C0[];
extern s32 pso_system_card_filename[];
extern s32 lbl_804C89BC[];
void *__nw__7TObjectFUl(int);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
extern RecoveredGlobal_80339F98_lbl_80477CBC TSaveChCr__message_text_ids;
u32 update_window_mode_from_progress__6TLobbyFPv(s32 *, s32 *);
extern s32 lbl_80477CAC[];
extern s32 lbl_80477CB4[];
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 poll_memcard_status__23TAdSinglePlyChrSelectGCFv();
extern const char *TSaveChCr__name;
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32 arg0);
int begin_action_from_char_select__10TObjPlayerFv(void*);
extern void *tl_03;
}

void TSaveChCr::destroy_if_keyboard_idle() { if (this->timer == 0) { queue_destruction__7TObjectFv(this); request_queued_main_phase(); } }
void TSaveChCr::sub_80339B94() { close_window(); }
void TSaveChCr::save_if_dirty() { if (sub_80339F30() != 0) { set_state((s32)((void*)4)); } }
void TSaveChCr::close_and_advance_to_3() { close_and_advance__9TSaveChCrFPv(this, 3); }
void TSaveChCr::update_save_status() {
    s32 var_r3;

    if ((s32) this->timer <= 0) {
        this->m_28 = 0;
        this->card_status = poll_memcard_status();
        if ((s32) this->card_status != 0) {
            set_state((s32)((void*)(1)));
            return;
        }
        if (this->mode == 0) {
            var_r3 = save_character();
        } else {
            var_r3 = sub_8033A138();
        }
        if (var_r3 == 7) {
            set_state((s32)((void*)(4)));
            return;
        }
        queue_destruction__7TObjectFv((this));
        TKeyBoardControl__sub_8000F9CC(9);
    }
}
void TSaveChCr::close_and_advance_step2() { close_and_advance__9TSaveChCrFPv(this, 2); }
void TSaveChCr::sub_80339CE4() {}
void TSaveChCr::save_1() { close_and_advance__9TSaveChCrFPv(this, 1); }
void TSaveChCr::update_save_state() {
    s32 temp_r4;

    temp_r4 = this->card_status;
    if (!(temp_r4 & 2)) {
        if (temp_r4 & 1) {
            if ((u32) this->owned_window == 0U) {
                close_and_advance__9TSaveChCrFPv(this, 0);
            }
        } else {
            if (temp_r4 & 4) {
                set_state((s32)((void*)(1)));
                return;
            }
            if (temp_r4 == 0) {
                set_state((s32)((void*)(2)));
            }
        }
    }
}
void TSaveChCr::fn_80339D78() {
    close_window();
    if (card_status & 1) {
        close_and_advance__9TSaveChCrFPv(this, 0);
    }
}
s32 TSaveChCr::sub_80339DBC() {
    if ((TAdPlayerLoadGC::find_card_file(0, (const char *)(pso_system_card_filename)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)(lbl_804C88C0)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)(lbl_804C89BC)) != 0)) {
        return 0;
    }
    return 1;
}

s32 TSaveChCr::poll_memcard_status() {
    s32 var_r31;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        this->m_28 = 0;
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        this->m_28 = 0;
        return 4;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        this->m_24 = (this->m_24 + 1);
        this->m_28 = 0;
        return 2;
    }
    this->m_24 = 0;
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        this->m_28 = 0;
        return 4;
    }
    if ((s32) this->m_28 != 0) {
        return this->card_status;
    }
    var_r31 = 0;
    this->m_28 = 1;
    if (poll_memcard_status__23TAdSinglePlyChrSelectGCFv() == 0) {
        var_r31 |= 4;
    }
    if (sub_80339DBC() == 0) {
        var_r31 |= 4;
    }
    return var_r31;
}

s32 TSaveChCr::sub_80339F30() {
    return creation_buttons_pressed(4) ? 1 : 0;
}

void TSaveChCr::close_and_advance(void* a1) { close_window(); set_message_by_index((s32)a1); }
typedef char RecoveredGlobal_80339F98_lbl_80477CBC_size[sizeof(RecoveredGlobal_80339F98_lbl_80477CBC) == 0x24 ? 1 : -1];
void TSaveChCr::set_message_by_index(s32 arg1) {
    s32 arg0 = (s32)this;
    ByteBlock_20 sp8;
    u8 *temp_r4;
    sp8 = *(const ByteBlock_20 *)((s32) ((u8 *)&TSaveChCr__message_text_ids.value + -4) + 4);
    temp_r4 = (u8 *)&sp8 + (arg1 * 8);
    open_message_window((u32)((int) (get_localized_text_entry(*(s32 *)((s8 *)temp_r4 + 0), *(s32 *)((s8 *)temp_r4 + 4)))));
}
void TSaveChCr::open_message_window(u32 arg1) {
    if ((u32) this->owned_window == 0U) {
        *(u32 *)&this->owned_window = update_window_mode_from_progress__6TLobbyFPv(lbl_80477CAC, lbl_80477CB4);
        if ((u32) this->owned_window != 0U) {
            if (arg1 != 0U) {
                ((TWindowMessage *)(this->owned_window))->append_line(arg1, 3);
            }
            ((TWindowMessage *)(this->owned_window))->complete_reveal();
        }
    }
}

void TSaveChCr::close_window() {
    if ((u32) *(u32 *)((s8 *)this + 0x3C) != 0U) {
        ((TWindowBase *)this->owned_window)->close();
        *(u32 *)((s8 *)this + 0x3C) = 0U;
        this->timer = 7;
    }
}

void TSaveChCr::create_backgrounds() {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = __ct__9TAdBackGCFv(o, this);
    }
    *(void **)((s8 *)this + 0x30) = o;
    o2 = __nw__7TObjectFUl(0x28);
    if (o2 != NULL) {
        o2 = __ct__12TAdBackTxtGCFv(o2, this);
    }
    this->m_34 = o2;
}

s32 TSaveChCr::sub_8033A138() { return load_character_from_card__23TAdSinglePlyChrSelectGCFi(0); }
s32 TSaveChCr::save_character() {
    begin_action_from_char_select__10TObjPlayerFv(this);
    return load_character_from_card__23TAdSinglePlyChrSelectGCFi(1);
}

typedef char MemberActionStorage_8033A184_size[sizeof(MemberActionStorage_8033A184) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8033A184_lbl_804EF658_size[sizeof(RecoveredGlobal_8033A184_lbl_804EF658) == 0x78 ? 1 : -1];
void TSaveChCr::set_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_8033A184 member_action;
    typedef char sp8_offset[(offsetof(Stack_8033A184, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8033A184, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8033A184, sp10) == 0x8) ? 1 : -1];
    Stack_8033A184 stack;
    u8 *temp_r6;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) != arg1) {
        *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
        temp_r6 = (u8 *)&(*(RecoveredGlobal_8033A184_lbl_804EF658 *)&lbl_804EF658).value + (*(s32 *)((s8 *)arg0 + 0x1C) * 0x18);
        member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0);
        member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 4);
        member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 8);
        if (member_action.action != 0) {
            (((TSaveChCr *)(arg0))->*member_action.action)();
        }
    }
}

#pragma opt_common_subs off
void TSaveChCr::run_task() {
  TSaveChCrStateActions *entry;
  TChCrCharSelect::reset_proportions();
  card_status = poll_memcard_status();
  if (card_status & 1)
  {
    set_state(0);
  }
  entry = &lbl_804EF658[state_index];
  TSaveChCrStateAction action = (*entry).task;
  if (action != 0)
  {
    (this->*action)();
  }
  --timer;
  if (timer < 0)
  {
    timer = 0;
  }
}
#pragma opt_common_subs reset

TSaveChCr::~TSaveChCr() {
    if (owned_window != NULL) {
        delete owned_window;
        owned_window = NULL;
    }
}

TSaveChCr::TSaveChCr(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TSaveChCr__name;
    this->mode = mode;
    m_24 = 0;
    m_28 = 0;
    card_status = poll_memcard_status();
    owned_window = NULL;
    timer = 0;
    create_backgrounds();
    set_state(0);
}

void *TSaveChCr::create(void *arg0) {
    return new TSaveChCr((TObject *)tl_03, (s32)arg0);
}

// Per-state actions of TSaveChCr: the first runs when set_state enters the
// state, the task runs every frame from run_task.
TSaveChCrStateActions lbl_804EF658[5] = {
    {&TSaveChCr::fn_80339D78, &TSaveChCr::update_save_state},
    {&TSaveChCr::save_1, &TSaveChCr::sub_80339CE4},
    {&TSaveChCr::close_and_advance_step2, &TSaveChCr::update_save_status},
    {&TSaveChCr::close_and_advance_to_3, &TSaveChCr::save_if_dirty},
    {&TSaveChCr::sub_80339B94, &TSaveChCr::destroy_if_keyboard_idle},
};
