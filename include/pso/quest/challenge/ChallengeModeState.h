#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"
#include "pso/quest/challenge/ChallengeRecord.h"

struct TWindowMessage;

// A record set's stage times and rank (TWindowSubStatusDisp::RecordSet, -1 for the current one).
extern "C" {
s32 *TWindowSubStatusDisp__sub_8006F0D8(ChallengeRecord *record, s32 slot);
ChallengeStageRank *TWindowSubStatusDisp__sub_8006F134(ChallengeRecord *record, s32 slot);
}

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
    s32 stage;                // indexes the record set's stage times (inferred)
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
LAYOUT_ASSERT(ChallengeClientRecords_size, sizeof(ChallengeClientRecords) == 0x104);
LAYOUT_ASSERT(ChallengeModeState_rank_thresholds, offsetof(ChallengeModeState, rank_thresholds) == 0x21C);
LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;
extern ChallengeModeState challenge_settings_defaults;
// The split-screen challenge (TChallenge4P) keeps its own session and defaults.
extern ChallengeModeState challenge4p_mode_state;
extern ChallengeModeState challenge_default_settings;

#endif
