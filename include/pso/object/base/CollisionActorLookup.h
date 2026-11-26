#ifndef PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H
#define PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H

#include "types.h"

class TObjCollidable;

// Registered collision actor with this entity ID, including players.
extern "C" TObjCollidable *find_entity_by_id(u16 id);

// The entity table find_entity_by_id searches, sorted by entity id:
// entity_table_count entries in all, players (ids below 0x1000) first, then
// enemies (ids below 0x4000), then the other objects; the three counts split it.
extern TObjCollidable *entity_table[0x18C];
extern s32 entity_table_count;
extern s32 registered_player_count;
extern s32 registered_enemy_count;
extern s32 registered_object_count;

#endif
