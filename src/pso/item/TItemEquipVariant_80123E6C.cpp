#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80123E6C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A1E28.h"
#include "pso/item/TItem.h"

void TUnk_804A1E28::update_idle() {
    s16 temp_r0;

    temp_r0 = *(s16 *)((s8 *)this + 0x1FE);
    if ((temp_r0 == 1) || (temp_r0 == 0)) {
        *(s16 *)((s8 *)this + 0x1FE) = 2;
    }
}

void TUnk_804A1E28::update_attack() {
    s16 temp_r0;

    temp_r0 = *(s16 *)&this->unk_1FE;
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
        *(s16 *)&this->unk_1FE = 1;
    }
}

extern s32 lbl_804A1E28[];

void *__dt__13TUnk_804A1E28Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A1E28;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
