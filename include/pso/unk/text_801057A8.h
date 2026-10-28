#ifndef PSO_UNK_TEXT_801057A8_H
#define PSO_UNK_TEXT_801057A8_H

#include "types.h"

struct FloorItem;

extern "C" {
// Creates the item a 6x5D/6x5F drop describes and puts it on the floor.
void *spawn_dropped_item_from_msg(FloorItem *drop, s32 quiet);
}

#endif
