#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponTechnicalCrozier.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecBarta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F5F8.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"


void TItemWeaponTechnicalCrozier::emit_marker_effects() {
    Vec pos;

    if (get_attack_stage() == 0) {
        TItemEffCane::spawn_pair(tl_05, this, 3, 2);
    }
    get_joint_position(0, &pos);
    if (is_mode_two_and_ready() != 0) {
        TTecBarta::create_ex(owner, &owner->position, owner->rotation_y, 3);
        return;
    }
    update_active_game_effect();
}


TItemWeaponTechnicalCrozier::TItemWeaponTechnicalCrozier(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}


TItem *TItemWeaponTechnicalCrozier::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponTechnicalCrozier(tl_05, item);
    }
    return NULL;
}


TItemWeaponTechnicalCrozier::~TItemWeaponTechnicalCrozier() {}
