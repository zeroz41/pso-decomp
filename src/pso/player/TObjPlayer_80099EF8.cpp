#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

s32 TItem::get_item_id() { return (*(s32 *)&(*(void * *)((u8 *)this + 0xD8))); }
