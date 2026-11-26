#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/network/TGameProtocol.h"
#include "pso/network/EntitySetFlagsCmd.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

void G_SetEntitySetFlags_6x76::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_16((u16 *)&floor);
    bswap_16((u16 *)&flags);
}

void G_SetEntitySetFlags_6x76::send() {
    bswap();
    send_subcommand(this);
}



void build_6x76_set_entity_set_flags(G_SetEntitySetFlags_6x76 *cmd) {
    cmd->header.subcommand = 0x76;
    cmd->header.size = sizeof(G_SetEntitySetFlags_6x76) / 4;
}

void append_wave_member(SendPlayerUpdateObject *o, SendPlayerUpdateItem *item) {
    if (o->count < o->max) {
        o->ptrs[o->count] = item;
        o->vals[o->count++] = item->v;
    }
}
