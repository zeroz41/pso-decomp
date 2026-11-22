#ifndef PSO_BOSS_BARBARAY_TBOSS7TENTACLENEEDLE_H
#define PSO_BOSS_BARBARAY_TBOSS7TENTACLENEEDLE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct NJS_OBJECT;
struct AnimationMotion;
class TParticleCtrl;

// A needle Barba Ray drives up through the floor under a player: it waits, rises (motion 0), stings every
// player standing over it (motion 1) and sinks away (motion 2).
struct TBoss7TentacleNeedle : public TObject {
    TBoss7TentacleNeedle(TObject *parent, Vec *pos);
    virtual ~TBoss7TentacleNeedle();
    virtual void render();
    virtual void run_task();
    void restart_particle_effect();
    void advance_anim_time_wrapped(f32 step);
    s32 advance_toward_limit(f32 step);
    // state 3: plays the sink motion out, then destroys the needle (name inferred from the body).
    void update_sink();
    void damage_nearby_players();
    void update_retract_state();
    void advance_needle_timer();
    // Load and release the needle's model and motions (the boss's resource callback table, as the
    // TBoss7Crawfish pair next to them).
    static void load_static_resource();
    static void destroy_instance();

    Vec position;
    s32 rotation[3];
    f32 unk_34;
    s32 state;
    s32 timer;
    TParticleCtrl *particle_emitter; // create_particle_emitter(pos, 0x212) in the ctor
    s32 player_hit[12];        // set once a player has been stung
    f32 frame;
    AnimationMotion *motion;
};

LAYOUT_ASSERT(TBoss7TentacleNeedle_size, sizeof(TBoss7TentacleNeedle) == 0x7C);

extern NJS_OBJECT *boss7_tentacle_needle_model;
extern AnimationMotion *boss7_tentacle_needle_motions[4];

#endif
