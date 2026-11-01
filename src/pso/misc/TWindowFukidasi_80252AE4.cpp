#include "types.h"
#include "pso/misc/TWindowFukidasi_80252AE4.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TUnk_804CF0B8.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowFukidasi.h"

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

}
