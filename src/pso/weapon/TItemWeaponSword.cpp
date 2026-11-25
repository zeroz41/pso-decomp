#include "types.h"
#include "pso/weapon/TItemWeaponSword.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSword::transform_model_node() {
    if (glows != 0 && TObjPlayer::get_player_list() == 1) {
        begin_particle_tev();
        load_projection_tex(0);
    }
}

void TItemWeaponSword::update_weapon() {
    if (get_item_index() == 5) {
        refresh_owner_stats();
    }
}

TItemWeaponSword::~TItemWeaponSword() {}

TItemWeaponSword::TItemWeaponSword(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    if (item[2] == 5 || item[1] == 0x8F) {
        glows = 1;
    } else {
        glows = 0;
    }
    if (glows != 0) {
        set_weapon_flags(0x800);
    }
    if (item[2] > 5U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponSword::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSword(tl_05, item);
    }
    return NULL;
}
