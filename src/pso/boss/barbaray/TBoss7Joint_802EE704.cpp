#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"

void G_BarbaRayBossActions_6xAA::bswap() {
    header.bswap();
    bswap_16((u16 *)&what);
    bswap_16((u16 *)&unknown_a2);
    bswap_32(&target_client_id);
}

void G_BarbaRayBossActions_6xA9::bswap() {
    header.bswap();
    bswap_16((u16 *)&what);
    bswap_16((u16 *)&unknown_a2);
}

void G_BarbaRayBossActions_6xA9::send() {
    bswap();
    send_subcommand(this);
}

void G_BarbaRayBossActions_6xA9::init() {
    header.subcommand = 0xA9;
    header.size = sizeof(*this) / 4;
}

void G_BarbaRayBossActions_6xAA::send() {
    bswap();
    send_subcommand(this);
}

void G_BarbaRayBossActions_6xAA::init() {
    header.subcommand = 0xAA;
    header.size = sizeof(*this) / 4;
}
