#include "types.h"
#include "pso/item/TUnk_804A5058.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer.h"

void TUnk_804A5058::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    get_current_matrix((void *)(*(s32 *)((s8 *)(*(void * *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]) + 0xDB4) + (player_list * 0x30)));
    if (player_list == 9) {
        TItem::begin_effect_render();
    }
}
