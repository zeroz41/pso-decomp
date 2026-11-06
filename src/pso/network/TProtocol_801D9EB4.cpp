#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/quest/TQuestListOnline.h"

void TProtocol::handle_cmd_AC(packet &pkt) {
    void *arg1 = &pkt;
    if ((u8) *(u8 *)((s8 *)arg1 + 1) == 0) {
        TQuestListOnline::handle_quest_ready();
        return;
    }
    this->m_is_invalid_packet = 1;
}
