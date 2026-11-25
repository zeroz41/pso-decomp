#ifndef PSO_BOSS_TBOSS1DRAGONATTACKCOLLIDER_H
#define PSO_BOSS_TBOSS1DRAGONATTACKCOLLIDER_H
#include "types.h"
#include "pso/object/base/TAttackCollider.h"

class TBoss1DragonAttackCollider : public TAttackCollider {
public:
    TBoss1DragonAttackCollider(TObject *parent, TObjBase *owner);
    virtual ~TBoss1DragonAttackCollider();
    virtual void apply_hit_if_active(TObjChara *target, const f32 *recoil);
    virtual void area_attack_receive_direct(TObjChara *target, const f32 *recoil, DirectAttackPayload *attack);
};
LAYOUT_ASSERT(TBoss1DragonAttackCollider_size, sizeof(TBoss1DragonAttackCollider) == 0xB0);

#endif
