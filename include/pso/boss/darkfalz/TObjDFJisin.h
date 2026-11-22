#ifndef PSO_BOSS_DARKFALZ_TOBJDFJISIN_H
#define PSO_BOSS_DARKFALZ_TOBJDFJISIN_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TObjDFBeamCursor : public TObject {
public:
    TObjDFBeamCursor(TObject *parent, const Vec *position);
    static TObjDFBeamCursor *create(TObject *parent, const Vec *position);
    virtual ~TObjDFBeamCursor();
    virtual void run_task();

    s32 timer;    // spawns its particle effect at position when it runs out
    Vec position;
};
class TObjDFRecBall : public TObject {
public:
    TObjDFRecBall(TObject *parent, const Vec *position, const Vec *target);
    virtual ~TObjDFRecBall();
    virtual void run_task();

    Vec pos;
    Vec target;
    Vec vel;
    f32 speed;
    void *model; // its particle emitter
    s32 timer;
};

extern "C" {
void TObjDFTenchuFuru__sub_80051A7C(void);
void *create__13TObjDFRecBallFPvPvPv(void *parent, void *position, void *arg2);
void fn_spawn_particle_f3_with_flags(s32 arg0, saddr arg1);
int queue_destruction__13TObjDFHormingFPv(void *p);
void run_task__13TObjDFHormingFv(u8 *self);
}

// Draws a player-like model set (body, two attached parts, hair) at alpha; used by TBoss6Type2.
void boss6type2_draw_models(s32 arg0, s32 arg1, s32 arg2, uaddr arg3, uaddr arg4, u32 model, uaddr arg6, saddr appearance, f32 alpha);

#endif
