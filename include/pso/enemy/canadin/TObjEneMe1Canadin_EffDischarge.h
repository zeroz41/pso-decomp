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
    TObjEneMe1Canadin *m_1C;
    f32 m_20;
    f32 m_24;
    f32 m_28;
    f32 m_2C;
    f32 m_30;
    f32 m_34;
    Vec m_38;
    Vec m_44;
    Vec m_50;
    Vec m_5C;
};
typedef char TObjEneMe1Canadin_EffDischarge_size[sizeof(TObjEneMe1Canadin_EffDischarge) == 0x68 ? 1 : -1];

#endif
