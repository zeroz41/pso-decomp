#ifndef PSO_QUEST_CHALLENGE_CHALLENGERECORD_H
#define PSO_QUEST_CHALLENGE_CHALLENGERECORD_H

#include "types.h"
#include <stddef.h>
#include "pso/object/TObjTombstoneRecord.h"

// One record set's award: the award bits and the encoded grade (0 none, 1 B, 2 A, 3 S).
struct ChallengeStageRank {
    u32 award_flags;
    s32 rank;
    void bswap();
};

// The record sets of a ChallengeRecord. resolve_challenge_record_set maps RECORD_SET_CURRENT to the
// running game's set by selected_episode and is_split_screen; the sets have 9/5/9/5 stages.
enum ChallengeRecordSet {
    RECORD_SET_CURRENT = -1,
    RECORD_SET_EP1,
    RECORD_SET_EP2,
    RECORD_SET_EP1_SPLIT,
    RECORD_SET_EP2_SPLIT
};

// Swaps one stage time of a ChallengeRecord.
void bswap_packet_field(s32 *value);

// A character's challenge-mode records, kept in the save record at 0x21C4 and per client in
// ChallengeModeState::client_records. The record sets follow TWindowSubStatusDisp::RecordSet.
struct ChallengeRecord {
    u16 title_color;
    s16 pad_2;
    s32 stage_times[9 + 5 + 9];          // EP1, EP2 and EP1 split-screen stages in turn, obfuscated
    TObjTombstoneRecord tombstone;       // where the character last died (inferred)
    TObjTombstoneSpot tombstone_spot;    // the split-screen challenge's grave (inferred)
    ChallengeStageRank ranks[3];         // EP1, EP2 and EP1 split-screen
    char rank_title[0xC];                // obfuscated
    ChallengeStageRank ep2_split_rank;
    s32 ep2_split_stage_times[5];
    void bswap();
};

LAYOUT_ASSERT(ChallengeRecord_size, sizeof(ChallengeRecord) == 0x100);
LAYOUT_ASSERT(ChallengeRecord_tombstone, offsetof(ChallengeRecord, tombstone) == 0x60);
LAYOUT_ASSERT(ChallengeRecord_tombstone_spot, offsetof(ChallengeRecord, tombstone_spot) == 0xB0);
LAYOUT_ASSERT(ChallengeRecord_ranks, offsetof(ChallengeRecord, ranks) == 0xC0);
LAYOUT_ASSERT(ChallengeRecord_rank_title, offsetof(ChallengeRecord, rank_title) == 0xD8);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_rank, offsetof(ChallengeRecord, ep2_split_rank) == 0xE4);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_stage_times, offsetof(ChallengeRecord, ep2_split_stage_times) == 0xEC);

// set: a ChallengeRecordSet.
s32 resolve_challenge_record_set(s32 set);
s32 challenge_set_stage_count(s32 set);
// The valid range of a set's total time: 300 seconds to 9:59:59 per stage.
s32 challenge_set_min_time(s32 set);
s32 challenge_set_max_time(s32 set);
s32 *challenge_set_stage_times(ChallengeRecord *record, s32 set);
ChallengeStageRank *challenge_set_rank(ChallengeRecord *record, s32 set);

#endif
