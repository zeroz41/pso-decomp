#ifndef PSO_ITEM_TUNK_804E355C_H
#define PSO_ITEM_TUNK_804E355C_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

// What TUnk_804E355C's constructor copies; TObjPlayer__sub_802E451C fills in
// the defaults. The derived attack colliders' parameter blocks start with it.
struct S_802E451C {
    Vec position;
    f32 radius;      // the collision body's radius
    s32 hits;        // targets it may hit before it destroys itself
    u16 client_id;   // the attacking player's
    s16 room;
    s32 item_id;     // the weapon's, for find_item_by_id
    f32 pad_1C;
    f32 pad_20;
    s32 pad_24;
};

// Fills in an S_802E451C's defaults (defined in TItemAttackCol.cpp).
extern "C" void TObjPlayer__sub_802E451C(S_802E451C *params);

class TUnk_804E355C : public TObject {
public:
    TUnk_804E355C(TObject *parent, S_802E451C *params);
    virtual ~TUnk_804E355C();
    void check_hits();
    s32 try_add_hit_target(void *);
    virtual void vfunc_6(s32 *);
    s32 has_game_join_id();
    s32 resolve_attack_col_hit(u8 *);
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
    f32 pad_B0;
    f32 pad_B4;
    s32 pad_B8;
    s32 pad_BC;
    s32 pad_C0;
};

#endif
