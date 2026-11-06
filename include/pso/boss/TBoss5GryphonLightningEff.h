#ifndef PSO_BOSS_TBOSS5GRYPHONLIGHTNINGEFF_H
#define PSO_BOSS_TBOSS5GRYPHONLIGHTNINGEFF_H

#include "pso/technique/TTecZondeEff.h"
#include "types.h"

class TBoss5GryphonLightningEff : public TTecZondeEff {
public:
    virtual ~TBoss5GryphonLightningEff();
    virtual void run_task();
    virtual void render();
public:
    s32 calc_segment_uvs(void *p_);
};

extern "C" {
void TBoss5GryphonLightningEff__sub_80325064(void *p);
}

#endif
