#include "types.h"
#include "pso/unk/text_8013AAD4.h"
#include "pso/player/TPlyGuildCardTag.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_14 { u8 bytes[0x14]; };

struct ByteBlock_24 { u8 bytes[0x24]; };

struct ByteBlock_50 { u8 bytes[0x50]; };

struct ByteBlock_348 { u8 bytes[0x348]; };

u8 *fn_8013AAD4(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r5;
    u8 *temp_r6;
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u8 *)((s8 *)arg0 + 2) = (u8) *(u8 *)((s8 *)arg1 + 2);
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg1 + 3);
    *(ByteBlock_348 *)((s32) arg0 + 4) = *(const ByteBlock_348 *)((s32) arg1 + 4);
    temp_r6 = (arg0 + 0x348);
    temp_r4 = (arg1 + 0x348);
    *(ByteBlock_24 *)((s32) temp_r6 + 4) = *(const ByteBlock_24 *)((s32) temp_r4 + 4);
    *(ByteBlock_50 *)((arg0 + 0x36C) + 4) = *(const ByteBlock_50 *)((arg1 + 0x36C) + 4);
    ((TPlyGuildCardTag *)(arg0 + 0x3C0))->copy_full(arg1 + 0x3C0);
    temp_r5 = (arg0 + 0x404);
    temp_r4_2 = (arg1 + 0x404);
    *(ByteBlock_14 *)((s32) temp_r5 + 4) = *(const ByteBlock_14 *)((s32) temp_r4_2 + 4);
    return arg0;
}
