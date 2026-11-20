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

u8 *init_appearance_load_request__10TNpcPlayerFPvPvii(u8 *arg0, u8 *parent, s32 arg2, s32 arg3) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8028B810, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8028B810, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8028B810, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_8028B810, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_8028B810, sp18) == 0x10);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_8028B810, sp1C) == 0x14);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_8028B810, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_8028B810, sp24) == 0x1C);
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
    *(u8 **)((s8 *)arg0 + 0) = (u8 *)create_ch_cr_load_req(parent, &stack.sp8);
    return arg0;
}
}
