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
    static TObjDFRecBall *create(TObject *parent, const Vec *position, const Vec *target);
    virtual ~TObjDFRecBall();
    virtual void run_task();

    Vec pos;
    Vec target;
    Vec vel;
    f32 speed;
    void *model; // its particle emitter
    s32 timer;
};

// The Jisin: a ring of fire that grows by 25 a frame around its centre (TBoss4Type2::create_jisin).
class TObjDFJisin : public TObject {
public:
    TObjDFJisin(TObject *parent, s32 angle);
    virtual ~TObjDFJisin();
    virtual void run_task();
    void spawn_particle_f3(const Vec *point);
    void damage_players_near_point(Vec *point);

    Vec center;
    f32 radius;
};


// Draws a player-like model set (body, two attached parts, hair) at alpha; used by TBoss6Type2.
// head is the part drawn at node 0x3B (with the hair), part the one at node 0x3A (names inferred).
void boss6type2_draw_models(s32 body_texlist, s32 head_texlist, s32 part_texlist, uaddr body, uaddr head, u32 hair, uaddr part, saddr appearance, f32 alpha);

#endif
