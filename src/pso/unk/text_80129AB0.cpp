#include "types.h"
#include "pso/unk/text_80129AB0.h"

extern "C" {
u8 * init_s_rank_shot(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_s_rank_shot(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_s_rank_shot(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
