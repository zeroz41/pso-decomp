#include "types.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/network/TPlyJoinLobby.h"
#include "pso/system/memory.h"

extern "C" {

s32 __destroy_arr(s32, s32 *, s32, s32);

u8 *__ct__13TPlyJoinLobbyFRC13TPlyJoinLobby(u8 *arg0, u8 *arg1) {
    u32 var_r30;
    s32 var_r29;

    var_r30 = (unsigned long) (arg0 + 0x10);
    var_r29 = (long) (arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 4) = (u8) *(u8 *)((s8 *)arg1 + 4);
    *(u8 *)((s8 *)arg0 + 5) = (u8) *(u8 *)((s8 *)arg1 + 5);
    *(u8 *)((s8 *)arg0 + 6) = (u8) *(u8 *)((s8 *)arg1 + 6);
    *(u8 *)((s8 *)arg0 + 7) = (u8) *(u8 *)((s8 *)arg1 + 7);
    *(u8 *)((s8 *)arg0 + 8) = (u8) *(u8 *)((s8 *)arg1 + 8);
    *(u8 *)((s8 *)arg0 + 9) = (u8) *(u8 *)((s8 *)arg1 + 9);
    *(u8 *)((s8 *)arg0 + 0xA) = (u8) *(u8 *)((s8 *)arg1 + 0xA);
    *(u8 *)((s8 *)arg0 + 0xB) = (u8) *(u8 *)((s8 *)arg1 + 0xB);
    *(u8 *)((s8 *)arg0 + 0xC) = (u8) *(u8 *)((s8 *)arg1 + 0xC);
    *(u8 *)((s8 *)arg0 + 0xD) = (u8) *(u8 *)((s8 *)arg1 + 0xD);
    *(u8 *)((s8 *)arg0 + 0xE) = (u8) *(u8 *)((s8 *)arg1 + 0xE);
    *(u8 *)((s8 *)arg0 + 0xF) = (u8) *(u8 *)((s8 *)arg1 + 0xF);
    do {
        TLobby__sub_8013AA64((u8 *)var_r30, (u8 *)var_r29);
        var_r30 += 0x43C;
        var_r29 += 0x43C;
    } while (var_r30 < (u32)(arg0 + 0x32E0));
    return arg0;
}

extern s32 __dt__18TPlyJoinLobbyEntryFv[];

s32 __dt__13TPlyJoinLobbyFv(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0 + 0x10, __dt__18TPlyJoinLobbyEntryFv, 0x43C, 0xC);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}
