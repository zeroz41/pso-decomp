#ifndef PSO_UNK_TEXT_80072230_H
#define PSO_UNK_TEXT_80072230_H

#include "types.h"

void TLobby__sub_800722AC(s32 index);
void send_own_challenge_records(void);

void handle_6x97_select_challenge_mode_failure_option(void *player);

struct SendChallengeTimeStack {
    s32 header;
    s32 client_id;
    s32 time;
    u8 trailing_storage[0x8];
};

struct ChallengeDeadFlagStack { s32 header; s32 client_id; u8 unused[8]; };

#endif
