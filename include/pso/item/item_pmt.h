#ifndef PSO_ITEM_ITEM_PMT_H
#define PSO_ITEM_ITEM_PMT_H

#include "types.h"

struct TObjPlayer;
class TObjChara;

// What the item sound players read: the item's group and index, the player
// using it and, for a hit, what it hit and which of its colliders.
struct ItemSoundRequest {
    s8 group;
    s8 index;
    u8 pad_2[2];
    TObjPlayer *player;
    s32 pad_8;
    TObjChara *target;
    s32 collider;

    void clear();
};

void free_item_pmt(void);
void load_item_pmt(void);
void load_items(void);
void unload_items(void);

#endif
