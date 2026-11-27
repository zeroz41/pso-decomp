#ifndef PSO_OBJECT_BASE_COLLISIONBODYSET_H
#define PSO_OBJECT_BASE_COLLISIONBODYSET_H

#include "pso/system/vector.h"

struct CollisionBody;
class TObjCollidable;
struct TObjMapWarp;

struct CollisionBodySet {
    CollisionBody *colliders;
    s32 count;
    Vec position;
    s32 facing;
};

CollisionBody *refresh_actor_body_spheres(CollisionBodySet source_set, CollisionBodySet destination_set);
// 1 if source's bodies at pos touch another registered non-player actor's;
// that body is copied to *out.
s32 test_player_overlap_with_players(TObjCollidable *actor, TObjCollidable *source, Vec *pos, CollisionBody *out);
s32 test_player_body_overlap_at(TObjMapWarp *warp, TObjCollidable *player, const Vec *position);

#endif
