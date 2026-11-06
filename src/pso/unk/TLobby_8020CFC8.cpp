#include "types.h"
#include "pso/unk/TLobby_8020CFC8.h"

void TLobby__sub_8020CFC8(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
}
