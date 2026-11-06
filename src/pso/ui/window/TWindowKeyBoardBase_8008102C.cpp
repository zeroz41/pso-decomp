#include "types.h"
#include "pso/ui/window/TWindowKeyBoardBase_8008102C.h"
#include "pso/system/memory.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
s32 is_split_screen(void);
u8 * TEF_LensFlare__ct(void *, s32, s32);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_05;
void mem_free(void *p);
void *mem_alloc(u32 size);
u32 __cvt_fp2unsigned(f32);
f32 horizontal_distance_squared(s32, s32);
void *get_player_by_client_id(s32 i);
}

void init_keyboard_text_buffer(u8 *arg0, u32 arg1, u32 arg2) {
    s16 *temp_r3;
    u32 temp_r3_2;
    temp_r3 = (s16 *)(*(s16 **)((s8 *)arg0 + 0));
    if (temp_r3 != NULL) {
        mem_free(temp_r3);
    }
    if (arg2 == 0) {
        *(u32 *)((s8 *)arg0 + 0x14) = arg1;
    } else {
        *(u32 *)((s8 *)arg0 + 0x14) = __cvt_fp2unsigned((f32) arg2 * TWindowSubStatusDisp::round_away_from_zero((f32) (arg1 / 6U)));
    }
    temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x14);
    if (temp_r3_2 != 0) {
        *(s16 **)((s8 *)arg0 + 0) = (s16 *)mem_alloc((temp_r3_2 + 1) * 2);
        **(s16 **)((s8 *)arg0 + 0) = 0;
    } else {
        *(s16 **)((s8 *)arg0 + 0) = NULL;
    }
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s32 *)((s8 *)arg0 + 0x10) = 0;
    *(u32 *)((s8 *)arg0 + 8) = arg1;
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) (arg2 * 0x14);
}

u32 *destroy__19TWindowKeyBoardBaseFPvs(u32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if ((u32) *arg0 != 0U) {
            mem_free((void *)(*arg0));
        }
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 local_client_id;

s32 *TWindowKeyBoardBase::init_text_buffer_holder() {
    s32 *arg0 = (s32 *)this;
    *arg0 = 0;
    init_keyboard_text_buffer((u8 *)arg0, (u32)(0U), (u32)(0U));
    return arg0;
}

int TEF_LensFlare::is_player_near(f32 farg0) {
    s32 arg0 = (s32)this;
    u32 player;

    player = (u32)get_player_by_client_id(local_client_id);
    if (player == 0U) {
        return 0;
    }
    return (u32) __cntlzw(horizontal_distance_squared(player + 0x38, arg0 + 0x38) < farg0) >> 5;
}
u8 *TEF_LensFlare__create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x94));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TEF_LensFlare__ct(temp_r3, tl_05, arg0));
    }
    return var_r0;
}
