#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_801AA5C0.h"
#include "pso/player/TObjPlayer.h"
struct O_801AA64C { u16 a; u16 b; };

extern "C" {
int __dl__FPv(void* a0);
extern "C" {
s32 __construct_array(void *, void *, void *, int, int);
void TObjPlayer__sub_801AA64C(O_801AA64C *p);

}

s32 TObjPlayer__sub_801AA584(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        ((s32)__dl__FPv((void*)arg0));
    }
    return arg0;
}

extern "C" {

s32 TObjPlayer::init_arrays() {
    s32 arg0 = (s32)this;
    __ct__8FlagWordFv((void *)(arg0 + 4));
    __construct_array((void *)(arg0 + 8), (void *)&TObjPlayer__sub_801AA61C, (void *)&TObjPlayer__sub_801AA584, 4, 4);
    ((TObjPlayer *)arg0)->reset_id_entry();
    return arg0;
}

}

void* TObjPlayer__sub_801AA61C(void* p) { TObjPlayer__sub_801AA64C((O_801AA64C *)p); return p; }

void TObjPlayer__sub_801AA64C(O_801AA64C *p) {
    p->a = 0xFFFF;
    p->b = 0;
}

}
