#ifndef PSO_PLAYER_PLAYERTECHNIQUESTATE_H
#define PSO_PLAYER_PLAYERTECHNIQUESTATE_H

#include <stddef.h>
#include "types.h"
#include "pso/system/data/FlagWord.h"

// A player's techniques (TObjPlayer + 0x428): the cast in progress, its
// targets and the level of each of the 19 techniques.
class PlayerTechniqueState {
public:
    PlayerTechniqueState();
    void reset_all_tech_slots();
    void reset_tech_state();

    u8 pad_0[0x2];
    u8 pad_2;
    u8 pad_3;
    u8 pad_4[0x6];
    s16 pad_a;
    u8 pad_c[0x4];
    FlagWord flags;
    u8 pad_14[0xC];
    u8 targets[0x28];
    u8 pad_48[0x14];
    u8 levels[0x14];
    u8 caps[0x14];
};

LAYOUT_ASSERT(PlayerTechniqueStateSize, sizeof(PlayerTechniqueState) == 0x84);
LAYOUT_ASSERT(PlayerTechniqueStateLevels, offsetof(PlayerTechniqueState, levels) == 0x5C);

#endif
