#ifndef PSO_PLAYER_TOBJPLAYER_801542CC_H
#define PSO_PLAYER_TOBJPLAYER_801542CC_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct Vec;
class TObjChara;

extern "C" {
// Gives the actor a copy of `count` collision bodies (once) and its contact
// list; returns the actor's bodies.
CollisionBody *init_collision_body_parts(TObjCollidable *actor, const CollisionBody *bodies, s32 count);
void free_collision_body_parts(TObjCollidable *actor);
void check_enemy_body_collisions(TObjCollidable *actor);
// The registered actor with this entity id (players below 12), or NULL.
TObjCollidable *find_entity_by_id(u16 id);
// The actor with this entity id if it can be hit on that collision body now,
// else NULL.
TObjChara *resolve_hittable_target(u16 actor_id, s16 collider);
s32 project_actor_to_ground(TObjChara *actor, Vec *pos, s32 flags);
// The radius of the actor's collision body, or a default without bodies.
f32 get_collision_body_radius(TObjCollidable *actor, s32 body);
}

// The entity table: players fill its first registered_player_count slots.
extern s32 registered_player_count;

#endif
