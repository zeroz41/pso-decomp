#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"

struct TWindowMessage;

// One record set's award: the award bits and the encoded grade (0 none, 1 B, 2 A, 3 S).
struct ChallengeStageRank {
    u32 award_flags;
    s32 rank;
};

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

// A client's challenge records as received from the server.
struct ChallengeClientRecords {
    s32 present;
    ChallengeRecord records;
};

// The running challenge-mode session.
struct ChallengeModeState {
    u8 pad_0[0x34];
    s32 retry_menu_disabled;  // set by the quest opcode that disables the retry menu
    s32 client_died[4];       // per client: listed in the dead-list window
    s32 record_window_mode;   // 0 closed, 1/2 progress, 3..0x10 a stage's times
    TWindowMessage *record_window;
    u8 pad_50[0x270 - 0x50];
    ChallengeClientRecords client_records[4];
    u8 pad_680[0x690 - 0x680];
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeRecord_size, sizeof(ChallengeRecord) == 0x100);
LAYOUT_ASSERT(ChallengeRecord_ranks, offsetof(ChallengeRecord, ranks) == 0xC0);
LAYOUT_ASSERT(ChallengeRecord_rank_title, offsetof(ChallengeRecord, rank_title) == 0xD8);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_rank, offsetof(ChallengeRecord, ep2_split_rank) == 0xE4);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_stage_times, offsetof(ChallengeRecord, ep2_split_stage_times) == 0xEC);
LAYOUT_ASSERT(ChallengeClientRecords_size, sizeof(ChallengeClientRecords) == 0x104);
LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;

#endif
