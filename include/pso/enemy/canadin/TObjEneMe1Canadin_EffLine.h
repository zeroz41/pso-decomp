#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TObjEneMe1Canadin_EffLine : public TObject {
public:
    TObjEneMe1Canadin_EffLine(TObject *parent, Vec *from, Vec *to);
    virtual ~TObjEneMe1Canadin_EffLine();
    virtual void run_task();
    virtual void render();
    s32 timer;
    Vec *tracked_from;
    Vec *tracked_to;
    Vec start;
    Vec end;
    u32 start_color;
    u32 end_color;
};
LAYOUT_ASSERT(TObjEneMe1Canadin_EffLine_size, sizeof(TObjEneMe1Canadin_EffLine) == 0x48);

#endif
