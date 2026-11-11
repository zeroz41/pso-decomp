#ifndef PSO_WEAPON_TITEMATTACKCOL_H
#define PSO_WEAPON_TITEMATTACKCOL_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

#include "pso/system/data/FlagWord.h"

class TEffStarLight2D;
class TParticleCtrl;

// Called when the collider hits a wall (or at once for an instant one):
// the weapon's item id, where it is and its velocity.
typedef void (*TItemAttackColHitWall)(s32 item_id, Vec *position, Vec *velocity);
// Called for each target it hits: the weapon's item id, the target's
// ActorBodyHit entry and the collider's velocity.
typedef void (*TItemAttackColHitObject)(s32 item_id, s32 *hit, Vec *velocity);

// TItemAttackCol's parameters (TObjPlayer__sub_802E449C fills in the defaults).
struct S_802E449C : S_802E451C {
    s32 rotation_y;     // heading without flag 1
    Vec direction;      // with it
    f32 speed;
    f32 range;          // how far it flies before it destroys itself
    u32 flags;          // copied to TItemAttackCol::flags
    u32 model;          // NJS_OBJECT drawn at its position, 0 for none
    u32 texlist;
    f32 scale;
    s32 spin[3];
    f32 star_width;     // StarLightParameters::width of its star light
    f32 pad_60;
    f32 star_color[3];  // red, green, blue in 0..1
    TItemAttackColHitWall hit_wall;
    TItemAttackColHitObject hit_object;
    s32 particle;       // create_particle_emitter id, -1 for none
    s32 trail_particle; // a second one, -1 for none
};

struct TItemAttackCol : public TUnk_804E355C {
    TItemAttackCol(TObject *parent, S_802E449C *params);
    virtual ~TItemAttackCol();
    virtual void vfunc_7();
    void check_object_hits();
    virtual void vfunc_6(s32 *);
    Vec start_position;
    Vec velocity;
    f32 range_sq;
    FlagWord hit_wall_flags;
    u32 flags;          // S_802E449C::flags
    u32 model;          // NJS_OBJECT render draws, 0 for none
    u32 texlist;        // set_texlist before drawing it
    s32 rotation[3];    // heading the model is drawn at
    s32 spin[3];        // run_task turns spin[1] 0x888 a frame with flag 0x20
    Vec scale;
    s32 pad_114[3];
    f32 pad_120[3];
    TEffStarLight2D *star_light;
    TParticleCtrl *particle;
    TParticleCtrl *trail_particle;
    TItemAttackColHitWall hit_wall;
    TItemAttackColHitObject hit_object;
    TParticleCtrl *continuous_particle;
    static void add_to_active_list(void* a0);
    void shift_collision_bounds();
    void move_with_collision(void *arg1);
    virtual void render();
    virtual void run_task();
    static void create(void *arg0, void *arg1);
    void copy_pos(void* q);
};

typedef char TItemAttackCol_size[sizeof(TItemAttackCol) == 0x144 ? 1 : -1];
#endif
