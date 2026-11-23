#ifndef PSO_TECHNIQUE_TTECRAZONDE_H
#define PSO_TECHNIQUE_TTECRAZONDE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

struct TTecRaZonde : public TTecCircle {
    TTecRaZonde(saddr source, Vec *origin, s32 level);
    virtual ~TTecRaZonde();
    virtual void vfunc_8(void *);
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    void calc_damage();
    static void create(void *source, void *origin, s32 level);
    virtual void render();
    Vec bolt_points[8];  // the constructor's spiral; a bolt runs between each neighbouring pair
};

LAYOUT_ASSERT(TTecRaZonde_size, sizeof(TTecRaZonde) == 0x150);
#endif
