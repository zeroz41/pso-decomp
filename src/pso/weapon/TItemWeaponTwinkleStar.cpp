#include "types.h"
#include "pso/weapon/TItemWeaponTwinkleStar.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponTwinkleStar::transform_model_node() {
    switch (get_model_node_counter()) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_y(0, star_angle);
        return;
    case 3:
        TItem::begin_effect_render();
        rotate_matrix_y(0, -star_angle);
    case 2:
        return;
    }
}

void TItemWeaponTwinkleStar::update_weapon() {
    star_angle += 0xCCC;
}

void TItemWeaponTwinkleStar::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        TItemEffCane::spawn_pair(tl_05, this, 2, 4);
    }
}

TItemWeaponTwinkleStar::~TItemWeaponTwinkleStar() {}

TItemWeaponTwinkleStar::TItemWeaponTwinkleStar(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    star_angle = 0;
}

TItem *TItemWeaponTwinkleStar::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponTwinkleStar(tl_05, item);
    }
    return NULL;
}
