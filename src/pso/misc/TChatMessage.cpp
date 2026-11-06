#include "types.h"
#include "pso/misc/TChatMessage.h"
#include "pso/system/byteswap.h"
#include "pso/player/TPlyGuildCardTag.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__12TChatMessageFv(s32 arg0) {
    bswap__13packet_headerFv();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
    bswap_32((u32 *)(arg0 + 0x1C));
}

}
