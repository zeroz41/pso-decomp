#include "types.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/weapon/TUnk_804A4748.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B620.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A4748::emit_marker_effects() {
    TObjPlayer__sub_80128A70();
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
        return;
    }
    launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
}

void TUnk_804A4748::reserved_53() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TUnk_804A4748::~TUnk_804A4748() {}

TUnk_804A4748::TUnk_804A4748(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(547);
    shot_callback = (WeaponShotCallback)create_gun_shot;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TObjPlayer::create_action(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4748(tl_05, item);
    }
    return NULL;
}
