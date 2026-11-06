#ifndef PSO_OBJECT_TUNK_804E4788_H
#define PSO_OBJECT_TUNK_804E4788_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TParticleCtrl;

// A ring of the last 20 points fed by push_ring_point, replayed through a
// continuous particle effect once m_limit points have been pushed.
class TUnk_804E4788 : public TObject {
public:
    enum { NUM_POINTS = 20 };

    Vec m_points[NUM_POINTS];
    s32 m_head;
    s32 m_cur;
    s32 m_limit;
    s32 m_effect_id;
    TParticleCtrl *m_particle;
    s32 m_state;

    TUnk_804E4788(TObject *parent, s32 limit, s32 effect_id);
    virtual ~TUnk_804E4788();
    virtual void run_task();

    void push_ring_point(const Vec *pos);
};
typedef char TUnk_804E4788_size[sizeof(TUnk_804E4788) == 0x124 ? 1 : -1];

#endif
