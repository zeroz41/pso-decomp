#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"
#include "pso/quest/challenge/ChallengeRecord.h"

struct TWindowMessage;

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

// A title the quest gives a character whose decoded rank title is `match` (set_cmode_rank_override).
struct ChallengeRankOverride {
    char match[0xC];   // obfuscated
    char title[0xC];   // obfuscated
    s32 color;         // ARGB
};

// The running challenge-mode session. Both structs are copied with their implicit operator=
// (challenge_settings_defaults resets the session); the copy code fixes the member split.
struct ChallengeModeState {
    s32 stage;                // indexes the record set's stage times
    f32 exp_multiplier;       // set by the exp_multiplication quest opcode
    s32 current_floor;        // the floor the challenge time window was last made for
    s32 base_time;            // set by the set_cmode_base_time quest opcode
    s32 min_clear_time;       // encoded; challenge_min_clear_time decodes it
    s32 result_rank;          // the rank check_challenge_rank_time gave, negative on failure
    s32 rank_result_color;    // ARGB colour of rank_result_title
    s32 rank_override_count;  // entries of rank_overrides in use
    s32 failed;               // set once any (or every) player died
    s32 retry_choice;         // the retry menu's answer after a failure
    s32 retry_confirmed;      // set when the retry countdown ran out
    s32 boss_warp_disabled;   // set by the disable_bosswarp_option quest opcode
    s32 solo_play_notice_shown; // the solo play notice closed; it is not shown again
    s32 retry_menu_disabled;  // set by the quest opcode that disables the retry menu
    s32 client_died[4];       // per client: listed in the dead-list window
    s32 record_window_mode;   // 0 closed, 1/2 progress, 3..0x10 a stage's times
    TWindowMessage *record_window;
    char rank_result_title[0xC]; // obfuscated; the title for a character no override matches
    ChallengeRankOverride rank_overrides[16];
    ChallengeRankThreshold rank_thresholds[3];
    ChallengeClientRecords client_records[4];
    s32 client_time_records[4]; // per client, encoded: the time each one reported
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeClientRecords_size, sizeof(ChallengeClientRecords) == 0x104);
LAYOUT_ASSERT(ChallengeRankOverride_size, sizeof(ChallengeRankOverride) == 0x1C);
LAYOUT_ASSERT(ChallengeModeState_rank_thresholds, offsetof(ChallengeModeState, rank_thresholds) == 0x21C);
LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;
extern ChallengeModeState challenge_settings_defaults;
// The split-screen challenge (TChallenge4P) keeps its own session and defaults.
extern ChallengeModeState challenge4p_mode_state;
extern ChallengeModeState challenge_default_settings;

#endif
