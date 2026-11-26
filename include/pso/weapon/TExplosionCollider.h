#ifndef PSO_WEAPON_TEXPLOSIONCOLLIDER_H
#define PSO_WEAPON_TEXPLOSIONCOLLIDER_H
#include "types.h"
#include "pso/item/TItemAttackColBase.h"

class TExplosionCollider : public TItemAttackColBase {
public:
    TExplosionCollider(TObject *parent, AttackColParams *params);
    virtual ~TExplosionCollider();
    virtual void run_task();
    f32 max_radius; // run_task grows body.radius up to it, then destroys the collider
};
LAYOUT_ASSERT(TExplosionCollider_size, sizeof(TExplosionCollider) == 0xC8);

#endif
