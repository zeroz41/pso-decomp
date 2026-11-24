#ifndef PSO_OBJECT_BASE_ACTORCOLLISION_H
#define PSO_OBJECT_BASE_ACTORCOLLISION_H

#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/CollisionBodySet.h"
#include "types.h"
#include "pso/object/base/TObjCollidable.h"

struct Vec;
class TObjChara;
struct CollisionBox;
struct CollisionSphere;
struct G_UpdateObjectState_6x0B;

// The actor bodies the last collect_body_contacts pass touched, each pair once.
extern ActorBodyHit player_unique_pair_entries[16];
extern int player_unique_pair_entry_count;
// The actors TObjPlayer::find_or_alloc_slot gave a slot, 0 for a free one.
extern saddr player_battle_param_table[16];

// Places the set's bodies at its position and adds every registered actor body
// they touch to player_unique_pair_entries: the players' (TObjPlayer::
// apply_status_effect), the enemies' or the other objects'.
void collect_enemy_body_contacts(CollisionBodySet *set);
void collect_object_body_contacts(CollisionBodySet *set);
void collect_body_contacts(CollisionBodySet *set, s32 start, s32 count);
int set_battle_param_slot(int slot, int actor);
CollisionBox *copy_collision_box(CollisionBox *dst, const CollisionBox *src);
void copy_collision_sphere(CollisionSphere *dst, CollisionSphere *src);
// The sphere of a body on the ground plane (y 0); 1 when written to *out.
s32 test_collider_sphere_overlap_xz(Vec origin, const CollisionBody *body, CollisionSphere *out);
// Pushes the actor out of the other actor's body it ran into (a sphere or a
// box); 1 when it moved.
s32 resolve_actor_sphere_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
s32 resolve_player_box_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
s32 respond_to_body_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
// Empties the entity table and the battle param slots.
void clear_entity_tables(void);

extern "C" {
// Gives the actor a copy of `count` collision bodies (once) and its contact
// list; returns the actor's bodies.
CollisionBody *init_collision_body_parts(TObjCollidable *actor, const CollisionBody *bodies, s32 count);
void free_collision_body_parts(TObjCollidable *actor);
void check_enemy_body_collisions(TObjCollidable *actor);
// Enters the actor in the id-sorted entity table; returns its entity id.
u16 register_entity_by_id(TObjCollidable *actor);
// The actor with this entity id if it can be hit on that collision body now,
// else NULL.
TObjChara *resolve_hittable_target(u16 actor_id, s16 collider);
// Drops pos onto the ground under it (from 10 units up, through the actor's
// ground cache when it has one); 1 if found, the ground normal in *normal.
s32 project_actor_to_ground(TObjCollidable *actor, Vec *pos, Vec *normal);
// The eight world corners of a box body of an actor at origin turned by
// facing; 1 when written to *out.
s32 build_collision_box_corners(Vec origin, s32 facing, CollisionBody *body, CollisionBox *out);
// Empties player_unique_pair_entries.
void reset_global_table(void);
// 1 if the actor's bodies at pos touch another registered non-player actor's;
// that body is copied to *out.
s32 test_player_overlap_with_players(void *, TObjCollidable *self, Vec *pos, CollisionBody *out);
}

#endif
