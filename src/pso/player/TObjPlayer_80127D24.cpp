#include "types.h"
#include "pso/item/TUnk_804A3640.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3640[];

void *TUnk_804A3640::init_with_id_2() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3640;
    set_weapon_flags(2);
    return this;
}

}
