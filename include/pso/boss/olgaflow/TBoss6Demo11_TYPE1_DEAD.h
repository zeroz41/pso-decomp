#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO11_TYPE1_DEAD_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO11_TYPE1_DEAD_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct AnimationMotion;
struct TObjFish;
class TParticleCtrl;

class TBoss6Demo11_TYPE1_DEAD : public TObject {
public:
    // One drawn body part: get_bml_model / TObjFish__sub_8001EDB0 / get_bml_motion results (ctor loop).
    struct Part {
        s32 model;
        s32 texture;
        AnimationMotion *motion;
    };

    TBoss6Demo11_TYPE1_DEAD(TObject *parent, void *arg);
    virtual ~TBoss6Demo11_TYPE1_DEAD();
    void render_fade_model();
    virtual void render();
    virtual void run_task();

    Vec position;            // 0x1C, copied from the start position in the ctor
    Part parts[2];           // 0x28
    f32 frame;               // 0x40, animation frame (inferred)
    s32 timer;               // 0x44, frame counter (inferred)
    TObjFish *owner;         // 0x48, the parent passed to the ctor (get_phase() polled)
    Vec effect_points[5];    // 0x4C, filled by TObjFish__sub_800E3124
    TObjFish *node_effect;   // 0x88, TObjFish__sub_800E3124 result
    TParticleCtrl *emitter;  // 0x8C, create_particle_emitter result
};
typedef char TBoss6Demo11_TYPE1_DEAD_size[sizeof(TBoss6Demo11_TYPE1_DEAD) == 0x90 ? 1 : -1];

#endif
