#ifndef PSO_BOSS_DARKFALZ_TOBJBS4CUTATK_H
#define PSO_BOSS_DARKFALZ_TOBJBS4CUTATK_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

// The sweep TBoss4Type3's CUT states send round the arena: it hits every player
// whose bearing from the centre falls in its arc.
class TObjBs4CutAtk : public TObject {
public:
    TObjBs4CutAtk(TObject *parent, s32 heading, s32 side);
    virtual ~TObjBs4CutAtk();
    static TObjBs4CutAtk *create(TObject *parent, s32 heading, s32 side);
    virtual void run_task();
    virtual void render();

    s32 angle;
    s32 angle_step;
    s32 age;
};
LAYOUT_ASSERT(CutAttackSize, sizeof(TObjBs4CutAtk)==0x28);
LAYOUT_ASSERT(CutAttackAngle, offsetof(TObjBs4CutAtk,angle)==0x1C);
LAYOUT_ASSERT(CutAttackStep, offsetof(TObjBs4CutAtk,angle_step)==0x20);
LAYOUT_ASSERT(CutAttackAge, offsetof(TObjBs4CutAtk,age)==0x24);
#endif
