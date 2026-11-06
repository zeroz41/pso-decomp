#include "types.h"
#include "pso/player/TPlySmth.h"
#include "pso/ui/chat/TChatMessage_801DF918.h"
#include "pso/unk/text_801DB998.h"

struct VBase_18_44382c { char pad[0x18]; };

struct VObj_18_44382c : VBase_18_44382c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(u8 *, s32);
};

struct Stack_801DB998 {
    u8 sp8;
    u8 pad_9[0x1];
    s16 spA;
    u8 spC[8];
    s32 sp14;
    u8 pad_18[0x1];
    s8 sp19;
    u8 pad_1A[0x2];
    char sp1C[0x30];
    char sp4C[0x30];
    char sp7C[0x30];
};

extern "C" {
s32 strncpy(void *, void *, int);
s32 memset(void *, int, int);
}
void send_register_9c(u8 *arg0) {
    Stack_801DB998 stack;
    fn_801DF954((&stack.sp8));
    memset(&stack.sp8, 0, 0xA4);
    stack.sp8 = 0x9C;
    stack.spA = 0xA4;
    __as__8TPlySmthFRC8TPlySmth((s32)&stack.spC, (s32)(arg0 + 0x18F8));
    stack.sp14 = (s32) *(u16 *)((s8 *)arg0 + 0x1908);
    stack.sp19 = (s8) *(s32 *)((s8 *)arg0 + 0x1934);
    strncpy(&stack.sp1C, arg0 + 0x3EDA, 0x30);
    strncpy(&stack.sp4C, arg0 + 0x3F0A, 0x30);
    strncpy(&stack.sp7C, arg0 + 0x3F3A, 0x30);
    fn_801DF918((&stack.sp8));
    ((VObj_18_44382c *)(arg0))->m8(&stack.sp8, 0xA4);
}
