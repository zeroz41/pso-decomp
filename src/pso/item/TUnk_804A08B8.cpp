#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A08B8.h"

extern s32 lbl_804A08B8[];

void *__dt__13TUnk_804A08B8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A08B8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A08B8::init_vtable_804A08B8() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A08B8;
    return this;
}

}
