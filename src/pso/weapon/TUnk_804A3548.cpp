#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A3548.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A3548::emit_marker_effects() {
    Vec pos;
    TObjPlayer *player;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(1, &pos) != 0) {
            player = owner;
            TTecFoie::create(player, &pos, player->rotation_y, 5);
        }
    } else {
        update_active_game_effect();
    }
}

TUnk_804A3548::~TUnk_804A3548() {}

TUnk_804A3548::TUnk_804A3548(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

TItem *TObjPlayer::create_vtable_804A3548(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3548(tl_05, item);
    }
    return NULL;
}
