#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/protocol.h"

void TProtocol::handle_cmd_95(packet &pkt) {
    s32 *arg1 = (s32 *)&pkt;
    s32 sp8;
    s32 (*temp_r12)();

    sp8 = *arg1;
    ((packet_header *)(&sp8))->bswap();
    temp_r12 = *(s32 (**)())((s8 *)this + 0xBC34);
    if (temp_r12 != NULL) {
        temp_r12();
    }
}
void TProtocol::handle_cmd_92(packet &pkt) {
    s32 *arg1 = (s32 *)&pkt;
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 (*temp_r12)(u8);
    sp8 = *(s32 *)((s8 *)arg1 + 0);
    ((packet_header *)(&sp8))->bswap();
    this->m_regist_state = (s32) *(u8 *)((s8 *)&sp8 + 0x1);
    temp_r12 = *(s32 (**)(u8))((s8 *)arg0 + 0xBC2C);
    if (temp_r12 != NULL) {
        temp_r12(*(u8 *)((s8 *)&sp8 + 0x1));
    }
}
