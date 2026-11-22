#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO10_TYPE1_APPEAR_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO10_TYPE1_APPEAR_H
#include "pso/boss/Boss6ScrollStrips.h"
#include "types.h"
#include "pso/boss/olgaflow/OlgaFlowScenePart.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/system/task/TObject.h"

class ModelNodePositionCapture;
struct TBoss6PlotFalz;
class TParticleCtrl;
struct TObjFish;

class TBoss6Demo10_TYPE1_APPEAR : public TObject {
public:
    TBoss6Demo10_TYPE1_APPEAR(TBoss6PlotFalz *plot);
    static TBoss6Demo10_TYPE1_APPEAR *create(TBoss6PlotFalz *plot);
    virtual ~TBoss6Demo10_TYPE1_APPEAR();
    void draw_parts();
    virtual void render();
    virtual void run_task();
    OlgaFlowScenePart parts[2];
    f32 frame;
    saddr timer;
    TBoss6PlotFalz *plot;
    Boss6ScrollStrips scroll_strips;
    Vec effect_position;
    ModelNodePositionCapture *capture;
    TParticleCtrl *emitter;
};
LAYOUT_ASSERT(TBoss6Demo10_TYPE1_APPEAR_size, sizeof(TBoss6Demo10_TYPE1_APPEAR) == 0x68);

LAYOUT_ASSERT(TBoss6Demo10_capture_offset, offsetof(TBoss6Demo10_TYPE1_APPEAR, capture) == 0x60);
#endif
