#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"

struct TWindowMessage;

// One stage's award: the award bits and the encoded grade (0 none, 1 B, 2 A, 3 S).
struct ChallengeStageRank {
    u32 award_flags;
    s32 rank;
};

// A client's challenge records as received from the server.
struct ChallengeClientRecords {
    s32 present;
    u8 records[0x100];
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

LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;

#endif
