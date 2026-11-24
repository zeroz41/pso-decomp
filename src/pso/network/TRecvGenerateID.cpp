#include "pso/network/protocol/packet_classes.h"

void TRecvGenerateID::bswap() {
    header.bswap();
    bswap_32(&client_id);
    tag.bswap();
}

void TGenGuildCardTag::bswap() {
    bswap_16(&tag2);
    bswap_32(&guildcard_number);
}
