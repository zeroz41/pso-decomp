#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponProphetsOfMotav.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecJelin.h"
#include "pso/technique/TTecZarua.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponProphetsOfMotav::on_equipped() {
    roll_technique();
    roll_technique();
}

void TItemWeaponProphetsOfMotav::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        TItemEffCane::spawn_pair(tl_05, this, 2, 1);
    }
    if (is_mode_two_and_ready() != 0) {
        if (get_tp() == 0) {
            TTecJelin::create((saddr)owner, (saddr)&owner->position, (saddr)&owner->position, 4);
        } else {
            TTecZarua::create_instance((saddr)owner, &owner->position, &owner->position, 4);
        }
        roll_technique();
        return;
    }
    update_active_game_effect();
}

TItemWeaponProphetsOfMotav::~TItemWeaponProphetsOfMotav() {}

TItemWeaponProphetsOfMotav::TItemWeaponProphetsOfMotav(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    set_technique_roll_range(2);
}

TItem *TItemWeaponProphetsOfMotav::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponProphetsOfMotav(tl_05, item);
    }
    return NULL;
}
