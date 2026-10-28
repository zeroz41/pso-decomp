#include "types.h"
#include "pso/item/TUnk_804A0AC4.h"
#include "pso/player/TObjPlayer.h"

extern "C" {


extern f32 lbl_805DACC0;

void TUnk_804A0AC4::emit_marker_effects() {
    s32 arg0 = (s32)this;
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)arg0)->launch_rare_weapon_special(0, 1, lbl_805DACC0);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}
