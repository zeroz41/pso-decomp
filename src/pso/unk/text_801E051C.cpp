#include "types.h"
#include "pso/unk/text_801E051C.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_10 { u8 bytes[0x10]; };

extern "C" {
s32 __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
u8 *copy_player_lobby_data_entry(u8 *arg0, u8 *arg1) {
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
    *(s32 *)((s8 *)arg0 + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(ByteBlock_10 *)((s32) arg0 + 0x10) = *(const ByteBlock_10 *)((s32) arg1 + 0x10);
    return arg0;
}

}
