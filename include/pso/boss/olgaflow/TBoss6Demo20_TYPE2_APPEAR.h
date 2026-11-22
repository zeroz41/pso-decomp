#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO20_TYPE2_APPEAR_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO20_TYPE2_APPEAR_H
#include "types.h"
#include "pso/boss/olgaflow/OlgaFlowScenePart.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/system/task/TObject.h"

class ModelNodePositionCapture;
struct TObjFish;
class TParticleCtrl;
struct TBoss6PlotFalz;
class TBoss6Demo20_TYPE2_APPEAR : public TObject {
public:
    TBoss6Demo20_TYPE2_APPEAR(TBoss6PlotFalz *plot);
    virtual ~TBoss6Demo20_TYPE2_APPEAR();
    static TBoss6Demo20_TYPE2_APPEAR *create(TBoss6PlotFalz *plot);
    void draw_fading_model_pair();
    void draw_fading_model_4();
    void draw_fading_model_1_pair();
    void draw_model_12();
    virtual void render();
    virtual void run_task();
    Vec effect_positions[8];
    ModelNodePositionCapture *capture;
    TParticleCtrl *emitters[9];
    OlgaFlowScenePart opening_parts[2];
    OlgaFlowScenePart model4;
    OlgaFlowScenePart model1;
    OlgaFlowScenePart model12;
    f32 frame;
    f32 secondary_frame;
    saddr timer;
    TBoss6PlotFalz *plot;
};
LAYOUT_ASSERT(TBoss6Demo20_TYPE2_APPEAR_size, sizeof(TBoss6Demo20_TYPE2_APPEAR) == 0xF0);

LAYOUT_ASSERT(TBoss6Demo20_capture_offset, offsetof(TBoss6Demo20_TYPE2_APPEAR, capture) == 0x7C);
LAYOUT_ASSERT(TBoss6Demo20_parts_offset, offsetof(TBoss6Demo20_TYPE2_APPEAR, opening_parts) == 0xA4);
#endif
