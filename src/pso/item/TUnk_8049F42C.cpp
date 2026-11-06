#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemLoad_8010FC28.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_800F7DAC.h"

extern "C" {
s32 test_flags_any(void *, int);
extern s32 lbl_8049F42C[];
extern s32 item_load_work_buffer_busy;
void init_buffer__9TItemLoadFPviii(void *);
void mem_free(void *p);
struct VOff_8010FD2C_arg0_8010fd2c { char pad_0[0x1C]; char f_1C[1]; };

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

u8 *__dt__13TUnk_8049F42CFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_8049F42C;
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

void *TUnk_8049F42C::init() {
    struct VOff_8010FD2C_arg0_8010fd2c *self = (struct VOff_8010FD2C_arg0_8010fd2c *)this;
    init_buffer__9TItemLoadFPviii(this);
    *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_8049F42C;
    __ct__8FlagWordFv((self->f_1C));
    *(u32 *)((s8 *)this + 0x18) = 0;
    ((FlagWord *)(self->f_1C))->reset();
    return this;
}

s32 TItemLoad::decompress_buffer(u32 arg0) {
    if (((u32) (*(u32 *)&item_load_compressed_work_buffer) != 0U) && (arg0 != 0U)) {
        return prs_decompress_buffer((*(u32 *)&item_load_compressed_work_buffer), arg0);
    }
    return 0;
}

void TItemLoad::free_boss4_rock() { mem_free((void *)item_load_compressed_work_buffer); item_load_compressed_work_buffer = 0; }

}
