#include "types.h"
#include "pso/ui/window/TWindowKeyBoardSoft_803E6610.h"

#include <stddef.h>
#include "pso/ui/window/TWindowKeyBoardSoft.h"
struct Stack_803E68D0 {
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
};

struct Req_803E669C { s32 id; s32 a; s32 b; };

struct Req_803E6704 { s32 id; s32 a; s32 b; };

struct Req_803E6738 { s32 id; s32 a; s32 b; };

struct Req_803E676C { s32 id; s32 a; s32 b; };

struct Req_803E6668 { s32 id; s32 a; s32 b; };

struct Req_803E66D0 { s32 id; s32 a; s32 b; };

struct Req_803E67D4 { s32 id; s32 a; s32 b; };

struct Req_803E67A0 { s32 id; s32 a; s32 b; };

struct Req_803E6808 { s32 id; s32 a; s32 b; };

struct Req_803E6908 { s32 id; s32 a; s32 b; };

struct Req_803E693C { s32 id; s32 a; s32 b; };

struct Req_803E689C { s32 id; s32 a; s32 b; };

struct Req_803E6868 { s32 id; s32 a; s32 b; };
typedef s32 (*Fn_803E6610)(void *);
struct S_803E6610 { s32 idx; s32 rest; };

extern Fn_803E6610 keyboard_soft_dispatch_fn_table[];
s32 TWindowKeyBoardSoft::dispatch_by_index() {
    S_803E6610 *arg0 = (S_803E6610 *)this;
    s32 i = arg0->idx;
    void *rest = &arg0->rest;
    if (i <= 0 || (u32)i > 0x3F) {
        return -1;
    }
    return keyboard_soft_dispatch_fn_table[i - 1](rest);
}

void TWindowKeyBoardSoft::dispatch_request_0x28(s32 a, s32 b) {
    Req_803E6668 req;
    req.id = 0x28;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x27(s32 a, s32 b) {
    Req_803E669C req;
    req.id = 0x27;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x26(s32 a, s32 b) {
    Req_803E66D0 req;
    req.id = 0x26;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x25(s32 a, s32 b) {
    Req_803E6704 req;
    req.id = 0x25;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x24(s32 a, s32 b) {
    Req_803E6738 req;
    req.id = 0x24;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x23(s32 a, s32 b) {
    Req_803E676C req;
    req.id = 0x23;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x22(s32 a, s32 b) {
    Req_803E67A0 req;
    req.id = 0x22;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft__sub_803E67D4(s32 a, s32 b) {
    Req_803E67D4 req;
    req.id = 0x21;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x20(s32 a, s32 b) {
    Req_803E6808 req;
    req.id = 0x20;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x1c() {
    s32 sp8;
    sp8 = 0x1C;
    ((TWindowKeyBoardSoft *)(&sp8))->dispatch_by_index();
}

void TWindowKeyBoardSoft__sub_803E6868(s32 a, s32 b) {
    Req_803E6868 req;
    req.id = 0x15;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x14(s32 a, s32 b) {
    Req_803E689C req;
    req.id = 0x14;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x13(s32 arg0, s32 arg1, s32 arg2) {
    typedef char sp14_offset[(offsetof(Stack_803E68D0, sp14) == 0x0) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_803E68D0, sp18) == 0x4) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_803E68D0, sp1C) == 0x8) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_803E68D0, sp20) == 0xC) ? 1 : -1];
    Stack_803E68D0 stack;
    stack.sp14 = 0x13;
    stack.sp18 = arg0;
    stack.sp1C = arg1;
    stack.sp20 = arg2;
    ((TWindowKeyBoardSoft *)(&stack.sp14))->dispatch_by_index();
}
void TWindowKeyBoardSoft::dispatch_request_0x10(s32 a, s32 b) {
    Req_803E6908 req;
    req.id = 0x10;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}
void TWindowKeyBoardSoft::dispatch_request_0f(s32 a, s32 b) {
    Req_803E693C req;
    req.id = 0xf;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}
