#include "types.h"
#include "pso/weapon/TUnk_804A2C90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A2C90::update_weapon() {
    if (get_item_index() == 6) {
        refresh_owner_stats();
    }
}

TUnk_804A2D88::TUnk_804A2D88(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

u8 *create_suppressed_gun_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2D88(tl_05, item);
    }
    return NULL;
}

TUnk_804A2C90::TUnk_804A2C90(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    if (item[2] >= 5U) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_handgun_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2C90(tl_05, item);
    }
    return NULL;
}

TUnk_804A2C90::~TUnk_804A2C90() {}
