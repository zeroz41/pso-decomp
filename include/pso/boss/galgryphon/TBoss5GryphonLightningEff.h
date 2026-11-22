#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGEFF_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGEFF_H

#include "pso/technique/TTecZondeEff.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

class TBoss5GryphonLightningEff : public TTecZondeEff {
public:
    TBoss5GryphonLightningEff(TObject *parent, TBoss5GryphonLightningSegment *segments, int segment_count, f32 from,
                              f32 to, f32 scale);
    virtual ~TBoss5GryphonLightningEff();
    void set_two_sided();
    virtual void run_task();
    virtual void render();
public:
    s32 calc_segment_uvs(void *p_);

    u8 two_sided;  // render draws the strip a second time with its sides swapped
};

#endif
