#include "types.h"
#include "pso/technique/TTecKafun.h"

extern "C" {

s32 TTecKafun__sub_802A9948(void *, s32, s32, s32, s32, s32, f32, f32);
void *__nw__7TObjectFUl(s32);

void TTecKafun::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0, f32 farg1) {
    void *ptr = __nw__7TObjectFUl(0x100);
    if (ptr != NULL) {
        TTecKafun__sub_802A9948(ptr, arg0, arg1, arg2, arg3, arg4, farg0, farg1);
    }
}

}
