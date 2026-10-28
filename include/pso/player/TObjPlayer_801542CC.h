#ifndef PSO_PLAYER_TOBJPLAYER_801542CC_H
#define PSO_PLAYER_TOBJPLAYER_801542CC_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct Vec;

extern "C" {
// Gives the actor a copy of `count` collision bodies (once) and its contact
// list; returns the actor's bodies.
CollisionBody *init_collision_body_parts(TObjCollidable *actor, const CollisionBody *bodies, s32 count);
void free_collision_body_parts(TObjCollidable *actor);
void check_enemy_body_collisions(TObjCollidable *actor);
TObjBase *find_entity_by_id(u16 id);
s32 project_actor_to_ground(TObjChara *actor, Vec *pos, s32 flags);
}

#endif
