#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_8015C944.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/misc/TLobby.h"

extern "C" {

void TLobby::byteswap_and_send() {
    s32 arg0 = (s32)this;
    ((s32 (*)())byteswap_event_packet__6TLobbyFi)();
    send_subcommand((u8 *)arg0);
}

void byteswap_event_packet__6TLobbyFi(s32 packet) {
    ((G_ClientIDHeader *)packet)->bswap();
    bswap_32((u32 *)(packet + 4));
    bswap_32((u32 *)(packet + 8));
    bswap_32((u32 *)(packet + 0xC));
}
void TLobby::init_packet_67_04() { *(u8 *)&this->m_name = 103; *(u8*)((char*)this + 0x1) = 4; }

}
