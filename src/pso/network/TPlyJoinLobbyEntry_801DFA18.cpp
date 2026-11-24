#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlyCharData_801E0A04.h"

void TPlyJoinLobbyEntry::bswap() {
    tag.bswap();
    bswap_32(&ip_addr);
    bswap_32(&client_id);
    bswap__12TPlyCharDataFv((saddr)&char_data);
}
