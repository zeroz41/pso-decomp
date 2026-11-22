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

    // Moves emitters 5-8 to their players (by client id) and the others to the ball.
    void update_emitter_positions();
    // create_emitter with particle flag 0x2000 added; used for emitter 4 when the charge starts.
    void create_charge_emitter(s32 index);
    void clear_emitters();
    void clear_player_grav_flags();
    // Charge phase: players within 10 are held at the ball, players within 32.5 pushed out to 33.5.
    void push_players();
    // Grounded phase: players are pulled to the ball (pull_strength), held within 10.
    void pull_players();
    // Moves the ball 2/3 of a unit per frame towards the origin of the floor (x, z).
    void drift_to_center();
    s32 clamp_to_ground();
    void update_state();
    void update_charge_effects();
    void update_lifetime();
    void destroy_part(s32 index);
    void create_emitter(s32 index);
    void init_parts();
    virtual void render();
};

LAYOUT_ASSERT(TBoss6GravBallOwnerOffset, offsetof(TBoss6GravBall, owner) == 0xAC);
LAYOUT_ASSERT(TBoss6GravBallEmittersOffset, offsetof(TBoss6GravBall, emitters) == 0xD4);
LAYOUT_ASSERT(TBoss6GravBall_size, sizeof(TBoss6GravBall) == 0xF8);
#endif
