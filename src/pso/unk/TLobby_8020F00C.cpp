#include "types.h"
#include "pso/unk/TLobby_8020F00C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"

void push_shop_pool_entry(u8 *arg0, s8 arg1) {
    s32 temp_r5;
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x64);
    if (temp_r5 < 0x64) {
        *(s32 *)((s8 *)arg0 + 0x64) = (temp_r5 + 1);
        *(arg0 + temp_r5) = arg1;
    }
}

void TLobby::reset_counter_64() { *(s32*)((char*)this + 0x64) = 0; }
