#ifndef PSO_OBJECT_TBOSS7DEROLLECLASERTRAIL_H
#define PSO_OBJECT_TBOSS7DEROLLECLASERTRAIL_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TParticleCtrl;

// A ring of the last 20 points fed by push_ring_point, replayed through a
// continuous particle effect once m_limit points have been pushed.
class TBoss7DeRolLeCLaserTrail : public TObject {
public:
    enum { NUM_POINTS = 20 };

    Vec m_points[NUM_POINTS];
    s32 m_head;
    s32 m_cur;
    s32 m_limit;
    s32 m_effect_id;
    TParticleCtrl *m_particle;
    s32 m_state;

    TBoss7DeRolLeCLaserTrail(TObject *parent, s32 limit, s32 effect_id);
    virtual ~TBoss7DeRolLeCLaserTrail();
    virtual void run_task();

    void push_ring_point(const Vec *pos);
};
LAYOUT_ASSERT(TBoss7DeRolLeCLaserTrail_size, sizeof(TBoss7DeRolLeCLaserTrail) == 0x124);

#endif
