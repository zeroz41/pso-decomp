#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/TItemLoad.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern int item_load_compressed_work_buffer;
struct VOff_8010FD2C_arg0_8010fd2c { char pad_0[0x1C]; char f_1C[1]; };

void init_buffer__9TItemLoadFPviii(void *);
void mem_free(void *p);

extern s32 lbl_8049F42C[];

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
