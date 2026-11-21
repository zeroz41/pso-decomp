#include "types.h"
#include "pso/weapon/TUnk_804A5648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8011BEF0.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A5648::emit_marker_effects() {
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
    } else {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
    }
}

void TUnk_804A5648::reserved_53() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TUnk_804A5648::~TUnk_804A5648() {}

TUnk_804A5648::TUnk_804A5648(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(515);
    shot_callback = (WeaponShotCallback)spawn_shoot_particle_9f;
    shot_speed = 11.0f;
}


TItem *TObjPlayer__sub_8012CE44(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5648(tl_05, item);
    }
    return NULL;
}
