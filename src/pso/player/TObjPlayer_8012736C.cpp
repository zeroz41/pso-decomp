#include "types.h"
#include "pso/item/TUnk_804A3260.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rotate_matrix_y(s32, s32);

void TUnk_804A3260::vfunc_60() {
    if ((s32) *(s32 *)((s8 *)this + 0x210) == TObjPlayer::get_player_list()) {
        rotate_matrix_y(0, *(s32 *)((s8 *)this + 0x214));
    }
}

}
