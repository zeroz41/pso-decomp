#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO21_TYPE2_DEAD_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO21_TYPE2_DEAD_H
#include "types.h"
#include "pso/boss/olgaflow/OlgaFlowScenePart.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

class ModelNodePositionCapture;
struct TBoss6Zanzo;
struct TBoss6PlotFalz;
struct TObjFish;
class TParticleCtrl;

class TBoss6Demo21_TYPE2_DEAD : public TObject {
public:
    TBoss6Demo21_TYPE2_DEAD(TBoss6PlotFalz *plot, const Vec *target);
    virtual ~TBoss6Demo21_TYPE2_DEAD();
    static TBoss6Demo21_TYPE2_DEAD *create(TBoss6PlotFalz *plot, const Vec *target);
    virtual void render();
    virtual void run_task();
    OlgaFlowScenePart models[4];
    f32 frame;
    saddr timer;
    TBoss6PlotFalz *plot;
    Vec camera_position;
    Vec effect_position_5;
    ModelNodePositionCapture *capture_5;
    Vec effect_position_8;
    ModelNodePositionCapture *capture_8;
    Vec trail_positions[2];
    ModelNodePositionCapture *capture_13;
    TParticleCtrl *emitters[4];
    TBoss6Zanzo *trail_effect;
public:
    void draw_model_13();
    void draw_fading_model_8();
    void draw_fading_model_5();
    void draw_fading_model_4();
};
LAYOUT_ASSERT(TBoss6Demo21_TYPE2_DEAD_size, sizeof(TBoss6Demo21_TYPE2_DEAD) == 0xB4);

LAYOUT_ASSERT(TBoss6Demo21_TYPE2_DEAD_camera_position_offset, offsetof(TBoss6Demo21_TYPE2_DEAD, camera_position) == 0x58);
LAYOUT_ASSERT(TBoss6Demo21_TYPE2_DEAD_trail_offset, offsetof(TBoss6Demo21_TYPE2_DEAD, trail_effect) == 0xB0);
#endif
