#ifndef PSO_OBJECT_BASE_TOBJCOLLIDABLE_H
#define PSO_OBJECT_BASE_TOBJCOLLIDABLE_H

#include "types.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>
#include "pso/object/CursorAction.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/data/FlagWord.h"

struct CsnGroundCandidates;

// One collision body of an actor (TObjCollidable::bodies points at the actor's
// array of them); init_collision_body_parts copies a static table of these.
struct CollisionBody {
    Vec offset;      // from the actor's position, turned by its y rotation
    f32 radius;      // a sphere's radius, a box's half depth (z)
    f32 half_width;  // a box's half width (x)
    s32 shape;       // 0 sphere, 1 box
    u32 flags;
    Vec center;      // offset placed in the world by refresh_collision_body_centers
    f32 defense;  // per-body defense value the bosses fill in from their parameter blocks (0 for plain bodies); name inferred
};
// *dst = *src, the copy CodeWarrior 1.3.2 generates (TBoss1DragonColli's TU).
void copy_collision_body(CollisionBody *dst, const CollisionBody *src);

class TObjCollidable : public TObjBase {
public:
    TObjCollidable(TObject *parent);
    virtual ~TObjCollidable();
    f32 get_collision_body_radius(s32);
    virtual void reset_motion_fields();
    CollisionBody *find_actor_body_contact(TObjCollidable *target, f32 limit);
    void set_indexed_flags(s32, s32);
    void clear_player_status_flag(s32, u32);
    // actorFlags & flags.
    s32 test_actor_flags(u32 flags);
    s32 access_object_saved_state(void *, s16);
    void sub_80156A68();
    // Empty in this build; the ancient trap and chainsaw call it from their demo and debug-draw updates.
    void sub_80154D78();
    void*set_collision_body(void*);
    void clear_collision_bodies();
    // Clear / set the collision flag (bit 1) of every body.
    void disable_all_bodies();
    void enable_all_bodies();
    // The radius of collision body `body`.
    f32 get_body_radius(s32 body);
    u32 check_actor_body_contact(void *, f32);
    void mark_enemy_body_contacts();
    void update_enemy_collision_flags();
    void check_object_collisions();
    // check_object_collisions, then the same against the enemies
    // (check_enemy_body_collisions); actors call it once per update.
    void update_collisions();
    void refresh_collision_body_centers();
    // Gives it an entity id if it has none and enters it in the id-sorted
    // entity table (unregister_object_by_id takes it out).
    void register_object_by_id();
    s32 unregister_object_by_id();
    void send_object_state_update(void *);
    // A player (client id, 0xFFFF for none) uses the action button on it.
    virtual void interact(u16 client);
    s32 set_flag8();
    s32 has_interactor();
    s32 get_cursor_action();
    void set_shadow_flag();
    void clear_shadow_flag();
    // The ground polygons project_actor_to_ground last found (csnVectorUnder's
    // cache), NULL to query without one.
    CsnGroundCandidates *ground_cache;
    u16 interactor;  // client id of the player interacting, 0xFFFF for none
    u16 hit_receive_state;  // 1 allows this object to receive hits
    CursorAction cursor_action;
    FlagWord *body_flags;  // one word per collision body
    FlagWord own_body_flags;  // body_flags of an actor with a single body
    CollisionBody *bodies;
    s32 body_count;
};
LAYOUT_ASSERT(TObjCollidableHitReceiveStateOffset, offsetof(TObjCollidable, hit_receive_state) == 0x96);

// The actor and collision body a weapon's hit reports.
struct ActorBodyHit {
    TObjCollidable *target;
    s32 body;  // index into target->bodies
};
void copy_actor_body_hit(ActorBodyHit *destination, const ActorBodyHit *source);

struct G_UpdateObjectState_6x0B;
void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet);

void free_collision_body_parts(TObjCollidable *actor);

#endif
