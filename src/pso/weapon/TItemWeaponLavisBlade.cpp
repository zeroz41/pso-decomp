#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponLavisBlade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/system/task/TMainTask.h"


void TItemWeaponLavisBlade::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        drain_owner_hp_fraction(0.05f);
        launch_rare_weapon_special(0, 1, 1.1666666f);
        return;
    }
    update_active_game_effect();
}


TItemWeaponLavisBlade::~TItemWeaponLavisBlade() {}

TItemWeaponLavisBlade::TItemWeaponLavisBlade(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x100622);
    shot_callback = (WeaponShotCallback)create_lavis_shot;
    shot_speed = 10.0f;
}


TItem *TItemWeaponLavisBlade::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponLavisBlade(tl_05, item);
    }
    return NULL;
}
