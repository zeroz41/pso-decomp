#include "types.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TUnk_804A3830.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3830[];

void *TUnk_804A3830::construct_state_variant() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3830;
    set_weapon_trail_joints((s32)this, 2, 1, 2);
    set_weapon_trail_joints((s32)this, 3, 3, 4);
    set_weapon_flags(513);
    return this;
}

}
