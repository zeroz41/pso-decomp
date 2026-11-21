#ifndef PSO_BOSS_OLGAFLOW_TBOSS6GRAVBALL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6GRAVBALL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx.h>

struct TBoss6Type1;
class TParticleCtrl;

struct TBoss6GravBall : public TObjCollidable {
    TBoss6GravBall(TBoss6Type1 *owner, const Vec *position);
    virtual ~TBoss6GravBall();
    virtual void run_task();
    TBoss6Type1 *owner;
    s32 state;
    s32 age;
    s32 charge_age;
    f32 pull_strength;
    u32 pull_flags;
    s32 burst_played;
    Vec ball_position;
    TParticleCtrl *emitters[9];

    void clear_player_grav_flags();
    s32 clamp_to_ground();
    void update_state();
    void update_charge_effects();
    void update_lifetime();
    void destroy_part(s32 arg1);
    void create_emitter(s32 arg1);
    void init_parts();
    virtual void render();
};

typedef char TBoss6GravBallOwnerOffset[offsetof(TBoss6GravBall, owner) == 0xAC ? 1 : -1];
typedef char TBoss6GravBallEmittersOffset[offsetof(TBoss6GravBall, emitters) == 0xD4 ? 1 : -1];
typedef char TBoss6GravBall_size[sizeof(TBoss6GravBall) == 0xF8 ? 1 : -1];
#endif
