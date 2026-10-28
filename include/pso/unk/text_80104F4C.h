#ifndef PSO_UNK_TEXT_80104F4C_H
#define PSO_UNK_TEXT_80104F4C_H

#include "types.h"

struct TItem;
struct TItemData;
struct TObjPlayer;

// The one equipped item item combines with, or NULL when none or several do.
TItem *find_unique_combination_target(TObjPlayer *player, TItemData *item);

#endif
