#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/unk/text_8010F168.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void *mem_alloc(u32 size);
s32 fn_8010F018();
s32 fn_8010F0C0(void *);
void mem_free(void *p);

void *TItemDrop__sub_8010F168(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        fn_8010F018();
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 8)));
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TItemDrop__sub_8010F1B8(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__8FlagWordFv((arg0 + 0xC));
    *(s32 *)((s8 *)arg0 + 4) = arg1;
    *(s32 *)((s8 *)arg0 + 0) = arg2;
    *(s32 *)((s8 *)arg0 + 8) = (s32)mem_alloc((arg2));
    fn_8010F0C0(arg0);
    return arg0;
}

}
