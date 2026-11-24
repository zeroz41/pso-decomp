#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DPB_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DPB_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct TBoss6Type2;

// Olga Flow's photon blast: hits every player within radius of position on its sixth frame.
class TBoss6DPB : public TObject {
public:
    TBoss6DPB(TObject *parent, const Vec *position, f32 radius);
    virtual ~TBoss6DPB();
    void apply_shower_damage_to_players();
    void sub_8035D8B0();
    virtual void run_task();
    virtual void render();
public:
    TBoss6Type2 *owner;  // the parent that created it
    Vec position;
    f32 radius;
    s32 frame;
    s32 power;           // boss parameter 0x2C
    f32 power_scale;     // boss parameter 0x2F, applied while the owner's rotation timer runs
};

#endif
