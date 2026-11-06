#include "types.h"
#include "pso/unk/TUnk_804A7260.h"
#include "pso/unk/TLOC_ListClear.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

u8 *__dt__14TLOC_ListClearFv(u8 *arg0, s16 arg1);
void TObjPlayer__sub_8013DEF8(u8 *arg0);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
s32 __dl__7TObjectFPv(void *);

void TLOC_ListClear::run_task() {
    s32 arg0 = (s32)this;
    if ((TObjPlayer__sub_801C6DAC((u8 *)(arg0 + 0x1C)) != 0) && ((u32) *(u32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) != 0U)) {
        TObjPlayer__sub_8013DEF8((u8 *)(*(s32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) + 0x520));
    }
}

extern s32 lbl_804A71C4[];

u8 *__dt__14TLOC_ListClearFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A71C4;
        if ((TObjPlayer__sub_801C6DAC(arg0 + 0x1C) != 0) &&((u32) *(u32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424) != 0U)) {
            ((TMainCursor *)(*(s32 *)((s8 *)(((TMainCursor *)(arg0 + 0x1C))->get_state()) + 0x424)))->destroy_lock_on(0);
        }
        ((TUnk_804A7260 *)arg0)->destroy_cursor(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
