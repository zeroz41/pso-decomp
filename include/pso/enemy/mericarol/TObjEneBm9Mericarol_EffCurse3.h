#ifndef PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_EFFCURSE3_H
#define PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_EFFCURSE3_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"

class TObjEneBm9Mericarol_EffCurse3 : public TObject {
public:
    TObjEneBm9Mericarol_EffCurse3(TObject *parent, TObjBase *target);
    virtual ~TObjEneBm9Mericarol_EffCurse3();
    virtual void run_task();
    s32 m_1c;
    TObjBase *m_20;
    TParticleCtrl *m_24;
};
typedef char TObjEneBm9Mericarol_EffCurse3_size[sizeof(TObjEneBm9Mericarol_EffCurse3) == 0x28 ? 1 : -1];

#endif
