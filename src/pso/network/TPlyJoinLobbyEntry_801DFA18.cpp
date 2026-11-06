#include "types.h"
#include "pso/player/TPlyCharData_801E0A04.h"
#include "pso/network/TPlyJoinLobbyEntry_801DFA18.h"
#include "pso/system/byteswap.h"

extern "C" {

s32 bswap__16TPlyGuildCardTagFv();

void bswap__18TPlyJoinLobbyEntryFv(s32 arg0) {
    bswap__16TPlyGuildCardTagFv();
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap__12TPlyCharDataFv(arg0 + 0x20);
}

}
