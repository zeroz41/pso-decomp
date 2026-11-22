#ifndef PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_EFFCURSE3_H
#define PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_EFFCURSE3_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"

class TObjEneBm9Mericarol_EffCurse3 : public TObject {
public:
    TObjEneBm9Mericarol_EffCurse3(TObject *parent, TObjBase *victim);
    virtual ~TObjEneBm9Mericarol_EffCurse3();
    virtual void run_task();
    s32 age;                 // frames alive; destroyed after 10
    TObjBase *target;
    TParticleCtrl *effect;   // particle 0x20D, kept in front of the target toward the camera
};
LAYOUT_ASSERT(TObjEneBm9Mericarol_EffCurse3_size, sizeof(TObjEneBm9Mericarol_EffCurse3) == 0x28);

#endif
