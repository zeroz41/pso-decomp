#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemLoad_8010FC28.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/TItemLoad.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8010FCB4_lbl_8049F42C {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 test_flags_any(void *, int);
extern RecoveredGlobal_8010FCB4_lbl_8049F42C lbl_8049F42C;
extern s32 item_load_work_buffer_busy;

extern s32 item_load_compressed_work_buffer;

void TItemLoad::advance_load_state() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any(arg0 + 0x1C, 4) == 0) {
        if ((s32) item_load_work_buffer_busy != 1) {
            item_load_work_buffer_busy = 1;
            ((FlagWord *)(arg0 + 0x1C))->set(4);
            goto block_3;
        }
    } else {
block_3:
        if (((TItemLoad *)arg0)->load_data((int) (*(s32 *)((s8 *)arg0 + 0x20))) != 0U) {
            TItemLoad__sub_801107DC(arg0);
            ((TItemLoad *)arg0)->request_load(item_load_compressed_work_buffer);
            *(s32 *)((s8 *)arg0 + 0x18) = 2;
        }
    }
}
typedef char RecoveredGlobal_8010FCB4_lbl_8049F42C_size[sizeof(RecoveredGlobal_8010FCB4_lbl_8049F42C) == 0x10 ? 1 : -1];
u8 *__dt__13TUnk_8049F42CFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = &lbl_8049F42C.value;
        if (test_flags_any(arg0 + 0x1C, 4) != 0) {
            item_load_work_buffer_busy = 0;
        }
        ((TUnk_8049F42C *)arg0)->sub_80110010(0);
        if (arg1 > 0) {
            ::operator delete((arg0));
        }
    }
    return arg0;
}

}
