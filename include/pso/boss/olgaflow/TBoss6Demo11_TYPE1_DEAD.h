#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO11_TYPE1_DEAD_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO11_TYPE1_DEAD_H
#include "types.h"
#include "pso/boss/olgaflow/OlgaFlowScenePart.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class ModelNodePositionCapture;
struct TObjFish;
struct AnimationMotion;
struct NJS_TEXLIST;
class TParticleCtrl;
struct TBoss6PlotFalz;

class TBoss6Demo11_TYPE1_DEAD : public TObject {
public:
    TBoss6Demo11_TYPE1_DEAD(TBoss6PlotFalz *plot, const Vec *target);
    static TBoss6Demo11_TYPE1_DEAD *create(TBoss6PlotFalz *plot, const Vec *target);
    virtual ~TBoss6Demo11_TYPE1_DEAD();
    void render_fade_model();
    virtual void render();
    virtual void run_task();

    Vec position;            // 0x1C, copied from the start position in the ctor
    OlgaFlowScenePart parts[2];           // 0x28
    f32 frame;               // 0x40, animation frame (inferred)
    s32 timer;               // 0x44, frame counter (inferred)
    TBoss6PlotFalz *plot;         // 0x48, the parent passed to the ctor (get_phase() polled)
    Vec effect_points[5];
    ModelNodePositionCapture *node_effect;
    TParticleCtrl *emitter;  // 0x8C, create_particle_emitter result
};
LAYOUT_ASSERT(TBoss6Demo11_TYPE1_DEAD_size, sizeof(TBoss6Demo11_TYPE1_DEAD) == 0x90);

#endif
