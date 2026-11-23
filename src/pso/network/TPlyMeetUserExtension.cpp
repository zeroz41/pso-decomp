#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/system/byteswap.h"
#include "pso/player/TPlyGuildCardTag.h"

void TPlyMeetUserExtension::bswap() {
    for (int i = 0; i < 8; ++i) {
        tags[i].bswap();
    }
    bswap_32(&mbr_0x40);
}
