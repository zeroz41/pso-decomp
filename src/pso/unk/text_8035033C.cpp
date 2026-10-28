#include "types.h"
#include "pso/unk/text_8035033C.h"

extern "C" {
void *create_item_object_lbl_804F0C48(void *arg0, void *arg1, void *arg2);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *fn_8035033C(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)create_item_object_lbl_804F0C48((void *)temp_r3, (void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

}
