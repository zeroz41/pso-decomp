#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer.h"

void TObjPlayer::apply_conveyor_effect() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    get_current_matrix((void *)(*(s32 *)((s8 *)(*(void * *)&this->unk_F0) + 0xDB4) + (player_list * 0x30)));
    if (player_list == 9) {
        TItem::begin_effect_render();
    }
}
