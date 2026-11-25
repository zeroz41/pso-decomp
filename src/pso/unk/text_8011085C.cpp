#include "types.h"
#include "pso/unk/text_8011085C.h"

void fn_8011085C(u8 *ctrl, s32 index) {
    s32 (*callback)(s32);
    s32 count;
    saddr counts;
    s32 offset;
    if (index < (s32) *(s32 *)((s8 *)ctrl + 0x1C)) {
        counts = *(s32 *)((s8 *)ctrl + 0x20);
        offset = index * 4;
        count = *(s32 *)((s8 *)counts + offset);
        if (count != 0) {
            *(s32 *)((s8 *)counts + offset) = count - 1;
            if ((s32) *(s32 *)((s8 *)(*(saddr *)((s8 *)ctrl + 0x20)) + offset) == 0) {
                callback = *(s32 (**)(s32))((s8 *)ctrl + 0x28);
                if (callback != NULL) {
                    callback(index);
                }
            }
        }
    }
}
void fn_801108C8(u8 *ctrl, s32 index) {
    s32 (*callback)(s32);
    s32 offset;
    saddr counts;
    if (index < (s32) *(s32 *)((s8 *)ctrl + 0x1C)) {
        offset = index * 4;
        if ((s32) *(s32 *)((s8 *)(*(saddr *)((s8 *)ctrl + 0x20)) + offset) == 0) {
            callback = *(s32 (**)(s32))((s8 *)ctrl + 0x24);
            if (callback != NULL) {
                callback(index);
            }
        }
        counts = *(s32 *)((s8 *)ctrl + 0x20);
        *(s32 *)((s8 *)counts + offset) = *(s32 *)((s8 *)counts + offset) + 1;
    }
}
