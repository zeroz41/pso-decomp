#ifndef PSO_OBJECT_BASE_ACTORCOLLISION_H
#define PSO_OBJECT_BASE_ACTORCOLLISION_H

#include "pso/object/base/CollisionActorLookup.h"
#include "pso/map/CsnGroundQuery.h"
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
// The actors find_or_alloc_battle_param_slot gave a slot, 0 for a free one.
extern TObjChara *player_battle_param_table[16];

// Places the set's bodies at its position and adds every registered actor body
// they touch to player_unique_pair_entries: the players', the enemies' or the
// other objects'.
void collect_player_body_contacts(CollisionBodySet *set);
void collect_enemy_body_contacts(CollisionBodySet *set);
void collect_object_body_contacts(CollisionBodySet *set);
void collect_body_contacts(CollisionBodySet *set, s32 start, s32 count);
// Enters (target, body) in the hit pair table unless it is already there.
void add_unique_pair_entry(TObjCollidable *target, s32 body);
// 1 if two bodies with these flags can touch / hit each other.
s32 check_body_flag_pair(s32 flags, s32 other_flags);
s32 check_body_flags(s32 flags, s32 other_flags);
// Empties the entity table.
void clear_entity_table();
// Frees every battle param slot.
void clear_battle_param_slots();
// The slot the actor has, else a free one given to it; -1 when all are taken.
s32 find_or_alloc_battle_param_slot(TObjChara *actor);
int set_battle_param_slot(int slot, TObjChara *actor);
CollisionBox *copy_collision_box(CollisionBox *dst, const CollisionBox *src);
void copy_collision_sphere(CollisionSphere *dst, CollisionSphere *src);
// The sphere of a body on the ground plane (y 0); 1 when written to *out.
s32 test_collider_sphere_overlap_xz(Vec origin, const CollisionBody *body, CollisionSphere *out);
// Pushes the actor out of the other actor's body it ran into (a sphere or a
// box); 1 when it moved.
s32 resolve_actor_sphere_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
s32 resolve_player_box_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
s32 respond_to_body_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact);
// Empties the entity table and the battle param slots; init_entity_tables also
// zeroes the registered actor counts.
void init_entity_tables();
void clear_entity_tables(void);

extern "C" {
// Gives the actor a copy of `count` collision bodies (once) and its contact
// list; returns the actor's bodies.
CollisionBody *init_collision_body_parts(TObjCollidable *actor, const CollisionBody *bodies, s32 count);
}
void check_enemy_body_collisions(TObjCollidable *actor);
// Enters the actor in the id-sorted entity table; returns its entity id.
u16 register_entity_by_id(TObjCollidable *actor);
extern "C" {
// The actor with this entity id if it can be hit on that collision body now,
// else NULL.
TObjChara *resolve_hittable_target(u16 actor_id, s16 collider);
}
// The eight world corners of a box body of an actor at origin turned by
// facing; 1 when written to *out.
s32 build_collision_box_corners(Vec origin, s32 facing, CollisionBody *body, CollisionBox *out);
// Empties player_unique_pair_entries.
void reset_global_table(void);

#endif
