#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012CA20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/unk/text_8012CB2C.h"

extern s32 lbl_804A5458[];

void *__dt__13TUnk_804A5458Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5458;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

s32 __ct__11TItemWeaponFP7TObjectPUc();

extern s32 lbl_804A5458[];

void *TObjPlayer::construct_weapon_variant(s32 arg1, void *arg2) {

    __ct__11TItemWeaponFP7TObjectPUc();
    *(s32 **)((s8 *)this + 0x18) = lbl_804A5458;
    switch ((s32) (*(u8 *)((s8 *)arg2 + 2))) {
    case 5:
    case 6:
        set_weapon_trail_joints((s32)this, 0, 3, 2);
        break;
    case 4:
        set_weapon_trail_joints((s32)this, 0, 2, 1);
        break;
    default:
        set_weapon_trail_joints((s32)this, 0, 2, 3);
        break;
    }
    if ((u8) *(u8 *)((s8 *)arg2 + 2) >= 4U) {
        set_atp(-1);
    }
    return this;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_rod_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TObjPlayer *)temp_r3)->construct_weapon_variant(tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
