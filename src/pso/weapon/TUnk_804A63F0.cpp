#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A63F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecBarta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F5F8.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"


void TUnk_804A63F0::emit_marker_effects() {
    Vec pos;

    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects(this, 3, 2);
    }
    get_joint_position(0, &pos);
    if (is_mode_two_and_ready() != 0) {
        TTecBarta::create_ex(owner, &owner->position, owner->rotation_y, 3);
        return;
    }
    update_active_game_effect();
}


TUnk_804A63F0::TUnk_804A63F0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}


TItem *TObjPlayer::create_vtable_804A63F0(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A63F0(tl_05, item);
    }
    return NULL;
}


TUnk_804A63F0::~TUnk_804A63F0() {}
