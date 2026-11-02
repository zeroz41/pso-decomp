#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 play_sound_effect(s32, s32, s32, s32);
u8 get_item_index__5TItemFv();


void TObjPlayer::start_shield_action() {
    if (get_item_index__5TItemFv() == 0) {
        if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
            drain_owner_hp_fraction(0.07f);
            launch_rare_weapon_special(0, 1, 3.5f);
            play_sound_effect(0x4001A341, *(s32 *)&this->blend.frame[1] + 0x38, 0, 0);
            return;
        }
        update_active_game_effect();
        return;
    }
    update_active_game_effect();
}

}
