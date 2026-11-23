#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/quest/TQuestListOnline.h"

void TProtocol::handle_cmd_AC(packet &pkt) {
    if (pkt.pkt.header.flags == 0) {
        TQuestListOnline::handle_quest_ready();
        return;
    }
    this->m_is_invalid_packet = 1;
}
