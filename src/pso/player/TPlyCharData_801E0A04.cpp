#include "types.h"
#include "pso/player/TPlyDispData.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/player/TPlyCharData_801E0A04.h"
#include "pso/player/TPlyDispConfigSmth.h"
#include "pso/player/TPlyInventoryItem.h"

void bswap__12TPlyCharDataFv(s32 arg0) {
    s32 off;
    s32 i;

    for (i = 0, off = 0; i < 0x1E; i++, off += 0x1C) {
        bswap__17TPlyInventoryItemFv((s32)((char *)arg0 + off + 4));
    }
    bswap__15disp_data_part2Fv(arg0 + 0x370);
    bswap__12player_statsFv((void *)(arg0 + 0x34C));
    ((TPlyDispConfig *)(arg0 + 0x3C0))->bswap_pair();
}

void TPlyDispConfig::bswap_pair() { bswap__18TPlyDispConfigSmthFv((s32)this); bswap__18TPlyDispConfigSmthFv((s32)((char*)this + 0x24)); }
