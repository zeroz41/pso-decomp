#ifndef PSO_BOSS_TBOSS2DEROLLELASERTRAIL_H
#define PSO_BOSS_TBOSS2DEROLLELASERTRAIL_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TParticleCtrl;

// De Rol Le's laser trail: a ring of the last 20 points fed by push_ring_point, replayed through a
// continuous particle effect once m_limit points have been pushed (the Barba Ray twin is TUnk_804E4788).
class TBoss2DeRolLeLaserTrail : public TObject {
public:
    enum { NUM_POINTS = 20 };

    Vec m_points[NUM_POINTS];
    s32 m_head;
    s32 m_cur;
    s32 m_limit;
    s32 m_effect_id;
    TParticleCtrl *m_particle;
    s32 m_state;

    TBoss2DeRolLeLaserTrail(TObject *parent, s32 limit, s32 effect_id);
    virtual ~TBoss2DeRolLeLaserTrail();
    virtual void run_task();

    void push_ring_point(const Vec *pos);
};
LAYOUT_ASSERT(TBoss2DeRolLeLaserTrail_size, sizeof(TBoss2DeRolLeLaserTrail) == 0x124);

#endif
