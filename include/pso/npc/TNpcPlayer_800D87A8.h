#ifndef PSO_NPC_TNPCPLAYER_800D87A8_H
#define PSO_NPC_TNPCPLAYER_800D87A8_H

#include "types.h"

class TObjCollidable;

// An active collision object in the entity table, or NULL.
extern "C" TObjCollidable *find_active_entity_by_id(u16 id);
// The active object in a battle slot, or NULL.
TObjCollidable *get_valid_target_player(int id);

#endif
