#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/text_8010F168.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {

s32 load_unload_set_unload();
s32 load_unload_set_load(void *);

void *TItemDrop__sub_8010F168(void *drop, s16 flags) {
    if (drop != NULL) {
        load_unload_set_unload();
        mem_free((void *)(*(saddr *)((s8 *)drop + 8)));
        if (flags > 0) {
            ::operator delete(drop);
        }
    }
    return drop;
}

u8 *TItemDrop__sub_8010F1B8(u8 *drop, s32 id, s32 size) {
    __ct__8FlagWordFv((drop + 0xC));
    *(s32 *)((s8 *)drop + 4) = id;
    *(s32 *)((s8 *)drop + 0) = size;
    *(s32 *)((s8 *)drop + 8) = (saddr)mem_alloc((size));
    load_unload_set_load(drop);
    return drop;
}

}
