#ifndef PSO_BOSS_BARBARAY_TBOSS7BODYBREAKUP_H
#define PSO_BOSS_BARBARAY_TBOSS7BODYBREAKUP_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/boss/barbaray/TBoss7BreakUp.h"

// The body breakup TBoss7DeRolLeC starts (state flag 0x80): the pieces of archive model 2 fly off
// from the boss's node matrices.
class TBoss7BodyBreakUp : public TBoss7BreakUp {
public:
    TBoss7BodyBreakUp(TObject *parent, GC_Mtx *matrices);
    virtual ~TBoss7BodyBreakUp();
    virtual void run_task();
    virtual void render();
    GC_Mtx *matrices;   // the boss's node matrices
    Vec pivot;          // origin transformed by the first matrix; render draws around it

};
LAYOUT_ASSERT(TBoss7BodyBreakUp_size, sizeof(TBoss7BodyBreakUp) == 0x3C);

#endif
