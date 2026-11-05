#include "types.h"
#include "pso/item/TUnk_804A2770.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A2868.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEffFlame.h"
#include "pso/item/TItemProShield.h"

extern "C" {


extern s32 tl_05;

void TUnk_804A2770::emit_marker_effects() {
    s32 item = (s32)this;
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 1);
    }
}

}

extern s32 __vt__13TUnk_804A2770[];

TUnk_804A2770::~TUnk_804A2770() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TObjPlayer__sub_80125F24(void *weapon, s32 parent, void *item) {
    __ct__11TItemWeaponFP7TObjectPUc(weapon);
    *(s32 **)((s8 *)weapon + 0x18) = __vt__13TUnk_804A2770;
    return weapon;
}

}


extern "C" {
u8 *__nw__5TItemFUl(s32);
u8 *TObjPlayer::create_obj_80125F60(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80125F24(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}


}

