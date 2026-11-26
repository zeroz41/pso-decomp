#ifndef PSO_PLAYER_EQUIPPEDITEMSLOT_H
#define PSO_PLAYER_EQUIPPEDITEMSLOT_H

#include "types.h"

// An equipped item and the slot it sits in, kept while apply_battle_level_reset rebuilds the stats.
struct EquippedItemSlot {
    EquippedItemSlot() {
        slot = 0;
        item = NULL;
    }

    s16 slot;
    TItem *item;
};

#endif
