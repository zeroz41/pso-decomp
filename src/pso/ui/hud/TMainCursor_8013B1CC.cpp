#include "types.h"
#include "pso/unk/TUnk_804A7260.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

u8 *__dt__10TLOC_StartFv(u8 *arg0, s16 arg1);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
s32 __dl__7TObjectFPv(void *);

extern s32 lbl_804A7290[];

u8 *__dt__10TLOC_StartFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A7290;
        if ((TObjPlayer__sub_801C6DAC((arg0 + 0x1C)) != 0) && ((u32) *(u32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) != 0U)) {
            ((TMainCursor *)(*(s32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424)))->set_sub_cursor_value(0);
        }
        ((TUnk_804A7260 *)arg0)->destroy_cursor(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
