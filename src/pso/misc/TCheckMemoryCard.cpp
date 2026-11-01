#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TCheckMemoryCard.h"
#include "pso/misc/TWindowSubComCard_80244774.h"


struct Base_8033C4E0_8033C420 { char pad[0x18]; };
struct VObj_8033C4E0_8033C420 : Base_8033C4E0_8033C420 { virtual void m0(int); };

#include <stddef.h>
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowSubComCard.h"
struct Stack_8033C424 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8033C424 { s32 words[3]; void (TCheckMemoryCard::*action)(); };

struct RecoveredGlobal_8033C424_lbl_804EF940 {
    s32 value;
    u8 remaining[0x5C];
};

extern RecoveredGlobal_8033C424_lbl_804EF940 lbl_804EF940;

extern "C" {

void *__ct__16TCheckMemoryCardFP7TObjectPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
void *__nw__7TObjectFUl(int);

void TCheckMemoryCard::render() {  }


typedef char MemberActionStorage_8033C424_size[sizeof(MemberActionStorage_8033C424) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8033C424_lbl_804EF940_size[sizeof(RecoveredGlobal_8033C424_lbl_804EF940) == 0x60 ? 1 : -1];
void TCheckMemoryCard::run_task() {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_8033C424 member_action;
    typedef char sp8_offset[(offsetof(Stack_8033C424, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8033C424, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8033C424, sp10) == 0x8) ? 1 : -1];
    Stack_8033C424 stack;
    u8 *temp_r6;
    this->m_3c = 0;
    this->m_28 = ((TCheckMemoryCard *)arg0)->sub_8033BB14();
    if (this->m_28 & 1) {
        ((TWindowSubComCard *)arg0)->set_state(0);
    }
    temp_r6 = (u8 *)&lbl_804EF940.value + (this->m_20 * 0x18);
    member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0xC);
    member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 0x10);
    member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 0x14);
    if (member_action.action != 0) {
        (((TCheckMemoryCard *)(arg0))->*member_action.action)();
    }
    this->m_38 = (this->m_38 - 1);
    if ((s32) this->m_38 < 0) {
        this->m_38 = 0;
    }
}

}
TCheckMemoryCard::~TCheckMemoryCard() {
    void *temp_r3;
    temp_r3 = this->m_30;
    if (temp_r3 != NULL) {
        if (temp_r3 != NULL) {
            ((VObj_8033C4E0_8033C420 *)temp_r3)->m0(1);
        }
        this->m_30 = NULL;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
}
extern void *TCheckMemoryCard__name;
TCheckMemoryCard::TCheckMemoryCard(TObject *object, void *arg2, void *arg3, void *arg4) : TObject(object) {
    *(void * *)&this->m_name = TCheckMemoryCard__name;
    *(void **)((s8 *)this + 0x48) = arg2;
    *(void **)((s8 *)this + 0x1C) = arg4;
    *(void **)((s8 *)this + 0x4C) = arg3;
    ((TWindowSubComCard *)this)->reset();
}

void *TCheckMemoryCard::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x250);
    if (o != NULL) {
        o = __ct__16TCheckMemoryCardFP7TObjectPvPvPv(o, this, arg1, arg2, (void *)(1));
    }
    return o;
}
