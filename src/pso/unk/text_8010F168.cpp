#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/text_8010F168.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {

s32 load_unload_set_unload();
s32 load_unload_set_load(void *);

void *TItemDrop__sub_8010F168(void *block, s16 dealloc) {
    if (block != NULL) {
        load_unload_set_unload();
        mem_free((void *)(*(saddr *)((s8 *)block + 8)));
        if (dealloc > 0) {
            ::operator delete(block);
        }
    }
    return block;
}

u8 *TItemDrop__sub_8010F1B8(u8 *block, s32 arg1, s32 found) {
    __ct__8FlagWordFv((block + 0xC));
    *(s32 *)((s8 *)block + 4) = arg1;
    *(s32 *)((s8 *)block + 0) = found;
    *(s32 *)((s8 *)block + 8) = (saddr)mem_alloc((found));
    load_unload_set_load(block);
    return block;
}

}
