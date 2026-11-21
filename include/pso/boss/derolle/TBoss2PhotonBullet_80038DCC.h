#ifndef PSO_BOSS_DEROLLE_TBOSS2PHOTONBULLET_80038DCC_H
#define PSO_BOSS_DEROLLE_TBOSS2PHOTONBULLET_80038DCC_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

struct Vec;

class TBoss2PhotonBullet : public TUnk_804928CC {
public:
    TBoss2PhotonBullet(TObject *parent, TObjBase *owner, Vec *pos, Vec *dir, f32 speed);
    virtual ~TBoss2PhotonBullet();
    virtual void run_task();
    virtual void render();

    u8 pad_b0[0xE8 - 0xB0];
};

extern "C" {
void *__dt__15TBoss2PhotonPadFv(void *self, s16 arg1);
}

#endif
