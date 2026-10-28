#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A1288.h"

extern "C" {


extern s32 tl_05;

void TUnk_804A1288::emit_marker_effects() {
    s32 item = (s32)this;
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 1);
    }
}

}
