#include "pso/TSaveChCr.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TSaveChCr_8033A088.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "types.h"

#include <stddef.h>
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

#include "pso/TChCrCharSelect.h"

struct RecoveredGlobal_8033A34C___vt__9TSaveChCr {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void *__nw__7TObjectFUl(int);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8033A34C___vt__9TSaveChCr __vt__9TSaveChCr;
extern s32 TSaveChCr__name;
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32 arg0);
int begin_action_from_char_select__10TObjPlayerFv(void*);

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

int TSaveChCr__sub_8033A138(void) { return load_character_from_card__23TAdSinglePlyChrSelectGCFi(0); }
void TSaveChCr::save_character() { begin_action_from_char_select__10TObjPlayerFv(this); load_character_from_card__23TAdSinglePlyChrSelectGCFi((s32)((void*)1)); }

extern void *tl_03;

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

typedef char RecoveredGlobal_8033A34C___vt__9TSaveChCr_size[sizeof(RecoveredGlobal_8033A34C___vt__9TSaveChCr) == 0x18 ? 1 : -1];

u8 *TSaveChCr__ct(TSaveChCr *save_ch_cr, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(save_ch_cr, arg1);
    *(s32 **)((s8 *)save_ch_cr + 0x18) = &__vt__9TSaveChCr.value;
    *(s32 *)((s8 *)save_ch_cr + 0) = (s32) TSaveChCr__name;
    *(s32 *)((s8 *)save_ch_cr + 0x20) = arg2;
    ((TSaveChCr *)save_ch_cr)->m_24 = 0;
    ((TSaveChCr *)save_ch_cr)->m_28 = 0;
    ((TSaveChCr *)save_ch_cr)->card_status = save_ch_cr->poll_memcard_status();
    *(s32 *)((s8 *)save_ch_cr + 0x3C) = 0;
    ((TSaveChCr *)save_ch_cr)->timer = 0;
    save_ch_cr->create_backgrounds();
    save_ch_cr->set_state(0);
    return (u8 *)save_ch_cr;
}

void *TSaveChCr::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x40);
    if (o != NULL) {
        o = TSaveChCr__ct((TSaveChCr *)((u8 *)o), (u8 *)tl_03, (s32)arg0);
    }
    return o;
}
