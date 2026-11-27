#ifndef PSO_UNK_TLOBBY_SESSION_H
#define PSO_UNK_TLOBBY_SESSION_H

#include "types.h"

void reset_quest_collision_ids_on_floor_load(void);
void reset_quest_collision_ids_on_floor_free(void);

struct CollectActiveCardIdsL { u8 pad0; u8 count; u8 pad2[2]; s32 ids[30]; };

#endif
