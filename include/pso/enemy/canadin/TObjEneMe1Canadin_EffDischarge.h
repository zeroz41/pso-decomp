#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFDISCHARGE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFDISCHARGE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct TObjEneMe1Canadin;

class TObjEneMe1Canadin_EffDischarge : public TObject {
public:
    TObjEneMe1Canadin_EffDischarge(TObjEneMe1Canadin *parent, Vec *from, Vec *to);
    virtual ~TObjEneMe1Canadin_EffDischarge();
    virtual void run_task();
    virtual void render();
    TObjEneMe1Canadin *owner;
    f32 arc_curve;
    f32 start_height;
    f32 travelled;
    f32 arc_length;
    f32 flat_length;
    f32 total_length;
    Vec seg_start;
    Vec target;
    Vec seg_end;
    Vec step;
};
LAYOUT_ASSERT(TObjEneMe1Canadin_EffDischarge_size, sizeof(TObjEneMe1Canadin_EffDischarge) == 0x68);

#endif
