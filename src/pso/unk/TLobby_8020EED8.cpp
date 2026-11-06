#include "types.h"
#include "pso/unk/TLobby.h"

s32 TLobby::pop_byte() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x64);
    if (temp_r4 > 0) {
        temp_r0 = temp_r4 - 1;
        *(s32 *)((s8 *)arg0 + 0x64) = temp_r0;
        return (u8)*(arg0 + temp_r0);
    }
    return -1;
}
