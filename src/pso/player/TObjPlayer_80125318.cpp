#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A2358[];

void *TObjPlayer::init_and_configure() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A2358;
    set_weapon_trail_joints((s32)this, 2, 6, 5);
    ((TItemWeapon *)this)->set_weapon_flags(35);
    set_effect_state(13);
    return this;
}

}
