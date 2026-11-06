#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A3070.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80120D50.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

s32 play_sound_effect(s32, s32, s32, s32);


void TUnk_804A3070::emit_marker_effects() {
    if (get_item_index() == 0) {
        if (is_mode_two_and_ready() != 0) {
            ((TObjPlayer *)this)->drain_owner_hp_fraction(0.07f);
            ((TObjPlayer *)this)->launch_rare_weapon_special(0, 1, 3.5f);
            play_sound_effect(0x4001A341, (s32)this->owner + 0x38, 0, 0);
            return;
        }
        ((TObjPlayer *)this)->update_active_game_effect();
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

}

TUnk_804A3070::~TUnk_804A3070() {

}

// Agito (inferred from create_agito_weapon)
TUnk_804A3070::TUnk_804A3070(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    if (get_item_index() == 0) {
        set_weapon_flags(0x20);
        shot_callback = (WeaponShotCallback)create_lavis_shot;
        shot_speed = 10.0f;
    }
}

u8 *create_agito_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A3070(tl_05, item);
    }
    return NULL;
}
