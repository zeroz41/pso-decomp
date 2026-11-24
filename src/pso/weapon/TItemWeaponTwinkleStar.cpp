#include "types.h"
#include "pso/weapon/TUnk_804A6010.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TUnk_804A6010::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
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

void TUnk_804A6010::update_weapon() {
    star_angle += 0xCCC;
}

void TUnk_804A6010::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        TItemEffCane::spawn_pair(tl_05, this, 2, 4);
    }
}

TUnk_804A6010::~TUnk_804A6010() {}

TUnk_804A6010::TUnk_804A6010(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    star_angle = 0;
}

TItem *TObjPlayer::create_state_0(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A6010(tl_05, item);
    }
    return NULL;
}
