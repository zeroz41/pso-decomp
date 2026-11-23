#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A3168.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80120D50.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/system/task/TMainTask.h"


void TUnk_804A3168::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        drain_owner_hp_fraction(0.05f);
        launch_rare_weapon_special(0, 1, 1.1666666f);
        return;
    }
    update_active_game_effect();
}


TUnk_804A3168::~TUnk_804A3168() {}

TUnk_804A3168::TUnk_804A3168(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x100622);
    shot_callback = (WeaponShotCallback)create_lavis_shot;
    shot_speed = 10.0f;
}


TItem *TObjPlayer__sub_80127314(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3168(tl_05, item);
    }
    return NULL;
}
