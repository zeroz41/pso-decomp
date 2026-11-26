#ifndef PSO_ITEM_TITEMATTACKCOLBASE_H
#define PSO_ITEM_TITEMATTACKCOLBASE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

// What TItemAttackColBase's constructor copies; reset_attack_params fills in
// the defaults. The derived attack colliders' parameter blocks start with it.
struct ItemAttackColParams {
    Vec position;
    f32 radius;      // the collision body's radius
    s32 hits;        // targets it may hit before it destroys itself
    u16 client_id;   // the attacking player's
    s16 room;
    s32 item_id;     // the weapon's, for find_item_by_id
    f32 accuracy;      // get_attack_accuracy_scale of the attacker
    f32 damage_scale;  // the attacker's damage multiplier
    s32 attack_kind;   // TItemWeapon::deliver_hit's attack_kind
};

// Fills in an ItemAttackColParams's defaults: no position, radius 5, one hit, no owner, room or weapon.
void reset_attack_params(ItemAttackColParams *params);

class TItemAttackColBase : public TObject {
public:
    TItemAttackColBase(TObject *parent, ItemAttackColParams *params);
    virtual ~TItemAttackColBase();
    void check_hits();
    s32 try_add_hit_target(const ActorBodyHit *hit);
    virtual void on_hit(ActorBodyHit *hit);
    s32 has_game_join_id();
    s32 resolve_attack_col_hit(ActorBodyHit *hit);
    CollisionBody *bodies;  // its one body below
    s32 body_count;
    Vec position;
    s32 rotation_y;
    CollisionBody body;
    ActorBodyHit hits[8];   // what it has hit so far
    s32 hit_count;
    s32 hits_left;
    u16 client_id; // compared with get_entity_id() and passed to get_player_by_client_id()
    s16 room;      // compared with the target's get_room()
    s32 item_id;
    f32 accuracy;       // the attacker's accuracy scale
    f32 damage_scale;   // TItemWeapon::deliver_hit's scale
    s32 attack_kind;    // TItemWeapon::deliver_hit's attack_kind
    s32 hits_players;   // 1 when the owner is in a player-vs-player state
    s32 hits_objects;   // 1: also hits objects, not only enemies
};

#endif
