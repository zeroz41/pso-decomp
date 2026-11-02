#include "types.h"
#include "pso/player/TUnk_804A63F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecBarta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F5F8.h"
#include "pso/item/TItem.h"

extern "C" {


extern s32 tl_05;

void TUnk_804A63F0::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    u8 *temp_r3;

    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)arg0, 3, 2);
    }
    ((TItemWeapon *)arg0)->get_joint_position(0, &sp8);
    if (((TItemWeapon *)arg0)->is_mode_two_and_ready() != 0) {
        temp_r3 = (unsigned char *) (this->owner);
        ((TTecBarta *)temp_r3)->create_ex(temp_r3 + 0x38, (void *)(*(s32 *)((s8 *)temp_r3 + 0x60)), (void *)3);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A63F0[];

void *TUnk_804A63F0::init_vtable_804A63F0() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A63F0;
    set_weapon_flags(34);
    return this;
}

}

extern "C" {
u8 * init_vtable_804A63F0__13TUnk_804A63F0Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_vtable_804A63F0(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_804A63F0__13TUnk_804A63F0Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 __vt__13TUnk_804A63F0[];

TUnk_804A63F0::~TUnk_804A63F0() {}
