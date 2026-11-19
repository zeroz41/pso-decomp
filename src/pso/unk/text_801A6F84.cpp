#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_801A57C4.h"
struct InputRepeatRecord {u8 unused[0x2c];s16 heldTicks[14];u32 held,pressed;};

struct S_801A6F84 { u8 pad[0x2C]; s16 v[14]; };

extern "C" {
s32 input_press_or_repeat(InputRepeatRecord* input,u32 mask,s32 delay,s32 period);
s32 check_packed_flag_match(S_801A6F84 *arg0, u32 arg1, s32 arg2, s32 arg3);

s32 check_packed_flag_match(S_801A6F84 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 r;
    s32 i;
    s32 d;
    if (arg1 == 0) {
        return 0;
    }
    r = 0;
    for (i = 0; i < 14; i++) {
        if (arg1 & input_button_mask_table[i]) {
            d = arg0->v[i] - (arg2 + 1);
            if (d >= 0 && d % arg3 == 0) {
                r |= 1;
            }
        }
    }
    return r;
}

s32 input_press_or_repeat(InputRepeatRecord* input,u32 mask,s32 delay,s32 period) {
    if(!mask)return 0;
    if(input->pressed&mask)return 1;
    s32 result=0;
    for(int i=0;i<14;++i) {
        if(mask&input_button_mask_table[i]) {
            const s32 elapsed=input->heldTicks[i]-(delay+1);
            if(elapsed>=0&&elapsed%period==0)result|=1;
        }
    }
    return result;
}

}
