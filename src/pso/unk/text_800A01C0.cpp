#include "types.h"
#include "pso/enemy/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Stack_800A01C0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

extern "C" {
s32 draw_line_list(void *, int, int);
void TObjEneMe1Canadin_EffLineFade::render() {
    s32 arg0 = (s32)this;
    Stack_800A01C0 stack;
    stack.sp8 = arg0 + 0x1C;
    stack.spC = arg0 + 0x34;
    stack.sp10 = 0;
    stack.sp14 = 2;
    set_additive_blend();
    draw_line_list(&stack.sp8, 1, 5);
}

}
