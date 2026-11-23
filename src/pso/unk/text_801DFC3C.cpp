#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlyCharData_801E0A04.h"
#include "pso/unk/text_801DF280.h"
#include "pso/unk/text_801DFC3C.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/network/protocol/packet_classes.h"

struct Obj_801DFC3C { u8 pad[0x600]; u32 w[30]; };

void bswap_player_record_upload(u8 *arg0) {
    s32 i;
    ((packet_header *)arg0)->bswap();
    bswap__12TPlyCharDataFv((saddr)(arg0 + 4));
    ((TPlyChallenge *)(arg0 + 0x420))->bswap();
    bswap_choice_search_config(arg0 + 0x53C);
    for (i = 0; i < 0x1E; i++) {
        bswap_32(&((Obj_801DFC3C *)arg0)->w[i]);
    }
    bswap_32((u32 *)(arg0 + 0x678));
}
