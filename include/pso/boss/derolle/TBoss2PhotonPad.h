#ifndef PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#define PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss2PhotonPad : public TObject {
public:
    virtual ~TBoss2PhotonPad();
    virtual void run_task();
    virtual void render();
public:
};

#endif
