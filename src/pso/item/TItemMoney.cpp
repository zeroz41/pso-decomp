#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMoney.h"
#include "pso/player/TObjPlayer.h"

extern s32 __vt__10TItemMoney[];

void *__dt__10TItemMoneyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TItemMoney;
        __dt__5TItemFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
