#ifndef PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H
#define PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H

#include "types.h"
#include "pso/object/base/TAttackCollider.h"

class TParticleCtrl;

struct TBoss7PhotonBullet : public TAttackCollider {
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
    static const char *name;
};

LAYOUT_ASSERT(TBoss7PhotonBullet_size, sizeof(TBoss7PhotonBullet) == 0xF8);

struct Boss7PhotonLevel {
    s32 shots;
    s32 interval;
    s32 spread;
    f32 speed;
};

#endif
