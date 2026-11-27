#ifndef PSO_WEAPON_TITEMATTACKCOL_H
#define PSO_WEAPON_TITEMATTACKCOL_H

#include "types.h"
#include "pso/weapon/WeaponEffectDescriptor.h"

#include "pso/system/data/FlagWord.h"

class TEffStarLight2D;
class TParticleCtrl;

struct TItemAttackCol : public TItemAttackColBase {
    static const char *name;
    TItemAttackCol(TObject *parent, WeaponEffectDescriptor *params);
    virtual ~TItemAttackCol();
    virtual void move_by_velocity();
    void check_object_hits();
    virtual void on_hit(ActorBodyHit *hit);
    Vec start_position;
    Vec velocity;
    f32 range_sq;
    FlagWord hit_wall_flags;
    u32 flags;          // WeaponEffectDescriptor::flags
    NJS_OBJECT *model;    // the model render draws, NULL for none
    NJS_TEXLIST *texlist; // set_texlist before drawing it
    s32 rotation[3];    // heading the model is drawn at
    s32 spin[3];        // run_task turns spin[1] 0x888 a frame with flag 0x20
    Vec scale;
    s32 extra_rotation[3];
    f32 extra_scale[3];
    TEffStarLight2D *star_light;
    TParticleCtrl *particle;
    TParticleCtrl *trail_particle;
    TItemAttackColHitWall hit_wall;
    TItemAttackColHitObject hit_object;
    TParticleCtrl *continuous_particle;
    static void add_to_active_list(NJS_OBJECT *node);
    void shift_collision_bounds();
    void move_with_collision(Vec *to);
    virtual void render();
    virtual void run_task();
    static void create(TObject *parent, WeaponEffectDescriptor *params);
};

LAYOUT_ASSERT(TItemAttackCol_size, sizeof(TItemAttackCol) == 0x144);
#endif
