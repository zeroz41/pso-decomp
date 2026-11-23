#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DF280.h"

void TProtocol::handle_cmd_C0(packet &pkt) {
    TRecvChoiceSearchOptions tmp = as(TRecvChoiceSearchOptions &, pkt);
    bswap_c0_lobby_entries(&tmp);
    if (m_recv_handlers.handle_C0_choice_search_option_packet != NULL) {
        m_recv_handlers.handle_C0_choice_search_option_packet(&tmp);
    }
}
