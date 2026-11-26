#ifndef PSO_PLAYER_PLAYERTRAPCOUNTS_H
#define PSO_PLAYER_PLAYERTRAPCOUNTS_H

#include "types.h"

// A player's sonar uses left in a battle (0..99, set from the battle rules,
// used up when the sonar task starts).
class PlayerSonarStock {
public:
    s32 count;

    PlayerSonarStock();

    s32 consume(s32 amount);
    s32 get_count();
    void set_count(s32 count);
};

// A player's trap stock, one count per trap kind (0..20).
class PlayerTrapCounts {
public:
    s8 counts[4];

    bool is_empty(s32 kind);
    void clear();
    s32 is_full(s32 level, s8 char_class);
    void refill(s32 level, s8 char_class);
    s32 consume(s32 amount, s32 kind);
    s8 get_count(s32 kind);
    void set_count(s8 count, s32 kind);
    PlayerTrapCounts();
};

// Only the android classes (HUcast, RAcast, RAcaseal, HUcaseal) carry traps;
// their stock grows with level and is capped at 20.
s8 calc_trap_capacity(s32 level, s8 char_class, s32 kind);

#endif
