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
        set_weapon_trail_joints(this, 0, 3, 2);
        break;
    case 4:
        set_weapon_trail_joints(this, 0, 2, 1);
        break;
    default:
        set_weapon_trail_joints(this, 0, 2, 3);
        break;
    }
    if (item[2] >= 4U) {
        set_color_node(-1);
    }
}

TItem *create_rod_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5458(tl_05, item);
    }
    return NULL;
}
