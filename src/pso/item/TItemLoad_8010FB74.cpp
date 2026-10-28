#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/TItemLoad.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 test_flags_any(void *, int);
s32 free_texture__9TItemLoadFv();
s32 get_ring_lobby__9TItemLoadFv();

void TItemLoad::update_ring() {
    s32 arg0 = (s32)this;
    s32 temp_r3;

    temp_r3 = get_ring_lobby__9TItemLoadFv();
    if (temp_r3 != 2) {
        if (temp_r3 == 3) {
            ((FlagWord *)(arg0 + 0x1C))->clear(1);
        } else {
            ((FlagWord *)(arg0 + 0x1C))->set(1);
        }
        update_load_state();
    }
}

void TItemLoad::update_load_state() {
    u8 *arg0 = (u8 *)this;
    free_texture__9TItemLoadFv();
    if (test_flags_any(arg0 + 0x1C, 1) != 0) {
        *(s32 *)((s8 *)arg0 + 0x18) = 1;
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x18) = 4;
}

}
