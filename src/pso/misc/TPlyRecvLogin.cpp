#include "types.h"
#include "pso/packet_classes.h"
#include "pso/misc/TPlyGuildCardTag_8013ABCC.h"
#include "pso/misc/TPlyRecvLogin.h"
#include "pso/player/TPlyGuildCardTag.h"

struct ByteBlock_20 { u8 bytes[0x20]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
s32 bswap__13packet_headerFv();

void bswap__13TPlyRecvLoginFv(s32 arg0) {
    bswap__13packet_headerFv();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
}

s32 __ct__13TPlyRecvLoginFRC13TPlyRecvLogin(s32 arg0, s32 arg1) {
    ((TPlyRecvLogin *)arg0)->copy_with_guild_card_tag((s32 *)arg1);
    *(ByteBlock_20 *)(arg0 + 8 + 4) = *(const ByteBlock_20 *)(arg1 + 8 + 4);
    return arg0;
}

s32 *TPlyRecvLogin::copy_with_guild_card_tag(s32 *arg1) {
    s32 *arg0 = (s32 *)this;
    *arg0 = *arg1;
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag((s32 *)((s8 *)arg0 + 4), (s32 *)((s8 *)arg1 + 4));
    return arg0;
}

}
