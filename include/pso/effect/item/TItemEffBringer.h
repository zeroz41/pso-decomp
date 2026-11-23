#ifndef PSO_EFFECT_ITEM_TITEMEFFBRINGER_H
#define PSO_EFFECT_ITEM_TITEMEFFBRINGER_H

#include "pso/weapon/shoot/TItemShoot.h"
#include "types.h"
#include "dolphin/mtx.h"

// A Bringer's rifle shot: a row of particles along the shot's step, more of them the
// more the shot crosses the view.
class TItemEffBringer : public TItemShoot {
public:
    TItemEffBringer(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemEffBringer();
    virtual void hook();

    static void *create(void *owner, const Vec *pos, const Vec *dir, f32 life);
    static const char *class_name;

    void *particles[10];
    s32 particle_count;
    Vec particle_step;  // the shot's step divided among the particles
};

#endif
