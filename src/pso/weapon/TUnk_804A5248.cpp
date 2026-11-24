#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TUnk_804A5248.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_8012C268.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"



void TUnk_804A5248::vfunc_60() {
    if ((get_item_index() == 5) && (TObjPlayer::get_player_list() == 3)) {
        scale_matrix(NULL, 1.0f, barrel_scale, 1.0f);
    }
}


void TUnk_804A5248::update_idle() {
    if (get_item_index() == 5) {
        ::approach_value(&barrel_scale, 0.1f, 0.6f);
    }
}


void TUnk_804A5248::update_attack() {
    if (get_item_index() == 5) {
        ::approach_value(&barrel_scale, 0.2f, 1.0f);
    }
}

TUnk_804A5248::TUnk_804A5248(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    barrel_scale = 1.0f;
    if (item[2] >= 5U) {
        set_color_node(-1);
    }
}

TItem *create_rifle_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5248(tl_05, item);
    }
    return NULL;
}

TUnk_804A5248::~TUnk_804A5248() {}
