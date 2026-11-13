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
    s32 m_1C;
    Vec *m_20;
    Vec *m_24;
    Vec m_28;
    Vec m_34;
    u32 m_40;
    u32 m_44;
};
typedef char TObjEneMe1Canadin_EffLine_size[sizeof(TObjEneMe1Canadin_EffLine) == 0x48 ? 1 : -1];

#endif
