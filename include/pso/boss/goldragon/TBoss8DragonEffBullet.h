#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBULLET_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBULLET_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct TBoss8DragonEffBullet : public TObject {
    TBoss8DragonEffBullet(TObject *parent, Vec *from, Vec *to, saddr kind, u16 owner);
    virtual ~TBoss8DragonEffBullet();
    Vec m_1c;
    Vec m_28;
    s32 m_34;
    s32 m_38;
    f32 m_3c;
    f32 m_40;
    s32 m_44;
    u16 m_48;
    TParticleCtrl *m_4c;
    TParticleCtrl *m_50;
    const s32 *m_54;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss8DragonEffBullet_size, sizeof(TBoss8DragonEffBullet) == 0x58);

#endif
