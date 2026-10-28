#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_803083B0.h"
#include "pso/player/TUnk_804E71F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804E71F8[];

void *TUnk_804E71F8::construct_nug2000_bazooka(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E71F8;
    set_weapon_flags(2);
    return this;
}
u8 *TObjPlayer::create_nug2000_bazooka() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804E71F8 *)temp_r3)->construct_nug2000_bazooka(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void *__dt__13TUnk_804E71F8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E71F8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
