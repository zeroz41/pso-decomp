#include "types.h"
#include "pso/player/TObjPlayer_80125550.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/item/TItemAttackCol.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__13TUnk_804A2548[];

void *__dt__13TUnk_804A2548Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804A2548;
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
