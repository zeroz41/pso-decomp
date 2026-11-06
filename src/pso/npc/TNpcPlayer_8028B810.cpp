#include "types.h"
#include "pso/npc/TNpcPlayer_8028B810.h"

#include <stddef.h>
struct Stack_8028B810 {
    u8 * sp8;
    u8 * spC;
    s32 sp10;
    u8 * sp14;
    u8 * sp18;
    u8 * sp1C;
    u8 * sp20;
    u8 * sp24;
};

void *create_ch_cr_load_req(void *arg0, void *arg1);
extern "C" {
s32 copy_player_visual_record(void *, void *);
s32 TCharaMaking__bind_appearance_texture_lists(void *, void *, void *, void *);

u8 *init_appearance_load_request__10TNpcPlayerFPvPvii(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    typedef char sp8_offset[(offsetof(Stack_8028B810, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8028B810, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8028B810, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8028B810, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8028B810, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8028B810, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_8028B810, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_8028B810, sp24) == 0x1C) ? 1 : -1];
    Stack_8028B810 stack;
    copy_player_visual_record(arg0 + 4, (void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x4A8) = 0xFF;
    TCharaMaking__bind_appearance_texture_lists(arg0 + 0x54, arg0 + 0x1C0, arg0 + 0x32C, arg0 + 4);
    stack.sp8 = (arg0 + 4);
    stack.spC = (arg0 + 0x4A8);
    stack.sp10 = arg3;
    stack.sp14 = (arg0 + 0x4A4);
    stack.sp18 = (arg0 + 0x498);
    stack.sp1C = (arg0 + 0x490);
    stack.sp20 = (arg0 + 0x324);
    stack.sp24 = (arg0 + 0x1B8);
    *(u8 **)((s8 *)arg0 + 0) = (u8 *)create_ch_cr_load_req(arg1, &stack.sp8);
    return arg0;
}
}
