#ifndef PSO_EFFECT_TEFFCLITICAL_H
#define PSO_EFFECT_TEFFCLITICAL_H

#include "types.h"
#include "pso/effect/TEffect.h"

class TEffClitical : public TEffect {
public:
    TEffClitical(void *arg1);
    virtual ~TEffClitical();
    virtual void run_task();
    virtual void render();
public:
    void create();
};

extern "C" {
void approach_position_if_far(u8 *arg0, u8 *arg1, f32 farg0);
void init_texture_copy_rect(void *arg0, saddr arg1, saddr arg2, s32 arg3, s32 arg4);
}

#endif
