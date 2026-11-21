#ifndef PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#define PSO_BOSS_DEROLLE_TBOSS2PHOTONPAD_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// Fires a fan of photon bullets from origin (twin of Barba Ray's TBoss7PhotonPad): one every interval
// frames, turning pos (the shot direction) across the level's spread.
class TBoss2PhotonPad : public TObject {
public:
    TBoss2PhotonPad(TObject *parent, Vec *start, Vec *dir, s32 level);
    virtual ~TBoss2PhotonPad();
    virtual void run_task();
    virtual void render();

    Vec *origin;
    Vec pos;
    s32 level;
    s32 shots;
    s32 timer;
};

LAYOUT_ASSERT(TBoss2PhotonPad_size, sizeof(TBoss2PhotonPad) == 0x38);

#endif
