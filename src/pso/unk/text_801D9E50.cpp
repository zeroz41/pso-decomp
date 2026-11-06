#include "types.h"
#include "pso/unk/text_801D9E50.h"
#include "pso/network/protocol/protocol.h"

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
    virtual s32 m8(s8 *, s32);
};

struct Stack_801D9E50 {
    s8 sp8;
    s8 sp9;
    s16 spA;
};

void send_keepalive(u8 *arg0) {
    Stack_801D9E50 stack;
    stack.sp8 = 0x1D;
    stack.sp9 = 0;
    stack.spA = 4;
    ((packet_header *)((s32) &stack.sp8))->bswap();
    ((VObj_18_44382c *)(arg0))->m8(&stack.sp8, 4);
}
