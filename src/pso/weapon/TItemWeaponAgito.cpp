#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponAgito.h"
#include "pso/item/TItem.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponAgito::emit_marker_effects() {
    if (get_item_index() == 0) {
        if (is_mode_two_and_ready() != 0) {
            ((TItemWeapon *)this)->drain_owner_hp_fraction(0.07f);
            ((TItemWeapon *)this)->launch_rare_weapon_special(0, 1, 3.5f);
            play_sound_effect(0x4001A341, &owner->position, 0, 0);
            return;
        }
        ((TItemWeapon *)this)->update_active_game_effect();
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TItemWeaponAgito::~TItemWeaponAgito() {

}

// Agito (inferred from TItemWeaponAgito::create)
TItemWeaponAgito::TItemWeaponAgito(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    if (get_item_index() == 0) {
        set_weapon_flags(0x20);
        shot_callback = (WeaponShotCallback)create_lavis_shot;
        shot_speed = 10.0f;
    }
}

TItem *TItemWeaponAgito::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponAgito(tl_05, item);
    }
    return NULL;
}
