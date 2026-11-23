#include "types.h"
#include "pso/unk/text_80074BD0.h"
#include "pso/unk/text_80074C70.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

s32 TLobby::start_lobby_name_request() {
    fn_80074C70();
    if (protocol_instance == NULL) {
        return 0;
    }
    protocol_instance->m_recv_handlers.handle_8A_lobby_name_packet = (recv_packet_handler_handle_8A_lobby_name_packet)fn_80074BD0;
    protocol_instance->send_lobby_name_request();
    return 1;
}
