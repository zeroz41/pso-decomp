#ifndef PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#define PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct Vec;

class TBoss2PhotonPad : public TObject {
public:
    TBoss2PhotonPad(TObject *parent, Vec *start, Vec *dir, s32 level);
    virtual ~TBoss2PhotonPad();
    virtual void run_task();
    virtual void render();

    u8 pad_1c[0x38 - 0x1C];
};

#endif
