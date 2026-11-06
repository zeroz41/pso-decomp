#include "types.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

void TLobby::copy_record_entry(s32 arg1) {
    s32 arg0 = (s32)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)(arg1);
    *(s16 *)((s8 *)arg0 + 0x14) = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
    *(s16 *)((s8 *)arg0 + 0x1A) = (s16) *(s16 *)((s8 *)arg1 + 0x1A);
    *(s16 *)((s8 *)arg0 + 0x1C) = (s16) *(s16 *)((s8 *)arg1 + 0x1C);
    *(s16 *)((s8 *)arg0 + 0x1E) = (s16) *(s16 *)((s8 *)arg1 + 0x1E);
}
