#include "types.h"
#include "pso/unk/text_80327338.h"

extern "C" {
u8 * construct_dark_flow(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_dark_flow(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_dark_flow(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
