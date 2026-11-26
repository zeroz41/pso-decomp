#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeaponRifle.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_8012C268.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"



void TItemWeaponRifle::transform_model_node() {
    if ((get_item_index() == 5) && (TObjPlayer::get_player_list() == 3)) {
        scale_matrix(NULL, 1.0f, barrel_scale, 1.0f);
    }
}


void TItemWeaponRifle::update_idle() {
    if (get_item_index() == 5) {
        ::approach_value(&barrel_scale, 0.1f, 0.6f);
    }
}


void TItemWeaponRifle::update_attack() {
    if (get_item_index() == 5) {
        ::approach_value(&barrel_scale, 0.2f, 1.0f);
    }
}

TItemWeaponRifle::TItemWeaponRifle(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    barrel_scale = 1.0f;
    if (item[2] >= 5U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponRifle::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRifle(tl_05, item);
    }
    return NULL;
}

TItemWeaponRifle::~TItemWeaponRifle() {}
