#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODESTATE_H

#include "types.h"

// The running challenge-mode session.
struct ChallengeModeState {
    u8 pad_0[0x34];
    s32 retry_menu_disabled;  // set by the quest opcode that disables the retry menu
    s32 client_died[4];       // per client: listed in the dead-list window
    u8 pad_48[0x690 - 0x48];
};

LAYOUT_ASSERT(ChallengeModeState_size, sizeof(ChallengeModeState) == 0x690);

extern ChallengeModeState challenge_mode_state;

#endif
