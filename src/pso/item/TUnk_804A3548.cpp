#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A3548.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/item/TUnk_804A3640.h"
#include "pso/misc/TTecGiZonde.h"

extern "C" {


void TObjPlayer::create_foie_effect() {
    s32 sp8;
    void *owner;

    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if (((TItemWeapon *)this)->get_joint_position(1, &sp8) != 0) {
            owner = *(void * *)&this->blend.frame[1];
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)5);
        }
    } else {
        update_active_game_effect();
    }
}

}

extern s32 lbl_804A3548[];

void *__dt__13TUnk_804A3548Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3548;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A3548::init_vtable_804A3548() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3548;
    set_weapon_flags(34);
    return this;
}

}


extern "C" {
u8 * init_vtable_804A3548__13TUnk_804A3548Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_vtable_804A3548(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_804A3548__13TUnk_804A3548Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
