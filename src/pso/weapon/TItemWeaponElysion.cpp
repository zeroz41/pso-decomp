#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponElysion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponElysion::emit_marker_effects() {
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

TItemWeaponElysion::~TItemWeaponElysion() {}

TItemWeaponElysion::TItemWeaponElysion(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

TItem *TObjPlayer::create_vtable_804A3548(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponElysion(tl_05, item);
    }
    return NULL;
}
