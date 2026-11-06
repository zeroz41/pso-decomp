#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/protocol.h"

void TProtocol::handle_cmd_97(packet &pkt) {
    s32 *arg1 = (s32 *)&pkt;
    s32 sp8;
    u8 temp_r3;
    s32 (*temp_r12)(u8);

    sp8 = *arg1;
    ((packet_header *)(&sp8))->bswap();
    temp_r3 = *(u8 *)((s8 *)&sp8 + 1);
    temp_r12 = *(s32 (**)(u8))((s8 *)this + 0xBC44);
    if (temp_r12 != NULL) {
        temp_r12(temp_r3);
    }
}
