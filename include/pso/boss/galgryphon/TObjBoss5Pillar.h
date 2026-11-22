#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLAR_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLAR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

struct AnimationMotion;
struct NJS_OBJECT;
struct TObjBoss5PillarSmoke;

// A pillar of the Gal Gryphon arena. play_sound_once starts it: models[0] then
// plays its motion once with smoke on the model's nodes; models[1] is always drawn.
struct TObjBoss5Pillar : public TObject {
    TObjBoss5Pillar(TObject *parent, Vec *pos);
    virtual ~TObjBoss5Pillar();
    virtual void run_task();
    virtual void render();
    static TObjBoss5PillarSmoke *create_smoke(TObject *parent, NJS_OBJECT *node);
    static TObjBoss5Pillar *create(Vec *pos);
    void play_sound_once();

    s32 state;  // 0 waiting, 1 playing the motion, 2 smoke settling, 3 done
    f32 frame;
    f32 frame_step;
    s32 timer;  // frames spent in state 2
    Vec position;
    NJS_OBJECT *models[2];
    AnimationMotion *motions[2];  // played on models[0] and models[1]
    TObjBoss5PillarSmoke *smoke;
};

LAYOUT_ASSERT(TObjBoss5Pillar_size, sizeof(TObjBoss5Pillar) == 0x4C);

#endif
