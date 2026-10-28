#include "types.h"
#include "pso/item/TUnk_804A3168.h"
#include "pso/player/TObjPlayer.h"

extern "C" {


extern f32 lbl_805DADC0;
extern f32 lbl_805DADC4;

void TUnk_804A3168::emit_marker_effects() {
    s32 arg0 = (s32)this;
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)arg0)->drain_owner_hp_fraction(lbl_805DADC0);
        ((TObjPlayer *)arg0)->launch_rare_weapon_special(0, 1, lbl_805DADC4);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}
