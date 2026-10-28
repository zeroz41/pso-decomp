#include "types.h"
#include "pso/unk/text_80121FBC.h"

extern "C" {
u8 * belra_cannon_ct(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_belra_cannon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(belra_cannon_ct(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
