#include "types.h"
#include "pso/network/TProtocol.h"

void TProtocol::handle_cmd_AB(packet &pkt) {
    void *protocol = &pkt;
    s32 (*temp_r12)(u16);

    ((TProtocol *)protocol)->bswap_cmd_AB();
    temp_r12 = *(s32 (**)(u16))((s8 *)this + 0xBC94);
    if (temp_r12 != NULL) {
        temp_r12(((TProtocol *)protocol)->m_flags);
    }
}
