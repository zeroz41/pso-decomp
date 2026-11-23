#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

s32 info_board_state_flags;
TRecvInfoBoard *information_board_response_buffer;
void TLobby::init_once(TRecvInfoBoard *info_board) {
    if (!(info_board_state_flags & 2) && (information_board_response_buffer != NULL)) {
        info_board_state_flags |= 2;
        *information_board_response_buffer = *info_board;
    }
}

void *TLobby::get_info_board_ptr() {
    void *p;
    if (!(info_board_state_flags & 2)) {
        return NULL;
    }
    p = (void *)information_board_response_buffer;
    if (p != NULL) {
        return p;
    }
    return NULL;
}
