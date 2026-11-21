#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/ui/chat/TChatMessage.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlyGuildCardTag.h"

extern "C" {


void bswap__12TChatMessageFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
    bswap_32((u32 *)(arg0 + 0x1C));
}

}
