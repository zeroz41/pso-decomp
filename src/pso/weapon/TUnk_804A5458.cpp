#include "types.h"
#include "pso/weapon/TUnk_804A5458.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A5458::~TUnk_804A5458() {}

TUnk_804A5458::TUnk_804A5458(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    switch (item[2]) {
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
    if (item[2] >= 4U) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_rod_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5458(tl_05, item);
    }
    return NULL;
}
