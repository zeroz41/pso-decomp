#ifndef PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H
#define PSO_OBJECT_BASE_COLLISION_ACTOR_LOOKUP_H

#include "types.h"

class TObjCollidable;

// Registered collision actor with this entity ID, including players.
extern "C" TObjCollidable *find_entity_by_id(u16 id);

// The entity table find_entity_by_id searches, sorted by entity id:
// lbl_805D5868 entries in all, players (ids below 0x1000) first, then
// enemies (ids below 0x4000), then the rest.
extern s32 lbl_805D5868;
extern s32 registered_player_count;
extern s32 registered_enemy_count;

#endif
