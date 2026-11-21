#ifndef PSO_BOSS_DEROLLE_TBOSS2PHOTONBULLET_80038DCC_H
#define PSO_BOSS_DEROLLE_TBOSS2PHOTONBULLET_80038DCC_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class TParticleCtrl;

class TBoss2PhotonBullet : public TUnk_804928CC {
public:
    TBoss2PhotonBullet(TObject *parent, TObjBase *owner, Vec *pos, Vec *dir, f32 speed);
    virtual ~TBoss2PhotonBullet();
    virtual void run_task();
    virtual void render();

    f32 speed;
    Vec aim;
    Vec travel;
    Vec shadow_pos;
    s32 age;
    u32 grounded;
    f32 fall;
    TParticleCtrl *effect;
};

LAYOUT_ASSERT(TBoss2PhotonBullet_size, sizeof(TBoss2PhotonBullet) == 0xE8);

#endif
