#ifndef PSO_QUEST_CHALLENGE_CHALLENGECOMMANDS_H
#define PSO_QUEST_CHALLENGE_CHALLENGECOMMANDS_H

#include "types.h"

struct G_SelectChallengeModeFailureOption_6x97;

void send_challenge_dead_flag(s32 index);
void send_own_challenge_records(void);

struct G_SelectChallengeModeFailureOption_6x97;
void handle_6x97_select_challenge_mode_failure_option(G_SelectChallengeModeFailureOption_6x97 *packet);

struct ChallengeDeadFlagStack { s32 header; s32 client_id; u8 unused[8]; };
void send_challenge_retry_cmd(s32 choice);

#endif
