#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80352AC0.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void TItemObject__ct(void *);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);

extern s32 lbl_804F0FF0[];

void *__dt__13TUnk_804F0FF0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F0FF0;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TItemObject__sub_80352B18(void *item) {
    TItemObject__ct(item);
    *(s32 **)((s8 *)item + 0x18) = lbl_804F0FF0;
    ((TItem *)item)->clear_item_flags(16);
    return item;
}

}
