#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"

struct TWindowMessage;

// One record set's award: the award bits and the encoded grade (0 none, 1 B, 2 A, 3 S).
struct ChallengeStageRank {
    u32 award_flags;
    s32 rank;
};

struct ChallengeRecord;

// A record set's stage times and rank (TWindowSubStatusDisp::RecordSet, -1 for the current one).
extern "C" {
s32 *TWindowSubStatusDisp__sub_8006F0D8(ChallengeRecord *record, s32 slot);
ChallengeStageRank *TWindowSubStatusDisp__sub_8006F134(ChallengeRecord *record, s32 slot);
}

// A character's challenge-mode records, kept in the save record at 0x21C4 and per client in
// ChallengeModeState::client_records. The record sets follow TWindowSubStatusDisp::RecordSet.
struct ChallengeRecord {
    u16 title_color;
    s16 pad_2;
    s32 stage_times[9 + 5 + 9];          // EP1, EP2 and EP1 split-screen stages in turn, obfuscated
    u32 pad_60[20];
    u32 pad_B0[2];
    u32 pad_B8[2];
    ChallengeStageRank ranks[3];         // EP1, EP2 and EP1 split-screen
    char rank_title[0xC];                // obfuscated
    ChallengeStageRank ep2_split_rank;
    s32 ep2_split_stage_times[5];
};

// A challenge rank's threshold, set by the quest: a clear time at or under `time` earns
// `award_flags` (checked against the record set's ChallengeStageRank::award_flags).
struct ChallengeRankThreshold {
    s32 time;
    u32 award_flags;
    u32 pad_8[5];
};

// A client's challenge records as received from the server.
struct ChallengeClientRecords {
    s32 present;
    ChallengeRecord records;
};

// The running challenge-mode session. Both structs are copied with their implicit operator=
// (challenge_settings_defaults resets the session); the copy code fixes the member split.
struct ChallengeModeState {
    s32 pad_0;
    f32 pad_4;
    s32 current_floor;        // the floor the challenge time window was last made for (inferred)
    s32 pad_C;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
    s32 pad_1C;
    s32 pad_20;
    s32 pad_24;
    s32 pad_28;
    s32 pad_2C;
    s32 pad_30;
    s32 retry_menu_disabled;  // set by the quest opcode that disables the retry menu
    s32 client_died[4];       // per client: listed in the dead-list window
    s32 record_window_mode;   // 0 closed, 1/2 progress, 3..0x10 a stage's times
    TWindowMessage *record_window;
    u32 pad_50[2];
    s32 pad_58;
    u32 pad_5C[0x70];
    ChallengeRankThreshold rank_thresholds[3];
    ChallengeClientRecords client_records[4];
    s32 pad_680[4];
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeRecord_size, sizeof(ChallengeRecord) == 0x100);
LAYOUT_ASSERT(ChallengeRecord_ranks, offsetof(ChallengeRecord, ranks) == 0xC0);
LAYOUT_ASSERT(ChallengeRecord_rank_title, offsetof(ChallengeRecord, rank_title) == 0xD8);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_rank, offsetof(ChallengeRecord, ep2_split_rank) == 0xE4);
LAYOUT_ASSERT(ChallengeRecord_ep2_split_stage_times, offsetof(ChallengeRecord, ep2_split_stage_times) == 0xEC);
LAYOUT_ASSERT(ChallengeClientRecords_size, sizeof(ChallengeClientRecords) == 0x104);
LAYOUT_ASSERT(ChallengeModeState_rank_thresholds, offsetof(ChallengeModeState, rank_thresholds) == 0x21C);
LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;
extern ChallengeModeState challenge_settings_defaults;
// The split-screen challenge (TChallenge4P) keeps its own session and defaults.
extern ChallengeModeState challenge4p_mode_state;
extern ChallengeModeState challenge_default_settings;

#endif
