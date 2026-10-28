#ifndef PSO_MISC_TECHNIQUEBOOST_H
#define PSO_MISC_TECHNIQUEBOOST_H

#include "types.h"

// One technique boost an equipped item gives its owner: the technique it
// raises, flags OR'd into get_technique_caster_flags and an amount added by
// calc_technique_boost.
struct TechniqueBoost {
    s16 technique;  // -1: no boost
    u16 flags;
    f32 amount;

    TechniqueBoost();
    void clear();
    void copy_from(TechniqueBoost *src);
};

// A technique boost as an item's parameter table gives it (three per item).
struct TechniqueBoostParam {
    s8 technique;
    u8 flags;
    f32 amount;
};

// The technique boosts of one player: three from the weapon, three from the
// shield (TItemEquipBase::register_technique_boosts).
struct TechniqueBoostTable {
    TechniqueBoost boosts[6];

    void set(s32 index, TechniqueBoost *boost);
    void clear();
};

// Stores a technique boost of an item in slot `index` of player `client`'s table.
void set_technique_boost(TechniqueBoost *boost, u16 client, s32 index);

#endif
