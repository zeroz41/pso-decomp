#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcBase.h"

extern "C" {
    extern const float lbl_805DB1C4;

#include "pso/misc/TNpcPlayer.h"

extern "C" {

void TNpcPlayer::send_6x3E() {
    s32 arg0 = (s32)this;
    bswap_6x3E();
    send_subcommand((u8 *)arg0);
}
void TNpcPlayer::bswap_6x3E() {
    s32 arg0 = (s32)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 8));
    bswap_16((u16 *)(arg0 + 0xA));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
}
void TNpcPlayer::init_6x3E_packet() { *(short *)&this->m_flags = 0; *(short *)&this->m_id = 0; *(short *)&this->m_prev = -1; *(short*)((char*)this + 0xa) = -1; *(float *)&this->m_down = lbl_805DB1C4; *(float *)&this->m_up = lbl_805DB1C4; *(float *)&this->m_next = lbl_805DB1C4; *(unsigned char *)&this->m_name = 62; *(unsigned char*)((char*)this + 0x1) = 6; }
void TObjNpcBringer::vfunc_88() {
    if ((s16) this->mode != 2) {
        this->m_b8 = 0;
        return;
    }
    this->m_b8 = 1;
}

}

}
