#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/network/TPlyRecvLogin.h"
#include "pso/player/TPlyGuildCardTag.h"

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {

void bswap__13TPlyRecvLoginFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
}

s32 __ct__13TPlyRecvLoginFRC13TPlyRecvLogin(saddr arg0, saddr arg1) {
    TPlyRecvLoginCopy *dst = (TPlyRecvLoginCopy *)arg0;
    const TPlyRecvLoginCopy *src = (const TPlyRecvLoginCopy *)arg1;
    ((TPlyRecvLogin *)arg0)->copy_with_guild_card_tag((s32 *)arg1);
    dst->client_config = src->client_config;
    return arg0;
}

s32 *TPlyRecvLogin::copy_with_guild_card_tag(s32 *arg1) {
    s32 *arg0 = (s32 *)this;
    *arg0 = *arg1;
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag((s32 *)((s8 *)arg0 + 4), (s32 *)((s8 *)arg1 + 4));
    return arg0;
}

}
