#include "types.h"
#include "pso/item/TUnk_804A68C8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/items/TItemWeapon.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A68C8::vfunc_60() {
    if (get_item_index() == 5) {
        switch (TObjPlayer::get_player_list()) {
        case 1:
            scale_matrix(NULL, scale, scale, scale);
            break;
        }
    }
}

void TUnk_804A68C8::update_idle() {
    if (attack_spawned == 1) {
        attack_spawned = 0;
    }
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&scale, -0.2f, 0.6f);
    }
}

void TUnk_804A68C8::update_attack() {
    if (attack_spawned == 0) {
        switch ((s32)get_item_index()) {
        case 5:
            break;
        case 4:
            if (get_attack_stage() == 0) {
                ((TObjPlayer *)tl_05)->create_item_eff_cane(this, 1, 0x1AE);
            }
            break;
        case 6:
            if (get_attack_stage() == 0) {
                ((TObjPlayer *)tl_05)->create_item_eff_cane(this, 2, 0x101);
            }
            break;
        }
        attack_spawned = 1;
    }
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&scale, 0.1f, 1.0f);
    }
}

TUnk_804A68C8::~TUnk_804A68C8() {}

TUnk_804A68C8::TUnk_804A68C8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale = 1.0f;
    attack_spawned = 0;
    if (item[2] >= 4U) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_cane_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A68C8(tl_05, item);
    }
    return NULL;
}
