#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlyCharData_801E0A04.h"
#include "pso/unk/text_801DF280.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/network/protocol/packet_classes.h"

void TPlyJoinData::bswap() {
    header.bswap();
    bswap__12TPlyCharDataFv((saddr)&char_data);
    challenge.bswap();
    choice_search_config.bswap();
    for (int i = 0; i < 30; i++) {
        bswap_32(&blocked_senders[i]);
    }
    bswap_32(&auto_reply_enabled);
}
