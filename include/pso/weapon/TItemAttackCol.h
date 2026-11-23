#ifndef PSO_WEAPON_TITEMATTACKCOL_H
#define PSO_WEAPON_TITEMATTACKCOL_H

#include "types.h"
#include "pso/weapon/WeaponEffectDescriptor.h"

#include "pso/system/data/FlagWord.h"

class TEffStarLight2D;
class TParticleCtrl;

// Called when the collider hits a wall (or at once for an instant one):
// the weapon's item id, where it is and its velocity.
typedef void (*TItemAttackColHitWall)(s32 item_id, Vec *position, Vec *velocity);
// Called for each target it hits: the weapon's item id, the target's
// ActorBodyHit entry and the collider's velocity.
typedef void (*TItemAttackColHitObject)(s32 item_id, s32 *hit, Vec *velocity);

struct TItemAttackCol : public TUnk_804E355C {
    TItemAttackCol(TObject *parent, Desc_8011E5C4 *params);
    virtual ~TItemAttackCol();
    virtual void vfunc_7();
    void check_object_hits();
    virtual void vfunc_6(ActorBodyHit *hit);
    Vec start_position;
    Vec velocity;
    f32 range_sq;
    FlagWord hit_wall_flags;
    u32 flags;          // Desc_8011E5C4::flags
    uaddr model;          // NJS_OBJECT render draws, 0 for none
    NJS_TEXLIST *texlist; // set_texlist before drawing it
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
    static void add_to_active_list(void* node);
    void shift_collision_bounds();
    void move_with_collision(void *to);
    virtual void render();
    virtual void run_task();
    static void create(TObject *parent, Desc_8011E5C4 *params);
};

LAYOUT_ASSERT(TItemAttackCol_size, sizeof(TItemAttackCol) == 0x144);
#endif
