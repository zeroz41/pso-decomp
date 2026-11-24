#include "types.h"
#include "pso/player/TPlyDispData.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/player/TPlyCharData_801E0A04.h"
#include "pso/player/TPlyDispConfigSmth.h"
#include "pso/player/TPlyInventory.h"

void bswap__12TPlyCharDataFv(saddr char_data) {
    s32 off;
    s32 i;

    for (i = 0, off = 0; i < 0x1E; i++, off += 0x1C) {
        ((TPlyInventoryItem *)((char *)char_data + off + 4))->bswap();
    }
    bswap__15disp_data_part2Fv(char_data + 0x370);
    bswap__12player_statsFv((void *)(char_data + 0x34C));
    ((TPlyDispConfig *)(char_data + 0x3C0))->bswap_pair();
}

void TPlyDispConfig::bswap_pair() { bswap__18TPlyDispConfigSmthFv((saddr)this); bswap__18TPlyDispConfigSmthFv((saddr)((char*)this + 0x24)); }
