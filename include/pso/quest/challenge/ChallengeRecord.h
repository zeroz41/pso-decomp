#ifndef PSO_QUEST_CHALLENGE_CHALLENGERECORD_H
#define PSO_QUEST_CHALLENGE_CHALLENGERECORD_H

#include "types.h"
#include "pso/quest/challenge/ChallengeModeState.h"

// A character's challenge-mode records, kept in the save record at 0x21C4 and per client in
// ChallengeModeState::client_records. The record sets follow TWindowSubStatusDisp::RecordSet.
struct ChallengeRecord {
    u16 title_color;
    u8 pad_2[2];
    s32 stage_times[9 + 5 + 9];          // EP1, EP2 and EP1 split-screen stages in turn, obfuscated
    u8 pad_60[0xC0 - 0x60];
    ChallengeStageRank ranks[3];         // EP1, EP2 and EP1 split-screen
    char rank_title[0xC];                // obfuscated
    ChallengeStageRank ep2_split_rank;
    s32 ep2_split_stage_times[5];
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeRecord_size, sizeof(ChallengeRecord) == 0x100);
LAYOUT_ASSERT(ChallengeRecord_ranks, offsetof(ChallengeRecord, ranks) == 0xC0);
LAYOUT_ASSERT(ChallengeRecord_rank_title, offsetof(ChallengeRecord, rank_title) == 0xD8);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_rank, offsetof(ChallengeRecord, ep2_split_rank) == 0xE4);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_stage_times, offsetof(ChallengeRecord, ep2_split_stage_times) == 0xEC);

#endif
