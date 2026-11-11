#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO5_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO5_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
struct TObjFish;
struct AnimationMotion;

// One entry of a TObjFish node table (TObjFish__sub_800E3124 walks it up to
// the node -1 and keeps one Vec per entry in the array it is given).
struct TObjFishNodeEntry {
    s32 node;
    Vec offset; // inferred: a float triple per node (TBoss6Type2 sets y -5.0 / 1.0)
};

// One model of the Dark Falz death scene: its model, texture list and motion.
struct TObjDFDemo5Part {
    s32 model;
    s32 texlist;
    AnimationMotion *motion;
};

struct TObjDFDemo5 : public TObjBase {
    TObjDFDemo5(TObject *parent, const Vec *pos, s32 angle);
    virtual ~TObjDFDemo5();
    virtual void run_task();
    virtual void render();
    void update_particle_emitters();
    void release_subobjects();
    void draw_fading_motion();
    static void *create(void *arg0, void *arg1, void *arg2);

    TParticleCtrl *particle_emitters[5];
    TObjDFDemo5Part parts[4];
    Vec pos;
    s32 angle;
    s32 timer;
    f32 frame;
    TObjFish *node_list0;     // tracks emitter_positions
    Vec emitter_positions[2];
    TObjFish *node_list1;     // tracks tail_position
    Vec tail_position;
};

typedef char TObjDFDemo5_size[sizeof(TObjDFDemo5) == 0x118 ? 1 : -1];

extern "C" {
// Dark Falz's three body models (TBoss4Type3's table).
extern s32 lbl_80486FB0[3];
}

#endif
