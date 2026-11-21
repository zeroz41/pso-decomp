#ifndef PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H
#define PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class TParticleCtrl;

struct TBoss7PhotonBullet : public TUnk_804928CC {
    TBoss7PhotonBullet(TObject *parent, TObjBase *owner, const Vec *origin, const Vec *aim, f32 scale);
    virtual ~TBoss7PhotonBullet();
    virtual void render();
    virtual void run_task();

    f32 speed;
    Vec aim;
    Vec travel;
    Vec shadow_pos;
    Vec shadow_scale;
    s32 age;
    u32 grounded;
    f32 fall;
    TParticleCtrl *effects[2];

    static f32 get_target_pos_y();
};

LAYOUT_ASSERT(TBoss7PhotonBullet_size, sizeof(TBoss7PhotonBullet) == 0xF8);
#endif
