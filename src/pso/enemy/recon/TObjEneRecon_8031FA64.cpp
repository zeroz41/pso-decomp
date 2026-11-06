#include "types.h"
#include "pso/enemy/recon/TObjEneRecon.h"

extern "C" {

s32 has_child_in_anim_5__12TObjEneReconFv();

u8 TObjEneRecon::is_out_of_range() {
    int var_r4;

    if (has_child_in_anim_5__12TObjEneReconFv() == 1) {
        return 1;
    }
    var_r4 = 0;
    if (((s32) *(s32 *)((s8 *)this + 0x410) >= (s32) *(s32 *)((s8 *)this + 0x3F8)) || ((s32) *(s32 *)((s8 *)this + 0x414) >= (s32) *(s32 *)((s8 *)this + 0x3F4))) {
        var_r4 = 1;
    }
    return (u8) var_r4;
}

}
