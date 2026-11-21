#ifndef PSO_BOSS_BARBARAY_TBOSS7PHOTONPAD_H
#define PSO_BOSS_BARBARAY_TBOSS7PHOTONPAD_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TBoss7PhotonPad : public TObject {
public:
    TBoss7PhotonPad(TObject *parent, const Vec *shot_origin, const Vec *direction, s32 shot_level);
    virtual ~TBoss7PhotonPad();
    virtual void run_task();
    virtual void render();

    const Vec *origin;
    Vec pos;
    s32 level;
    s32 shots;
    s32 timer;
};

LAYOUT_ASSERT(TBoss7PhotonPad_size, sizeof(TBoss7PhotonPad) == 0x38);

#endif
