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

extern "C" CollisionBody *refresh_actor_body_spheres(CollisionBodySet source, CollisionBodySet destination);
extern "C" s32 test_player_overlap_with_players(TObjCollidable *actor, TObjCollidable *source, Vec *pos, CollisionBody *out);
extern "C" s32 test_player_body_overlap_at(TObjMapWarp *warp, TObjCollidable *player, const Vec *position);

#endif
