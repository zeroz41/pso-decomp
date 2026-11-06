#include "types.h"
#include "pso/technique/TTecKafun.h"

extern "C" {

s32 TTecKafun__ct(u32, f32, f32, s32, s32, s32, s32, s32, s32);
u32 __nw__7TObjectFUl(s32);

void TTecKafun::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1) {
    u32 tec_kafun = __nw__7TObjectFUl(0x100);
    if (tec_kafun != 0U) {
        TTecKafun__ct(tec_kafun, farg0, farg1, arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

}
