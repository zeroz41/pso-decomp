#ifndef PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H
#define PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H

#include "types.h"

class TObjCollidable;

// Registered collision actor with this entity ID, including players.
extern "C" TObjCollidable *find_entity_by_id(u16 id);

#endif
