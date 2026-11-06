#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/text_802754EC.h"

extern "C" {
u8 *TWindowSubComCardList__ct(u8 *arg0, void *arg1);
u8 *__nw__7TObjectFUl(s32);
u8 *fn_802754EC(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    fn_80266378(7);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0xA0));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowSubComCardList__ct(temp_r3, (void *)arg0));
    }
    return var_r0;
}

}
