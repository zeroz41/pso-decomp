#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/enemy/AttackTargetHistory.h"

struct TBoss8DragonEffBreath : public TObject {
    TBoss8DragonEffBreath(TObject *parent, Vec *pos, Vec *velocity, s32 kind, u16 owner);
    virtual ~TBoss8DragonEffBreath();
    Vec m_1c;
    Vec m_28;
    u32 m_34;
    u16 m_38;
    AreaAttackHistory *m_3c;
    virtual void render();
    virtual void run_task();
};

typedef char TBoss8DragonEffBreath_size[sizeof(TBoss8DragonEffBreath) == 0x40 ? 1 : -1];

#endif
