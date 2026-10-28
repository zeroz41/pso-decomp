#include "types.h"
#include "pso/player/TObjPlayer_8012FFE4.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_item_index__5TItemFv();
s32 scale_matrix(s32, f32, f32, f32);

void TObjPlayer::update_shield_effect() {
    f32 temp_f1;

    if (get_item_index__5TItemFv() == 5) {
        switch (TObjPlayer::get_player_list()) {
        case 1:
            temp_f1 = *(f32 *)((s8 *)this + 0x1F8);
            scale_matrix(0, temp_f1, temp_f1, temp_f1);
            break;
        }
    }
}

}
