#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A3070.h"

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
