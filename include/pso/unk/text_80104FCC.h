#ifndef PSO_UNK_TEXT_80104FCC_H
#define PSO_UNK_TEXT_80104FCC_H

#include "types.h"

struct TObjPlayer;
struct TItemData;

u8 roll_weapon_special_channel15(u8 stars);
// Whether the player's class has every class bit perm asks for.
int check_class_equip_permission(TObjPlayer *player, s32 perm);
extern "C" {
// Whether `player` meets the item's requirements; *requirement gets the
// stat it falls short on.
s32 check_equip_requirements(void *player, TItemData *item, s32 *requirement);
}

struct TItem;
struct TItemData;
// Builds the item object for `data` with its type's create function.
TItem *construct_item(TItemData *data);

// --- C functions defined in text_80104FCC.cpp ---
u8 roll_weapon_special_channel15(u8 stars);
// --- end of C functions

#endif
