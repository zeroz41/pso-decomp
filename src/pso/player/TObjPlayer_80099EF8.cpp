#include "types.h"
#include "pso/enemy/TUnk_8048FE08.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct O_80099F00 { u8 pad[0xb0]; s32 xb0; };

s32 TItem::get_item_id() { return (*(s32 *)&(*(void * *)((u8 *)this + 0xD8))); }
void TUnk_8048FE08::render() {
    if (((O_80099F00 *)this)->xb0 == 0) {
        return;
    }
}
