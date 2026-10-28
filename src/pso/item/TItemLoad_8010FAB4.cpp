#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/TItemLoad.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

struct VOff_8010FB0C_arg0_8010fb0c_8010FAB4 { char pad_0[0x1C]; char f_1C[1]; };

s32 test_flags_any(void *, int);

s32 TItemLoad::begin_load(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x18) == 0) {
        *(s32 *)((s8 *)arg0 + 0x20) = arg1;
        ((FlagWord *)(arg0 + 0x1C))->clear(2);
        *(s32 *)((s8 *)arg0 + 0x18) = 1;
        return 1;
    }
    return 0;
}

extern u32 item_load_work_buffer_busy;

void TItemLoad::reset_state() {
    s32 x;
    struct VOff_8010FB0C_arg0_8010fb0c_8010FAB4 *self = (struct VOff_8010FB0C_arg0_8010fb0c_8010FAB4 *)this;
    free_texture();
    ((FlagWord *)(self->f_1C))->set(2);
    x = test_flags_any(self->f_1C, 4);
    if (x != 0) {
        item_load_work_buffer_busy = 0;
        ((FlagWord *)(self->f_1C))->clear(4);
    }
    *(u32 *)((s8 *)this + 0x18) = 0;
}

}
