#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO5_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO5_H

#include "types.h"
#include "pso/boss/darkfalz/DarkFalzScenePart.h"
#include "pso/object/base/TObjMotion.h"

class ModelNodePositionCapture;

class TParticleCtrl;
struct TObjFish;
struct AnimationMotion;

struct TObjDFDemo5 : public TObjBase {
    TObjDFDemo5(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo5();
    virtual void run_task();
    virtual void render();
    void update_particle_emitters();
    void release_subobjects();
    void draw_fading_motion();
    static TObjDFDemo5 *create(TObject *parent, const Vec *position, s32 angle);

    TParticleCtrl *particle_emitters[5];
    DarkFalzScenePart parts[4];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    ModelNodePositionCapture *node_list0;     // tracks emitter_positions
    Vec emitter_positions[2];
    ModelNodePositionCapture *node_list1;     // tracks tail_position
    Vec tail_position;
};

LAYOUT_ASSERT(TObjDFDemo5_size, sizeof(TObjDFDemo5) == 0x118);

extern "C" {
// Dark Falz's three body models (TBoss4Type3's table).
extern s32 boss4_type3_model_ids[3];
}

#endif
