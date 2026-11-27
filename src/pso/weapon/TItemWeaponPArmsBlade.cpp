#include "types.h"
#include "pso/weapon/TItemWeaponPArmsBlade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"
#include <stdlib.h>


s32 TItemWeaponPArmsBlade::is_rand_below_threshold() {
    return (u32)__cntlzw(((3.0517578e-05f * (f32) rand()) < 0.3f)) >> 5;
}


void TItemWeaponPArmsBlade::draw_held_model() {
    s32 saved;
    NJS_OBJECT *saved_model;
    saved = get_photon_color_id();
    saved_model = item_model;
    if (is_rand_below_threshold() == 0) {
        set_photon_color_id(8);
        item_render_state.set(4);
    }
    draw_weapon_model();
    if (get_photon_color_id() != 8) {
        update_trail_slot(0);
    }
    item_model = second_model;
    if (is_rand_below_threshold() == 0) {
        set_photon_color_id(8);
        item_render_state.set(4);
    } else {
        set_photon_color_id(saved);
    }
    draw_weapon_at_joint(0x23);
    if (get_photon_color_id() != 8) {
        update_trail_slot(1);
    }
    item_model = saved_model;
    set_photon_color_id(saved);
}


TItemWeaponPArmsBlade::TItemWeaponPArmsBlade(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
}

TItem *TItemWeaponPArmsBlade::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPArmsBlade(tl_05, item);
    }
    return NULL;
}

TItemWeaponPArmsBlade::~TItemWeaponPArmsBlade() {}

void TItemWeaponPArmsBlade::set_photon_color_id(s16 v) { this->photon_color_id = v; }
s16 TItemWeaponPArmsBlade::get_photon_color_id() { return this->photon_color_id; }
