#ifndef PSO_NETWORK_INFOBOARDSTATE_H
#define PSO_NETWORK_INFOBOARDSTATE_H

#include "types.h"

struct TRecvInfoBoard;

TRecvInfoBoard *get_info_board_ptr();

extern s32 info_board_state_flags;
extern TRecvInfoBoard *information_board_response_buffer;

#endif
