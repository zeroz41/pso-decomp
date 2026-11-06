#include "types.h"
#include "pso/weapon/TUnk_804A6010.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A6010::vfunc_60() {
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
        ((TObjPlayer *)tl_05)->spawn_cane_effects(this, 2, 4);
    }
}

TUnk_804A6010::~TUnk_804A6010() {}

TUnk_804A6010::TUnk_804A6010(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    star_angle = 0;
}

u8 *TObjPlayer::create_state_0(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A6010(tl_05, arg0);
    }
    return NULL;
}
