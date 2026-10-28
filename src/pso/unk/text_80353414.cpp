#include "types.h"
#include "pso/unk/text_80353414.h"

extern "C" {
void *fn_803533D8(void *arg0, void *arg1, void *arg2);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *fn_80353414(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)fn_803533D8((void *)temp_r3, (void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

}
