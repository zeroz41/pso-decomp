#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012789C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecJelin.h"
#include "pso/misc/TTecZarua.h"
#include "pso/item/TUnk_804A3450.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"

extern "C" {


void TObjPlayer__sub_8012789C(void* p) { ((TItemWeapon *)p)->roll_technique(); ((TItemWeapon *)p)->roll_technique(); }

extern s32 tl_05;

void TObjPlayer::cast_jellen_zalure() {
    s32 owner;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r4_2;

    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)this, 2, 1);
    }
    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if (get_tp() == 0) {
            owner = *(s32 *)&this->blend.frame[1];
            temp_r4 = owner + 0x38;
            TTecJelin::create(owner, temp_r4, temp_r4, 4);
        } else {
            temp_r3_2 = *(s32 *)&this->blend.frame[1];
            temp_r4_2 = temp_r3_2 + 0x38;
            TTecZarua::create_instance(temp_r3_2, temp_r4_2, temp_r4_2, 4);
        }
        ((TItemWeapon *)this)->roll_technique();
        return;
    }
    update_active_game_effect();
}

}

extern s32 lbl_804A3450[];

void *__dt__13TUnk_804A3450Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3450;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TObjPlayer::init_substate_b() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3450;
    ((TItemWeapon *)this)->set_weapon_flags(34);
    set_effect_state(2);
    return this;
}

}

extern "C" {
u8 * init_substate_b__10TObjPlayerFv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
u8 *TObjPlayer::create_substate_b(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_substate_b__10TObjPlayerFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
