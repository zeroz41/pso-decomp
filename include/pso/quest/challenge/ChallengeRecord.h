#ifndef PSO_QUEST_CHALLENGE_CHALLENGERECORD_H
#define PSO_QUEST_CHALLENGE_CHALLENGERECORD_H

#include "types.h"

// The rank awards of one challenge record set.
struct ChallengeAwardState {
    u32 award_flags;  // one bit per rank award already given
    s32 best_rank;    // stored obfuscated
};

// A character's challenge-mode records, kept in the save record at 0x21C4 and per client in a
// running challenge. The record sets follow TWindowSubStatusDisp::RecordSet.
struct ChallengeRecord {
    u16 title_color;
    u8 pad_2[2];
    s32 stage_times[9 + 5 + 9];          // EP1, EP2 and EP1 split-screen stages in turn, obfuscated
    u8 pad_60[0xC0 - 0x60];
    ChallengeAwardState awards[3];       // EP1, EP2 and EP1 split-screen
    char rank_title[0xC];                // obfuscated
    ChallengeAwardState ep2_split_award;
    s32 ep2_split_stage_times[5];
    u8 pad_100[4];
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeRecord_size, sizeof(ChallengeRecord) == 0x104);
LAYOUT_ASSERT(ChallengeRecord_awards, offsetof(ChallengeRecord, awards) == 0xC0);
LAYOUT_ASSERT(ChallengeRecord_rank_title, offsetof(ChallengeRecord, rank_title) == 0xD8);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_award, offsetof(ChallengeRecord, ep2_split_award) == 0xE4);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_stage_times, offsetof(ChallengeRecord, ep2_split_stage_times) == 0xEC);

#endif
