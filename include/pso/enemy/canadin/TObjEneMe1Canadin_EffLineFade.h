#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINEFADE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjEneMe1Canadin_EffLineFade : public TObject {
public:
    virtual ~TObjEneMe1Canadin_EffLineFade();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1B];
    u8 m_37;
    u8 unk_38[0x3];
    s8 m_3b;
};
typedef char TObjEneMe1Canadin_EffLineFade_size[sizeof(TObjEneMe1Canadin_EffLineFade) == 0x3C ? 1 : -1];

#endif
