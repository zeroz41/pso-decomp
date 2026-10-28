#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 * init_trade_action__13TUnk_804A535CFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_trade_action_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x214));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_trade_action__13TUnk_804A535CFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
