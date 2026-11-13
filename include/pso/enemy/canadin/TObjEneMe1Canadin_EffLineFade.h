#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TObjEneMe1Canadin_EffLineFade : public TObject {
public:
    virtual ~TObjEneMe1Canadin_EffLineFade();
    virtual void run_task();
    virtual void render();
    Vec m_1C;
    Vec m_28;
    u8 m_34[0x3];
    u8 m_37;
    u8 m_38[0x3];
    s8 m_3b;
};
typedef char TObjEneMe1Canadin_EffLineFade_size[sizeof(TObjEneMe1Canadin_EffLineFade) == 0x3C ? 1 : -1];

#endif
