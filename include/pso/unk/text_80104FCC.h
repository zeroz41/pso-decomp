#ifndef PSO_UNK_TEXT_80104FCC_H
#define PSO_UNK_TEXT_80104FCC_H

#include "types.h"

extern "C" {
int roll_weapon_special_channel15(void *p);
// Whether `player` meets the item's requirements; *requirement gets the
// stat it falls short on.
s32 check_equip_requirements(void *player, void *item, s32 *requirement);
}

// --- C functions defined in text_80104FCC.cpp ---
extern "C" {
int roll_weapon_special_channel15(void *p);
}
// --- end of C functions

#endif
