#include "pso/network/protocol/packet_classes.h"

void TUserAns::bswap() {
    header.bswap();
    tag.bswap();
    bswap_32(&found_guildcard);
    recv_port.bswap();
    extension.bswap();
}
