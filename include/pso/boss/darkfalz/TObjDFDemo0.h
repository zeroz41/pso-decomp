#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO0_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO0_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/ModelNodeTables.h"

class TParticleCtrl;
struct AnimationMotion;
struct NJS_TEXLIST;

// A particle effect the demo keeps alive from frame `start` until frame `end`.
struct DFDemo0Emitter {
    s32 effect_id;
    s32 start;
    s32 end;
    Vec position;
};

// Dark Falz's first demo scene: six body models from boss4_type1_model_ids
// play their motions around df_demo0_center while timed particle effects,
// sounds and pad rumble run; it fades in and removes itself after 0x118 frames.
class TObjDFDemo0 : public TObjBase {
public:
    TObjDFDemo0(TObject *parent);
    virtual ~TObjDFDemo0();
    virtual void run_task();
    virtual void render();
    static TObjDFDemo0 *create(TObject *parent);

    s32 timer;
    ModelNodeTables strips;
    TParticleCtrl *particle_emitters[5];
    NJS_OBJECT *models[6];
    NJS_TEXLIST *texture_lists[6];
    AnimationMotion *motions[6];
    f32 loop_frame;   // motion frame of models 0 and 1, wraps at 30
    f32 motion_frame; // motion frame of the other models, stops at 139
    f32 fade;         // 0 hidden .. 1 opaque
};

LAYOUT_ASSERT(TObjDFDemo0_size, sizeof(TObjDFDemo0) == 0x110);
#endif
