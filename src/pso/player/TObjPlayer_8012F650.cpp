#include "types.h"
#include "pso/item/TUnk_804A64E8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 scale_current_matrix(void *);
s32 rotate_matrix_x(s32, s32);

void TUnk_804A64E8::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_x(0, this->m_204);
        return;
    case 2:
        scale_current_matrix((u8 *)&this->unk_1F8);
        return;
    case 3:
        rotate_matrix_x(0, -this->m_204);
        return;
    }
}

}
