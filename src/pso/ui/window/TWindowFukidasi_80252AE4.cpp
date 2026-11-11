#include "types.h"
#include "pso/ui/window/TWindowFukidasi_80252AE4.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TUnk_804CF0B8.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowFukidasi_80252B74.h"

extern "C" {

void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);

extern s32 lbl_804CF0B8[];

u8 *__dt__13TUnk_804CF0B8Fv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CF0B8;
        if (((TUnk_804CF0B8 *)arg0)->is_flag_set() != 0) {
            ((TUnk_804CF0B8 *)arg0)->clear_visible_flag();
            TWindowCtrl::release_slot((s8 *)(arg0 + 0x73));
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x78) != 0U) {
            mem_free(*(void **)((s8 *)arg0 + 0x78));
            *(u32 *)((s8 *)arg0 + 0x78) = 0U;
        }
        ((TWindowAddition *)arg0)->destroy_window(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *construct_with_parent__15TWindowAdditionFPv(void *, void *, s16, s32);
void *sub_80251DF0__13TUnk_804CF0B8Fslsf(void *, s32, s32, s32, f32);
s32 get_zero_vec2();
extern u8 window_fukidasi_addition_params[];
u8 *TWindowFukidasi__sub_80252B74(u8 *arg0, s32 arg1, s32 str, s32 arg3, f32 farg0) {
    construct_with_parent__15TWindowAdditionFPv(arg0, window_fukidasi_addition_params, arg3, get_zero_vec2());
    *(void **)(arg0 + 0x18) = lbl_804CF0B8;
    sub_80251DF0__13TUnk_804CF0B8Fslsf(arg0, arg1, str, arg3, farg0);
    return arg0;
}

}
