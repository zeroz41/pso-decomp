#include "types.h"
#include "pso/player/TUnk_804A3A20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80128308.h"
#include "pso/item/TItemEquipVariant_80128360.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 lbl_804A3A20[];

void *TUnk_804A3A20::init_mode() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3A20;
    ((TItemWeapon *)this)->set_weapon_flags(1536);
    return this;
}

}

extern "C" {
u8 * init_mode__13TUnk_804A3A20Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_80128308(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_mode__13TUnk_804A3A20Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A3A20[];

void *__dt__13TUnk_804A3A20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3A20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
