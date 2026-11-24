#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemData.h"


void TObjPlayer::init_item_data(s32 arg1) {
    ((TItemData *)this)->init();
    *(s8 *)((s8 *)this + 0) = 4;
    *(s32 *)((s8 *)this + 0x10) = arg1;
}
