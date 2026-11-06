#include "types.h"
#include "pso/misc/TPlyMeetUserExtension.h"
#include "pso/system/byteswap.h"
#include "pso/player/TPlyGuildCardTag.h"

void bswap__21TPlyMeetUserExtensionFv(s32 arg0) {
    s32 var_r31;
    s32 var_r30;

    var_r30 = 0;
    var_r31 = 0;
    do {
        ((TPlyGuildCardTag *)(arg0 + var_r31))->bswap();
        var_r30 += 1;
        var_r31 += 8;
    } while (var_r30 < 8);
    bswap_32((u32 *)(arg0 + 0x40));
}
