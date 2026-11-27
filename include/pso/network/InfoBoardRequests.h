#ifndef PSO_NETWORK_INFOBOARDREQUESTS_H
#define PSO_NETWORK_INFOBOARDREQUESTS_H

#include "types.h"

struct TRecvInfoBoard;

void set_info_board_text(char *text);
void reset_info_board();
void request_info_board(TRecvInfoBoard *buffer);
void flush_pending_send();

#endif
