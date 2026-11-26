#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"

s32 info_board_state_flags;
TRecvInfoBoard *information_board_response_buffer;
void TLobby::init_once(TRecvInfoBoard *info_board) {
    if (!(info_board_state_flags & 2) && (information_board_response_buffer != NULL)) {
        info_board_state_flags |= 2;
        *information_board_response_buffer = *info_board;
    }
}

TRecvInfoBoard *TLobby::get_info_board_ptr() {
    TRecvInfoBoard *p;
    if (!(info_board_state_flags & 2)) {
        return NULL;
    }
    p = information_board_response_buffer;
    if (p != NULL) {
        return p;
    }
    return NULL;
}
