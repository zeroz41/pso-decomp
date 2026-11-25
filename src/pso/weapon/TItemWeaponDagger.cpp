#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponDagger.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"

void TItemWeaponDagger::transform_model_node() {
    if (get_item_index() == 5) {
        s32 n = TObjPlayer::get_player_list();
        switch (n) {
        case 3:
        case 4:
            scale_matrix(0, 1.0f, blade_scale, blade_scale);
            break;
        }
    }
}

void TItemWeaponDagger::update_idle() {
    if (get_item_index() == 5) {
        ::approach_value(&blade_scale, 0.2f, 0.0f);
    }
}

void TItemWeaponDagger::update_attack() {
    if (get_item_index() == 5) {
        ::approach_value(&blade_scale, 0.5f, 1.0f);
    }
}

TItemWeaponDagger::TItemWeaponDagger(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    u8 kind;
    set_weapon_flags(0x600);
    blade_scale = 1.0f;
    kind = item[2];
    if ((kind >= 5U) && (kind != 7)) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponDagger::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDagger(tl_05, item);
    }
    return NULL;
}

TItemWeaponDagger::~TItemWeaponDagger() {}

void TItemWeapon::set_color_node(s16 node) { color_node = node; }
