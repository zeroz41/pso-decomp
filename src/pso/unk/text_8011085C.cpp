#include "types.h"
#include "pso/unk/text_8011085C.h"

void fn_8011085C(u8 *ctrl, s32 arg1) {
    s32 (*temp_r12)(s32);
    s32 temp_r5;
    saddr temp_r6;
    s32 temp_r7;
    if (arg1 < (s32) *(s32 *)((s8 *)ctrl + 0x1C)) {
        temp_r6 = *(s32 *)((s8 *)ctrl + 0x20);
        temp_r7 = arg1 * 4;
        temp_r5 = *(s32 *)((s8 *)temp_r6 + temp_r7);
        if (temp_r5 != 0) {
            *(s32 *)((s8 *)temp_r6 + temp_r7) = temp_r5 - 1;
            if ((s32) *(s32 *)((s8 *)(*(saddr *)((s8 *)ctrl + 0x20)) + temp_r7) == 0) {
                temp_r12 = *(s32 (**)(s32))((s8 *)ctrl + 0x28);
                if (temp_r12 != NULL) {
                    temp_r12(arg1);
                }
            }
        }
    }
}
void fn_801108C8(u8 *ctrl, s32 arg1) {
    s32 (*temp_r12)(s32);
    s32 temp_r31;
    saddr temp_r4;
    if (arg1 < (s32) *(s32 *)((s8 *)ctrl + 0x1C)) {
        temp_r31 = arg1 * 4;
        if ((s32) *(s32 *)((s8 *)(*(saddr *)((s8 *)ctrl + 0x20)) + temp_r31) == 0) {
            temp_r12 = *(s32 (**)(s32))((s8 *)ctrl + 0x24);
            if (temp_r12 != NULL) {
                temp_r12(arg1);
            }
        }
        temp_r4 = *(s32 *)((s8 *)ctrl + 0x20);
        *(s32 *)((s8 *)temp_r4 + temp_r31) = *(s32 *)((s8 *)temp_r4 + temp_r31) + 1;
    }
}
