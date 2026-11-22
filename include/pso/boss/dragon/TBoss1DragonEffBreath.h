#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBREATH_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBREATH_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class AreaAttackHistory;

struct TBoss1DragonEffBreath : public TObject {
    TBoss1DragonEffBreath(TObject *parent, Vec *initial_position, Vec *direction);
    virtual ~TBoss1DragonEffBreath();
    Vec position;
    Vec velocity;
    AreaAttackHistory *attack_history;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss1DragonEffBreath_size, sizeof(TBoss1DragonEffBreath) == 0x38);

#endif
