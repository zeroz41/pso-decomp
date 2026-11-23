#ifndef PSO_WEAPON_TITEMFOLLOWEFFECT_H
#define PSO_WEAPON_TITEMFOLLOWEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TItemWeapon;
class TParticleCtrl;

// Keeps a particle emitter on a weapon joint while the weapon is out.
class TItemFollowEffect : public TObject {
public:
    TItemFollowEffect(TObject *parent, TItemWeapon *weapon, s32 joint, s32 effect_id);
    virtual ~TItemFollowEffect();
    virtual void run_task();

    s32 item_id;
    s32 joint;
    TParticleCtrl *particle;
    u32 item_generation;  // get_item_system_generation() when built; a change ends it
};
LAYOUT_ASSERT(TItemFollowEffect_size, sizeof(TItemFollowEffect) == 0x2C);

void spawn_item_follow_effect(TObject *parent, TItemWeapon *weapon, s32 joint, s32 effect_id);

#endif
