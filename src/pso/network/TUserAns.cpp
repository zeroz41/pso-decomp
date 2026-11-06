#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/network/TRecvPort.h"
#include "pso/network/TUserAns.h"
#include "pso/system/byteswap.h"
#include "pso/player/TPlyGuildCardTag.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__8TUserAnsFv(s32 arg0) {
    bswap__13packet_headerFv();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
    bswap_32((u32 *)(arg0 + 0xC));
    bswap__9TRecvPortFv(arg0 + 0x10);
    bswap__21TPlyMeetUserExtensionFv(arg0 + 0x60);
}

}
