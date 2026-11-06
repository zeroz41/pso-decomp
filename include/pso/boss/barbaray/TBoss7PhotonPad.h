#ifndef PSO_BOSS_BARBARAY_TBOSS7PHOTONPAD_H
#define PSO_BOSS_BARBARAY_TBOSS7PHOTONPAD_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss7PhotonPad : public TObject {
public:
    TBoss7PhotonPad(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    virtual ~TBoss7PhotonPad();
    virtual void run_task();
    virtual void render();
public:
};

#endif
