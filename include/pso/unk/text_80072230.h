#ifndef PSO_UNK_TEXT_80072230_H
#define PSO_UNK_TEXT_80072230_H

#include "types.h"

extern "C" {
void TLobby__sub_800722AC(s32 client_id);
}
void send_own_challenge_records(void);

void handle_6x97_select_challenge_mode_failure_option(void *player);

#endif
