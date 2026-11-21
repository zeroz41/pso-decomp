#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_EFFCURSE3_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_EFFCURSE3_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"

class TObjEneRe2Flower_EffCurse3 : public TObject {
public:
    TObjEneRe2Flower_EffCurse3(TObject *parent, TObjBase *target);
    virtual ~TObjEneRe2Flower_EffCurse3();
    virtual void run_task();
    s32 timer;
    TObjBase *target;
    TParticleCtrl *effect;
};
LAYOUT_ASSERT(TObjEneRe2Flower_EffCurse3_size, sizeof(TObjEneRe2Flower_EffCurse3) == 0x28);

#endif
