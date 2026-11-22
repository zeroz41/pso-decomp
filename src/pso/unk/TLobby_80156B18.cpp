#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_80156B18.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"


void TLobby::bswap_60_header(void* p) { ((TLobby *)p)->bswap_header(); }
void TLobby::bswap_header() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
}
void TLobby::update_and_send_60() {
    saddr arg0 = (saddr)this;
    TLobby::bswap_60_header(this);
    send_subcommand((u8 *)arg0);
}
void TLobby__sub_80156BA8(void* p) { *(u8*)((char*)p + 0x0) = 11; *(u8*)((char*)p + 0x1) = 3; }

