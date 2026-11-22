#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/TUnk_80484840.h"
#include <dolphin/mtx.h>

// A line end color: set as one word, faded through its alpha byte.
union TObjEneMe1Canadin_LineColor {
    u32 rgba;
    VoloptLineColor c;
};

// The fading copy of an EffLine segment that TObjEneMe1Canadin_EffLine::run_task leaves behind.
class TObjEneMe1Canadin_EffLineFade : public TObject {
public:
    TObjEneMe1Canadin_EffLineFade(TObject *parent, Vec *from, Vec *to);
    virtual ~TObjEneMe1Canadin_EffLineFade();
    virtual void run_task();
    virtual void render();
    Vec points[2];
    TObjEneMe1Canadin_LineColor colors[2];
};
LAYOUT_ASSERT(TObjEneMe1Canadin_EffLineFade_size, sizeof(TObjEneMe1Canadin_EffLineFade) == 0x3C);

#endif
