#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponCaduceus.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponCaduceus::emit_marker_effects() {
    Vec origin;
    TObjPlayer *owner;

    get_joint_position(2, &origin);
    spawn_particle_effect(&origin, 0x1BF);
    if (is_mode_two_and_ready() != 0) {
        owner = this->owner;
        TTecFoie::create(owner, &origin, owner->rotation.y, 3);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TItemWeaponCaduceus::TItemWeaponCaduceus(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

TItem *TItemWeaponCaduceus::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponCaduceus(tl_05, item);
    }
    return NULL;
}

TItemWeaponCaduceus::~TItemWeaponCaduceus() {}
