#include "types.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/player/TObjPlayer.h"

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
