#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss5PillarSmoke : public TObject {
    virtual ~TObjBoss5PillarSmoke();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    virtual void render();
    virtual void run_task();
};

typedef char TObjBoss5PillarSmoke_size[sizeof(TObjBoss5PillarSmoke) == 0x28 ? 1 : -1];
#endif
