#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/text_8010F168.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {

s32 load_unload_set_unload();
s32 load_unload_set_load(void *);

void *TItemDrop__sub_8010F168(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        load_unload_set_unload();
        mem_free((void *)(*(saddr *)((s8 *)arg0 + 8)));
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TItemDrop__sub_8010F1B8(u8 *arg0, s32 arg1, s32 found) {
    __ct__8FlagWordFv((arg0 + 0xC));
    *(s32 *)((s8 *)arg0 + 4) = arg1;
    *(s32 *)((s8 *)arg0 + 0) = found;
    *(s32 *)((s8 *)arg0 + 8) = (saddr)mem_alloc((found));
    load_unload_set_load(arg0);
    return arg0;
}

}
