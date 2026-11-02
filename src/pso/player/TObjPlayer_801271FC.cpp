#include "types.h"
#include "pso/item/TUnk_804A3168.h"
#include "pso/player/TObjPlayer.h"

extern "C" {



void TUnk_804A3168::emit_marker_effects() {
    s32 arg0 = (s32)this;
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)arg0)->drain_owner_hp_fraction(0.05f);
        ((TObjPlayer *)arg0)->launch_rare_weapon_special(0, 1, 1.1666666f);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}
